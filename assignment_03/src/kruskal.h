#ifndef KRUSKAL_H
#define KRUSKAL_H
#include<vector>
struct mstedge
{
    int u;
    int v;
    int weight;
};
void kruskal
(
    int v,
    const std::vector<int> &row_pointer,
    const std::vector<int> &colIndex,
    const std::vector<int> &weight,
    std::vector<mstedge> &mst,
    int &totalweight
);
#endif