/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:04:09 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/11 20:06:18 by gacalaza         ###   ########.fr       */
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


int	main() {
	PhoneBook	firstCall("firstCall");

	showMenu();

	std::cout << "Number of contacts: " << PhoneBook::getNbrContacts() << std::endl;


	return (0);
}

