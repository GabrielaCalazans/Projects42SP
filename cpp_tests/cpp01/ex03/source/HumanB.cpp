/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:39:16 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/21 20:30:12 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanB.hpp"


HumanB::HumanB(std::string name) {
	this->_name = name;
	return;
}

HumanB::~HumanB() {
	return;
}

std::string	HumanB::getName(void) const {
	return this->_name;
}

void	HumanB::setName(std::string name) {
	this->_name = name;
}

// void	HumanB::attack() {
// 	std::cout << this->getName() << " attacks with their " << this->getType() << std::endl;
// }
