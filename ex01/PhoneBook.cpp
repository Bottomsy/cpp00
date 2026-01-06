#include "PhoneBook.hpp"
#include "Contact.hpp"

void PhoneBook:: add(std::string fnm, std::string lnm, std::string nnm, std::string pn, std::string ds, int i)
{
	contacts[i].setFirstName(fnm);
	contacts[i].setLastName(lnm);
	contacts[i].setNickName(nnm);
	contacts[i].setPhoneNum(pn);
	contacts[i].setDarkestSecret(ds);
}
 Contact PhoneBook::getContact(int i)
 {
	return contacts[i];
 }
