/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:09:08 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/29 23:09:08 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//  Default Constructor
Animal::Animal(void) {
	std::cout << "Animal default constructor called" << std::endl;
	this->_type = "Animalia";
	return ;
}

//  Copy Constructor
Animal::Animal(const Animal &obj) {
	std::cout << "Animal copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

// Assignment Operator
Animal& Animal::operator=(const Animal &obj) {
	if (this != &obj) {
		this->_type = obj.getType();
	}
	std::cout << "Animal assignment operator called" << std::endl;
	return *this;
}


Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
	return ;
}


std::string Animal::getType(void) const {
	return (this->_type);
}


void	Animal::makeSound(void) const
{
	std::cout << "An indistinct sound echoes through the world!" << std::endl;
}
