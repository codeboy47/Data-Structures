/* Dijkstra’s algorithm solves the single source shortest path problem for weighted directed graphs 
having non-negative edge costs. Given a weighted directed graph and a source vertex s, 
it finds shortest paths from s to every other vertex v. 

Running time analysis: Each edge is relaxed at most once and each edge relaxation might take 
O(log V) time to decrease a key in the priority queue, so the overall running time of Dijkstra’s algorithm
with indexed priority queue is O(E log V).*/

/* Links are 
https://kartikkukreja.wordpress.com/2013/06/03/dijkstras-single-source-shortest-path-algorithm/
http://www.geeksforgeeks.org/greedy-algorithms-set-7-dijkstras-algorithm-for-adjacency-list-representation/
dijkstra algo using set: 
http://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-set-in-stl/
dijkstra algo using priority queue:
http://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
*/
#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

#define inf 1000000000000000 // i.e. 10^15
typedef pair<int,int> isPair;

// Either use struct node1
struct nodeStruct{
	int dVertex;
	int weight;
};

// OR use class node2 to push it into vector of struct node1 or class node2
class nodeClass{
	int dVertex;
	int weight;
public:
	nodeClass(int v, int w) : dVertex(v) , weight(w) { } 
};


class Graph{
	
	int V; // vertices
	vector<isPair> *arr; // for nodeStruct
	//vector<nodeClass> *arr; // for nodeClass
	int weight; // weight of an edge

public:

	Graph(int vertices){
		V = vertices;
// making dynamic array arr(size V) of vectors of nodeStruct i.e. each vector block contains one nodeStruct
		arr = new vector<isPair>[vertices];
		//arr = new vector<nodeClass>[vertices];
	}

	void addEdge(int u, int v, int w){
		arr[u].push_back(make_pair(v,w)); // this is the way to push structure elements in vector
		arr[v].push_back(make_pair(u,w));
	}

	/* for class node 
	void addEdgeForClassNode(int u, int v, int w){
		nodeClass n1(v,w);
		nodeClass n2(u,w);
		arr[u].push_back(n1);
		arr[v].push_back(n2);
		//arr[u].push_back((nodeClass){v,w});
	}*/

	void printGraph(){
		for(int i = 0;i < V;i++){
			cout<<i<<" : ";
			vector<isPair>::iterator it;
			for(it = arr[i].begin();it != arr[i].end(); it++){
				cout<<"("<<(*it).first<<","<<(*it).second<<")   ";
			}
			cout<<endl;
		}
	}

	void dijkstra(int src){
		priority_queue< isPair , vector<isPair> , greater<isPair> > pq;

		vector<long long int> dist;
		for(int i = 0; i < V; i++){
			dist.push_back(inf);
		}
		dist[src] = 0;
		pq.push(make_pair(0,src));
		while(!pq.empty()){
			int u = pq.top().second;
			vector<isPair>::iterator it;
			for(it = arr[u].begin();it != arr[u].end(); it++){
				int v = (*it).first;
				int wt = (*it).second;
				if(dist[v] > dist[u] + wt){
					dist[v] = dist[u] + wt;
					pq.push(make_pair(dist[v],v));
				}
			}
			pq.pop();
		}
		for(int i  = 0; i < V; i++){
			cout<<i<<" : "<<dist[i]<<"\n";
		}
	}

	~Graph(){
		delete [] arr;
	}

};

int main(){
	Graph g(9);
	g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    int s;
    g.printGraph();
    cout<<"enter the source : ";
    cin>>s;
    g.dijkstra(s);

    return 0;
}