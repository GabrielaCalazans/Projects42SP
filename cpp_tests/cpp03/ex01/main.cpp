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
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	// Test construction of objects
	std::cout << std::endl << "**** Object construction tests ***" << std::endl;
	ClapTrap a("A");
	ClapTrap b("B");
	ScavTrap c("C");
	ScavTrap d;

	std::cout << std::endl << "**** Initial State Check ***" << std::endl;
	a.getStatus();
	b.getStatus();
	c.getStatus();
	d.getStatus();

	// Test attack and damage functionality
	std::cout << std::endl << "**** Attack and Damage Tests ***" << std::endl;
	std::cout << "-----------" << std::endl;
	
	std::cout  << std::endl << " ** ClapTrap A attacks ClapTrap B  ** " << std::endl;
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(1);

	std::cout << std::endl << " ** ScavTrap C attacks ClapTrap A ** " << std::endl;
	c.attack("A");
	a.takeDamage(c.getAttackDamage());

	std::cout << std::endl << " ** ScavTrap C attacks ClapTrap A again ** " << std::endl;
	c.attack("A");
	a.takeDamage(c.getAttackDamage());

	// Test specific ScavTrap behavior
	std::cout << std::endl << "**** ScavTrap Gatekeeper Mode Test ***" << std::endl;
	c.guardGate();

	// Test when an attacker has no energy or is already destroyed
	std::cout << std::endl << "**** Energy and Destruction Tests ***" << std::endl;
	
	// Reduce ClapTrap B's energy to 0 for testing
	std::cout << " ** Reducing ClapTrap B's energy to 0 ** " << std::endl;
	for (int i = 0; i < 10; ++i) {
		b.attack("C");  // Each attack will consume 1 energy point
	}
	b.getStatus();
	
	std::cout << " ** ClapTrap B tries to attack ScavTrap C with no energy left ** " << std::endl;
	b.attack("C");  // This attack should fail due to lack of energy

	// Check that ScavTrap C did not take damage from the failed attack
	c.getStatus();

	std::cout << " ** ScavTrap C repairs itself ** " << std::endl;
	c.beRepaired(10);

	std::cout << " ** ScavTrap D goes into Gatekeeper mode ** " << std::endl;
	d.guardGate();
	std::cout << "-----------" << std::endl << std::endl;

	// Final state check to verify the integrity after all operations
	std::cout << std::endl << "**** Final State Check ***" << std::endl;
	a.getStatus();
	b.getStatus();
	c.getStatus();
	d.getStatus();

	return (0);
}
