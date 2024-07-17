/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:40:04 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/16 15:23:02 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact() {
	std::cout << "Contact Constructor called" << std::endl;
	Contact::phoneNbr = 0;

	return;
}


Contact::~Contact() {
	std::cout << "Contact Destructor called" << std::endl;

	return;
}

