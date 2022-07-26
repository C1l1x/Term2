
#include<string>
#include <iostream>

using namespace std;

class CBook
{
private:
	string iNumber;
	string title;
	string author;
	int pages;
	float price;
public:
	string GetiNumber();
	string GetTitle();
	string GetAuthor();
	int GetPages();
	float GetPrice();
	void DisplayData();
	void setData();
};

void CBook::setData() {
	cout << "Insert book number: "; cin >> iNumber; cin.ignore();
	cout << "Insert title: "; getline(cin, title);
	cout << "Insert author: "; getline(cin, author);
	cout << "Insert number of Pages: "; cin >> pages;
	cout << "Price: "; cin >> price;

}
void CBook::DisplayData() {
	cout << "Book number: " << GetiNumber() << ".\n";
	cout << "Title: " << GetTitle() << ".\n";
	cout << "Author: " << GetAuthor() << ".\n";
	cout << "Number of Pages: " << GetPages() << ".\n";
	cout << "Price: " << GetPrice() << ".\n";
	cout << "------------------------------------------------------\n";
}


string CBook::GetiNumber() {
	return iNumber;
}
string CBook::GetTitle() {
	return title;
}
string CBook::GetAuthor() {
	return author;
}
int CBook::GetPages() {
	return pages;
}
float CBook::GetPrice() {
	return price;
}

float SumPrices(CBook Books[], int n) {
	float sum = 0;

	for (int i = 0; i < n; i++)
		sum += Books[i].GetPrice();
	return sum;
}

void BooksAuthor(CBook Books[], int n, string insAuthor) {
	for (int i = 0; i < n; i++) {

		if (Books[i].GetAuthor() == insAuthor)
			Books[i].DisplayData();
	}
}

void DeleteBook(CBook Books[], int & n, string insNum) {
	int i, j = 0;
	for (i = 0; i < n; i++)
		if (Books[i].GetiNumber() == insNum)
			for (int j = i; j < n - 1; j++)
				Books[j] = Books[j + 1];
	i--;
	n--;
}


class Book1 {
private:
	string title;
public:
	void displayData() {
		cout << "Title: " << GetTitle() << endl;
	}
	void SetTitle(string get_title);
	string GetTitle();
};
void Book1::SetTitle(string get_title) {
	this->title = get_title;
}


string Book1::GetTitle() {
	return this->title;
}


void NewArr(CBook Books[], int count_b, Book1 Books15[], int& cbooks15) {
	int j = 0;
	for (int i = 0; i < count_b; i++)
		if (Books[i].GetPrice() <= 15) {
			Books15[j++].SetTitle(Books[i].GetTitle());
		}
	cbooks15 = j;
}


int main() {
	char choise;
	int i, Books1 = 0,pBooks15 = 0;

	CBook Books[100]; 
	Book1 Books15[100];

	string InsAuthor;
	string InsNum;
	do {
		cout << "\nMENU OF PERFORMED OPERATIONS:\n";
		cout << " 1 - to add book data.\n";
		cout << " 2 - to display the data of all books.\n";
		cout << " 3 - to find and deduct the sum from the prices of all books.\n";
		cout << " 4 - to display the data of all books by a given author.\n";
		cout << " 5 - for creating an array with the titles of the books with a price up to 15 BGN.\n";
		cout << " 6 - to delete the data of a book with a set inventory number.\n";
		cout << " 0 - for exit.\n";
		cout << "Insert number: "; cin >> choise;
		switch (choise) {
		case '0':break;
		case '1':Books[Books1++].setData(); break;
		case '2':cout << "\nList of all books:\n";
			for (i = 0; i < Books1; i++) Books[i].DisplayData();break;
		case '3':cout << "\nThe sum of the prices of all books is "
			<< SumPrices(Books, Books1) << " BGN.\n";break;
		case '4':cin.ignore();
			cout << "Instert author: "; cin >> InsAuthor;
			cout << "\n\tBooks from " << InsAuthor << ":\n";
			BooksAuthor(Books, Books1, InsAuthor); break;
		case '5':NewArr(Books, Books1, Books15, pBooks15);
			for (i = 0; i < pBooks15; i++) Books15[i].displayData();
			break;
		case '6': cout << "Instert inv.number: "; cin >> InsNum;
			DeleteBook(Books, Books1, InsNum);
			cout << "\nThe book has been deleted!!!\n";
			break;

		default: cout << "You insert wrong number.\n";
		}
	} while (choise != '0');

}