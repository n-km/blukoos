#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "arch/x86/io.h"

/* VGA-Treiber (Textmodus, 0xB8000) */
#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80
#define WHITE_ON_BLACK 0x0f

#define VGA_CTRL_REGISTER 0x3d4
#define VGA_DATA_REGISTER 0x3d5
#define VGA_OFFSET_LOW 0x0f
#define VGA_OFFSET_HIGH 0x0e

static int cursor_offset = 0;

static int get_row_from_offset(int offset) { return offset / (2 * MAX_COLS); }

static int get_offset(int col, int row) { return 2 * (row * MAX_COLS + col); }

static void memory_copy(char *source, char *dest, int nbytes)
{
  int i;
  for (i = 0; i < nbytes; i++)
  {
    *(dest + i) = *(source + i);
  }
}

static void set_cursor(int offset)
{
  offset /= 2;
  outb(VGA_CTRL_REGISTER, VGA_OFFSET_HIGH);
  outb(VGA_DATA_REGISTER, (unsigned char)(offset >> 8));
  outb(VGA_CTRL_REGISTER, VGA_OFFSET_LOW);
  outb(VGA_DATA_REGISTER, (unsigned char)(offset & 0xff));
}

static void set_char_at_video_memory(char character, int offset)
{
  unsigned char *vidmem = (unsigned char *)VIDEO_ADDRESS;
  vidmem[offset] = character;
  vidmem[offset + 1] = WHITE_ON_BLACK;
}

static int scroll_ln(int offset)
{
  memory_copy((char *)(get_offset(0, 1) + VIDEO_ADDRESS),
              (char *)(get_offset(0, 0) + VIDEO_ADDRESS),
              MAX_COLS * (MAX_ROWS - 1) * 2);

  for (int col = 0; col < MAX_COLS; col++)
  {
    set_char_at_video_memory(' ', get_offset(col, MAX_ROWS - 1));
  }

  return offset - 2 * MAX_COLS;
}

static int move_offset_to_new_line(int offset)
{
  return get_offset(0, get_row_from_offset(offset) + 1);
}

void vga_write(char *string)
{
  int offset = cursor_offset;
  int i = 0;
  while (string[i] != 0)
  {
    if (offset >= MAX_ROWS * MAX_COLS * 2)
    {
      offset = scroll_ln(offset);
    }
    if (string[i] == '\n')
    {
      offset = move_offset_to_new_line(offset);
    }
    else
    {
      set_char_at_video_memory(string[i], offset);
      offset += 2;
    }
    i++;
  }
  cursor_offset = offset;
  set_cursor(offset);
}

void vga_write_line(char *string)
{
  vga_write(string);
  vga_write("\n");
}

void vga_clear_screen()
{
  for (int i = 0; i < MAX_COLS * MAX_ROWS; ++i)
  {
    set_char_at_video_memory(' ', i * 2);
  }
  cursor_offset = get_offset(0, 0);
  set_cursor(cursor_offset);
}

void vga_putc(char c)
{
  char buf[2] = {c, 0};
  vga_write(buf);
}

void vga_backspace(void)
{
  if (cursor_offset <= 0)
    return;

  cursor_offset -= 2;
  set_char_at_video_memory(' ', cursor_offset);
  set_cursor(cursor_offset);
}

void vga_print_hex(uint8_t val)
{
  const char hex[] = "0123456789ABCDEF";

  char buf[5];
  buf[0] = '0';
  buf[1] = 'x';
  buf[2] = hex[(val >> 4) & 0xF]; // high nibble
  buf[3] = hex[val & 0xF];        // low nibble
  buf[4] = 0;

  vga_write(buf);
}