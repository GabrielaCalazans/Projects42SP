/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:51:05 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/10 17:29:18 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


void	updateValue(int& ref) {
	ref = 20;
}

int	main() {
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "The address of the string variable is: " << &string << std::endl;
	std::cout << "The address of the stringPTR variable is: " << &stringPTR << std::endl;
	std::cout << "The address of the stringREF variable is: " << &stringREF << std::endl;

	std::cout << "---------------------------------------------" << std::endl;

	std::cout << "The value of the string variable is: " << string << std::endl;
	std::cout << "The value of the stringPTR variable is: " << stringPTR << std::endl;
	std::cout << "The value of the stringREF variable is: " << stringREF << std::endl;

	int x = 10;
	updateValue(x);
	std::cout << "x = " << x << std::endl;

	return 0;
}
