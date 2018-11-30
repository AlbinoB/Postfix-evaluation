#include<iostream>
#include<stdlib.h>
#include<stack_array_int.h>
#include<string.h>
using namespace std;
	void accept(char *,char *);
	void display(char *);
	void evaluate(char *);
int main()
{

	int c,arrsize=20;
	char arrstring[arrsize],copyarrstring[arrsize];
	do
	{
		cout<<"\n\n\n enter your choice \n 1.Accept expression \n 2.Display infix expresion \n 3.Display postfix expression \n 4.Evaluate postfix expression. \n 0.exit.";
		cin>>c;
		switch(c)
		{
			case 1:{
				accept(arrstring,copyarrstring);
				break;
				}
			case 2:{
			    cout<<"\n The infix expression is:";
				display(arrstring);
				break;
				}
			case 3:{
			    if(strcmp(arrstring,copyarrstring)==0)
                {
                    cout<<"\n not coverted to postfix!!! \n Select option 4 to convert...";
                }
                else
                {
                    cout<<"\n The postfix expression is:";
                    display(copyarrstring);
                }
				break;
				}
            case 4:{
				evaluate(copyarrstring);
				break;
				}

			 default:{
					cout<<"\n wrong input entered!!!";
					break;
				      }
		}
	    cout<<"\n___________________________________________________\n";
	}while(c!=0 && c<5 && c>0);
	return 0;
}

	void accept(char *arrstring,char *copyarrstring)
	{
		cout<<"\n Enter the infix expression:";
        cin>>arrstring;
        strcpy(copyarrstring,arrstring);
        cout<<"\n The infix expression is:";
        display(arrstring);
	}

	void display(char *arrstring)
		{
			cout<<arrstring;
		}

void evaluate(char *copyarrstring){
     int outputstack[20],x,y,eval;
    int i=0,topoutputstack=-1;
    while(copyarrstring[i]!='\0')
    {
       if((int)copyarrstring[i]=='*'||(int)copyarrstring[i]=='/'||(int)copyarrstring[i]=='+'||(int)copyarrstring[i]=='-')
        {
            y=pop(outputstack,topoutputstack);
            topoutputstack--;
            x=pop(outputstack,topoutputstack);
            topoutputstack--;
            cout<<"\n ascii value of cpy ar[i]"<<(int)copyarrstring[i]<<"x="<<x<<"y:"<<y;
            switch(copyarrstring[i])
                {
                    case '*':{
                        eval=x*y;
                        break;


                    }
                    case '/':{
                        eval=x/y;
                         break;


                    }
                    case '+':{
                        eval=x+y;
                         break;

                    }
                    case '-':{
                        eval=x-y;
                         break;

                    }
                }
                topoutputstack=push(outputstack,topoutputstack,eval);
                i++;
        }
        else
        {
             int x=(int)copyarrstring[i]-48;
             topoutputstack=push(outputstack,topoutputstack,x);
             i++;
               }

    }
        cout<<"\n answers is :"<<outputstack[0];
}



