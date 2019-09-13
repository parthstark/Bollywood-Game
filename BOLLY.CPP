#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void loading()
 {
 int num;
 for(num=0; num<2000; num++)
  {
  cout<<"Loading";
  cout<<"__  __  __  __  __  __  __  __  __  __  __  __  __  __  __  __  __  __";
  clrscr();
  cout<<"Loading";
  cout<<" __  __  __  __  __  __  __  __  __  __  __  __  __  __  __  __  __  __";
  clrscr();
  }
 }

void game_rules()
 {
 clrscr();
 cout<<"Hello Player :)\n\nWelcome to the world of movies.\n\n";
 cout<<"->This is a simple MOVIE NAME GUESSING GAME.\n\n";
 cout<<"->You will a get a name of a movie with all the letters blank EXCEPT the VOWELS\n\n";
 cout<<"->You will have to guess one letter at a time.\n";
 cout<<"->In total you can try guess upto 10 wrong letters.\n\n";
 cout<<"->Depending on the number of tries left,\n  you will be awarded 10 points for each try.\n";
 cout<<"->If no chance is left and you still aren't able to guess right, you lose.\n\n";
 cout<<"->Example:\n\n  Suppose the movie name is:\n  SHOLAY\n\n";
 cout<<"  It will be displayed as:\n";
 cout<<"  _ _ o _ a _";
 getch();
 }

class movie
{
 public:
 char movname[50];
 void input()
 {
 cout<<"Enter movie name\t";
 gets(movname);
 }
 void output()
 {
 cout<<movname<<endl;
 }
}mn;

