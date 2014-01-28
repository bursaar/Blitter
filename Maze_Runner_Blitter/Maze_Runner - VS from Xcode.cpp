// Maze_Runner - VS from Xcode.cpp : main project file.


#include <iostream>
#include "Maze.h"
#include "Pathfinder.h"
#include "Interface.h"


using namespace std;

//int main(array<System::String ^> ^args)
/*{
	cout << "MAZE RUNNER";
	SkipLine(3);
	cout << "Created by Ben Keenan";
	SkipLine();
	cout << "ben@ben.ie | +353 87 935 0483";
	SkipLine();
	cout << "Student No. CD9000002O";
	SkipLine();
	cout << "Portfolio 1, Project 2";
	SkipLine(2);
	cout << "This is a simple test of my";
	SkipLine();
	cout << "data serialisation algorithm";
	SkipLine(2);
	cout << "Please maximize your window and choose an option.";
	SkipLine(2);
	cout << "1. Test game." << endl << "2. Demo code." << endl;

	int choice;		// Menu choice from the start of the program.
	cin >> choice;
	system("CLS");

	if (choice == 2) {

		// Create Maze
		// =========================

		// Maze object.
		cMaze LevelOne;

		// Generator code for maze object.
		bool LevelOneCode[338] = { 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

		// Name for Maze Object
		char LevelOneName[25] = "Test_Game_Example_01";

		// Generate contents of maze.
		LevelOne.NewGame(LevelOne, LevelOneName, LevelOneCode, 1);
		SkipLine();

		getchar();
		system("CLS");

		// Print proper values of maze.
		// =========================
		LevelOne.print();
		SkipLine();

		getchar();
		system("CLS");

		// Perform pathfinding pass.
		// =========================

		cPathfinder pthLevelOne;		// Pathfinder instance with nodemap. One per level. Kept separate from maze for portability.

		pthLevelOne.create(LevelOne);	// Populate nodemap of the entire maze.

		gridloc gl_tempLegalMoves[4];	// Array to hold the current legal moves.
		gridloc gl_tempLookHere;		// Create location to check for legal moves *from*

		gl_tempLookHere.xloc = 1;		// Assign values to x & y - in this case the node at (1, 1)
		gl_tempLookHere.yloc = 1;

		// Examine next legal moves.
		pthLevelOne.LookAround(gl_tempLookHere, gl_tempLegalMoves);

		cout << "This is the node map (should be identical).";

		SkipLine(2);
		pthLevelOne.print();

		SkipLine();

		getchar();
		system("CLS");

		cout << "These are the moves available at ";

		gl_tempLookHere.printLoc(gl_tempLookHere); // TODO find a more elegant implementation where it doesn't need to be passed itself.

		cout << ":";

		SkipLine();

		PrintCoOrds(gl_tempLegalMoves);

		SkipLine(2);

	}
	else {

		// Maze object.
		cMaze LevelOne;

		// Generator code for maze object.
		bool LevelOneCode[338] = { 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

		// Name for Maze Object
		char LevelOneName[25] = "Let_Us_Play";

		// Generate contents of maze.
		LevelOne.NewGame(LevelOne, LevelOneName, LevelOneCode, 1);

		getchar();
	}

	cout << "Press enter to quit.";

	SkipLine();

	getchar();
    return 0;
}*/
