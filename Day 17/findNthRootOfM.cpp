double findNthRootOfM(int n, long long m) {
    // Write your code here.
    double t=1.000000/n;
    double ans=pow(m,t);
    return ans;
}


// Here is one more method to do the same
// using the binary search method
double multiply(double mid, int n){
    double ans = 1.0;
    while(n--){
        ans *= mid;
    }
    return ans;
}

double findNthRootOfM(int n, long long m) {
    // Write your code here.
     double low = 1;
    double high = m;
    double eps = 1e-;
    
    while((high-low)>eps){
        double mid = (low + high)/2;
        if(multiply(mid,n) < m){
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return low;
}
