#include<iostream>
using namespace std;
class Process{
	public:
		int I;
		int BT;
		int AT;
		Process* link;
};
class ProcessList{
	public:
		Process* head = NULL;
		void BeProcess(int x,int bt, int at);
		void display();
		void CT(ProcessList *PBT,ProcessList *PCT);
        void deletenode(int x);
};
void ProcessList::BeProcess(int x,int bt, int at){
	Process* temp = new Process;
	temp->I=x;
	temp->AT=at;
	temp->BT=bt;
	temp->link=NULL;
	if(head==NULL){
		head=temp;
	}else{
		Process* temp1 = head;
		while(temp1->link!=NULL){
			temp1=temp1->link;
		}
		temp1->link=temp;
	}
}
void ProcessList::display(){
	Process* temp = head;
	int a=1;
	while(temp!=NULL){
		cout<<"P"<<temp->I<<"  "<<temp->AT<<"  "<<temp->BT<<endl;
		a+=1;
		temp=temp->link;
	}
}
/*void ProcessList::deletenode(int x){
    Process* temp = head;
	cout<<"whileb"<<endl;
    while(temp->link->I!=(x)){
        temp=temp->link;
    }
	cout<<"while"<<endl;
    if(temp==head){
        head=temp->link;
        free(temp);
    }else{
        Process* rm = temp;
        cout<<"Work3"<<endl;
        temp->link = temp->link->link;
        free(rm);
    }

    
}
*/
void ProcessList::deletenode(int x)
{
    Process* temp;
    Process* prev;
    temp = head;
    prev = head;
    for (int i = 0; i < x; i++) {
        if (i == 0 && x == 1) {
            head = (head)->link;
            free(temp);
        }
        else {
            if (i == x - 1 && temp) {
                prev->link = temp->link;
                free(temp);
            }
            else {
                prev = temp;
 
                // Position was greater than
                // number of nodes in the list
                if (prev == NULL)
                    break;
                temp = temp->link;
            }
        }
    }
}
void ProcessList::CT(ProcessList *PBT,ProcessList *PCT){
	Process* temp = head;
	Process* min,* temp1;
	int ct = 0;
	
	int k = 5;
	int l = 5;
	while(k>0){
	    min = head;
	    temp1 = head;
		temp=head;
		int flag=0;
		cout<<min->I<<endl;
	    for(int i = 0 ; i < k ; i++){
    		if(temp->AT<min->AT){
			    min=temp;
		    }
			cout<<min->I<<endl;
			if(temp->AT<ct){
				flag=1;
			}
		    temp=temp->link;
	    }
		cout<<"l"<<endl;
	    for(int j = 0 ; j < l ; j++){
    		if(temp1->AT==min->AT){
                //cout<<"1Temp1->I : "<<temp1->I<<endl;
			    if(temp1->BT<min->BT){
                    //cout<<"2Temp1->I : "<<temp1->I<<endl;
                    min=temp1;
                    //cout<<"min->I : "<<min->I<<endl;
                }
                temp1=temp1->link;
		    }else{
                //cout<<"3Temp1->I : "<<temp1->I<<endl;
    			temp1=temp1->link;
		    }
	    }
		cout<<"flag"<<endl;
		if(flag){
			Process* temp2 = head;
			for(int i = 0 ; i < k ; i++){
    			if(temp2->BT<min->BT){
			    	min=temp2;
		    	}
		    	temp2=temp2->link;
	    	}
		}
	    (*PCT).BeProcess(min->I,(min->BT)+ct,min->AT);
		(*PBT).BeProcess(min->I,min->BT,min->AT);
	    ct=ct+min->BT;
        cout<<"ct : "<<ct<<endl;
	    k--;
	    l--;
	    //cout<<"Work1";
        cout<<min->I<<endl;
		int g=1;
		Process* temp3 = head;
		while(temp3->I!=min->I){
			temp3=temp3->link;
			g++;
		}
		cout<<g<<endl;
	    deletenode(g);
		display();
	}
	cout<<"Work"<<endl;
	//(*PCT).display();
	//(*PBT).display();
}
int main(){
	ProcessList P,PBT,PCT;
	P.BeProcess(1,5,0);
	P.BeProcess(2,4,1);
	P.BeProcess(3,4,0);
	P.BeProcess(4,2,1);
	P.BeProcess(5,1,2);
	P.display();
	P.CT(&PBT,&PCT);
	PCT.display();
	PBT.display();
}