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
    val = tan(i);
    if(val < 0) {
      if(val < -1)
        stars = 74;
      else
    	  stars = -int(val*74);
    	cout<<setw(76-stars);
	    for(j = 0; j < stars; j++)
	      cout<<"*";	
	  	cout<<"|";
    }
    else {
      if(val > 1)
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