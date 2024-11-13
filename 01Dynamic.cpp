#include <bits/stdc++.h>
using namespace std;

int zerooneknapsack(vector<int> wt ,vector<int> val, int W , int n);

int main(){
    int n , len, W, ans;

    while(1){
    cout<<"Enter the length of array:";
    cin>>len;

    vector<int> values(len);
    vector<int> weight(len);


    cout<<"Enter the values:";
    for(int i =0 ; i< len; i++){
        cin>>values[i];
    }

    cout<<"Enter the weight: ";
    for(int i =0 ; i< len; i++){
        cin>>weight[i];
    }

    cout<<"Enter the capacity of the bag: ";
    cin>>W;


    ans = zerooneknapsack(weight,values,W,len);
    cout<<endl<<"maximum value is "<<ans<<endl;

    return 0;

    }
}

int zerooneknapsack(vector<int> wt ,vector<int> val, int W , int n){
    if(n ==0){
        if(W-wt[0] >=0){
            return val[0];
        }
        else{
            return 0;
        }
    }
    int include = 0;
    if(W-wt[n] >=0){
        include = val[n] + zerooneknapsack(wt, val, W-wt[n], n-1);
    }
    
    int exclude = 0 + zerooneknapsack(wt, val,W, n-1); 
     
    return max(include, exclude);
}
