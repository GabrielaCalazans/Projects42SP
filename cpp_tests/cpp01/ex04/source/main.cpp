/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:51:05 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/23 22:43:21 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceInFile.hpp"


int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl 
				<< "Usage: ./replace <filename> \'str_to_be_replaced\' \'str_to_replace\'" << std::endl;
	}
	ReplaceInFile	file(argv[1]);
	file.replaceSring(argv[2], argv[3]);

	return (0);
}