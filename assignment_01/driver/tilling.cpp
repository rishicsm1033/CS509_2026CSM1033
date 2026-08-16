#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> tillingmethod(const vector<vector<int>> &mat1,const vector<vector<int>> &mat2,int M,int K,int N,int B)
{
    vector<vector<int>> result(M,vector<int>(N,0));
    int i,j,k,i1,j1,k1;

    for(i1=0;i1<M;i1+=B)
	{
        for(j1=0;j1<N;j1+=B)
		{
            for(k1=0;k1<K;k1+=B)
			{
               for(i=i1;i<min(M,i1+B);i++)
			   {
				for(j=j1;j<min(N,j1+B);j++)
				{
					for(k=k1;k<min(K,k1+B);k++)
					{
						result[i][j]+=mat1[i][k] * mat2[k][j];
					}
				}
			   }
            }
        }
    }
    return result;
}
