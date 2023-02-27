#include <map>
#include <string>
#include <iostream>
#include <fstream>
//packages for map,string,input/output stream, and file stream

using namespace std;

class ItemList {
private:
	map<string,int>maplist;
	//map to store word and frequency from the file

public:
	//constructor to readfile
	ItemList() {
		string word;
		ifstream readFile("CS210_Project_Three_Input_File.txt");
		while (readFile >> word) {
			maplist[word]++;
		}
		//read file with input words loop through entire file before closiing
		readFile.close();
		//close file when done using
	}

	void PrintWord(string word) {
		cout << "What word would you like to search" << endl;
		cin >> word;
		cout << word << " Frequency: " << maplist[word] << endl << endl;
	}
	//print word based off user input and value attached to key

	void PrintList() {
		cout << "Purchase Frequency" << endl << "-------------------" << endl;
		for (auto const& item : maplist) {
			cout << item.first << " " << item.second << endl;
		}
		cout << endl;
	}
	//print entire map via loop iteration using auto increment to be able to utilize first and second attributes

	void Histogram() {
		cout << "Purchase Frequency (Histogram)" << endl << "-------------------" << endl;
		for (auto const& item : maplist) {
			cout << item.first << " ";
			for (int x = 0; x < item.second; x++) {
				cout << "*";
			}
			cout << endl;
		}
		cout << endl;
	}
	//create histogram of the data using loop with same technique but additonal loop to generate *

	void storeData() {
		ofstream outfile("frequency.dat");
		for (auto const& item : maplist) {
			outfile << item.first << " " << item.second<< endl;
		}
		outfile.close();
		//write to backup file after reading file
	}
	

};
//public functions 

int main() {
string word;
int menuChoice = 0;
ItemList ItemList;
ItemList.storeData();
//readfile and store data first then while loop for menu
while (menuChoice != 4){
	cout << "Menu" << endl;
	cout << "-------------------" << endl;
	cout << "1: Search Word Frequency" << endl;
	cout << "2: Print Frequency List" << endl;
	cout << "3: Print Histogram" << endl;
	cout << "4: Exit Program" << endl;
	cin >> menuChoice;
	//switch case to iterate through inputs 
	switch (menuChoice) {
		case 1:
			ItemList.PrintWord(word);
			cout << "Menu" << endl;
			cout << "-------------------" << endl;
			cout << "1: Search Word Frequency" << endl;
			cout << "2: Print Frequency List" << endl;
			cout << "3: Print Histogram" << endl;
			cout << "4: Exit Program" << endl;
			cin >> menuChoice;
		case 2:
			ItemList.PrintList();
			cout << "Menu" << endl;
			cout << "-------------------" << endl;
			cout << "1: Search Word Frequency" << endl;
			cout << "2: Print Frequency List" << endl;
			cout << "3: Print Histogram" << endl;
			cout << "4: Exit Program" << endl;
			cin >> menuChoice;
		case 3:
			ItemList.Histogram();
			cout << "Menu" << endl;
			cout << "-------------------" << endl;
			cout << "1: Search Word Frequency" << endl;
			cout << "2: Print Frequency List" << endl;
			cout << "3: Print Histogram" << endl;
			cout << "4: Exit Program" << endl;
			cin >> menuChoice;
		case 4:
			cout << "Goodbye. Results save in file: frequency.dat "<< endl << endl;
			exit(0);
	}
	}
}
