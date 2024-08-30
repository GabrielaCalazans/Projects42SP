/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:26:46 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/29 23:26:46 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//  Default Constructor
Cat::Cat(void) : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	return ;
}

//  Copy Constructor
Cat::Cat(const Cat &obj) {
	std::cout << "Cat copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

// Assignment Operator
Cat&	Cat::operator=(const Cat &obj) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_type = obj.getType();
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	return ;
}


void	Cat::makeSound(void) const {
	std::cout << "Meow!" << std::endl;
}
