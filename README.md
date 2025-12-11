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


Duration: 2 weeks
Goal: Establish the foundational structure of the blukoos operating system and ensure it can successfully boot through an existing bootloader.

### Sprint Objectives:
#### 1. Project Setup & Repository Initialization

- [ ] Create the main project repository structure (boot/, kernel/, build/, docs/).
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


