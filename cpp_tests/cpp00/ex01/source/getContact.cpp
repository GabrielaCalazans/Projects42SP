/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getContact.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:36:57 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/27 21:26:44 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"


bool	isValidOption(const std::string& option) {
	if (option.length() > 1)
		return false;

	if (!std::isdigit(option[0])) 
		return false;

	return true;
}


void	PhoneBook::searchContact(PhoneBook& phonebook) {
	int	index;

	phonebook.displayContacts();
	std::cout << "Type a contact index (1-8) to see all the details" << std::endl;

	while (true)
	{
		std::cin >> index;

		if (std::cin.fail()) {
					std::cin.clear(); // Limpa o estado de erro do cin
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora o input inválido restante
					std::cout << "Invalid index. Please enter a number between 1 and 8." << std::endl;
		} else if (index > 8 || index < 1) {
			std::cout << "Invalid index. Please enter a number between 1 and 8." << std::endl;
		} else {
			phonebook.getContact(phonebook, index - 1);
			break;
		}
	}
}


int	PhoneBook::getNbrContacts(void) const {
	return this->_nbrContacts;
}


int	PhoneBook::getIndex(void) const {
	return this->_index;
}

void	PhoneBook::getContact(const PhoneBook& phonebook, int pos) {
	std::cout << "Fist Name: " << phonebook._contacts[pos].getFirstName() << std::endl;
	std::cout << "Last Name: " << phonebook._contacts[pos].getLastName() << std::endl;
	std::cout << "Nickname: " << phonebook._contacts[pos].getNickname() << std::endl;
	std::cout << "Phone Number: " << phonebook._contacts[pos].getPhoneNbr() << std::endl;
	std::cout << "Darkest Secret: " << phonebook._contacts[pos].getDarkestSecret() << std::endl;
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

