/*
 * Copyright 2011-2015 Branimir Karadzic. All rights reserved.
 * License: http://www.opensource.org/licenses/BSD-2-Clause
 */

#ifndef BGFX_CONFIG_H_HEADER_GUARD
#define BGFX_CONFIG_H_HEADER_GUARD

#include <bx/config.h>

#ifndef BGFX_CONFIG_DEBUG
#	define BGFX_CONFIG_DEBUG 0
#endif // BGFX_CONFIG_DEBUG

#if !defined(BGFX_CONFIG_RENDERER_DIRECT3D9) \
	&& !defined(BGFX_CONFIG_RENDERER_DIRECT3D11) \
	&& !defined(BGFX_CONFIG_RENDERER_DIRECT3D12) \
	&& !defined(BGFX_CONFIG_RENDERER_METAL) \
	&& !defined(BGFX_CONFIG_RENDERER_OPENGL) \
	&& !defined(BGFX_CONFIG_RENDERER_OPENGLES) \
	&& !defined(BGFX_CONFIG_RENDERER_VULKAN) \
	&& !defined(BGFX_CONFIG_RENDERER_NULL)

#	ifndef BGFX_CONFIG_RENDERER_DIRECT3D9
#		define BGFX_CONFIG_RENDERER_DIRECT3D9 (0 \
					|| BX_PLATFORM_WINDOWS \
					|| BX_PLATFORM_XBOX360 \
					? 1 : 0)
#	endif // BGFX_CONFIG_RENDERER_DIRECT3D9

#	ifndef BGFX_CONFIG_RENDERER_DIRECT3D11
#		define BGFX_CONFIG_RENDERER_DIRECT3D11 (0 \
					|| BX_PLATFORM_WINDOWS \
					|| BX_PLATFORM_WINRT \
					? 1 : 0)
#	endif // BGFX_CONFIG_RENDERER_DIRECT3D11

#	ifndef BGFX_CONFIG_RENDERER_DIRECT3D12
#		define BGFX_CONFIG_RENDERER_DIRECT3D12 (0 \
					|| BX_PLATFORM_WINDOWS \
					? 1 : 0)
#	endif // BGFX_CONFIG_RENDERER_DIRECT3D12

	//TODO: should check if iOS8 or greater
#	ifndef BGFX_CONFIG_RENDERER_METAL
#		define BGFX_CONFIG_RENDERER_METAL (0 \
					|| BX_PLATFORM_IOS \
					? 1 : 0)
#	endif // BGFX_CONFIG_RENDERER_METAL

#	ifndef BGFX_CONFIG_RENDERER_OPENGL
#		define BGFX_CONFIG_RENDERER_OPENGL (0 \
					|| BX_PLATFORM_FREEBSD \
					|| BX_PLATFORM_LINUX \
					|| BX_PLATFORM_OSX \
					|| BX_PLATFORM_WINDOWS \
					? 1 : 0)
#	endif // BGFX_CONFIG_RENDERER_OPENGL

#	ifndef BGFX_CONFIG_RENDERER_OPENGLES
#		define BGFX_CONFIG_RENDERER_OPENGLES (0 \
					|| BX_PLATFORM_ANDROID \
					|| BX_PLATFORM_EMSCRIPTEN \
					|| BX_PLATFORM_IOS \
					|| BX_PLATFORM_NACL \
					|| BX_PLATFORM_QNX \
					|| BX_PLATFORM_RPI \
					? 1 : 0)
#	endif // BGFX_CONFIG_RENDERER_OPENGLES

#	ifndef BGFX_CONFIG_RENDERER_VULKAN
#		define BGFX_CONFIG_RENDERER_VULKAN 0
#	endif // BGFX_CONFIG_RENDERER_VULKAN

#	ifndef BGFX_CONFIG_RENDERER_NULL
#		define BGFX_CONFIG_RENDERER_NULL (!(0 \
					|| BGFX_CONFIG_RENDERER_DIRECT3D9 \
					|| BGFX_CONFIG_RENDERER_DIRECT3D11 \
					|| BGFX_CONFIG_RENDERER_DIRECT3D12 \
					|| BGFX_CONFIG_RENDERER_OPENGL \
					|| BGFX_CONFIG_RENDERER_OPENGLES \
					? 1 : 0) )
