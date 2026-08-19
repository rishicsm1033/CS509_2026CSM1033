#include"../src/kruskal.h"
#include<vector>
#include<algorithm>
using namespace std;
class DSU
{
    private:
    vector<int> parent;
    vector<int> rank;
    public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    int find(int x)
    {
        if(parent[x] != x)
        {
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int a,int b)
    {
        a=find(a);
        b=find(b);
        if(a == b)
        {
            return false;
        }
        if(rank[a] < rank[b])
        {
            parent[a]=b;
        }
        else if(rank[a] > rank[b])
        {
            parent[b]=a;
        }
        else
        {
            parent[b]=a;
            rank[a]++;
        }
        return true;
    }
};
void kruskal(int v,const vector<int> &row_pointer,const vector<int> &colIndex,const vector<int> &weight,vector<mstedge> &mst,int &totalweight)
{
    vector<mstedge> edges;
    for(int i=0;i<v;i++)
    {
        for(int j=row_pointer[i];j<row_pointer[i+1];j++)
        {
            int u=i;
            int dest=colIndex[j];
            int w=weight[j];
            if(u<dest)
            {
                edges.push_back({u,dest,w});
            }
        }
    }
    sort(edges.begin(),edges.end(),[](const mstedge &a,const mstedge &b)
    {
        return a.weight<b.weight;
    });
    DSU dsu(v);
    totalweight=0;
    mst.clear();
    for(const mstedge& edge : edges)
    {
        if(dsu.unite(edge.u,edge.v))
        {
            mst.push_back(edge);
            totalweight+=edge.weight;
        }
        if(mst.size() == v-1)
        {
            break;
        }
    }
}
