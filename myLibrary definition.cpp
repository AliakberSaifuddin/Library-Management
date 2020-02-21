
// LIBARAY MANAGEMENT SYSTEM ALL FUNCTIONS DECLARATION

#include<iostream>
#include<conio.h>
#include<iomanip>
#include<fstream>
#include<cstring>
#include<windows.h>
#include "library.h"

using namespace std;

//class Student;
//class Book;


void Librarian :: set_login()
{
	 cout << "Enter Id : ";
	 cin >> id;
	 cout << "Enter Password : ";
	 cin >> pass;
}
void Librarian :: change_Id_pass()
{
	int id;
	char pass[4];
	fstream file;
	
	file.open("password.txt",ios::in | ios::out);
	if(!file.is_open())
	{
		cout << "File Doesnot Exist.\n";
	}
	else
	{
		Librarian temp;
		cout << "Enter Old Id : ";
		cin >> id;
		cout <<"Enter Previous Password : ";
		cin >> pass;
		file.read((char *)&temp,sizeof(temp));
		cout << temp.get_id() << " "<<temp.get_pass() << "lala ";
		if(!strcmp(id,temp.get_id()) && !strcmp(pass,temp.get_pass()))
		{
			char pass1[20];
			cout << "Enter New Id : ";
			temp.set_id();
			cout << "Enter New Password : ";
			temp.set_pass();
			cout << "Enter Confirmation Password : ";
			cin >> pass1;
			  if(!strcmp(pass,temp.get_pass()))
			  {
			  	file.write((char *)&temp,sizeof(temp));
			  	cout << "\n\tPassword Successfully has been Changed.\n";
			  }
		}
		else
		{
			cout << "Incorrect Password.\n";
		}
	}
}

void Librarian :: set_id()
    {
   
    		cin >> id;
   	}
void Librarian ::  set_pass()
    {
   		    cin >> pass;	
	}
	
const char* Librarian :: get_id() const
{
	return id;
}
const char*Librarian :: get_pass() const
{
	return pass;
}

bool Librarian :: operator==(const Librarian & l1)
{
	if(!strcmp(this->get_id(),l1.get_id()) && !strcmp(this->get_pass(),l1.get_pass()))
       return 1;
    else
       return 0;
}
		
int Librarian :: check_pass()
{
	this->get_pass();
	Librarian temp;
	ifstream fin;
	fin.open("login.txt",ios::in);
	fin.read((char *)&temp,sizeof(temp));
	if(*this==temp)
       {
	     cout << "\n\t\tPassword Matched Successfully!.\n";
	     return 1;
	   }
	else
	   {
	     cout << "\n\t\tID or Password Incorrect!.\n";
	     return 0;
	   }
	 
}

Book :: Book()
{
	//Book *b1 = new Book;
  //  Student *s1 = new Student;
    serial = 0;
    totalQuantity = 0;
	quantity_avail = 0;  
    strcpy(title,"title");
    strcpy(author,"author");
    edition = 0;
    price = 0.0;
}
void Book :: set_Data()
{

	cin.ignore();
	cout << "\n Enter the title: ";
	cin.getline(title,19);
	cin.ignore();
	cout << "Enter the name of the author : ";
	cin.getline(author,19);
	cout << "Enter the edition: ";
	cin >> edition;
	cout << "Enter the Price : ";
	cin >> price;
}
 
