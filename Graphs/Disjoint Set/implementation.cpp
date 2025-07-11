#include <bits/stdc++.h>
using namespace std;


class DisjoinSet{
    vector<int> rank,parent;
public: 
    DisjoinSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findparent(int u){
        if(u == parent[u]){
            return u;
        }
        return parent[u] = findparent(parent[u]);
    }
    void unionbyrank(int u,int v){
        int pu = findparent(u);
        int pv = findparent(v);
        if(pu == pv)return;
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }else if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

int main(){
    DisjoinSet ds(7);
    ds.unionbyrank(1,2);
    ds.unionbyrank(2,3);
    ds.unionbyrank(4,5);
    ds.unionbyrank(6,7);
    // if 5 and 6 belong to same comp or not
    if(ds.findparent(5) == ds.findparent(6)){
        cout<<"same"<<endl;
    }else{
        cout<<"different"<<endl;
    }
    ds.unionbyrank(5,6);
    if(ds.findparent(5) == ds.findparent(6)){
        cout<<"same"<<endl;
    }else{
        cout<<"different"<<endl;
    }
    return 0;
}