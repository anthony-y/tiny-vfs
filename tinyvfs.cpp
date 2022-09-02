#include "tinyvfs.hpp"

TinyVFS* TinyVFS::FS()
{
    static TinyVFS vfs;
    return &vfs;
}

VFSPath TinyVFS::GetPathAndFile(std::string filePath)
{
    VFSPath result;

    int endOfPathIndex = 0;

    for (int c = 0; c < filePath.size(); c++)
    {
        if (filePath[c] == '/')
            endOfPathIndex = c;
    }

    result.path = filePath.substr(0, endOfPathIndex + 1);
    result.fileName = filePath.substr(result.path.length(), filePath.length());

    return result;
}

bool TinyVFS::DoesFileExist(std::string filePath)
{
    std::ifstream checker(filePath);

    return checker.good();
}

void TinyVFS::MountDir(std::string virtualDir, std::string physicalDir)
{
    mappedDirs[virtualDir].push_back(physicalDir);
}

void TinyVFS::UnmountDir(std::string virtualDir)
{
    mappedDirs[virtualDir].clear();
}

std::string TinyVFS::ResolvePhysicalDir(std::string virtualDir)
{
    std::string physicalDir;

    auto pathAndFile = GetPathAndFile(virtualDir);

    auto virtualPath = pathAndFile.path;
    auto fileName = pathAndFile.fileName;

    for (auto &item : mappedDirs[virtualPath])
    {
        auto pathAndFileName = item + fileName;

        if (DoesFileExist(pathAndFileName))
            physicalDir = pathAndFileName;
    }
    
    return physicalDir;
}

bool TinyVFS::ReadTextFile(std::string virtualDir, std::string &outFileContents)
{
    auto resolved = ResolvePhysicalDir(virtualDir);

    std::ifstream fileHandle(resolved);

    if (!fileHandle)
        return false;

    std::string data;
    std::string contents;
    while(getline(fileHandle, data)) 
    {
        contents += (data + "\n");
    }

    outFileContents = contents;

    fileHandle.close();

    return true;
}