#	endif // BGFX_CONFIG_RENDERER_NULL
#else
#	ifndef BGFX_CONFIG_RENDERER_DIRECT3D9
#		define BGFX_CONFIG_RENDERER_DIRECT3D9 0
#	endif // BGFX_CONFIG_RENDERER_DIRECT3D9

#	ifndef BGFX_CONFIG_RENDERER_DIRECT3D11
#		define BGFX_CONFIG_RENDERER_DIRECT3D11 0
#	endif // BGFX_CONFIG_RENDERER_DIRECT3D11

#	ifndef BGFX_CONFIG_RENDERER_DIRECT3D12
#		define BGFX_CONFIG_RENDERER_DIRECT3D12 0
#	endif // BGFX_CONFIG_RENDERER_DIRECT3D12

#	ifndef BGFX_CONFIG_RENDERER_METAL
#		define BGFX_CONFIG_RENDERER_METAL 0
#	endif // BGFX_CONFIG_RENDERER_METAL

#	ifndef BGFX_CONFIG_RENDERER_OPENGL
#		define BGFX_CONFIG_RENDERER_OPENGL 0
#	endif // BGFX_CONFIG_RENDERER_OPENGL

#	ifndef BGFX_CONFIG_RENDERER_OPENGLES
#		define BGFX_CONFIG_RENDERER_OPENGLES 0
#	endif // BGFX_CONFIG_RENDERER_OPENGLES

#	ifndef BGFX_CONFIG_RENDERER_VULKAN
#		define BGFX_CONFIG_RENDERER_VULKAN 0
#	endif // BGFX_CONFIG_RENDERER_VULKAN

#	ifndef BGFX_CONFIG_RENDERER_NULL
#		define BGFX_CONFIG_RENDERER_NULL 0
#	endif // BGFX_CONFIG_RENDERER_NULL
#endif // !defined...

#if BGFX_CONFIG_RENDERER_OPENGL && BGFX_CONFIG_RENDERER_OPENGL < 21
#	undef BGFX_CONFIG_RENDERER_OPENGL
#	define BGFX_CONFIG_RENDERER_OPENGL 21
#endif // BGFX_CONFIG_RENDERER_OPENGL && BGFX_CONFIG_RENDERER_OPENGL < 21

#if BGFX_CONFIG_RENDERER_OPENGLES && BGFX_CONFIG_RENDERER_OPENGLES < 20
#	undef BGFX_CONFIG_RENDERER_OPENGLES
#	define BGFX_CONFIG_RENDERER_OPENGLES 20
#endif // BGFX_CONFIG_RENDERER_OPENGLES && BGFX_CONFIG_RENDERER_OPENGLES < 20

#if BGFX_CONFIG_RENDERER_OPENGL && BGFX_CONFIG_RENDERER_OPENGLES
#	error "Can't define both BGFX_CONFIG_RENDERER_OPENGL and BGFX_CONFIG_RENDERER_OPENGLES"
#endif // BGFX_CONFIG_RENDERER_OPENGL && BGFX_CONFIG_RENDERER_OPENGLES

/// Enable use of extensions.
#ifndef BGFX_CONFIG_RENDERER_USE_EXTENSIONS
#	define BGFX_CONFIG_RENDERER_USE_EXTENSIONS 1
#endif // BGFX_CONFIG_RENDERER_USE_EXTENSIONS

/// Enable use of tinystl.
#ifndef BGFX_CONFIG_USE_TINYSTL
#	define BGFX_CONFIG_USE_TINYSTL 1
#endif // BGFX_CONFIG_USE_TINYSTL

/// Enable OculusVR integration.
#ifndef BGFX_CONFIG_USE_OVR
#	define BGFX_CONFIG_USE_OVR 0
#endif // BGFX_CONFIG_USE_OVR

/// Enable nVidia PerfHUD integration.
#ifndef BGFX_CONFIG_DEBUG_PERFHUD
#	define BGFX_CONFIG_DEBUG_PERFHUD 0
#endif // BGFX_CONFIG_DEBUG_NVPERFHUD

