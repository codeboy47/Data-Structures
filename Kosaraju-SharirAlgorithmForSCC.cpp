// Given a directed graph, find out whether the graph is strongly connected or not. A directed graph is 
// called strongly connected if there is a path from each vertex in the graph to every other vertex.
// Hint use  Strongly Connected Components (SCC) algorithm i.e. Kosaraju-Sharir Algorithm for SCC 
// ALGO : first call dfs with any vertex on directed graph, then check all elements of visited array 
// are true, if not return false, then make reverse of directed graph and call dfs with same vertex on it.
// Again check all elements of visited array are true then return true,if not return false.
// It calls dfs 2 times so time complexity is O(V + E)
// The above approach requires two traversals of graph. We can find whether a graph is strongly connected 
// or not in one traversal using Tarjan’s Algorithm to find Strongly Connected Components.
// We can also do bfs traversal instead of dfs
#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

// Directed Graph
class Graph{
	int V; // vertices
	vector<int> *arr; // better command over the elements if we use array of vector
	//list<int> *arr;  // we can also use array of linked list

public : 

	Graph(int vertices) : V(vertices) { 
		arr = new vector<int>[vertices]; // creating array of vectors equal to no of vertices
	}

	void addEdge(int u, int v){
		// this is done for directed graph
		arr[u].push_back(v);
	}

	void DFSHelper(int index, bool *visited){
		//cout<<index<<" ";
		visited[index] = true;
		vector<int>::iterator it;
		for(it = arr[index].begin();it != arr[index].end(); it++){
			if(visited[*it] == false) // this is done to ensure no elements get repeated
				DFSHelper(*it,visited);
		}
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

	bool isStronglyConnected(){

		bool *visited = new bool[V]; // dynamic array
		for(int i = 0; i < V; i++){
			visited[i] = false;
		}
		DFSHelper(0,visited);
		for(int i = 0; i < V; i++){
			if(visited[i] == false){
				return false;
			}
		}

		Graph gRev = reverseGraph();
		for(int i = 0; i < V; i++){
			visited[i] = false;
		}
		gRev.DFSHelper(0,visited);
		for(int i = 0; i < V; i++){
			if(visited[i] == false){
				return false;
			}
		}
		return true;
	}

	~Graph(){
		delete [] arr;
	}
};

int main(){

    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0);
    g1.addEdge(2, 4);
    g1.addEdge(4, 2);
    g1.isStronglyConnected()? cout << "Yes graph is strongly connected \n" : cout << "No\n";
 
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.isStronglyConnected()? cout << "Yes graph is strongly connected \n" : cout << "No\n";
 
    return 0;
}
