#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int main(){
    char Input = true;
    class a;
    fstream myFile;
    int br = 0;

    do{
        cout << "\n------MENU-----\n";
		cout << "1. \n";
        cout << "2. \n";
		cout << "3. \n";
		cout << "4. \n";
        cout << "5. \n";
        cout << "6. \n";
		cout << "0. Exit.\n";
		cout << "Insert number: "; cin >> Input;

		switch (Input) {
            case '0': 
            Input = false; ; break;
            case '1':
                
                break;
            case '2':
                
                break;
            case '3':
                
                break;
            case '4':
                
                break;
            case '5': 
                
                break;
            case '6':
                
                break;
            default: cout << "\nWrong number!\n";
        }
    }while(Input != false);

    return 0;
}