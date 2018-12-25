#ifndef FILES_H
#define FILES_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <unistd.h>
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
   void createFile(string, int, string);
   void select(int select);
   int countLines(string);
   int menu();
};
int file::menu(){
    int input = 0;
    cout<<" Choose an option:"<<endl;
    cout << "[1]. Create two DirA and DirB directories and copy five files of different size (mkdir, cp, cat)" << endl;
    cout << "[2]. look for largest file in (DirB) and the smallest in(DirA)(find, cat) " << endl;
    cout << "[3]. concatenate two files( cp, cat) " << endl;
    cout << "[4]. Change owner attribute to DirA files. (chown)" << endl;
    cout << "[5]. Change write, read and execute permissions of DirB files (chmod)" << endl;
    cout << "[6]. Change Group permissions to the DirB files. (chgrp)" << endl;
    cout << "[7]. Search within a text file using the grep command to locate how many times Letter B or b is repeated ( find, cat, grep ) " << endl;
    cout << "[8]. Create a link from a file in the DirA to a file in the DirB (ln)" << endl;
    cout << "[9]. Compare the files in the DirB directories and Say the most current and the oldest" << endl;
    cout << "[10]. Encrypt the contents of a text file and then decrypt it. (gpg)" << endl;
    cout << "[11].  Leave:" << endl;
    cout<<"\n Choose an Option (1-10, 11 = exit): ";
    cin>>input;
    return input;
}
void file::createFile(string file,int times, string content){
    ofstream txt(file.c_str());
    string command;
    txt << content << endl;
    for(int i = 0; i < times ;i++)
    { system(("cat" + file + " " + file + ">> temp.txt && mv temp.txt " + file).c_str());}
}
int file::countLines(string file){
    ifstream txt(file.c_str());
    string line;
    int c = 0;
    while (getline(txt, line)){
        c++;
    }
    return c;
}
void file::option1(){
    system("mkdir DirA");
    system("mkdir DirB");
    string dir[10] = {"DirA/A1.txt", "DirA/A2.txt", "DirA/A3.txt", "DirA/A4.txt", "DirA/A5.txt",
                      "DirB/B1.txt", "DirB/B2.txt", "DirB/B3.txt", "DirB/B4.txt", "DirB/B5.txt"};
    string message[10]={"hello","A2 Baron Belcebu","hello :v","hi >:v"," a*1+b*3","hello teacher",
                        "B2 file text","this is B3 file","playground","all hope is gone"};
    for(int i = 0;i<10;i++){
        createFile(dir[i],10,message[i]);
    }
    cout <<" DIRECTORIES AND FILES WAS CREATED SUCCESFULLY\n"<<endl;
}
void file::option2(){
    cout << "\n========================================" << endl;
    cout << "" << endl;
    cout << "files greater than 100kb in DirB:" << endl;
    system("find DirB -size +100k");
    cout << endl;
    cout << "\nfiles less than 100kb in DirA:" << endl;
    system("find DirB -size -100k");
    cout << "DONE!\n"<< endl;
    cout << "========================================\n"<< endl;
}
void file::option3(){
    cout << "\n========================================" << endl;
    cout << "" << endl;
    cout << "Concatenating DirA/A2.txt with DirB/B1.txt" << endl;
    system("cat <DirA/A2.txt DirB/B1.txt >> DirA/A2.txt");
    //system("cat < ~/DirA/A2.txt >> ~/DirB/B1.txt");
    cout << "DONE!\n"
         << endl;
    cout << "========================================\n"
         << endl;
}
void file::option4(){
    cout << "\n========================================" << endl;
	cout << "" << endl;
	system("sudo chown -R root DirA/");
    cout << "OWNER OF THE ARCHIVES OF THE DirA CHANGED TO ROOT!\n"<< endl;
    cout << "DONE!\n" << endl;
	cout << "========================================\n" << endl;
}
void file::option5(){
    cout << "\n========================================" << endl;
	cout << "" << endl;
	system("chmod -R 774 DirB"); //permisos de lectura, escritura y ejecucion para Usuario y Grupo, solo lectura para Otros
    cout << "READING PERMITS CHANGED TO THE DirB, WRITING AND EXECUTION ARCHIVES FOR USER AND GROUP, READING ONLY FOR OTHERS!\n"
         << endl;
    cout << "DONE!\n" << endl;
	cout << "========================================\n" << endl;
}
void file::option6(){
    cout << "\n========================================" << endl;
	cout << "" << endl;
	system("sudo chgrp -R root DirB");
    cout << "GROUP OF THE ARCHIVES OF DirB CHANGED TO ROOT!\n"<< endl;
    cout << "DONE!\n" << endl;
	cout << "========================================\n" << endl;
}
void file::option7(){
    cout << "\n========================================" << endl;
	cout << "" << endl;
	system("grep --ignore-case --only-matching --no-filename 'b' DirA/A2.txt > conteo.txt");
    cout << "THE TIMES THAT THE LETTER 'B' IS REPEATED IN THE FILE A2.txt OF DirA S:\n"<< countLines("conteo.txt") << endl;
    system("rm conteo.txt");
	cout << "HECHO!\n" << endl;
	cout << "========================================\n" << endl;
}
void file::option8(){

	cout << "\n========================================" << endl;
	cout << "" << endl;
	system("ln DirB/B3.txt DirA/B3-enlace.txt");
	cout << "LINK TO B3.txt CREATED IN DirA SUCCESFULLY" << endl;
	cout << "DONE!\n" << endl;
	cout << "========================================\n" << endl;
}
void file::option9(){
    cout << "\n========================================" << endl;
    cout << "Compare the files of the DirA and DirB directories" << endl;
    cout << "The oldest file in the DirA directory";
    system("find DirA -ls -mtime +1 | head -2");cout<<endl;
    cout << "The most current file in the DirB directory" << endl;
    system("find DirB -ls -mtime -1 | head -2");
	sleep(2);
	
	cout << "DONE!\n" << endl;
	cout << "========================================\n" << endl;
}
void file::option10(){
   char in;
	cout << "\n========================================" << endl;
	cout << "" << endl;
	system("gpg -c DirA/A4.txt");
	system("rm DirA/A4.txt");
	remove("DirA/A4.txt");
    cout << "'DirA/A4.txt' ENCRYPTED CORRECTLY, DO YOU WANT TO DECRYPT IT NOW? (Y / n)" << endl;
    cin >> in;
	if(in == 'y')
	{
		system("gpg DirA/A4.txt.gpg");
        cout << "Decrypted FILE SUCCESSFULLY!!" << endl;
        remove("DirA/A4.txt.gpg");
	}
	cout << "DONE!\n" << endl;
	cout << "========================================\n" << endl;
}
void file::select(int select){
  
  switch (select)
    {
        case 1: option1(); break;
        case 2: option2(); break;
        case 3: option3(); break;
        case 4: option4(); break;
        case 5: option5(); break;
        case 6: option6(); break;
        case 7: option7(); break;
        case 8: option8(); break;
        case 9: option9(); break;
        case 10:option10(); break;
    }
}
#endif
