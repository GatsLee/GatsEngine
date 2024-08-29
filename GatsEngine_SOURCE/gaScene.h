#pragma once

#include "gaEntity.h"
#include "gaGameObject.h"

namespace ga
{
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		void Init();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);
	private:
		std::vector<GameObject *> mGameObjects;

	};
}

