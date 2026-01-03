#include "PhoneBook.hpp"
#include "Contact.hpp"
int indx = 0;

int main()
{
	std::string fnm;
	std::string lnm;
	std::string nnm;
	std::string pn;
	std::string ds;
	std::string command;
	int i = 0;
	PhoneBook pb;

	while(command != "EXIT")
	{
		std::cout << "Enter one of the commands : ADD, SEARCH, EXIT\n";
		while(command.empty())
		{
			std::getline(std::cin, command);
		}
		if(command == "ADD")
		{
			if(indx >= 3)
				indx = 0;
			std::cout << "Add a contact to the phone book\nfirst name : " ;
			std::getline(std::cin, fnm);
			std::cout << "last name : " ;
			std::getline(std::cin, lnm);
			std::cout << "nick name : " ;
			std::getline(std::cin, nnm);
			std::cout << "phone number : " ;
			std::getline(std::cin, pn);
			std::cout << "darkest secret : " ;
			std::getline(std::cin, ds);
			pb.add(fnm, lnm, nnm, pn, ds, indx++);
			std::cout << "fnm : " << pb.contacts[0].firstname << "\n";
			command = "";
		}
	}
}
