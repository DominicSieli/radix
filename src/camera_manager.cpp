#include "game.h"
#include "camera_manager.h"

namespace Radix
{
	CameraManager::CameraManager()
	{}

	CameraManager::~CameraManager()
	{}

	void CameraManager::initialize(const float& x, const float& y, const float& w, const float& h)
	{
		camera = {x, y, w, h};
	}

	SDL_FRect CameraManager::get_camera()
	{
		return camera;
	}

	void CameraManager::update_resolution(const float& w, const float& h)
	{
		Game::window_manager.update_resolution(static_cast<int>(w), static_cast<int>(h));
		camera = {camera.x, camera.y, w, h};
	}

	void CameraManager::update_position(const Vector2<float>& player_position, const Vector2<float>& map_dimensions)
	{
		float w = (map_dimensions.x < camera.w) ? map_dimensions.x : camera.w;
		float h = (map_dimensions.y < camera.h) ? map_dimensions.y : camera.h;

		update_resolution(w, h);

		if(!Game::time_manager.is_paused())
		{
			camera.x = player_position.x - camera.w / 2;
			camera.y = player_position.y - camera.h / 2;

			camera.x = (camera.x < 0) ? 0 : camera.x;
			camera.y = (camera.y < 0) ? 0 : camera.y;
			camera.x = (camera.x + camera.w > map_dimensions.x) ? map_dimensions.x - camera.w : camera.x;
			camera.y = (camera.y + camera.h > map_dimensions.y) ? map_dimensions.y - camera.h : camera.y;
		}
	}

	bool CameraManager::is_inside_bounds(const Vector2<float>& position, const Vector2<float>& dimensions)
	{
		if(position.x + (dimensions.x * 2) >= camera.x && position.y + (dimensions.y * 2) >= camera.y && position.x - dimensions.x <= camera.x + camera.w && position.y - dimensions.y <= camera.y + camera.h)
		{
			return true;
		}

		return false;
	}
}
