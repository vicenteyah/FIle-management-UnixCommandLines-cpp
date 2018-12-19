#ifndef FILES_H
#define FILES_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;
class file{
   public:
   void option1();
   void option2();
   void option3();
   void option4();
   void option5();
   void option6();
   void option7();
   void option8();
   void option9();
   void option10();
   void createFile(string file, int times , string content);
   int countLines();
   int menu();
};
int file::menu(){
    int input = 0;
    cout<<" Choose an option:"<<endl;
    cout << "1. Create two DirA and DirB directories and copy five files of different size (mkdir, cp, cat)" << endl;
    cout << "2. look for largest file in (DirB) and the smallest in(DirA)(find, cat) " << endl;
    cout << "3. concatenate two files( cp, cat) " << endl;
    cout << "4. Change owner attribute to DirA files. (chown)" << endl;
    cout << "5. Change write, read and execute permissions of DirB files (chmod)" << endl;
    cout << "6. Change Group permissions to the DirB files. (chgrp)" << endl;
    cout << "7. Search within a text file using the grep command to locate how many times Letter B or b is repeated ( find, cat, grep ) " << endl;
    cout << "8. Create a link from a file in the DirA to a file in the DirB (ln)" << endl;
    cout << "9. Compare the files in the DirB directories and Say the most current and the oldest" << endl;
    cout << "10. Encrypt the contents of a text file and then decrypt it. (gpg)" << endl;
    cout << "11.  Leave:" << endl;
    cout<<"\n Choose an Option (1-10, 11 = exit)"<<endl;
    cin>>input;
    return input;
}
#endif
