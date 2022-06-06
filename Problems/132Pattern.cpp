// Return true if there is a 132 pattern in nums, otherwise, return false.

#include<iostream>
#include<stack>
using namespace std;

bool pattern(int arr[], int n){
    int s3 = INT_MIN;
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        if(arr[i] < s3){
            return true;
        }else{
            while(!st.empty() && arr[i] > st.top()){
                s3 = st.top();
                st.pop();
            }
        }
        st.push(arr[i]);
    }
    return false;
}





int main(){
    int arr[] = {1,3,4,2,8};
    int n = 5;
    if(pattern(arr,n)){
        cout<<"Yes" <<endl;

    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}