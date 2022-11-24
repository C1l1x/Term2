/*
Група делегати на национална конференция:
(име, ЕГН, населено място, пътни разходи) са настанени в няколко хотела
(име на хотела, номер на стаята, цена на нощувката).
Всеки делегат получава делигатска карта с вписани:
делегатски номер (6 знака), дата на пристигане, дата на отпатуване.
Данните за всеки делегат, хотела, в който е настанен, и неговата делегатска карта се съхраняват в масив.
Да се състави програма, която изпълнява от меню следните операции:
    - добавя към масива данните на нов делегат, делегатската му карта и хотела, в който е настанен;
    - извежда всички въведени данни;
    - намира сумата, която трябва да се заплати на посочен хотел за нощувките на делегатите от зададено
населено място;
    - извежда името на най-рано пристигналия делегат мъж и данните за хотела, в който е настанен;
    - създава масив с данните за делегатите (име, ЕГН, населено място, пътни разходи) от 
посочено населено място;
*/

#include <iostream>
#include <string>

using namespace std;

class Delegate{
private:
    string Name, EGN, City;
    float TravelExpens; 
public:
    Delegate(){

    }
    void getData(){
        cin.ignore();
        cout << "\nInsert Name: "; getline(cin, Name);
        cout << "Insert EGN: "; getline(cin, EGN);
        cout << "Insert City: "; getline(cin, City);
        cout << "Insert travel expenses: "; cin >> TravelExpens;
    }
    void display(){
        cout << "Name: " << Name << "\n";
        cout << "EGN: " << EGN << "\n";
        cout << "City: " << City << "\n";
        cout << "Travel expenses: " << TravelExpens << "\n";
    }
    string getName(){
        return Name;
    }
    string getEGN(){
        return EGN;
    }
    string getCity(){
        return City;
    }
    float getTrExpen(){
        return TravelExpens;
    }
};

class Hotel{
private:
    string HotelName;
    int RoomNumber;
    float NightPrice;
public:
    Hotel(){

    }
    void getData(){
        cin.ignore();
        cout << "Insert hotel name: "; getline(cin, HotelName);
        cout << "Insert room number: "; cin >> RoomNumber;
        cout << "Insert price per night: "; cin >> NightPrice;
    }
    void display(){
        cout << "Hotel name: " << HotelName << "\n";
        cout << "Room number: " << RoomNumber << "\n";
        cout << "Hotel name: " << HotelName << "\n";
    }
    string getHotelName(){
        return HotelName;
    }
    int getRoomNumber(){
        return RoomNumber;
    }
    float getNightPrice(){
        return NightPrice;
    }
};

class DelegateCard: public Hotel , public Delegate{
private:
    string CardNum;
    int D, M, Y, Day, Month, Year;
public:
    DelegateCard(){

    }
    void getData(){
        Delegate::getData();
        Hotel::getData();
        while(true){
            cout << "Insert card number: "; getline(cin, CardNum);
            if(CardNum.length() == 6){
                break;
            }else
                cout << "\nWrong input!!!\n";
        }
        while(true){
            cout << "Insert arrival date: \n";
            cout << "DD//MM//YYYY\n"; cin >> D; cin >> M; cin >> Y;
            if(D < 32 && M < 13 && Y > 1000){
                break;
            }else
                cout << "\nWrong input!!!\n";
        }
        while(true){
            cout << "Insert departure date: \n";
            cout << "DD//MM//YYYY\n"; cin >> Day; cin >> Month; cin >> Year;
            if(Day < 32 && Month < 13 && Year > 1000){
                break;
            }else
                cout << "\nWrong input!!!\n";
        }
        cin.ignore();
    }
    void display(){
        Delegate::display();
        Hotel::display();
        cout << "Card number: " << CardNum << "\n";
        cout << "Arrival date: " << D << "." << M << "." << Y << ".\n";
        cout << "Departure date: " << Day << "." << Month << "." << Year << ".\n";
    }
    int getArrDay(){
        return D;
    }
    int getArrMonth(){
        return M;
    }
    int getArrYear(){
        return Y;
    }
    int getDepDay(){
        return Day;
    }
    int getDepMonth(){
        return Month;
    }
    int getDepYear(){
        return Year;
    }
    
};