void main()
{
clrscr();
loading();
int a;

begin:
clrscr();
cout<<"\t ____________________________________________________________ \n";
cout<<"\t||    ___      ___                                           ||\n";
cout<<"\t||  ||   ||  //   \\\\  ||      ||   \\\\    //                  ||\n";
cout<<"\t||  ||___//  ||   ||  ||      ||     \\\\//                    ||\n";
cout<<"\t||  ||   \\\\  ||   ||  ||      ||      ||                     ||\n";
cout<<"\t||  ||___||  \\\\___//  ||____  ||____  ||                     ||\n";
cout<<"\t||                                 ___      ___      ____    ||\n";
cout<<"\t||             \\\\            //  //   \\\\  //   \\\\  ||    \\\\  ||\n";
cout<<"\t||              \\\\          //   ||   ||  ||   ||  ||    ||  ||\n";
cout<<"\t||               \\\\  //\\\\  //    ||   ||  ||   ||  ||    ||  ||\n";
cout<<"\t||                \\\\//  \\\\//     \\\\___//  \\\\___//  ||____//  ||\n";
cout<<"\t||     ___    ______                ____      ___            ||\n";
cout<<"\t||   ||   ||    ||    |\\\\     ||  //        //   \\\\          ||\n";
cout<<"\t||   ||___//    ||    || \\\\   ||  ||  ___   ||   ||          ||\n";
cout<<"\t||   ||   \\\\    ||    ||   \\\\ ||  ||    ||  ||   ||          ||\n";
cout<<"\t||   ||___||  __||__  ||     \\\\|  \\\\____||  \\\\___//          ||\n";
cout<<"\t||___________________________________________________________||\n";

int ch;
cout<<"-> Enter your choice\n\n1.Play Game\n2.Game Rules\n3.Admin login\n4.Terminate Program\n";
cin>>ch;

if(ch==1)
 goto game;

else if(ch==2)
 {
 loading();
 game_rules();
 goto begin;
 }

else if(ch==3)
{
 char password[6];
 clrscr();
 for(a=0;a<4;a++)
 {
  cout<<"\t\t\t\tADMIN LOGIN\n";
  cout<<"Enter the password\n";
  cin>>password;
  if(strcmp(password,"admin")==0)
   {
   a=4;
   clrscr();
   fstream obj1;
   fstream obj2;
   int admin_choice;
   menu:
   clrscr();
   cout<<"Enter your choice number\n";
   cout<<"1.Add more movie names\n2.View list of movies\n";
   cout<<"3.Exit admin and play game\n4.Terminate program\n";
   cin>>admin_choice;
    if(admin_choice==1)
     {
     clrscr();
     cout<<"\t\t-> Type X to stop entering movies any more.\n\n\t\t->Else enter movie name and continue\n\n";
     do
      {
      mn.input();
      if(strcmp(mn.movname,"x")==0||strcmp(mn.movname,"X")==0)
       goto menu;
      else
      {
       obj1.open("list.dat",ios::binary|ios::app);
       obj1.write((char*)&mn,sizeof(mn));
       obj1.close();
      }
      }while(0==0);
     }
    else if(admin_choice==2)
     {
      clrscr();
      obj2.open("list.dat",ios::binary|ios::in);
      cout<<"-> List of movies are\n\n";
      int list_count=0;
      while(obj2.read((char*)&mn,sizeof(mn)))
       {
       list_count++;
       mn.output();
       if(list_count==22)
	{
	getch();
	clrscr();
	list_count=0;
	}
       }
      getch();
      obj2.close();
      int sub_choice;
      SubChoice:
      cout<<"\n-> Enter your choice\n1.Return to admin menu\n2.Return to main menu\n3.Play the game\n";
      cin>>sub_choice;
      clrscr();
      if(sub_choice==1)
       goto menu;
      else if(sub_choice==2)
       goto begin;
      else if(sub_choice==3)
       goto game;
      else
      goto SubChoice;
     }
    else if(admin_choice==3)
     goto game;
    else if(admin_choice==4)
     exit(0);
    else
     {
     cout<<"Wrong choice entered\n";
     goto menu;
     }
   }
  else
  cout<<"\nWrong password!\nChances left="<<3-a<<endl;
 }
}

else if(ch==4)
 exit(0);

else
{
 clrscr();
 goto begin;
}

game:
loading();

randomize();
fstream f("list.dat",ios::binary|ios::in);
f.seekg(0,ios::end);
int total_size=f.tellp();
int no_records=total_size/sizeof(mn);
int random_no=random(no_records);
f.close();

clrscr();
cout<<"\n\t\t\t\tLET'S PLAY!!!\n\n";
char l, film[50], temp1[50], temp[50];

fstream mov("list.dat",ios::binary|ios::in);
mov.seekg(sizeof(mn)*random_no,ios::beg);
mov.read((char*)&mn,sizeof(mn));
strcpy(temp1,mn.movname);

for(a=0;temp1[a]!='\0';a++)
 {
  film[a*2]=temp1[a];
  film[a*2+1]=' ';
 }
film[a*2]='\0';

int chance=10;
cout<<"\nNumber of chances left="<<chance<<endl;
for(a=0;film[a]!='\0';a++)
 {
 if(film[a]=='a'||film[a]=='e'||film[a]=='i'||film[a]=='o'||film[a]=='u'||film[a]==' '||film[a]=='.')
  {
  temp[a]=film[a];
  }
 else
  {
  temp[a]='_';
  }
 }
temp[a]='\0';
int count_;
cout<<temp;
do
{
cout<<"\nEnter the letter\t";
cin>>l;
int right_count=0;
for(a=0;temp[a]!='\0';a++)
 {
 if(film[a]==l)
  {
  temp[a]=l;
  right_count++;
  }
 }
if(right_count==0)
chance--;
cout<<"\nNumber of chances left="<<chance<<endl;
cout<<temp;
if(chance==0)
break;
count_=0;
for(int a=0;temp[a]!='\0';a++)
 {
 if(temp[a]=='_')
 count_++;
 }
}
while(count_!=0);
loading();
clrscr();
if(count_==0)
 {
 cout<<"\n\n\t\t\t\t'"<<mn.movname<<"'";
 cout<<"\n\n\t\t\t\t-> You Win!!!\n\n\t\t\t\t-> Total Points= "<<chance*10;
 }
else
 {
 cout<<"\n\n\t\t\t\t'"<<mn.movname<<"'";
 cout<<"\n\n\t\t\t\t-> You Lose\n";
 }
getch();
int enter;
cout<<"\n\n-> Enter 5 to play again\n";
cout<<"\n-> Enter 0 to go to main menu\n";
cout<<"\n-> Enter any key to exit\n\n";
cin>>enter;
clrscr();
if(enter==5)
goto game;
else if(enter==0)
goto begin;
else
exit(0);
}