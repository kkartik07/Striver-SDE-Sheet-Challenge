#include<bits/stdc++.h>
void bfs(int **arr,int i,int j,vector<vector<int>> &vis,int n, int m){
   vis[i][j]=1;
   queue<pair<int,int>> q;
   q.push({i,j});

   while(!q.empty()){
      int row=q.front().first;
      int col=q.front().second;
      q.pop();

      for(int delrow=-1;delrow<=1;delrow++){
         for(int delcol=-1;delcol<=1;delcol++){
            int drow=row+delrow;
            int dcol=col+delcol;
            if(drow>=0 && drow<n && dcol>=0 && dcol<m && arr[drow][dcol]==1 && !vis[drow][dcol]){
               vis[drow][dcol]=1;
               q.push({drow,dcol});
            }
         }
      }
   }
}
int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   vector<vector<int>> vis(n,vector<int>(m,0));
   int cnt=0;
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(!vis[i][j] && arr[i][j]==1){
            vis[i][j]=1;
            cnt++;
            bfs(arr,i,j,vis,n,m);
         }
      }
   }
   return cnt;

}
