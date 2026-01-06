#include "Contact.hpp"

void Contact::setFirstName(std::string name)
{
	firstname = name;
}

void Contact::setLastName(std::string name)
{
	lastname = name;
}

void Contact::setNickName(std::string name)
{
	nickname = name;
}

void Contact::setPhoneNum(std::string name)
{
	phonenum = name;
}

void Contact::setDarkestSecret(std::string name)
{
	darkest_secret = name;
}
	std::string Contact::getFirstName()
	{
		return firstname;
	}
	std::string Contact::getLastName()
	{
		return lastname;
	}
	std::string Contact::getNickName()
	{
		return nickname;
	}
	std::string Contact::getPhoneNum()
	{
		return phonenum;
	}
	std::string Contact::getDarkestSecret()
	{
		return darkest_secret;
	}
