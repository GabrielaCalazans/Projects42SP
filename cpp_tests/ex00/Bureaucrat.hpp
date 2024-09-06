/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:38:04 by gacalaza          #+#    #+#             */
/*   Updated: 2024/09/05 18:09:22 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
private:
	std::string	_name;
	int			_grade;

public:
	Bureaucrat(void);
	Bureaucrat(const std::string& name);
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat& operator=(const Bureaucrat &obj);
	~Bureaucrat(void);

	std::string	getName(void) const;
	int			getGrade(void) const;
	void		GradeTooHighException(void) const;
	void		GradeTooLowException(void) const;
	void		setName(std::string name);
	void		setGrade(int grade);
	void		incrementBureaucratGrade(int grade);
	void		decrementBureaucratGrade(int grade);


};


#endif
