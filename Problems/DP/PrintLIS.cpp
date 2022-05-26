
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <string>
using namespace std;

int main() {
    int n = 10 ;
    vector<int> arr = {10,22,9,33,21,50,41,60,80,1};
   
    vector<int> dp(n,0);
    dp[0] = 1;
    int omax = 0;    
    int index = -1;
    
    for(int i = 1 ; i < n ; i++) {
        int max = 0;
        for(int j = 0 ; j < i ; j++) {
            if(arr[i] > arr[j]) {
                if(max < dp[j]) {
                    max = dp[j];
                }
            }
        }
        dp[i] = max+1;
        if(omax < dp[i]) {
            omax = dp[i];
            index = i;
        }
    }
    
    if(omax == 0) {
        omax += 1;
        index = 0;
    }
    
    cout<<omax<<endl;
    queue<pair<int,string>> myqueue;
    myqueue.push(make_pair(index,to_string(arr[index])));
    
    while(!myqueue.empty()) {
        pair<int,string> temp = myqueue.front();
        int i = temp.first;
        string val = temp.second;
        int value = dp[i] - 1;
        myqueue.pop();
        
        if(i == 0) {
            cout<<val<<endl;
            continue;
        }
        
        for(int pq = 0 ; pq < i ; pq++) {
            if(dp[pq] == value) {
                myqueue.push(make_pair(pq, to_string(arr[pq]) + " " +val));    
            }    
        }
        
    }
    
    
    return 0;
}