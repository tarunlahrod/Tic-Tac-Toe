

//TIC TAC TOE :my FIRST ever game, Dated: 5 jan 2017.

#include<fstream.h>
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void make_stone()
{
cout<<"\n\n            _.._  \n";
cout<<"        ._./    \,,_\n";
cout<<"      ,,/          \_\n";
cout<<"    ../     STONE   ''\ \n";
cout<<"   (_,,___,,,_ _ ...___) \n";
}


void make_scissor()
{


cout<<"\n\n\n";
cout<<"   .-.        \n";
cout<<"  ( O )......... \n";
cout<<"   '>------------>	SCISSOR\n";
cout<<"  ( O )'''''''''  \n";
cout<<"   '-' \n\n\n";
}

void make_paper()
{
cout<<"\n";
cout<<"   .----------.   \n";
cout<<"   |_|________|   \n";
cout<<"   | |        | \n";
cout<<"   | | PAPER  | \n";
cout<<"   | |        | \n";
cout<<"   | |        |  \n";
cout<<"   '----------'  \n";
}

int check_SPS(int n1,int n2)
{
if(n1==1&&n2==1) return 0;
if(n1==1&&n2==2) return 2;
if(n1==1&&n2==3) return 1;

if(n1==2&&n2==1) return 1;
if(n1==2&&n2==2) return 0;
if(n1==2&&n2==3) return 2;

if(n1==3&&n2==1) return 2;
if(n1==3&&n2==2) return 1;
if(n1==3&&n2==3) return 0;
}

void starline()
{
for(int i=0;i<30;i++)
cout<<"****";
}

void fn_grid(char b[])
{
	cout<<"\n\n\n";
	for(int i=1;i<10;i+=3)
	{
	cout<<"   |   |   \n";
	cout<<" "<<b[i]<<" | "<<b[i+1]<<" | "<<b[i+2]<<" \n";
	if(i==7)
   	cout<<"   |   |   ";
	else
   	cout<<"___|___|___\n";
	}
   cout<<"\n\n\n";
}


int fn_check(char c[])
{
if(
	c[1]==c[2] && c[2]==c[3]   ||
   c[1]==c[4] && c[4]==c[7]   ||
   c[1]==c[5] && c[5]==c[9]   ||
   c[4]==c[5] && c[5]==c[6]   ||
   c[7]==c[8] && c[8]==c[9]   ||
   c[7]==c[5] && c[5]==c[3]   ||
   c[3]==c[6] && c[6]==c[9]   ||
   c[2]==c[5] && c[5]==c[8]
   )
	return -1;
else
	return 0;
}


//******************************************************//
//                     main fn()                        //
//******************************************************//


void main()
{

int retry,choice,pos,flag=0,flag_winner=0;  //'flag' for finding the winner and 'flag_winner' for storing the winner name in record.
char a[10],P1[25],P2[25],rec[500];

cout<<"\n\n							GAME HUB\n							~~~~~~~\n\n";
menu:
cout<<"\n	Press...\n\n	1. Stone-Paper-Scissor\n	2. Tic Tac Toe\n\n				Choice...";
cin>>choice;



switch(choice)
{
//**************************************//
//        STONE PAPER SCISSOR           //
//**************************************//
case 1:
	{
   int select,computer,result;

cout<<"\n\n							Stone Paper Scissor\n							~~~~~~~~~~~~~~~~~~~\n\n";

make_stone();
make_paper();
make_scissor();

cout<<"\n	Select- \n";
cout<<"	1. Stone \n	2. Paper \n	3. Scissor\n";
cout<<"	Your Choice...";
cin>>select;

randomize();
computer=random(3)+1;
result=check_SPS(select,computer);
cout<<"\n\n	You choosed: "<<select;
cout<<"\n	Computer: "<<computer;
if(result==0)
	cout<<"\n	Match Draw\n";
   else if(result==1)
				{cout<<"\n 	You Win\n";}
            else if (result==2)
							{cout<<"\n	You Lose\n";}

cout<<"\n\n	Thanks For playing...\n\n";
break;
}

case 2:
{
//***************************//
//        Tic Tac Toe        //
//***************************//

cout<<"\n\n							TIC-TAC-TOE\n						       ~~~~~~~~~~~\n";

cout<<"\n\n\n	Enter names...\n\n	Player #1: ";
gets(P1);
cout<<"\n	Player #2: ";
gets(P2);

//assigning the positions to the grid numbers...

a[1]='1' ;  a[2]='2' ;  a[3]='3' ;
a[4]='4' ;  a[5]='5' ;  a[6]='6' ;
a[7]='7' ;  a[8]='8' ;  a[9]='9' ;



cout<<"\n\n\n";
cout<<"   |   |   \n";
cout<<" 1 | 2 | 3 \n";
cout<<"___|___|___\n";

cout<<"   |   |   \n";
cout<<" 4 | 5 | 6 \n";
cout<<"___|___|___\n";

cout<<"   |   |   \n";
cout<<" 7 | 8 | 9 \n";
cout<<"   |   |   \n";


//loop for playing the game...

for(int x=1;x<10;x++)
{
if(x%2)
{

	cout<<"\n	"<<P1<<"'s turn,\n	Enter position...";
	cin>>pos;
   a[pos]='0';

   fn_grid(a);

   flag=fn_check(a);

   if(flag==-1)
   {
   cout<<"\n\n	"<<P1<<" Wins!"; flag_winner=1;
   break;
   }
   else ;

   if(x==9)
   {
   cout<<"\n\n		MATCH DRAW!!!!\n\n";
   }


}
else
	{
   cout<<"\n	"<<P2<<"'s turn,\n	Enter position...";
	cin>>pos;
   a[pos]='X';

   fn_grid(a);

   flag=fn_check(a);

   if(flag==-1)
   {
   cout<<"\n\n	"<<P2<<" Wins!";flag_winner=2;
   break;
   }

   }



}

//**************************************//
//    storing the player's record       //
//**************************************//

fstream f;

f.open("TIC-TAC-TOE.txt",ios::app);
f<<"   player1: "<<P1;
f<<"   player2: "<<P2;

if(flag_winner==0)
{
 f<<"     status: DRAW\n\n";
}
else if(flag_winner==1)
{
f<<"     status: "<<P1<<" wins\n\n";
}
else if(flag_winner==2)
{
f<<"     status: "<<P2<<" wins\n\n";
}

f.close();

cout<<"\n\n\n				THANKS FOR PLAYING...\n			check your data in records...\n\n\n\n";

break;
}

default:
cout<<"\n\n	Invalid!!!\n";
goto menu;
}

cout<<"\n\n			DO YOU WANNA RETRY?\n			1.Yes\n			2.No\n					Enter...";
cin>>retry;

if(retry==1)
goto menu;

else cout<<"\n\n\n						PROGRAM ENDED \n";

starline();

getch();

}  //End of main()







 
