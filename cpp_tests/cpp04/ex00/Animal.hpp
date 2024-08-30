/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:38:04 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/28 19:15:20 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
	std::string	_type;

public:
	Animal(void);
	Animal(const Animal &obj);
	Animal& operator=(const Animal &obj);
	virtual ~Animal(void);

	std::string	getType(void) const;
	virtual void	makeSound(void) const;
};



#endif
