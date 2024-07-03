/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:04:09 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/03 19:48:18 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"


static void	showMenu() {
	
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

