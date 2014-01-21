#include "LevelLoader.h"
#define _CRT_SECURE_NO_WARNINGS 1

cLevelLoader::cLevelLoader()
{

}

int cLevelLoader::LoadLevel(const char pFilename[15])
{
	FILE * f_level_open;
	f_level_open = fopen(pFilename, "r");
	if (f_level_open == NULL)
	{
		cout << "Err. File Empty" << endl;
		return 1;	// Empty file error
	}
	

}

int cLevelLoader::SaveLevel(char pFilename[15])
{

}