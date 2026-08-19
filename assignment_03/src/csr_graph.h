#ifndef CSR_GRAPH_H
#define CSR_GRAPH_H

#include<vector>

struct edgelist
{
    int source;
    int destination;
    int weight;
};

void csrgraph(std::vector<edgelist>& edges,int v,int e,std::vector<int>& row_pointer,std::vector<int>& colIndex,std::vector<int>& weight);
#endif