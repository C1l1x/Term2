/*
Да се състави програма за нуждите на хотел, която поддържа в масив
следната информация за гостите на хотела:
    - име;
    - ЕГН;
    - семейно положение(1-несемеен, 2-семеен);
    - брой нощувки - цяло число;
    - цена на ползваното легло - реално число;
    - населено място;
И извършва следните операции, избрани от меню:
    - записва в едномерен масив въведените данни;
    - извежда на екрана всички въведени данни;
    - извежда на екрана имената и заплатената сума от семейните
гости, пребивавали повече от 5 дни;
    - създава нов масив с данните на несемейните гости от посоченото населено място.
*/

#include <iostream>
#include <string>

using namespace std;

class Guest{
private:
    int Status, Nights;
    float BedPrice;
    string City, Name, EGN;

public:
    Guest(){

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
        cout << "Insert city: "; getline(cin, City);
        while (true){
            cout << "Type 1 if you are unmarried, type 2 if you are married:"; cin >> Status;
            if (Status <= 2){
                break;
            }else
                cout << "\nWrong input!!!\n";
        }
        cout << "Insert stay time: "; cin >> Nights;
        cout << "Insert bed price per night: "; cin >> BedPrice;
    }
    void display(){
        cout << "Name: " << Name << endl;
        cout << "EGN: " << EGN << endl;
        cout << "City: " << City << endl;
        if (Status == 1)
        {
            cout << "Status: Unmarried" << endl;
        }
        else
            cout << "Status: Married" << endl;
        cout << "Stay time: " << Nights << endl;
        cout << "Bed price per night: " << BedPrice << endl;
    }
    string getName(){
        return Name;
    }
    string getEGN(){
        return EGN;
    }
    int getStatus(){
        return Status;
    }
    int getNights(){
        return Nights;
    }
    float getBedPrice(){
        return BedPrice;
    }
    string getCity(){
        return City;
    }
};

void PriceOfMarriedAbove5(Guest Guests[], int brGuest, float price){
    float sum = 0;
    string n;
    for (int i = 0; i < brGuest; i++){
        if (Guests[i].getStatus() == 2){
            if (Guests[i].getNights() > 5){
                sum = Guests[i].getBedPrice() * Guests[i].getNights();
                price = sum * 2;
                n = Guests[i].getName();
                cout << "\nGuest N " << i + 1 << " :\n";
                cout << "Name: " << n << endl;
                cout << "Price for staying: " << price << " BGN" << endl;
            }
        }
    }
}

int main(){
    string newCity;
    char Input = true;
    Guest Guests[100];
    Guest UnmarriedGuests[100];
    int brGuest = 0, brUnmGuests = 0;
    float price = 0;

    do{
        cout << "\n------MENU------\n";
        cout << "1. Insert data.\n";
        cout << "2. Display data.\n";
        cout << "3. Displays the names and price from married guests staying more than 5 days.\n";
        cout << "4. Creates a new array with the data of the unmarried guests from the inserted city.\n";
        cout << "5. Display a new array.\n";
        cout << "0. Exit.\n";
        cout << "Insert number: ";
        cin >> Input;

        switch (Input){
        case '0': Input = false; break;
        case '1': Guests[brGuest++].getData(); break;
        case '2':
            for (int i = 0; i < brGuest; i++){
                cout << "\nGuest N " << i + 1 << " :\n";
                Guests[i].display();
            } break;
        case '3': PriceOfMarriedAbove5(Guests, brGuest, price); break;
        case '4': cin.ignore();
            cout << "\nInsert City: "; getline(cin, newCity);
            for (int i = 0; i < brGuest; i++){
                if (Guests[i].getCity() == newCity){
                    if (Guests[i].getStatus() == 1){
                        UnmarriedGuests[brUnmGuests++] = Guests[i];
                    }
                }
            } 
            cout << "The new array is created!\n"; break;
        case '5':
            for (int i = 0; i < brUnmGuests; i++){
                cout << "\nGuest N " << i + 1 << " :\n";
                UnmarriedGuests[i].display();
            } break;
        default: cout << "You insert wrong number.\n";
        }
    } while (Input != false);
    return 0;
}