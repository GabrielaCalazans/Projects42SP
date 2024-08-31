/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:09:08 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/30 21:32:23 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

//  Default Constructor
AAnimal::AAnimal(void) {
	std::cout << "AAnimal default constructor called" << std::endl;
	this->_type = "Animalia";
	return ;
}

//  Copy Constructor
AAnimal::AAnimal(const AAnimal &obj) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

// Assignment Operator
AAnimal& AAnimal::operator=(const AAnimal &obj) {
	std::cout << "AAnimal assignment operator called" << std::endl;
	if (this != &obj) {
		this->_type = obj.getType();
	}
	return *this;
}


AAnimal::~AAnimal(void) {
	std::cout << "AAnimal destructor called" << std::endl;
	return ;
}


std::string AAnimal::getType(void) const {
	return (this->_type);
}


void	AAnimal::makeSound(void) const
{
	std::cout << "An indistinct sound echoes through the world!" << std::endl;
}
