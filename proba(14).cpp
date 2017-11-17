#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <stdlib.h> // Только из-за очистки экрана



class lib
{	private:
		 int numRead = 0; 
		 int numBook = 0;
		 int countRead = 0, countBook = 0, countOnhands = 0;
	public:
		void printNum_Read();
		void printNum_Book();		
		void addReader(std::string);
		void delReader(int);
		void addBooks(std::string);
		void delBooks(int);
		void giveBook(int, int);
		void returnBook();
		
};

void lib::printNum_Book()
{
	system("cls");
	countBook = 0;
	std::vector<std::string> vec;
	std::ifstream myfile("books.txt", std::ios::in);
	if(myfile.is_open())
	{
		std::string str;
		while(getline(myfile, str))
		{
			vec.push_back(str);
			countBook++;
		}
		myfile.close();
	}
	int x2 = 1;
	for(std::string i: vec)
	{
		std::cout << x2 << '-' << i << std::endl;
		++x2;
	}
	std::cout << std::endl;
}
void lib::printNum_Read()
{
	system("cls");
	countRead = 0;
	std::vector<std::string> vec;
	std::ifstream myfile("reader.txt", std::ios::in);
	if(myfile.is_open())
	{
		std::string str;
		while(getline(myfile, str))
		{
			vec.push_back(str);
			countRead++;
		}
		myfile.close();
	}
	int x2 = 1;
	for(std::string i: vec)
	{
		std::cout << x2 << '-' << i << std::endl;
		++x2;
	}
	std::cout << std::endl;
}
void lib::addReader(std::string newReader)
{	
	std::ofstream addFile("reader.txt", std::ios::app);
	addFile << newReader << std::endl;
	addFile.close();
	++countRead;


}	
void lib::delReader(int numDel)
{		
	if(numDel > 0 && numDel <= countRead )
	{
		
		std::vector<std::string> vec;
		std::ifstream myfile("reader.txt");
		if(myfile.is_open())
		{
			std::string str;
			while(getline(myfile, str))
				vec.push_back(str);
			myfile.close();
			vec.erase(vec.begin() + numDel - 1);	
		}
		--countRead;
		std::ofstream myfile2("reader.txt", std::ios::out);
		std::vector<std::string>::iterator it;
		for(it = vec.begin(); it != vec.end(); ++it)
			myfile2 << *it << std::endl;
	}
	else{std::cout << "Error" <<std::endl;}
	
}
void lib::addBooks(std::string newBook)
{
	std::ofstream addFile("books.txt", std::ios::app);
	addFile << newBook << std::endl;
	addFile.close();
	++countBook;
}
void lib::delBooks(int numDel)
{
	if(numDel >= 0 && numDel <= countBook )
	{	
			std::vector<std::string> vec;
			std::ifstream myfile("books.txt");
			if(myfile.is_open())
			{
				std::string str;
				while(getline(myfile, str))
					vec.push_back(str);
				myfile.close();
				vec.erase(vec.begin() + numDel - 1);	
			}
			--countBook;
			std::ofstream myfile2("books.txt", std::ios::out);
			std::vector<std::string>::iterator it;
			for(it = vec.begin(); it != vec.end(); ++it)
				myfile2 << *it << std::endl;
			
	}
	else{std::cout << "Error" <<std::endl; }
	
	
	
}
void lib::giveBook(int nBook, int nRead)
{
	if((nBook > 0 && nBook <= countBook) && (nRead > 0 && nRead <= countRead))
	{
		std::vector<std::string> vec;
		std::ifstream myfile("books.txt");
		if(myfile.is_open())
		{
			std::string str;
			while(getline(myfile, str))
				vec.push_back(str);
			myfile.close();	
		}
		std::fstream myfileReadBook("onHands.txt", std::ios::app);
		
		if(myfileReadBook.is_open())
			myfileReadBook  <<  vec[nBook-1] << std::endl;
	
		std::vector<std::string> vec2;
		std::ifstream myfile2("reader.txt", std::ios::in);
		
		if(myfile2.is_open())
		{
			std::string str;
			while(getline(myfile2, str))
				vec2.push_back(str);
			myfile2.close();
		}
		
		myfileReadBook << "Reader -- " << vec2[nRead-1] << std::endl;
		myfileReadBook.close();
	}
	else { std::cout << "Error numbers" <<std::endl;}		
}	
void lib::returnBook()
{

	countOnhands = 0;
	std::vector<std::string> vec;
	std::ifstream myfile("onHands.txt", std::ios::in);
	if(myfile.is_open())
	{
		std::string str;
		while(getline(myfile, str))
		{
			vec.push_back(str);
			countOnhands++;
		}
		myfile.close();
	}
	std::cout << "Books on hands:" << std::endl;
	int j = 1;			
	for(int i =0; i < countOnhands; i++)
	{
		if(i == 0 || i%2 == 0)
		{
			std::cout << j << " - " << vec[i] << std::endl;
			j++;
		}
	}
	
	int numReturn_book ;
	std::cout << "Please, enter number of the returned book --  " ;
	std::cin >> numReturn_book;
		
	vec.erase(vec.begin() + numReturn_book - 1);
	vec.erase(vec.begin() + numReturn_book - 1);
	countOnhands--;
	countOnhands--;
	
	std::cout << "Book return." << std::endl;
		
	std::ofstream myfile2("onHands.txt", std::ios::out);
	if(myfile2.is_open())
	{
		std::vector<std::string>::iterator it;
		for(it = vec.begin(); it != vec.end(); ++it)
			myfile2 << *it << std::endl;
			
	}
	if(countOnhands == 0)
		std::cout << "No books on hand!!!!!!"<<std::endl
				  << "Need give books" << std::endl;
	std::cout << std::endl;
}
void menuLibrary()
{
	std::cout << "Menu library:" << std::endl
		 << " 1 - Show readers."<< std::endl
		 << " 2 - Show books."<< std::endl
		 << " 3 - Add reader."<< std::endl
		 << " 4 - Delete reader."<< std::endl
		 << " 5 - Add books." << std::endl
		 << " 6 - Delete books." << std::endl
		 << " 7 - Give the book to the reader." << std::endl
		 << " 8 - Return a book ." << std::endl
		 << " 9 - Exit program."<< std::endl;
}
int main()
{	
	int numCom = 0;
	while(1)
	{
		menuLibrary();
		std::cout << "Please, enter number operation -- ";
		std::cin >> numCom;
	
		lib mylib;
		
		switch(numCom)
		{
			case 1:
			{	
				system("cls");
				mylib.printNum_Read();
				break;
			}
			case 2:
			{
				system("cls");
				mylib.printNum_Book();
				break;
			}
			case 3:
			{
				system("cls");
				std::cin.clear();
				while(std::cin.get() != '\n');
				std::string nName;
				std::cout << "Please, enter name new rader: ";
				getline(std::cin, nName);
				
				mylib.addReader(nName);
				std::cout << "Enter OK" << std::endl << std::endl;

				break;
			}
			case 4:
			{
				mylib.printNum_Read();
				
				int numDel_R = 0;
				std::cout << "Please, enter number of the line to delete: ";
				std::cin >> numDel_R;
				mylib.delReader(numDel_R);
				std::cout << "Data delete" << std::endl << std::endl;
				break; 
			}
			case 5:
			{
				system("cls");
				std::cin.clear();
				while(std::cin.get() != '\n');
				std::string addBook;
				std::cout << "Please, enter name book: ";
				getline(std::cin, addBook);
				mylib.addBooks(addBook);
				std::cout << "Enter OK" << std::endl << std::endl;

				break;
			}
			case 6:
			{
				mylib.printNum_Book();
				
				int numDel_B = 0;
				std::cout << "Please, enter number of the line to delete: ";
				std::cin >> numDel_B;
				
				mylib.delBooks(numDel_B);
				std::cout << "Data delete" << std::endl;
				break;
			}
			case 7:
			{	
				system("cls");
				
				mylib.printNum_Book();
				
				int numBook = 0, numRead = 0;
				std::cout << "Please, enter number book we give: ";
				std::cin >> numBook;
				
				system("cls");
				
				mylib.printNum_Read();
				
				std::cout << "Please, enter number reader who takes the book: ";
				std::cin >> numRead;
				
				mylib.giveBook(numBook, numRead);
				
				break;
				
			}
			case 8:
			{
				system("cls");
				
				mylib.returnBook();

				break;
			}				
			
			case 9:
			{	
				return 0;
			}
			default:
			{
				std::cout << "Entered number is not correct!!!!" << std::endl << std::endl;
			}
		}
	}
}