void DelegateSumPaid(DelegateCard Delegates[], int DelCount, string newCity, string newHotelName){
    float b = 0;
    for(int i = 0; i < DelCount; i++){
        if(Delegates[i].getCity() == newCity && Delegates[i].getHotelName() == newHotelName){
            if(Delegates[i].getArrDay() > Delegates[i].getDepDay()){
                b = Delegates[i].getArrDay() - Delegates[i].getDepDay();
                b *= Delegates[i].getNightPrice();
                cout << "\n Delegate N " << i+1 << " :\n";
                cout << "Sum: " << b << "\n";
            }else if(Delegates[i].getArrDay() < Delegates[i].getDepDay()){
                b = Delegates[i].getDepDay() - Delegates[i].getArrDay();
                b *= Delegates[i].getNightPrice();
                cout << "\n Delegate N " << i+1 << " :\n";
                cout << "Sum: " << b << "\n";
            }
        }
        b = 0;
    }
}

bool MaleCheck(DelegateCard Delegates[], int DelCount){
    for(int i = 0; i < DelCount; i++){
        if(stoi(Delegates[i].getEGN()) %2 == 0){
            return true;
        }else
            return false;
    }
}

void EarlyArrivedDelegate(DelegateCard Delegates[], int DelCount){
    int a, b, c;
    for(int i = 0; i < DelCount; i++){
        if(Delegates[i].getArrYear() <= Delegates[i+1].getArrYear() && MaleCheck(Delegates, DelCount)){
            c = Delegates[i].getArrYear();
        }
    }
    for(int i = 0; i < DelCount; i++){
        if(Delegates[i].getArrYear() == c){
            if(Delegates[i].getArrMonth() <= Delegates[i+1].getArrMonth() && MaleCheck(Delegates, DelCount)){
                b = Delegates[i].getArrMonth();
            }
        }
    }
    for(int i = 0; i < DelCount; i++){
        if(Delegates[i].getArrMonth() == b){
            if(Delegates[i].getArrDay() < Delegates[i+1].getArrDay() && MaleCheck(Delegates, DelCount)){
                a = Delegates[i].getArrDay();
            }
        }
    }
    for(int i = 0; i < DelCount; i++){
        if(Delegates[i].getArrDay() == a && Delegates[i].getArrMonth() == b && Delegates[i].getArrYear() == c){
            cout << "\nDelegate N " << i+1 << " :\n";
            cout << "Name: " << Delegates[i].getName() << endl;
            cout << "Hotel Name: " << Delegates[i].getHotelName() << endl;
            cout << "Room number: " << Delegates[i].getRoomNumber() << endl;
            cout << "Price per night: " << Delegates[i].getNightPrice() << endl;
        }
    }a = 0; b = 0; c = 0;
}

int main(){
    char Input = true;
    DelegateCard Delegates[100];
    Delegate Person[100];
    int DelCount = 0, PerCount = 0;
    string newCity, newHotelName;



    do{
        cout << "\n<------MENU------->\n";
        cout << "1. Add new Delegate.\n";
        cout << "2. Display data.\n";
        cout << "3. Finds the amount to be paid.\n";
        cout << "4. \n";
        cout << "5. \n";
        cout << "6. \n";
        cout << "0. Exit!!!\n";
        cout << "Input: "; cin >> Input;
        switch (Input){
        case '0': Input = false; break;
        case '1': Delegates[DelCount++].getData(); break;
        case '2': for(int i = 0; i < DelCount; i++){
            cout << "\nDelegate N " << i + 1 << " :\n";
            Delegates[i].display();
        } break;
        case '3': cin.ignore();
            cout << "Insert City: "; getline(cin, newCity);
            cout << "Insert hotel name: "; getline(cin, newHotelName);
            DelegateSumPaid(Delegates, DelCount, newCity, newHotelName); break;
        case '4': EarlyArrivedDelegate(Delegates, DelCount); break;
        case '5': cin.ignore();
            cout << "Insert city: "; getline(cin, newCity);
            for(int i = 0; i < DelCount; i++){
                if(Delegates[i].getCity() == newCity){
                    Person[PerCount++] = Delegates[i];
                }
            }break;
        case '6': 
            for(int i = 0; i < PerCount; i++){
                cout << "\nDelegate N " << i + 1 << " :\n";
                Person[i].display();
            }break;
        default: cout << "\nWrong input!!!\n"; break;
        }
    } while (Input != false);
    return 0;
}