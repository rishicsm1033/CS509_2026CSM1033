#ifndef PRIMS_H
#define PRIMS_H
#include<vector>
struct mstedge
{
    int source;
    int destination;
    int weight;
};
void prim
(
    int v,
    const std::vector<int> &row_pointer,
    const std::vector<int> &colIndex,
    const std::vector<int> &weight,
    std::vector<mstedge> &mst,
    int &totalweight
);


#endif