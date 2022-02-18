#include <bits/stdc++.h>
using namespace std;


int kp(  int index,int weight[],  int profit[],int W,int n){
    
    if(index==n || W==0)return 0;
    
    int exclude = kp(index+1,weight,profit,W,n);
    int include= INT_MIN;
    if(weight[index]<=W){
        include= profit[index]+kp(index+1,weight,profit,W-weight[index],n);
    }
 return max(exclude,include);
}


int main(){
    cout<<"Enter the no. of items\n";
    int n;
    cin>>n;
     cout<<"Enter the size of knapsack\n";
     int W=0;
     cin>>W;
    cout<<"enter the weight of item with its profit\n";
    int weight[n];
    int profit[n];

    for(int i=0 ;i<n ;i++){
        int wt,val;
        cin>>wt>>val;
        weight[i]=wt;
        profit[i]=val;
    }
     cout<<"your Maxmimum profit is : " <<kp(0,weight,profit,W,n);


    return 0;

}

