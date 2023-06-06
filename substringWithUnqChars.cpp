#include <bits/stdc++.h> 
int uniqueSubstrings(string input)

{
    int i=0,j=0;
    int n=input.size();
    int len=1;
    unordered_map<char,int> st;
    while(j<n && i<n){
        if(st.find(input[j])!=st.end()){
            st.erase(input[i]);
            i++;
        }
        else {
            st[input[j]]=1;
            len=max(len,j-i+1);
            j++;
        }
    }
    return len;
}