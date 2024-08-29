/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:15:03 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/28 19:59:43 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//  Default Constructor
ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "ScavTrap default constructor called." << std::endl;
	this->_name = "Who am I?";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

//  Parameterized Constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap parameterized constructor called. Name: " << this->_name << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj.getName()) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

// Assignment Operator
ScavTrap& ScavTrap::operator=(const ScavTrap &obj) {
	if (this != &obj) {
		this->_name = obj.getName();
		this->_hitPoints = obj.getHitPoints();
		this->_energyPoints = obj.getEnergyPoints();
		this->_attackDamage = obj.getAttackDamage();
	}
	std::cout << "ScavTrap assignment operator called. Name: " << this->_name << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructed called." << std::endl;
	return ;
}


void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints < 1 || this->_energyPoints < 1)
		return ;
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is in Gate keeper mode" << std::endl;
}
