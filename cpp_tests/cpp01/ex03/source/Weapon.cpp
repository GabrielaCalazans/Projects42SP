/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:36:41 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/10 18:24:46 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

Weapon::Weapon(/* args */) {
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

