#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;
string name[20];
string display_name[20];
int amount[20];
int display_amount[20];
int betting_amount[20];
int guess[20];
int N;
int counter=1;//to keep track record of winners of each round(for Display() )
int maxl;//to find max amount for the player who won a particular round
int maxi;//storage of winning player of a round
int dice;
string entry;
int amt;
int lc;
int lc1;
int k;
int temp;//for Display()
int tu;//checking for the lost players
int m;//for game() function's looping
int call;
int ichoice;
int choice;//for game() function's do while
int tdf;
void Start();
void choice_starting();
void extra(char character,int n);
void rule_book();
void temp_display_first();
void Display();
void Entering();
void Entering1();
void game();
void insert();
void insert1();
void Delete();
void new_Display();
int main()
{
	srand(time(0));
	Start();
	
	
}
void Start()
{
	system("cls");
	extra('*',80);
	extra('*',80);
	cout<<"\n\n";
	cout<<"\t\tWELCOME TO CASINO ROYALE BETTING GAME\n";
	cout<<"\t\tTRY YOUR LUCK TO MAKE LOTS OF MONEY\n";
	cout<<"\n\n";
	extra('*',80);
	extra('*',80);
	choice_starting();
}
void choice_starting()
{
	cout<<"\t\tENTER YOUR CHOICE FROM BELOW\n";
	cout<<"\t\t1). PLAYER ENTRY \n";
	cout<<"\t\t2). DISPLAY ROUNDWISE WINNERS\n";
	cout<<"\t\t3). TO LEAVE\n";
	cin>>ichoice;
	if(ichoice==1)
	temp_display_first();
	else if(ichoice==2)
	Display();
	else if(ichoice==3)
	exit(0);
	else
	{
		cout<<"\nEnter a valid entry\n";
		Start();
	}
}
void extra(char character, int n)
{
    for(int i=0; i<n; i++)
        cout << character;
    cout << "\n" ;
}
void rule_book()
{
    system("cls");
    cout << "\n\n";
    extra('*',80);
    cout << "\t\tRULES OF THE GAME\n";
    extra('*',80);
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    extra('*',80);
}
void temp_display_first()
{
	system("cls");
	cout<<"\n1).Enter name of players\n";
	cout<<"2).Enter intial bet amount\n";
	cout<<"3).To start the game\n";
	cout<<"4).Exit to main menu\n";
	cin>>tdf;
	if(tdf==1)
	Entering();
	else if(tdf==2)
	Entering1();
	else if(tdf==3)
	game();
	else if(tdf==4)
	Start();
	else
	{
			cout<<"\nEnter valid entry\n";
			temp_display_first();
	}
}
void Display()
{
	system("cls");
	extra('*',80);
	cout<<"\t\tCONGRATULATIONS TO ALL WINNERS\n";
	extra('*',80);
	cout<<endl;
	for(temp=1;temp<counter;temp++)
	{
		cout<<endl;
		cout<<"\tROUND "<<temp<<" WINNER IS "<<display_name[temp]<<endl;
		cout<<"\t"<<display_name[temp]<<" WON "<<display_amount[temp]<<endl;
	}
	cout<<"\nEnter 0 to exit\n";
	cin>>call;
	if(call==0)
	Start();
}
void Entering()
{
	cout<<"\nenter no.of players to play\n";
	cin>>N;
	lc=-1;
    do
	{
		cout<<"\nEnter player name\t";
		fflush(stdin);
		getline(cin,entry);
		insert();
	}while(lc!=N-1);
	cout<<"\nEnter 0 to exit\n";
	cin>>call;
	if(call==0)
	temp_display_first();
}
void insert()
{
	lc++;
	name[lc]=entry;
}
void Entering1()
{
	lc1=-1;
	k=0;
	do
	{
		cout<<"\n"<<name[k]<<", Enter your deposit money, $";
		cin>>amt;
		k++;
		insert1();
	}while(lc1!=N-1);
	cout<<"\nEnter 0 to exit\n";
	cin>>call;
	if(call==0)
	temp_display_first();
}
void insert1()
{
	lc1++;
	amount[lc1]=amt;
}
void game()
{
	do
	{
		system("cls");
		rule_book();
		
		for(m=0;m<=lc;m++)
		{
			cout <<"\n"<<name[m]<<",Your current balance is $ " << amount[m];
		}
		cout<<endl;
		
	    for(m=0;m<=lc;m++)
		{
			do
			{
				cout<<endl<<name[m]<<", Enter your betting money $";
				cin>>betting_amount[m];
				if(betting_amount[m] > amount[m])
                {
			        cout <<name[m]<<" ,your betting amount is more than your current balance\n";
                    cout<<"\nRe-enter data\n ";
                }
			}while(betting_amount[m]>amount[m]);
		}
		
		for(m=0;m<=lc;m++)
		{
			do
			{
				cout<<endl<<name[m]<<" ,Guess your number between 1 to 10 to place the bet:";
			    cin>>guess[m];
			    if(guess[m] <= 0 || guess[m] > 10)
                {
			        cout << "Please check the number!! should be between 1 to 10\n";
                    cout<<"\n Re-enter number";
                } 
			}while(guess[m] <= 0 || guess[m] > 10);
		}
		dice = rand()%10 + 1; // Will hold the randomly generated integer between 1 and 10
		int temp=10;
		new_Display();
		tu=0;
		for(m=0;m<=lc;m++)
		{
			if(betting_amount[m]==0)
			{
				tu=1;
				break;
			}
		}
		cout<<endl;
		cout<<"\n ENTER 1 TO PALY AGAIN ";
		cout<<"\n ENTER 2 IF YOU WANT TO DELETE A PLAYER"<<endl;
		cout<<"ENTER 3 TO LEAVE"<<endl;
		cin>>choice;
    }while((choice==1 || choice==1) && tu==0);
    if(choice==2 || choice==2)
    Delete();
    maxl=0;
    maxi=0;
	for(m=0;m<=lc;m++)
    {
    	if(amount[m]>maxl)
    	{
    		maxl=amount[m];
    		maxi=m;
		}
	}
	display_name[counter]=name[maxi];
	display_amount[counter]=amount[maxi];
	counter++;
	Start();
}
void new_Display()
{
	system("cls");
	int temp=10;
		for(m=0;m<=lc;m++)
		{
			if(guess[m]==dice)
			{
				extra('*',80);
				cout << "\n\nCongratulations!! "<<name[m]<<" You won $" << betting_amount[m];
                cout<<endl;
                cout<<"\n";
				extra('*',80);
				amount[m] = amount[m] + betting_amount[m];
                temp=m;
                break;
			}
		}
		
		for(m=0;m<=lc;m++)
		{
			if(temp!=m)
			{
				amount[m]=amount[m]-betting_amount[m];
			}
		}
		 cout << "\nThe winning number was : " << dice <<"\n";
		
		for(m=0;m<=lc;m++)
		{
			cout<<endl<<name[m]<<",you have $"<<amount[m];
		}
		
}

string del_name;
void Delete()
{
	system("cls");
	int p,f=0;
	cout<<"Write the name of palyer who wants to quit.."<<endl;
	cin>>del_name;
	for( m=0;m<=lc;m++)
	{
		if(name[m]==del_name)
		{
			p=m;
			f=1;
			break;
		}
	}
	if(f==1)
	{
		cout<<name[p]<<" ,you have left the game"<<endl;
		for(m=p+1;m<=lc;m++)
		{
			name[m-1]=name[m];
			amount[m-1]=amount[m];
		}
		lc--;
	}
	else
	{
		cout<<"The player you entered is not playing"<<endl;
	}
	cout<<"\nEnter 0 to exit\n";
	cin>>call;
	if(call==0)
	game();
}
