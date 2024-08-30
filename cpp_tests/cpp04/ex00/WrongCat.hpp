/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:40:37 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/29 23:40:37 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat &obj);
		WrongCat& operator=(const WrongCat &obj);
		~WrongCat(void);

		void	makeSound(void) const;
};

#endif
