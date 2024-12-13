#include "header.h"

int main()
{
    setlocale(0, "ru");

    consoleLogger l1;
    simpleFileLogger l2;
    timedFileLogger l3;
    userLogger user;

    std::string str = "string";
    user.setStrategy(&l1);
    user.log(str);
    user.setStrategy(&l2);
    user.log(str);
    user.setStrategy(&l3);
    user.log(str);
}
