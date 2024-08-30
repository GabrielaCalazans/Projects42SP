/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:39:36 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/29 23:39:36 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "Wrong Animal default constructor called" << std::endl;
	this->_type = "";
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
	std::cout << "Wrong Animal copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &obj) {
	std::cout << "Wrong Animal copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_type = obj.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Wrong Animal destructor called" << std::endl;
	return ;
}

std::string WrongAnimal::getType(void) const {
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "Generic wrong animal sound!" << std::endl;
}
