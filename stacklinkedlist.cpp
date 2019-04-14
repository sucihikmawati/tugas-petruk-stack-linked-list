#include <iostream>
#define MAX_STACK_SIZE 10
using namespace std;

struct Element {
    int data, top;
    Element *next;
};
class MyStack {
    private:
    Element stack;
    Element *head = NULL;
   
    public:
    	void top(){
    		stack.top=-1;
		}
    bool isEmpty(){
    	if (stack.top == -1){
        return 1; 
    } else {
        return 0;
    	}	
	}
	bool isfull(){
		if (stack.top == MAX_STACK_SIZE-1){
			return 1;
		} else {
			return 0;
		}
	}
    void push(int data){
    	if (!isfull()){
    
	    Element *item=new Element;
        item->data=data;
        item->next= NULL;
        if (isEmpty()){
        	head = item;
            head->next=NULL;
        } else {
            item->next=head;
            head=item;
        }
        stack.top++;
    }
    else{
    	cout<<"stack penuh"<<endl;
	}
}
    Element pop(){
        if (isEmpty()){
        	cout<<"Stack Kosong"<<endl;
        } else {
			Element *item = new Element;
        	item = head;
        	head=head->next;
        	delete item;
            stack.top--;
        }
    }
    void printStackList(){
        if (isEmpty()){
			cout<<"stack kosong"<<endl;
		}else {
			Element *item = new Element;
        	item = head;
        	while(item!=NULL){
        		cout<<item->data<<" ";
        		item= item->next;
			}
			cout<<"\n";
	 }
	}
    int getTop(){
        return stack.top;
    }
};
int main()
{
    MyStack s;
    s.push(8);
    s.push(3);
    s.push(2);
    s.push(9);
    s.push(7);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.printStackList();
    return 0;
} 
