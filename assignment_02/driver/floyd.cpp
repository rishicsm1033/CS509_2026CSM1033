#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> apsp(vector<vector<int>> &A,int v)
{
    for(int k=0;k<v;k++)
    {
    for(int i=0;i<v;i++)
        {
        for(int j=0;j<v;j++)
            {
                A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
            }
        
        }
    }
    return A;
}