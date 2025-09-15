#include<iostream>
using namespace std;
int max(int a, int b){
    return (a>b) ? a:b;
}
int knapsack(int w, int *wt, int *p, int n){
    if(n==0 || w==0){
        return 0;
    }
    if(wt[n-1]>wt[n]){
        return (knapsack(w,wt,p,n-1));
    }
    else{
        return max(p[n-1]+knapsack(w-wt[n-1],wt,p,n-1),knapsack(w,wt,p,n-1));
    }
}
int main(){
    
    int profit[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    // int **V = new int* [n];
    // for(int)
    cout<<(knapsack(W, weight, profit, n));
    return 0;

}
