#include<iostream>
#include<vector>
#include "../src/csr_graph.h"
using namespace std;
void csrgraph(vector<edgelist>& edges,int v,int e)
{
    vector<int> degree(v,0);
    for(auto& edge_row:edges)
    {
        degree[edge_row.source]+=1;
    }

    vector<int> row_pointer(v+1,0);
    for(int i=0;i<v;i++)
    {
        row_pointer[i+1]=row_pointer[i]+degree[i];
    }
    vector<int> t=row_pointer;
    vector<int> colIndex(edges.size());
    vector<int> weight(edges.size());
    for(auto& edge:edges)
    {
        int dest_index=t[edge.source]++;
        colIndex[dest_index]=edge.destination;
        weight[dest_index]=edge.weight;
    }
    
    for(int i=0;i<v;i++)
    {
        cout<<row_pointer[i]<<" ";   
    }
    cout<<endl;
    for(int i=0;i<e;i++)
    {
        cout<<colIndex[i]<<" ";  
    }
    cout<<endl;
    for(int i=0;i<e;i++)
    {
        cout<<weight[i]<<" ";   
    }
    cout<<endl;
    return;


}