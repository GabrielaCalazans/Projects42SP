/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:41:34 by gacalaza          #+#    #+#             */
/*   Updated: 2024/06/27 20:29:13 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook {

private:
	Contact		contacts[8];
	static int	_nbrContacts;
	std::string	_nameT;

	
public:
	PhoneBook(std::string name);
	~PhoneBook();

	static int	getNbInst(void);
	void		testfunc(std::string name) const;
	int			test;

	void		setNameT(std::string name);
	std::string	getName(void);
};

#endif
