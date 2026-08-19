#include<vector>
#include "csr_graph.h"
using namespace std;
void csrgraph(vector<edgelist>& edges,int v,int e,vector<int>& row_pointer,vector<int>& colIndex,vector<int>& weight)
{
    vector<int> degree(v,0);
    for(auto&edge : edges)
    {
        degree[edge.source]++;
    }
    row_pointer.resize(v+1,0);
    for(int i=0;i<v;i++)
    {
        row_pointer[i+1] = row_pointer[i] + degree[i];
    }
    vector<int> temp = row_pointer;
    colIndex.resize(e);
    weight.resize(e);
    for(auto&edge : edges)
    {
        int index=temp[edge.source]++;
        colIndex[index] = edge.destination;
        weight[index] = edge.weight;
    }

}