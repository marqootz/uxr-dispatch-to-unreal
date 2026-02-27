// Copyright Ark. Ark Log Player — module implementation.

#include "Modules/ModuleManager.h"

class FArkLogPlayerModule : public IModuleInterface
{
public:
	virtual void StartupModule() override {}
	virtual void ShutdownModule() override {}
};

IMPLEMENT_MODULE(FArkLogPlayerModule, ArkLogPlayer);
