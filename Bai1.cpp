#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string.h>
using namespace std;

fstream fio("IOputContact.dat");

typedef struct {
	char name[30]; 
	char phone[11]; 
	char email[30]; 
	char address[50]; 
	char sex[5];
} CONTACT;

vector <CONTACT> db;

void readFileContact();
void writeFileContact();
void addContact();
void showFileContact();
void editByPhone();
void deleteByPhone();
void searchByName();
void showMenu();
void menuOption();
bool returnToMenu();

//Read file .dat contact
void readFileContact(){
	CONTACT c;
	
	while(!fio.eof()) {
		fio.read(c.name, 30);
		fio.read(c.sex, 5);
		fio.read(c.phone, 10);
		fio.read(c.email, 30);
		fio.read(c.address, 50);
		
		db.push_back(c);
	}
	fio.close();
	db.pop_back();
}

//Write file .dat contact
void writeFileContact() {
	for (int i = 0; i < db.size(); i++) {
		fio.write(db[i].name, sizeof(db[i].name));
		fio.write(db[i].sex, sizeof(db[i].sex));
		fio.write(db[i].phone, sizeof(db[i].phone));
		fio.write(db[i].email, sizeof(db[i].email));
		fio.write(db[i].address, sizeof(db[i].address));	
	}
	fio.close(); 
}

//Show file .dat contact
void showFileContact() {
	for (int i = 0; i < db.size(); i++) {
		cout << "----------------" << endl;
		cout << db[i].name << endl;
		cout << db[i].sex << endl;
		cout << db[i].phone << endl;
		cout << db[i].email << endl;
		cout << db[i].address << endl;
	}
}

// add machine in file
void addContact() { 
	CONTACT addFile1;
	strcpy(addFile1.name, "Son");
	strcpy(addFile1.sex, "Nam");
	strcpy(addFile1.phone, "0985407705");
	strcpy(addFile1.email, "nhuson2306@gmail.com");
	strcpy(addFile1.address, "QuangTri");
	db.push_back(addFile1);
	
	CONTACT addFile2;
	strcpy(addFile2.name, "Suong");
	strcpy(addFile2.sex, "Nu");
	strcpy(addFile2.phone, "0336692745");
	strcpy(addFile2.email, "xuansuonga3@gmail.com");
	strcpy(addFile2.address, "CamLam");
	db.push_back(addFile2);
	
	CONTACT addFile3;
	strcpy(addFile3.name, "Vy");
	strcpy(addFile3.sex, "Nam");
	strcpy(addFile3.phone, "0384722549");
	strcpy(addFile3.email, "nguyentrieuvy@gmail.com");
	strcpy(addFile3.address, "CamRanh");
	db.push_back(addFile3);
}

// edit contact with by name

// edit contact with by phone
void editByPhone() {
	CONTACT cEdit;
	
	int item;
	char ePhone[11];
	
	cout << "Enter the phone to fix: ";
	cin >> ePhone;
	
	for (int i = 0; i < db.size(); i++) {
		if (strcmp(ePhone, db[i].phone) == 0) {
			item = i;
			db.erase(db.begin() + item);
			cout << "New name: ";
			cin >> cEdit.name;
			cout << "New sex: ";
			cin >> cEdit.sex;
			cout << "New phone: ";
			cin >> cEdit.phone;
			cout << "New email: ";
			cin >> cEdit.email;
			cout << "New address: ";
			cin >> cEdit.address;
			db.insert(db.begin() + item , cEdit);
		}
	}
}

// Delete contact with by name

// Delete contact with by phone
void deleteByPhone() {
	int item;
	char dePhone[11];
	
	cout << "Enter the phone to delete: ";
	cin >> dePhone;
	
	for (int i = 0; i < db.size(); i++) {
		if (strcmp(dePhone, db[i].phone) == 0) {
			item = i;
			db.erase(db.begin() + item);		
		}
	}
}

// Search contact with by phone

// Search contact with by name
void searchByName() {
	int item;
	char sName[20];
	
	cout << "Enter name: ";
	cin >> sName;
	
	for (int i = 0; i < db.size(); i++) {
		if(strcmp(sName, db[i].name) == 0){
			item = i;
			cout << "----------------" << endl;
			cout << db[item].name << endl;
			cout << db[item].sex << endl;
			cout << db[item].phone << endl;
			cout << db[item].email << endl;
			cout << db[item].address << endl;
		}
		
	}
}

bool returnToMenu() {
	char rtnMenu;
	cout << "-----------------------------" << endl;
    cout << "Enter z to return to the menu:> "; 
	cin >> rtnMenu;

    if(rtnMenu == 'z' || rtnMenu == 'Z') {
        return true;
    } return false;
}

void showMenu() {
	cout << "1. Add contact" << endl;
	cout << "2. Show contact" << endl;
	cout << "3. Edit contact" << endl;
	cout << "4. Delete contact" << endl;
	cout << "5. Find contact" << endl;
	cout << "6. Exit contact" << endl;
}

void menuOption() {
	int mo;
	cout << "Enter your choice:> ";
	cin >> mo;
	
	switch(mo) {
		case 1:
			system("cls");
			addContact();
			writeFileContact();
			cout << "Add contact successfully!" << endl;
			
			if(returnToMenu()) {
                system("cls");
                showMenu();
                menuOption();
            } else {
                cout << "Exited!" << endl;
            }
			break;
		case 2: 
			system("cls");
			showFileContact();
			
			if(returnToMenu()) {
                system("cls");
                showMenu();
                menuOption();
            } else {
                cout << "Exited!" << endl;
            }
			break;
		case 3: 
			system("cls");
			cout << "------ Edit ------" << endl;
			editByPhone();
			cout << "Edit successfully!" << endl;
			
			if(returnToMenu()) {
                system("cls");
                showMenu();
                menuOption();
            } else {
                cout << "Exited!" << endl;
            }
			break;
		case 4: 
			system("cls");
			cout << "------ Delete ------" << endl;
			deleteByPhone();
			cout << "Delete successfully!" << endl;
			
			if(returnToMenu()) {
                system("cls");
                showMenu();
                menuOption();
            } else {
                cout << "Exited!" << endl;
            }
			break;
		case 5: 
			system("cls");
			cout << "------ Search ------" << endl;
			searchByName();
			
			if(returnToMenu()) {
                system("cls");
                showMenu();
                menuOption();
            } else {
                cout << "Exited!" << endl;
            }
			break;
		case 6: 
			cout << "Exited!" << endl;
            break;
		default:
            system("cls");
            showMenu();
            cout << "Wrong option!" << endl;
            menuOption();
	}
}

int main() {	
	showMenu();
	menuOption();
	
	return 0;
}
