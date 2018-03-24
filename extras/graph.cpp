/*
Implement BFS and DFS over a class by taking graph as a input from a file. 
class Graph {
	constructor("filename")
	DFS method() {stack}
	BFS method() {queue}
}
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int vertex, int visited[], vector <int> *adj);

class Graph {
private:
	vector <int> *adj;
	int size;
public:
	Graph(int s) {
		size = s;
		FILE *f;
		char c;
		int toggleVertex = 1;
		f = fopen("graph.txt","r");

		/*if(f) {
			while((c = getc(f)) != EOF) {
				cout<<c;
				if(toggleVertex == 1)
				if(c=='\n')
					toggleVertex = 0;
			}
		}
		cout<<endl;*/
		adj = new vector <int>[s];
	}
	int breadhFirstSearch(int k);
	int depthFirstSearch(int k);
	void display();
	void addEdge(int u, int v)
	{
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
}; //end of graph class

void Graph::display() {
	vector <int> :: iterator i;
	for(int j = 0; j < size; j++) {
		cout<<"For vertex "<<j<<endl;
		for (i = adj[j].begin(); i != adj[j].end(); ++i)
        	cout << *i << ' ';
    	cout<<endl;
	}
}

int Graph::depthFirstSearch(int k) {
	cout<<"Depth First Search in action"<<endl;
	int visited[size], j;
	//initializing visited with false
	for(j = 0; j < size; j++) {
		visited[j] = 0;
	}

	for(j = 0; j < size; j++) {
		if(visited[j] == 0)
			dfs(j, visited, adj);
	}
	cout<<endl;

}

void dfs(int vertex, int visited[], vector <int> *adj) {
	visited[vertex] = 1;
	cout<<vertex<<" ";
	//visit the children for that vertex
	for(int j = 0; j < adj[vertex].size(); j++) {
		if(visited[adj[vertex][j]] == 0)
			dfs(adj[vertex][j], visited, adj);
	}
}

int main() {
	Graph g(5);
	g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.display();
    g.depthFirstSearch(3);
	return 0;	
}

