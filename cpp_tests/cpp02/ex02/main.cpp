/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:51:05 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/28 16:28:10 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	
	std::cout << std::endl << "**** More tests ****" << std::endl << std::endl;
	Fixed c(2);
	Fixed d(b); // Test copy

	std::cout << "Initial values:" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;

	// Test Increment/Decrement operators
	std::cout << "\nIncrement and Decrement operators:" << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	// Test Arithmetic operator
	std::cout << "\nArithmetic operators:" << std::endl;
	std::cout << "b + c = " << (b + c) << std::endl;
	std::cout << "b - c = " << (b - c) << std::endl;
	std::cout << "b * c = " << (b * c) << std::endl;
	std::cout << "b / c = " << (b / c) << std::endl;

	// Test Comparison operator
	std::cout << "\nComparison operators:" << std::endl;
	std::cout << "b > c: " << (b > c) << std::endl;
	std::cout << "b < c: " << (b < c) << std::endl;
	std::cout << "b >= c: " << (b >= c) << std::endl;
	std::cout << "b <= c: " << (b <= c) << std::endl;
	std::cout << "b == c: " << (b == c) << std::endl;
	std::cout << "b != c: " << (b != c) << std::endl;

	// Test Static member functions
	std::cout << "\nMin and Max functions:" << std::endl;
	std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;

	// Test member functions with const reference
	const Fixed &e = Fixed(1.23f);
	const Fixed &f = Fixed(4.56f);
	std::cout << "min(e, f): " << Fixed::min(e, f) << std::endl;
	std::cout << "max(e, f): " << Fixed::max(e, f) << std::endl;

	return (0);
}

// $> ./a.out
// 0
// 0.00390625
// 0.00390625
// 0.00390625
// 0.0078125
// 10.1016
// 10.1016
// $>