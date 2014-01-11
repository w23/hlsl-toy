#pragma once

#include "directx.h"
#include "com_ptr.h"

namespace toy {

class Window;

class DXRenderDevice {
public:
	bool init(const Window& window);
	void shutdown();
private:
	bool create_back_buffer_and_dst();
	void setup_buffers();

	ComPtr<ID3D11Device> _device;
	ComPtr<ID3D11DeviceContext> _immediate_device;
	ComPtr<IDXGISwapChain> _swap_chain;

	ComPtr<ID3D11Texture2D> _back_buffer;
	ComPtr<ID3D11Texture2D> _depth_stencil;
	ComPtr<ID3D11RenderTargetView> _back_buffer_rtv;
	ComPtr<ID3D11DepthStencilView> _depth_stencil_view;
};

} // namespace toy