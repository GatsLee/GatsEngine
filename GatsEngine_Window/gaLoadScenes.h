#pragma once
#include "..\\GatsEngine_SOURCE\\gaSceneManager.h"
#include "gaPlayScene.h"

namespace ga
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
	}
}