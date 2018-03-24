/*
Vectors are dynamic arrays that have the ablity to resize itself.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int s;
	vector <int> *g;
	vector <int> g1[2]; //array of vector elements
	g = new vector <int>[2];
    vector <int> :: iterator i;
    vector <int> :: reverse_iterator ir;
 	cout<<"Enter size"<<endl;
 	cin>>s;
    for (int j = 1; j <= 5; j++)
        g[3].push_back(j*2);
 	
    cout << "Output of begin and end: ";
    for (i = g[3].begin(); i != g[3].end(); ++i)
        cout << *i << ' ';
    cout<<endl;
    cout<<g[3].empty()<<endl;
	/* 
    cout << "Output of rbegin and rend\t:\t";
    for (ir = g1.rbegin(); ir != g1.rend(); ++ir)
        cout << '\t' << *ir;*/
 	return 0;
}