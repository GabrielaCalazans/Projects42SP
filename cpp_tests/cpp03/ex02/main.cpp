/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:51:05 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/28 21:47:08 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	a("A");
	ClapTrap	b("B");
	ScavTrap	c("C");
	FragTrap	d("D");
	FragTrap	e;

	std::cout << std::endl;
	a.getStatus();
	b.getStatus();
	c.getStatus();
	d.getStatus();
	e.getStatus();

	std::cout << "-----------" << std::endl;
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	b.attack("D");
	d.takeDamage(b.getAttackDamage());
	c.attack("A");
	a.takeDamage(c.getAttackDamage());
	c.attack("D");
	d.takeDamage(c.getAttackDamage());
	d.attack("C");
	c.takeDamage(d.getAttackDamage());
	d.highFivesGuys();
	b.beRepaired(1);
	c.guardGate();
	d.beRepaired(5);
	e.highFivesGuys();
	std::cout << "-----------" << std::endl << std::endl;

	a.getStatus();
	b.getStatus();
	c.getStatus();
	d.getStatus();
	e.getStatus();
}

