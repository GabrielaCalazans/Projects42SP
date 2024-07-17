/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:41:34 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/16 20:14:43 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook {

private:
	Contact		contacts[8];
	static int	_nbrContacts;

	
public:
	PhoneBook(void);
	~PhoneBook();

	int		getNbrContacts(void) const;
	void	setContact(const PhoneBook& phonebook);
	void	getContact(const PhoneBook& phonebook);
};

#endif
