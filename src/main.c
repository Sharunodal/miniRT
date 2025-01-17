/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:53:49 by arissane          #+#    #+#             */
/*   Updated: 2025/01/16 14:23:02 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_controls(void)
{
	ft_putstr_fd(BL"Object controls:\n"RS GR"Select objects:"RS" =/-\n", 1);
	ft_putstr_fd(GR"Translation:\n"RS"  * Left/Right: ←/→\n  ", 1);
	ft_putstr_fd("* Up/Down: Space/Ctrl\n  * Forward/Backward:  ↑/↓\n", 1);
	ft_putstr_fd(GR"Rotation\n"RS"  * Around the X-axis: J\n  ", 1);
	ft_putstr_fd("* Around the Y-axis: K\n  * Around the Z-axis: L\n", 1);
	ft_putstr_fd(GR"Resize\n"RS"  * Diameter(-/+): </>\n  ", 1);
	ft_putstr_fd("* Height(-/+): N/M\n", 1);
	ft_putstr_fd(BL"\nCamera controls:\n"RS GR"Translation\n"RS, 1);
	ft_putstr_fd("  * Left/Right: A/D\n  * Up/Down: R/F\n  ", 1);
	ft_putstr_fd("* Forward/Backward: W/S\n", 1);
	ft_putstr_fd(GR"Rotation\n"RS"  * X-axis(up/down): Z/X\n  ", 1);
	ft_putstr_fd("* Y-axis(left/right): Q/E\n  * Z-axis: C/V\n", 1);
	ft_putstr_fd(BL"\nLight controls:\n"RS GR"Translation\n"RS"  * "
		"Left/Right: 8/4\n  * Up/Down: 7/1\n  * Forward/Backward:  5/6\n", 1);
	ft_putstr_fd(GR"Rotation\n"RS"  * X-axis(up/down): **/**\n  "
		"* Y-axis(left/right): **/**\n  * X-axis: **/**\n", 1);
	ft_putstr_fd(GR"Brightness(-/+): "RS"9/3\n\n", 1);
	ft_putstr_fd(BL"Ambient Light\n"RS"  Brightness(-/+): [/]\n", 1);
	ft_putstr_fd(BL"\n************************************************\n"RS, 1);
}

void	initialise(t_minirt *mrt)
{
	mrt->mlx = mlx_init();
	mrt->win = mlx_new_window(mrt->mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	mrt->img = mlx_new_image(mrt->mlx, WIN_WIDTH, WIN_HEIGHT);
	mrt->data_addr = mlx_get_data_addr(mrt->img, &mrt->bits_per_pixel,
			&mrt->line_length, &mrt->endian);
}

int	main(int argc, char **argv)
{
	t_minirt	mrt;

	if (argc != 2 || argv[1] == NULL)
	{
		ft_putstr_fd("Invalid number of arguments", 2);
		return (1);
	}
	ft_bzero(&mrt, sizeof(t_minirt));
	if (read_rt_file(&mrt, argv[1]) == 1)
		return (1);
	initialise(&mrt);
	render(&mrt);
	print_controls();
	mlx_hook(mrt.win, 17, 0, end_event, &mrt);
	mlx_key_hook(mrt.win, key_input, &mrt);
	mlx_loop(mrt.mlx);
	return (0);
}
