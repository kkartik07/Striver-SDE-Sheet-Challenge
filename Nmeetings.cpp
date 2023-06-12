#include <bits/stdc++.h> 

bool comp(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b){
    if(a.first.second<b.first.second)return true;
    else if(a.first.second > b.first.second)return false;
    else if(a.second<b.second)return true;
    return false;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector <pair<pair<int,int>,int>> v;
    for(int i=0;i<start.size();i++){
        v.push_back({{start[i],end[i]},i+1});
    }
    sort(v.begin(),v.end(),comp);
   
    vector<int> ans;
    int lastMeet=0;

    ans.push_back(v[0].second);
    lastMeet=v[0].first.second;

    for(int i=1;i<start.size();i++){
        if(v[i].first.first>lastMeet){
            ans.push_back(v[i].second);
            lastMeet=v[i].first.second;
        }
    }
    return ans;
}