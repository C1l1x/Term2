/*
Да се дефинира базов клас фигура - всяка фигура се характеризира с цвят (string).
Да се дефоморат класовете - наследници на класа фигура, които описват:
    - триъгълник;
    - правоъгълник;
Да се състави клас, който съхранява в масив данните за няколко (максимум 30) фигури и извършва следните действия:
    - добавя нова фигура: триъгълник или правоъгълник;
    - извежда данните за всички фигури (вид, цвят и размери);
    - извежда сумата от периметрите на всички правоъгълници;
    - извежда списък с цветовете на всички правоъгълници;
Да се състави подходяща тестваща програма.
*/

#include<iostream>
#include<string>

using namespace std;

class Figure{
private:
    string Color;
public:
    Figure(){}
    virtual void getData(){
        cin.ignore();
        cout << "\nInsert color: "; getline(cin, Color); 
    }
    virtual void display(){
        cout << "Color: " << Color << endl;
    }
    virtual int getPer(){
        return 0;
    }
    virtual string getColor(){
        return Color;
    }
    virtual int getAngle(){
        return 0;
    }
    virtual void displayRectColor(Figure* Fig[],int FigNum){
        for(int i = 0; i < FigNum; i++){
            if(Fig[i]->getAngle() == 2){
                cout << Fig[i]->Color << endl;
            }
        }
    }
};

class Triangle: public Figure{
private:
    int a, b, c, angle = 1;
public:
    Triangle(){

    }
    void getData(){
        Figure::getData();
        cout << "Insert a: "; cin >> a;
        cout << "Insert b: "; cin >> b;
        cout << "Insert c: "; cin >> c;
    }
    void display(){
        Figure::display();
        cout << "A: " << a << endl;
        cout << "B: " << b << endl;
        cout << "C: " << c << endl;
    }
    int getPer(){
        return a+b+c;
    }
    int getAngle(){
        return angle;
    }
};

class Rectangle: public Figure{
private:
    int a, b, angle = 2;
public:
    Rectangle(){
        
    }
    void getData(){
        Figure::getData();
        cout << "Insert a: "; cin >> a;
        cout << "Insert b: "; cin >> b;
    }
    void display(){
        Figure::display();
        cout << "A: " << a << endl;
        cout << "B: " << b << endl;
    }
    int getPer(){
        return 2*a+2*b;
    }
    string getColor(){
        return Figure::getColor();
    }
    int getAngle(){
        return angle;
    }
};

void displayRectColor(Figure *Fig[],int FigNum){
    string SetColor;
    for(int i = 0; i < FigNum; i++){
        if(Fig[i]->getAngle() == 2){
            SetColor = Fig[i]->getColor();
            cout << "\nFigure N " << i + 1 << " :\n";
            cout << "Color: " << SetColor << endl;
        }
    }
}


int main(){
    char Input = true;
    Figure *Fig[30];
    int FigNum = 0, sum = 0;

    do{
        cout << "\n---------MENU--------\n";
		cout << "1. Add data for new triangle.\n";
        cout << "2. Add data for new rectangle.\n";
		cout << "3. Display all data.\n";
		cout << "4. Display sum.\n";
        cout << "5. Display all color of rectangles.\n";
		cout << "0. Exit.\n";
		cout << "Insert number: "; cin >> Input;

		switch (Input) {
		case '0': 
        Input = false; ; break;
		case '1':
            Fig[FigNum] = new Triangle;
            Fig[FigNum++]->getData(); break;
		case '2':
            Fig[FigNum] = new Rectangle;
            Fig[FigNum++]->getData(); break;
		case '3':
            for (int i = 0; i < FigNum; i++){
                cout << "\nFigure N " << i + 1 << " :\n";
                Fig[i]->display();
            } break;
        case '4':
            for(int i = 0; i < FigNum; i++){
                sum+=Fig[i]->getPer();
            }
            cout << "Sum: " << sum << endl;
            sum = 0; break;
        case '5':
            displayRectColor(Fig, FigNum); break;
		default: cout << "\nWrong number!\n";
        }
    }while(Input != false);

    return 0;

}