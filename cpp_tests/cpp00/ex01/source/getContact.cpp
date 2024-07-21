/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getContact.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:36:57 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/20 18:37:12 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"

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

