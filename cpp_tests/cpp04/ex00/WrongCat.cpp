/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:40:40 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/30 16:44:05 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "WrongCat";
	return ;
}

WrongCat::WrongCat(const WrongCat &obj) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

WrongCat&	WrongCat::operator=(const WrongCat &obj) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_type = obj.getType();
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

void	WrongCat::makeSound(void) const {
	std::cout << "Wrong meow!" << std::endl;
}
