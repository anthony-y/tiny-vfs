# Tiny VFS

A tiny virtual file system library for C++.

**NOTE: Tiny VFS only works with C++11 and newer!**

Tiny VFS maps virtual directories to physical ones.

# Getting started

First, you need to clone the Tiny VFS repository:

```
git clone https://github.com/anthony-y/tiny-vfs.git
```

Next, you need to include the Tiny VFS header file in your project, which is located under the tiny-vfs/include/directory.

```cpp
#include "tiny-vfs/include/tinyvfs.hpp"
```

To mount a directory:

```cpp
TinyVFS::FS()->MountDir("VIRTUAL/DIRECTORY/", "PHYSICAL/DIRECTORY");
```

Resolving a physical directory is as simple as:

```cpp
std::string physicalDir = TinyVFS::FS()->ResolvePhysicalDir("VIRTUAL/DIRECTORY");
```

This works the same with files too:

```cpp
std::string physicalDirOfFile = TinyVFS::FS()->ResolvePhysicalDir("VIRTUAL/DIRECTORY/FILE.extension");
```

Tiny VFS also has a simple method for reading text files from a virtual directory:

```cpp
std::string fileContents;
TinyVFS::FS()->ReadTextFile("VIRTUAL/DIRECTORY/TEXTFILE.txt", fileContents);
```

This method returns a boolean value as to whether the read failed or not.

```cpp
if (!TinyVFS::FS()->ReadTextFile("VIRTUAL/DIRECTORY/TEXTFILE.txt", fileContents))
{
    std::cout << "Read failed!" << std::endl;
    return  1;
}
```

Make sure that you destroy the TinyVFS instance when you have finished with it by calling:

```cpp
TinyVFS::FS()->Close();
```

Finally, to compile your code with Tiny VFS, you will need to link against the static library located in tinyvfs/lib:
To compile with g++:

```
g++ -o yourexecutable.exe -std=c++11 yourfile.cpp tiny-vfs/lib/tinyvfs.a
```