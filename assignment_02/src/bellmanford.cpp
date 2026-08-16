#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
const int INF = 1e9;
void bellmanford(vector<int>& vertex,vector<int> &child,vector<int> &weight,int v,int e,int source);
void adjListTocsr(vector<vector<pair<int,int>>>& adjList,vector<int>& vertex,vector<int>& child,vector<int>& weight,int v)
{
    int i=0,j=0;
    for(i=0;i<v;i++)
    {
        vertex[i] = j;
        for(auto edge : adjList[i])
        {
            child[j] = edge.first;
            weight[j] = edge.second;
            j+=1;
        }
    }
    vertex[i] = j;

}
/*
        vector<int> distance(V,INT_MAX);
        vector<int> parent(V,-1);
        distance[source]=0;
        for(int k=1;k<V;k++)
        {
            for(int u=0;u<V;u++)
            {
                for(int j= row_pointer[u];j<row_pointer[u+1];j++)
                {
                    int v=column_index[j];
                    int w=weight[j];
                    if(distance[u] != INT_MAX && distance[v] > distance[u] + w)
                    {
                        distance[v]=distance[u]+w;
                        parent[v]=u;
                    }
                }
            }
        }
        
        for(int u=0;u<V;u++)
            {
                for(int j= row_pointer[u];j<row_pointer[u+1];j++)
                {
                    int v=column_index[j];
                    int w=weight[j];
                    if(distance[u] != INT_MAX && distance[v] > distance[u] + w)
                    {
                        break;
                    }
                }
            }

        for(int i=0;i<V;i++)
        {
            if(distance[i]==INT_MAX)
            {
                cout<<"edge not exists";
            }
            else
            {
                cout<<distance[i];
            }
        cout<<endl;
        }

    }
*/
int main()
{
    int v;
    cout<<"enter the no of vertices";
    cin>>v;
    int e;
    cout<<"Enter the no.of edges : ";
    cin>>e;
    vector<vector<pair<int,int>>> adjList(v);
    for(int i=0;i<e;i++)
    {
    int src,dest,w;
    cin>>src>>dest>>w;
    adjList[src].push_back({dest,w});   
    }
    vector<int> vertex(v+1,0);
    vector<int> child(e,0);
    vector<int> weight(e,0);
    adjListTocsr(adjList,vertex,child,weight,v);
    auto start = chrono::high_resolution_clock::now();
    bellmanford(vertex,child,weight,v,e,0);
    auto end = chrono::high_resolution_clock::now();
    double time = chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0;
    cout<<endl;
   /* cout << "\nCSR Representation\n";
    cout << "rowptr";
    for (int i = 0; i <= v; i++) 
    {
        cout << vertex[i] << " ";
    }
    cout << "\ncolindex";
    for (int i = 0; i < e; i++) {
        cout << child[i] << " ";
    }
    cout << "\nWeight";
    for(int i = 0; i < e; i++) 
    {
        cout << weight[i] << " ";
    }
    */
    cout << endl;
    cout<<"||  Runtime Complexity : "<<time<<"ms.      ||";cout<<endl;
}