# Radix

**(WIP)** — Radix is a 2D C++ game library. It is a work-in-progress personal project and is not intended to be a commercial product.

This project was built and tested on **Arch Linux**.

## Dependencies

* SDL3
* SDL3_image
* SDL3_mixer
* SDL3_ttf
* clang-tidy

## How to Build

Clone the repository:

```bash
git clone https://github.com/DominicSieli/radix.git
```

Build the library using either the debug or optimized configuration:

```bash
make build_debug
```

or:

```bash
make build_optimized
```

## Utilities

Check for warnings and errors

```bash
make check
```

Clean project directory

```bash
make clean
```

### Using Radix in Another Project

Alternatively, you can place the `radix` directory inside your project and include the desired header files in your source files. This will compile Radix as part of your project.
