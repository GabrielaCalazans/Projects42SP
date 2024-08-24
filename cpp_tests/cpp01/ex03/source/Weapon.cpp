/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:36:41 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/23 18:01:14 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string name) {
	this->setType(name);
	return;
}

Weapon::Weapon(void) {
	return;
}

Weapon::~Weapon() {
	return;
}


std::string	Weapon::getType(void) const {
	return (this->_type);
}


void	Weapon::setType(std::string type) {
	this->_type = type;
}

