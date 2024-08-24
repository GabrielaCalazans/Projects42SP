/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:39:16 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/23 19:25:07 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanB.hpp"
# include "Weapon.hpp"


HumanB::HumanB(std::string name) {
	this->setName(name);
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

void	HumanB::attack() {
	if (this->_weapon)
		std::cout << this->getName() << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->getName() << " has no weapon" << std::endl;
}


void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

