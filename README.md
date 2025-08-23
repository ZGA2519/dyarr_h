# dyarr_h
Simple Single-Header File For Dynamic Array

This single-header library is inspired by `stb_ds.h`. It hides the array metadata (such as length and capacity) just before the actual array data, allowing you to use the array in C/C++ as you normally would, while benefiting from dynamic sizing.

| length, capacity | actual array . . . |
| ---------------- | ------------------ |
|                  | ⬆ array pointer   |

