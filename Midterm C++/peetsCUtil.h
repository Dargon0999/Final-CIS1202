#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <random>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;

#pragma region IOFunc

// integer
int getInt(string x) {
	int num;

	cin.ignore();

	cout << x << endl;

	while (!(cin >> num) || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cin.sync();

		cout << "\nError: Invalid input" << endl;

		cout << "\n" << x << endl;
	}
	return num;
}

int  getInt(string x, int min, int max) {
	int num;

	cout << x << endl;

	while (!(cin >> num) || cin.fail() || (num < min || num > max)) {
		cin.clear();
		cin.ignore(100, '\n');
		cin.sync();

		cout << "\nError: Invalid input" << endl;

		cout << "\n" << x << endl;
	}
	return num;
}

int getInt(vector<string> prompt, string prompt2, int i) {
	int num;

	cin.ignore();

	cout << prompt[i] << " " << prompt2 << endl;

	while (!(cin >> num) || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cin.sync();

		cout << "\nError: Invalid input" << endl;

		cout << prompt[i] << " " << prompt2 << endl;
	}
	return num;
}




//float
float getFloat(string x) {
	float num;

	cout << x << endl;

	while (!(cin >> num) || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cin.sync();

		cout << "\nError: Invalid input" << endl;

		cout << "\n" << x << endl;
	}
	return num;
}


float getFloat(string x, float min, float max) {
	float num;

	cout << x << endl;

	while (!(cin >> num) || cin.fail() || (num < min || num > max)) {
		cin.clear();
		cin.ignore(100, '\n');
		cin.sync();

		cout << "\nError: Invalid input" << endl;

		cout << "\n" << x << endl;
	}
	return num;
}


//double
double getDouble(string x) {
	double num;

	cout << x << endl;

	while (!(cin >> num) || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cin.sync();

		cout << "\nError: Invalid input" << endl;

		cout << "\n" << x << endl;
	}
	return num;
}

double getDouble(string x, double min, double max) {
	double num;

	cout << x << endl;

	while (!(cin >> num) || cin.fail() || (num < min || num > max)) {
		cin.clear();
		cin.ignore(100, '\n');
		cin.sync();

		cout << "\nError: Invalid input" << endl;

		cout << "\n" << x << endl;
	}
	return num;
}


//response answer

char getRes(string x, char res1, char res2) {
	char res;

	cout << x << endl;
	cin >> res;
	res = tolower(res);
	while (!(res == res1 || res == res2)) {
		cout << "\nInvalid response" << endl;

		cout << "\n" << x << endl;
		cin >> res;
		res = tolower(res);
	}
	return res;
}

int getRes(string res1, string res2) {
	int res;

	cout << "1.) " << res1 << endl;
	cout << "2.) " << res2 << endl;
	cout << "\nChoice: ";
	while (!(cin >> res) || cin.fail() || (res < 1 || res > 2)) {

		cout << "\nInvalid response" << endl;

		cout << "\n1.) " << res1 << endl;
		cout << "2.) " << res2 << endl;
		cout << "\nChoice: ";
	}
	return res;
}



#pragma endregion 


#pragma region FileFunc


//Random number

int getRand(int min, int max) {
	random_device randDev;
	mt19937 gen(randDev());
	uniform_int_distribution<int> random(min, max);
	int randNum = random(gen);
	return randNum;
}


//open file

//write

int writeFile(string fileName) {
	fout.open(fileName);

	if (!fout) {
		cout << "File did not open";
		return -1;
	}

	return 0;
}

//append

int appFile(string fileName) {
	fout.open(fileName, ios::app);

	if (!fout) {
		cout << "File did not open";
		return -1;
	}

	return 0;
}

//read

int readFile(string fileName) {
	fin.open(fileName);

	if (!fin) {
		return -1;
	}

	return 0;
}

//action dots
void sleepDots(int duration, int count) {

	duration *= 1000;

	for (int i = 0; count > i; i++) {
		cout << ".";
		Sleep(duration);
	}
	cout << endl;
}

