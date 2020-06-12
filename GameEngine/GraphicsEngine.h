#pragma once
//#pragma comment(lib,"d3d11.lib")
#include <d3d11.h>

class SwapChain;
class DeviceContext;
class VertexBuffer;


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
	VertexBuffer* createVertexBuffer();

	bool createShaders();
	bool setShaders();
	void getShaderBufferAndSize(void ** bytecode, UINT * size);

private:
#pragma region Initialization
	ID3D11Device * m_d3d_device;
	D3D_FEATURE_LEVEL m_feature_level;
	ID3D11DeviceContext * m_imm_context;
#pragma endregion

#pragma region Swap Chain
	friend class SwapChain;
	IDXGIDevice * m_dxgi_device;
	IDXGIAdapter * m_dxgi_adapter;
	IDXGIFactory * m_dxgi_factory;
#pragma endregion

	DeviceContext * m_imm_device_context;

#pragma region VertexBuffer
	friend class VertexBuffer;

#pragma endregion

#pragma region Shader
	ID3DBlob* m_vsblob = nullptr;
	ID3DBlob* m_psblob = nullptr;
	ID3D11VertexShader* m_vs = nullptr;
	ID3D11PixelShader* m_ps = nullptr;
#pragma endregion
};
