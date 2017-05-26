#pragma once
#include <wut.h>
#include <gx2/shaders.h>

/**
 * \defgroup whb_gfx Graphics
 * \ingroup whb
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct WHBGfxShaderGroup WHBGfxShaderGroup;

struct WHBGfxShaderGroup
{
   GX2FetchShader fetchShader;
   void *fetchShaderProgram;
   GX2PixelShader *pixelShader;
   GX2VertexShader *vertexShader;
   uint32_t numAttributes;
   GX2AttribStream attributes[16];
};

BOOL
WHBGfxInit();

void
WHBGfxShutdown();

void
WHBGfxBeginRender();

void
WHBGfxFinishRender();

void
WHBGfxBeginRenderDRC();

void
WHBGfxFinishRenderDRC();

void
WHBGfxBeginRenderTV();

void
WHBGfxFinishRenderTV();

GX2PixelShader *
WHBGfxLoadGFDPixelShader(uint32_t index,
                         const void *file);

BOOL
WHBGfxFreePixelShader(GX2PixelShader *shader);

GX2VertexShader *
WHBGfxLoadGFDVertexShader(uint32_t index,
                          const void *file);

BOOL
WHBGfxFreeVertexShader(GX2VertexShader *shader);

BOOL
WHBGfxLoadGFDShaderGroup(WHBGfxShaderGroup *group,
                         uint32_t index,
                         const void *file);

BOOL
WHBGfxInitShaderAttribute(WHBGfxShaderGroup *group,
                          const char *name,
                          uint32_t buffer,
                          uint32_t offset,
                          GX2AttribFormat format);

BOOL
WHBGfxInitFetchShader(WHBGfxShaderGroup *group);

BOOL
WHBGfxFreeShaderGroup(WHBGfxShaderGroup *group);

#ifdef __cplusplus
}
#endif

/** @} */