#include<algorithm>

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    
    vector<pair<int,int>> activities;
    for(int i=0;i<start.size();i++){
        activities.push_back({finish[i], start[i]}); 
    }
    sort(activities.begin(), activities.end());  //sort on finishing based
    int result=1, j = 0;
    for(int i=1;i<activities.size();i++){
        if(activities[i].second >= activities[j].first){
           result++;
           j=i;
        }
    }
    return result;
}
