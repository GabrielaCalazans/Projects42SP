/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:13:16 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/20 20:38:00 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNbr;
	std::string	_darkestSecret;

public:
	Contact(void);
	~Contact(void);

	void		setFirstName(void);
	void		setLastName(void);
	void		setNickname(void);
	void		setPhoneNbr(void);
	void		setDarkestSecret(void);

	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickname() const;
	std::string	getPhoneNbr() const;
	std::string	getDarkestSecret() const;
};


bool	isValidPhoneNumber(const std::string& phoneNumber);
bool	containsForbiddenCharacter(const std::string& str);

#endif
