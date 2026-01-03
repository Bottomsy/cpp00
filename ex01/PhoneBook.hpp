#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"


class PhoneBook
{
        public :
        Contact contacts[8];
	
        public :
	void add(std::string fnm, std::string lnm, std::string nnm, std::string pn, std::string ds, int i);
        //void search();
        //void exit();
};


#endif
