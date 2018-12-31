#include <iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
struct NgayThang
{
	int ng;
	int	tg;
	int nm;
};
void Nhap(string &s, NgayThang &ngay)
{
	
	cout<<"nhap ngay thang nam :";
	getline(cin,s);
	cout<<s;
}
void LayDMY(string &s, NgayThang &ngay)
{
	ngay.ng = atoi((s.substr(0,2)).c_str());
	cout<<ngay.ng<<endl;
	ngay.tg = atoi((s.substr(3,2)).c_str());
	cout<<ngay.tg<<endl;
	ngay.nm = atoi((s.substr(6,4)).c_str());
	cout<<ngay.nm<<endl;
}
int ktranhuan(NgayThang ngay)
{
    if((((ngay.nm)%100==0) && ( (ngay.nm)%400==0) )||(((ngay.nm)%100!=0) && ( (ngay.nm)%4==0) ))
        return 1;
    else
        return 0;
}
int tinhSoNgayTrongThang(NgayThang ngay)
{
	int nNumOfDays;

	switch (ngay.tg)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: 
		nNumOfDays = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11: 
		nNumOfDays = 30;
		break;
	case 2:
		if (ktranhuan(ngay)==1)
		{
			nNumOfDays = 29;
		}
		else
		{
			nNumOfDays = 28;
		}
		break;
	}

	return nNumOfDays;
}
int tinhSTTNgayTrongNam(NgayThang ngay)
{
	int count = ngay.ng;

	for (int i = 1; i <= ngay.tg - 1; i++)
	{
		count = count + tinhSoNgayTrongThang(ngay,i);
	}
	
	return count;
}
void sothutungaytrongnam(NgayThang ngay)
{
    int n, thutu;
    n=0;
    switch (ngay.tg)
    {
    case 12: n=n+30;
    case 11: n=n+31;
    case 10: n=n+30;
    case 9: n=n+31;
    case 8: n=n+31;
    case 7: n=n+30;
    case 6: n=n+31;
    case 5: n=n+30;
    case 4: n=n+31;
    case 3: if(ktranhuan(ngay))
                n=n+29;
            else
                n=n+28;
    case 2: n=n+31;
    case 1: n=n;
    }
    thutu=n+(ngay.ng);
    cout<<"ngay thu "<<thutu <<" trong nam";
}
//int CongSoNguyenDuong(NgayThang &ngay)
//{	
//	int n;
//	cout<<"nhap so nguyen duong :";
//	cin>>n;
//	int k = n + tinhSTTNgayTrongNam(ngay);
//	int h = tinhSoNgayTrongThang(ngay,);
//		
//}
int main()
{	
	struct NgayThang ngay;
	string s;
	Nhap(s,ngay);
//	cout<<"nhap ngay thang nam : ";
//	getline(cin,s);
	LayDMY(s,ngay);
	cout<<endl;
	if(ktranhuan(ngay) == 1)
		cout<<"nam vua nhap la nam nhuan :"<<endl;
	else
		cout<<"nam vua nhap khong la nam nhuan :"<<endl;
	
	cout<<"ngay thu "<<tinhSTTNgayTrongNam(ngay) << " trong nam"<<endl;///tinh thang cach 1
	sothutungaytrongnam(ngay);///tinh thang cach 2
	
}
