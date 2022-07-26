/*
���: �� �� ������� ��� ������� � ���� � ���� ���:
-	���� �� ���������� �� �������� ��� ������;
-	���� �� ����������� ���������� �� �������� ����� ������.

��� �� ������:
-	���������� �� ��� ��������� - Triangle � RectTriangle ��������� �� ���������� 
(3 ������) � ����������� ���������� (2 ������);
-	��������� �� ��� ������ - �� Triangle � ����� �� RectTriangle;
-	������� �� ��������, ����� ���� ������� �� ������� ���������� ����������� 
(��� �������� ��� ������)  � ������� ����������� ����������� (��� �������� ��� ������);
-	������� �� ��� ������� � ���� � ���� ���, ����� ���������, ���������, ������ �� ���������� 
(� ��� ��� � �� ���������� �������) � �� ����������� ����������;
-	������ �� ��� ��� ������� main ��� ������������ 
�������, ���� �� ���������� �� �������� ������ �� ����������� � ���-������ ����.
*/
#include <iostream>
#include <math.h>

using namespace std;

struct Triangle {
	int a, b, c;
};
struct RectTriangle {
	int a, b;
};

float GetArea(Triangle t) {
	float p = (t.a + t.b + t.c) / 2;
	return sqrt(p * (p - t.a) * (p - t.b) * (p - t.c));
}
float GetArea(RectTriangle r) {
	return (r.a * r.b) / 2;
}
int main() {
	Triangle tr[10];
	RectTriangle rectTr[10];
	int n; //���� �� �����������
	int m; //���� �� ����������� �����������
	cout << "Insert count of triangles: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Triangle number " << i + 1 << ": " << endl;
		cout << "Side a: "; cin >> tr[i].a;
		cout << "Side b: "; cin >> tr[i].b;
		cout << "Side c: "; cin >> tr[i].c;
	}

	cout << "Insert count of rectTriangles: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "rectTriangle number " << i + 1 << ": " << endl;
		cout << "Side a: "; cin >> rectTr[i].a;
		cout << "Side b: "; cin >> rectTr[i].b;
	}

	for (int i = 0; i < n; i++) {

	}
}