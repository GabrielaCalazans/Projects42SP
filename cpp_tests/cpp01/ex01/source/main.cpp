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
	int	hordeSize = 0;
	Zombie*	myZombieHorde = zombieHorde(hordeSize, "CrazyZombie");

	for (int i = 0; i < hordeSize; ++i)
	{
		std::cout << "Zombie " << i + 1 << ":\t";
		myZombieHorde[i].announce();
	}

	delete myZombieHorde;

	std::cout << "\n" << std::endl;
	std::cout << "******* NEW TEST *******" << std::endl;

	hordeSize = 6;
	myZombieHorde = zombieHorde(hordeSize, "CrazyZombie");

	for (int i = 0; i < hordeSize; ++i)
	{
		std::cout << "Zombie " << i + 1 << ":\t";
		myZombieHorde[i].announce();
	}

	delete myZombieHorde;

	return 0;
}
