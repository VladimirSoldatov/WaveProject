#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    int mas[10][10];


    size_t  size1 = 0;
   for (auto item : mas)
    {
       size1++;
    }
   
   size_t size2 = sizeof(mas) / (sizeof(int) * size1);
   std::cout <<"Size mas is " << size1 << " on " << size2 <<"\n";
    
}
