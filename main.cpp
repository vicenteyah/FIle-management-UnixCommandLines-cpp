#include <iostream>
#include "files.h"
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    file init; init.menu();
    while(init.menu()!=11){
        switch(init.menu()){
            case 1: init.option1(); break;
            case 2: init.option2(); break;
            case 3: init.option3(); break;
            case 4: init.option4(); break;
            case 5: init.option5(); break;
            case 6: init.option6(); break;
            case 7: init.option7(); break;
            case 8: init.option8(); break;
            case 9: init.option9(); break;
            case 10: init.option10(); break;
        }
        init.menu();
    }
    system("rm -r DirA");
    system("rm -r DirB");
    return 0;
}
