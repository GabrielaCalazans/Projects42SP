/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceInFile.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:39:16 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/23 22:59:39 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//  Default Constructor
ClapTrap::ClapTrap(void) {
	this->_name = "Who am I?";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap default constructor called. Name: " << _name << std::endl;

	return ;
}

//  Parameterized Constructor
ClapTrap::ClapTrap(const std::string& name) {
		this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap parameterized constructor called. Name: " << _name << std::endl;
	return ;
}

//  Copy Constructor
ClapTrap::ClapTrap(const ClapTrap &obj) {
	std::cout << "ClapTrap copy constructor called." << std::endl;
	*this = obj;
	return ;
}

// Assignment Operator
ClapTrap& ClapTrap::operator=(const ClapTrap &obj) {
	if (this != &obj) {
		this->_name = obj.getName();
		this->_hitPoints = obj.getHitPoints();
		this->_energyPoints = obj.getEnergyPoints();
		this->_attackDamage = obj.getAttackDamage();
	}
	std::cout << "ClapTrap assignment operator called. Name: " << _name << std::endl;
	return *this;
}


ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << this->_name << " destructed." << std::endl;
	return ;
}

std::string		ClapTrap::getName(void) const {
	return(this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const {
	return(this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const {
	return(this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return(this->_attackDamage);
}


void	ClapTrap::attack(const std::string& target) {
	std::string	word;

	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
		
	}
	else if (this->_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy left!" << std::endl;
	} else {
		this->_energyPoints--;
		word = this->_attackDamage < 2 ? " point of damage!" : " points of damage!";
		std::cout << "ClapTrap " << this->getName() << " attacks " << target 
				<< ", causing " << this->getAttackDamage() << word << std::endl;
	}
	return ;
}


void	ClapTrap::takeDamage(unsigned int amount) {
	
	if (this->_hitPoints < 1) {
		std::cout << "ClapTrap " << this->getName() << " is dead and took 0 points of damage" << std::endl;
		return ;
	} else if (this->_hitPoints < amount) {
		std::cout << "ClapTrap " << this->getName() << " tokes " << amount << " points of damage and died" << std::endl;
		this->_hitPoints = 0;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->getName() << " takes " << amount << " points of damage! Current HP: " << this->_hitPoints << std::endl;
}


void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy or is already destroyed and can't repair!" << std::endl;
		return;
	}

	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << "ClapTrap " <<  this->getName() << " repairs itself for " << amount << " points! Current HP: " << _hitPoints << std::endl;
}


void	ClapTrap::getStatus(void)
{
	std::cout << "ClapTrap " << this->getName() << " status:" << std::endl
		<< "Hit points: " << this->getHitPoints() << std::endl
		<< "Energy points: " << this->getEnergyPoints() << std::endl
		<< "Attack damage: " << this->getAttackDamage() << std::endl << std::endl;
}
