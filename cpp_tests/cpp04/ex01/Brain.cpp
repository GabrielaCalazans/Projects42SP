/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:38:05 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/31 15:27:38 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	return ;
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Brain&	Brain::operator=(const Brain &obj)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = obj.getIdea(i);
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

std::string	Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return "";
	return (this->_ideas[index]);
}

void	Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index >= 100)
	{
		std::cout << "Index is out of range" << std::endl;
		return ;
	}
	this->_ideas[index] = idea;
}