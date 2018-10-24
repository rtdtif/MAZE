#include <iostream>
#include <array>
#include <conio.h>


const int maxRowsCount = 25;
const int maxColumnsCount = 50;

const char mapPlayerIcon = '@';
const char mapExitIcon = 'E';
const char mapWallIcon = '#';
const char mapFieldIcon = ' ';

using Map = std::array < std::array<char, maxColumnsCount>, maxRowsCount>;


void showMenu()
{
	std::cout << std::endl;
	std::cout << "\t\t ~***  MAZE  ***~" << std::endl;
	std::cout << std::endl;
	std::cout << "\tTip : use arrows to control your personage." << std::endl;
	std::cout << std::endl;
}
void fillMap(Map &map)
{
	for (int row = 0; row < maxRowsCount; ++row)
	{
		for (int column = 0; column < maxColumnsCount; ++column)
		{
			if (row == 0 || row == (maxRowsCount - 1) || column == 0 || column == (maxColumnsCount - 1))
			{
				map[row][column] = mapWallIcon; 
			}
			else
			{
				map[row][column] = mapFieldIcon;
			}
		}
	}
}
void showMap(const Map &map)
{
	for (int row = 0; row < maxRowsCount; ++row)
	{
		std::cout << "    ";
		for (int column = 0; column < maxColumnsCount; ++column)
		{
			std::cout << map[row][column];
		}
		std::cout << std::endl;
	}
}

int main()
{
	Map map;
	showMenu();
	fillMap(map);
	showMap(map);
	getchar();
	return 0;
}
