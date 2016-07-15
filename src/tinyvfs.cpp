#include "../include/tinyvfs.hpp"

TinyVFS* TinyVFS::instance = nullptr;

TinyVFS* TinyVFS::FS()
{
    if (TinyVFS::instance == nullptr) TinyVFS::instance = new TinyVFS();

    return TinyVFS::instance;
}

void TinyVFS::Close()
{
    if (TinyVFS::instance != nullptr) delete TinyVFS::instance;
}

std::string *TinyVFS::GetPathAndFile(std::string filePath)
{
    std::string path;
    std::string file;

    std::string arr[2];

    int endOfPathIndex = 0;

    for (int c = 0; c < filePath.size(); c++)
    {
        if (filePath[c] == '/')
            endOfPathIndex = c;
    }

    arr[0] = filePath.substr(0, endOfPathIndex + 1);
    arr[1] = filePath.substr(path.length(), filePath.length());

    return arr;
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

    auto virtualPath = GetPathAndFile(virtualDir)[0];
    auto fileName = GetPathAndFile(virtualDir)[1];

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
        contents += data;
        contents.append("\n");
    }

    outFileContents = contents;

    fileHandle.close();

    return true;
}