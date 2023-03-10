#include "raycaster.h"
/**
 * convert_color - converts a hexa value in color
 * @hexa_value: value to be converted
 * Return: SDL_Color after convertion
 */
SDL_Color convert_color(int hexa_value)
{
	SDL_Color color;

	color.r = ((hexa_value >> 16) & 0xFF);
	color.g = ((hexa_value >> 8) & 0xFF);
	color.b = ((hexa_value) & 0xFF);
	return (color);
}
/**
 * select_wall_color - Identify the color in the map
 * @map_x: map value in x
 * @map_y: map value in y
 * Return: SDL_Color selected
 */
SDL_Color select_wall_color(int map_x, int map_y)
{
	SDL_Color color;

	if (worldMap[map_x][map_y] == 1)
		color = convert_color(RED);
	else if (worldMap[map_x][map_y] == 2)
		color = convert_color(GREEN);
	else if (worldMap[map_x][map_y] == 3)
		color = convert_color(BLUE);
	else if (worldMap[map_x][map_y] == 4)
		color = convert_color(WHITE);
	else
		color = convert_color(BLACK);
	return (color);
}
/**
 * hexa_wall_color - minimap color selection
 * @map: minimap matrix values
 * Return: integer with minimap color
 */
int hexa_wall_color(int map)
{
	int color;

	if (map == 1)
		color = RED;
	else if (map == 2)
		color = GREEN;
	else if (map == 3)
		color = BLUE;
	else if (map == 4)
		color = WHITE;
	else
		color = BLACK;
	return (color);
}
/**
 * apply_night_effect - apply a dar efect tor far walls
 * @color: Color of the wall
 * @distance: distance between player and wall
 * Return: SDL_Color with night effect
 */
SDL_Color apply_night_effect(SDL_Color color, double distance)
{
	if (color.r / distance * AMB_LIGHT <= color.r)
		color.r = color.r / distance * AMB_LIGHT;
	if (color.g / distance * AMB_LIGHT <= color.g)
		color.g = color.g / distance * AMB_LIGHT;
	if (color.b / distance * AMB_LIGHT <= color.b)
		color.b = color.b / distance * AMB_LIGHT;
	return (color);
}
