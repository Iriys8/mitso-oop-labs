#include "header.h"

int main()
{
    setlocale(0, "ru");
    magicVector<int> magic_int;
    magic_int.pushVector({ 1,2,3 });
    magic_int.pushVector({ 4,5,6 });
    std::vector<int> vector1 = magic_int.topVector();
    magic_int.popVector();
    std::vector<int> vector2 = magic_int.topVector();
    magic_int.popVector();
    for (int i = 0; i <= 2; i++) {
        std::cout << vector1[i];
    }
    for (int i = 0; i <= 2; i++) {
        std::cout << vector2[i];
    }
    std::cout << " -int" << std::endl;
    magicVector<std::string> magic_string;
    magic_string.pushVector({ "1","2","3" });
    magic_string.pushVector({ "4","5","6" });
    std::vector<std::string> vector3 = magic_string.topVector();
    magic_string.popVector();
    std::vector<std::string> vector4 = magic_string.topVector();
    magic_string.popVector();
    for (int i = 0; i <= 2; i++) {
        std::cout << vector3[i];
    }
    for (int i = 0; i <= 2; i++) {
        std::cout << vector4[i];
    }
    std::cout << " -string" << std::endl;
    magicVector<double> magic_double;
    magic_double.pushVector({ 1.0,2.0,3.0 });
    magic_double.pushVector({ 4.0,5.0,6.0 });
    std::vector<double> vector5 = magic_double.topVector();
    magic_double.popVector();
    std::vector<double> vector6 = magic_double.topVector();
    magic_double.popVector();
    for (int i = 0; i <= 2; i++) {
        std::cout << vector5[i];
    }
    for (int i = 0; i <= 2; i++) {
        std::cout << vector6[i];
    }
    std::cout << " -double" << std::endl << std::endl;

    /////////////////////////////////////////////////////////////////////////////////////////

    std::cout << "Iterators" << std::endl << std::endl;

    magic_int.pushVector({ 7,8,9 });
    magic_int.pushVector({ 10,11,12 });
    auto stackIt = magic_int.getStackIterator();
    while (stackIt.hasNext()) {
        auto vec = stackIt.next();
        std::cout << "Vector in stack: ";
        for (auto val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    magic_string.pushVector({ "one","two","three" });
    magic_string.pushVector({ "four","five","six" });
    auto vec = magic_string.topVector();
    auto vectorIt = magic_string.getVectorIterator(vec);
    std::cout << "Top vector elements: ";
    while (vectorIt.hasNext()) {
        std::cout << vectorIt.next() << " ";
    }
    std::cout << std::endl;
}
