/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:46:51 by jquinodo          #+#    #+#             */
/*   Updated: 2024/11/26 18:09:42 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void update_player_image(t_game *game, int step_x, int step_y)
{
    if (step_y == -1)
        game->img_ptr.player = game->img_ptr.player_up;
    else if (step_y == 1)
        game->img_ptr.player = game->img_ptr.player_down;
    else if (step_x == -1)
        game->img_ptr.player = game->img_ptr.player_left;
    else if (step_x == 1)
        game->img_ptr.player = game->img_ptr.player_right;
}

static int	move(t_game *game, int step_x, int step_y)
{
	char	next;
	char	current;

	current = game->map->vector[(game->player).y][(game->player).x];
	next = game->map->vector[(game->player).y + step_y][(game->player).x
		+ step_x];
	if (next != WALL)
	{
		update_player_image(game, step_x, step_y);
		(game->move_count)++;
		ft_printf("movement: %d\n", game->move_count);
		if (next == COLLECTIBLE)
			game->collectible_count--;
		if (current != EXIT)
		{
			game->map->vector[(game->player).y][(game->player).x] = FLOOR;
			game->map->vector[(game->exit).y][(game->exit).x] = EXIT;
		}
		game->map->vector[(game->player).y + step_y][(game->player).x
			+ step_x] = PLAYER;
		game->player.x = game->player.x + step_x;
		game->player.y = game->player.y + step_y;
		if ((next == EXIT) && (game->collectible_count == 0))
			return (1);
	}
	return (0);
}

int	key_handler(int key_code, t_game *game)
{
	int	move_response;

	if (key_code == ESC)
	{
		ft_printf("--------------------------------------------------\n");
		ft_printf("|             Tu as gave up :(                    |\n");
		ft_printf("|                  SERIEUX      !!!               |\n");
		ft_printf("--------------------------------------------------\n");
		exit_game(game);
	}
	if (key_code == W || key_code == UP)
		move_response = move(game, 0, -1);
	else if (key_code == S || key_code == DOWN)
		move_response = move(game, 0, 1);
	else if (key_code == D || key_code == RIGHT)
		move_response = move(game, 1, 0);
	else if (key_code == A || key_code == LEFT)
		move_response = move(game, -1, 0);
	else
		return (0);
	if (move_response == 1)
	{
		ft_printf("--------------------------------------------------\n");
		ft_printf("|   🎉🎉🎉  Congratulations!!!!!  🎉🎉🎉         |\n");
		ft_printf("|              BRAVO    BG                       |\n");
		ft_printf("|              TU AS GAGNÉ     !!!               |\n");
		ft_printf("--------------------------------------------------\n");
		ft_printf("###        TON SCORE EST DE   %d STEPS    !    ###\n\n\n",
			game->move_count);
		exit_game(game);
	}
	put_image_to_window(game);
	return (0);
}
