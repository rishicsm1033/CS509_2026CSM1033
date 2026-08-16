#include<bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> apsp(vector<vector<int>> &costmatrix,int v);
int main()
{
    int v,i,j,k;
    cout<<"enter the number of vertices"<<endl;
    cin>>v;
    vector<vector<int>> costmatrix(v, vector<int> (v));
    cout<<"enter the cost matrix"<<endl;
    for(i=0;i<v;i++)
    {
       for(j=0;j<v;j++)
        {
                cin>>costmatrix[i][j];
        } 
        cout<<endl;
    }
    vector<vector<int>> shortestpath(v, vector<int> (v));

    auto start = chrono::high_resolution_clock::now();
    shortestpath=apsp(costmatrix,v);
    auto end = chrono::high_resolution_clock::now();
    double time = chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0;
    cout<<endl;

    /*for(i=0;i<v;i++)
    {
       for(j=0;j<v;j++)
        {
                cout<<shortestpath[i][j]<<" ";
        } 
        cout<<endl;
    }
   */

    
    cout<<endl;
    cout<<"||  Runtime Complexity : "<<time<<"ms.      ||";cout<<endl;
   
}