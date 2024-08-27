/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:51:05 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/23 22:43:21 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void ) {

	ClapTrap marvin("Marvin");
	ClapTrap wallE("WALL-E");


	ClapTrap	trapCopy(wallE);
	ClapTrap	nameless;

	marvin.getStatus();
	wallE.getStatus();
	trapCopy.getStatus();
	nameless.getStatus();
	nameless = wallE;
	marvin.attack(nameless.getName());
	marvin.getStatus();
	nameless.takeDamage(marvin.getAttackDamage());
	nameless.beRepaired(1);
	nameless.getStatus();

	return (0);
}


// {
// 	ClapTrap	a("A");
// 	ClapTrap	b("B");

// 	std::cout << std::endl;
// 	a.getStatus();
// 	b.getStatus();

// 	std::cout << "-----------" << std::endl;
// 	a.attack("B");
// 	b.takeDamage(a.getAttackDamage());
// 	b.beRepaired(1);
// 	b.attack("A");
// 	a.takeDamage(b.getAttackDamage());
// 	std::cout << "-----------" << std::endl << std::endl;

// 	a.getStatus();
// 	b.getStatus();
// }