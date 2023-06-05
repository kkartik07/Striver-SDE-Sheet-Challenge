#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &nums)
{
    int cnt1=0,cnt2=0;
        int n=nums.size();
        long long el1=INT_MAX,el2=INT_MAX;

        for(int i=0;i<n;i++){
            if(cnt1==0 && el2!=nums[i]){
                el1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0 && el1!=nums[i]){
                el2=nums[i];
                cnt2=1;
            }
            else if(el1==nums[i])cnt1++;
            else if(el2==nums[i])cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;

        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1)cnt1++;
            if(nums[i]==el2)cnt2++;
        }
        if(cnt1>n/3)ans.push_back(el1);
        if(cnt2>n/3)ans.push_back(el2);
        return ans;
}