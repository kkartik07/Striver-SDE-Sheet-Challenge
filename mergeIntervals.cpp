#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<int> start;
    vector<int> fin;
    vector<vector<int>> mergedInt;
    int n_start = intervals.size();
    for(int i = 0 ; i < n_start ; i++){
        start.push_back(intervals[i][0]);
        fin.push_back(intervals[i][1]);
    }
    sort(start.begin() , start.end());
    sort(fin.begin() , fin.end());
    int mini = start[0];
    int maxi = fin[0];
    int last = 0;
    if(n_start == 1){
        mergedInt.push_back({mini,maxi});    
    }
    for(int i = 0 ; i < n_start-1 ; i++){
        mini = min(start[i],mini);
        maxi = max(fin[i],maxi);
        if(fin[i] >= start[i+1]){
            maxi = fin[i+1];
            if(i == n_start-2){
                maxi = max(fin[i+1],maxi);
                mergedInt.push_back({mini,maxi});           
            }
        }
        else{
            mergedInt.push_back({mini,maxi});
            mini = start[i+1];
            if(i == n_start-2){
                maxi = max(fin[i+1],maxi);
                mergedInt.push_back({mini,maxi});           
            }
        }
    }
    return mergedInt;    
}
