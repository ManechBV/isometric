#include "camera_controller.h"

void	move_camera_screen_border(Camera2D *camera, int margin, int speed)
{
	if (GetMouseX() < margin)
		camera->target.x -= speed;
	if (GetMouseY() < margin)
		camera->target.y -= speed;
	if (GetMouseX() > GetScreenWidth() - margin)
		camera->target.x += speed;
	if (GetMouseY() > GetScreenHeight() - margin)
		camera->target.y += speed;
}

void	zoom_camera_mouse_wheel(Camera2D *camera, float amount)
{
	camera->zoom += GetMouseWheelMove() * amount;
	if (camera->zoom < amount)
		camera->zoom = amount;
}
