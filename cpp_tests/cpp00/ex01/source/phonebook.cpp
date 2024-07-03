/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:31:22 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/03 19:05:58 by gacalaza         ###   ########.fr       */
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

