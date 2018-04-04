/*
An example of operator overloading
*/

#include <bits/stdc++.h>
using namespace std;


class Complex {
	float rl, img;
public:
	float mod, avg;
	
	Complex(float x = 1.0, float y = 1.0) {
		rl = x;
		img = y;
	}
	
	~Complex() {}
	//Complex &addComplex(Complex &x); //c1=c2.addComplex(c3)
	//Complex &operator+(Complex &x); //c1=c2+c3
	//Complex &operator+(int x); //c1=c2+2
	friend Complex &operator+(Complex &a, Complex &b); //using friend function c1 = c2+c3
	friend Complex &operator+(int x, Complex &b); //using friend function c1 = 2+C2
	friend Complex &operator+(Complex &a, int x); //using friend function c1 = c2+2
	friend void operator<<(const ostream &a, Complex &x); //cout<<c1;
};

int main(void) {
	Complex c1, c2(5), c3(3,5);
	//c1 = c2.addComplex(c3);
	c1 = c2+c3; //either c2.operator+(c3) or operator+(c2,c3)
	cout<<c1;
	cout<<c2;
	cout<<c3;
	c1 = c2+2; //either c2.operator+(2) or operator+(c2, 2)
	cout<<c1;
	c1 = 3+c2; //only operator+(3, c2)
	cout<<c1;
	return 0;
}

//-----------------------FUNCTION DEFINITIONS-------------------------

Complex &operator+ (Complex &a, Complex &b) { //using friend function c1 = 2+C2
	static Complex t;
	t.rl = a.rl + b.rl;
	t.img = a.img + b.img;
	return (t);
}

Complex &operator+ (int x, Complex &b) { //using friend function c1 = 2+C2
	static Complex t;
	t.rl = x + b.rl;
	t.img = b.img;
	return (t);
}

Complex &operator+ (Complex &a, int x) { //using friend function c1 = c2+2
	static Complex t;
	t.rl = a.rl + x;
	t.img = a.img;
	return (t);
}

void operator<<(const ostream &a, Complex &x) { //cout<<c1;
		cout<<x.rl<<'+'<<x.img<<'i'<<endl;
	}

/*Complex &Complex::operator+(Complex &x) { //c1=c2+c3
	static Complex t;
	t.rl = rl + x.rl;
	t.img = img + x.img;
	return (t);
}

Complex &Complex::addComplex(Complex &x) { //c1=c2.addComplex(c3)
	static Complex t;
	t.rl = rl + x.rl;
	t.img = img + x.img;
	return (t);
}

Complex &Complex::operator+(int x) { //c1=c2+2
	static Complex t;
	t.rl = rl + x;
	t.img = img;
	return (t);
}*/

