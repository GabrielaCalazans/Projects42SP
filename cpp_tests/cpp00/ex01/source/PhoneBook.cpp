/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:31:22 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/16 18:02:33 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	std::cout << "PhoneBook Constructor called" << std::endl;
	PhoneBook::_nbrContacts = 0;
	return;
}


PhoneBook::~PhoneBook(void) {
	std::cout << "PhoneBook Destructor called" << std::endl;
	return;
}


int	PhoneBook::getNbrContacts(void) const {
	return PhoneBook::_nbrContacts;
}


void	PhoneBook::setContact(const PhoneBook& phonebook) {
	Contact newContact;

	std::cout << "Set Contact" << std::endl;
	std::cout << phonebook.getNbrContacts() << std::endl;;

}


void	PhoneBook::getContact(const PhoneBook& phonebook) {
	std::cout << "Get Contact" << std::endl;
	std::cout << phonebook.getNbrContacts() << std::endl;;
}
