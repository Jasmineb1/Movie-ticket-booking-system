#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
class ticketinfo
{
	private:
		int n,ID;
		char name[30],moviename[30];
		float price;
		int seats[30];
		int choice_seat[30];
	public:
		void getdata()//to get information from the customer
		{
			int count=0;
			cout<<"Please enter number of people:"<<endl;
			cin>>n;
			cout<<"Whose name can we register the ticket under?:"<<endl;
			cin>>name;
			cout<<"Please enter your ID number:"<<endl;
			cin>>ID;
			cout<<"Please enter the name of the movie you want to watch:"<<endl;
			cin>>moviename;
			
			for(int i=0;i<n;i++)//for seats
			{
				cout<<"Please enter the seat of your choice:"<<endl;
				cin>>choice_seat[i];
					ifstream infile;
					char ch;
					infile.open("newseat.txt",ios::in|ios::app);
					if(!infile)
					{
						cout<<"FILE NOT FOUND!"<<endl;
					}
				while(!infile.eof())
				{
					//if(infile.read(reinterpret_cast<char*>(this),sizeof(*this))>0)
					//{
							infile.get(ch);
							//count++;								
							if(ch==choice_seat[i]){
								cout<<"The seat is already taken.Please choose another one!"<<endl;
							}
						
						
					//}	
			    	else{
			    			//i=i-1;
			    			break;
							/*fstream outfile;
							for(int i=0;i<n;i++){
								cout<<"Enter the seat of your choice:"<<endl;
								outfile.open("seat.txt",ios::binary|ios::app);
								outfile.write(reinterpret_cast<char*>(this),sizeof(*this));
							}*/
							
							//cin>>seats[i];
						}
						n=n+1;
						fstream outfile;
						outfile.open("newseat.txt",ios::out|ios::app);
						outfile.write(reinterpret_cast<char*>(this),sizeof(*this));
						outfile.open("final.dat",ios::out|ios::app);
						outfile.write(reinterpret_cast<char*>(this),sizeof(*this));
						//outfile.write((char *)&seats,sizeof(seats));
						//cin>>seats[i];
					}
				
				infile.close();
			}
		}
		void display()//to display the ticket
		{
			float amount=250*n;
			cout<<endl<<endl<<endl<<endl<<endl;
			cout<<"\t\t\t\t\t\t      TICKET"<<endl;
			cout<<"\t\t\t\t\t -------------------------------"<<endl;
			cout<<"\t\t\t\t\t | NO of people:"<<n<<endl;
			cout<<"\t\t\t\t\t | Name:"<<name<<endl;
			cout<<"\t\t\t\t\t | ID:"<<ID<<endl;
			cout<<"\t\t\t\t\t | Movie:"<<moviename<<endl;
			for(int i=0;i<n;i++){
				cout<<"\t\t\t\t\t | Seats: ";
				cout<<choice_seat[i]<<endl;
			}
			cout<<"\t\t\t\t\t | Cost for each ticket:250"<<endl;
			cout<<"\t\t\t\t\t | Total cost: "<<amount<<endl;
			cout<<"\t\t\t\t\t -------------------------------"<<endl;
		}
		void file_write()//to write the information into the file
		{
			char condition;
			fstream outfile;
			outfile.open("final.dat",ios::binary|ios::app);
			if(!outfile)
			{
				cout<<"FILE NOT FOUND!"<<endl;
			}
			do
			{
				getdata();//function call
				outfile.write(reinterpret_cast<char*>(this),sizeof(*this));
				cout<<"Do you want to continue enterting data?(Y/N)"<<endl;
				cin>>condition;
			}while(condition=='Y'||condition=='y');
			cout<<"<3> Recieve ticket"<<endl;
			cout<<"<5> View the total transaction and your ticket"<<endl;
			cout<<"<6> Exit"<<endl;
			
		}
		void file_read()//to read the movie list from the file
		{
			ifstream infile;
			char ch;
			infile.open("movie.txt",ios::in);
			if(!infile)
			{
				cout<<"FILE NOT FOUND!"<<endl;
			}
			while(!infile.eof())
			{
					infile.get(ch);
					cout<<ch;
			    
			}
			infile.close();
			cout<<endl;cout<<endl;cout<<endl;cout<<endl;
			cout<<"<2> Book your ticket"<<endl;
			cout<<"<3> Recieve your ticket"<<endl;
			cout<<"<4> View the seats"<<endl;
			cout<<"<6> Exit"<<endl;
		}
		void file_search()//to search the information from the file
		{
			ifstream infile;
			int number;
			infile.open("final.dat",ios::binary|ios::in);
			if(!infile)
			{
				cout<<"FILE NOT FOUND!"<<endl;
			}
			cout<<"Enter ID number to be searched:"<<endl;
			cin>>number;
			while(!infile.eof())
			{
				if(infile.read(reinterpret_cast<char*>(this),sizeof(*this))>0)
				{
					if(ID==number)
					{
						display();//function call
						return;
					}
				}
			}
			cout<<"Record not found!"<<endl;
			infile.close();
		}
		
};
void firstpage()//homepage of the program
{
	   cout<<endl;cout<<endl;
	   cout<<endl;cout<<endl;
	   cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;cout<<endl;
	   cout<<"\t\t\t\t\t  -------------------------"<<endl;
	   cout<<"\t\t\t\t\t  | WELCOME TO C++ MOVIES |"<<endl;
	   cout<<"\t\t\t\t\t  -------------------------"<<endl;
		
}
void seatformat()//seat arrangement view
{
	ticketinfo t;
	int choice_from_seatpage;
	cout<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t------------------------"<<endl;
	cout<<"\t\t\t\t\t|\t SCREEN \t|"<<endl;
	cout<<"\t\t\t\t\t------------------------"<<endl<<endl;
	cout<<"\t 1 \t | \t 2 \t | \t 3 \t | \t 4 \t | \t 5 \t | \t 6 \t "<<endl;
	cout<<"\t------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t 7 \t | \t 8 \t | \t 9 \t | \t10\t | \t11\t | \t12\t "<<endl;
	cout<<"\t------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t13\t | \t14\t | \t15\t | \t16\t | \t17\t | \t18\t "<<endl;
	cout<<"\t------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t19\t | \t20\t | \t21\t | \t22\t | \t23\t | \t24\t "<<endl;
	cout<<"\t------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t25\t | \t26\t | \t27\t | \t28\t | \t29\t | \t30\t "<<endl;
	//cout<<"\t------------------------------------------------------------------------------------------"<<endl;
	cout<<endl<<endl;
	cout<<"\t\t\t\t PLEASE REMEMBER THE SEAT YOU WANT TO CHOOSE!"<<endl;
	cout<<"Press 1 to proceed to book your ticket"<<endl;
	cout<<"Press 2 to exit"<<endl;
	cin>>choice_from_seatpage;
	if(choice_from_seatpage==1)
	{
		system("CLS");
		t.file_write();
	}
	else if(choice_from_seatpage==2)
	{
		system("CLS");
		exit(0);
	}
}
int main()
{
	int c1,c2;
	firstpage();//function call
	cout<<"\t\t\t\t\t      ENTER 1 TO PROCEED"<<endl;
	cin>>c1;
	if(c1==1)
	{
		system("CLS");
	}
	ticketinfo t1;
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t <1> Now showing :"<<endl;
	cout<<"\t\t\t\t\t <2> Ticket booking:"<<endl;
	cout<<"\t\t\t\t\t <3> Recieve your ticket:"<<endl;
	cout<<"\t\t\t\t\t <4> View the seats:"<<endl;
	cout<<"\t\t\t\t\t <5> View your ticket and total transaction:"<<endl;
	cout<<"\t\t\t\t\t <6> Exit:"<<endl;
	while(1)
	{
		cout<<"Enter choice:"<<endl;
		cin>>c2;
		if(c2==1||c2==2||c2==3||c2==4||c2==5)
		{
			system("CLS");
		}
		switch(c2)
		{
			case 1:
				t1.file_read();
				break;
			case 2:
				t1.file_write();
				break;
			case 3:
				t1.file_search();
				break;
			case 4:
				seatformat();
				break;
			case 5:
				t1.display();
				break;
			case 6:
				exit(0);
				break;
			default:
				cout<<"INVALID CHOICE!"<<endl;
		}
	}
	return 0;
}//end of program


