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
#include <cmath>


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
		this->_fixedPoint = other._fixedPoint;
	return (*this);
}


Fixed::Fixed(const int nbr) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = nbr << this->_fractionalBits;
	return ;
}


Fixed::Fixed(const float nbr) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = roundf(nbr * 256);
	return ;
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


float	Fixed::toFloat( void ) const {
	return ((float)this->_fixedPoint / 256);
}


int		Fixed::toInt( void ) const {
	return (this->_fixedPoint / (1 << Fixed::_fractionalBits));
}


std::ostream& operator<<(std::ostream& lhs, const Fixed& fixed)
{
	std::cout << "ostream operator called" << std::endl;
	lhs << fixed.toFloat();
	return (lhs);
}