void Book :: add_book()
  {
   	fstream file;
  	Book temp; 
  	int choice;
  	this->set_Data();
    char ch = '\n';
    int c = 0;
   	if(!strcmp(this->title,"title") && !strcmp(this->author,"author"))
  	{
  		cout << "\nData is Uninitialized.";
      	return;
	}
  	else
  	{    
	    file.open("Libraryfile1.txt",ios::in | ios::out | ios::ate );
	    
  	     cout << file.tellp() << endl;
  	     file.seekp(0);
  	     if(!file.is_open())
		  	{
		  	    cout << "\nFile doesnot exist";	
		    }
		 else
		 if(file.eof())
		 {
		 	cout << "Previously File was Empty.\n";
	     }   
         else
		    {
		    	file.read((char *)&temp,sizeof(temp));
		    	int start_size = file.tellp();
				while(!file.eof())
			    {
			   	  if(!strcmp(title,temp.title) && !strcmp(author,temp.author) && (edition == temp.edition))  
			        {
			        	if(price!=temp.price)
			        	{
			        		cout << "\n\t\tThe Record that You have Entered Previously Exist.\n"
			        		     << "               But Price is not Matching                \n"
			        		     << "\t 1) But would you like to change the Existing Record Price.\n"
			        		     << "                             OR                              \n"
			        		     << "\t 2)               want to keep price same                  \n"
			        			 <<"\t press (1) Or (2) : ";
	     		            cin >> choice;
    		            }
	   		        	temp.totalQuantity+=1;
	   		        	temp.quantity_avail+=1;
							  
	    		        if(choice == 1)
		    		      temp.price = price;
		    		      int set = 0;
		    		            int size = file.tellp();
								set = size - start_size + c;
					            file.seekg(set);
					            file.write((char *)&temp,sizeof(temp));

								file.close();
								return;
                    }
                    c++;
                    file.read((char *)&ch,sizeof(ch));
	    		    file.read((char *)&temp,sizeof(temp));
				}
				file.close();
 			}
 			      
                  file.open("Libraryfile1.txt",ios::in | ios::out | ios::app);
 			        int set = 0;
 			        this->serial = temp.serial + 1; 
		    		int size = file.tellg();
		            file.write((char *)this,sizeof(*this));
					file.write((char *)&ch,sizeof(ch));
					file.close();
	} 
}

