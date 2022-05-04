// Prim's Algo for Minimum Spanning Tree
// Problem Statement: Given a weighted, undirected, 
// and connected graph of V vertices and E edges. 
// The task is to find the sum of weights of the 
// edges of the Minimum Spanning Tree.

// Approach - 3 Arrays
// Key : This array holds the weight/ cost of the MST(intialized to INT_MAX except the index 0 which is set with value of zero)
// MST : This is a boolean array which indicates whether a node is already a part of MST or not(initialized to false except the index 0 which is true)
// Parent :  This indicates the parent of a particular node in the MST(initialized to -1)

#include<bits/stdc++.h>
using namespace std;

int main(){

    int N = 5, m = 6;

    vector<pair<int, int>> adj[N]; 

    adj[0].push_back({1,2}); //
    adj[0].push_back({3,6}); //
    adj[1].push_back({0,2});
    adj[1].push_back({2,3}); //
    adj[1].push_back({3,8});
    adj[1].push_back({4,5}); //
    adj[2].push_back({1,3});
    adj[2].push_back({4,7});
    adj[3].push_back({0,6});
    adj[3].push_back({1,8});
    adj[4].push_back({1,5});
    adj[4].push_back({2,7});

    int key[N];
    bool mstSet[N]; 
    int parent[N];
  
    for(int i=0; i<N; i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    } 
         
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});

    int total_cost = 0;

    while(!pq.empty()){ 

        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true;
        
        for(auto it: adj[u]){

            int v = it.first;
            int wt = it.second;
            
            if(mstSet[v] == false && wt < key[v]){

                parent[v] = u;
                key[v] = wt; 
                pq.push({key[v], v});   
                cout<<parent[v]<<" "<<v<<" "<<wt<<endl; 
                total_cost += wt;
            }
        }      
    } 
    cout<<"Total Cost = "<<total_cost;

    return 0;
}