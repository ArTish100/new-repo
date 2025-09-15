#include<iostream>
using namespace std;

int main(){
    cout<<"Enter number of proceses : ";
    int np;
    cin>>np;
    int PAT[20];
    int PBT[20];
    int PET[20];
    for(int i = 0 ; i < np ; i++){
        cout<<"Enter arrival time : ";
        cin>>PAT[i];
        cout<<"Enter burst time : ";
        cin>>PBT[i];
        if(i==0){
            PET[0]=PAT[0]+PBT[0];
        }else{
            PET[i]=PBT[i]+PET[i-1];
        }
    }
    
    int Turn=0;
    for(int i = 0; i < np ; i++){
        Turn = PET[i]-PAT[i] + Turn;
    }
    cout<<"Waiting time : "<<Turn;

}
    