#pragma endregion


#pragma region Vectors_are_better_than_arrays


#pragma region Enter array data

#pragma region array

//enter values
void enterArray(int*& array, int& size) {
	int num;
	char res;
	int i;
	
	do{
		
		
		int* temp = new int[size + 1];
		
	
		for (i = 0; i < size - 1; i++) {
			temp[i] = array[i];
		}
		

		num = getInt("Enter a number: ");

		temp[size] = num;

		delete[] array;

		array = temp;

		size++;
		
		res = getRes("Would you like to enter another number (y/n): ", 'y', 'n');
		cout << endl;
	} while (res == 'y');
}

void enterArray(int*& array, int min, int max, int& size) {
	int num;
	int input;
	char res;
	int i;

	

	input = getInt("How many pieces of data do you want to add: ", 1, 100);



	int* temp = new int[size + input];

	if (array != nullptr) {
		for (i = 0; i < size; i++) {
			*(temp + i) = *(array + i);
		}
	}

	array = temp;

	for (i = size; i < size + input; i++) {

		num = getInt("Enter a number: ", min, max);

		*(temp + i) = num;
	}

	size += input;
		
}

void deleteValue(int*& array, int& size) {

	int choice;
	int i;

	for (i = 0; i < size; i++) {
		cout << i + 1 << ". " << *(array + i) << endl;
	}
	choice = getInt("Choice: ", 1, size) - 1;

	size--;

	for (i = choice; i < size; i++) {
		*(array + i) = *(array + i + 1);
	}

	int* temp = new int[size];

	for (i = 0; i < size; i++) {
		*(temp + i) = *(array + i);
	}

	array = temp;

	cout << "Deleting";
	sleepDots(1, 3);
}


void enterArray(string array[], int& size) {

	string input;
	for (int i = 0; i < size; i++) {
		cout << "Enter word: ";
		cin >> input;
		cin.ignore(100, '\n');
		array[i] = input;
	}

}
#pragma endregion 

#pragma region vector


void enterArray(vector<int>& array) {
	int num;
	char res;
	do {
		num = getInt("Enter a number: ");
		array.push_back(num);
		res = getRes("Would you like to put in another number (y/n)", 'y', 'n');
	} while (res == 'y');
}

void enterArray(vector<int>& array, int min, int max) {
	int num;
	char res;
	do {
		num = getInt("Enter a number: ", min, max);
		array.push_back(num);
		res = getRes("Would you like to put in another number (y/n)", 'y', 'n');
	} while (res == 'y');

}


void enterArray(vector<string>& array) {

	string input;
	char res;
	do {
		cout << "Enter word: ";
		cin >> input;
		cin.ignore(100, '\n');
		array.push_back(input);
		res = getRes("\nWould you like to put in another number (y/n)", 'y', 'n');
	} while (res == 'y');

}

#pragma endregion 

#pragma endregion 

#pragma region Display array


#pragma region array

void displayArray(int* array, int& size) {

	for (int i = 0; i < size - 1; i++) {
		cout << *(array + i) << ", ";
	}
	cout << *(array + size - 1);
}

void displayArray(string prompt, int array[], int& size) {

	for (int i = 0; i < size - 1; i++) {
		cout << prompt << i + 1 << ": " << array[i] << ", ";
	}
	cout << array[size];
}

#pragma endregion

#pragma region vector


void displayArray(vector<int>& array) {

	for (int i = 0; i < array.size() - 1; i++) {
		cout << array[i] << ", ";
	}
	cout << array[array.size()];
}

void displayArray(string prompt, vector<int>& array) {

	for (int i = 0; i < array.size() - 1; i++) {
		cout << prompt << i + 1 << ": " << array[i] << ", ";
	}
	cout << array[array.size()];
}


#pragma endregion


#pragma endregion 

#pragma region find value (pos/val)

#pragma region  value


