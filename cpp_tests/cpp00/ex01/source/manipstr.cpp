/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipstr.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:15:44 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/27 21:51:17 by gacalaza         ###   ########.fr       */
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
		std::cout << "Invalid character \'" << phoneNumber[pos] << "\'. ";
		return false;
	}
	int digitCount = 0;
	for (size_t i = 0; i < phoneNumber.length(); ++i) {
		if (std::isdigit(phoneNumber[i])) {
			digitCount++;
		}
	}

	if (digitCount < 6) {
		std::cout << "The phone number must have at least 6 digits. ";
		return false;
	}

	return true;
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


std::string rightAlignText(const std::string& text, size_t width, int check) {
	if (text.length() >= width && check == 1) {
		return text.substr(0, width - 1) + ".";
	}
	size_t padding = width - text.length();
	return std::string(padding, ' ') + text;
}

void	PhoneBook::displayContacts() const {
	size_t width = 10;
	std::cout << rightAlignText("Index", width, 0) << "|"
			<< rightAlignText("First Name", width, 0) << "|"
			<< rightAlignText("Last Name", width, 0) << "|"
			<< rightAlignText("Nickname", width, 0) << "|" << std::endl;
	
	for (int i = 0; i <= getNbrContacts(); ++i) {
		const Contact& contact = _contacts[i];
		if (getNbrContacts() != 7 && getNbrContacts() == i)
			break;
		std::cout << std::setfill(' ') << std::setw(width) << i + 1 << "|"
				<< std::setfill(' ') << std::setw(width) << (contact.getFirstName().length() > 9 ? contact.getFirstName().substr(0, 9) + "." : contact.getFirstName()) << "|"
				<< std::setfill(' ') << std::setw(width) << (contact.getLastName().length() > 9 ? contact.getLastName().substr(0, 9) + "." : contact.getLastName()) << "|"
				<< std::setfill(' ') << std::setw(width) << (contact.getNickname().length() > 9 ? contact.getNickname().substr(0, 9) + "." : contact.getNickname()) << "|" << std::endl;
	}
}
