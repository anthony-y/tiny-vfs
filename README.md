# Tiny VFS

A tiny virtual file system library for C++.

**NOTE: Tiny VFS only works with C++11 and newer!**

Tiny VFS maps virtual directories to physical ones.

# Getting started

First, you need to clone the Tiny VFS repository:

```
git clone https://github.com/anthony-y/tiny-vfs.git
```
Next, move the tinyvfs source files into a suitable location. You will compile the library into your project as if it were part of your own codebase:

```cpp
#include "tinyvfs.hpp"
```

To mount a directory:

```cpp
TinyVFS::FS()->MountDir("Virtual/Directory", "Physical/Directory");
```

Resolving a physical directory is as simple as:

```cpp
std::string physicalDir = TinyVFS::FS()->ResolvePhysicalDir("Virtual/Directory");
```

This works the same with files too:

```cpp
std::string physicalDirOfFile = TinyVFS::FS()->ResolvePhysicalDir("Virtual/Directory/File.extension");
```

Tiny VFS also has a simple method for reading text files from a virtual directory:

```cpp
std::string fileContents;
TinyVFS::FS()->ReadTextFile("Virtual/Directory/Text File.txt", fileContents);
```

This method returns a boolean value as to whether the read failed or not.

```cpp
if (!TinyVFS::FS()->ReadTextFile("Virtual/Directory/Text File.txt", fileContents))
{
    std::cout << "Read failed!" << std::endl;
    return 1;
}

std::cout << "Read succeeded! File contents: " << fileContents << std::endl;

return 0;
```

To compile, just build the .cpp file into your binary:

```
g++ -o yourexecutable.exe -std=c++11 yourfile.cpp tinyvfs.cpp
```

Check out the [samples](https://github.com/anthony-y/tiny-vfs/tree/master/sample) directory for a full example of usage.
