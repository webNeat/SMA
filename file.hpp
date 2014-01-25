#ifndef FILE_HPP
#define FILE_HPP 1
class File {
public:
	static void saveConfig();
	static void loadConfig();

	static void saveParams();
	static void loadParams();

	static void saveWorld();
	static void loadWorld();
};
#endif