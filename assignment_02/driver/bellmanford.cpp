#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;
void bellmanford(vector<int>& vertex,vector<int>& child,vector<int>& weight,int v,int e,int source)
{
    vector<int> distance(v,INF);
    distance[source]=0;
    vector<int> parent(v,-1);
    for(int k=0;k<v-1;k++)
    {
        for(int i=0;i<v;i++)
        {
            if(distance[i] == INF)
                continue;
            for(int j=vertex[i];j<vertex[i+1];j++)
            {
                int dest = child[j];
                int w = weight[j];
                if(distance[i]+w <distance[dest])
                {
                    distance[dest] = distance[i] + w;
                    parent[dest] = i;
                }
            }
        }
    }
    bool flag = false;
    for(int i=0;i<v;i++){
        if(distance[i]==INF) continue;
        for(int j=vertex[i];j<vertex[i+1];j++){
            int dest = child[j];
            int w = weight[j];
            if(distance[i]+w < distance[dest]){
                flag = true;
                break;
            }           
        }
        if(flag) break;       
    }
    if(flag){
        cout<<"Negative cycle.";
        cout<<endl;
        return;
    }
    cout << "\nShortest Paths from Source " << source << "\n";
   /* for (int i = 0; i < v; i++) {
        cout  << i <<" " ;
        if (distance[i] == INF) {
            cout << "No Path Exists\n";
        } else {
            cout << distance[i] <<endl ; 
        }
    }
        */
}