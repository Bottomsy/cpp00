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

int printByIndex(std::string command, PhoneBook *pb, int accs_added)
{
	if(validIndex(command))
	{
		int value = std::stoi(command);
		if(value >= accs_added)
			return 0;
		std::cout << "first name     - " << pb->contacts[value].firstname << "\n";
		std::cout << "last name      - " << pb->contacts[value].lastname << "\n";
		std::cout << "nickname       - " << pb->contacts[value].nickname << "\n";
		std::cout << "phone number   - " << pb->contacts[value].phonenum << "\n";
		std::cout << "darkest secret - " << pb->contacts[value].darkest_secret << "\n";
	}
	else
		std::cout << "Invalid index\n";
	return 1;
}

int promptAdd(std::string fnm, std::string lnm, std::string nnm, std::string pn, std::string ds, PhoneBook *pb)
{
	std::cout << "Add a contact to the phone book\n" ;
	while(fnm.length() == 0)
	{
		std::cout << "first name : " ;
		std::getline(std::cin, fnm);
		if(std::cin.eof())
		{
			exit(1);
		}
	}
	while(lnm.length() == 0)
	{
		std::cout << "last name : " ;
		std::getline(std::cin, lnm);
		if(std::cin.eof())
		{
			exit(1);
		}
	}
	while(nnm.length() == 0)
	{
		std::cout << "nick name : " ;
		std::getline(std::cin, nnm);
		if(std::cin.eof())
			return 0;
	}
	while(pn.length() == 0)
	{
		std::cout << "phone number : " ;
		std::getline(std::cin, pn);
	}
	while(ds.length() == 0)
	{
		std::cout << "darkest secret : " ;
		std::getline(std::cin, ds);
	}
	pb->add(fnm, lnm, nnm, pn, ds, indx++);
	return 1;
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
			if(std::cin.eof())
			{
				std::cout << "EOF\n";
				command = "?";
			}
		}
			
		if(command == "EXIT")
			break;
		if(command == "ADD")
		{
			if(indx >= 8)
				indx = 0;
			if(promptAdd(fnm,lnm, nnm, pn, ds, &pb) == 0)
				return 0;
			accs_added++;
			command = "";
		}
		else if(command == "SEARCH")
		{
			if(accs_added > 0)
			{
				std::cout << std::setw(10) << "index" << "|"<< std::setw(10) << "first name" << "|"<< std::setw(10) << "last name" << "|"<< std::setw(10) << "nickname" << "\n";
				printContacts(&pb, accs_added);
				command = "";
				std::cout << "Type the contact's index to show extra info\n";
				std::getline(std::cin, command);
				if(printByIndex(command, &pb, accs_added) == 0)
					std::cout << "No contact in that index is found\n";
				command = "";
			}
			else
			{
				std::cout << "No contacts in the phone book\n";
				command = "";
			}
		}
		else
		{
			std::cout << "command not recognized\n" ;
			command = "";	
		}

	}
}
