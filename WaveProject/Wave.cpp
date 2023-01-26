#include "Wave.h"
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

vector<Cell> diff{ {0, -1},{0,1},{-1,0},{1,0} };
Wave::Wave(std::string file_path)
{
	int steps = 0;
	std::cout<< "Ok\n";
	path = vector<Cell>();
	string str;
	fstream file;
	file.open("Text.txt", ios::in);
	int rows{};
	while (!file.eof())
	{
	getline(file, str);
	cout << str << endl;
	int code = 0;
	int columns{};
	vector<Cell> line;
		while (str[columns])
		{
			
			switch (str[columns])
			{
			case ' ':
				code = CellType::Space;
				break;
			case 'S':
				code = CellType::Start;
				start = Cell(rows, columns);
				break;
			case 'F':
				code = CellType::Finish;
				finish = Cell(rows, columns);
				break;
			case '#':
				code = CellType::Wall;
			default:
				break;
			}
			line.push_back(Cell(rows, columns, code));
			columns++;
		}
		matrix.push_back(line);
		rows++;
	}
	
	file.close();
	

}

void Wave::createWave()
{
	vector<Cell> fronts[2];
	bool indexCurrentFront{ false };
	int countFronts = 0;
	fronts[indexCurrentFront].push_back(start);
	isFinish = false;
	int row = -5;
	int column = -5;
	while (true)
	{
		fronts[!indexCurrentFront].clear();
		steps++;
		for (auto cell : fronts[indexCurrentFront])
		{
	
			row = cell.Row();
			column = cell.Column();
			for (int i = 0; i < diff.size(); i++)
			{
				int currentCol = column + diff[i].Column();
				int currentRow = row + diff[i].Row();
				if (matrix[currentRow][currentCol].Value() == CellType::Finish)
				{
					//matrix[currentRow][currentCol].Value() = steps;
					isFinish = true;
					print();
					break;

				}
				if (matrix[currentRow][currentCol].Value() == CellType::Space)
				{
					matrix[currentRow][currentCol].Value() = steps;
					fronts[!indexCurrentFront].push_back(Cell(currentRow, currentCol));

				}
			}
			if (isFinish)
				break;

		}
		if (isFinish)
			break;
		if (fronts->size() == 0)
		{
			cout << "No variant\n";
			return;
		}
		indexCurrentFront = !indexCurrentFront;
		print();
	}
	
}


void Wave::print()
{

	cout << "\n";
	int row = 0;
	int column;
	for (auto rows : matrix)
	{
		column = 0;
		for (auto columns : rows)
		{
			switch ((CellType)columns.Value())
			{
			case CellType::Space:
				cout << setw(2)<< ' ';
				break;
			case CellType::Start:
				cout << setw(2) << 'S';
				break;
			case CellType::Wall:
				cout << (char)-78 << (char)-78;
				break;
			case CellType::Finish:
				cout << setw(2) << 'F';
				break;
			default:
				if (path.size())
				{
					vector<Cell>::iterator result = find_if(path.begin(), path.end(),
						[row, column](auto cell)
						{
							return row == cell.Row() && column == cell.Column();
						}); //Предикат - это лямда функция которая возращает истина или ложь
					if (result != path.end())
					{
						cout << setw(2) << columns.Value();
					}
					else
					{
						cout << setw(2) << " ";
					}
				}
				else
					cout << setw(2) << columns.Value();
				break;
			}
			column++;
		}
		row++;
		cout << "\n";
	}
}

void Wave::createPath()
{
	if (!isFinish)
		return;
		
	path.push_back(finish);

	int numberWave = steps;
	while (numberWave)
	{
		
		int row = path.back().Row();
		int col = path.back().Column();
		for (int i = 0; i < diff.size(); i++)
		{
			int drow = row + diff[i].Row();
			int dcol = col + diff[i].Column();
			int curValue = matrix[drow][dcol].Value();
			if (curValue == numberWave - 1)
			{
				numberWave--;
				path.push_back(Cell(drow, dcol, numberWave));
			
				break;
			}

		}
	}
}
