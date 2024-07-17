/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:04:09 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/11 19:55:28 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "PhoneBook.hpp"


// // #ifndef PHONEBOOK_H
// // # define PHONEBOOK_H

// // //# include "Contact.hpp"

// // class PhoneBook {

// // private:
// // //	Contact		contacts[8];
// // 	static int	_nbrContacts;
// // 	std::string	_nameT;

	
// // public:
// // 	PhoneBook(std::string name);
// // 	~PhoneBook();

// // 	static int	getNbInst(void);
// // 	void		testfunc(std::string name) const;
// // 	int			test;

// // 	void		setNameT(std::string name);
// // 	std::string	getName(void);
// // };

// // #endif


PhoneBook::PhoneBook(std::string name) : test(0) {
	std::cout << "PhoneBook Constructor called" << std::endl;
	std::cout << "ObjectName: " << name << std::endl;
	PhoneBook::_nbrContacts += 1;
	PhoneBook::setNameT(name);
	return;
}


PhoneBook::~PhoneBook(void) {
	std::cout << "PhoneBook Destructor called" << std::endl;
	PhoneBook::_nbrContacts -= 1;
	return;
}


int	PhoneBook::getNbInst(void) {
	return PhoneBook::_nbrContacts;
}

void	PhoneBook::setNameT(std::string name) {
	PhoneBook::_nameT = name;
}

std::string	PhoneBook::getName(void) {
	return PhoneBook::_nameT;
}


void	PhoneBook::testfunc(std::string name) const {

	std::cout << "Member function testfunc called with parameter: " << name << std::endl;
	return;
}


static void	showMenu() {
	
	std::string text = "  PhoneBook  ";
	int width = 40;
	int text_length = text.length();
	int fill_length = (width - text_length) / 2;

	std::cout << std::setfill('*') << std::setw(fill_length + text_length) << text;
	std::cout << std::setfill('*') << std::setw(fill_length) << "" << std::endl;


	std::cout << "Type ADD to save a new contact" << std::endl;
	std::cout << "Type SEARCH to save a new contact" << std::endl;
	std::cout << "Type EXIT to quit the program" << std::endl;

	std::cout << std::hex << 674 << std::endl;
	std::cout << std::setw(10) << std::setfill('0') << "anil" << std::endl;

}


int	PhoneBook::_nbrContacts = 0;

int	main() {

	std::cout << "Number of instances: " << PhoneBook::getNbInst() << std::endl;

	PhoneBook	firstCall("firstCall");
	PhoneBook	*secondCallptr = &firstCall;


	int			PhoneBook::*p = NULL;
	void		(PhoneBook::*f)(std::string name) const;
	std::cout << "Number of instances: " << PhoneBook::getNbInst() << std::endl;


	p = &PhoneBook::test;

	std::cout << "Value of member test: " << firstCall.test << std::endl;
	firstCall.*p = 21;
	std::cout << "Value of member test: " << firstCall.test << std::endl;
	secondCallptr->*p = 42;
	std::cout << "Value of member test: " << firstCall.test << std::endl;

	f = &PhoneBook::testfunc;

	(firstCall.*f)("Hello, I'm the first");
	(secondCallptr->*f)("Hello, I'm the second");

	std::cout << "The Name set is: " << firstCall.getName() << std::endl;
	std::cout << "The Second Name is: " << secondCallptr->getName() << std::endl;

	showMenu();
	
	return (0);
}

