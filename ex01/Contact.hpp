#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private :
	std::string firstname;
	std::string nickname;
	std::string lastname;
	std::string phonenum;
	std::string darkest_secret;

	public :
	void setFirstName(std::string name);
	void setLastName(std::string name);
	void setNickName(std::string name);
	void setPhoneNum(std::string name);
	void setDarkestSecret(std::string name);
	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhoneNum();
	std::string getDarkestSecret();
};

#endif
