/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:56:59 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/21 20:30:35 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "Weapon.hpp"


HumanA::HumanA(std::string name, Weapon weapon)
{
	this->_weapon = weapon;
	this->_name = name;
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


void	HumanA::attack() {
	std::cout << this->getName() << " attacks with their " << this->getType() << std::endl;
}

