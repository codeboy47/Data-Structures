// Q. Find all Strongly Connected Components (for directed graph)
// We can find all strongly connected components in O(V+E) time using Kosaraju’s algorithm.
// Links :	1. http://www.geeksforgeeks.org/strongly-connected-components/
// 2. https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/tutorial/
#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class Graph{
	
	int V; // vertices
	vector<int> *arr; // better command over the elements if we use array of vector

public:

	Graph(int vertices){
		V = vertices;
		arr = new vector<int>[vertices];
	}

	void addEdge(int u, int v){
		// this is done for directed graph
		arr[u].push_back(v);
	}

	Graph reverseGraph(){
		Graph gRev(V);
		for(int i = 0; i < V; i++){
			vector<int>::iterator it;
			for(it = arr[i].begin(); it != arr[i].end(); it++){
				gRev.arr[*it].push_back(i);
			}
		}
		return gRev;
	}

	// this function is same as dfsHelper but cout is omitted and we push vertices in stack
	void fillStackUsingDFSHelper(int source, bool *visited, stack<int> &Stack){
		visited[source] = true;
		vector<int>:: iterator it;
		for(it = arr[source].begin(); it != arr[source].end(); it++){
			if(visited[*it] == false){
				fillStackUsingDFSHelper(*it,visited,Stack);
			}
		}
		Stack.push(source); // 1 2 4 3 0(top)
	}

	void dfsHelper(int source, bool *visited){
		cout<<source<<" -> ";
		visited[source] = true;
		vector<int>:: iterator it;
		for(it = arr[source].begin(); it != arr[source].end(); it++){
			if(visited[*it] == false){
				dfsHelper(*it,visited);
			}
		}
	}

	void printSCC(){
		stack<int> Stack;
		bool *visited = new bool[V];
		for(int i = 0; i < V; i++){
			visited[i] = false;
		}
		for(int i = 0; i < V; i++){
			if(visited[i] == false){
				fillStackUsingDFSHelper(i,visited,Stack);
			}
		}
		Graph gRev(V);
		gRev = reverseGraph();
		for(int i = 0; i < V; i++){
			visited[i] = false;
		}
		while(!Stack.empty()){
			if(visited[Stack.top()] == false){
				gRev.dfsHelper(Stack.top(),visited);
				cout<<"NULL"<<endl;
			}
			Stack.pop();
		}
	}

};

int main(){
	Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    cout << "Following are strongly connected components in given graph :\n";
    g.printSCC();
    return 0;
}