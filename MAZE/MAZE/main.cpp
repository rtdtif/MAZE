#include <iostream>
#include <array>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


const int maxRowsCount = 29;
const int maxColumnsCount = 54;
const int exitRetreat = 4;

const char mapPlayerIcon = '@';
const char mapExitIcon = 'E';
const char mapWallIcon = '#';
const char mapFieldIcon = ' ';
const char mapTestIcon = 't';

using Map = std::array < std::array<char, maxColumnsCount>, maxRowsCount>;

char playerMovementDirection;

struct playerIconPos
{
	int playerIconRow;
	int playerIconColumn;
};


void showMenu()
{
	std::cout << std::endl;
	std::cout << "\t\t      ~***  MAZE  ***~" << std::endl;
	std::cout << "\tMain goal: Help dog to find exit." << std::endl;
	std::cout << "\tTip : use arrows to control your personage." << std::endl;
	std::cout << std::endl;
	std::cout << "\t Do you want to play this great game?( 'y' - to play, 'n' - exit)." << std::endl;
}

void endGame()
{
	for (int i = 0; i < maxRowsCount; ++i)
	{
		std::cout << std::endl;
	}
	std::cout << "You won! The dog got out of the labyrinth! " << std::endl;
	std::cout << "You won! The dog got out of the labyrinth! " << std::endl;
	std::cout << "You won! The dog got out of the labyrinth! " << std::endl;
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

void genereteMap(Map &map)
{
	for (int row = 1; row < maxRowsCount - 1; ++row)
	{
		for (int column = 1; column < maxColumnsCount - 1; ++column)
		{
			if ((rand() % 5 == 1) && (row != maxRowsCount - exitRetreat && column != maxColumnsCount - exitRetreat * 2))
			{
				if (row != exitRetreat && column != exitRetreat * 2)
				{
					map[row][column] = mapWallIcon;
				}
			}
		}

	}

}
playerIconPos findPlayerIcon(const Map &map, playerIconPos &position)
{
	for (int row = 1; row < maxRowsCount - 1; ++row)
	{
		for (int column = 1; column < maxColumnsCount - 1; ++column)
		{
			if (map[row][column] == mapPlayerIcon)
			{
				position.playerIconRow = row;
				position.playerIconColumn = column;
				return position;
			}
		}

	}
}
void drawPlayerIcon(Map &map,const playerIconPos position)
{
	map[position.playerIconRow][position.playerIconColumn] = mapPlayerIcon;
}
void delPlayerIcon(Map &map,const playerIconPos &position) 
{
	map[position.playerIconRow][position.playerIconColumn] = mapFieldIcon;
}
void movePlayerIcon(Map &map,playerIconPos &position)
{
	playerMovementDirection = _getch();
	switch (playerMovementDirection = _getch())
	{
	case 72:
		findPlayerIcon(map, position);
		if(map[position.playerIconRow-1][position.playerIconColumn]==mapExitIcon)
		{
			--position.playerIconRow;
			endGame();
		}
		else if(map[position.playerIconRow - 1][position.playerIconColumn] == mapFieldIcon)
		{
			delPlayerIcon(map, position);
			--position.playerIconRow;
			drawPlayerIcon(map,position);
		}
		break;
	case 80:
		findPlayerIcon(map, position);
		if (map[position.playerIconRow + 1][position.playerIconColumn] == mapExitIcon)
		{
			++position.playerIconRow;
			endGame();
		}
		else if (map[position.playerIconRow + 1][position.playerIconColumn] == mapFieldIcon)
		{
			delPlayerIcon(map, position);
			++position.playerIconRow;
			drawPlayerIcon(map, position);
		}
		break;
	case 75:
		findPlayerIcon(map, position);
		if (map[position.playerIconRow][position.playerIconColumn-1] == mapExitIcon)
		{
			--position.playerIconColumn;
			endGame();
		}
		else if (map[position.playerIconRow][position.playerIconColumn-1] == mapFieldIcon)
		{
			delPlayerIcon(map, position);
			--position.playerIconColumn;
			drawPlayerIcon(map, position);
		}
		break;
	case 77:
		findPlayerIcon(map, position);
		if (map[position.playerIconRow][position.playerIconColumn + 1] == mapExitIcon)
		{
			++position.playerIconColumn;
			endGame();
		}
		else if (map[position.playerIconRow][position.playerIconColumn + 1] == mapFieldIcon)
		{
			delPlayerIcon(map, position);
			++position.playerIconColumn;
			drawPlayerIcon(map, position);
		}
		break;
	default:
		break;
	}
}
int main()
{
	playerIconPos position;
	Map map;
	showMenu();
	char playerAsk;
	srand(time(NULL));
	std::cin >> playerAsk;
	while (playerAsk != 'y' && playerAsk != 'n')
	{
		std::cin >> playerAsk;
	}
	if (playerAsk == 'y')
	{
		fillMapBorders(map);
		genereteMap(map);
		while (true)
		{
			system("cls");
			showMap(map);
			movePlayerIcon(map, position);
			if (map[position.playerIconRow][position.playerIconColumn] == mapExitIcon)
				break;
		}
	}
	getchar();
	std::cout << "Press ENTER to exit." << std::endl;
	getchar();
	return 0;
}
