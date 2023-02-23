#include "raycaster.h"

SDL_Color convert_color(int hexa_value)
{
	SDL_Color color;

	color.r = ((hexa_value >> 16) & 0xFF);
	color.g = ((hexa_value >> 8) & 0xFF);
	color.b = ((hexa_value) & 0xFF);
	return (color);
}

SDL_Color select_wall_color(int map_x, int map_y)
{
	for(int x = 0; x < 64; x++)
  	for(int y = 0; y < 64; y++)
	{
    	int xorcolor = (x * 256 / 64) ^ (y * 256 / 64);
    	//int xcolor = x * 256 / 64;
    	int ycolor = y * 256 / 64;
    	int xycolor = y * 128 / 64 + x * 128 / 64;
		texture[1][64 * y + x] = 65536 * 192 * (x % 16 && y % 16);
	}
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
