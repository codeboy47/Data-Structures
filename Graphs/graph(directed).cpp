#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *arr;

public:

    Graph(int vertices){
        V = vertices;
        arr = new list<int>[V];
    }
    void addEdge(int u,int v){
        arr[u].push_back(v);
        //arr[v].push_back(u);
    }

void DFSHelper(int s,bool*visited){
	cout<< s <<" -> ";
	visited[s] = true;

	list<int>::iterator it;
	for(it = arr[s].begin();it!=arr[s].end();it++){
			if(visited[*it]==false){
				DFSHelper(*it,visited);
			}
	}

}

void DFS(){
	bool *visited = new bool[V];

	for(int i=0;i<V;i++)
		{ visited[i] = false; }

	int component = 1;

	for(int i=0;i<V;i++){
		if(visited[i]==false)
			{ 	cout<<endl<<"Component "<<component <<" is : ";
				component++;
				DFSHelper(i,visited);}
			}

}


bool isConnected(int s){
	bool *visited = new bool[V];

	for(int i=0;i<V;i++)
		{ visited[i] = false; }

	DFSHelper(s,visited);
	for(int i=0;i<V;i++){
		if(visited[i]==false)
				return false;
	}
return true;
}

void BFSPrint(int s){
	bool *visited = new bool[V];

	for(int i=0;i<V;i++){
		visited[i] = false;
	}
	queue<int> q;
	q.push(s);
	visited[s] = true;

	while(!q.empty()){
		int front = q.front();
		cout<<front<<" ";
		q.pop();

		list<int>::iterator it;
		for(it = arr[front].begin();it!=arr[front].end();it++)
		{
			if(!visited[*it]){
				 q.push(*it);
                visited[*it] = true;
            }
		}
	}
}

void topologicalSort(){

int *indegree = new int[V];
//Initialise
for(int i=0;i<V;i++){
	indegree[i] = 0;
}
//Traverse adjacency list and increase indegree for v ( edge u-v)
for(int i=0;i<V;i++){
	list<int>::iterator it;
	for(it = arr[i].begin();it!=arr[i].end();it++){
		indegree[*it]++;
	}

}
// Find the nodes with indegree 0 and push them into queue.
queue<int> q;
for(int i=0;i<V;i++){
	if(indegree[i]==0){
		q.push(i);
	}
}
// Queue pop and .......

while(!q.empty()){
	int f = q.front();
	q.pop();
	cout<< f <<endl;
    list<int>::iterator it;
	for(  it = arr[f].begin();it!=arr[f].end();it++){
			indegree[*it]--;
			if(indegree[*it]==0){
				q.push(*it);
			}
		}
	}

return;
}

int shortestPath(int s,int d){

	int *dist = new int[V];
	for(int i=0;i<V;i++){
		dist[i] = -1;
	}

	queue<int> q;
	q.push(s);
	dist[s] = 0;

	while(!q.empty()){
		int f = q.front();
		q.pop();

		list<int>::iterator it;
		for(it = arr[f].begin();it!=arr[f].end();it++){
			if(dist[*it]==-1){
				dist[*it] = dist[f] + 1;
				q.push(*it);

				if(*it==d){
					return dist[*it];
				}
			}
		}
	}
return -1;
}

	~Graph(){
		delete [] arr;
	}
};



int main(){
Graph g(8);
g.addEdge(0,2);
g.addEdge(0,5);
g.addEdge(2,3);
g.addEdge(2,4);
g.addEdge(3,4);
g.addEdge(4,6);
g.addEdge(5,6);
g.addEdge(1,7);
//g.BFSPrint(3);
g.DFS();
g.topologicalSort();

if(g.isConnected(0))
	cout<<"Its a connected graph ";
else
	cout<<"Not connected";

cout<< endl<<"Shortest Path is "<< g.shortestPath(6,0);
return 0;
}
