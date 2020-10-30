#include<bits/stdc++.h>
using namespace std;
/*------------------------------------GRAPH CLASS------------------------------------------*/
class Graph{
	int V; 		//no of vertices
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int v,int w);
	void addEdgeUndirected(int u, int v);
	void printGraph(int V);
			//BFS
	void BFS(int s);
			//DFS
	void DFSUtil(int v, bool visited[]);
	void DFS(int v);
			//DFSIterative
	void DFSIterative(int s);
			//TopologicalSort
	void TopologicalSort();
	void TopologicalSortUtil(int v, bool visited[], stack<int> &Stack);
};

//Member Functions
/*------------------------------------CONSTRUCTOR------------------------------------------*/
			//Constructor
Graph::Graph(int V){
	this->V = V;
	adj=new list<int>[V];
}
/*------------------------------------EDGE ADDITION (DIRECTED)----------------------------------------*/
			//Edge addition for "Directed Graph"
void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}
/*------------------------------------EDGE ADDITION (UNDIRECTED)--------------------------------------*/
			//Edge addition for "Un-Directed Graph"
void Graph::addEdgeUndirected(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}
/*------------------------------------PRINTING-----------------------------------------------------*/
			//PrintGraph
void Graph::printGraph(int V){
	for(int v=0;v<V;v++){
		cout<<"\nAdj List of Vertex "<<v<<"\nHead ";
		for(auto x : adj[v])
			cout<<"->"<<x;
		printf("\n");
	}
}
/*------------------------------------BFS-----------------------------------------------------------*/
			//BFS implemented here
void Graph::BFS(int s){
	bool *visited = new bool[V]; //vector<bool> visited(V,false);
	for (int i = 0; i < V; ++i)
		visited[i] = false;
	
			//queue for BFS
	list<int> queue;
			//starting with s as the starting node
	visited[s]=true;
	queue.push_back(s);

	list<int>::iterator i;

	while(!queue.empty()){
		s=queue.front();
		cout<< s <<" ";
		queue.pop_front();

		for(i = adj[s].begin(); i!=adj[s].end();++i){
			if(!visited[*i]){
				visited[*i]=1;
				queue.push_back(*i);
			}
		}
	}
}
/*------------------------------------DFS Iterative approach--------------------------------------*/
//DFS Iterative approach
void Graph::DFSIterative(int s){
	vector<bool> visited(V,false);
	stack<int> stack;
	stack.push(s);

	list<int>::iterator i;

	while(!stack.empty()){
		s=stack.top();
		stack.pop();
		if(!visited[s]){
			cout<<s<<" ";
			visited[s]=1;
		}
		for(i=adj[s].begin(); i!=adj[s].end(); ++i)
			if(!visited[*i])
				stack.push(*i);
	}
}


/*------------------------------------DFS RECURSIVE approach--------------------------------------*/
			//DFS Implementation with Utility Function
void Graph::DFSUtil(int v, bool visited[]){
	visited[v] = true;
	cout<< v << " ";
	list<int>:: iterator i;
	
	// Recur for all the vertices adjacent to this vertex 
	for(i = adj[v].begin(); i!=adj[v].end();++i)
		if(!visited[*i])
			DFSUtil(*i, visited);
}
			//DFS Main Function
void Graph::DFS(int v){
	bool *visited = new bool[V];
	for (int i = 0; i < V; ++i)
		visited[i] = false;

	DFSUtil(v, visited);
}

/*------------------------------------TOPOLOGICAL SORT--------------------------------------*/
			//TopologicalSort Utility Function
void Graph::TopologicalSortUtil(int v,bool visited[],stack<int> &Stack){
	visited[v]=true;
	list<int>:: iterator i;
	
	for(i=adj[v].begin() ; i!=adj[v].end() ; i++)
		if(!visited[*i])
			TopologicalSortUtil(*i,visited,Stack);

	Stack.push(v);
}
			//Topological Sort MAIN
void Graph::TopologicalSort(){
	stack<int> Stack;

	bool *visited = new bool[V];
	for(int i=0 ; i<V;i++)
		visited[i]=false;

	for(int i=0;i<V;i++)
		if(visited[i]==false)
			TopologicalSortUtil(i,visited,Stack);

	while(Stack.empty()==false){
		cout<<Stack.top()<<" ";
		Stack.pop();
	}
}


/*------------------------------------Driver Code------------------------------------------*/
int main() 
{ 
    Graph g(5); 
    g.addEdgeUndirected(0, 1); 
    g.addEdgeUndirected(0, 2);
    g.addEdgeUndirected(0, 4);
     
    g.addEdgeUndirected(1, 2); 
    g.addEdgeUndirected(1, 4);
    
    //g.addEdge(2, 0); 
    g.addEdgeUndirected(2, 3); 
    g.addEdgeUndirected(3, 3);
    g.addEdgeUndirected(3, 4);
     
  	cout<<"\nPrintGraph\n";
  	g.printGraph(5);
    cout << "\nFollowing is Breadth First Traversal " << "(starting from vertex 2) \n"; 
    g.BFS(2); 
    cout << "\nFollowing is Depth First Traversal" << " (starting from vertex 2) \n"; 
    g.DFS(2); 
    cout << "\nFollowing is Iterative Depth First Traversal" << " (starting from vertex 2) \n"; 
    g.DFSIterative(2); 
	cout << "\nFollowing is a Topological Sort of the given graph \n"; 
    g.TopologicalSort(); 
  
    return 0; 
} 