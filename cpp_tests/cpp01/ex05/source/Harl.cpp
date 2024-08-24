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

#include "Harl.hpp"


Harl::Harl(void) {
	this->_levels[0] = std::make_pair("DEBUG", &Harl::debug);
	this->_levels[1] = std::make_pair("INFO", &Harl::info);
	this->_levels[2] = std::make_pair("WARNING", &Harl::warning);
	this->_levels[3] = std::make_pair("ERROR", &Harl::error);
}


Harl::~Harl(void) {
	return ;
}


void	print_complain(std::string level, std::string complain)
{
	std::cout << "[ " << level << " ]" << std::endl << complain << std::endl << std::endl;
}


void	Harl::debug( void ) {
	print_complain("DEBUG", "Calling function 'minishell()'... Fingers crossed it doesn't blow up!");
}


void	Harl::info( void ) {
	print_complain("INFO", "User 'admin' logged in. Make sure they don't do anything crazy!");
}


void	Harl::warning( void ) {
	print_complain("WARNING", "User 'admin' is attempting to access a restricted area. Are they lost, or are we?");
}


void	Harl::error( void ) {
	print_complain("ERROR", "Application crashed. Somebody grab the defibrillator!");
}


void	Harl::complain( std::string level )
{
	for (int i = 0; i < 4; i++)
	{
		if (level == this->_levels[i].first)
		{
			(this->*_levels[i].second)();
			return ;
		}
	}
}
