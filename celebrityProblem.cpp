#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	stack<int> s;
	for(int i=0;i<n;i++)s.push(i);

	while(s.size()>1){
		int one=s.top();
		s.pop();
		int two=s.top();
		s.pop();
		if(knows(one,two))s.push(two);
		else s.push(one);
	}
	if(s.size()==0)return -1;
	else {
		int potCel=s.top();
		for(int i=0;i<n;i++){
			if(i==potCel)continue;
			if(knows(potCel,i) || !knows(i,potCel))return -1;
		}
		return potCel;
	}
}