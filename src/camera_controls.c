/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:15:37 by arissane          #+#    #+#             */
/*   Updated: 2025/01/17 13:37:22 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * Updates the camera up and right vectors based on the global up vector.
 */
static void	update_up_right_vectors(t_camera *camera)
{
	t_vec3	up;

	up.y = 0.0f;
	if (camera->direction.y > 0.9f)
		up.x = 1.0f;
	else if (camera->direction.y < -0.9f)
		up.x = -1.0f;
	else
	{
		up.x = 0.0f;
		up.y = 1.0f;
	}
	up.z = 0.0f;
	camera->right = vec3_crossproduct(camera->direction, up);
	vec3_normalise(&camera->right);
	camera->up = vec3_crossproduct(camera->right, camera->direction);
	vec3_normalise(&camera->up);
}

static int	camera_rotation(int keycode, t_camera *camera)
{
	t_vec3	rotation_axis;
	t_vec4	target_quaternion;

	rotation_axis.x = 0;
	rotation_axis.y = 0;
	rotation_axis.z = 0;
	if (keycode == 101)
		rotation_axis.y = -1.0f;
	else if (keycode == 113)
		rotation_axis.y = 1.0f;
	else if (keycode == 122)
		rotation_axis.x = 1.0f;
	else if (keycode == 120)
		rotation_axis.x = -1.0f;
	else if (keycode == 99)
		rotation_axis.z = 1.0f;
	else if (keycode == 118)
		rotation_axis.z = -1.0f;
	else
		return (1);
	target_quaternion = angle_to_quaternion(&rotation_axis, 0.1f);
	camera->rotation = vec4_multiply(&camera->rotation, &target_quaternion);
	camera->direction = quaternion_to_vec3(&camera->rotation);
	update_up_right_vectors(camera);
	return (0);
}

int	camera_controls(int keycode, t_camera *camera)
{
	if (keycode == 97)
		camera->position.x -= 0.5;
	else if (keycode == 100)
		camera->position.x += 0.5;
	else if (keycode == 114)
		camera->position.y += 0.5;
	else if (keycode == 102)
		camera->position.y -= 0.5;
	else if (keycode == 119)
		camera->position.z += 0.5;
	else if (keycode == 115)
		camera->position.z -= 0.5;
	else if (camera_rotation(keycode, camera) == 0)
		return (0);
	else
		return (1);
	return (0);
}