#pragma region array


void findMin(int array[], int& num, int& size) {

	for (int i = 0; i < size; i++) {
		if (num > array[i]) {
			num = array[i];
		}
	}
}

void findMax(int array[], int& num, int& size) {

	for (int i = 0; i < size; i++) {
		if (num < array[i]) {
			num = array[i];
		}
	}
}


int findValues(int array[], int& size) {
	int num = array[0];
	int type;

	type = getRes("Find Min", "Find Max");

	if (type == 1) {
		findMin(array, num, size);

	}
	else {
		findMax(array, num, size);

	}

	return num;
}

int findValues(string type, int array[], int& size) {
	int num = array[0];

	if (type == "min") {
		findMin(array, num, size);

	}
	else if (type == "max") {
		findMax(array, num, size);

	}


	return num;
}


#pragma endregion

#pragma region vector


void findMin(vector<int> array, int& num) {

	for (int i = 0; i < array.size(); i++) {
		if (num > array[i]) {
			num = array[i];
		}
	}
}

void findMax(vector<int> array, int& num) {

	for (int i = 0; i < array.size(); i++) {
		if (num < array[i]) {
			num = array[i];
		}
	}
}


int findValues(vector<int>& array) {
	int num = array[0];
	int type;

	type = getRes("Find Min", "Find Max");

	if (type == 1) {
		findMin(array, num);

	}
	else {
		findMax(array, num);

	}

	return num;
}

int findValues(string type, vector<int>& array) {
	int num = array[0];

	if (type == "min") {
		findMin(array, num);

	}
	else if (type == "max") {
		findMax(array, num);

	}


	return num;
}


#pragma endregion


#pragma endregion 

#pragma region position

#pragma region vector


int minPosition(vector<int> array) {
	int i;
	int place = 0;

	for (i = 0; i < array.size(); i++) {
		if (array[place] > array[i]) {
			place = i;
		}
	}
	return place;
}

int maxPosition(vector<int> array) {
	int i;
	int place = 0;

	for (i = 0; i < array.size(); i++) {
		if (array[place] < array[i]) {
			place = i;
		}
	}
	return place;
}


int findPosition(vector<int>& array) {
	int type;
	int i;

	type = getRes("Find Min", "Find Max");

	if (type == 1) {
		i = minPosition(array);

	}
	else {
		i = maxPosition(array);

	}

	return i;
}

int findPosition(string type, vector<int>& array) {
	int num = array[0];
	int i;

	if (type == "min") {
		i = minPosition(array);

	}
	else if (type == "max") {
		i = maxPosition(array);

	}


	return i;
}

#pragma endregion

#pragma region array

int minPosition(int array[], int& size) {
	int num = array[0];
	int i;
	int place = 0;

	for (i = 0; i < size; i++) {
		if (array[i] < num) {
			place = i;
		}
	}
	return place;
}

int maxPosition(int array[], int& size) {
	int num = array[0];
	int i;
	int place = 0;

	for (i = 0; i < size; i++) {
		if (num < array[i]) {
			place = i;
		}
	}
	return place;
}


int findPosition(int array[], int& size) {
	int num = array[0];
	int type;
	int i;

	type = getRes("Find Min", "Find Max");

	if (type == 1) {
		i = minPosition(array, size);

	}
	else {
		i = maxPosition(array, size);

	}

	return i;
}

int findPosition(string type, int array[], int &size) {
	int num = array[0];
	int i;

	if (type == "min") {
		i = minPosition(array, size);

	}
	else if (type == "max") {
		i = maxPosition(array, size);

	}


	return num;
}

#pragma endregion


#pragma endregion 


#pragma endregion 


//menus

int makeMenu(vector<string> options) {
	int i;
	for (i = 0; i < options.size(); i++) {
		cout << i + 1 << "). " << options[i] << endl;
	}
	cout << i + 1 << "). Quit" << endl;

	int choice = getInt("Choice: ", 1, options.size() + 1);

	return choice;

}

