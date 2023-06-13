#include <bits/stdc++.h> 
// Stack class.
class Stack {
private:
    int* arr;
    int t;
    int cap;
    int cnt;
public:
    Stack(int capacity) {
        // Write your code here.
        arr=new int[capacity];
        cap=capacity;
        cnt=0;
        t=-1;
    }

    void push(int num) {
        // Write your code here.
        if(cnt==cap)return;
        arr[++t]=num;
        cnt++;
    }

    int pop() {
        // Write your code here.
        if(cnt==0)return -1;
        cnt--;
        return arr[t--];
    }
    
    int top() {
        // Write your code here.
        if(t==-1)return -1;
        return arr[t];
    }
    
    int isEmpty() {
        // Write your code here.
        if(t==-1)return 1;
        return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(t==cap-1)return 1;
        return 0;
    }
    
};