/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:41:42 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/08 16:41:57 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h> // Para alocação dinâmica de memória

int nb_words(t_token *tokens)
{
    t_token *temp = tokens;
    int words = 0;

    while (temp && temp->type != PIPE)
    {
        if (temp->type == WORD)
            words++;
        temp = temp->next;
    }

    return words;
}

char **get_words(t_token *tokens)
{
    t_token *temp = tokens;
    int n_words = nb_words(tokens);
    char **words = malloc(sizeof(char *) * (n_words + 1));
    int i = 0;

    while (temp)
    {
        if (temp->type == WORD || is_special_case(temp->type, 2) || temp->type == QUOTED_WORD)
        {
            words[i] = ft_strdup(temp->token);
            i++;
        }
        temp = temp->next;
    }

    words[i] = NULL; // Terminar o array com NULL

    return words;
}

char **get_all_words(t_token *tokens)
{
    char **all_words = NULL;
    int check = 0;
    int pipes = has_pipe_yet(tokens);

    if (has_redirect_pipe(tokens))
        check = 1;

    if (has_d_redirec_p(tokens))
        check += 2;

    if (check == 1)
        all_words = get_words(tokens);

    return all_words;
}

void parsing_it(t_data *data)
{
    int i;
    char **all_words = get_all_words(data->tokens);

    i = 0;
    while (all_words[i])
    {
        printf("string[%i]: %s\n", i, all_words[i]);
        i++;
    }
}

int main() {
    // Exemplo de inicialização e uso de data e tokens
    // Substitua isso pelo seu código real
    t_data data;
    data.tokens = ... // Inicialize tokens adequadamente

    parsing_it(&data); // Chame a função de análise
    return 0;
}

Lembre-se de substituir os comentários ... com a inicialização real de data e tokens no seu código. Certifique-se de que as funções ft_strdup e is_special_case funcionem conforme o esperado e de que a memória alocada seja liberada quando não for mais necessária para evitar vazamentos de memória.
