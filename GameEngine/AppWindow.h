#pragma once
#include "Window.h"
#include "GraphicsEngine.h"
#include "SwapChain.h"
#include "DeviceContext.h"
#include "VertexBuffer.h"


class AppWindow : public Window
{
public:
	AppWindow();
	~AppWindow();

#pragma region Window States
	virtual void onCreate() override;
	virtual void onUpdate() override;
	virtual void onDestroy() override;
#pragma endregion

private:
	SwapChain* m_swap_chain;
	VertexBuffer* m_vb;

};
