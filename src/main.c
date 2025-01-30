/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:53:49 by arissane          #+#    #+#             */
/*   Updated: 2025/01/30 10:23:39 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_controls(void)
{
	ft_putstr_fd(BL"Object controls:\n"RS GR" - Selection:"RS" =/-\n", 1);
	ft_putstr_fd(GR" - Translation:\n"RS"     * Left/Right: ←/→\n     ", 1);
	ft_putstr_fd("* Up/Down: Space/Ctrl\n     * Forward/Backward:  ↑/↓\n", 1);
	ft_putstr_fd(GR" - Rotation\n"RS"     * X-axis: J\n     ", 1);
	ft_putstr_fd("* Y-axis: K\n     * Z-axis: L\n", 1);
	ft_putstr_fd(GR" - Resize\n"RS"     * Diameter(-/+): </>\n     ", 1);
	ft_putstr_fd("* Height(-/+): N/M\n", 1);
	ft_putstr_fd(BL"\nCamera controls(based on global x,y and z):\n"RS
		GR" - Translation\n"RS, 1);
	ft_putstr_fd("     * Left/Right: A/D\n     * Up/Down: R/F\n     ", 1);
	ft_putstr_fd("* Forward/Backward: W/S\n", 1);
	ft_putstr_fd(GR" - Rotation\n"RS"     * X-axis(up/down): Z/X\n     ", 1);
	ft_putstr_fd("* Y-axis(left/right): Q/E\n     * Z-axis(left/right): "
		"C/V\n", 1);
	ft_putstr_fd(BL"\nLight controls:\n"RS GR" - Translation\n"RS"     * "
		"Left/Right: 4/6\n     * Up/Down: 7/1\n     * Forward/Backward: 8/5\n",
		1);
	ft_putstr_fd(GR" - Brightness(-/+): "RS"9/3\n\n", 1);
	ft_putstr_fd(BL"Ambient Light\n"RS GR" - Brightness(-/+):"RS" [/]\n", 1);
	ft_putstr_fd(BL"\n************************************************\n"RS, 1);
}

static int	initialise(t_minirt *mrt)
{
	mrt->mlx = mlx_init();
	if (!mrt->mlx)
		return (write_error("mlx init failed"));
	mrt->win = mlx_new_window(mrt->mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	if (!mrt->win)
		return (write_error("mlx init window failed"));
	mrt->img = mlx_new_image(mrt->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!mrt->img)
		return (write_error("mlx init image failed"));
	mrt->data_addr = mlx_get_data_addr(mrt->img, &mrt->bits_per_pixel,
			&mrt->line_length, &mrt->endian);
	if (!mrt->data_addr)
		return (write_error("mlx init data addresses failed"));
	return (0);
}

static int	check_window_size(void)
{
	if (WIN_WIDTH < 50 || WIN_WIDTH > 2000 || WIN_HEIGHT < 50
		|| WIN_HEIGHT > 2000)
	{
		ft_putstr_fd("Error\nWindow width/height should be"
			" between 50 and 2000\n", 2);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_minirt	mrt;

	if (argc != 2 || argv[1] == NULL)
		return (write_error("Invalid number of arguments"));
	if (check_window_size() == 1)
		return (1);
	ft_bzero(&mrt, sizeof(t_minirt));
	if (read_rt_file(&mrt, argv[1]) == 1)
	{
		if (mrt.object)
			free(mrt.object);
		return (1);
	}
	if (initialise(&mrt) == 1)
		return (end_event(&mrt));
	render(&mrt);
	print_controls();
	mlx_hook(mrt.win, 17, 0, end_event, &mrt);
	mlx_key_hook(mrt.win, key_input, &mrt);
	mlx_loop(mrt.mlx);
	return (0);
}
