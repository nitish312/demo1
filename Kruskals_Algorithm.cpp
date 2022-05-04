// Kruskal's Algo for Minimum Spanning Tree
// Problem Statement: Given a weighted, undirected, 
// and connected graph of V vertices and E edges. 
// The task is to find the sum of weights of the 
// edges of the Minimum Spanning Tree.

// Definition: A minimum spanning tree consists 
// of N Nodes and N-1 edges connecting all the Nodes
// which have the minimum cost(sum of edge weights).

// Note: It is known as a tree since a tree doesn’t 
// have cycles involved. A graph with N Nodes and 
// N-1 edges is equivalent to a tree.

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int parent[N], sz[N];

void make(int v){
	parent[v] = v;
	sz[v] = 1;
}

int find(int v){
	if(parent[v] == v){
		return parent[v];
	}
	return parent[v] = find(parent[v]);
}

void unionThem(int a, int b){

	a = find(a);
	b = find(b);
	if(a != b){
		if(sz[a] < sz[b]){
			swap(a, b);
		}
		parent[b] = a;
		sz[a] += sz[b];
	}
}

int main(){

	int n = 5, m = 6; // n = no. of nodes , m = no. of edges 
	// vec of edges = 1st int : wt, 2nd : u, 3rd : v
	vector<pair<int, pair<int, int>>> edges;

	for(int i=0; i<m; i++){

		edges.push_back({2, {0, 1}});
		edges.push_back({6, {0, 3}});
		edges.push_back({3, {1, 2}});
		edges.push_back({8, {1, 3}});
		edges.push_back({5, {1, 4}});
		edges.push_back({7, {2, 4}});
	}

	sort(edges.begin(), edges.end());

	// need to call make function for all nodes
	for(int i=1; i<=n; i++){
		make(i);
	}

	int total_cost = 0;

	// now we can select edges having minimum wt
	// check if that mini wt edge can be selected or not
	for(auto &edge : edges){
		
		int wt = edge.first;
		int u = edge.second.first, v = edge.second.second;
		
		if(find(u) == find(v)) continue;
		unionThem(u, v);

		cout<<u<<" "<<v<<" "<<wt<<endl;

		total_cost += wt;
	}

	cout<<"Total Cost = "<<total_cost;

	return 0;
}