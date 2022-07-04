int atoi(string str) {
    int sign=1;
    int i=0;
    int ans=0;
    if(str[i]=='-'){
        sign=-1;
        i++;
    }
    for(;i<str.length();i++){
        if(str[i]-'0'>=0 && str[i]-'0'<=9){
            ans=ans*10+str[i]-'0';
        }
    }
    return ans*sign;
}
