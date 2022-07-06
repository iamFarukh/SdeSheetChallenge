#include <bits/stdc++.h>
bool areAnagram(string &str1, string &str2){
    
    //if they are not in same length dont need to check further  
    if (str1.length() != str2.length())
        return false;
        
    //initialize both vectors (treated as map)
    vector <int> s1(26, 0);
    vector <int> s2(26, 0);
    
    //count frequency 
    for (int i = 0 ; i < str1.length(); i++){
        
        s1[str1[i] - 'a']++;
        s2[str2[i] - 'a']++;
        
    }
    
    // checke if found unrqual count
    for (int i = 0; i< str1.length(); i++){
        
        if (s1[i] != s2[i])
            return false;
    }
    
    return true;
}
