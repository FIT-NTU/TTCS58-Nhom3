#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h> 
using namespace std;

struct DATE {
	int day;
	int month;
	int year;
};

void Import(string &s) {
	cout << "Nhap chuoi: ";
	getline(cin, s);
}

bool checkYear(int y) {
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		return true;
	return false;
}

int timSTT(DATE n) {
	int stt = 0;
	int month[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	for (int i = 0; i < n.month; i++)
		stt += month[i];
		stt += n.day;
		
	if (checkYear(n.year) == true)
		stt + 1;
	return stt;
}

int main() {
	DATE d;
	char c[4];
	string st;
	
	cout << endl;
	
	Import(st);
		
	c[0]= st[0];
	c[1] = st[1];
	d.day = atoi(c);
	cout<<"\nNgay: "<< d.day;
	
	c[0]= st[3];
	c[1] = st[4];
	d.month = atoi(c);
	cout << "\nThang: " << d.month;
	
	c[0] = st[6];
	c[1] = st[7];
	c[2] = st[8];
	c[3] = st[9];
	d.year = atoi(c);
	cout << "\nNam: " << d.year;
	
	if(checkYear(d.year)) 
		cout << "La nam nhuan!" << endl;
	else	
		cout << "La nam khong nhuan!"<<endl;
		
	cout << "STT ngay trong nam:" << timSTT(d);
}
