#include<iostream>
#include<string>
using namespace std;


int length(char* s){
    int i = 0;
    while(s[i]!='\0'){
        i++;
    }
    return i;
}
void concat(char s1[], char s2[]){
    int l1 = length(s1);
    int l2 = length(s2);
    char s3[l1+l2-1];
    for(int i = 0 ; i < l1 ; i ++){
        s3[i] = s1[i];
    }
    for(int j = 0 ; j < l2 ; j ++){
        s3[l1] = s2[j];
        l1++;
    }
    cout<<s3;
}

int main(){
    int i = 0;
    int j;
    char str1[20];
    char str2[20];
    cout<<"Enter string : ";
    cin>>str1;
    cout<<str1<<endl;
    cout<<"Enter 2nd string : ";
    cin>>str2;
    cout<<str2<<endl;
    int l1 = length(str1);
    int l2 = length(str2);
    concat(str1,str2);
}
