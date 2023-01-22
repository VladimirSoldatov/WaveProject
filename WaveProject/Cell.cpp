#include "Cell.h"

Cell::Cell(int _row, int _column, int _value) :row{ _row }, column{ _column }, value{_value}
{
}



int& Cell::Column()
{
	return column;
}
int& Cell::Row()
{
	return row;
}
int& Cell::Value()
{
	return value;
}
std::ostream& operator<<(std::ostream& out, Cell& obj)
{
	return out << "[" << obj.row << "," << obj.column <<"]";
}
