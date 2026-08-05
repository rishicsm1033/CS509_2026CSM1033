#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> matrixmultiply(const vector<vector<int>> &mat1,const vector<vector<int>> &mat2,int M,int K,int N)
{
    vector<vector<int>> result(M,vector<int>(N,0));
    
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<K;k++){
                result[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    return result;
}