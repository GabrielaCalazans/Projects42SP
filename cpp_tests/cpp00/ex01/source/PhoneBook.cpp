/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:31:22 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/20 19:59:31 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "PhoneBook Constructor called" << std::endl;
	PhoneBook::_nbrContacts = 0;
	return;
}


PhoneBook::~PhoneBook(void) {
	std::cout << "PhoneBook Destructor called" << std::endl;
	return;
}


int	PhoneBook::getNbrContacts(void) const {
	return this->_nbrContacts;
}


void	PhoneBook::setContact(void) {
	Contact newContact;

	std::cout << "Set Contact" << std::endl;
	newContact.setFirstName();
	newContact.setLastName();
	newContact.setNickname();
	newContact.setPhoneNbr();
	newContact.setDarkestSecret();
	
	if (PhoneBook::getNbrContacts() > 7)
		PhoneBook::_nbrContacts = 0;

	PhoneBook::contacts[PhoneBook::getNbrContacts()] = newContact;
	PhoneBook::_nbrContacts++;
}


void	PhoneBook::getContact(const PhoneBook& phonebook, int pos) {
	
	std::cout << "\n**** Get Contact ****" << std::endl;
	std::cout << "Fist Name: " << phonebook.contacts[pos].getFirstName() << std::endl;
	std::cout << "Last Name: " << phonebook.contacts[pos].getLastName() << std::endl;
	std::cout << "Nickname: " << phonebook.contacts[pos].getNickname() << std::endl;
	std::cout << "Phone Number: " << phonebook.contacts[pos].getPhoneNbr() << std::endl;
	std::cout << "Darkest Secret: " << phonebook.contacts[pos].getDarkestSecret() << std::endl;

}
