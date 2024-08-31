/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:38:04 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/30 21:41:15 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal {
protected:
	std::string	_type;

public:
	AAnimal(void);
	AAnimal(const AAnimal &obj);
	AAnimal& operator=(const AAnimal &obj);
	virtual ~AAnimal(void);

	std::string		getType(void) const;
	virtual void	makeSound(void) const = 0;
};



#endif
