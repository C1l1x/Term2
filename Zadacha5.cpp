/*
Да се създаде клас CPerson, съдържащ следните членове:
    - име;
    - ЕГН;
    - конструктори - без аргументи и с входни аргументи за всички данни;
    - член-функции getData и display;
Да се създаде произволен клас CStudent, който съдържа:
    - факултетен номер;
    - оценки по 5 дисциплини;
    - конструктори (с извикване на конструктор на базовия клас);
    - член-функции getData и display;
    - член-функция за изчисляване на среден успех.
Да се създаде клас-контейнер CGroup, който съхранява данните за група студенти, с член-функции:
    - за добавяне на нов студент;
    - за намиране на средния успех на групата.
Да се състави програма, която чрез меню, управлява обект от клас CGroup.
Задача 2:
    - да се добави брой оценки k (k<=10) на един студент;
    - в CStudent да се добави член функция, която проверява дали студента има поне една 2-ка;
    - в CGtoup да се добави функция, която извежда данните на студентите с двойки;
*/

#include <iostream>
#include <string>

using namespace std;

class CPerson{
private:
    string Name;
    string EGN;
public:
    CPerson(): Name(""), EGN(""){

    }
    void getData(){
        cout << "Insert name: "; getline(cin, Name);
        cout << "Insert EGN: "; getline(cin, EGN);
    }
    void display(){
        cout << "Name: " << Name << endl;
        cout << "EGN: " << EGN << endl;
    }
};

class CStudent:public CPerson{
private:
    string FacNum;
    float Grade[5];
public:
    CStudent(): CPerson(), FacNum(""), Grade{0}{

    }
    void getData();
    void display();
};
void CStudent::getData(){
    CPerson::getData();
    cout << "Insert fac.num.: "; getline(cin, FacNum);
    for(int i = 0; i < 4; i++){
        cout << "Insert grade: "; cin >> Grade[i];
    }
}


int main(){
    CStudent students[20];
    int input,studentNum = 0;
    bool check = true;

    while(check){
        cout<<"\n1. New Student\n";
        cout<<"2. Display all students\n";
        cout<<"3. Average mark\n";
        cout<<"4. Check for bad mark\n";
        cout<<"5. Display students with bad marks\n";
        cout<<"0. Exit!!!\n";
        cout<<"-> ";
        cin>>input; cin.ignore();
        switch(input){
            case 1:
            students[studentNum++].getData(); break;
            



            case 0:
            check = false;
            break;
            default:
            cerr<<"Wrong inmput"<<endl;
        }


    }
    return 0;
}