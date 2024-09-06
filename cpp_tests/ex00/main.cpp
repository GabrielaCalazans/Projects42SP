/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:51:05 by gacalaza          #+#    #+#             */
/*   Updated: 2024/09/05 17:05:58 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat marvin("Marvin");
	Bureaucrat wallE("WALL-E");

	std::cout << std::endl << "**** Object construction tests ***" << std::endl;
	// Test the copy constructor
	Bureaucrat trapCopy(wallE);
	// Test the default constructor
	Bureaucrat nameless;

	std::cout << std::endl << "**** Initial state test ***" << std::endl;
	marvin.getStatus();
	wallE.getStatus();
	trapCopy.getStatus();
	nameless.getStatus();

	std::cout << std::endl << "**** Assignment test ***" << std::endl;
	nameless = marvin;  // Test the assignment operator
	nameless.getStatus(); // Check if the assignment was correct

	std::cout << std::endl << "**** Test attack and damage ***" << std::endl;
	marvin.attack(nameless.getName());
	marvin.getStatus(); // Check state after attack

	nameless.takeDamage(marvin.getAttackDamage());
	nameless.getStatus(); // Check state after taking damage

	std::cout << std::endl << "**** Test repair ***" << std::endl;
	nameless.beRepaired(1);
	nameless.getStatus(); // Check state after repair

	std::cout << std::endl << "**** Test attack with no energy ***" << std::endl;
	for (int i = 0; i < 10; i++) {
		wallE.attack("target"); // Should fail when energy runs out
	}
	wallE.attack("target"); // Test with no energy, should fail
	wallE.getStatus();

	std::cout << std::endl << "**** Test repair with no energy ***" << std::endl;
	for (int i = 0; i < 10; i++) {
		wallE.beRepaired(1); // Should fail when energy runs out
	}
	wallE.beRepaired(1); // Test with no energy, should fail
	wallE.getStatus();

	std::cout << std::endl << "**** Test attack when destroyed ***" << std::endl;
	wallE.takeDamage(100); // Exceed hit points, causing destruction
	wallE.attack("target"); // Should fail because ClapTrap is destroyed
	wallE.getStatus();

	std::cout << std::endl << "**** Test repair when destroyed***" << std::endl;
	wallE.beRepaired(5); // Should fail because ClapTrap is destroyed
	wallE.getStatus();

	return (0);
}
