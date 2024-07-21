/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipstr.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:15:44 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/20 21:48:57 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"

bool	isValidPhoneNumber(const std::string& phoneNumber) {
	std::string allowedChars = "0123456789()-+";

	bool result = phoneNumber.find_first_not_of(allowedChars) == std::string::npos;
	if (!result) {
		size_t pos = phoneNumber.find_first_not_of(allowedChars);
		std::cout << "Invalid character \'" << phoneNumber[pos];
	}
	return result;
}

bool	containsForbiddenCharacter(const std::string& str) {
	return str.find(' ') != std::string::npos;
}