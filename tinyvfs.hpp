#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iterator>

struct VFSPath {
    std::string path;
    std::string fileName;
};

class TinyVFS
{
private:
	std::map<std::string, std::vector<std::string>> mappedDirs;

    VFSPath GetPathAndFile(std::string filePath);
	bool DoesFileExist(std::string filePath);

	
public:
	void MountDir(std::string virtualDir, std::string physicalDir);
	void UnmountDir(std::string virtualDir);
	std::string ResolvePhysicalDir(std::string virtualDir);
	bool ReadTextFile(std::string virtualDir, std::string &outFileContents);

	static TinyVFS* FS();
};
