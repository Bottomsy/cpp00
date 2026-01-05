#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>

int indx = 0;

void printContacts(PhoneBook *pb, int accs_added)
{
	int i = 0;
	while(i < accs_added)
	{
		std::cout << std::setw(10) << i << "|";
		if(pb->contacts[i].firstname.length() > 10)
		{
			pb->contacts[i].firstname.resize(9);
			std::cout << std::setw(10) << pb->contacts[i].firstname << ".|";
		}
		else
			std::cout << std::setw(10) << pb->contacts[i].firstname << "|";
		if(pb->contacts[i].lastname.length() > 10)
		{
			pb->contacts[i].lastname.resize(9);
			std::cout << std::setw(10) << pb->contacts[i].lastname << ".|";
		}
		else
			std::cout << std::setw(10) << pb->contacts[i].lastname << "|";
		if(pb->contacts[i].nickname.length() > 10)
		{
			pb->contacts[i].nickname.resize(9);
			std::cout << std::setw(10) << pb->contacts[i].nickname << ".\n";
		}
		else
			std::cout << std::setw(10) << pb->contacts[i].nickname << "\n";
		i++;
	}
}
int validIndex(std::string command)
{
	if(command == "0" || command == "1" || command == "2" || command == "3")
		return 1;
	if(command == "4" || command == "5" || command == "6" || command == "7")
		return 1;
	return 0;	
}
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
	int accs_added = 0;

	while(command != "EXIT")
	{
		std::cout << "Enter one of the commands : ADD, SEARCH, EXIT\n";
		while(command.length() == 0)
		{
			std::getline(std::cin, command);
    	}
		if(command == "EXIT")
			break;
		if(command == "ADD")
		{
			if(indx >= 8)
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
			accs_added++;
			command = "";
		}
		else if(command == "SEARCH")
		{
			std::cout << std::setw(10) << "index" << "|"<< std::setw(10) << "first name" << "|"<< std::setw(10) << "last name" << "|"<< std::setw(10) << "nickname" << "\n";
			printContacts(&pb, accs_added);
			command = "";
			std::cout << "Type the contact's index to show extra info or type {no} to go back\n";
			std::getline(std::cin, command);
			if(validIndex(command) == 1)
			{
				int value = std::stoi(command);
				std::cout << "first name     - " << pb.contacts[value].firstname << "\n";
				std::cout << "last name      - " << pb.contacts[value].lastname << "\n";
				std::cout << "nickname       - " << pb.contacts[value].nickname << "\n";
				std::cout << "phone number   - " << pb.contacts[value].phonenum << "\n";
				std::cout << "Darkest secret - " << pb.contacts[value].darkest_secret << "\n";
			}
			else
				std::cout << "Invalid index\n";
			command = "";
		}
		else
		{
			std::cout << "command not recognized\n" ;
			command = "";	
		}

	}
}
