#include<iostream>
#include<fstream>
#include<cstring>
//declaring functions outside class
void ItemRecord();
void login();
bool isFileOpen();
void renaming();
using namespace std;
//declaring object for file at global level scope 
fstream file;
//class for Item record 
class Item
{
	//declaring private variables of class
	private:
		char Name[20];
		char Category[20];
		int barcode;
		int quantity;
		float price;
	//declaring Functions at public level 	
	public:
		void menu();
		void add_item();
		void update_Record();
		void search_name();
		void search_barcode();
		void show();
		void del_Rec();
		void update_quantity();
};
//declaring functions for file openeing to reduce code
bool isFileOpen()
{
	file.open("store1.txt",ios::in); 
	//if file opened then it will return true value else return false value   
	if (file)
	{
		return true;  
	}
	else
	{
		return false;  
	}
}
void renaming()
{
	//using remove function to remove file store.txt
	remove("store1.txt");
	//using rename function to rename file store to store1
	rename("store.txt","store1.txt");
	
}
//Defining Menu Function For Class
void Item::menu()
{
		cout<<endl<<endl;
		cout<<"\t\t\t\t\t\t    ******************************************************"<<endl<<endl;
		cout<<"\t\t\t...............................WELCOME TO WAREHOUSE INVENTORY MANAGEMENT SYSTEM..................................."<<endl<<endl;
		cout<<"\t\t\t\t\t\t    ******************************************************"<<endl;
	    cout<<"\n\n\n\n\n\n\t\t\t\t\t   ==============================================================================="<<endl;
	    cout<<"\n\n\t\t\t\t\t   |||||||||||||||||||||||||||||||    MENU CARD   ||||||||||||||||||||||||||||||||" <<endl;
	    cout<<"\n\t\t\t\t\t   ================================================================================"<<endl<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t            1. Add Item Record"<<endl;
		cout<<"\n\t\t\t\t\t\t\t            2. Display All Items Record"<<endl;
		cout<<"\n\t\t\t\t\t\t\t            3. Update Item Quantity"<<endl;
		cout<<"\n\t\t\t\t\t\t\t            4. Search Item by Barcode number "<<endl;
		cout<<"\n\t\t\t\t\t\t\t            5. Search Item By Name "<<endl;
		cout<<"\n\t\t\t\t\t\t\t            6. Delete Item Record "<<endl;
		cout<<"\n\t\t\t\t\t\t\t            7. Exit "<<endl<<endl;
		cout<<"\n\t\t\t\t\t   ================================================================================"<<endl;
	
		

			
}
//Defining Functions For Adding Item Record To File 
void Item::add_item()
{
	
		bool s=false;
		cout<<"\n\t\t\t\t";
		cout<<"\n\t\t\t\t\t\t\t   <<<< ADD NEW ITEM RECORD >>>>"<<endl<<endl;
		w:
		cin.ignore();
		cout<<"\n\t\t\t\t\t\t\t\tPlease Enter Item Name :- ";
		cin.getline(Name,20);
		for (int i = 0;i<strlen(Name);i++)
		{
			if (Name[i]=='\0')
			{
				s = true;
				break;
			}
			if(!isalpha(Name[i]))   //here using isalpha to check passed character is letter or a number..........
			{
				s = false;
				cout<<"\n\t\t\t\t\t\t\t\tYour input is wrong Enter Name without numbers ";
				//here using jump statement to shift control to p
				goto w;
			}
		}
		cin.ignore();
		cout<<"\t\t\t\t\t\t\t\tPlease Enter Category of Item :- ";
		cin.getline(Category,20);
		cout<<endl<<endl;
		cout<<"\t\t\t\t\t\t\t\tPlease Enter Barcode Number :- ";
		cin>>barcode;
		cout<<endl<<endl;
		//adding constraint on barcode valid or invalid 
		while(!s)
		{
			if(barcode>=1&&barcode<=9999)
			{
				s=true;
			}
			else
			{
				cout<<"\t\t\t\t\t\t\t\tInvalid barcode(Barcode Must be of 4 Numbers)"<<endl;
				cout<<"\n\t\t\t\t\t\t\t\tEnter Barcode Number of an item:\t";
				cin>>barcode;
			}
	
		}
		cout<<"\t\t\t\t\t\t\t\tPlease Enter Price of an Item :- ";
		cin>>price;
		cout<<endl;
		cout<<"\t\t\t\t\t\t\t\tPlease Enter Quantity Of Item :-  ";
		cin>>quantity;
		
		//Opening File in reading as well as append mode
		file.open("store1.txt",ios::out|ios::app);
		//Inserting Data to the file 
		file<<"\t\t   "<<Name<<" "<<Category<<" "<<barcode<<" "<<price<<" "<<quantity<<endl;
		//Calling Function for Closing File 
		file.close();
}
void Item::show()
{
    cout << "\n\n\n\n\t\t\t\t\t            <<<<<<< Displaying All Items Record Stored In File >>>>>>>"<<endl<<endl<<endl<<endl;
    //Calling user defined function to open file
    isFileOpen();
    //If File not Opened then Display File Opening Error...........
    if(!file)
        cout << "\n\n..........File Opening Error..........!";
    else 
	{
  
        cout << "\n\n\t\t\t\t    Item Name\t     Item Category\t    BarcodeNumber\t     Price\t     Quantity "<<endl<<endl;
  		file.clear();  
		file.seekg(0,ios::beg);  //using seekg function to manipulate cursor to the begining of text file
        while (file>>Name>>Category>>barcode>>price>>quantity) 
		{
            cout << "\t\t\t\t    " << Name
                 << "\t\t" <<Category
                 << "\t\t\t " <<barcode
                 << "\t\t       " <<price
                 << "\t\t " <<quantity
                 << "\n\n";
            cout<<endl;             
		}
		cout<<"\n\t\t\t\t\t   ______________________________________________________________________________"<<endl<<endl;
		cout<<"\n\n";
		file.close();
		}
	}
