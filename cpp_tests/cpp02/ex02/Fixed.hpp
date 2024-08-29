/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:38:04 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/28 16:27:40 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					_fixedPoint;
	static const int	_fractionalBits = 8;

public:
	Fixed(void);
	Fixed(const Fixed& other);
	Fixed(const int nbr);
	Fixed(const float nbr);
	~Fixed(void);

	Fixed&	operator = (const Fixed& other);

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;

	bool	operator>(const Fixed &other) const;
	bool	operator<(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& lhs, const Fixed& fixed);

#endif

// • A constructor that takes a constant integer as a parameter.
// It converts it to the corresponding xed-point value. The fractional bits value is
// initialized to 8 like in exercise 00.
// • A constructor that takes a constant oating-point number as a parameter.
// It converts it to the corresponding xed-point value. The fractional bits value is
// initialized to 8 like in exercise 00.
// • A member function float toFloat( void ) const;
// that converts the xed-point value to a oating-point value.
// • A member function int toInt( void ) const;
// that converts the xed-point value to an integer value.
// And add the following function to the Fixed class les:
// • An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.