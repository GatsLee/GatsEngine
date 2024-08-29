#pragma once

#include "gaScene.h"

namespace ga
{
	class SceneManager
	{
	public:
		template <typename T>
		static void CreateScene(std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			mScenes[name] = scene;
			return scene;
		}

		static void Init();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
	private:
		static std::map<std::wstring, Scene *> mScenes;
		static Scene* mActiveScene;
	};
}