int Book :: update_record()
{
	fstream fout;
	int c = 0;
  	Book temp;
    fout.open("Libraryfile1.txt",ios::out|ios::in|ios::ate);
    fout.seekg(0);
    char ch;
    char choice;
    fout.read((char *)this,sizeof(*this));
    int start_size = fout.tellp();
   	
   	this->view_all_book();
    cout << "\nEnter Book Serial Number to update Record.? ";
	cin >> choice;
	 	while(!fout.eof())
	       {
			  if((int)choice-48 == this->serial)
	          {
                 if(totalQuantity != quantity_avail)     
	                cout << "\t\tBe Carefull while Changing Quantity\t"
				         << " Becauses Some Books Are issued.\n";     
	           
	          	label : 1;
			    cout << "\n\n\t\tRecord Founded";
			    cout << "\nwhat update what you want : \n";
	            cout << "1) Change Total quantity\n"
	                 << "2) Change Available Quantity.\n"
                     << "3) Change Title.\n"
	                 << "4) change Author.\n"
	                 << "5) Change Price.\n"
	                 << "6) All Of them.\n"
	                 << "7) To Update.\n";
                cin >> choice;
	        
            	   system("CLS");
					switch(choice)
		            {
					   case '1':
						{
							cout << "Previous Total Quantity : " << totalQuantity << endl;
							cout << "Enter Total Quantity : ";
							cin >> totalQuantity;
							goto label;
						}
						case '2':
						{
							cout << "Previous Available Quantity : " << quantity_avail << endl;
							cout << "Enter Available Quantity : ";
							cin >> quantity_avail;
							goto label;
						}
			            case '3':
					    {
							cout << "Previous Book Title : " << title << endl;
							cout << "Enter Book Title : ";
							cin >> title;
							goto label;
						}
						case '4':
						{
							cout << "Previous Book Author : " << author << endl;
							cout << "Enter Total author : ";
							cin >> author;
							goto label;
						}
						case '5':    
						{
							cout << "Previous Book Price : " << price << endl;
							cout << "Enter Book Price : ";
							cin >> price;
							goto label;
						}
						case '6':
						{
							cout << "Total Quantity : " <<totalQuantity << endl
								 << "Quantity Available : " <<quantity_avail<< endl
								 << "Title : "<<title << endl
								 << "Author : " <<author << endl
								 << " Price : "<<price << endl;
							cout << "\t\tEnter Information to Update Record.\n";	 
							cout << "Enter Total Quantity : ";
							cin >> totalQuantity;
							cout << "Enter Available Quantity : ";
							cin >> quantity_avail;
							cout << "Enter Title : ";
							cin >> title;
							cout << "Enter Author : ";
							cin >> author;
							cout << "Enter Price : ";
							cin >> price;
							goto label;							
       					}
       					case '7':
 						{
						    int size = fout.tellp();
							int set = size - start_size + c;
						    fout.seekp(set); 
							fout.write((char *)this,sizeof(*this));
						    fout.close(); 
						    return 1;
						}
						default : 
						{
							cout << "Invalid Choice.\n";
							break;
							goto label;
						}      						
			    	}
			
   }
		      c++;
		       fout.read((char *)&ch,sizeof(ch));
		       fout.read((char *)this,sizeof(*this));
	        }
       fout.close();
       cout << "\nRecord Not Found";
}
void Book :: delete_book()
  {
	ofstream fout;
	int trip = 0;
	ifstream fin;
	int choice,check = 0;
	view_all_book();
	cout << "Enter Book Serial No. to delete Record.? ";
	cin >> choice;
	
    fin.open("Libraryfile1.txt",ios::in);
    fout.open("temporaryfile.txt",ios::out | ios::app);

      char ch;
	  fin.read((char *)this,sizeof(*this));
	  fin.read((char *)&ch,sizeof(ch)); 
	  
	while(!fin.eof())
       {
  	    if(choice != serial || totalQuantity != quantity_avail)
      	    {
      	    	if(trip !=0)
      	    	this->serial--;
      	    	// setting serial number after deletion (kal karna hae)
      	    	  this->serial--;
				  fout.write((char *)this,sizeof(*this));
	        	  fout.write((char *)&ch,sizeof(ch));
	        	  check++;
      	    }
      	    else
      	    trip = 1; 
	        fin.read((char *)this,sizeof(*this));
    	    fin.read((char *)&ch,sizeof(ch));
       }
       check++;
       if(check == serial)
       cout << "\n\t\tRecord Was Founded and Deleted.\n";
       else
       cout << "\n\t\tRecord was not Found.\n";
       
	   fout.close();
	   fin.close();

       getch();
       remove("Libraryfile1.txt");
       getch();
       rename("temporaryfile.txt","Libraryfile1.txt");
}
/*
void Librarian :: issuingBook(const Book & b1)
	{
		int choice;
		char nam[20],id[10];
	    cout << "Enter Your name : ";
	    cin >> nam;
	    cout << "Enter Id : ";
	    cin >> id;
	    if(this->search(nam,id))
	    {
	    	cout << "\n\t\tRecord Founded.\n";
		  //  this->view_all_book();
			label : 1;
			cout << "1) Would you like to search Book.\n"
		         << "2) View All Books.\n"
		         << "3) To Exit.\n"
		         << "\nEnter Your Choice : ";
			cin >> choice;
			if(choice ==)
			{
		       this->view_all_book();
		       cout << "Enter serial No to issue Book.? ";
			}
	        
		}
	    
	        
	}
	*/
	/*
bool Librarian :: search_student(char const *nam, char const *id)
    {
    	student s1;
	    ifstream fin;
		fin.open("studentRecord.txt",ios::in); 
        if(!fin.is_open())
        {
        	cout << "\nNo Record Exist.\n";
		}
		else
		{
			fin.read((char *)&s1,sizeof(s1));
			
			while(!file.eof())
			{
				if(!strcmp(nam,s1.name) && !strcmp(id,s1.id))
				{
					return 1;
				}
			fin.read((char *)&ch,sizeof(ch));	
			fin.read((char *)&s1,sizeof(s1));

			}
			return 0;
		}
	}*/	
void Book :: view_all_book()
    {
    	ifstream fin;
    	Book temp;
    	fin.open("Libraryfile1.txt",ios::in | ios::app);
    	if(!fin.is_open())
    	 {
   		   cout << "\nFile doesnot exist.\n";
		 }
		else
		 {
		        fin.seekg(0);
		        fin.read((char *)&temp,sizeof(temp));
		        cout << "\n\n*******All Books Record********\n\n";
    		    cout <<left<< "Serial" << '\t' << "Total-Quantity" <<'\t' <<"Quantity Available"
                     << '\t' <<"Title" << '\t'<<"Author"
	                 << '\t' <<"Edition" << '\t' <<"Price\n";
			while(!fin.eof())
			{
				char ch;
				fin.read((char *)&ch,sizeof(ch));
				cout << left << temp.serial <<"\t" 
				     << temp.totalQuantity << "\t"
				     << temp.quantity_avail << "\t" <<temp.title <<'\t'
					 << '\t'<<temp.author<< "\t"<<temp.edition << "\t"
					 <<temp.price<<endl;
			    fin.read((char *)&temp,sizeof(temp));
			    
			}
			fin.close();
		 }
	} 
