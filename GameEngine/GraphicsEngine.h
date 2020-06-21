#pragma once
//#pragma comment(lib,"d3d11.lib")
#include <d3d11.h>

class SwapChain;
class DeviceContext;
class VertexBuffer;
class ConstantBuffer;
class VertexShader;
class PixelShader;


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
	ConstantBuffer* createConstantBuffer();
	VertexShader* createVertexShader(const void * shader_byte_code, size_t byte_code_size);
	PixelShader* createPixelShader(const void * shader_byte_code, size_t byte_code_size);

	bool compileVertexShader(const wchar_t* file_name, const char* entry_point_name, void** shader_byte_code, size_t* byte_code_size);
	bool compilePixelShader(const wchar_t* file_name, const char* entry_point_name, void** shader_byte_code, size_t* byte_code_size);

	void releaseCompiledShader();

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

#pragma region ConstantBuffer
	friend class ConstantBuffer;

#pragma endregion

#pragma region VertexShader
	friend class VertexShader;

#pragma endregion

#pragma region PixelShader
	friend class PixelShader;

#pragma endregion

#pragma region Shader
	ID3DBlob* m_blob = nullptr;



	ID3DBlob* m_vsblob = nullptr;
	ID3DBlob* m_psblob = nullptr;
	ID3D11VertexShader* m_vs = nullptr;
	ID3D11PixelShader* m_ps = nullptr;
#pragma endregion
};
