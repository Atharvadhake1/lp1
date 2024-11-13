#include <bits/stdc++.h>
using namespace std;

int fractionalknapsack(vector<int> wt ,vector<int> val, int W , int n);

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


    ans = fractionalknapsack(weight,values,W,len);
    cout<<endl<<"maximum value is "<<ans<<endl;

    return 0;

    }
}

int fractionalknapsack(vector<int> wt ,vector<int> val, int W , int n){
    vector<int> ratio(n);
    for(int i =0 ; i< n; i++){
        ratio[i] = val[i]/wt[i];
    }
    sort(ratio.begin(),ratio.end(), greater<int>());

    int value =0;
    int capacity =0;
    for(int i =0 ; i< n; i++){
        if(capacity + wt[i] <=W){
            capacity += wt[i];
            value += val[i];
        }
        else{
            int temp = W-capacity;
            int x = temp * ratio[i];
            value += x;
        }
    }
    return value;
}
