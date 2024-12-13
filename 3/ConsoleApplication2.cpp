#include "header.h"

int main()
{
    setlocale(LC_ALL, "RU");
    std::cout << "goodbye World >:)\n";
    int* a1 = new int;
    *a1 = 6066;
    std::string* a2 = new std::string;
    *a2 = "GOODBYE";
    double* a3 = new double;
    *a3 = 1.68;
    mns::UPtrArr<int> ptrInt(a1);
    std::cout << "int: " << ptrInt.dai() << std::endl;
    mns::UPtrArr<std::string> ptrString(a2);
    std::cout << "string: " << ptrString.dai() << std::endl;
    mns::UPtrArr<double> ptrDouble(a3);
    std::cout << "double: " << ptrDouble.dai() << std::endl;
}
