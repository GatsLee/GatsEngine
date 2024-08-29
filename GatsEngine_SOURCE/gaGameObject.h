#pragma once
#include "CommonInclude.h"
#include "gaInput.h"

namespace ga
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y) { mX = x; mY = y; }
		float GetX(void) const { return mX; }
		float GetY(void) const { return mY; }
		
	private:
		float mX;
		float mY;
	};
}

