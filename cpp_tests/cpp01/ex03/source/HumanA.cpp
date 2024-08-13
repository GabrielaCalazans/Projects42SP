/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:56:59 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/10 18:29:56 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "Weapon.hpp"


HumanA::HumanA(std::string	type)
{
	this->_weapon.setType(type);
	return;
}


HumanA::~HumanA()
{
	return;
}

void	HumanA::attack() {
	std::cout << this->getName() << " attacks with their " << this->getType() << std::endl;
}

