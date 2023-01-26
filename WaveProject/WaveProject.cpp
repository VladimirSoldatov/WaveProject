#include <iostream>
#include"Wave.h"
#include<map>
#include<algorithm>

int main()
{
	std::map<int, std::string> steps{ {1, "Cat"},{2,"Dog"}};
	int a = 6;
	auto result = std::find_if(steps.begin(), steps.end(), 
		[a](std::pair<int, std::string> temp) {return temp.second == "Cat"; });
	if (result != steps.end())
		std::cout << "Yes\n";
	else
	{
		std:: cout << "No\n";
	}
	
	Wave p("Text.txt");
	p.print();
	p.createWave();
	p.createPath();
	p.print();
}
