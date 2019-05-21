# Questions

## What's `stdint.h`?

A header file in C that allows programmers to write a portable code by providing a set of typedefs to specify exact-width integer types, with the defined min and max values for each type, using macros.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

These are signed and unasigned integer types from stdint.h. They make the code easier/safer to port as the exact-wideth integer is defined.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE = 1 byte, DWORD = 4 bytes, LONG = 4 bytes, WORD = 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

ASCII BM and hex 0x424d stored as bfType

## What's the difference between `bfSize` and `biSize`?

bfSize is the total size in bytes of a file including pixels and padding
biSize is the total size in bytes of a file including pixels, padding, and header

## What does it mean if `biHeight` is negative?

The image is a top-down DIB, with the origin at the upper left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If the file copy.c is not valid/found

## Why is the third argument to `fread` always `1` in our code?

We are using fread to read a specified struct/element from the input file

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

padding = 3

## What does `fseek` do?

The fseek function is used to move the cursor in the file

## What is `SEEK_CUR`?

An integer that specifies the current position of the cursor in the file (used with fseek so we know where fseek is moving from)

## Whodunit?

Professor Plum with the candlestick in the library.
