#include <string>
#include <iostream>

using namespace std;

class House{
private:
    string adress;
    float price;
    int rooms;
public:
    House(){

    }
    void getData(){
        cin.ignore();
        cout << "\nInsert adress: "; getline(cin, adress);
        cout << "Insert price: "; cin >> price;
        cout << "Insert rooms: "; cin >> rooms;
    }
    void display(){
        cout << "\nAdress: " << adress << ".\n";
        cout << "Price: " << price << ".\n";
        cout << "Rooms: " << rooms << ".\n";
    }
    string getAdress(){
        return adress;
    }
    float getPrice(){
        return price;
    }
    int getRooms(){
        return rooms;
    }
};

void HousesWithAbove10(House H[], int brH){
    for(int i = 0; i < brH; i++){
        if(H[i].getRooms() > 10){
            H[i].display();
        }
    }
}

int main() {
	char Input = true;
    House H[100];
    int brH = 0;

    
	do {
		cout << "\n------MENU------\n";
		cout << "1. Insert data for house.\n";
		cout << "2. Display all data.\n";
		cout << "3. Display all houses with more than 10 rooms.\n";
		cout << "0. Exit.\n";
		cout << "Insert number: "; cin >> Input;
		switch (Input) {
		case '0':Input = false; break;
		case '1': H[brH++].getData(); break;
		case '2': 
            for(int i = 0; i < brH; i++){
                H[i].display();
            } break;
		case '3': HousesWithAbove10(H, brH); break;
		default: cout << "You insert wrong number.\n";
		}
	} while (Input != false);
    return 0;

}