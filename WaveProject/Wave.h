#pragma once
#include<vector>
#include"Cell.h"
class Wave
{
	std::vector<std::vector<Cell>> matrix;
	Cell start;
	Cell finish;

public:
	Wave(std::string file_path);
	void createWave();
	void print();
	void createWave();

};

