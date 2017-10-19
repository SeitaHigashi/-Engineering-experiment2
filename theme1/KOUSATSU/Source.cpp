#include <iostream>

using namespace std;

void swap(int& x,int&y){int temp=x;x=y;y=temp;}
void swap(char& x,char& y){char temp=x;x=y;y=temp;}
void swap(double& x,double& y){double temp=x;x=y;y=temp;}

int main(){
	int x=6,y=4;
	char c1='S',c2='H';
	double a=5.7,b=8.3;
	cout << "x=" << x << ":y=" << y << endl;
	cout << "c1=" << c1 << ":c2=" << c2<< endl;
	cout << "a=" << a << ":b=" << b << endl;

	swap(x,y);
	swap(c1,c2);
	swap(a,b);

	cout << "x=" << x << ":y=" << y << endl;
	cout << "c1=" << c1 << ":c2=" << c2<< endl;
	cout << "a=" << a << ":b=" << b << endl;

	return 0;
}