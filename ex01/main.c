#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	std::string fnm;
	std::string lnm;
	std::string nnm;
	std::string pn;
	std::string ds;
	int i = 0;
	PhoneBook pb;

	std::cout << "first name : ";
	std::cin >> fnm;
	std::cout << "last name : ";
	std::cin >> lnm;
	std::cout << "nickname : ";
	std::cin >> nnm;
	std::cout << "phone number : ";
	std::cin >> pn;
	std::cout << "darkest secret : ";
	std::cin >> ds;

	pb.add(fnm, lnm, nnm, pn, ds, 0);
	std::cout << pb.contacts[0].firstname;
	
}