void Book :: search_book()
	{
		Book temp;
		char tit[20];
		cin.ignore();
		cout << "Enter the title of the Book: ";
		cin.getline(tit,19);
		ifstream fin;
		cout << tit;
		fin.open("Libraryfile1.txt",ios::in);
//		fin.seekg(0);
		if(!fin.is_open())
		 {
		   "File Doesnot Exist.\n";	
		 }
		else
		 {
		 	fin.read((char *)&temp,sizeof(temp));
		 //	 cout <<title<< "\t" << author << "\t" << edition << "\t" << price << endl;
			 char ch;
			 fin.read((char *)&ch,sizeof(ch));
			 cout << "Title\t\tAuthor\t\tEdition\t\tPrice\n";
			while(!fin.eof())
			  {
				if(!strcmp(tit,temp.title))
			    {
				  cout <<temp.title<< " \t\t" << temp.author << "\t\t" << temp.edition << "\t\t" << temp.price << endl;
				//   cout <<temp.title<< "\t" << author << "\t" << temp.edition << "\t" << temp.price << endl;
			    }
				 fin.read((char *)&temp,sizeof(temp));
                 fin.read((char *)&ch,sizeof(ch));
			  }
        }
	}
void Book :: all_issued_Book()
{
    	ifstream fin;
    	Book temp;
    	fin.open("issueBook.txt",ios::in | ios::app);
    	if(!fin.is_open())
    	 {
   		    cout << "\nFile doesnot exist.\n";
		 }
 	    else
		 {
		 	    char ch;
		        fin.seekg(0);
		        fin.read((char *)&temp,sizeof(temp));
		        fin.read((char *)&ch,sizeof(char));
				cout << "\n\n*******All Issued Books Record********\n\n";
    		    cout << "Title\t\tAuthor\t\tEdition\t\tPrice\n";
				while(!fin.eof())
					{
						cout <<temp.title<<"\t"<<temp.author<<"\t"<<temp.edition<<"\t"<<temp.price<<endl;
					    fin.read((char *)&temp,sizeof(temp));
					    fin.read((char *)&ch,sizeof(char));
					}
		 }
		        fin.close();
}


void Student :: set_student()
   {
		cin.ignore();
        cout << "Enter Student name : ";
		cin.getline(name,19);
		cin.ignore();
		cout << "Enter Roll No. : ";
        cin.getline(rollno,19);
        cin.ignore();
        cout << "Enter Student Field : ";
        cin.getline(field,19);
   }

bool Student :: Add_student()
  {
   	ofstream fout;
   	this->set_student();
  	if(!strcmp(this->name,"name") && !strcmp(this->rollno,"Roll-No"))
  	{
  		cout << "\nData is Uninitialized.";
      	return 1;
	}
 
  	else
  	{  
         fout.open("StudentData.txt",ios::out | ios::app);
  	     if(!fout.is_open())
		  	{
		  	    cout << "\nFile doesnot exist";	
		    }
         else
		    {  
		        char ch = '\n';
		        fout.write((char *)this,sizeof(*this));
		        fout.write((char *)&ch,sizeof(ch));
				fout.close();			    	
            }
    }
}

void Student :: search_student()
{
	char nam[20],no[20];
   		cin.ignore();
        cout << "Enter Student name : ";
		cin.getline(nam,19);
		cin.ignore();
		cout << "Enter Roll No. : ";
        cin.getline(no,19);
        cin.ignore();
		ifstream fin;
		fin.open("StudentData.txt",ios::in);
//		fin.seekg(0);
		if(!fin.is_open())
		 {
		   "File Doesnot Exist.\n";	
		 }
		else
		 {
		 //	cout << "chaale";
            fin.read((char *)this,sizeof(*this));
		     char ch;
			 fin.read((char *)&ch,sizeof(ch));
			 cout << "Name\t\tRoll - No\t\tField\n";
			while(!fin.eof())
			  {
				if(!strcmp(nam,this->name) && !strcmp(no,this->rollno))
			    {
				  cout <<name<< " \t\t" << rollno << "\t\t" << field << endl;
				//   cout <<temp.title<< "\t" << author << "\t" << temp.edition << "\t" << temp.price << endl;
			    }
				 fin.read((char *)this,sizeof(*this));
                 fin.read((char *)&ch,sizeof(ch));
			  }
        }
}


        


