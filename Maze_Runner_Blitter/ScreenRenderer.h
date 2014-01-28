//
//  ScreenRenderer.h
//  Maze Runner
//
//  Created by Ben Keenan on 06/01/2014.
//  Copyright (c) 2014 Ben Keenan. All rights reserved.
//

#ifndef __Maze_Runner__ScreenRenderer__
#define __Maze_Runner__ScreenRenderer__


#include <iostream>

using namespace std;

class Screen
{
public:
	static const int i_screenWidth = 80;
	static const int i_screenHeight = 25;
	char ch_screenMatrix[i_screenWidth][i_screenHeight];

	void PrintScreen() {
		while (y < 80) {
			while (x < 80)
			{
				cout << ch_screenMatrix[x][y];
				x++;
			}
			y++;
		}
		return;
	}


private:
	int x = 0;
	int y = 0;

};


#endif /* defined(__Maze_Runner__ScreenRenderer__) */
