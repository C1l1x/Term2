/*
Да се състави програма, която съхранява в масив следната информация за лекарствата в една аптека:
    - наименование символен низ;
    - цена - реално число;
    - налично количество - цяло число;
    - дата, до която е годно за употреба;

    и извършва следните операции, избрани от меню:
    - добавя към масива данните на ново лекарство;
    - извежда всички въведени данни;
    - извежда имената на лекарствата с цена над 5 лв.;
    - създава нов масив с данните на лекарствата с налични количества под 10 броя;
    - създава нов масив с имената на лекарствата с изтичащ срок на годност на зададена дата.

Забележка:
Създайте клас за опериране с дата, който да използвате като член данни за срок на годност.
*/

#include <string>
#include <iostream>

using namespace std;

class OutDate{
private:
    int D, M, Y;
public:
    void getData(){
        cout << "Day -> "; cin >> D;
        cout << "Month -> "; cin >> M;
        cout << "Year -> "; cin >> Y;
    }
    void display(){
        cout << "Day -> " << D << endl;
        cout << "Month -> " << M << endl;
        cout << "Year -> " << Y << endl;
    }
    int getDay(){
        return D;
    }
    int getMonth(){
        return M;
    }
    int getYear(){
        return Y;
    }

};
class Medicine: public OutDate{
private:
    string Name;
    float Price;
    int Amount;
public:
    void getData(){
        cin.ignore();
        cout << "\nInsert data for medicament\n";
        cout << "Name -> "; getline(cin,Name);
        cout << "Price -> "; cin >> Price;
        cout << "Amount -> "; cin >> Amount;
        OutDate::getData();
    }
    void display(){
        cout << "Name -> " << Name << "\n";
        cout << "Price -> " << Price << " bgn\n";
        cout << "Amount -> " << Amount << "\n";
        OutDate::display();
    }
    string getName(){
        return Name;
    }
    float getPrice(){
        return Price;
    }
    int getAmount(){
        return Amount;
    }
};

void getNameUnder5(Medicine Drug[], int br){
    for(int i = 0; i < br; i++){
        if(Drug[i].getPrice() >= 5){
            cout << "\nMedicament " << i + 1 << " ->\n";
            Drug[i].display();
        }
    }
}

void ArrayWithAmountUnder10(Medicine Drug[], Medicine DrugAmountAbove10[], int br, int& brA){
    for(int i = 0; i < br; i++){
        if(Drug[i].getAmount() < 10){
            DrugAmountAbove10[brA++] = Drug[i];
        }
    }
    cout << "\n--> Done <--\n";
}

void ArrayWithMedicamentsWithOutDate(Medicine Drug[], Medicine DrugOutDate[], int br, int& brD){
    int newD, newM, newY;
    string newName;
    cout << "Insert date to check medicament outdate: \n";
    cout << "Day -> "; cin >> newD;
    cout << "Month -> "; cin >> newM;
    cout << "Year -> "; cin >> newY;
    for(int i = 0; i < br; i++){
        if(Drug[i].getDay() > newD || Drug[i].getMonth() > newM || Drug[i].getYear() > newY){
            DrugOutDate[brD++] = Drug[i].getName();
        }
    }
}

int main(){
    Medicine Drug[100];
    Medicine DrugAmountAbove10[100];
    Medicine DrugOutDate[100];
	char Input = true;
    int br = 0, brA = 0, brD = 0;

    
	do{
		cout << "\n--->Menu<---\n";
		cout << "-> 1. Insert data.\n";
		cout << "-> 2. Display all data.\n";
		cout << "-> 3. Display data for medicaments with 10 amounts and above.\n";
        cout << "-> 4. Creat array with medicaments under 10 amounts.\n";
        cout << "-> 5. Check array.\n";
        cout << "-> 6. Create array with outdated medicaments.\n";
        cout << "-> 7. Check array.\n";
		cout << "-> 0. Exit.\n";
		cout << "Input -> "; cin >> Input;
		switch (Input){
		case '0': Input = false; break;
		case '1': Drug[br++].getData(); break;
		case '2': 
            for(int i = 0; i < br; i++){
                cout << "\nMedicament " << i + 1 << " ->\n";
                Drug[i].display();
            } break;
		case '3': getNameUnder5(Drug, br); break;
		case '4': ArrayWithAmountUnder10(Drug, DrugAmountAbove10, br, brA); break;
        case '5': 
            for(int i = 0; i < brA; i++){
                cout << "\nMedicament " << i + 1 << " ->\n";
                DrugAmountAbove10[i].display();
            } break;
        case '6': ArrayWithMedicamentsWithOutDate(Drug, DrugOutDate, br, brD); break;
        case '7':
            for(int i = 0; i < brD; i++){
                cout << "\nOutdated medicament " << i + 1 << " ->\n";
                DrugOutDate[i].display();
            } break;
		default: cout << "\n--> Try Again <--\n";
		}
	} while (Input != false);
    return 0;
}