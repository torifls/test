#include <iostream>
#include <string>
#include "aeroflot.h"

using namespace std;

/*
���������� ����� � ������ ��R�FL��, ���������� ��������� ����:
-�������� ������ ���������� �����;
-����� �����;
-��� ��������.
���������� ������ ������� � ���� ����� � ������������� �������� ���������� � ������� ��� �������� ���� ��R�FL��.
�������� ���������, ����������� ��������� ��������:
-���� � ���������� ������ � ������, ��������� �� ���� �������� ���� ��R�FL��; ������ ������ ���� ��������� � ���������� ������� �� ��������� ������� ����������;
-����� �� ����� ������� ���������� � ������� ������, ������������� ���������, ��� �������� ������ � ����������;
-���� ����� ������ ���, ������ �� ������� ��������������� ���������.
*/

// ���������� �� ��������
void SortByAlphabet(AEROFLOT *aeroflot, int n) {
	bool isSorted = false;

	while (!isSorted) {
		isSorted = true;

		for (int i = 0; i < n - 1; i++) {
			if (aeroflot[i].getDestination() > aeroflot[i + 1].getDestination()) {
				AEROFLOT tmp = aeroflot[i];
				aeroflot[i] = aeroflot[i + 1];
				aeroflot[i + 1] = tmp;
				isSorted = false;
			}
		}
	}
}

// ����� �� ����� ������� ���������� � ������� ������, ������������� ���������, ��� �������� ������ � ����������
void PrintByType(AEROFLOT *aeroflot, int n) {
	string type;
	cout << endl << "Enter type: ";
	cin >> type;

	int finded = 0;

	for (int i = 0; i < n; i++) {
		if (aeroflot[i].getType() == type) {
			cout << "#" << aeroflot[i].getRoute() << ". destination: " << aeroflot[i].getDestination() << endl;
			finded++;
		}
	}

	if (finded == 0)
		cout << "No routes with type '" << type << "'" << endl;
}

int main() {
	const int N = 7;

	AEROFLOT *aeroflot = new AEROFLOT[N]; // ������ ������ �� N ���������
	cout << "Enter information about objects:" << endl;

	// �������� ���������� �� N ��������
	for (int i = 0; i < N; i++)
		aeroflot[i].Read();

	cout << endl << "Entered information: " << endl;

	// ������� �������� ������
	for (int i = 0; i < N; i++)
		aeroflot[i].Print();

	SortByAlphabet(aeroflot, N); // ��������� �� ��������

	cout << endl << "Sorted information: " << endl;

	// ������� ��������������� ������
	for (int i = 0; i < N; i++)
		aeroflot[i].Print();

	PrintByType(aeroflot, N); // ������� ������ � ������ �� ����

	delete[] aeroflot;

	return 0;
}