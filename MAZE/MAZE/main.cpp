#include <iostream>
#include <array>
#include <conio.h>


const int maxRowsCount = 25;
const int maxColumnsCount = 35;

const char mapPlayerIcon = '@';
const char mapExitIcon = 'E';
const char mapWallIcon = '#';
const char mapFieldIcon = ' ';

using Map = std::array < std::array<char, maxRowsCount>, maxColumnsCount>;


void showMenu()
{
	std::cout << "\t ~***  MAZE  ***~" << std::endl;
	std::cout << std::endl;
	std::cout << "Tip : use arrows to control your personage." << std::endl;
	std::cout << std::endl;
}

int main()
{
	showMenu();
	getchar();
	return 0;
}
