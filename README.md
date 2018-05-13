## About

Application extract pairs of hexadecimal digits from input file (name of file is input). Divide them based on number of ones in binary representation, sort two collection and output to files (files are named even and odd).

Input:

```
32189fhwqf2398hycf9q3efchqevhuqeh2y839yrnhfvqusih923yr4wfhnar23y97823yvhfsdiah2yu98243asd
23r4fq23
```

Output:

Even:

```
3
18
24
28
39
39
39
3a
78
9f
d2
ee
f9
f9
fc
```

Odd:

```
fd
f2
f2
a2
a2
98
8c
4f
3e
34
32
23
23
```

## Application usage

Move input file into project root folder and change its name to "input".

Compile project:

```
cmake .
make
./runHex
```

### Prerequisites

* CMAKE version >= 3.7.2
* GCC (because I'm using `int  __builtin_popcount(unsigned int)`)

## Lib usage

Example usage in ```main.cpp``.

Include headers

```
#include "src/InputProcessor.h"
#include "src/Output.h"
```

Specify input file:

```
    InputProcessor ip;
    std::vector<std::vector<unsigned char>> out = ip.processFile("input");
```

Output processed data to files:

```
    Output o;
    o.outputToFile(out);
```