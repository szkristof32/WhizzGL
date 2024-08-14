#include "WhizzGL/WhizzGL.h"

#include <stdio.h>

typedef void (APIENTRYP pfn_glCullFace)(GLcullmode_t mode);
typedef void (APIENTRYP pfn_glFrontFace)(GLpolygonface_t mode);
typedef void (APIENTRYP pfn_glHint)(GLhinttarget_t target, GLhintmode_t mode);
typedef void (APIENTRYP pfn_glLineWidth)(GLfloat width);
typedef void (APIENTRYP pfn_glPointSize)(GLfloat size);
typedef void (APIENTRYP pfn_glPolygonMode)(GLpolygonface_t face, GLpolygonmode_t mode);
typedef void (APIENTRYP pfn_glScissor)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP pfn_glTexParameterf)(GLtexturetype_t target, GLtextureparameter_t pname, GLfloat param);
typedef void (APIENTRYP pfn_glTexParameterfv)(GLtexturetype_t target, GLtextureparameter_t pname, const GLfloat* params);
typedef void (APIENTRYP pfn_glTexParameteri)(GLtexturetype_t target, GLtextureparameter_t pname, GLint param);
typedef void (APIENTRYP pfn_glTexParameteriv)(GLtexturetype_t target, GLtextureparameter_t pname, const GLint* params);
typedef void (APIENTRYP pfn_glTexImage1D)(GLtexturetype_t target, GLint level, GLinternalformat_t internalformat, GLsizei width, GLint border, GLformat_t format, GLdatatype_t type, const void* data);
typedef void (APIENTRYP pfn_glTexImage2D)(GLtexturetype_t target, GLint level, GLinternalformat_t internalformat, GLsizei width, GLsizei height, GLint border, GLformat_t format, GLdatatype_t type, const void* data);
typedef void (APIENTRYP pfn_glDrawBuffer)(int buffer);
typedef void (APIENTRYP pfn_glClear)(GLclearmask_t mask);
typedef void (APIENTRYP pfn_glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

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

void APIENTRY glCullFace(GLcullmode_t mode)
{
	CALL_OPENGL(glCullFace, mode);
}

void APIENTRY glFrontFace(GLpolygonface_t mode)
{
	CALL_OPENGL(glFrontFace, mode);
}

void APIENTRY glHint(GLhinttarget_t target, GLhintmode_t mode)
{
	CALL_OPENGL(glFrontFace, mode);
}

void APIENTRY glLineWidth(GLfloat width)
{
	CALL_OPENGL(glLineWidth, width);
}

void APIENTRY glPointSize(GLfloat size)
{
	CALL_OPENGL(glPointSize, size);
}

void APIENTRY glPolygonMode(GLpolygonface_t face, GLpolygonmode_t mode)
{
	CALL_OPENGL(glPolygonMode, face, mode);
}

void APIENTRY glScissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
	CALL_OPENGL(glScissor, x, y, width, height);
}

void APIENTRY glTexParameterf(GLtexturetype_t target, GLtextureparameter_t pname, GLfloat param)
{
	CALL_OPENGL(glTexParameterf, target, pname, param);
}

void APIENTRY glTexParameterfv(GLtexturetype_t target, GLtextureparameter_t pname, const GLfloat* params)
{
	CALL_OPENGL(glTexParameterfv, target, pname, params);
}

void APIENTRY glTexParameteri(GLtexturetype_t target, GLtextureparameter_t pname, GLint param)
{
	CALL_OPENGL(glTexParameteri, target, pname, param);
}

void APIENTRY glTexParameteriv(GLtexturetype_t target, GLtextureparameter_t pname, const GLint* params)
{
	CALL_OPENGL(glTexParameteriv, target, pname, params);
}

void APIENTRY glTexImage1D(GLtexturetype_t target, GLint level, GLinternalformat_t internalformat, GLsizei width, GLint border, GLformat_t format, GLdatatype_t type, const void* data)
{
	CALL_OPENGL(glTexImage1D, target, level, internalformat, width, border, format, type, data);
}

void APIENTRY glTexImage2D(GLtexturetype_t target, GLint level, GLinternalformat_t internalformat, GLsizei width, GLsizei height, GLint border, GLformat_t format, GLdatatype_t type, const void* data)
{
	CALL_OPENGL(glTexImage2D, target, level, internalformat, width, height, border, format, type, data);
}

void APIENTRY glDrawBuffer(int buffer)
{
	CALL_OPENGL(glDrawBuffer, buffer);
}

void APIENTRY glClear(GLclearmask_t mask)
{
	CALL_OPENGL(glClear, mask);
}

void APIENTRY glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	CALL_OPENGL(glClearColor, red, green, blue, alpha);
}
