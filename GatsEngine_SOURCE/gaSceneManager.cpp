#include "gaSceneManager.h"

namespace ga
{ 
	void SceneManager::Init()
	{
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
	}

	void SceneManager::Render(HDC hdc)
	{
	}
} // namespace ga