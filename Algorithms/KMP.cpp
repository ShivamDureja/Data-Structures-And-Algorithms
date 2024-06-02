// Knuth-Morris-Pratt Algorithm - To find pattern in a given string in Linear Time Complexity
// 1. First compute LPS array - Longest Prefix suffix
// 2. Perform Algorithm

// Steps to compute LPS array
// 1. Take variable len to keep track of length of longest prefix suffix.
// 2. if pat[len] == pat[i], then len++ and assign incremented value to lps[i].
// 3. if pat[i] != pat[len] and len > 0, then len = lps[len - 1]

# include<vector>
# include <iostream>
using namespace std;

    vector<int> computeLPS(string &pat){
        int len = 0;
        int m = pat.length();
        vector<int> lps(m,-1);
        lps[0] = 0;
        int i = 1;
        while(i < m){
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0){
                    len = lps[len - 1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    vector<int> KMP(string &s, string &pat, vector<int> &LPSarray){
       // cout<<"going"<<endl;
        int n = s.length();
        int m = pat.length();
        vector<int> res;
        int i = 0;
        int j = 0;
        while(i < n){
            if(pat[j] == s[i]){
                j++;
                i++;
            }
            if(j == m){
                res.push_back(i - j);
               // cout<<"going"<<endl;
                j = LPSarray[j-1];
            }
            else if(i < n && pat[j] != s[i]){
                if(j != 0){
                    j = LPSarray[j-1];
                }else{
                    i++;
                }
            }
        }
        return res;

    }


int main(){
    string pat = "AAACAAAA";
    string s = "AAACAAAACAAACAAAAC";
    
    vector<int> LPSarray(pat.length(),-1);
    LPSarray = computeLPS(pat);
    // cout<<"LPS array => "<<endl;
    // for(auto it : LPSarray){
    //     cout<<it<<endl;
    // }
    vector<int> ans(5,-1);
    ans = KMP(s,pat,LPSarray);
    cout<<"ans =>"<<endl;
    for(auto it : ans){
        cout<<it<<endl;
    }
    return 0;
}