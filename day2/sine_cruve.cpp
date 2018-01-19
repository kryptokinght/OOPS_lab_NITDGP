#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
  double val;
  int count = 0, j ,stars;
  for(double i = 0; i < 5*M_PI; i = i + 0.1) {
    count++;
    if(count%40 == 0)
      cin.get();
    val = sin(i);
    if(val < 0) {
    	stars = -int(val*74);
    	cout<<setw(76-stars);
	    for(j = 0; j < stars; j++)
	      cout<<"*";	
	  	cout<<"|";
    }
    else {
	    stars = int(val*74);
	    cout<<setw(76)<<"|";
	    for(j = 0; j < stars; j++)
	      cout<<"*";	
    }
    
    cout<<endl;
  }
}