#pragma once
#include <d3d12.h>
#include <dxgi1_6.h>
#include <dxgidebug.h>
#include <dxcapi.h>
#include "Window.h"

//#pragma comment(lib,"dxcompiler.lib")
//#pragma comment(lib, "dxguid.lib")
//#pragma comment(lib, "d3d12.lib")
//#pragma comment(lib, "dxgi.lib")
class DirectXCommon
{
public:
	~DirectXCommon();
	void Initialize(Window* window);
	ID3D12Device* GetDevice() { return device_; }
	ID3D12DescriptorHeap* GetSRV() { return srvDescriptorHeap_; }
	ID3D12DescriptorHeap* GetRTV() { return rtvDescriptorHeap_; }

	void Begin();

	void End();

private:
	void CreateDxgiFactory();
	void CreateDevice();
	void CreateCommand();
	void CreateSwapChain(Window* window);
	void PipelineStateObject();
	void CreateDepthStencil(Window* window);
	ID3D12DescriptorHeap* CreateDescriptorHeap(D3D12_DESCRIPTOR_HEAP_TYPE heapType, UINT numDescriptors, bool shaderVisible);
	ID3D12Resource* CreateDepthStencilTextureResource(int32_t width, int32_t height);
	IDxcBlob* CompileShader(
		// CompilerするShaderファイルへのパス
		const std::wstring& filePath,
		// Compilerに使用するProfile
		const wchar_t* profile,
		// 初期化で生成したものを3つ
		IDxcUtils* dxcUtils,
		IDxcCompiler3* dxcCompiler,
		IDxcIncludeHandler* includeHandler);
private:
	HRESULT hr;

	// DXGIファクトリーの生成
	IDXGIFactory7* dxgiFactory_ = nullptr;

	// 使用するアダプタ用の変数。最初にnullptrを入れておく
	IDXGIAdapter4* useAdapter_ = nullptr;

	ID3D12Device* device_ = nullptr;

	ID3D12CommandQueue* commandQueue_ = nullptr;
	ID3D12CommandAllocator* commandAllocator_ = nullptr;
	ID3D12GraphicsCommandList* commandList_ = nullptr;

	// RTVを2つ作るのでディスクリプタを2つ用意
	D3D12_CPU_DESCRIPTOR_HANDLE rtvHandles_[2]{};
	IDXGISwapChain4* swapChain_ = nullptr;
	ID3D12Resource* swapChainResources_[2] = { nullptr };
	ID3D12DescriptorHeap* rtvDescriptorHeap_ = nullptr;
	ID3D12DescriptorHeap* srvDescriptorHeap_ = nullptr;
	// デバッグ用
	ID3D12InfoQueue* infoQueue_ = nullptr;

	// フェンス
	ID3D12Fence* fence_ = nullptr;
	uint64_t fenceValue_ = 0;
	HANDLE fenceEvent_{};

	IDxcUtils* dxcUtils_ = nullptr;
	IDxcCompiler3* dxcCompiler_ = nullptr;
	IDxcIncludeHandler* includeHandler_ = nullptr;

	ID3DBlob* signatureBlob_ = nullptr;
	ID3DBlob* errorBlob_ = nullptr;

	D3D12_GRAPHICS_PIPELINE_STATE_DESC graphicsPipelineStateDesc_{};
	ID3D12RootSignature* rootSignature_ = nullptr;
	ID3D12PipelineState* graphicsPipelineState_ = nullptr;

	ID3D12Resource* depthStencilResource_ = nullptr;
	ID3D12DescriptorHeap* dsvDescriptorHeap_ = nullptr;

	IDxcBlob* vertexShaderBlob_ = nullptr;
	IDxcBlob* pixelShaderBlob_ = nullptr;
};

