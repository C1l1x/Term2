#include<iostream>

using namespace std;


class Date{
private:
    int Day;
    int Month;
    int Year;
public:
    Date(){

    }
    Date(int, int, int){

    }
    void getData(){
        while(true){
            cout << "Insert day: "; cin >> Day;
            if (Day <= 31){
                break;
            }else
            cout << "Wrong Input!!!\n";
        }
        while(true){
            cout << "Insert month: "; cin >> Month;
            if (Month <= 12){
                break;
            }else
            cout << "Wrong Input!!!\n";
        }
        cout << "Insert year: "; cin >> Year;
        
    }
    void display(){
        cout << "Day: " << Day << endl;
        cout << "Month: " << Month << endl;
        cout << "Year: " << Year << endl;
    }
    int getDay(){
        return Day;
    }
    int getMonth(){
        return Month;
    }
    int getYear(){
        return Year;
    }
};
