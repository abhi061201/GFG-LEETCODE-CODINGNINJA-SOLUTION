#include <bits/stdc++.h>
using namespace std;


int knapsack(  int weight[],  int profit[],int W,int n){
    
    if(n==0 || W==0)return 0;
    if(weight[n-1]<W){
        return max(knapsack(weight,profit,W,n-1),profit[n-1]+knapsack(weight,profit,W-weight[n-1],n-1));
    }
    else if(weight[n-1]>W){return knapsack(weight,profit,W,n-1);}
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
     cout<<"your Maxmimum profit is : " <<knapsack(weight,profit,W,n);


    return 0;

}
