
# idx.h

**idx.h** is a small C library that provides a standard interface to the (non-standard) 64-bit system-alternatives of the standard library file indexing functions: `fseek` and `ftell`. These alternatives are required if you want to index a file that's potentially larger than 2GB (32-bits).


## Background

This library exists because the standard library functions `fseek` and `ftell` are limited to using `long int` values (not even an `unsigned long int`). A `long int` has been defined as "at least 32-bits wide" in standard C; this limits the `fseek` and `ftell` to indexing files that are 2GB at most, which for some cases makes them fairly useless.
The reason these functions use this data type is because they are from the pre-standard C days, before fixed-width data types and `long long int`, where `long int` was just a 'big integer' and not necessarily a 32-bit integer.

Unfortunately, while the ISO-C committee standardised fixed-width data types with `stdint.h` in C99, they never added updated versions of functions that used the (now-defined, ergo limit) data types. This means that to index a file larger than 2GB on a modern system using C requires you to use platform-specific alternatives, such as `fseeko` in POSIX, or `fseeki64` in Windows, etc. *Even better*, most of these alternatives were written before ISO-C introduced fixed-width data types, so they don't even make use of those nice standard data types.

It would be nice to have a `uintmax_t ftell(FILE *stream)` on all platforms (and the same for `fseek`) but instead we have `__int64 ftelli64(FILE *stream)` on *Windows*, `off_t ftello(FILE *stream)` on *POSIX.1*, etc.

This isn't a huge inconvenience but writing cross-platform C with a bunch of `#ifdef`s is *ugly*. **idx.h** aims to replace that inconvenience with a functions that are just as nice to use as the standard library.


## API

**idx_t** - The system's own 64-bit data type.

- `off_t` on *POSIX*
- `__int64` on *Windows*


**idxseek**, `idx_t idxseek(FILE *f, idx_t origin, int origin);`

**idxtell**, `idx_t idxtell(FILE *f);`


## Support

Currently support platforms are:

- Unixes (Linux, BSD's, etc) and MacOS
- Windows


## Authors

- gearsix, 2022