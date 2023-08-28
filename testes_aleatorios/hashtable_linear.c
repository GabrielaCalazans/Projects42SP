/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_linear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:13:50 by gacalaza          #+#    #+#             */
/*   Updated: 2023/08/25 17:20:30 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// const represent the size of hashtable
#define M 19

typedef struct s_person
{
	int		registration;
	char	name[50];
}			t_person;

t_person hashtable[M];


// initializing hash table with code value
void	init_hashtable()
{
	int	i;
	for(i = 0; i < M; i++)
		hashtable[i].registration = -1;
}

// func spread
int	generate_hashcode(int key)
{
	return key % M;
}

// func to read and return a person
t_person	read_person()
{
	t_person	p;
	printf("Registration number: ");
	scanf("%d", &p.registration);
	scanf("%*c");
	printf("Name: ");
	fgets(p.name, 50, stdin);
	return p;
	
}

// inset a person to hash table
void	insetperson()
{
	t_person	person = read_person();
	int			index = generate_hashcode(person.registration);
	while (hashtable[index].registration != -1)
		index = generate_hashcode(index + 1);
	hashtable[index] = person;
}

t_person	*find(int key)
{
	int	index = generate_hashcode(key);
	while (hashtable[index].registration != -1)
	{
		if(hashtable[index].registration == key)
			return (&hashtable[index]);
		else
			index = generate_hashcode(index + 1);
	}
	return (NULL);
}

void	print_hashtable()
{
	int	i;
	printf("\n----------------------HASH_TABLE--------------------\n");
	for (i = 0; i < M; i++)
	{
		if(hashtable[i].registration != -1)
			printf("%2d = %3d \t %s", i, hashtable[i].registration, hashtable[i].name);
		else
			printf("%d =\n", i);
	}
	printf("\n----------------------HASH_TABLE--------------------\n");
}

int	main()
{
	int			op, key;
	t_person	*p;

	init_hashtable();

	do
	{
		printf("1 - Insert \n2 - Find\n3 - print\n0 - Exit\n");
		scanf("%d", &op);

		switch (op)
		{
		case 0:
			printf("Leaving...\n");
			break;
		case 1:
			insetperson();
			break;
		case 2:
			printf("Registration to Find: ");
			scanf("%d", &key);
			p = find(key);

			if(p)
				printf("\n\t Registration: %d \tName: %s\n", p->registration, p->name);
			break;
		case 3:
			print_hashtable();
			break;		
		default:
			printf("Invalide Option!\n");
		}
	} while (op != 0);
	
	return (0);
}
