#include "Wave.h"
#include<fstream>
#include<string>
#include<vector>
using namespace std;

vector<Cell> diff{ {0, -1},{0,-1},{0,1},{1,0} };
Wave::Wave(std::string file_path)
{
	std::cout<< "Ok\n";
	//path//
	string str;
	fstream file;
	file.open("Text.txt", ios::in);
	int rows{};
	while (!file.eof())
	{
	getline(file, str);
	cout << str << endl;
	int code;
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
	bool flag{ false };
	while (true)
	{
		fronts[!indexCurrentFront].clear();
		countFronts++;
		for (auto cell : fronts[indexCurrentFront])
		{
			int row = cell.Row();
			int column = cell.Column();
			for (int i = 0; i < diff.size(); i++)
			{
				int currentCol = column + diff[i].Column();
				int currentRow = row + diff[i].Row();
				if (matrix[currentRow][currentCol].Value() == CellType::Finish)
				{
					matrix[currentRow][currentCol].Value() = countFronts;
					flag = true;
					break;

				}
				if (matrix[currentRow][currentCol].Value() == CellType::Space)
				{
					matrix[currentRow][currentCol].Value() = countFronts;
					fronts[!indexCurrentFront].push_back(Cell(currentRow, currentCol));

				}
			}
			if (flag)
				break;

		}
		if (flag)
			break;
		indexCurrentFront = !indexCurrentFront;
		print();
	}
}

void Wave::print()
{
	cout << "\n";
	for (auto rows : matrix)
	{
		for (auto columns : rows)
		{
			switch ((CellType)columns.Value())
			{
			case CellType::Space:
				cout << ' ';
				break;
			case CellType::Start:
				cout << 'S';
				break;
			case CellType::Wall:
				cout << (char)-78;
				break;
			case CellType::Finish:
				cout << 'F';
				break;
			default:
				cout << columns.Value();
				break;
			}
		}
		cout << "\n";
	}
}
