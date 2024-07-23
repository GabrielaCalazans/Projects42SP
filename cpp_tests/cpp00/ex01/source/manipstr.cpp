/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipstr.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:15:44 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/23 18:37:40 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

bool	isValidPhoneNumber(const std::string& phoneNumber) {
	std::string allowedChars = "0123456789()-+";

	bool result = phoneNumber.find_first_not_of(allowedChars) == std::string::npos;
	if (!result) {
		size_t pos = phoneNumber.find_first_not_of(allowedChars);
		std::cout << "Invalid character \'" << phoneNumber[pos] << "\'";
	}
	return result;
}

bool	containsForbiddenCharacter(const std::string& str) {
	return str.find(' ') != std::string::npos;
}

std::string	centerText(const std::string& text, size_t width) {
	int padding = width - text.length();
	int padLeft = padding / 2;
	int padRight = padding - padLeft;
	return std::string(padLeft, ' ') + text + std::string(padRight, ' ');
}


void	PhoneBook::displayContacts() const {
	size_t width = 10;
	std::cout << centerText("Index", width) << "|"
			<< centerText("First Name", width) << "|"
			<< centerText("Last Name", width) << "|"
			<< centerText("Nickname", width) << std::endl;
	
	for (int i = 0; i < getNbrContacts(); ++i) {
		const Contact& contact = contacts[i];
		std::cout << std::setfill(' ') << std::setw(width) << i + 1 << "|"
				<< std::setfill(' ') << std::setw(width) << (contact.getFirstName().length() > 9 ? contact.getFirstName().substr(0, 9) + "." : contact.getFirstName()) << "|"
				<< std::setfill(' ') << std::setw(width) << (contact.getLastName().length() > 9 ? contact.getLastName().substr(0, 9) + "." : contact.getLastName()) << "|"
				<< std::setfill(' ') << std::setw(width) << (contact.getNickname().length() > 9 ? contact.getNickname().substr(0, 9) + "." : contact.getNickname()) << std::endl;
	}
}
