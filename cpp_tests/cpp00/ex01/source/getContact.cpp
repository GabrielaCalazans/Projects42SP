/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getContact.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:36:57 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/23 18:32:56 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"


void	PhoneBook::searchContact(PhoneBook& phonebook) {
	int	index;

	phonebook.displayContacts();
		std::cout << "Type a contact index to see all the details" << std::endl;
		std::cin >> index;
		while (true)
		{
			if (index > 8 || index < 1) {
				std::cout << "Invalid index. Try Again!" << std::endl;
			} else {
				phonebook.getContact(phonebook, index - 1);
				break;
			}
		}
}


int	PhoneBook::getNbrContacts(void) const {
	return this->_nbrContacts;
}


void	PhoneBook::getContact(const PhoneBook& phonebook, int pos) {
	
	std::cout << "\n**** Get Contact ****" << std::endl;
	std::cout << "Fist Name: " << phonebook.contacts[pos].getFirstName() << std::endl;
	std::cout << "Last Name: " << phonebook.contacts[pos].getLastName() << std::endl;
	std::cout << "Nickname: " << phonebook.contacts[pos].getNickname() << std::endl;
	std::cout << "Phone Number: " << phonebook.contacts[pos].getPhoneNbr() << std::endl;
	std::cout << "Darkest Secret: " << phonebook.contacts[pos].getDarkestSecret() << std::endl;
}


std::string Contact::getFirstName() const {
	return this->_firstName;
};


std::string Contact::getLastName() const {
	return this->_lastName;
};


std::string Contact::getNickname() const {
	return this->_nickname;
};


std::string Contact::getPhoneNbr() const {
	return this->_phoneNbr;
};


std::string Contact::getDarkestSecret() const {
	return this->_darkestSecret;
};