/// Enable PIX markers.
#ifndef BGFX_CONFIG_DEBUG_PIX
#	define BGFX_CONFIG_DEBUG_PIX BGFX_CONFIG_DEBUG
#endif // BGFX_CONFIG_DEBUG_PIX

/// Enable DX11 object names.
#ifndef BGFX_CONFIG_DEBUG_OBJECT_NAME
#	define BGFX_CONFIG_DEBUG_OBJECT_NAME BGFX_CONFIG_DEBUG
#endif // BGFX_CONFIG_DEBUG_OBJECT_NAME

/// Enable Metal markers.
#ifndef BGFX_CONFIG_DEBUG_MTL
#	define BGFX_CONFIG_DEBUG_MTL BGFX_CONFIG_DEBUG
#endif // BGFX_CONFIG_DEBUG_MTL

#ifndef BGFX_CONFIG_MULTITHREADED
#	define BGFX_CONFIG_MULTITHREADED ( (!BGFX_CONFIG_RENDERER_NULL)&&(0 \
						|| BX_PLATFORM_ANDROID \
						|| BX_PLATFORM_FREEBSD \
						|| BX_PLATFORM_LINUX \
						|| BX_PLATFORM_IOS \
						|| BX_PLATFORM_NACL \
						|| BX_PLATFORM_OSX \
						|| BX_PLATFORM_QNX \
						|| BX_PLATFORM_RPI \
						|| BX_PLATFORM_WINDOWS \
						|| BX_PLATFORM_WINRT \
						|| BX_PLATFORM_XBOX360 \
						? 1 : 0) )
#endif // BGFX_CONFIG_MULTITHREADED

#ifndef BGFX_CONFIG_MAX_DRAW_CALLS
#	define BGFX_CONFIG_MAX_DRAW_CALLS ( (64<<10)-1)
#endif // BGFX_CONFIG_MAX_DRAW_CALLS

#ifndef BGFX_CONFIG_MAX_MATRIX_CACHE
#	define BGFX_CONFIG_MAX_MATRIX_CACHE (BGFX_CONFIG_MAX_DRAW_CALLS+1)
#endif // BGFX_CONFIG_MAX_MATRIX_CACHE

#ifndef BGFX_CONFIG_MAX_RECT_CACHE
#	define BGFX_CONFIG_MAX_RECT_CACHE (4<<10)
#endif //  BGFX_CONFIG_MAX_RECT_CACHE

#ifndef BGFX_CONFIG_MAX_VIEWS
// Do not change. Must be power of 2.
#	define BGFX_CONFIG_MAX_VIEWS 256
#endif // BGFX_CONFIG_MAX_VIEWS

#define BGFX_CONFIG_MAX_VIEW_NAME_RESERVED 6

#ifndef BGFX_CONFIG_MAX_VIEW_NAME
#	define BGFX_CONFIG_MAX_VIEW_NAME 256
#endif // BGFX_CONFIG_MAX_VIEW_NAME

#ifndef BGFX_CONFIG_MAX_VERTEX_DECLS
#	define BGFX_CONFIG_MAX_VERTEX_DECLS 64
#endif // BGFX_CONFIG_MAX_VERTEX_DECLS

#ifndef BGFX_CONFIG_MAX_INDEX_BUFFERS
#	define BGFX_CONFIG_MAX_INDEX_BUFFERS (4<<10)
#endif // BGFX_CONFIG_MAX_INDEX_BUFFERS

#ifndef BGFX_CONFIG_MAX_VERTEX_BUFFERS
#	define BGFX_CONFIG_MAX_VERTEX_BUFFERS (4<<10)
#endif // BGFX_CONFIG_MAX_VERTEX_BUFFERS

#ifndef BGFX_CONFIG_MAX_DYNAMIC_INDEX_BUFFERS
#	define BGFX_CONFIG_MAX_DYNAMIC_INDEX_BUFFERS (4<<10)
#endif // BGFX_CONFIG_MAX_DYNAMIC_INDEX_BUFFERS

