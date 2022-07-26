/*
До участие в национална олимпиада по програмиране се допускат студенти
(име, ЕГН, университет, факултет, специалност, събрани точки) и ученици
(име, ЕГН, училище, клас, събрани точки). Данните за всички участници се
съхраняват в един масив.
Да се състави програма, която изпълнява от меню следните операции:
- добавя към масива данните на пореден участник;
- извежда всички въведени данни;
- извежда данните на участника с най-много точки;
- създава масив с данните на всички участнички с повече от 30 точки.
*/
#include <iostream>
#include <string>

using namespace std;

class Participants{
public:
    virtual void getData() = 0;
    virtual void display() = 0;
    virtual float getPoints(){
        return 0;
    }
    virtual string getEGN(){
        return 0;
    }
    virtual bool WomenCheck(){
        return 0;
    }
    virtual bool WomenWith30pplus(){
        return 0;
    }
};

class CollegeSt : public Participants{
private:
    string Name, EGN, University, Facolty, Spec;
    float Points;
public:
    void getData(){
        cin.ignore();
        cout << "\nInsert name: "; getline(cin, Name);
        while (true){
            cout << "Insert EGN: "; getline(cin, EGN);
            if (EGN.length() == 10){
                break;
            }
            else
                cout << "EGN shoud be 10 digits!\n";
        }
        cout << "Insert university: "; getline(cin, University);
        cout << "Insert facolty: "; getline(cin, Facolty);
        cout << "Insert spec: "; getline(cin, Spec);
        cout << "Insert points: "; cin >> Points;
    }
    void display(){
        cout << "Name: " << Name << endl;
        cout << "EGN: " << EGN << endl;
        cout << "University: " << University << endl;
        cout << "Facolty: " << Facolty << endl;
        cout << "Spec: " << Spec << endl;
        cout << "Points: " << Points << endl;
    }
    float getPoints(){
        return Points;
    }
    string getEGN(){
        return EGN;
    }
    bool WomenCheck(){
        if (stoi(EGN.substr(8, 1)) % 2 == 1){
            return true;
        }
        else
            return false;
    }
    bool WomenWith30pplus(){
        if (WomenCheck() && Points >= 30){
            return true;
        }
        else
            return false;
    }
};

class Students: public Participants{
private:
    string Name, EGN, School;
    int Class;
    float Points;
public:
    void getData(){
        cin.ignore();
        cout << "\nInsert name: ";
        getline(cin, Name);
        while (true){
            cout << "Insert EGN: "; getline(cin, EGN);
            if (EGN.length() == 10){
                break;
            }
            else
                cout << "EGN shoud be 10 digits!\n";
        }
        cout << "Insert school: "; getline(cin, School);
        while (true){
            cout << "Insert class: "; cin >> Class;
            if (Class < 13 && Class > 0){
                break;
            }
            else
                cout << "Wrong input!!!\n";
        }
        cout << "Insert points: "; cin >> Points;
    }
    void display(){
        cout << "Name: " << Name << endl;
        cout << "EGN: " << EGN << endl;
        cout << "School: " << School << endl;
        cout << "Class: " << Class << endl;
        cout << "Points: " << Points << endl;
    }
    float getPoints(){
        return Points;
    }
    string getEGN(){
        return EGN;
    }
    bool WomenCheck(){
        if (stoi(EGN.substr(8, 1)) % 2 == 1){
            return true;
        }
        else
            return false;
    }
    bool WomenWith30pplus(){
        if (WomenCheck() && Points >= 30){
            return true;
        }
        else
            return false;
    }
};

void TopPoints(Participants *P[], int brP){
    float a = 0;
    for (int i = 0; i < brP; i++){
        if (a < P[i]->getPoints()){
            a = P[i]->getPoints();
        }
    }
    for (int i = 0; i < brP; i++){
        if (a == P[i]->getPoints()){
            cout << "Participant with the most points:\n";
            P[i]->display();
        }
    }
    a = 0;
}

int main(){
    char Input = true;
    Participants *P[100];
    Participants *W[100];
    int choice = 0, brP = 0, brW = 0;

    do{
        cout << "\n------MENU------\n";
        cout << "1. Add data for school student.\n";
        cout << "1. Add data for college student.\n";
        cout << "3. Display all data.\n";
        cout << "4. Person with the most points.\n";
        cout << "5. Creates a new array with all girls with more than 30 points.\n";
        cout << "6. Check new array.\n";
        cout << "0. Exit!!!\n";
        cout << "Input: ";
        cin >> Input;
        switch (Input){
        case '0':
            Input = false;
            break;
        case '1':
            P[brP] = new Students;
            P[brP++]->getData();
            break;
        case '2':
            P[brP] = new CollegeSt;
            P[brP++]->getData();
            break;
        case '3':
            for (int i = 0; i < brP; i++){
                cout << "\nParticipant N " << i + 1 << " :\n";
                P[i]->display();
            }
            break;
        case '4':
            TopPoints(P, brP);
            break;
        case '5':
            for (int i = 0; i < brP; i++){
                if (P[i]->WomenWith30pplus()){
                    W[brW++] = P[i];
                }
            }
            cout << "\nNew arr is created!\n";
            break;
        case '6':
            for (int i = 0; i < brW; i++){
                W[i]->display();
            }
            break;
        default:
            cout << "Wtong input!!!\n";
        }
    } while (Input != false);
    return 0;
}