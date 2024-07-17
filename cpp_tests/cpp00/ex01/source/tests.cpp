/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:59:48 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/15 18:02:49 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "PhoneBook.hpp"

int	main() {
	PhoneBook	firstCall("firstCall");

	showMenu();

	std::cout << "Number of contacts: " << PhoneBook::getNbrContacts() << std::endl;
	


	return (0);
}
