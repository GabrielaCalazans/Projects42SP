/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:04:09 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/20 18:49:10 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "PhoneBook.hpp"


static void	showMenu() {
	
	std::string text = "  PhoneBook  ";
	int width = 40;
	int text_length = text.length();
	int fill_length = (width - text_length) / 2;

	std::cout << "\n" << std::setfill('*') << std::setw(fill_length + text_length) << text;
	std::cout << std::setfill('*') << std::setw(fill_length) << "" << std::endl;


	std::cout << "\nType ADD to save a new contact" << std::endl;
	std::cout << "Type SEARCH to save a new contact" << std::endl;
	std::cout << "Type EXIT to quit the program\n" << std::endl;
}

void	tests(PhoneBook& phonebook, int pos) {
	phonebook.getContact(phonebook, pos);
}


void	search(void) {
	int	width = 10;
	std::string index = "index";
	std::string firstName = "first name";
	std::string lastName = "last name";
	std::string nickname = "nickname";
	int index_length = index.length();
	int fill_length = (width - index_length) / 2;

	std::cout << "\n" << std::setfill(' ') << std::setw(fill_length + index.length()) << index;
	std::cout << std::setfill(' ') << std::setw(fill_length) << "|";
	std::cout << std::setfill(' ') << std::setw(fill_length + firstName.length()) << firstName;
	std::cout << std::setfill(' ') << std::setw(fill_length) << "|";
	std::cout << std::setfill(' ') << std::setw(fill_length + lastName.length()) << lastName;
	std::cout << std::setfill(' ') << std::setw(fill_length) << "|";
	std::cout << std::setfill(' ') << std::setw(fill_length + nickname.length()) << nickname;
	std::cout << std::setfill(' ') << std::setw(fill_length) << "|" << std::endl;
}


void	PhoneBook::displayContacts() const {
	std::cout << std::setfill(' ') << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << std::endl;
	
	for (int i = 0; i < getNbrContacts(); ++i) {
		const Contact& contact = contacts[i];
		std::cout << std::setw(10) << i << "|"
				<< std::setw(10) << (contact.getFirstName().length() > 9 ? contact.getFirstName().substr(0, 9) + "." : contact.getFirstName()) << "|"
				<< std::setw(10) << (contact.getLastName().length() > 9 ? contact.getLastName().substr(0, 9) + "." : contact.getLastName()) << "|"
				<< std::setw(10) << (contact.getNickname().length() > 9 ? contact.getNickname().substr(0, 9) + "." : contact.getNickname()) << std::endl;
	}
}



int	PhoneBook::_nbrContacts = 0;

int	main() {
	PhoneBook	phonebook;
	std::string	prompt = "";
	int			i = 1;
	
	while (i)
	{
		showMenu();
		std::cin >> prompt;
		if (!prompt.compare("ADD")) {
			phonebook.setContact();
			tests(phonebook, phonebook.getNbrContacts()-1);
		}
		else if (!prompt.compare("SEARCH"))
			phonebook.displayContacts();
		else if (!prompt.compare("EXIT"))
			i = 0;
		else
			std::cout << "Invalid command." << std::endl;
	}
	

	return (0);
}

