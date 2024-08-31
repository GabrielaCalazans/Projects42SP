/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:26:57 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/30 17:43:42 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain	*_brain;

	public:
		Dog(void);
		Dog(const Dog &obj);
		Dog& operator=(const Dog &obj);
		~Dog(void);

		void		makeSound(void) const;
		Brain*		getBrain(void) const;
		std::string	getBrainIdea(int index) const;
		void		setBrainIdea(int index, std::string idea);
};

#endif