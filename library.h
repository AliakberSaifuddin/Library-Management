
// LIBARAY MANAGEMENT SYSTEM ALL FUNCTIONS AND CLASS DECLARATION

#include<iostream>
class Book;
class Student; 
class Librarian
{
	char id[20];
	char pass[20];
	Book *b1;
//	Student *s1;
    
    public:
    	void set_login();
    	bool operator==(const Librarian &);
    	int check_pass();
		void set_id();
   		void set_pass();
    	const char* get_id()const;
   		const char* get_pass()const;
		void change_Id_pass();
        void issuingBook(const Student &,const Book &);
    	
};

void all_issued_Book()
 {
}
class Book
{
    private:
	  int serial;
	  int totalQuantity;
	  int quantity_avail;
	  char title[20];
	  char author[20];
	  int edition;
	  double price;
    
  public:
	  Book();
	  void set_Data();
	  void add_book();
	  void delete_book();
	  int update_record();
      void view_all_book();
      static void view_noOftotalBooks();
      void all_issued_Book();
      void search_book();
};
    
class Student
{
	char name[20];
	char rollno[10];
    char field[20];
	
	public:
		void set_student();
		bool Add_student();
		void search_student();
};
