#include<iostream>
#include<vector>
#include "csr_graph.h"
#include<chrono>

using namespace std;

int main()
{
    int v,e;
    cout<<"enter number of vertices "<<endl;
    cin >> v;
    cout << "enter the number of edges"<<endl;
    cin >> e;
    vector<edgelist> edge(e);
    for(int i=0;i<e;i++)
    {
        cin>>edge[i].source>>edge[i].destination>>edge[i].weight;
    }

    auto start = chrono::high_resolution_clock::now();
    csrgraph(edge,v,e);
    auto end = chrono::high_resolution_clock::now();
    double time = chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0;
    cout<<endl;
    
    cout<<"||  Runtime Complexity : "<<time<<"ms.||";cout<<endl;
    
    return 0;

}