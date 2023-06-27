#include <bits/stdc++.h> 

void func(string &s, int index, vector<string> &ans)
{
    if (index == s.length())
    {
        ans.push_back(s);
        return;
    }

    for (int i = index; i < s.length(); i++)
    {
        swap(s[i],s[index]);
        func(s, index + 1 , ans);
        swap(s[i],s[index]);
    }

    // a.push_back(s[index]);
    //     func(s, index + 1, a, ans);
    //     a.pop_back();
}

vector<string> findPermutations(string &s) {
    // Write your code here.
     vector<string> ans;
    func(s, 0, ans);
    return ans;
}