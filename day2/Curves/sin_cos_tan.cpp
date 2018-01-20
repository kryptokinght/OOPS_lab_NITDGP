#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void plot(double (*func)(double), double step, double x1, double x2, double y);
void input(double *x1, double *x2, double *y, double *steps);
double damped(double t);
double w0,x0,v0,v;

int main() {
	double val;
	double x1, x2, y, steps;
	cout<<"1. sine surve"<<endl;
	cout<<"2. cos surve"<<endl;
	cout<<"3. tan surve"<<endl;
	cout<<"4. exp curve"<<endl;
	cout<<"5. damped oscillation curve"<<endl;
	int ch;
	cout<<"Enter your choice:"<<endl;
	cin>>ch;
	switch(ch) {
		case 1:
			input(&x1, &x2, &y, &steps);
			plot(&sin, steps, x1, x2, y);
			break;
		case 2:
			input(&x1, &x2, &y, &steps);
			plot(&cos, steps, x1, x2, y);
			break;
		case 3:
			input(&x1, &x2, &y, &steps);
			plot(&tan, steps, x1, x2, y);
			break;
		case 4:
			input(&x1, &x2, &y, &steps);
			plot(&exp, steps, x1, x2, y);
			break;
		case 5:
			cout<<"Enter values for w0,v0,x0,v"<<endl;
			cin>>w0>>v0>>x0>>v;
			input(&x1, &x2, &y, &steps);
			plot(&damped, steps, x1, x2, y);
			break;
		default: cout<<"Wrong Entry"<<endl;
	}
	//end of main
}

void plot(double (*func)(double), double step, double x1, double x2, double y) {
	double i, j, val, scale, forw;
	int dec = 0;
	scale = 70/y;
	cout<<"SCALE:"<<scale<<endl;
	int stars, count = 0;
	for(i = x1; i < x2; i = i + step) {
		count++;
    	if(count%40 == 0)
      		cin.get();
		val = func(i);
		forw = func(i + step);
		if(val < 0) {
			if(val < -y)
				stars = 70;
			else
				stars = -int(val*scale);
			cout<<setw(72-stars);
			if((forw - val) > 0 && dec == 1) {
				dec = 0;
				cout<<"-1";
			}
			for(j = 0; j < stars; j++)
				cout<<"*";	
			cout<<"|";
		}
		else {
			if(val > y)
				stars = 70;
			else
				stars = int(val*scale);
			cout<<setw(72)<<"|";
			for(j = 0; j < stars; j++)
				cout<<"*";
			if((forw - val) < 0 && dec == 0) {
				dec = 1;
				cout<<"1";
			}

		}
		cout<<endl;		
	}
}

void input(double *x1, double *x2, double *y, double *steps) {
	cout<<"Enter values for x1,x2,y,steps"<<endl;
	cin>>*x1>>*x2>>*y>>*steps;	
}

double damped(double t) {
	double wr = sqrt(w0*w0 - v*v);
	return x0*exp((-v)*t)*cos(wr*t) + ((v0+v*x0)/wr)*exp(-v*t)*sin(wr*t);
}
