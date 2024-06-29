/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:31:22 by gacalaza          #+#    #+#             */
/*   Updated: 2024/06/27 20:31:26 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

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

	return (0);
}
