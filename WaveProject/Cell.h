#pragma once
#include<iostream>

enum CellType
{
	Space = -1,
	Wall = -3,
	Start = 0,
	Finish = -2
};
class Cell
{
	int row;
	int column;
	int value;

	friend std::ostream& operator<<(std::ostream& out, Cell& obj);
public:
	Cell(int _row = 0, int _column = 0, int _value = CellType::Space);
	int& Row();
	int& Column();
	int& Value();
};