/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:31:27 by gacalaza          #+#    #+#             */
/*   Updated: 2024/06/25 18:27:24 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

// Função para converter uma string ASCII para maiúsculas
std::string	to_uppercase(const std::string& str) {
	std::string result;
	char	ch;

	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
		ch = *it;
		result += static_cast<unsigned char>(std::toupper(static_cast<unsigned char>(ch)));
	}
	return result;
}

void	print_upper(const std::string& toup, int check) {
	std::string upperStr = to_uppercase(toup);
	std::cout << upperStr;
	if (check == 1)
		std::cout << std::endl;
}


// // // // ************* DIV 0 ***************************
// void	print_upper(const std::string& toup)
// {
// 	char	ch;
// 	int		size;

// 	size = toup.size();
// 	for (int i = 0; i < size; i++)
// 	{
// 		// convert str[i] to uppercase
// 		ch = toupper(toup[i]);
// 		std::cout << ch;
// 	}

// 	for (std::string::const_iterator it = toup.begin(); it != toup.end(); ++it) {
// 		char ch = *it;
// 		std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
// 	}
// }
// // // // ************* DIV 0 ***************************
// // // // ************* DIV 1 ***************************
// // Função auxiliar para converter uma string UTF-8 para maiúsculas
// std::string	to_uppercase(const std::wstring& str) {
// 	// // Converter std::string (UTF-8) para std::wstring
// 	std::locale loc("en_US.UTF-8");
// 	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
// 	std::wstring wide_str = converter.from_bytes(str);

// 	for (std::wstring::size_type i = 0; i < wide_str.size(); ++i) {
// 		wide_str[i] = std::toupper(wide_str[i], loc);
// 	}
// 	return (converter.to_bytes(wide_str));
// }
// // // // ************* DIV 1 ***************************


int	main(int argc, char *argv[])
{
	if (argc < 2)
		print_upper("* loud and unbearable feedback noise *", 1);
	else {
		for (int i = 1; i < argc; i++) {
			print_upper(argv[i], 0);
			if (i < argc - 1) {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
