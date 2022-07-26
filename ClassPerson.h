#include<string>
#include<iostream>

using namespace std;

class Person{
private:
    string Name;
    string EGN;
public:
    Person(){

    }
    Person(string, string){
    
    }
    void getData(){
        cin.ignore();
        cout << "\nInsert name: "; getline(cin, Name);
        while(true){
            cout << "Insert EGN: "; getline(cin, EGN);
            if(EGN.length() == 10){
                break;
            }else
            cout << "EGN shoud be 10 digits!\n";
        }

    }
    void display(){
        cout << "\nName: " << Name << endl;
        cout << "EGN: " << EGN << endl;
    }
    string getName(){
        return Name;
    }
    string getEGN(){
        return EGN;
    }
    bool WomenCheck(){
        if(stoi(EGN.substr(8,1))%2 == 1){
            return true;
        }else 
        return false;
    }
};
