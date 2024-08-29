/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:15:03 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/28 21:53:34 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//  Default Constructor
FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "FragTrap default constructor called." << std::endl;
	this->_name = "Who am I?";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

//  Parameterized Constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap parameterized constructor called. Name: " << this->_name << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj.getName()) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

// Assignment Operator
FragTrap& FragTrap::operator=(const FragTrap &obj) {
	if (this != &obj) {
		this->_name = obj.getName();
		this->_hitPoints = obj.getHitPoints();
		this->_energyPoints = obj.getEnergyPoints();
		this->_attackDamage = obj.getAttackDamage();
	}
	std::cout << "FragTrap assignment operator called. Name: " << this->_name << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructed called." << std::endl;
	return ;
}


void	FragTrap::attack(const std::string& target)
{
	if (this->_hitPoints < 1 || this->_energyPoints < 1)
		return ;
	this->_energyPoints--;
	std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " requests a positive high five!" << std::endl;
}
