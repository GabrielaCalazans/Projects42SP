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
	// Test: Object construction
	std::cout << std::endl << "**** Object construction tests ***" << std::endl;
	ClapTrap a("A");
	ClapTrap b("B");
	ScavTrap c("C");
	FragTrap d("D");
	FragTrap e;

	std::cout << std::endl;
	a.getStatus();
	b.getStatus();
	c.getStatus();
	d.getStatus();
	e.getStatus();

	std::cout << "-----------" << std::endl;

	// Test: Basic attack and repair
	std::cout << std::endl << "**** Basic attack and repair tests ***" << std::endl;

	std::cout << std::endl << " ** ClapTrap A attacks ClapTrap B ** " << std::endl;
	a.attack("B");
	b.takeDamage(a.getAttackDamage());

	std::cout << std::endl << " ** ClapTrap B attacks FragTrap D ** " << std::endl;
	b.attack("D");
	d.takeDamage(b.getAttackDamage());

	std::cout << std::endl << " ** ScavTrap C attacks ClapTrap A ** " << std::endl;
	c.attack("A");
	a.takeDamage(c.getAttackDamage());

	std::cout << std::endl << " ** ScavTrap C attacks FragTrap D ** " << std::endl;
	c.attack("D");
	d.takeDamage(c.getAttackDamage());

	std::cout << std::endl << " ** FragTrap D attacks ScavTrap C ** " << std::endl;
	d.attack("C");
	c.takeDamage(d.getAttackDamage());

	std::cout << std::endl << " ** FragTrap D requests a high five ** " << std::endl;
	d.highFivesGuys();

	std::cout << std::endl << " ** ClapTrap B repairs itself ** " << std::endl;
	b.beRepaired(1);

	// Test: Special abilities and methods
	std::cout << std::endl << "**** Special abilities and methods tests ***" << std::endl;

	std::cout << " ** ScavTrap C enters guard gate mode ** " << std::endl;
	c.guardGate();

	std::cout << std::endl << " ** FragTrap D repairs itself ** " << std::endl;
	d.beRepaired(5);

	std::cout << std::endl << " ** FragTrap E requests a high five ** " << std::endl;
	e.highFivesGuys();

	std::cout << "-----------" << std::endl << std::endl;

	// Test: Final status of all objects
	std::cout << std::endl << "**** Final status of all objects ***" << std::endl;
	a.getStatus();
	b.getStatus();
	c.getStatus();
	d.getStatus();
	e.getStatus();

	return (0);
}

