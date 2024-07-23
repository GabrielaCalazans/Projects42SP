/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:41:34 by gacalaza          #+#    #+#             */
/*   Updated: 2024/07/23 18:29:02 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {

private:
	Contact		contacts[8];
	static int	_nbrContacts;

	
public:
	PhoneBook(void);
	~PhoneBook(void);

	int		getNbrContacts(void) const;
	void	setContact(void);
	void	getContact(const PhoneBook& phonebook, int pos);
	void	displayContacts() const;
	void	searchContact(PhoneBook& phonebook);
};


#endif
