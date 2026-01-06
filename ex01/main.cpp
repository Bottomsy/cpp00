#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>

int indx = 0;

void printContacts(PhoneBook *pb, int accs_added)
{
	int i = 0;
	while(i < accs_added)
	{
		std::string fnm = pb->getContact(i).getFirstName();
		std::string lnm = pb->getContact(i).getLastName();
		std::string nnm = pb->getContact(i).getNickName();
		std::cout << std::setw(10) << i << "|";
		if(fnm.length() > 10)
		{
			fnm.resize(9);
			std::cout <<  fnm << ".|";
		}
		else
			std::cout << std::setw(10) << fnm << "|";
		if(lnm.length() > 10)
		{
			lnm.resize(9);
			std::cout << lnm << ".|";
		}
		else
			std::cout << std::setw(10) << lnm << "|";
		if(nnm.length() > 10)
		{
			nnm.resize(9);
			std::cout <<  nnm << ".\n";
		}
		else
			std::cout << std::setw(10) << nnm << "\n";
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
		int value = command[0] - '0';
		if(value >= accs_added)
			return 0;
		std::cout << "first name     - " << pb->getContact(value).getFirstName() << "\n";
		std::cout << "last name      - " << pb->getContact(value).getLastName() << "\n";
		std::cout << "nickname       - " << pb->getContact(value).getNickName() << "\n";
		std::cout << "phone number   - " << pb->getContact(value).getPhoneNum() << "\n";
		std::cout << "darkest secret - " << pb->getContact(value).getDarkestSecret() << "\n";
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
			return 0;
	}
	while(lnm.length() == 0)
	{
		std::cout << "last name : " ;
		std::getline(std::cin, lnm);
		if(std::cin.eof())
			return 0;
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
		if(std::cin.eof())
			return 0;
	}
	while(ds.length() == 0)
	{
		std::cout << "darkest secret : " ;
		std::getline(std::cin, ds);
		if(std::cin.eof())
			return 0;
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
	PhoneBook pb;
	int accs_added = 0;

	while(command != "EXIT")
	{
		std::cout << "Enter one of the commands : ADD, SEARCH, EXIT\n";
		while(command.length() == 0)
		{
			std::getline(std::cin, command);
			if(std::cin.eof())
				return 0;
		}
		if(command == "EXIT")
			break;
		if(command == "ADD")
		{
			if(indx >= 8)
				indx = 0;
			if(promptAdd(fnm,lnm, nnm, pn, ds, &pb) == 0)
				return 0;
			if(accs_added < 8)
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
				if(std::cin.eof())
					return 0;
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