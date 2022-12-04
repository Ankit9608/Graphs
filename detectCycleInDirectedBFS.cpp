//By using the previous Kahn's algorithm we just check whether it having cycle or not
// clue the graph is acylic if the toposort is possible that is why we are using this logical in reverse way/
//First we try to form a topological sort of a given graph if the graph is acylic then the element in the
// topological order is equal to the initial given graph and if cycle is present then this number will increasse
// if the number of elements in topological sort is greater than the number of elements in given graph it means
/// cycle is present
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
}
int main(){
int n;cin>>n;
vector<int>adj[n+1];
addedge(adj,)
}