#pragma endregion


#pragma region sorting^

#pragma region swap

void swap(int& a, int& b) {
	
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap(float& a, float& b) {

	float temp;
	temp = a;
	a = b;
	b = temp;
}

void swap(double& a, double& b) {

	double temp;
	temp = a;
	a = b;
	b = temp;
}

void swap(string& a, string& b) {

	string temp;
	temp = a;
	a = b;
	b = temp;
}

void swap(char& a, char& b) {

	char temp;
	temp = a;
	a = b;
	b = temp;
}

#pragma endregion

#pragma region select

#pragma region vector

void selectSort(vector<int> arr, char order) {

	int i;
	int j;
	int position;

	if (order == 'a') {
		for (i = 0; i < arr.size() - 1; i++) {

			position = i;

			for (j = i + 1; j < arr.size(); j++) {

				if (arr[position] > arr[j]) {
					position = j;
				}
				swap(arr[i], arr[position]);
			}
		}
	}

	else {
		for (i = 0; i < arr.size() - 1; i++) {

			position = i;

			for (j = i + 1; j < arr.size(); j++) {

				if (arr[position] < arr[j]) {
					position = j;
				}
				swap(arr[i], arr[position]);
			}
		}
	}
}

void selectSort(vector<float> arr, char order) {

	int i;
	int j;
	int position;

	if (order == 'a') {
		for (i = 0; i < arr.size() - 1; i++) {

			position = i;

			for (j = i + 1; j < arr.size(); j++) {

				if (arr[position] > arr[j]) {
					position = j;
				}
				swap(arr[i], arr[position]);
			}
		}
	}

	else {
		for (i = 0; i < arr.size() - 1; i++) {

			position = i;

			for (j = i + 1; j < arr.size(); j++) {

				if (arr[position] < arr[j]) {
					position = j;
				}
				swap(arr[i], arr[position]);
			}
		}
	}
}

void selectSort(vector<double> arr, char order) {

	int i;
	int j;
	int position;

	if (order == 'a') {
		for (i = 0; i < arr.size() - 1; i++) {

			position = i;

			for (j = i + 1; j < arr.size(); j++) {

				if (arr[position] > arr[j]) {
					position = j;
				}
				swap(arr[i], arr[position]);
			}
		}
	}

	else {
		for (i = 0; i < arr.size() - 1; i++) {

			position = i;

			for (j = i + 1; j < arr.size(); j++) {

				if (arr[position] < arr[j]) {
					position = j;
				}
				swap(arr[i], arr[position]);
			}
		}
	}
}

#pragma endregion

#pragma region array

void selectSort(int arr[], int n, char order) {

	int i;
	int j;
	int position;

	if (order == 'a') {
		for (i = 0; i < n - 1; i++) {

			position = i;

			for (j = i + 1; j < n; j++) {

				if (arr[position] > arr[j]) {
					position = j;
				}
				swap(arr[i], arr[position]);
			}
		}
	}

	else {
		for (i = 0; i < n - 1; i++) {

			position = i;

			for (j = i + 1; j < n; j++) {

				if (arr[position] < arr[j]) {
					position = j;
				}
				swap(arr[i], arr[position]);
			}
		}
	}
}

void selectSort(float arr[], int n, char order) {

	int i;
	int j;
	int position;

	if (order == 'a') {
		for (i = 0; i < n - 1; i++) {

			position = i;

			for (j = i + 1; j < n; j++) {

				if (arr[position] > arr[j]) {
					position = j;
				}
				swap(arr[i], arr[position]);
			}
		}
	}

	else {
		for (i = 0; i < n - 1; i++) {

			position = i;

			for (j = i + 1; j < n; j++) {

				if (arr[position] < arr[j]) {
					position = j;
				}
				swap(arr[i], arr[position]);
			}
		}
	}
}

void selectSort(double arr[], int n, char order) {

	int i;
	int j;
	int position;

	if (order == 'a') {
		for (i = 0; i < n - 1; i++) {

			position = i;

			for (j = i + 1; j < n; j++) {

				if (arr[position] > arr[j]) {
					position = j;
				}
				swap(arr[i], arr[position]);
			}
		}
	}

	else {
		for (i = 0; i < n - 1; i++) {

			position = i;

			for (j = i + 1; j < n; j++) {

				if (arr[position] < arr[j]) {
					position = j;
				}
				swap(arr[i], arr[position]);
			}
		}
	}
}

#pragma endregion

#pragma endregion

#pragma region bubble


#pragma region vector

void bubbleSort(vector<int> arr, char order) {

	int i;
	int j;
	if(order == 'a'){
		for (j = 0; j < arr.size() - 1; j++) {
			for (i = 0; i < arr.size() - j - 1; i++) {

				if (arr[i] > arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
				}
			}
		}
	}

	else {
		for (j = 0; j < arr.size() - 1; j++) {
			for (i = 0; i < arr.size() - j - 1; i++) {

				if (arr[i] < arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
				}
			}
		}
	}
}

void bubbleSort(vector<float> arr, char order) {

	int i;
	int j;
	if (order == 'a') {
		for (j = 0; j < arr.size() - 1; j++) {
			for (i = 0; i < arr.size() - j - 1; i++) {

				if (arr[i] > arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
				}
			}
		}
	}

	else {
		for (j = 0; j < arr.size() - 1; j++) {
			for (i = 0; i < arr.size() - j - 1; i++) {

				if (arr[i] < arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
				}
			}
		}
	}
}

void bubbleSort(vector<double> arr, char order) {

	int i;
	int j;
	if (order == 'a') {
		for (j = 0; j < arr.size() - 1; j++) {
			for (i = 0; i < arr.size() - j - 1; i++) {

				if (arr[i] > arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
				}
			}
		}
	}

	else {
		for (j = 0; j < arr.size() - 1; j++) {
			for (i = 0; i < arr.size() - j - 1; i++) {

				if (arr[i] < arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
				}
			}
		}
	}
}

#pragma endregion

#pragma region array

void bubbleSort(int arr[], int n, char order) {

	int i;
	int j;
	if (order == 'a') {
		for (j = 0; j < n - 1; j++) {
			for (i = 0; i < n - j - 1; i++) {

				if (arr[i] > arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
				}
			}
		}
	}

	else {
		for (j = 0; j < n - 1; j++) {
			for (i = 0; i < n - j - 1; i++) {

				if (arr[i] < arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
				}
			}
		}
	}
}

void bubbleSort(float arr[], int n, char order) {

	int i;
	int j;
	if (order == 'a') {
		for (j = 0; j < n - 1; j++) {
			for (i = 0; i < n - j - 1; i++) {

				if (arr[i] > arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
				}
			}
		}
	}

	else {
		for (j = 0; j < n - 1; j++) {
			for (i = 0; i < n - j - 1; i++) {

				if (arr[i] < arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
				}
			}
		}
	}
}

void bubbleSort(double arr[], int n, char order) {

	int i;
	int j;
	if (order == 'a') {
		for (j = 0; j < n - 1; j++) {
			for (i = 0; i < n - j - 1; i++) {

				if (arr[i] > arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
				}
			}
		}
	}

	else {
		for (j = 0; j < n - 1; j++) {
			for (i = 0; i < n - j - 1; i++) {

				if (arr[i] < arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
				}
			}
		}
	}
}

#pragma endregion

#pragma endregion

#pragma region insert


#pragma region vector

void insertSort(vector<int> arr, char order) {
	int i;
	int j;
	int num;

	if (order == 'a') {
		for (i = 0; i < arr.size(); i++) {

			num = arr[i];
			j = i;

			while (j > 0 && num < arr[j - 1]) {

				arr[j] = arr[j - 1];
				j -= 1;
			}
			arr[j] = num;
		}
	}

	else {
		for (i = 0; i < arr.size(); i++) {

			num = arr[i];
			j = i;

			while (j > 0 && num > arr[j - 1]) {

				arr[j] = arr[j - 1];
				j -= 1;
			}
			arr[j] = num;
		}
	}


}

void insertSort(vector<double> arr, char order) {
	int i;
	int j;
	double num;

	if (order == 'a') {
		for (i = 0; i < arr.size(); i++) {

			num = arr[i];
			j = i;

			while (j > 0 && num < arr[j - 1]) {

				arr[j] = arr[j - 1];
				j -= 1;
			}
			arr[j] = num;
		}
	}

	else {
		for (i = 0; i < arr.size(); i++) {

			num = arr[i];
			j = i;

			while (j > 0 && num > arr[j - 1]) {

				arr[j] = arr[j - 1];
				j -= 1;
			}
			arr[j] = num;
		}
	}


}

void insertSort(vector<float> arr, char order) {
	int i;
	int j;
	float num;

	if (order == 'a') {
		for (i = 0; i < arr.size(); i++) {

			num = arr[i];
			j = i;

			while (j > 0 && num < arr[j - 1]) {

				arr[j] = arr[j - 1];
				j -= 1;
			}
			arr[j] = num;
		}
	}

	else {
		for (i = 0; i < arr.size(); i++) {

			num = arr[i];
			j = i;

			while (j > 0 && num > arr[j - 1]) {

				arr[j] = arr[j - 1];
				j -= 1;
			}
			arr[j] = num;
		}
	}


}

#pragma endregion

#pragma region array

void insertSort(int arr[], int n, char order) {
	int i;
	int j;
	int num;

	if (order == 'a') {
		for (i = 0; i < n; i++) {

			num = arr[i];
			j = i;

			while (j > 0 && num < arr[j - 1]) {

				arr[j] = arr[j - 1];
				j -= 1;
			}
			arr[j] = num;
		}
	}

	else {
		for (i = 0; i < n; i++) {

			num = arr[i];
			j = i;

			while (j > 0 && num > arr[j - 1]) {

				arr[j] = arr[j - 1];
				j -= 1;
			}
			arr[j] = num;
		}
	}


}

void insertSort(float arr[], int n, char order) {
	int i;
	int j;
	float num;

	if (order == 'a') {
		for (i = 0; i < n; i++) {

			num = arr[i];
			j = i;

			while (j > 0 && num < arr[j - 1]) {

				arr[j] = arr[j - 1];
				j -= 1;
			}
			arr[j] = num;
		}
	}

	else {
		for (i = 0; i < n; i++) {

			num = arr[i];
			j = i;

			while (j > 0 && num > arr[j - 1]) {

				arr[j] = arr[j - 1];
				j -= 1;
			}
			arr[j] = num;
		}
	}


}

void insertSort(double arr[], int n, char order) {
	int i;
	int j;
	double num;

	if (order == 'a') {
		for (i = 0; i < n; i++) {

			num = arr[i];
			j = i;

			while (j > 0 && num < arr[j - 1]) {

				arr[j] = arr[j - 1];
				j -= 1;
			}
			arr[j] = num;
		}
	}

	else {
		for (i = 0; i < n; i++) {

			num = arr[i];
			j = i;

			while (j > 0 && num > arr[j - 1]) {

				arr[j] = arr[j - 1];
				j -= 1;
			}
			arr[j] = num;
		}
	}


}

#pragma endregion


#pragma endregion


#pragma region search


#pragma region binary


#pragma region array

int binarySearch(int arr[], int& size, int target) {

	int first = 0;
	int middle;
	int last = size - 1;
	int position = -1;

	bool found = false;

	while (!found && first <= last) {

		middle = (first + last) / 2;

		if (arr[middle] == target) {

			position = middle;
			found = true;
		}

		else if (arr[middle] < target) {

			first = middle + 1;
		}

		else {

			last = middle - 1;
		}

	}

	return position;
}

int binarySearch(float arr[], int& size, float target) {

	int first = 0;
	int middle;
	int last = size - 1;
	int position = -1;

	bool found = false;

	while (!found && first <= last) {

		middle = (first + last) / 2;

		if (arr[middle] == target) {

			position = middle;
			found = true;
		}

		else if (arr[middle] < target) {

			first = middle + 1;
		}

		else {

			last = middle - 1;
		}

	}

	return position;
}

int binarySearch(double arr[], int& size, double target) {

	int first = 0;
	int middle;
	int last = size - 1;
	int position = -1;

	bool found = false;

	while (!found && first <= last) {

		middle = (first + last) / 2;

		if (arr[middle] == target) {

			position = middle;
			found = true;
		}

		else if (arr[middle] < target) {

			first = middle + 1;
		}

		else {

			last = middle - 1;
		}

	}

	return position;
}

#pragma endregion

#pragma region vector

int binarySearch(vector<int> arr, int target) {

	int first = 0; 
	int middle;
	int last = arr.size() - 1;
	int position = -1;

	bool found = false;

	while (!found && first <= last) {
		
		middle = (first + last) / 2;

		if (arr[middle] == target) {

			position = middle;
			found = true;
		}

		else if (arr[middle] < target) {

			first = middle + 1;
		}

		else {

			last = middle - 1;
		}

	}

	return position;
}

int binarySearch(vector<float> arr, float target) {

	int first = 0;
	int middle;
	int last = arr.size() - 1;
	int position = -1;

	bool found = false;

	while (!found && first <= last) {

		middle = (first + last) / 2;

		if (arr[middle] == target) {

			position = middle;
			found = true;
		}

		else if (arr[middle] < target) {

			first = middle + 1;
		}

		else {

			last = middle - 1;
		}

	}

	return position;
}

int binarySearch(vector<double> arr, double target) {

	int first = 0;
	int middle;
	int last = arr.size() - 1;
	int position = -1;

	bool found = false;

	while (!found && first <= last) {

		middle = (first + last) / 2;

		if (arr[middle] == target) {

			position = middle;
			found = true;
		}

		else if (arr[middle] < target) {

			first = middle + 1;
		}

		else {

			last = middle - 1;
		}

	}

	return position;
}

#pragma endregion


#pragma endregion

# pragma region linear


#pragma region array

int linearSearch(int arr[], int& size, int& target) {

	int i;
	int position = -1;

	for (i = 0; i < size; i++) {

		if (arr[i] == target) {
			position = i;
		}
	}
	return position;
}

float linearSearch(float arr[], int& size, float& target) {

	int i;
	int position= -1;

	for (i = 0; i < size; i++) {

		if (arr[i] == target) {
			position = i;
		}
	}
	return position;
}

double linearSearch(double arr[], int& size, double& target) {

	int i;
	int position = -1;

	for (i = 0; i < size; i++) {

		if (arr[i] == target) {
			position = i;
		}
	}
	return position;
}

#pragma endregion

#pragma region vector

int linearSearch(vector<int>& arr, int& target) {

	int i;
	int position = -1;

	for (i = 0; i < arr.size(); i++) {

		if (arr[i] == target) {
			position = i;
		}
	}
	return position;
}

float linearSearch(vector<float>& arr, float& target) {

	int i;
	int position= -1;

	for (i = 0; i < arr.size(); i++) {

		if (arr[i] == target) {
			position = i;
		}
	}
	return position;
}

double linearSearch(vector<double>& arr, double& target) {

	int i;
	int position = -1;

	for (i = 0; i < arr.size(); i++) {

		if (arr[i] == target) {
			position = i;
		}
	}
	return position;
}

#pragma endregion


#pragma endregion


#pragma endregion


#pragma endregion


//endprogram
int endProgram() {
	cout << "Press any key to exit";
	cin.ignore(100, '\n');
	cin.get();
	return 0;
}