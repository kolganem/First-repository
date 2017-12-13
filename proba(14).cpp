#include "mylib.h"

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
