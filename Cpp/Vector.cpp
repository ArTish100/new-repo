#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> &vec){
    for (int i = 0; i < vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> vec1;
    int element;
    for(int i = 0; i < 4; i++){
        cout<<"Enter an element to add to this vector : ";
        cin>>element;
        vec1.push_back(element);
        
    }
    vector<int> :: iterator itr = vec1.begin();
    vec1.insert(itr, 56);
    cout<<vec1[0];
    display(vec1);
    vector<int> vec2(4);
    vector<int> vec3(3,5);
    display(vec2);
    display(vec3);
    return 0;
}
//cplusplus.com