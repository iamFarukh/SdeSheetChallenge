#include<bits/stdc++.h>
//creating a structure
struct meeting{
    int start;
    int end;
    int pos;
};
bool comparator(struct meeting m1,meeting m2){
    if(m1.end<m2.end) return true;
    else if(m1.end>m2.end) return false;
    else if(m1.pos<m2.pos) return true;
    else return false;
}
vector<int> maximumMeetings(vector<int> &s, vector<int> &e) {
    // Write your code here.
    int n=s.size();
    struct meeting meet[n];
    for(int i=0;i<n;i++){
        meet[i].start=s[i],meet[i].end=e[i],meet[i].pos=i+1;
    }
    sort(meet,meet+n,comparator);
    vector<int> ans;
    int ending=meet[0].end;
    //first meeting toh hoge hee hogii
    ans.push_back(meet[0].pos);
    //last mai humhe positions chhaiye bss
    for(int i=1;i<n;i++){
        if(meet[i].start>ending){
            ending=meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }
    return ans;
}
