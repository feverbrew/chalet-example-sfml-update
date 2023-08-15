#ifndef UTIL_WINDOWS_PLATFORM_HPP
#define UTIL_WINDOWS_PLATFORM_HPP

#include "Platform/IPlatform.hpp"

#include <array>

#if defined __UINT32_MAX__ or UINT32_MAX
	#include <inttypes.h>
#else
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;
#endif

// TODO: WM_DISPLAYCHANGE event handling (multi-monitor support)

namespace util
{
struct WindowsPlatform final : IPlatform
{
	WindowsPlatform();

	virtual void initialize(const sf::WindowHandle& inHandle) final;
	virtual void toggleFullscreen(const sf::WindowHandle& inHandle, const sf::Uint32 inStyle, const bool inWindowed, const sf::Vector2u& inResolution) final;
	virtual float getScreenScalingFactor(const sf::WindowHandle& inHandle) final;
	virtual float getRefreshRate(const sf::WindowHandle& inHandle) final;

private:
	PBYTE getIconDirectory(const int inResourceId);
	HICON getIconFromIconDirectory(PBYTE inIconDirectory, const uint32_t inSize);
	DWORD sfmlWindowStyleToWin32WindowStyle(const sf::Uint32 inStyle);

	float m_screenScalingFactor = 0.0f;
};
}

#endif // UTIL_WINDOWS_PLATFORM_HPP
