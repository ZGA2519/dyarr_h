# Utility Library
Simple Single-Header File For Utility Library

## dyarr.h

This single-header library is dynamic array inspired by `stb_ds.h`. It hides the array metadata (such as length and capacity) just before the actual array data, allowing you to use the array in C/C++ as you normally would, while benefiting from dynamic sizing.

| length, capacity | actual array . . . |
| ---------------- | ------------------ |
|                  | ⬆ array pointer   |

## logging.h

This single-header library is use for logging system to provide more information for user when processing.
