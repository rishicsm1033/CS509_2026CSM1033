#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> matrixmultiply(const vector<vector<int>> &mat1,const vector<vector<int>> &mat2,int M,int K,int N);
int main() {
    int r1,c1,i,j,k,r2,c2;
	cout << "enter the number of rows and columns of  matrix1" << endl ;
	cin >> r1 >> c1  ;
	vector<vector<int>> matrix1(r1,vector<int> (c1));
	cout << "enter the  elements of matrix 1" << endl;
	for (i=0;i<r1;i++)
	{
	    for(j=0;j<c1;j++)
	    {
	        cin >> matrix1[i][j] ;
	    }
	    cout << endl;
	}
	cout << "enter the number of rows and columns of matrix 2" << endl;
	cin >> r2>>c2;
	vector<vector<int>> matrix2(r2,vector<int> (c2));
	cout << " enter the elements of matrix 2" << endl;
    for (i=0;i<r2;i++)
	{
	    for(j=0;j<c2;j++)
	    {
	        cin >> matrix2[i][j] ;
	    }
	    cout << endl;
	}
	
	if (c1!=r2)
	{
	    cout << "multiplication of matrix cannot be performed ";
	    return 1;
	}
	vector<vector<int>> resultmatrix(r1,vector<int> (c2));
	auto start = chrono::high_resolution_clock::now(); 
	resultmatrix=matrixmultiply(matrix1,matrix2,r1,c1,c2);
	auto end = chrono::high_resolution_clock::now();
	cout << " the resultant matrix is"<< endl;
	for (i=0;i<r1;i++)
	/*{
	    for(j=0;j<c2;j++)
	    {
	        cout << resultmatrix[i][j] << " " ;
	    }
	    cout << endl;
	}
	*/
	double time = chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0;
    cout<<endl;
    cout<<"||  Runtime Complexity : "<<time<<"ms.      ||";cout<<endl;
    return 0;
	
}