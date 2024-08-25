/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceInFile.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:39:16 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/23 22:59:39 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPoint = 0;
	return ;
}


Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	if (this != &other)
		*this = other;
}


Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPoint = other.getRawBits();
	return (*this);
}


Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}



int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}


void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPoint = raw;
}
