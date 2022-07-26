/*
В градински център се продават растения (наименование, цена, брой),
които биват дървета (височина, вид(иглолистни/широколистни)) и цветя
(цвят). Данните за всяко растение се съхранява в масив.
Да се състави програма, която изпълнява от меню следните операции:
- добавя към масива данните на ново растение;
- извежда всички въведени данни;
- извежда данните на дърветата с височина над 2метра;
- създава масив с данните на всички цветя.
*/ 

#include <iostream>
#include <string>

using namespace std;

class GardenCentre{
private:
    string Name;
    float Price;
    int Count;
public:
    GardenCentre(){

    }
    virtual void getData(){
        cin.ignore();
        cout << "\nInsert name: "; getline(cin, Name);
        cout << "Insert price: "; cin >> Price;
        cout << "Insert count: "; cin >> Count;
    }
    virtual void display(){
        cout << "Name: " << Name << ".\n";
        cout << "Price: " << Price << ".\n";
        cout << "Count: " << Count << ".\n";
    }
    virtual string getName(){
        return Name;
    }
    virtual float getPrice(){
        return Price;
    } 
    virtual int getCount(){
        return Count;
    }
    virtual int getPlant(){
        return 0;
    }
    virtual float getHeight(){
        return 0;
    }
};

class Trees: public GardenCentre{
private:
    float Height;
    int Type, Pl = 1;
public:
    Trees(){

    }
    void getData(){
        GardenCentre::getData();
        cout << "Insert height (m): "; cin >> Height;
        cout << "----------Tree Type----------\n";
        cout << "1 - coniferous // 2 - deciduous\n";
        while(true){
            cout << "Insert 1 or 2: "; cin >> Type;
            if(Type == 1 || Type == 2){
                break;
            }else
                cout << "\nWrong input!!!\n";
        }
    }
    void display(){
        GardenCentre::display();
        cout << "Height: " << Height << " cm.\n";
        if(Type == 1){
            cout << "Type: Coniferous.\n";
        }else
            cout << "Type: Deciduous.\n";
    }
    float getHeight(){
        return Height;
    }
    int getType(){
        return Type;
    }
    int getPlant(){
        return Pl;
    }
};

class Flowers: public GardenCentre{
private:
    string Color;
    int Pl = 2;
public:
    Flowers(){

    }
    void getData(){
        GardenCentre::getData();
        cin.ignore();
        cout << "Insert color: "; getline(cin, Color);       
    }
    void display(){
        GardenCentre::display();
        cout << "Color: " << Color << ".\n";
    }
    string getColor(){
        return Color;
    }
    int getPlant(){
        return Pl;
    }
};

void TreesAbove2m(GardenCentre *Garden[],int br){
    for(int i = 0; i < br; i++){
        if(Garden[i]->getPlant() == 1){
            if(Garden[i]->getHeight() >= 2){
                cout << "\nTree N " << i + 1 << " :\n";
                Garden[i]->display();
            }
        }       
    }
}

int main(){
    char Input = true;
    GardenCentre *Garden[100];
    GardenCentre *allFlowers[100];
    int br = 0, Flower = 0;
    string newName;

    do{
        cout << "\n---------MENU--------\n";
		cout << "1. Add data for new tree.\n";
        cout << "2. Add data for new flower.\n";
		cout << "3. Display all data.\n";
		cout << "4. Display all trees above 2m.\n";
        cout << "5. Create new arr with all flowers.\n";
        cout << "6. Check new arr.\n";
		cout << "0. Exit.\n";
		cout << "Insert number: "; cin >> Input;

		switch (Input) {
		case '0': 
        Input = false; ; break;
		case '1':
            Garden[br] = new Trees;
            Garden[br++]->getData(); break;
		case '2':
            Garden[br] = new Flowers;
            Garden[br++]->getData(); break;
		case '3':
            for (int i = 0; i < br; i++){
                cout << "\nPlant N " << i + 1 << " :\n";
                Garden[i]->display();
            } break;
        case '4': TreesAbove2m(Garden, br); break;
        case '5': 
            for(int i = 0; i < br; i++){
                if(Garden[i]->getPlant() == 2){
                    allFlowers[Flower++] = Garden[i];
                }
            }
            cout << "\nDone :)\n"; break;
        case '6': for(int i = 0; i < Flower; i++){
            cout << "\nFlower N " << i + 1 << " :\n";
            allFlowers[i]->display();
        } break;
		default: cout << "\nWrong number!\n";
        }
    }while(Input != false);

    return 0;
}