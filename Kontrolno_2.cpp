#include<string>
#include <iostream>

using namespace std;

class Furniture{
private:
	string name;
	float price;
public:
	Furniture(){

	}
	virtual void getData(){
        cin.ignore();
        cout << "\nInsert name: "; getline(cin, name);
        cout << "Insert price: "; cin >> price;
    }
    virtual void display(){
        cout << "\nName: " << name << "\n";
        cout << "Price: " << price << "\n";
    }
    virtual string getColor(){
        return 0;
    }
    virtual int getSlots(){
        return 0;
    }
    virtual int getFur(){
        return 0;
    }
    virtual string getName(){
        return name;
    }
};

class Chair: public Furniture{
private:
    string color;
    int Fur = 1;
public:
    Chair(){
        
    }
    void getData(){
        Furniture::getData();
        cin.ignore();
        cout << "Insert color: "; getline(cin, color);
    }
    void display(){
        Furniture::display();
        cout << "Color: " << color << "\n";
    }
    string getColor(){
        return color;
    }
    int getFur(){
        return Fur;
    }
};

class Table: public Furniture{
private:
    int slots, Fur = 2;
public:
    Table(){
        
    }
    void getData(){
        Furniture::getData();
        cout << "Insert slots: "; cin >> slots;
    }
    void display(){
        Furniture::display();
        cout << "Slots: " << slots << "\n";
    }
    int getSlots(){
        return slots;
    }
    int getFur(){
        return Fur;
    }
};

void WhiteChairs(Furniture *shop[], int br){
    for(int i = 0; i < br; i++){
        if(shop[i]->getFur() == 1){
            if(shop[i]->getColor() == "White"){
                shop[i]->display();
            }
        }
    }
}

void NewArrayForTabels(Furniture *shop[], Furniture *tables[], int br, int& brT){
    for(int i = 0; i < br; i++){
        if(shop[i]->getFur() == 2){
            if(shop[i]->getSlots() > 4){
                tables[brT++] = shop[i];
                cout << "\nDone!\n";
            }
        }
    }
}

void DeleteArrWithName(Furniture *shop[], int& br, string newName){
    int i, j;
	for (i = 0; i < br; i++){
		if (shop[i]->getName() == newName){
			for (j = i; j < br - 1; j++){
				shop[j] = shop[j + 1];
            }
        }
    }
    i--;
    br--;
}


int main() {
	char Input = true;
    Furniture *shop[100];
    Furniture *tables[100];
    int br = 0, brT = 0;
    string newName;

    
	do {
		cout << "\n------MENU------\n";
		cout << "1. Insert data for chair.\n";
		cout << "2. Insert data for table.\n";
		cout << "3. Display all data.\n";
		cout << "4. Delete array with insertet name.\n";
        cout << "5. Display all white chairs.\n";
        cout << "6. Create new array for tabels with 4 slots.\n";
        cout << "7. Check new array.\n";
		cout << "0. Exit.\n";
		cout << "Insert number: "; cin >> Input;
		switch (Input) {
		case '0':Input = false; break;
		case '1': 
            shop[br] = new Chair;
            shop[br++]->getData(); break;
		case '2': 
            shop[br] = new Table;
            shop[br++]->getData(); break;
		case '3':
            for(int i = 0; i < br; i++){
                shop[i]->display();
            } break;
        case '4': cin.ignore();
            cout << "Insert name: "; getline(cin, newName);
            DeleteArrWithName(shop, br, newName); break;
        case '5': WhiteChairs(shop, br); break;
        case '6': NewArrayForTabels(shop, tables, br, brT); break;
        case '7':
            for(int i = 0; i < brT; i++){
                tables[i]->display();
            } break;
		default: cout << "You insert wrong number.\n";
		}
	} while (Input != false);

}