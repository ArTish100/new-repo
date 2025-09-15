#include <iostream>
using namespace std;
class myArr{
    int Tsize;
    int Usize;
    int *ptr;
    public:
        myArr(myArr *pclass, int Tsize, int Usize);
        void input(myArr *pclass);
        void display(myArr *pclass);
};
myArr :: myArr(myArr *pclass, int Tsize, int Usize){
    pclass->Tsize = Tsize;
    pclass->Usize = Usize;
    pclass->ptr = new int[Tsize];
}
void myArr :: input(myArr *pclass){
    for(int i = 0 ; i < pclass->Usize ; i++){
        cout<<"Enter member : ";
        cin>>(pclass->ptr)[i];
    }
}
void myArr :: display(myArr *pclass){
    for(int i = 0 ; i < pclass->Usize ; i++){
        cout<<(pclass->ptr)[i]<<endl;
    }
}
int main(){
    class myArr mark(&mark, 10, 5);
    mark.input(&mark);
    mark.display(&mark);
}