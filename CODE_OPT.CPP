#include<process.h>
#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>


void main()
{
clrscr();
char a[]={'=','-',',','@',';','#','%','+','^','!','{','[',']','}'};
char lhs[100][10];
char rhs[100][10];
int n,b=0,p=0,k,count=0;
static int flag = 1;
char y;
cout<<"Enter the no of 3 instructions code";
cin>>n;
cout<<"\nTo Abort  press at LHS symbols =,@,#,$,%,+,-";
for(int i=0;i<n;i++)
{ cout<<"\n\nEnter the instruction no:"<<i+1;
cout<<"\nLHS followed by RHS\n";

	for(int j=0;j<2;j++)
	{
	printf("%c",lhs[i][j]=getch());
	for(int l=0;l<strlen(a);l++)
	if(lhs[i][j] == a[l])
	  {
	  clrscr();

	  cout<<"\n\n\t\tYou Entered Wrong input (Aborting...)";
	   getch();
	  exit(1);

	  }
	  }


cout<<"\t=\t";

	       gets(rhs[i]);

}
cout<<"\nOptimal Code optimization for Entered code";


//COPY PROPAGATION

for(i=0;i<n;i++)
{
// checking each r.h.s

      /* if(rhs[i][k] == NULL)
	  { i=i+1;
	  continue;
	  } */
				       count=0;

	for(p=i+1;p<n;p++)
	{       /*if(lhs [p][0] == NULL)
			p=p+1;    */

		for(k=0;rhs[i][k] != '\0';k++)
		{

			if(rhs[i][k] == rhs[p][k])
		       {  count++;
		       }
			else
			{break;}
		}
if(count == strlen(rhs[p]))
		{ cout<<"\nCopy Propagation Found at";
		cout<<"\nInstructions:"<<i+1<<" and "<<p+1;
		flag=10;
		}
	}
}

// DEAD CODE
for(p=0;p<n-1;p++)
{ // Taking L.H.S first
	//implimenting KMP algorithm
	 flag=0;
	 for(i=p+1;i<n;i++)
	 { b=strlen(rhs[i]);
	 for(k=0;k<b; k++)
	    { if ((lhs[p][0] == rhs[i][k]) && (lhs[p][1] == rhs[i][k+1]))
			    { flag=1;
			    }
	    }
	 }
if(flag == 0)
{ cout<<"\nDead code found with instruction :"<<p+1;
   cout<<"\nRemoving ...";
		   lhs[p][1]=lhs[p][0]=NULL;

	  b=strlen(rhs[p]);
	 for(k=0;k<b; k++)
	     rhs[p][k]=NULL;


   flag = 10;
}

}





if(flag == 1)
{
cout<<"\n\nNO optimization Required already otimized";
}
else
for(i=0;i<n;i++)
{
cout<<"\n\nInstruction no:"<<i+1<<endl;
//cout<<"\nLHS followed by RHS\n";
	for(int j=0;j<2;j++)
	{if(lhs[i][j] == NULL)
	{ i=i+1;}

	printf("%c",lhs[i][j]);

	}



cout<<"\t=\t";

		puts(rhs[i]);

}

getch();
}











