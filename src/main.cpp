#include <bits/stdc++.h>
#include "LinkedHashMap.hpp"
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0; string mode; if(!(cin>>mode)) return 0; bool byTime=(mode=="time");
    LinkedHashMap mp(n, byTime);
    int q; if(!(cin>>q)) return 0;
    for(int i=0;i<q;++i){
        string cmd; cin>>cmd;
        if(cmd=="insert"){ int k; string v; cin>>k>>v; mp.insert(k%mp.len,v); }
        else if(cmd=="remove"){ int k; string v; cin>>k>>v; mp.remove(k%mp.len,v); }
        else if(cmd=="ask"){ int k; cin>>k; auto a=mp.ask(k%mp.len); for(size_t j=0;j<a.size();++j){ if(j) cout<<' '; cout<<a[j]; } cout<<"\n"; }
        else if(cmd=="foreach"){ auto all=mp.forEach(); for(size_t j=0;j<all.size();++j){ if(j) cout<<' '; cout<<'('<<all[j].key<<','<<all[j].value<<')'; } cout<<"\n"; }
        else { string line; getline(cin,line); }
    }
    return 0;
}
