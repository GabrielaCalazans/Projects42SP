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

#include "ReplaceInFile.hpp"

ReplaceInFile::ReplaceInFile(std::string arg1)
{
	this->_inFileName = arg1;
	this->_inFile.open(this->_inFileName.c_str());
	if (!this->_inFile.is_open())
	{
		std::cerr << "Could not open the file." << std::endl;
		exit(1);
	}
	this->_outFileName = arg1 + ".replace";
	this->_outFile.open(this->_outFileName.c_str());
	if (!this->_outFile.is_open())
	{
		std::cerr << "Could not open the file." << std::endl;
		exit(1);
	}
}


ReplaceInFile::~ReplaceInFile()
{
	this->_inFile.close();
	this->_outFile.close();
	return ;
}


void	ReplaceInFile::replaceSring(std::string arg2, std::string arg3)
{
	std::string	line;
	size_t		position;
	
	std::getline(this->_inFile, line);
	while (1)
	{
		if (arg2.compare(arg3))
		{
			position = line.find(arg2);
			while (position != std::string::npos)
			{
				line.insert(position, arg3);
				line.erase(position + arg3.length()), arg2.length();
				position = line.find(arg2);

			}
		}
		this->_outFile << line;
		if (std::getline(this->_inFile, line))
			this->_outFile << std::endl;
		else
			break;
	}
}
