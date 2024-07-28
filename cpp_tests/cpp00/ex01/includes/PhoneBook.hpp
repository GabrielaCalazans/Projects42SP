/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:41:34 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/27 21:26:58 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {

private:
	Contact		_contacts[8];
	static int	_index;
	static int	_nbrContacts;

	
public:
	PhoneBook(void);
	~PhoneBook(void);

	int		getNbrContacts(void) const;
	int		getIndex(void) const;
	void	setContact(PhoneBook& phonebook);
	void	getContact(const PhoneBook& phonebook, int pos);
	void	displayContacts() const;
	void	searchContact(PhoneBook& phonebook);
};


#endif
