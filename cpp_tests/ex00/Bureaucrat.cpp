/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:39:16 by gacalaza          #+#    #+#             */
/*   Updated: 2024/09/05 21:03:25 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//  Default Constructor
Bureaucrat::Bureaucrat(void) {
	this->_name = "Who am I?";
	std::cout << "Bureaucrat default constructor called. Name: " << _name << std::endl;

	return ;
}

//  Parameterized Constructor
Bureaucrat::Bureaucrat(const std::string& name) {
		this->_name = name;

	std::cout << "Bureaucrat parameterized constructor called. Name: " << _name << std::endl;
	return ;
}

//  Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &obj) {
	std::cout << "Bureaucrat copy constructor called." << std::endl;
	*this = obj;
	return ;
}

// Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj) {
	if (this != &obj) {
		this->_name = obj.getName();

	}
	std::cout << "Bureaucrat assignment operator called. Name: " << _name << std::endl;
	return *this;
}


Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat " << this->_name << " destructed." << std::endl;
	return ;
}

std::string		Bureaucrat::getName(void) const {
	return(this->_name);
}


int		Bureaucrat::getGrade(void) const {
	return(this->_grade);
}

void		Bureaucrat::setName(std::string name) {
	this->_name = name;
}

void		Bureaucrat::setGrade(int grade) {
	this->_grade = grade;
}

void	Bureaucrat::incrementBureaucratGrade(int grade) {
	try {
	/* do some stuff with bureaucrats */
		if (grade)
		this->_grade--;

	}
	catch (std::exception & e) {
	/* handle exception */
	}
}

// try {
//   int age = 15;
//   if (age >= 18) {
//     cout << "Access granted - you are old enough.";
//   } else {
//     throw (age);
//   }
// }
// catch (int myNum) {
//   cout << "Access denied - You must be at least 18 years old.\n";
//   cout << "Age is: " << myNum;
// } 


void	Bureaucrat::decrementBureaucratGrade(int grade) {
	this->_grade++;
}

void	Bureaucrat::GradeTooHighException(void) const {
	
}

void	Bureaucrat::GradeTooLowException(void) const {
	
}


// Any attempt to instantiate a Bureaucrat using an invalid grade must throw an ex-
// ception:
// either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.
// Implement also two member functions to increment or decrement the bureaucrat grade. If
// the grade is out of range, both of them will throw the same exceptions as the constructor.
// Remember. Since grade 1 is the highest one and 150 the lowest,
// incrementing a grade 3 should give a grade 2 to the bureaucrat