/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:51:05 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/30 21:50:45 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main(void)
{
	// const AAnimal	aanimal("Coisa");


	// Test object construction and destruction
	std::cout << std::endl << "**** Object Construction and Destruction Tests ****" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j; // Should call Dog destructor, then Animal destructor
	delete i; // Should call Cat destructor, then Animal destructor
	std::cout << "-----------------------------------------" << std::endl;

	// Test array of objects and polymorphism
	std::cout << "**** Polymorphism with Animal Array ****" << std::endl;
	const AAnimal* meta[4];
	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
	}

	for (int i = 0; i < 4; i++) {
		std::cout << "AAnimal at index " << i << ": " << meta[i]->getType() << " -> ";
		meta[i]->makeSound();
	}

	for (int i = 0; i < 4; i++) {
		delete meta[i]; // Should call the appropriate destructor for each object type
	}
	std::cout << "-----------------------------------------" << std::endl;

	// Test manipulation of Brain ideas for Cat
	std::cout << "**** Brain Manipulation Tests for Cat ****" << std::endl;
	Cat cat;
	cat.setBrainIdea(0, "I want Whiskas!");
	cat.setBrainIdea(1, "I want to sleep!");

	std::cout << "Cat's Brain Ideas:" << std::endl;
	std::cout << "Idea 0: " << cat.getBrainIdea(0) << std::endl;
	std::cout << "Idea 1: " << cat.getBrainIdea(1) << std::endl;
	std::cout << "-----------------------------------------" << std::endl;

	// Test copy constructor and assignment operator
	std::cout << "**** Copy and Assignment Tests for Cat ****" << std::endl;
	Cat tom;
	tom = cat; // Test assignment operator

	std::cout << "Tom's Brain Ideas after assignment:" << std::endl;
	std::cout << "Idea 0: " << tom.getBrainIdea(0) << std::endl;
	std::cout << "Idea 1: " << tom.getBrainIdea(1) << std::endl;

	tom.setBrainIdea(0, "I don't want Whiskas anymore!");
	std::cout << "Tom's Brain Ideas after changing the idea:" << std::endl;
	std::cout << "Idea 0: " << tom.getBrainIdea(0) << std::endl;
	std::cout << "Idea 1: " << tom.getBrainIdea(1) << std::endl;
	
	std::cout << "Cat's Brain Ideas (Should not be changed):" << std::endl;
	std::cout << "Idea 0: " << cat.getBrainIdea(0) << std::endl;
	std::cout << "Idea 1: " << cat.getBrainIdea(1) << std::endl;
	std::cout << "-----------------------------------------" << std::endl;

	// Test copy constructor
	std::cout << "**** Copy Constructor Test for Cat ****" << std::endl;
	Cat mandaChuva(tom);
	std::cout << "MandaChuva's Brain Ideas after copy construction:" << std::endl;
	std::cout << "Idea 0: " << mandaChuva.getBrainIdea(0) << std::endl;
	std::cout << "Idea 1: " << mandaChuva.getBrainIdea(1) << std::endl;


	return (0);
}




// int	main(void)
// {
// 	std::cout << std::endl << "**** Object Construction Tests ****" << std::endl;
// 	const Animal* dog = new Dog();
// 	const Animal* cat = new Cat();

// 	std::cout << std::endl << "**** Object Destruction Tests ****" << std::endl;
// 	delete dog;  // Deve chamar ~Dog() e então ~Animal()
// 	delete cat;  // Deve chamar ~Cat() e então ~Animal()

// 	std::cout << "---------" << std::endl;

// 	std::cout << std::endl << "**** Array of Animals Construction and Sound Tests ****" << std::endl;
// 	const Animal* animals[10];
// 	for (int i = 0; i < 10; i++) {
// 		if (i < 5)
// 			animals[i] = new Dog();
// 		else
// 			animals[i] = new Cat();
// 	}

// 	std::cout << std::endl << "**** Animal Sounds in Array ****" << std::endl;
// 	for (int i = 0; i < 10; i++) {
// 		animals[i]->makeSound();
// 	}

// 	std::cout << std::endl << "**** Array of Animals Destruction ****" << std::endl;
// 	for (int i = 0; i < 10; i++) {
// 		delete animals[i];  // Deve chamar destrutores na ordem reversa de construção
// 	}

// 	std::cout << "---------" << std::endl;

// 	std::cout << std::endl << "**** Deep Copy and Brain Tests ****" << std::endl;
// 	Cat originalCat;
// 	for (int i = 0; i < 100; i++) {
// 		originalCat.setBrainIdea(i, "I want Whiskas!");
// 	}

// 	std::cout << "Original Cat's Brain Ideas:" << std::endl;
// 	for (int i = 0; i < 100; i++) {
// 		std::cout << originalCat.getBrainIdea(i) << std::endl;
// 	}

// 	std::cout << "---------" << std::endl;

// 	std::cout << std::endl << "**** Assignment Operator Test ****" << std::endl;
// 	Cat copyCat;
// 	copyCat = originalCat;

// 	std::cout << "Copy Cat's Brain Ideas after assignment:" << std::endl;
// 	for (int i = 0; i < 100; i++) {
// 		std::cout << copyCat.getBrainIdea(i) << std::endl;
// 	}

// 	std::cout << std::endl << "**** Modifying Copy Cat's Brain Ideas ****" << std::endl;
// 	for (int i = 0; i < 100; i++) {
// 		copyCat.setBrainIdea(i, "I don't want Whiskas anymore!");
// 	}

// 	std::cout << "Copy Cat's Brain Ideas after modification:" << std::endl;
// 	for (int i = 0; i < 100; i++) {
// 		std::cout << copyCat.getBrainIdea(i) << std::endl;
// 	}

// 	std::cout << "Original Cat's Brain Ideas after modifying Copy Cat:" << std::endl;
// 	for (int i = 0; i < 100; i++) {
// 		std::cout << originalCat.getBrainIdea(i) << std::endl;
// 	}

// 	std::cout << "---------" << std::endl;

// 	std::cout << std::endl << "**** Copy Constructor Test ****" << std::endl;
// 	Cat anotherCat(originalCat);

// 	std::cout << "Another Cat's Brain Ideas after copy construction:" << std::endl;
// 	for (int i = 0; i < 100; i++) {
// 		std::cout << anotherCat.getBrainIdea(i) << std::endl;
// 	}



// 	return (0);
// }
