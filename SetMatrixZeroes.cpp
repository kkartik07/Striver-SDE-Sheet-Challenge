#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	vector<int> rows(matrix.size(),-1);
	vector<int> cols(matrix[0].size(),-1);

	int row=matrix.size(),col=matrix[0].size();
	for(int i=0;i<row;i++){
          for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 0)
             {
				rows[i] = 0;
           		cols[j] = 0;
          	 }
           }
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(rows[i]==0 || cols[j]==0)matrix[i][j]=0;
		}
	}
	
}