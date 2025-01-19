# Include Guards 

Include guards prevent multiple inclusions of the same header file in a C++ 
program. This avoids redefinition errors and reduces compilation overhead. 

They typically consist of a conditional macro check (`#ifndef…#define…#endif`) 
or a `#pragma once` directive, ensuring that a header’s contents are compiled 
only once per translation unit.


## Traditional Include Guards

_Example:_ Traditional Include Guards

```cpp
#ifndef MYHEADER_H
#define MYHEADER_H

// Declarations...

#endif // MYHEADER_H
```

* The macro (`MYHEADER_H`) is checked with `#ifndef`.  
* If **not** defined, the code in the header is included and the macro is 
defined.  
* Any subsequent attempts to include the same header see that `MYHEADER_H` 
is already defined, so the contents are skipped.  

### Advantages

* **Standard and portable**: Works on **all** C/C++ compilers.  
* **Explicit**: The guard name clearly identifies the header being protected.  

### Disadvantages

* **Manual**: You must manually ensure unique macro names for every header.  
* **Verbosity**: Requires 2–3 lines of boilerplate code in every header.  



## `#pragma once`

_Example:_ `#pragma once`

```cpp
#pragma once

// Declarations...
```

* Tells the compiler to include the file **once** per compilation unit, 
**regardless** of the number of subsequent `#include` directives.  

### Advantages

* **Simplicity**: Only **one** line needed at the top of the header.    
No manual macros.  
* **Less error-prone**: No need to keep track of macro guard names.  
* **Potential performance benefit**: Many compilers can skip the file 
quickly without checking macros, though this benefit is often minor or 
implementation-dependent.  

### Disadvantages

* **Non-standard**: It is not officially part of the C++ standard, 
though it’s **widely supported** by major compilers (GCC, Clang, MSVC, 
and others).  
* **Path/Link Ambiguities**: In very rare cases (e.g., **symbolic links** 
or **multiple includes via different paths**), the compiler might treat 
the same physical file as distinct, causing multiple inclusions. This is 
uncommon but can happen if your build system has unusual path handling.  


## Conclusion

* If our code must compile on very old or obscure compilers, **traditional 
include guards** are the safe choice, as they are standardized since the 
earliest C/C++ standards.

* In most modern environments (GCC, Clang, MSVC), `#pragma once` is 
well-supported and offers a quick, **less error-prone** solution.


*Egon Teiniker, 2020-2025, GPL v3.0*