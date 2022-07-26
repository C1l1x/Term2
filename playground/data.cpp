/*
Text..
*/


#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class MyProgram
{
private:
    string name;
    int age;
    string address;
public:
    MyProgram();
    void getData(){
        cin.ignore();
        cout << "\nInsert name: "; getline(cin, name);
        cout << "Insert age: "; cin >> age;
        cout << "Insert address: "; getline(cin, address);
    }
    void display(){
        cout << "\nName: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Address: " << address << "\n";
    }
};

int main(){

}