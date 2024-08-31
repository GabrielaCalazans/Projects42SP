/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:26:53 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/30 18:29:28 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//  Default Constructor
Dog::Dog(void) : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	return ;
}

//  Copy Constructor
Dog::Dog(const Dog &obj) : _brain(new Brain(*obj.getBrain())) {
	std::cout << "Dog copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}


// Assignment Operator
Dog&	Dog::operator=(const Dog &obj) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_type = obj.getType();
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	return ;
}


void	Dog::makeSound(void) const {
	std::cout << "Woof!" << std::endl;
}


Brain*	Dog::getBrain(void) const
{
	return (this->_brain);
}

std::string	Dog::getBrainIdea(int index) const
{
	if (index < 0 || index >= 100)
		return (NULL);
	return (this->getBrain()->getIdea(index));
}

void	Dog::setBrainIdea(int index, std::string idea)
{
	if (index < 0 || index >= 100)
	{
		std::cout << "Index is out of range" << std::endl;
		return ;
	}
	this->getBrain()->setIdea(index, idea);
}