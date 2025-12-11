# blukoos
An brand new operating system built on an existing bootloader

## Ordner-Structure:

```ordner-structure.txt
blukoos/
├── boot/          # Bootloader-Konfigurationen
├── kernel/        # Kernel-Quellcode
├── build/         # Build-Output (automatisch)
├── docs/          # Dokumentation
├── LICENSE
└── README.md
```

<details>
  
  <summary><h2>Sprint 1 – Core Boot & Kernel Initialization</h2></summary>


- Duration: 2 weeks
- Goal: Establish the foundational structure of the blukoos operating system and ensure it can successfully boot through an existing bootloader.

### Sprint Objectives:
#### 1. Project Setup & Repository Initialization

- [x] Create the main project repository structure (boot/, kernel/, build/, docs/).
- [ ] Add initial README, license, and contribution guidelines.
- [ ] Set up build system (Makefile or alternative).

#### 2. Bootloader Integration

- [ ] Choose the bootloader (Limine or GRUB).
- [ ] Add required configuration files to the boot/ directory.
- [ ] Ensure the bootloader recognizes and loads the kernel binary.

#### 3. Minimal Kernel Skeleton

- [ ] Implement a basic kernel entry point.
- [ ] Add simple initialization: stack setup, basic structures, environment detection.
- [ ] Implement a simple screen/console output function (e.g., print a text message).

#### 4. Build & Runtime Environment

- [ ] Configure toolchain (cross-compiler or Rust target).
- [ ] Add build targets:
```
make → compile kernel
make iso → generate bootable image
make run → boot in QEMU
```

#### 5. Documentation

- [ ] Document the boot process and kernel structure in /docs.
- [ ] Update README with build instructions.
- [ ] Add development guidelines and coding conventions.


</details>

<details>
  <summary><h2>Structured Link-List by AI</h2></summary>
  
| Source / Website                                                                                                                                                                                                                       | Why it’s useful / What it contains                                                                                         |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------- |
| **OSDev Wiki – “Bare Bones”**                                                                                                                                                                                                          |                                                                                                                            |
| [https://wiki.osdev.org/Bare_Bones](https://wiki.osdev.org/Bare_Bones)                                                                                                                                                                 | A well-known tutorial for building a minimal kernel using an existing bootloader like GRUB. Perfect for starting Sprint 1. |
| **OSDev Wiki – “Tutorials” Overview**                                                                                                                                                                                                  |                                                                                                                            |
| [https://wiki.osdev.org/Tutorials](https://wiki.osdev.org/Tutorials)                                                                                                                                                                   | Large collection of OS development tutorials: 32-bit, 64-bit, bootloaders, paging, memory management, etc.                 |
| **The Little Book About OS Development**                                                                                                                                                                                               |                                                                                                                            |
| [https://littleosbook.github.io](https://littleosbook.github.io)                                                                                                                                                                       | Beginner-friendly guide explaining how a small OS works from boot to kernel. Great conceptual overview.                    |
| **Blog: “Writing a Minimal 32-bit Kernel in C”**                                                                                                                                                                                       |                                                                                                                            |
| [https://medium.com/@2023a6r057/writing-a-minimal-32-bit-kernel-in-c-9fd4e3cc96d3](https://medium.com/@2023a6r057/writing-a-minimal-32-bit-kernel-in-c-9fd4e3cc96d3)                                                                   | Step-by-step guide to building a tiny kernel in C, with QEMU testing.                                                      |
| **Blog: “Build a Simple Bootloader and Kernel from Scratch Using NASM and QEMU”**                                                                                                                                                      |                                                                                                                            |
| [https://medium.com/@jothini231/build-a-simple-bootloader-and-kernel-from-scratch-using-nasm-and-qemu-e4699f6252a9](https://medium.com/@jothini231/build-a-simple-bootloader-and-kernel-from-scratch-using-nasm-and-qemu-e4699f6252a9) | Shows how a simple NASM bootloader works and how it hands off to a C kernel.                                               |
| **Article: “Writing an OS Kernel Using a Tutorial from OSDev.org”**                                                                                                                                                                    |                                                                                                                            |
| [https://coobird.net/blog/2022/04/23/writing-an-os-kernel-using-a-tutorial-from-osdev.html](https://coobird.net/blog/2022/04/23/writing-an-os-kernel-using-a-tutorial-from-osdev.html)                                                 | A real-world experience report from following OSDev’s tutorials — good for avoiding common pitfalls.                       |


</details>
