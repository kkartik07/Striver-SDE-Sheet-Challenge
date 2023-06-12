#include <bits/stdc++.h> 
bool comp(vector<int> j1,vector<int> j2){
    return j1[1]>j2[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(),jobs.end(),comp);
  
    int maxdead=jobs[0][0];
    for(int i=1;i<jobs.size();i++){
        if(jobs[i][0]>maxdead)maxdead=jobs[i][0];
    }
    vector<int> deadlines(maxdead+1,-1);
    int profit=jobs[0][1];
    deadlines[jobs[0][0]]=0;
    
    for(int i=1;i<jobs.size();i++){
        for(int j=jobs[i][0];j>=1;j--){
            if(deadlines[j]==-1){
                profit+=jobs[i][1];
                deadlines[j]=0;
                break;
            }
        }
    }
    return profit;
}
