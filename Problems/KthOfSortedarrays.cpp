// Binary Search approach
//Time Complexity: O(log(min(n,m)))
class Solution{
    public: 
        int kthOfSortedarrays(int arr1[],int arr2[],int n,int m,int k){
            if(n>m){
                return kthOfSortedarrays(arr2,arr1,m,n,k);
            }
            int low = max(0,k-m);
            int high = min(k,n);
            while(low<=high){
                int cut1 = (low+high) >> 1;
                int cut2 = k-cut1;
                int l1 = cut1 == 0 ? INT_MIN : arr[cut1-1];
                int r1 = cut1 == n ? INT_MAX : arr[cut1];
                int l2 = cut2 == 0 ? INT_MIN : arr[cut2-1];
                int r2 = cut2 == m ? INT_MAX : arr[cut2];

                //valid condth
                if(l1<=r2 && l2 <= r1){
                    max(l1,l2);
                }
                else if(l1>r2){
                    high = cut1-1;
                }else{
                    low = cut1+1;
                }
            }
            return 1;
        }
};