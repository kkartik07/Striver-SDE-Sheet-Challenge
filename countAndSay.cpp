#include <bits/stdc++.h>
string rec(string &cur,int n)
{
	if (n==1) return cur;
	string ans="";
	char ele=cur[0];
	int cnt=1;
	for (int i=1;i<cur.size();i++)
	{
		while(i<cur.size() && cur[i]==ele)
		{
          cnt++;
		  i++;
		}
		if (i==cur.size()) break;
        ans+=to_string(cnt)+ele;
		ele=cur[i];
		cnt=1;
	}
	ans+=to_string(cnt)+ele;
	return rec(ans,n-1);
}
string writeAsYouSpeak(int n) 
{
	string cur="1";
	return rec(cur,n);
}
