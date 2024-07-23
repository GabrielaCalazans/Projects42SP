/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setContact.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:37:31 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/20 21:49:35 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "Contact.hpp"
#include "PhoneBook.hpp"

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


void	Contact::setFirstName(void) {
	std::string	result;
	std::string str = "Type the First Name: ";

	std::cout << str << std::endl;
	while (true) {
		std::cin >> result;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (result.empty())
			std::cout << "Invalid. Please try again\n" << str << std::endl;
		else {
			this->_firstName = result;
			break;
		}
	}
}


void	Contact::setLastName(void) {
	std::string	nLastName;
	std::string str = "Type the Last Name: ";
	
	std::cout << str << std::endl;
	while (true) {
		std::cin >> nLastName;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (!nLastName.empty()) {
			this->_lastName = nLastName;
			break;
		}
		else
			std::cout << "Invalid. Please try again\n" << str << std::endl;
	}
}


void	Contact::setNickname(void) {
	std::string	newNickname;
	std::string str = "Type a Nickname: ";
	
	std::cout << str << std::endl;
	while (true) {
		std::cin >> newNickname;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (newNickname.empty())
			std::cout << "Invalid. Please try again\n" << str << std::endl;
		else {
			this->_nickname = newNickname;
			break;
		}
	}
}


void	Contact::setDarkestSecret(void) {
	std::string	newDarkestSecret;
	std::string str = "Type a Darkest Secret: ";
	
	std::cout << str << std::endl;
	while (true) {
		std::getline(std::cin, newDarkestSecret);
		if (!newDarkestSecret.empty()) {
			this->_darkestSecret = newDarkestSecret;
			break;
		}
		else
			std::cout << "Invalid. Please try again\n" << str << std::endl;
	}
}


void	Contact::setPhoneNbr(void) {
	std::string	newPhoneNbr;
	std::string str = "Type a Phone Number (Only numbers allowed): ";
	
	std::cout << str << std::endl;
	while (true) {
		std::cin >> newPhoneNbr;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if ((!newPhoneNbr.empty() && isValidPhoneNumber(newPhoneNbr))) {
			this->_phoneNbr = newPhoneNbr;
			return ;
		}
		else
			std::cout << "\'. Please try again\n" << str << std::endl;
	}
}

