/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceInFile.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:38:04 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/23 22:12:05 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACEINFILE_HPP
# define REPLACEINFILE_HPP

# include <string>
# include <fstream>
# include <iostream>
# include <cstring>
# include <cstdlib>


class ReplaceInFile
{
private:
	std::ifstream	_inFile;
	std::ofstream	_outFile;
	std::string		_inFileName;
	std::string		_outFileName;

public:
	ReplaceInFile(std::string arg1);
	~ReplaceInFile(void);

	void	replaceSring(std::string arg2, std::string arg3);

};


#endif
