/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:26:50 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/30 17:43:12 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain	*_brain;

	public:
		Cat(void);
		Cat(const Cat &obj);
		Cat& operator=(const Cat &obj);
		~Cat(void);

		void		makeSound(void) const;
		Brain*		getBrain(void) const;
		std::string	getBrainIdea(int index) const;
		void		setBrainIdea(int index, std::string idea);
};

#endif