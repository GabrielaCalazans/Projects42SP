/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:31:22 by gacalaza          #+#    #+#             */
/*   Updated: 2024/06/25 18:47:40 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(/* args */) {
	std::cout << "Constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook() {
	std::cout << "Destructor called" << std::endl;
	return ;
}


int	main() {
	PhoneBook	instance;

	return (0);
}