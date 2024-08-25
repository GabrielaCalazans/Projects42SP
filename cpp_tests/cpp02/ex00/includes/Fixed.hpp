/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceInFile.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:38:04 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/23 22:12:05 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int					_fixedPoint;
	static const int	_fractionalBits = 8;

public:
	Fixed(void);
	Fixed(const Fixed& other);
	~Fixed(void);
	Fixed&	operator = (const Fixed& other);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

// ◦ A default constructor that initializes the fixed-point number value to 0.
// ◦ A copy constructor.
// ◦ A copy assignment operator overload.
// ◦ A destructor.
// ◦ A member function int getRawBits( void ) const;
// that returns the raw value of the xed-point value.
// ◦ A member function void setRawBits( int const raw );
// that sets the raw value of the xed-point number.
// };


#endif
