/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:04:09 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/23 18:29:29 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "PhoneBook.hpp"


static void	showMenu() {
	
	std::string text = "  PhoneBook  ";
	int width = 30;
	int text_length = text.length();
	int fill_length = (width - text_length) / 2;

	std::cout << "\n" << std::setfill('*') << std::setw(fill_length + text_length) << text;
	std::cout << std::setfill('*') << std::setw(fill_length) << "" << std::endl;


	std::cout << "\nType ADD to save a new contact" << std::endl;
	std::cout << "Type SEARCH to display and search a contact" << std::endl;
	std::cout << "Type EXIT to quit the program\n" << std::endl;
}

void	tests(PhoneBook& phonebook, int pos) {
	phonebook.getContact(phonebook, pos);
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
			phonebook.searchContact(phonebook);
		else if (!prompt.compare("EXIT"))
			i = 0;
		else
			std::cout << "Invalid command." << std::endl;
	}
	

	return (0);
}

