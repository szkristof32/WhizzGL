#include "WhizzGL/WhizzGL.h"

#include <stdio.h>

typedef void (APIENTRYP pfn_glCullFace)(GlCullMode mode);
typedef void (APIENTRYP pfn_glFrontFace)(GlPolygonFace mode);
typedef void (APIENTRYP pfn_glHint)(GlHintTarget target, GlHintMode mode);
typedef void (APIENTRYP pfn_glLineWidth)(GlFloat32 width);
typedef void (APIENTRYP pfn_glPointSize)(GlFloat32 size);
typedef void (APIENTRYP pfn_glPolygonMode)(GlPolygonFace face, GlPolygonMode mode);
typedef void (APIENTRYP pfn_glScissor)(GlInt32 x, GlInt32 y, GlSizei width, GlSizei height);
typedef void (APIENTRYP pfn_glTexParameterf)(GlTextureType target, GlTextureParameter pname, GlFloat32 param);
typedef void (APIENTRYP pfn_glTexParameterfv)(GlTextureType target, GlTextureParameter pname, const GlFloat32* params);
typedef void (APIENTRYP pfn_glTexParameteri)(GlTextureType target, GlTextureParameter pname, GlFloat32 param);
typedef void (APIENTRYP pfn_glTexParameteriv)(GlTextureType target, GlTextureParameter pname, const GlFloat32* params);
typedef void (APIENTRYP pfn_glTexImage1D)(GlTextureType target, GlInt32 level, GlTextureParameter internalformat, GlSizei width, GlInt32 border, GlFormat format, GlDataType type, const void* data);
typedef void (APIENTRYP pfn_glTexImage2D)(GlTextureType target, GlInt32 level, GlTextureParameter internalformat, GlSizei width, GlSizei height, GlInt32 border, GlFormat format, GlDataType type, const void* data);
typedef void (APIENTRYP pfn_glDrawBuffer)(int buffer);
typedef void (APIENTRYP pfn_glClear)(GlClearMask mask);
typedef void (APIENTRYP pfn_glClearColor)(GlFloat32 red, GlFloat32 green, GlFloat32 blue, GlFloat32 alpha);

pfn_glCullFace _glCullFace = NULL;
pfn_glFrontFace _glFrontFace = NULL;
pfn_glHint _glHint = NULL;
pfn_glLineWidth _glLineWidth = NULL;
pfn_glPointSize _glPointSize = NULL;
pfn_glPolygonMode _glPolygonMode = NULL;
pfn_glScissor _glScissor = NULL;
pfn_glTexParameterf _glTexParameterf = NULL;
pfn_glTexParameterfv _glTexParameterfv = NULL;
pfn_glTexParameteri _glTexParameteri = NULL;
pfn_glTexParameteriv _glTexParameteriv = NULL;
pfn_glTexImage1D _glTexImage1D = NULL;
pfn_glTexImage2D _glTexImage2D = NULL;
pfn_glDrawBuffer _glDrawBuffer = NULL;
pfn_glClear _glClear = NULL;
pfn_glClearColor _glClearColor = NULL;

#ifdef _WIN32
#include <Windows.h>

HMODULE _openGLLib = NULL;
#endif

#define INIT_SUCCESS(returnVal)	if (_openGLLib == NULL) { fprintf(stderr, "Error: Couldn't load OpenGL!\n"); return returnVal; }
#define CALL_OPENGL(func, ...)	INIT_SUCCESS(;); if (_##func == NULL) { if (_loadOpenGLFunc(#func, (void**)&_##func) == 0) return; } _##func(__VA_ARGS__)

int APIENTRY wzLoadOpenGL()
{
	_openGLLib = LoadLibraryA("opengl32.dll");
	return _openGLLib != NULL;
}

int APIENTRY wzShutdownOpenGL()
{
	FreeLibrary(_openGLLib);
}

static int _loadOpenGLFunc(const char* name, void** output)
{
	INIT_SUCCESS(0);

#ifdef _WIN32
	void* proc = GetProcAddress(_openGLLib, name);
	if (proc != NULL)
	{
		*output = proc;
		return 1;
	}
#endif

	return 0;
}

void APIENTRY glCullFace(GlCullMode mode)
{
	CALL_OPENGL(glCullFace, mode);
}

void APIENTRY glFrontFace(GlPolygonFace mode)
{
	CALL_OPENGL(glFrontFace, mode);
}

void APIENTRY glHint(GlHintTarget target, GlHintMode mode)
{
	CALL_OPENGL(glFrontFace, mode);
}

void APIENTRY glLineWidth(GlFloat32 width)
{
	CALL_OPENGL(glLineWidth, width);
}

void APIENTRY glPointSize(GlFloat32 size)
{
	CALL_OPENGL(glPointSize, size);
}

void APIENTRY glPolygonMode(GlPolygonFace face, GlPolygonMode mode)
{
	CALL_OPENGL(glPolygonMode, face, mode);
}

void APIENTRY glScissor(GlInt32 x, GlInt32 y, GlSizei width, GlSizei height)
{
	CALL_OPENGL(glScissor, x, y, width, height);
}

void APIENTRY glTexParameterf(GlTextureType target, GlTextureParameter pname, GlFloat32 param)
{
	CALL_OPENGL(glTexParameterf, target, pname, param);
}

void APIENTRY glTexParameterfv(GlTextureType target, GlTextureParameter pname, const GlFloat32* params)
{
	CALL_OPENGL(glTexParameterfv, target, pname, params);
}

void APIENTRY glTexParameteri(GlTextureType target, GlTextureParameter pname, GlFloat32 param)
{
	CALL_OPENGL(glTexParameteri, target, pname, param);
}

void APIENTRY glTexParameteriv(GlTextureType target, GlTextureParameter pname, const GlFloat32* params)
{
	CALL_OPENGL(glTexParameteriv, target, pname, params);
}

void APIENTRY glTexImage1D(GlTextureType target, GlInt32 level, GlTextureParameter internalformat, GlSizei width, GlInt32 border, GlFormat format, GlDataType type, const void* data)
{
	CALL_OPENGL(glTexImage1D, target, level, internalformat, width, border, format, type, data);
}

void APIENTRY glTexImage2D(GlTextureType target, GlInt32 level, GlTextureParameter internalformat, GlSizei width, GlSizei height, GlInt32 border, GlFormat format, GlDataType type, const void* data)
{
	CALL_OPENGL(glTexImage2D, target, level, internalformat, width, height, border, format, type, data);
}

void APIENTRY glDrawBuffer(int buffer)
{
	CALL_OPENGL(glDrawBuffer, buffer);
}

void APIENTRY glClear(GlClearMask mask)
{
	CALL_OPENGL(glClear, mask);
}

void APIENTRY glClearColor(GlFloat32 red, GlFloat32 green, GlFloat32 blue, GlFloat32 alpha)
{
	CALL_OPENGL(glClearColor, red, green, blue, alpha);
}
