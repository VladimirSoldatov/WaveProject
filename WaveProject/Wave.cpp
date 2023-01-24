#include "Wave.h"
#include<fstream>
#include<string>
using namespace std;

Wave::Wave(std::string file_path)
{
	std::cout<< "Ok\n";
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
				break;
			case 'F':
				code = CellType::Finish;
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

}

void Wave::print()
{
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
				break;
			}
		}
		cout << "\n";
	}
}
