/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:39:16 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/28 16:28:42 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>


Fixed::Fixed(void) {
	this->_fixedPoint = 0;
	return ;
}

Fixed::Fixed(const Fixed& other) {
	if (this != &other)
		*this = other;
}

Fixed::Fixed(const int nbr) {
	this->_fixedPoint = nbr << this->_fractionalBits;
	return ;
}

Fixed::Fixed(const float nbr) {
	this->_fixedPoint = roundf(nbr * 256);
	return ;
}

Fixed::~Fixed(void) {
	return ;
}

 
// Assignment operator
Fixed&	Fixed::operator=(const Fixed& other) {
	if (this != &other)
		this->_fixedPoint = other._fixedPoint;
	return (*this);
}


// Comparison operator
bool	Fixed::operator>(const Fixed &other) const {
	return this->toFloat() > other.toFloat();
}

bool	Fixed::operator<(const Fixed &other) const {
	return this->toFloat() < other.toFloat();
}

bool	Fixed::operator>=(const Fixed &other) const {
	return this->toFloat() >= other.toFloat();
}

bool	Fixed::operator<=(const Fixed &other) const {
	return this->toFloat() <= other.toFloat();
}

bool	Fixed::operator==(const Fixed &other) const {
	return this->toFloat() == other.toFloat();
}

bool	Fixed::operator!=(const Fixed &other) const {
	return this->toFloat() != other.toFloat();
}


// Output operator
std::ostream&	operator<<(std::ostream& lhs, const Fixed& fixed) {
	lhs << fixed.toFloat();
	return (lhs);
}


// Arithmetic operator
Fixed	Fixed::operator+(const Fixed &other) const {
	return this->toFloat() + other.toFloat();
}

Fixed	Fixed::operator-(const Fixed &other) const {
	return this->toFloat() - other.toFloat();
}

Fixed	Fixed::operator*(const Fixed &other) const {
	return this->toFloat() * other.toFloat();
}

Fixed	Fixed::operator/(const Fixed &other) const {
	return this->toFloat() / other.toFloat();
}


// Increment/Decrement operators
Fixed&	Fixed::operator++(void) { // Pre-increment
	++this->_fixedPoint;
	return *this;
}

Fixed	Fixed::operator++(int) { // Post-increment
	Fixed temp(*this);
	++this->_fixedPoint;
	return temp;
}

Fixed&	Fixed::operator--(void) { // Pre-decrement
	--this->_fixedPoint;
	return *this;
}

Fixed	Fixed::operator--(int) { // Post-decrement
	Fixed temp(*this);
	--this->_fixedPoint;
	return temp;
}


// Static member functions
Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	return (a.toFloat() < b.toFloat() ? a : b);
}

// Provides a guarantee that the returned object and the argument will not be modified
const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	return (a.toFloat() < b.toFloat() ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	return (a.toFloat() > b.toFloat() ? a : b);
}

// Provides a guarantee that the returned object and the argument will not be modified
const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	return (a.toFloat() > b.toFloat() ? a : b);
}


// member functions
int		Fixed::getRawBits( void ) const {
	return (this->_fixedPoint);
}


void	Fixed::setRawBits( int const raw ) {
	this->_fixedPoint = raw;
}


float	Fixed::toFloat( void ) const {
	return ((float)this->_fixedPoint / 256);
}


int		Fixed::toInt( void ) const {
	return (this->_fixedPoint / (1 << Fixed::_fractionalBits));
}

