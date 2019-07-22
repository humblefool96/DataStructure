//implementation of djikstra using adjacency matrix

#include<iostream>
using namespace std;

int findMinVertex(bool *vis, int *dis, int nodes){
	int minVertex = -1;
	for(int i=0;i<nodes;i++){
		if(!vis[i] && (minVertex == -1 || dis[i] < dis[minVertex] )){
			minVertex = i;
		}
	}
	return minVertex;
}

void Display(int *dis, int nodes){
	for(int i=0;i<nodes; i++){
		cout<<i<<"   "<<dis[i]<<"\n";
	}
}

void Djikstra(int src, int nodes, int **mat){
	bool* vis = new bool[nodes];
	int* dis = new int[nodes];
	//intializing the visited and distance array
	for(int i=0;i<nodes;i++){
		vis[i] = false;
		dis[i] = INT_MAX;
	}
	dis[src] = 0;
	
	for(int i=0;i<nodes-1;i++){
		int minVertex = findMinVertex(vis, dis, nodes);
		vis[minVertex] = true;
		for(int j=0;j<nodes;j++){
			if(mat[minVertex][j] != 0 && !vis[j]){
				int dist = dis[minVertex] + mat[minVertex][j];
				if(dis[j] > dist)
					dis[j] = dist;
			}
		}
	}
	
	Display(dis, nodes);
}

int main(){
	int nodes, edges;
	cin>>nodes>>edges;
	
	int **mat = new int*[nodes];
	//intializing the mat with 0
	for(int i=0;i<nodes;i++){
		mat[i] = new int[nodes];
		for(int j=0;j<nodes;j++){
			mat[i][j] = 0;
		}
	}
	int x, y, z;
	for(int i=0;i<edges;i++){
		cin>>x>>y>>z;
		mat[x][y] = z;
	}
	int src;
	cout<<"enter the sourec element"<<"\n";
	cin>>src;
	Djikstra(src, nodes, mat);
	
	return 0;
}
