int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    int platform[2361]={0};
    int required=1;
    for(int i=0;i<n;i++){
        ++platform[at[i]];
        --platform[dt[i]+1];
    }
    for(int i=0;i<2361;i++){
        platform[i]=platform[i]+platform[i-1];
        required=max(required,platform[i]);
    }
    return required;
}
