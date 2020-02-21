#include<iostream>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include "myLibrary definition.cpp"

using namespace std;

int menu()
{
	
	getch();
	system("cls");
	int choice;
	cout << "\n 1) for insert Book."
	     << "\n 2) for update Book."
	     << "\n 3) for search Book."
	     << "\n 4) for Viewing all records."
	     << "\n 5) For Viewing All Issued Book."
		 << "\n 6) for delete Book."
	     << "\n 0) for exit." << endl;
    cout << "Enter your Choice : ";
    cin >> choice;
    return choice;
}

int main()
{
	Librarian l1;
	Book b1;
	int access;
cout << "\n\t\tAre you an Librarian Or Student.\n";	
cout << "\n\t  Enter 1) for Librarian And 2) for Student : ";
cin >> access;
if(access == 1)
{
	label : 1;
	l1.set_login();
    
	if(l1.check_pass())    
	   {
		 while(1)  
			{
				switch(menu())
				{
					case 1:
						b1.add_book();
						break;
				    
					case 2:
						b1.update_record();
						break;
					
					case 3:
						b1.search_book();
						break;
					
					case 4:
						b1.view_all_book();
						break;
					
					case 5:
					    b1.all_issued_Book();	
					    break;
					 
					case 6:
						b1.delete_book();
						break;	
						
					case 0:
						exit(0);
					    break;
					    
		            default:
		            	cout << "\nInvalid Choice.";
		
		        }
		    }
	    }
    else
        {
        	goto label;
	    }
}
else
if(access == 2)
{
	cout << "\n\tThis Part Coming soon.\n";
}
else
{
    cout << "\n\tInvalid Choice.\n";	
}
}


	


