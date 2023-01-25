#pragma once
#include<vector>
#include"Cell.h"
class Wave
{
	std::vector<std::vector<Cell>> matrix;
	Cell start;
	Cell finish;
	bool isFinish;
	std::vector<Cell> path;
	int steps;

public:
	Wave(std::string file_path);
	void createWave();
	void print();
	void createPath();
	
	
};


