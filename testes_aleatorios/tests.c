/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:37:59 by gacalaza          #+#    #+#             */
/*   Updated: 2023/02/28 02:31:51 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

int main()
{
	int	i = 1;
	int	result = 1;
	// int	values1[2] = {10, 20};
	// int values2[2] = {30, 40};
	// int total[2][2];

	// if (i++ % 2)
	// 	result *= 2;
	// else
	// 	result *= 20;
	// printf("result: %d\n", result);
	// printf("i++: %d\n", i++);

	// if (ceil((19 > 11)))
	// 	result = (10 / 5) + 2;
	// else
	// 	result = (300 / 3) + 2;

	// printf("result: %d\n", result);
	// printf("i++: %d\n", i++);
	// printf("ceil: 1:%d 2:%d 3:%d\n", ceil((19 > 11)));

	// fdf->map.y0 -= fdf->map.values[y][x] * fdf->map.x_value;

	// printf("VETOR: 1: %d 2: %d", values[0][0]);

	int	notasAlunos[2][4] = {0};
	int	mediasAlunos[2] = {0};
	int	notas0[4] = {10, 5, 20, 10};
	int	notas1[4] = {10, 5, 0, 0};
	int	media = 0;

	for (int aluno = 0; aluno < 2; ++aluno)
	{
		if (aluno == 0)
		{
			for (int nota = 0; nota < 4; ++nota)
			{
				notasAlunos[aluno][nota] = notas0[nota];
				media += notasAlunos[aluno][nota];
			}
		}
		if (aluno == 1)
		{
			for (int nota = 0; nota < 4; ++nota)
			{
				notasAlunos[aluno][nota] = notas1[nota];
				media += notasAlunos[aluno][nota];
			}
		}
		mediasAlunos[aluno] = media / 4;
		media = 0;
	}
	for (int aluno = 0; aluno < 2; ++aluno)
	{
		printf("A media do aluno %i é %i\n", aluno, mediasAlunos[aluno]);
	}
	return (0);
}