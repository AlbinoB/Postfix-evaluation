#include<iostream>
using namespace std;
int push(int *arrstring,int top,int ch)//pass the address of the string array,top index of the stack
	{
        arrstring[++top]=ch;
        return top;
	}


int pop(int *arrstring,int top)//pass the address of the string array,top index of the stack
{
    return arrstring[top--];
}


 char display_top(int *arrstring,int top)//pass the address of the string array,top index of the stack
 {
        return arrstring[top];
}


void display(int *arrstring,int top)//pass the address of the string array,top index of the stack
{
        if(top==-1){
            cout<<"\n stack is empty";
        }else
        {
            cout<<"\n top "<<"\n  :\n";
            for(int i=top;i>=0;i--)
            {
                cout<<"| "<<arrstring[i]<<" |"<<"\n";
            }
        }
}



int isfullint(int top,int arrsize){
    if((top+1)==arrsize)//top+1 as top array starts from 0
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isemptyint(int top){
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
