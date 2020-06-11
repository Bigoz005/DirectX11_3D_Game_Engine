#pragma once
//#pragma comment(lib,"d3d11.lib")
#include <d3d11.h>
class SwapChain;
class DeviceContext;

class GraphicsEngine
{
public:
	GraphicsEngine();
	bool init();
	bool release();
	~GraphicsEngine();
	static GraphicsEngine* get();

	SwapChain * createSwapChain();
	DeviceContext* getImmediateDeviceContext();

private:
#pragma region Initialization
	ID3D11Device * m_d3d_device;
	D3D_FEATURE_LEVEL m_feature_level;
	ID3D11DeviceContext * m_imm_context;
#pragma endregion

#pragma region Swap Chain
	IDXGIDevice * m_dxgi_device;
	IDXGIAdapter * m_dxgi_adapter;
	IDXGIFactory * m_dxgi_factory;
	friend class SwapChain;
#pragma endregion

	DeviceContext * m_imm_device_context;
};

