#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    // find nearest greater element to left and store its index, not value
    stack<int> ind;
    vector<int> ans;
    for(int i=0;i<price.size();i++){
        if(ind.size()==0)ans.push_back(1);
        else if(ind.size()>0 && price[ind.top()]>price[i])ans.push_back(1);
        else if(ind.size()>0 && price[ind.top()]<=price[i]){
            while (ind.size() && price[ind.top()] <= price[i]) {
                ind.pop();
            }
            if(ind.size()==0)ans.push_back(i+1);
            else ans.push_back(i-ind.top());
        }
        ind.push(i);
    }
    return ans;
}
