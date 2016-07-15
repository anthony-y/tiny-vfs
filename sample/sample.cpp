#include <iostream>

#include <tinyvfs.hpp>

int main(int argc, char **argv)
{
	TinyVFS::FS()->MountDir("files/", "res/magic/hazzah/");
	TinyVFS::FS()->MountDir("files/", "res/magic/");
	TinyVFS::FS()->MountDir("files/", "res/");

	std::string wowTxt;
	std::string someFileTxt;
	std::string fakePasswordsTxt;
	std::string someOtherFileTxt;

	if 
	(
		!TinyVFS::FS()->ReadTextFile("files/wow.txt", wowTxt) ||
		!TinyVFS::FS()->ReadTextFile("files/some file.txt", someFileTxt) ||
		!TinyVFS::FS()->ReadTextFile("files/mypasswords.txt", fakePasswordsTxt) ||
		!TinyVFS::FS()->ReadTextFile("files/some other file.txt", someOtherFileTxt)
	)
		std::cout << "Read failed" << std::endl;

	std::cout << "wow.txt contents: " << wowTxt << std::endl;
	std::cout << "some file.txt contents: " << someFileTxt << std::endl;
	std::cout << "mypasswords.txt contents: " << std::endl << fakePasswordsTxt << std::endl;
	std::cout << "some other file.txt contents: " << std::endl << someOtherFileTxt;

	getchar();

	return 0;
}