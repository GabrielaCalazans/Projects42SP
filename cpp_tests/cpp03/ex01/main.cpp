/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:51:05 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/28 19:54:10 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main( void ) {

	ClapTrap	a("A");
	ClapTrap	b("B");
	ScavTrap	c("C");
	ScavTrap	d;

	std::cout << std::endl;
	a.getStatus();
	b.getStatus();
	c.getStatus();
	d.getStatus();

	std::cout << "-----------" << std::endl;
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(1);
	c.attack("A");
	a.takeDamage(c.getAttackDamage());
	c.attack("A");
	a.takeDamage(c.getAttackDamage());
	c.guardGate();
	b.attack("C");
	c.takeDamage(b.getAttackDamage());
	c.beRepaired(10);
	d.guardGate();
	std::cout << "-----------" << std::endl << std::endl;

	a.getStatus();
	b.getStatus();
	c.getStatus();
	d.getStatus();

	return (0);
}
