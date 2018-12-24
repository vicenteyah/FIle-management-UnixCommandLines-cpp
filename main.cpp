#include <iostream>
#include "files.h"
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    file init;int op = init.menu();
    while(op!=11){
        init.select(op);
        op = init.menu();
    }
    system("rm -r DirA");
    system("rm -r DirB");
    return 0;
}
