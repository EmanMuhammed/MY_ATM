#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct personinfo
{    
    public:
	string userName[5]={"Eman","Noor","Hanan","ALi","Omer"};
	int userCode[5]={1,2,3,4,5};
	int userPassword[5]={11,22,33,44,55};
	int userAccount[5]={100000,200000,300000,400000,500000};
}object[5];

main()
{  

int code,password; bool flag;int ATM[1000],totalAmount=1000000,storageOfWithdrawnMoney=0,t1,t2; // t1 stands for temporary storage1
int withdrawAmount,j=0;  //j is the counter inside the for loop                                // t2  stands for temporary storage2
                         // i is counter
for(int i=0;i<1000;i++)
{
	if(i<8)
	ATM[i]=25000;
	else if(i>=8 && i<28)
	ATM[i]=10000;
    else if(i>=28 && i<68)
	ATM[i]=5000;
	else if(i>=68 && i<268)
	ATM[i]=1000;
	else if(i>=268 && i<668)
	ATM[i]=500;
	else
	ATM[i]=0;
}

while(totalAmount!=0)
{
    Try_again:
	
    cout<<"Please enter your code :";
    cin>>code;
    cout<<"Please enter your password :";
    cin>>password;

    for(int i=0;i<5;i++)
       if(object[i].userCode[i]==code && object[i].userPassword[i]==password)
         {    
	         flag=true;
    	     t1=i;
       	} 
      
///////////////////////////////////////////////////////////////////////////	
if(flag==1)
{    
      
    enter_again:
                cout<<"You have "<<object[t1].userAccount[t1]<<"\nPlease enter the amount you want to withdraw:";
                cin>>withdrawAmount;
                if(object[t1].userAccount[t1]!=0 ) 
			   	{
                    if(withdrawAmount%5==0 && withdrawAmount/5!=0)
                      {
			
	                     if(withdrawAmount<=totalAmount && withdrawAmount<=object[t1].userAccount[t1])
				           {               
						           t2=withdrawAmount;
				                   while(storageOfWithdrawnMoney!=t2)
								   {
					                    if(withdrawAmount>=ATM[j])
					                       {
					                      	  storageOfWithdrawnMoney+=ATM[j];
				                              ATM[j]=0;
				                              withdrawAmount=t2-storageOfWithdrawnMoney;
			                               }
				                        j++;
				                    }
				           }
			        	else
					       {  
					            cout<<"Out of range"<<endl;
				           }
                   } 
                   else    
			        	{
				
                           cout<<"Please enter the multiples of number five \n";
                           goto enter_again;	
	                    }    
}
	          
totalAmount-=storageOfWithdrawnMoney;	
object[t1].userAccount[t1]-=storageOfWithdrawnMoney;	
cout<<"The total amount in ATM ="<<totalAmount<<endl;
cout<<"The remained amount in your account = "<<object[t1].userAccount[t1]<<endl;
cout<<"Withdrawn ammount ="<<storageOfWithdrawnMoney<<endl;

}
	   
    
///////////////////////////////////////////////////////////////////////////
else
{
cout<<"Wrong Login ,Try again\n";
goto Try_again;
}
}
	

	
	
getch();
}
