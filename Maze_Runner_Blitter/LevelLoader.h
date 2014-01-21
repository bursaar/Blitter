#pragma once

#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Maze.h"

using namespace std;

class cLevelLoader
{
public:
	cLevelLoader();
	
	char filename[15];

	int LoadLevel(const char pFilename[15]);

	int SaveLevel(char pFilename[15]);

private:


};