void Item::update_Record()
{
	fstream file1;
	int ibar;
	cout<<"\n\n\n\t\t\t\t\t\t\t\t  <<<<<<< Upadate Item Record >>>>>>>> "<<endl<<endl;
	cout<<"\n\n\n";
	file1.open("store.txt",ios::app|ios::out);
	isFileOpen();
	if(!file)
	{
		cout<<"\n\t\tFile Not Opened ";	
	}
	
	else
	{

		
		cout<<"\n\n\t\t\t\t\t\tEnter Item Barcode :- ";
		cin>>ibar;
		bool isFound=false;  //Initializing Bool type variable 
		while(file>>Name>>Category>>barcode>>price>>quantity)
		{
			//if condition will execute if ibar==barcode
			if(ibar==barcode)
			{
				
				cout<<"\n\n\t\t\t\t\t\tNew Item Quantity :- ";
				cin>>quantity;	
				isFound=true;
			}
			//Insertion of data to the file using object file1
				file1<<Name<<" "<<Category<<" "<<barcode<<" "<<price<<" "<<quantity<<"\n";
		}
		if (isFound==true)
		{
			cout<<"\n\n\n\n\n\t\t\t\t\t\t        [[[[[[[[[[  RECORD UPDATED SUCCESSFULLY  ]]]]]]]]]]"<<endl;
			cout<<endl<<endl<<endl;
			cout<<"\n\t\t\t\t\t   ______________________________________________________________________________"<<endl<<endl;
		}
		else
		{
			cout<<"\n\t\t\t\t\t\tRecord Not Found "<<endl;
			cout<<"\n\n\t\t\t\t\t   ______________________________________________________________________________"<<endl<<endl;
			cout<<endl<<endl<<endl;
		}
	}
	//closing of both opened files 
	file.close();
	file1.close();
	renaming();
}
//Defining Search Function using barcode of an item 
void Item::search_barcode()
{
	int ibar;
	cout<<"\n\n\n\t\t\t\t\t\t\t\t  <<<< Search Item Record >>>> "<<endl<<endl<<endl<<endl;
	isFileOpen();
	if(!file)
	{
		cout<<"\n\t\tFile Not Opened ";	
	}
	else
	{
		cout<<"\n\t\t\t\t\t   Enter Item Barcode of which record you want to search :- ";
		cin>>ibar;
		cout<<endl;
		bool isFound=false;
		while(file>>Name>>Category>>barcode>>price>>quantity)
		{
			if(ibar==barcode)
			{
				cout<<"\n\n\n\t\t\t\t\t  Searched Item Record : "<<endl<<endl<<endl;
				cout<<"\n\t\t\t\t          "<<"Name"<<"\t\t"<<"Category"<<"\t\t"<<"Barcode"<<"\t\t"<<"Price\t\t"<<"Quantity"<<endl;
				cout<<"\n\t\t\t\t"<<Name<<" \t\t\t "<<Category<<"\t\t\t    "<<barcode<<"\t\t "<<price<<"\t\t "<<quantity<<endl<<endl;	
				isFound=true;
			}
		}
		if (isFound==true )
		{
			cout<<"\n\n\n\n\n\t\t\t\t\t\t   [[[[[[[[[[[[[   RECORD SEARCH COMPLETED   ]]]]]]]]]]]"<<endl<<endl<<endl;
			cout<<"\n\n\n\t\t\t\t\t   ______________________________________________________________________________"<<endl<<endl;
            cout<<endl<<endl;
		}
		else
		{
			cout<<"\n\t\t\t\t\t   Record Not Found "<<endl;
			cout<<"\n\t\t\t\t\t   ______________________________________________________________________________"<<endl<<endl;
			cout<<endl<<endl<<endl;
		}
	}
	file.close();

}
//Defining Search function for Record using name of Item 
void Item::search_name()
{
	char iname[20];
	cout<<"\n\n\t\t\t\t   <<<< Search Item Record >>>> "<<endl<<endl;
	isFileOpen();
	if(!file)
	{
		cout<<"\n\t\tFile Not Opened ";	
	}
	
	else
	{
		cout<<"\n\t\tEnter Item Name of which record you want to search :- ";
		cin.ignore();
		cin.getline(iname,20);
		bool isFound=false;
		while(file>>Name>>Category>>barcode>>price>>quantity)
		{
			if(strcmp(iname,Name)==0)
			{
				cout<<"\n\t\tSearched Item Record : "<<endl;
				cout<<"\n\t\t\t\t"<<"Name"<<"\t\t"<<"Category"<<"\t\t"<<"Barcode"<<"\t\t"<<"Price\t\t"<<"Quantity"<<endl;
				cout<<"\n\t\t\t\t"<<Name<<"\t\t "<<Category<<"\t\t         "<<barcode<<" \t\t"<<price<<" \t\t"<<quantity<<endl;	
				isFound=true;
			}
				
		}
		if (isFound==true )
		{
			cout<<"\n\n\t\t\t\t    'Record Search Completed'"<<endl<<endl;
			cout<<"\t\t\t\t   ____________________________"<<endl;
            cout<<endl<<endl<<endl;
		}
		else
		{
			cout<<"\n\t\t  Record Not Found "<<endl;
			
            cout<<endl<<endl;
		}
	}
	file.close();  //closing Of Opened File 
}
//Defining Function for Deleting Item Record from File
void Item::del_Rec()
{
	fstream file1;
	int ibar;
	cout<<"\n\t\t\t\t   <<<< DELETE ITEM RECORD >>>> "<<endl<<endl;
	//using built-in open function for file1 object
	file1.open("store.txt",ios::app|ios::out);
	//using user defined open function for file object
	isFileOpen();
	if(!file)
	{
		cout<<"\n\t\tFile Not Opened ";	
	}
	
	else
	{
		cout<<"\n\t\tEnter Item Barcode of which record you want to delete from file :- ";
		cin>>ibar;
		cout<<endl<<endl;
		bool isFound=false;  //Initialization of Bool type Variable isFound
		while(file>>Name>>Category>>barcode>>price>>quantity)
		{
			//this if statement will be execute if user entered barcode matches to data stored in file
			if(ibar!=barcode)
			{
				//Inserting of Data to File using Object of fstream Class File1
				file1<<"\t\t"<<Name<<" "<<Category<<" "<<barcode<<" "<<price<<" "<<quantity<<"\n";	
				isFound=true;
			}		
		}
		cout<<"\n\t\t\t\t'Record has been deleted if existed'"<<endl<<endl;
		cout<<"\t\t\t\t   ____________________________"<<endl;
		cout<<endl<<endl<<endl;
	}
	//calling Close functions for both files 
	file.close();
	file1.close();
	renaming();
	
}
void login()
{
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t    ******************************************************"<<endl<<endl;
	cout<<"\t\t\t...............................WELCOME TO WAREHOUSE INVENTORY MANAGEMENT SYSTEM..................................."<<endl<<endl;
	cout<<"\t\t\t\t\t\t    ******************************************************"<<endl;
	cout<<"\t\t\t\t\t\t          "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t Created By: "<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t Ariha Noor   20-NTU-CS-1097 "<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t Esha Akram   20-NTU-CS-1100"<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t Itba Ramzan  20-NTU-CS-1109"<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t Submitted to:   Dr Muhammad Adeel "<<endl<<endl;
	cout<<endl<<endl;
	cout<<"\t\t\t^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^"<<endl<<endl;
	cout<<"\t\t\t#################################################  LOGIN PAGE  ####################################################"<<endl<<endl;
	cout<<"\t\t\t^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^"<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t           ------------------- YOU HAVE TO LOGIN TO ACCESS SYSTEM  --------------------"<<endl<<endl<<endl;
	string user,password;
	while(1)
	
	{
		


				cout<<"\n\n\t\t\t\t\t\t\t          Enter Username ---->  ";
			
					cin>>user;
			
				cout<<"\n\n\t\t\t\t\t\t\t          Enter Password ---->  ";
			
					cin>>password;
			
				if(user=="store" && password=="ate")
				{
						cout<<endl<<endl;
						cout<<"\t\t\t############################################  YOU ARE MOST WELCOME!!  #############################################"<<endl<<endl;
						system("pause");
						break;
			
					}
			
				else
						{
							cout<<"\n\n\t\t\t\t\t\t\t\t  INVALID USERNAME OR PASSWORD\n"<<endl;	
						}
				}
	
}
void ItemRecord()
{	
	login();
	char x;
	Item m;
	Item *i;   //Declaring Object for Item Class
	i=&m;
	int *choice=new int;
	//This While loop is Infinite and execute all the time.....
	while(true)
	{
		//calling menu functions using class object...... 
		i->menu();
		//Taking Input For Choice of User 
		cout<<"\n\n\n\n\t\t\t\t\t   Enter Your Choice ---> ";
		cin>>*choice;
		cout<<endl;
	//Here using Switch Statements for Different Cases 
	switch(*choice)
	{
		case 1:
			do
			{
				//calling Add Functions for adding record to file
				i->add_item();
				cout<<"\n\t\t\t\t\t\t\t\tDo U Want to add another Item(y/n) ---> ";
				cin>>x;	
				cout<<endl;
				cout<<"\n\t\t\t\t\t   ______________________________________________________________________________"<<endl<<endl;
				cout<<endl<<endl<<endl;
			}
			while(x=='y');	//This Loop will Execute Till x=='y'		
			break;   //For closing Case 1 using Break Statement
		case 2:
			//If Choice==2 then calling show function of class 
			i->show();
			break;
		case 3:
			//If Choice==3 then calling update record function of class 
			i->update_Record();
			break;
		case 4:
			//If Choice==4 then calling Search function using barcode of an Item 
			i->search_barcode();
			break;
		case 5:
			//If Choice==5 then calling Search Function using Name of an Item
			i->search_name();
			break;
		case 6:
			//If Choice==6 then calling Delete Function for deletion of Record from File
			i->del_Rec();
			break;
		case 7:
			//Termination of Whole Execution
			exit(0);
		default:
			cout<<"\t\t\t\t\t\t\t\t\tYou Entered Wrong Choice Try Again"<<endl;
}
}
}
int main()
{
	//Calling function for Item Record 
	ItemRecord();
}

