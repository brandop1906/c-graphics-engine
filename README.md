# Graphics Engine Foundations

Building a graphics/game engine in C from first principles — starting at the machine level and working up to a real-time renderer. This repo is the foundation layer taking shape: the math, data structures, and systems groundwork an engine sits on.

The goal isn't to use an existing engine — it's to understand every layer, from memory management up to the rendering pipeline, by building it myself.

## Why

I'm working toward becoming a graphics/engine programmer, and I care about understanding *how* things work, not just *that* they work. This repo documents that journey: the reusable components I'm building, and the exercises I'm learning from along the way.

## Structure

```
foundations/
    math/          Vector math library (vec2/3/4: add, dot, cross, normalize, ...)
    containers/    Data structures (dynamic array, ...)
exercises/         Learning exercises (K&R, systems fundamentals)
```

## Foundations

### foundations/math — Vector Math Library

A small linear-algebra library for graphics: `vec2`, `vec3`, `vec4` with add, subtract, scale, dot product, length, normalize, and cross product. Built as a proper header/implementation split for reuse.

### foundations/containers — Dynamic Array

A growable array ("vector" in the data-structure sense), with amortized O(1) push via capacity doubling, pop, and manual heap management. Handles `realloc` failure safely — a failed grow leaves the structure untouched (strong exception safety). Verified leak-free with AddressSanitizer.

## Building

Each component compiles with a C compiler and its test file. Example:

```sh
gcc -Wall -Wextra -fsanitize=address -g \
    foundations/containers/dynarray.c \
    foundations/containers/test_dynarray.c \
    -o dynarray && ./dynarray
```

`-fsanitize=address` is used throughout to catch memory errors and leaks.

## Roadmap

- [x] Vector math library (vec2/3/4)
- [x] Dynamic array
- [ ] Matrix math (mat3/mat4, transformations)
- [ ] Quaternions
- [ ] First triangle (OpenGL)
- [ ] Basic renderer

## Status

Actively in progress. This is a long-term, learn-in-public project — the commit history is the story.