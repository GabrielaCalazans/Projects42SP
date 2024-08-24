/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:56:59 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/23 19:34:14 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "Weapon.hpp"


HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
	this->setName(name);
	return;
}


HumanA::~HumanA()
{
	return;
}

std::string	HumanA::getName(void) const {
	return this->_name;
}


void	HumanA::setName(std::string name) {
	this->_name = name;
}


void	HumanA::attack(void) {
	std::cout << this->getName() << " attacks with their " << this->_weapon.getType() << std::endl;
}

