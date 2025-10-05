#ifndef CAMERA_CONTROLLER_H
# define CAMERA_CONTROLLER_H

# include "raylib.h"

void	move_camera_screen_border(Camera2D *camera, int margin, int speed);
void	zoom_camera_mouse_wheel(Camera2D *camera, float amount);

#endif
