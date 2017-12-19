#include "stdafx.h"
#include <iostream>
#include <sstream>

using namespace std;


bool read_size(unsigned int &size) {
	string stroka_size;
	getline(cin, stroka_size);
	istringstream stream(stroka_size);
	if (!(stream >> size)) {
		return false;
	}

	return true;
}

bool input_mas(unsigned int * &mas, unsigned int size) {
	char lishniy_symbol; 
	string chisla;
	getline(cin, chisla);
	istringstream stream(chisla);
	for (unsigned int i = 0; i < size; i++) {
		if (!(stream >> mas[i])) {
			return false;
		}
	}
	if (stream >> lishniy_symbol) {
		return false;
	}
	return true;
}

void counting_sort(unsigned int *mas, unsigned int * &result_mas, unsigned int size) {
	unsigned int index;
	for (unsigned int i = 0; i < size; i++) {
		index = 0;
		for (unsigned int j = 1; j < size; j++) {
			if (mas[i] > mas[j]) {
				index++; 
			}
		}
		result_mas[index] = mas[i];
	}
}

int main()
{
	unsigned int size;
	unsigned int *mas;
	unsigned int *result_mas;
	if (read_size(size)) {
		mas = new unsigned int[size];
		for (unsigned int i = 0; i < size; i++) {
			mas[i] = 0;
		}
		if (input_mas(mas, size)) {
			result_mas = new unsigned int[size];
			counting_sort(mas, result_mas, size);
			for (unsigned int i = 0; i < size; i++) {
				cout << result_mas[i] << ' ';
			}
		}
		else cout << "An error has occured while reading input data." << endl;
		return -1;
	}
	else {
		cout << "An error has occured while reading input data." << endl;
		return -1;
	}
	cout << endl;
    return 0;
}
