/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:13:16 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/16 11:21:11 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

class Contact
{
private:
	std::string	fistName;
	std::string	lastName;
	std::string	nickname;
	std::string	darkestSecret;
	int			phoneNbr;

public:
	Contact(void);
	~Contact(void);
};

#endif
