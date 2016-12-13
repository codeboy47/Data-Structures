#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *arr;

    void DFSHelper(int s,bool *visited){
        cout<<s<<" --> ";
        visited[s] = true;
         list<int>::iterator it;
        for(it = arr[s].begin() ; it != arr[s].end();it++){
            if(visited[*it] ==false){
                DFSHelper(*it,visited);
            }
        }
        return;
    }

public:
Graph(int vertices){
	V = vertices;
	arr = new list<int>[V];
	//arr = new vector<vector<int> >(V);
	}
void addEdge(int u,int v){
	// undirected graph
	arr[u].push_back(v);
    arr[v].push_back(u);
}

void DFSPrint(){
    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    int component = 0;
    for(int i =0;i<V;i++){
        if(visited[i] == false){
            cout<<endl<<"component "<<++component<<" is : ";
            DFSHelper(i,visited);
        }
    }
    return;
}

bool isConnected(int s){
    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    DFSHelper(s,visited);
    for(int i =0;i<V;i++){
        cout<<"-"<<visited[i]<<"-";
        if(visited[i] == false){
            return false;
        }
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
        int f = q.front();
        q.pop();
        cout<<f<<" ";
        list<int>::iterator it;
        for(it = arr[f].begin() ; it != arr[f].end();it++){
            if(visited[*it] == false){
                q.push(*it);
                visited[*it] = true;
            }
        }
	}
	return;
}
int shortestPath(int s,int d){
    int *dist = new int[V];
    for(int i = 0;i<V;i++){
        dist[i] = -1;
    }
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        list<int>::iterator it;
        for(it = arr[f].begin() ; it != arr[f].end();it++){
         //   int k = i + 1;
            if(dist[*it] == -1){
                dist[*it] = dist[f] + 1;  /// put dist of children = dist of parent + 1 (level increased by 1)
                q.push(*it);
            }
        }
        if(f == d){
            for(int i =0;i<V;i++) cout<<endl<<dist[i]<<" ";
            cout<<endl;
            return dist[d];
        }
    }
    return -1;
}

void topological(){
        int *indegree = new int[V];
        for(int i=0;i<V;i++){
            indegree[i] = 0;
        }
		for(int i=0;i<V;i++){
            list<int>::iterator it;
            for(it = arr[i].begin();it!=arr[i].end();it++){
                indegree[*it]++; ///  *it means it->data
            }
		}
		int i =0 ;
        queue<int> q;
        for(int i =0;i<V;i++){
                if(indegree[i]==0){
                    q.push(i);
                }
        }
        /*
            1.push all those that have 0 indegree
            2.pop()
            3.print q.front()
            4.check its children have 0 indegree
            5.if yes  push them
            6.decrease degree of children by 1
            7.repeat step no 2,3,4,5,6
        */
        while(!q.empty()){
            int f = q.front();
            q.pop();
            cout<<f<<endl;
            list<int>::iterator it;
            for(it = arr[f].begin();it!=arr[f].end();it++){
                indegree[*it]--;
                if(indegree[*it] == 0 ){
                    q.push(*it);
                }
            }
        }
}

	~Graph(){
		delete [] arr;
	}
};


int main(){
Graph g(7);
g.addEdge(0,2);
g.addEdge(0,5);
g.addEdge(2,3);
g.addEdge(2,4);
g.addEdge(3,4);
g.addEdge(4,6);
g.addEdge(5,6);
g.addEdge(1,6);
//g.BFSPrint(0);
g.DFSPrint();
g.topological();
cout<< "Shortest Path is "<< g.shortestPath(0,6)<<endl;
cout<<endl<<"graph is connected(1)/not_connected(0) : "<<g.isConnected(0);
/* graph is connected for undirected graph and not connected for directed graph since we cant reach 1*/
return 0;
}
