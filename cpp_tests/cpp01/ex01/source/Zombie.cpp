/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:39:16 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/09 21:39:16 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"
#include <string>

Zombie::Zombie(/* args */)
{
	return;
}


Zombie::~Zombie()
{
	std::cout << this->getName() << " is destroyed." << std::endl;
	return;
}


void	Zombie::announce(void)
{
	std::cout << this->getName() << ": "
	<< "BraiiiiiiinnnzzzZ..." << std::endl;
}