#ifndef BGFX_CONFIG_MAX_DYNAMIC_VERTEX_BUFFERS
#	define BGFX_CONFIG_MAX_DYNAMIC_VERTEX_BUFFERS (4<<10)
#endif // BGFX_CONFIG_MAX_DYNAMIC_VERTEX_BUFFERS

#ifndef BGFX_CONFIG_DYNAMIC_INDEX_BUFFER_SIZE
#	define BGFX_CONFIG_DYNAMIC_INDEX_BUFFER_SIZE (1<<20)
#endif // BGFX_CONFIG_DYNAMIC_INDEX_BUFFER_SIZE

#ifndef BGFX_CONFIG_DYNAMIC_VERTEX_BUFFER_SIZE
#	define BGFX_CONFIG_DYNAMIC_VERTEX_BUFFER_SIZE (3<<20)
#endif // BGFX_CONFIG_DYNAMIC_VERTEX_BUFFER_SIZE

#ifndef BGFX_CONFIG_MAX_SHADERS
#	define BGFX_CONFIG_MAX_SHADERS 512
#endif // BGFX_CONFIG_MAX_FRAGMENT_SHADERS

#ifndef BGFX_CONFIG_MAX_PROGRAMS
// Must be power of 2.
#	define BGFX_CONFIG_MAX_PROGRAMS 512
#endif // BGFX_CONFIG_MAX_PROGRAMS

#ifndef BGFX_CONFIG_MAX_TEXTURES
#	define BGFX_CONFIG_MAX_TEXTURES (4<<10)
#endif // BGFX_CONFIG_MAX_TEXTURES

#ifndef BGFX_CONFIG_MAX_TEXTURE_SAMPLERS
#	define BGFX_CONFIG_MAX_TEXTURE_SAMPLERS 16
#endif // BGFX_CONFIG_MAX_TEXTURE_SAMPLERS

#ifndef BGFX_CONFIG_MAX_FRAME_BUFFERS
#	define BGFX_CONFIG_MAX_FRAME_BUFFERS 64
#endif // BGFX_CONFIG_MAX_FRAME_BUFFERS

#ifndef BGFX_CONFIG_MAX_FRAME_BUFFER_ATTACHMENTS
#	define BGFX_CONFIG_MAX_FRAME_BUFFER_ATTACHMENTS 8
#endif // BGFX_CONFIG_MAX_FRAME_BUFFER_ATTACHMENTS

#ifndef BGFX_CONFIG_MAX_UNIFORMS
#	define BGFX_CONFIG_MAX_UNIFORMS 512
#endif // BGFX_CONFIG_MAX_UNIFORMS

#ifndef BGFX_CONFIG_MAX_COMMAND_BUFFER_SIZE
#	define BGFX_CONFIG_MAX_COMMAND_BUFFER_SIZE (64<<10)
#endif // BGFX_CONFIG_MAX_COMMAND_BUFFER_SIZE

#ifndef BGFX_CONFIG_TRANSIENT_VERTEX_BUFFER_SIZE
#	define BGFX_CONFIG_TRANSIENT_VERTEX_BUFFER_SIZE (6<<20)
#endif // BGFX_CONFIG_TRANSIENT_VERTEX_BUFFER_SIZE

#ifndef BGFX_CONFIG_TRANSIENT_INDEX_BUFFER_SIZE
#	define BGFX_CONFIG_TRANSIENT_INDEX_BUFFER_SIZE (2<<20)
#endif // BGFX_CONFIG_TRANSIENT_INDEX_BUFFER_SIZE

#ifndef BGFX_CONFIG_MAX_INSTANCE_DATA_COUNT
#	define BGFX_CONFIG_MAX_INSTANCE_DATA_COUNT 5
#endif // BGFX_CONFIG_MAX_INSTANCE_DATA_COUNT

#ifndef BGFX_CONFIG_MAX_CLEAR_COLOR_PALETTE
#	define BGFX_CONFIG_MAX_COLOR_PALETTE 16
#endif // BGFX_CONFIG_MAX_CLEAR_COLOR_PALETTE

#define BGFX_CONFIG_DRAW_INDIRECT_STRIDE 32

#endif // BGFX_CONFIG_H_HEADER_GUARD
