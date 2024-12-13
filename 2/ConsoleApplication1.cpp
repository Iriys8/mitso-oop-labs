#include "header.h"

using namespace mns;

int main()
{
    setlocale(0, "ru");
    std::cout << "goodbye World >:)\n";
    int m;
    double z1, z2;
    try {
        std::cin >> m;
        if (m == 0)
            throw m;
        else if (m == -4)
            throw m;
        z1 = (sqrt(2 * m + 2 * sqrt(pow(m, 2) - 4))) / (m + sqrt(pow(m, 2) - 4) + 2);
        z2 = 1 / sqrt(m + 2);
        std::cout << z1 << " " << z2;
    }
    catch (int e) {
        nexochy_raboat::oshibka(e);
    }
}