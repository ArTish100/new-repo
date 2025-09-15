#include<iostream>
using namespace std;
void fun(){
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            for(int j = 0 ; j < 8 ; j++){
                break;
            }
            cout<<"tree";
        }
        cout<<"tree";
    }
}
int main(){
    fun();
}