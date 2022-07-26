/*
V gradinski tsentar se prodavat rasteniya (naimenovanie, tsena, broy), koito bivat darveta (visochina,
vid(iglolistni/shirokolistni)) i tsvetya (tsvyat). Dannite za vsyako rastenie se sahranyava v masiv.
Da se sastavi programa, koyato izpalnyava ot menyu slednite operatsii:
-    dobavya kam masiva dannite na novo rastenie;
-    izvezhda vsichki vavedeni danni;
-    izvezhda danni za iglolistnite darveta;
-    sazdava masiv s dannite na rasteniyata s tsena pod 10lv.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Plant{
private:
    string name;
    float price;
    int count;
public:
    Plant(){

    }
    void getData(fstream &myFile, int br){
        cin.ignore();
        cout << "Insert name: "; getline(cin, name);
        cout << "Insert price: "; cin >> price;
        cout << "Insert count: "; cin >> count;
        myFile.open("ReadFile.txt", ios::app);
        if(myFile.is_open()){
            myFile << name << "^" << price << "^" << count << "^\n";
            myFile.close();
        }
    }
    void display(fstream myFile){
        myFile.open("ReadFile.txt");
        if(myFile.is_open()){
            cout << "Name: " << name << "\n"; 
            cout << "Price: " << price << "\n";
            cout << "Count: " << count << "\n"; 
        }
    }
};

int main(){
    char Input = true;
    Plant plants[100];
    fstream myFile;
    int br = 0;
    
    
    do{
        cout << "\n------MENU-----\n";
        cout << "1. Insert data.\n";
        cout << "2. Display data.\n";
        cout << "3. \n";
        cout << "4. \n";
        cout << "5. \n";
        cout << "6. \n";
        cout << "0. Exit.\n";
        cout << "Insert number: "; cin >> Input;

        switch (Input) {
            case '0': 
            Input = false; break;
            case '1':
                plants[br++].getData(myFile, br);
                break;
            case '2':
                myFile.open("ReadFile.txt");
                if(myFile.is_open()){
                    string Read;
                    while(getline(myFile, Read)){
                        cout << Read << "\n";
                    }
                }myFile.close();
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

}