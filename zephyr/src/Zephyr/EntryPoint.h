#pragma once

#ifdef ZR_PLATFORM_WINDOWS

extern Zephyr::Application* Zephyr::CreateApplication();

int main(int argc, char** argv)
{
		Zephyr::Logger::Init();
		ZR_CORE_WARN("Initialized logger!");
		ZR_INFO("Launched app!");

  auto app = Zephyr::CreateApplication();
	 app->Run();
	 delete app;
}

#endif