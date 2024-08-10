/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:51:05 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/09 21:51:05 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

std::string	Zombie::getName(void) const
{
	return (this->_name);
}


void	Zombie::setName(std::string name)
{
	this->_name = name;
}


int	main()
{
	Zombie*	myZombie = newZombie("Gabriela Zombie - heap");
	myZombie->announce();
	delete myZombie;

	std::cout << "\n" << std::endl;

	randomChump("Gabriela randomChump - stack");
	std::cout << "\n" << std::endl;
	return 0;
}
