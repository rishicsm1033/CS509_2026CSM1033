#include<iostream>
#include<chrono>
#include<fstream>
#include<vector>
#include "csr_graph.h"
#include"../src/kruskal.h"
using namespace std;
int main()
{
    int v,e;
    cout<<"enter the number of vertices";
    cin>>v;
    cout<<"enter the number of edges";
    cin>>e;
    vector<edgelist> edges;
    for(int i=0;i<v;i++)
    {
        int s,degree,destination,weight;
        cin>>s>>degree;
        for(int j=0;j<degree;j++)
        {
            cin>>destination>>weight;
            edges.push_back({s,destination,weight});
        }
    }
    vector<int> row_pointer;
    vector<int> colIndex;
    vector<int> weight;
    csrgraph(edges,v,edges.size(),row_pointer,colIndex,weight);
    vector<mstedge> mst;

    int totalweight=0;

    auto start=chrono::high_resolution_clock::now();

    kruskal(v,row_pointer,colIndex,weight,mst,totalweight);

    auto end=chrono::high_resolution_clock::now();
    
    double time = chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0;

    cout<<"the mst is" <<endl;
    // for(auto &edge:mst)
    // {
    //     cout<<edge.source<<" "<<edge.destination<<" "<<edge.weight<<endl;
    // }
    cout<<"the cost of mst is"<<":"<<totalweight<<endl;
    cout<<"the execution time is "<<":"<<time<<"ms"<<endl;
}