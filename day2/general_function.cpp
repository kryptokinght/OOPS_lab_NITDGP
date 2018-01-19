#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double (*func)(double);
void plot(double (*func)(double), double step, double x1, double x2, double y1, double y2);

int main() {
	double val;
	cout<<"1. sine curve"<<endl;
	cout<<"2. cos curve"<<endl;
	cout<<"3. tan curve"<<endl;
	int ch;
	cout<<"Enter your choice:"<<endl;
	cin>>ch;
	switch(ch) {
		case 1:
			func = &sin;
			plot(func, 0.1, 0, M_PI*5, -1, 1);
			break;
		case 2:
			func = &cos;
			plot(func, 0.1, 0, M_PI*5, -1, 1);
			break;
		case 3:
			func = &tan;
			plot(func, 0.1, 0, M_PI*5, -1, 1);
			break;
		
		default: cout<<"Wrong Entry"<<endl;
	}
	cout<<"*"<<endl;
}

void plot(double (*func)(double), double step, double x1, double x2, double y1, double y2) {
	double i, j, val;
	int stars, count = 0;
	for(i = x1; i < x2; i = i + step) {
		count++;
    	if(count%40 == 0)
      		cin.get();
		val = func(i);
		if(val < 0) {
			if(val < y1)
				stars = 74;
			else
				stars = -int(val*74);
			cout<<setw(76-stars);
			for(j = 0; j < stars; j++)
				cout<<"*";	
			cout<<"|";
		}
		else {
			if(val > y2)
				stars = 74;
			else
				stars = int(val*74);
			cout<<setw(76)<<"|";
			for(j = 0; j < stars; j++)
				cout<<"*";	
		}
		cout<<endl;		
	}
}
