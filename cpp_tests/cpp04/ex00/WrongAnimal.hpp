/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:39:40 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/29 23:39:40 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

class	WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &obj);
		WrongAnimal& operator=(const WrongAnimal &obj);
		~WrongAnimal(void);

		std::string	getType(void) const;
		void		makeSound(void) const;
};

#endif
