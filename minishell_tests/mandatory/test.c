/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:55:33 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/18 19:56:18 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_fd[2]; // Descritores do pipe
    pid_t child_pid;

    // Cria um pipe
    if (pipe(pipe_fd) == -1) {
        perror("Erro ao criar o pipe");
        exit(EXIT_FAILURE);
    }

    // Cria um novo processo
    if ((child_pid = fork()) == -1) {
        perror("Erro ao criar um novo processo");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Código do filho (processo 1)
        close(pipe_fd[0]); // Fecha a extremidade de leitura do pipe

        // Redireciona a saída padrão para a extremidade de escrita do pipe
        dup2(pipe_fd[1], STDOUT_FILENO);

        // Execute o primeiro comando usando execve
        char *command1[] = {"/bin/ls", "-l", NULL};
        execve(command1[0], command1, NULL);
        perror("Erro ao executar o primeiro comando");
        exit(EXIT_FAILURE);
    } else {
        // Código do pai (processo 2)
        close(pipe_fd[1]); // Fecha a extremidade de escrita do pipe

        // Redireciona a entrada padrão para a extremidade de leitura do pipe
        dup2(pipe_fd[0], STDIN_FILENO);

        // Execute o segundo comando usando execve
        char *command2[] = {"/usr/bin/grep", "keyword", NULL};
        execve(command2[0], command2, NULL);
        perror("Erro ao executar o segundo comando");
        exit(EXIT_FAILURE);
    }

    return 0;
}
