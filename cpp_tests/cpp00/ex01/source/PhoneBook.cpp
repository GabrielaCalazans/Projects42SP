/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:31:22 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/11 20:07:41 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(std::string name) {
	std::cout << "PhoneBook Constructor called" << std::endl;
	std::cout << "ObjectName: " << name << std::endl;
	PhoneBook::setNameT(name);
	PhoneBook::_nbrContacts = 0;
	return;
}


PhoneBook::~PhoneBook(void) {
	std::cout << "PhoneBook Destructor called" << std::endl;
	return;
}


int	PhoneBook::getNbrContacts(void) {
	return PhoneBook::_nbrContacts;
}


void	PhoneBook::setNameT(std::string name) {
	PhoneBook::_nameT = name;
}

std::string	PhoneBook::getName(void) {
	return PhoneBook::_nameT;
}

