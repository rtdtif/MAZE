#include <iostream>
#include <array>
#include <conio.h>


const int maxRowsCount = 25;
const int maxColumnsCount = 50;
const int exitRetreat = 4;

const char mapPlayerIcon = '@';
const char mapExitIcon = 'E';
const char mapWallIcon = '#';
const char mapFieldIcon = ' ';
const char mapTestIcon = 't';

using Map = std::array < std::array<char, maxColumnsCount>, maxRowsCount>;


void showMenu()
{
	std::cout << std::endl;
	std::cout << "\t\t      ~***  MAZE  ***~" << std::endl;
	std::cout << "\tMain goal: Help dog to find exit." << std::endl;
	std::cout << "\tTip : use arrows to control your personage." << std::endl;
	std::cout << std::endl;
}
void fillMapBorders(Map &map)
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
			if (row == maxRowsCount - exitRetreat && column == maxColumnsCount - exitRetreat*2)
			{
				map[row][column] = mapExitIcon;
			}
			if (row == exitRetreat && column == exitRetreat * 2)
			{
				map[row][column] = mapPlayerIcon;
			}
		}
	}
}
void genereteMap(Map &map)
{
	for (int row = 1; row < maxRowsCount-1; ++row)
	{
		for (int column = 1; column < maxColumnsCount-1; ++column)
		{
			if ((rand() % 5 == 1) && (row != maxRowsCount - exitRetreat && column != maxColumnsCount - exitRetreat * 2))
			{
				if(row != exitRetreat && column != exitRetreat * 2)
				{
					map[row][column] = mapWallIcon;
				}
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
	fillMapBorders(map);
	genereteMap(map);
	showMap(map);
	getchar();
	return 0;
}
