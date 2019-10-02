//---------------------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This file is automatically generated.  Please do not edit it directly.
//
// File name: D2D1_2.h
//---------------------------------------------------------------------------
#ifdef _MSC_VER
#pragma once
#endif // #ifdef _MSC_VER

#ifndef _D2D1_2_H_
#define _D2D1_2_H_

#ifndef _D2D1_1_H_
#include <d2d1_1.h>
#endif // #ifndef _D2D1_1_H_
#ifndef _D2D1_EFFECTS_1_
#include <d2d1effects_1.h>
#endif // #ifndef _D2D1_EFFECTS_1_

#include <winapifamily.h>

#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)

#ifndef D2D_USE_C_DEFINITIONS

interface ID2D1Device1;
#else

typedef interface ID2D1Device1 ID2D1Device1;

#endif

//+-----------------------------------------------------------------------------
//
//  Enum:
//      D2D1_RENDERING_PRIORITY
//
//  Synopsis:
//      Specifies the extent to which D2D will throttle work sent to the GPU.
//
//------------------------------------------------------------------------------
typedef enum D2D1_RENDERING_PRIORITY
{
        D2D1_RENDERING_PRIORITY_NORMAL = 0,
        D2D1_RENDERING_PRIORITY_LOW = 1,
        D2D1_RENDERING_PRIORITY_FORCE_DWORD = 0xffffffff

} D2D1_RENDERING_PRIORITY;


#ifndef D2D_USE_C_DEFINITIONS



//+-----------------------------------------------------------------------------
//
//  Interface:
//      ID2D1GeometryRealization
//
//------------------------------------------------------------------------------
interface DX_DECLARE_INTERFACE("a16907d7-bc02-4801-99e8-8cf7f485f774") ID2D1GeometryRealization  : public ID2D1Resource
{
}; // interface ID2D1GeometryRealization



//+-----------------------------------------------------------------------------
//
//  Interface:
//      ID2D1DeviceContext1
//
//------------------------------------------------------------------------------
interface DX_DECLARE_INTERFACE("d37f57e4-6908-459f-a199-e72f24f79987") ID2D1DeviceContext1  : public ID2D1DeviceContext
{
    
    STDMETHOD(CreateFilledGeometryRealization)(
        _In_ ID2D1Geometry *geometry,
        FLOAT flatteningTolerance,
        _Outptr_ ID2D1GeometryRealization **geometryRealization 
        ) PURE;
    
    STDMETHOD(CreateStrokedGeometryRealization)(
        _In_ ID2D1Geometry *geometry,
        FLOAT flatteningTolerance,
        FLOAT strokeWidth,
        _In_opt_ ID2D1StrokeStyle *strokeStyle,
        _Outptr_ ID2D1GeometryRealization **geometryRealization 
        ) PURE;
    
    STDMETHOD_(void, DrawGeometryRealization)(
        _In_ ID2D1GeometryRealization *geometryRealization,
        _In_ ID2D1Brush *brush 
        ) PURE;
}; // interface ID2D1DeviceContext1



//+-----------------------------------------------------------------------------
//
//  Interface:
//      ID2D1Device1
//
//------------------------------------------------------------------------------
interface DX_DECLARE_INTERFACE("d21768e1-23a4-4823-a14b-7c3eba85d658") ID2D1Device1  : public ID2D1Device
{
    
    
    //
    // Retrieves the rendering priority currently set on the device.
    //
    STDMETHOD_(D2D1_RENDERING_PRIORITY, GetRenderingPriority)(
        ) PURE;
    
    
    //
    // Sets the rendering priority of the device.
    //
    STDMETHOD_(void, SetRenderingPriority)(
        D2D1_RENDERING_PRIORITY renderingPriority 
        ) PURE;
    
    
    //
    // Creates a new device context with no initially assigned target.
    //
    STDMETHOD(CreateDeviceContext)(
        D2D1_DEVICE_CONTEXT_OPTIONS options,
        _Outptr_ ID2D1DeviceContext1 **deviceContext1 
        ) PURE;
    
    using ID2D1Device::CreateDeviceContext;
}; // interface ID2D1Device1



//+-----------------------------------------------------------------------------
//
//  Interface:
//      ID2D1Factory2
//
//------------------------------------------------------------------------------
interface DX_DECLARE_INTERFACE("94f81a73-9212-4376-9c58-b16a3a0d3992") ID2D1Factory2  : public ID2D1Factory1
{
    
    
    //
    // This creates a new Direct2D device from the given IDXGIDevice.
    //
    STDMETHOD(CreateDevice)(
        _In_ IDXGIDevice *dxgiDevice,
        _Outptr_ ID2D1Device1 **d2dDevice1 
        ) PURE;
    
    using ID2D1Factory1::CreateDevice;
}; // interface ID2D1Factory2



//+-----------------------------------------------------------------------------
//
//  Interface:
//      ID2D1CommandSink1
//
//------------------------------------------------------------------------------
interface DX_DECLARE_INTERFACE("9eb767fd-4269-4467-b8c2-eb30cb305743") ID2D1CommandSink1  : public ID2D1CommandSink
{
    
    
    //
    // This method is called if primitiveBlend value was added after Windows 8.
    // SetPrimitiveBlend method is used for Win8 values (_SOURCE_OVER and _COPY).
    //
    STDMETHOD(SetPrimitiveBlend1)(
        D2D1_PRIMITIVE_BLEND primitiveBlend 
        ) PURE;
}; // interface ID2D1CommandSink1



#endif


EXTERN_C CONST IID IID_ID2D1GeometryRealization;
EXTERN_C CONST IID IID_ID2D1DeviceContext1;
EXTERN_C CONST IID IID_ID2D1Device1;
EXTERN_C CONST IID IID_ID2D1Factory2;
EXTERN_C CONST IID IID_ID2D1CommandSink1;


#ifdef D2D_USE_C_DEFINITIONS


typedef interface ID2D1GeometryRealization ID2D1GeometryRealization;

typedef struct ID2D1GeometryRealizationVtbl
{
    
    ID2D1ResourceVtbl Base;
    
} ID2D1GeometryRealizationVtbl;

interface ID2D1GeometryRealization
{
    CONST struct ID2D1GeometryRealizationVtbl *lpVtbl;
};


#define ID2D1GeometryRealization_QueryInterface(This, riid, ppv) \
    ((This)->lpVtbl->Base.Base.QueryInterface((IUnknown *)This, riid, ppv))

#define ID2D1GeometryRealization_AddRef(This) \
    ((This)->lpVtbl->Base.Base.AddRef((IUnknown *)This))

#define ID2D1GeometryRealization_Release(This) \
    ((This)->lpVtbl->Base.Base.Release((IUnknown *)This))

#define ID2D1GeometryRealization_GetFactory(This, factory) \
    ((This)->lpVtbl->Base.GetFactory((ID2D1Resource *)This, factory))

typedef interface ID2D1DeviceContext1 ID2D1DeviceContext1;

typedef struct ID2D1DeviceContext1Vtbl
{
    
    ID2D1DeviceContextVtbl Base;
    
    
    STDMETHOD(CreateFilledGeometryRealization)(
        ID2D1DeviceContext1 *This,
        _In_ ID2D1Geometry *geometry,
        FLOAT flatteningTolerance,
        _Outptr_ ID2D1GeometryRealization **geometryRealization 
        ) PURE;
    
    STDMETHOD(CreateStrokedGeometryRealization)(
        ID2D1DeviceContext1 *This,
        _In_ ID2D1Geometry *geometry,
        FLOAT flatteningTolerance,
        FLOAT strokeWidth,
        _In_opt_ ID2D1StrokeStyle *strokeStyle,
        _Outptr_ ID2D1GeometryRealization **geometryRealization 
        ) PURE;
    
    STDMETHOD_(void, DrawGeometryRealization)(
        ID2D1DeviceContext1 *This,
        _In_ ID2D1GeometryRealization *geometryRealization,
        _In_ ID2D1Brush *brush 
        ) PURE;
} ID2D1DeviceContext1Vtbl;

interface ID2D1DeviceContext1
{
    CONST struct ID2D1DeviceContext1Vtbl *lpVtbl;
};


#define ID2D1DeviceContext1_QueryInterface(This, riid, ppv) \
    ((This)->lpVtbl->Base.Base.Base.Base.QueryInterface((IUnknown *)This, riid, ppv))

#define ID2D1DeviceContext1_AddRef(This) \
    ((This)->lpVtbl->Base.Base.Base.Base.AddRef((IUnknown *)This))

#define ID2D1DeviceContext1_Release(This) \
    ((This)->lpVtbl->Base.Base.Base.Base.Release((IUnknown *)This))

#define ID2D1DeviceContext1_GetFactory(This, factory) \
    ((This)->lpVtbl->Base.Base.Base.GetFactory((ID2D1Resource *)This, factory))

#define ID2D1DeviceContext1_CreateSharedBitmap(This, riid, data, bitmapProperties, bitmap) \
    ((This)->lpVtbl->Base.Base.CreateSharedBitmap((ID2D1RenderTarget *)This, riid, data, bitmapProperties, bitmap))

#define ID2D1DeviceContext1_CreateSolidColorBrush(This, color, brushProperties, solidColorBrush) \
    ((This)->lpVtbl->Base.Base.CreateSolidColorBrush((ID2D1RenderTarget *)This, color, brushProperties, solidColorBrush))

#define ID2D1DeviceContext1_CreateLinearGradientBrush(This, linearGradientBrushProperties, brushProperties, gradientStopCollection, linearGradientBrush) \
    ((This)->lpVtbl->Base.Base.CreateLinearGradientBrush((ID2D1RenderTarget *)This, linearGradientBrushProperties, brushProperties, gradientStopCollection, linearGradientBrush))

#define ID2D1DeviceContext1_CreateRadialGradientBrush(This, radialGradientBrushProperties, brushProperties, gradientStopCollection, radialGradientBrush) \
    ((This)->lpVtbl->Base.Base.CreateRadialGradientBrush((ID2D1RenderTarget *)This, radialGradientBrushProperties, brushProperties, gradientStopCollection, radialGradientBrush))

#define ID2D1DeviceContext1_CreateCompatibleRenderTarget(This, desiredSize, desiredPixelSize, desiredFormat, options, bitmapRenderTarget) \
    ((This)->lpVtbl->Base.Base.CreateCompatibleRenderTarget((ID2D1RenderTarget *)This, desiredSize, desiredPixelSize, desiredFormat, options, bitmapRenderTarget))

#define ID2D1DeviceContext1_CreateLayer(This, size, layer) \
    ((This)->lpVtbl->Base.Base.CreateLayer((ID2D1RenderTarget *)This, size, layer))

#define ID2D1DeviceContext1_CreateMesh(This, mesh) \
    ((This)->lpVtbl->Base.Base.CreateMesh((ID2D1RenderTarget *)This, mesh))

#define ID2D1DeviceContext1_DrawLine(This, point0, point1, brush, strokeWidth, strokeStyle) \
    ((This)->lpVtbl->Base.Base.DrawLine((ID2D1RenderTarget *)This, point0, point1, brush, strokeWidth, strokeStyle))

#define ID2D1DeviceContext1_DrawRectangle(This, rect, brush, strokeWidth, strokeStyle) \
    ((This)->lpVtbl->Base.Base.DrawRectangle((ID2D1RenderTarget *)This, rect, brush, strokeWidth, strokeStyle))

#define ID2D1DeviceContext1_FillRectangle(This, rect, brush) \
    ((This)->lpVtbl->Base.Base.FillRectangle((ID2D1RenderTarget *)This, rect, brush))

#define ID2D1DeviceContext1_DrawRoundedRectangle(This, roundedRect, brush, strokeWidth, strokeStyle) \
    ((This)->lpVtbl->Base.Base.DrawRoundedRectangle((ID2D1RenderTarget *)This, roundedRect, brush, strokeWidth, strokeStyle))

#define ID2D1DeviceContext1_FillRoundedRectangle(This, roundedRect, brush) \
    ((This)->lpVtbl->Base.Base.FillRoundedRectangle((ID2D1RenderTarget *)This, roundedRect, brush))

#define ID2D1DeviceContext1_DrawEllipse(This, ellipse, brush, strokeWidth, strokeStyle) \
    ((This)->lpVtbl->Base.Base.DrawEllipse((ID2D1RenderTarget *)This, ellipse, brush, strokeWidth, strokeStyle))

#define ID2D1DeviceContext1_FillEllipse(This, ellipse, brush) \
    ((This)->lpVtbl->Base.Base.FillEllipse((ID2D1RenderTarget *)This, ellipse, brush))

#define ID2D1DeviceContext1_DrawGeometry(This, geometry, brush, strokeWidth, strokeStyle) \
    ((This)->lpVtbl->Base.Base.DrawGeometry((ID2D1RenderTarget *)This, geometry, brush, strokeWidth, strokeStyle))

#define ID2D1DeviceContext1_FillGeometry(This, geometry, brush, opacityBrush) \
    ((This)->lpVtbl->Base.Base.FillGeometry((ID2D1RenderTarget *)This, geometry, brush, opacityBrush))

#define ID2D1DeviceContext1_FillMesh(This, mesh, brush) \
    ((This)->lpVtbl->Base.Base.FillMesh((ID2D1RenderTarget *)This, mesh, brush))

#define ID2D1DeviceContext1_DrawText(This, string, stringLength, textFormat, layoutRect, defaultForegroundBrush, options, measuringMode) \
    ((This)->lpVtbl->Base.Base.DrawText((ID2D1RenderTarget *)This, string, stringLength, textFormat, layoutRect, defaultForegroundBrush, options, measuringMode))

#define ID2D1DeviceContext1_DrawTextLayout(This, origin, textLayout, defaultForegroundBrush, options) \
    ((This)->lpVtbl->Base.Base.DrawTextLayout((ID2D1RenderTarget *)This, origin, textLayout, defaultForegroundBrush, options))

#define ID2D1DeviceContext1_SetTransform(This, transform) \
    ((This)->lpVtbl->Base.Base.SetTransform((ID2D1RenderTarget *)This, transform))

#define ID2D1DeviceContext1_GetTransform(This, transform) \
    ((This)->lpVtbl->Base.Base.GetTransform((ID2D1RenderTarget *)This, transform))

#define ID2D1DeviceContext1_SetAntialiasMode(This, antialiasMode) \
    ((This)->lpVtbl->Base.Base.SetAntialiasMode((ID2D1RenderTarget *)This, antialiasMode))

#define ID2D1DeviceContext1_GetAntialiasMode(This) \
    ((This)->lpVtbl->Base.Base.GetAntialiasMode((ID2D1RenderTarget *)This))

#define ID2D1DeviceContext1_SetTextAntialiasMode(This, textAntialiasMode) \
    ((This)->lpVtbl->Base.Base.SetTextAntialiasMode((ID2D1RenderTarget *)This, textAntialiasMode))

#define ID2D1DeviceContext1_GetTextAntialiasMode(This) \
    ((This)->lpVtbl->Base.Base.GetTextAntialiasMode((ID2D1RenderTarget *)This))

#define ID2D1DeviceContext1_SetTextRenderingParams(This, textRenderingParams) \
    ((This)->lpVtbl->Base.Base.SetTextRenderingParams((ID2D1RenderTarget *)This, textRenderingParams))

#define ID2D1DeviceContext1_GetTextRenderingParams(This, textRenderingParams) \
    ((This)->lpVtbl->Base.Base.GetTextRenderingParams((ID2D1RenderTarget *)This, textRenderingParams))

#define ID2D1DeviceContext1_SetTags(This, tag1, tag2) \
    ((This)->lpVtbl->Base.Base.SetTags((ID2D1RenderTarget *)This, tag1, tag2))

#define ID2D1DeviceContext1_GetTags(This, tag1, tag2) \
    ((This)->lpVtbl->Base.Base.GetTags((ID2D1RenderTarget *)This, tag1, tag2))

#define ID2D1DeviceContext1_PopLayer(This) \
    ((This)->lpVtbl->Base.Base.PopLayer((ID2D1RenderTarget *)This))

#define ID2D1DeviceContext1_Flush(This, tag1, tag2) \
    ((This)->lpVtbl->Base.Base.Flush((ID2D1RenderTarget *)This, tag1, tag2))

#define ID2D1DeviceContext1_SaveDrawingState(This, drawingStateBlock) \
    ((This)->lpVtbl->Base.Base.SaveDrawingState((ID2D1RenderTarget *)This, drawingStateBlock))

#define ID2D1DeviceContext1_RestoreDrawingState(This, drawingStateBlock) \
    ((This)->lpVtbl->Base.Base.RestoreDrawingState((ID2D1RenderTarget *)This, drawingStateBlock))

#define ID2D1DeviceContext1_PushAxisAlignedClip(This, clipRect, antialiasMode) \
    ((This)->lpVtbl->Base.Base.PushAxisAlignedClip((ID2D1RenderTarget *)This, clipRect, antialiasMode))

#define ID2D1DeviceContext1_PopAxisAlignedClip(This) \
    ((This)->lpVtbl->Base.Base.PopAxisAlignedClip((ID2D1RenderTarget *)This))

#define ID2D1DeviceContext1_Clear(This, clearColor) \
    ((This)->lpVtbl->Base.Base.Clear((ID2D1RenderTarget *)This, clearColor))

#define ID2D1DeviceContext1_BeginDraw(This) \
    ((This)->lpVtbl->Base.Base.BeginDraw((ID2D1RenderTarget *)This))

#define ID2D1DeviceContext1_EndDraw(This, tag1, tag2) \
    ((This)->lpVtbl->Base.Base.EndDraw((ID2D1RenderTarget *)This, tag1, tag2))

#define ID2D1DeviceContext1_GetPixelFormat(This) \
    ((This)->lpVtbl->Base.Base.GetPixelFormat((ID2D1RenderTarget *)This))

#define ID2D1DeviceContext1_SetDpi(This, dpiX, dpiY) \
    ((This)->lpVtbl->Base.Base.SetDpi((ID2D1RenderTarget *)This, dpiX, dpiY))

#define ID2D1DeviceContext1_GetDpi(This, dpiX, dpiY) \
    ((This)->lpVtbl->Base.Base.GetDpi((ID2D1RenderTarget *)This, dpiX, dpiY))

#define ID2D1DeviceContext1_GetSize(This) \
    ((This)->lpVtbl->Base.Base.GetSize((ID2D1RenderTarget *)This))

#define ID2D1DeviceContext1_GetPixelSize(This) \
    ((This)->lpVtbl->Base.Base.GetPixelSize((ID2D1RenderTarget *)This))

#define ID2D1DeviceContext1_GetMaximumBitmapSize(This) \
    ((This)->lpVtbl->Base.Base.GetMaximumBitmapSize((ID2D1RenderTarget *)This))

#define ID2D1DeviceContext1_IsSupported(This, renderTargetProperties) \
    ((This)->lpVtbl->Base.Base.IsSupported((ID2D1RenderTarget *)This, renderTargetProperties))

#define ID2D1DeviceContext1_CreateBitmap(This, size, sourceData, pitch, bitmapProperties, bitmap) \
    ((This)->lpVtbl->Base.CreateBitmap((ID2D1DeviceContext *)This, size, sourceData, pitch, bitmapProperties, bitmap))

#define ID2D1DeviceContext1_CreateBitmapFromWicBitmap(This, wicBitmapSource, bitmapProperties, bitmap) \
    ((This)->lpVtbl->Base.CreateBitmapFromWicBitmap((ID2D1DeviceContext *)This, wicBitmapSource, bitmapProperties, bitmap))

#define ID2D1DeviceContext1_CreateColorContext(This, space, profile, profileSize, colorContext) \
    ((This)->lpVtbl->Base.CreateColorContext((ID2D1DeviceContext *)This, space, profile, profileSize, colorContext))

#define ID2D1DeviceContext1_CreateColorContextFromFilename(This, filename, colorContext) \
    ((This)->lpVtbl->Base.CreateColorContextFromFilename((ID2D1DeviceContext *)This, filename, colorContext))

#define ID2D1DeviceContext1_CreateColorContextFromWicColorContext(This, wicColorContext, colorContext) \
    ((This)->lpVtbl->Base.CreateColorContextFromWicColorContext((ID2D1DeviceContext *)This, wicColorContext, colorContext))

#define ID2D1DeviceContext1_CreateBitmapFromDxgiSurface(This, surface, bitmapProperties, bitmap) \
    ((This)->lpVtbl->Base.CreateBitmapFromDxgiSurface((ID2D1DeviceContext *)This, surface, bitmapProperties, bitmap))

#define ID2D1DeviceContext1_CreateEffect(This, effectId, effect) \
    ((This)->lpVtbl->Base.CreateEffect((ID2D1DeviceContext *)This, effectId, effect))

#define ID2D1DeviceContext1_CreateGradientStopCollection(This, straightAlphaGradientStops, straightAlphaGradientStopsCount, preInterpolationSpace, postInterpolationSpace, bufferPrecision, extendMode, colorInterpolationMode, gradientStopCollection1) \
    ((This)->lpVtbl->Base.CreateGradientStopCollection((ID2D1DeviceContext *)This, straightAlphaGradientStops, straightAlphaGradientStopsCount, preInterpolationSpace, postInterpolationSpace, bufferPrecision, extendMode, colorInterpolationMode, gradientStopCollection1))

#define ID2D1DeviceContext1_CreateImageBrush(This, image, imageBrushProperties, brushProperties, imageBrush) \
    ((This)->lpVtbl->Base.CreateImageBrush((ID2D1DeviceContext *)This, image, imageBrushProperties, brushProperties, imageBrush))

#define ID2D1DeviceContext1_CreateBitmapBrush(This, bitmap, bitmapBrushProperties, brushProperties, bitmapBrush) \
    ((This)->lpVtbl->Base.CreateBitmapBrush((ID2D1DeviceContext *)This, bitmap, bitmapBrushProperties, brushProperties, bitmapBrush))

#define ID2D1DeviceContext1_CreateCommandList(This, commandList) \
    ((This)->lpVtbl->Base.CreateCommandList((ID2D1DeviceContext *)This, commandList))

#define ID2D1DeviceContext1_IsDxgiFormatSupported(This, format) \
    ((This)->lpVtbl->Base.IsDxgiFormatSupported((ID2D1DeviceContext *)This, format))

#define ID2D1DeviceContext1_IsBufferPrecisionSupported(This, bufferPrecision) \
    ((This)->lpVtbl->Base.IsBufferPrecisionSupported((ID2D1DeviceContext *)This, bufferPrecision))

#define ID2D1DeviceContext1_GetImageLocalBounds(This, image, localBounds) \
    ((This)->lpVtbl->Base.GetImageLocalBounds((ID2D1DeviceContext *)This, image, localBounds))

#define ID2D1DeviceContext1_GetImageWorldBounds(This, image, worldBounds) \
    ((This)->lpVtbl->Base.GetImageWorldBounds((ID2D1DeviceContext *)This, image, worldBounds))

#define ID2D1DeviceContext1_GetGlyphRunWorldBounds(This, baselineOrigin, glyphRun, measuringMode, bounds) \
    ((This)->lpVtbl->Base.GetGlyphRunWorldBounds((ID2D1DeviceContext *)This, baselineOrigin, glyphRun, measuringMode, bounds))

#define ID2D1DeviceContext1_GetDevice(This, device) \
    ((This)->lpVtbl->Base.GetDevice((ID2D1DeviceContext *)This, device))

#define ID2D1DeviceContext1_SetTarget(This, image) \
    ((This)->lpVtbl->Base.SetTarget((ID2D1DeviceContext *)This, image))

#define ID2D1DeviceContext1_GetTarget(This, image) \
    ((This)->lpVtbl->Base.GetTarget((ID2D1DeviceContext *)This, image))

#define ID2D1DeviceContext1_SetRenderingControls(This, renderingControls) \
    ((This)->lpVtbl->Base.SetRenderingControls((ID2D1DeviceContext *)This, renderingControls))

#define ID2D1DeviceContext1_GetRenderingControls(This, renderingControls) \
    ((This)->lpVtbl->Base.GetRenderingControls((ID2D1DeviceContext *)This, renderingControls))

#define ID2D1DeviceContext1_SetPrimitiveBlend(This, primitiveBlend) \
    ((This)->lpVtbl->Base.SetPrimitiveBlend((ID2D1DeviceContext *)This, primitiveBlend))

#define ID2D1DeviceContext1_GetPrimitiveBlend(This) \
    ((This)->lpVtbl->Base.GetPrimitiveBlend((ID2D1DeviceContext *)This))

#define ID2D1DeviceContext1_SetUnitMode(This, unitMode) \
    ((This)->lpVtbl->Base.SetUnitMode((ID2D1DeviceContext *)This, unitMode))

#define ID2D1DeviceContext1_GetUnitMode(This) \
    ((This)->lpVtbl->Base.GetUnitMode((ID2D1DeviceContext *)This))

#define ID2D1DeviceContext1_DrawGlyphRun(This, baselineOrigin, glyphRun, glyphRunDescription, foregroundBrush, measuringMode) \
    ((This)->lpVtbl->Base.DrawGlyphRun((ID2D1DeviceContext *)This, baselineOrigin, glyphRun, glyphRunDescription, foregroundBrush, measuringMode))

#define ID2D1DeviceContext1_DrawImage(This, image, targetOffset, imageRectangle, interpolationMode, compositeMode) \
    ((This)->lpVtbl->Base.DrawImage((ID2D1DeviceContext *)This, image, targetOffset, imageRectangle, interpolationMode, compositeMode))

#define ID2D1DeviceContext1_DrawGdiMetafile(This, gdiMetafile, targetOffset) \
    ((This)->lpVtbl->Base.DrawGdiMetafile((ID2D1DeviceContext *)This, gdiMetafile, targetOffset))

#define ID2D1DeviceContext1_DrawBitmap(This, bitmap, destinationRectangle, opacity, interpolationMode, sourceRectangle, perspectiveTransform) \
    ((This)->lpVtbl->Base.DrawBitmap((ID2D1DeviceContext *)This, bitmap, destinationRectangle, opacity, interpolationMode, sourceRectangle, perspectiveTransform))

#define ID2D1DeviceContext1_PushLayer(This, layerParameters, layer) \
    ((This)->lpVtbl->Base.PushLayer((ID2D1DeviceContext *)This, layerParameters, layer))

#define ID2D1DeviceContext1_InvalidateEffectInputRectangle(This, effect, input, inputRectangle) \
    ((This)->lpVtbl->Base.InvalidateEffectInputRectangle((ID2D1DeviceContext *)This, effect, input, inputRectangle))

#define ID2D1DeviceContext1_GetEffectInvalidRectangleCount(This, effect, rectangleCount) \
    ((This)->lpVtbl->Base.GetEffectInvalidRectangleCount((ID2D1DeviceContext *)This, effect, rectangleCount))

#define ID2D1DeviceContext1_GetEffectInvalidRectangles(This, effect, rectangles, rectanglesCount) \
    ((This)->lpVtbl->Base.GetEffectInvalidRectangles((ID2D1DeviceContext *)This, effect, rectangles, rectanglesCount))

#define ID2D1DeviceContext1_GetEffectRequiredInputRectangles(This, renderEffect, renderImageRectangle, inputDescriptions, requiredInputRects, inputCount) \
    ((This)->lpVtbl->Base.GetEffectRequiredInputRectangles((ID2D1DeviceContext *)This, renderEffect, renderImageRectangle, inputDescriptions, requiredInputRects, inputCount))

#define ID2D1DeviceContext1_FillOpacityMask(This, opacityMask, brush, destinationRectangle, sourceRectangle) \
    ((This)->lpVtbl->Base.FillOpacityMask((ID2D1DeviceContext *)This, opacityMask, brush, destinationRectangle, sourceRectangle))

#define ID2D1DeviceContext1_CreateFilledGeometryRealization(This, geometry, flatteningTolerance, geometryRealization) \
    ((This)->lpVtbl->CreateFilledGeometryRealization(This, geometry, flatteningTolerance, geometryRealization))

#define ID2D1DeviceContext1_CreateStrokedGeometryRealization(This, geometry, flatteningTolerance, strokeWidth, strokeStyle, geometryRealization) \
    ((This)->lpVtbl->CreateStrokedGeometryRealization(This, geometry, flatteningTolerance, strokeWidth, strokeStyle, geometryRealization))

#define ID2D1DeviceContext1_DrawGeometryRealization(This, geometryRealization, brush) \
    ((This)->lpVtbl->DrawGeometryRealization(This, geometryRealization, brush))

typedef interface ID2D1Device1 ID2D1Device1;

typedef struct ID2D1Device1Vtbl
{
    
    ID2D1DeviceVtbl Base;
    
    
    STDMETHOD_(D2D1_RENDERING_PRIORITY, GetRenderingPriority)(
        ID2D1Device1 *This 
        ) PURE;
    
    STDMETHOD_(void, SetRenderingPriority)(
        ID2D1Device1 *This,
        D2D1_RENDERING_PRIORITY renderingPriority 
        ) PURE;
    
    STDMETHOD(CreateDeviceContext)(
        ID2D1Device1 *This,
        D2D1_DEVICE_CONTEXT_OPTIONS options,
        _Outptr_ ID2D1DeviceContext1 **deviceContext1 
        ) PURE;
} ID2D1Device1Vtbl;

interface ID2D1Device1
{
    CONST struct ID2D1Device1Vtbl *lpVtbl;
};


#define ID2D1Device1_QueryInterface(This, riid, ppv) \
    ((This)->lpVtbl->Base.Base.Base.QueryInterface((IUnknown *)This, riid, ppv))

#define ID2D1Device1_AddRef(This) \
    ((This)->lpVtbl->Base.Base.Base.AddRef((IUnknown *)This))

#define ID2D1Device1_Release(This) \
    ((This)->lpVtbl->Base.Base.Base.Release((IUnknown *)This))

#define ID2D1Device1_GetFactory(This, factory) \
    ((This)->lpVtbl->Base.Base.GetFactory((ID2D1Resource *)This, factory))

#define ID2D1Device1_CreatePrintControl(This, wicFactory, documentTarget, printControlProperties, printControl) \
    ((This)->lpVtbl->Base.CreatePrintControl((ID2D1Device *)This, wicFactory, documentTarget, printControlProperties, printControl))

#define ID2D1Device1_SetMaximumTextureMemory(This, maximumInBytes) \
    ((This)->lpVtbl->Base.SetMaximumTextureMemory((ID2D1Device *)This, maximumInBytes))

#define ID2D1Device1_GetMaximumTextureMemory(This) \
    ((This)->lpVtbl->Base.GetMaximumTextureMemory((ID2D1Device *)This))

#define ID2D1Device1_ClearResources(This, millisecondsSinceUse) \
    ((This)->lpVtbl->Base.ClearResources((ID2D1Device *)This, millisecondsSinceUse))

#define ID2D1Device1_GetRenderingPriority(This) \
    ((This)->lpVtbl->GetRenderingPriority(This))

#define ID2D1Device1_SetRenderingPriority(This, renderingPriority) \
    ((This)->lpVtbl->SetRenderingPriority(This, renderingPriority))

#define ID2D1Device1_CreateDeviceContext(This, options, deviceContext1) \
    ((This)->lpVtbl->CreateDeviceContext(This, options, deviceContext1))

typedef interface ID2D1Factory2 ID2D1Factory2;

typedef struct ID2D1Factory2Vtbl
{
    
    ID2D1Factory1Vtbl Base;
    
    
    STDMETHOD(CreateDevice)(
        ID2D1Factory2 *This,
        _In_ IDXGIDevice *dxgiDevice,
        _Outptr_ ID2D1Device1 **d2dDevice1 
        ) PURE;
} ID2D1Factory2Vtbl;

interface ID2D1Factory2
{
    CONST struct ID2D1Factory2Vtbl *lpVtbl;
};


#define ID2D1Factory2_QueryInterface(This, riid, ppv) \
    ((This)->lpVtbl->Base.Base.Base.QueryInterface((IUnknown *)This, riid, ppv))

#define ID2D1Factory2_AddRef(This) \
    ((This)->lpVtbl->Base.Base.Base.AddRef((IUnknown *)This))

#define ID2D1Factory2_Release(This) \
    ((This)->lpVtbl->Base.Base.Base.Release((IUnknown *)This))

#define ID2D1Factory2_ReloadSystemMetrics(This) \
    ((This)->lpVtbl->Base.Base.ReloadSystemMetrics((ID2D1Factory *)This))

#define ID2D1Factory2_GetDesktopDpi(This, dpiX, dpiY) \
    ((This)->lpVtbl->Base.Base.GetDesktopDpi((ID2D1Factory *)This, dpiX, dpiY))

#define ID2D1Factory2_CreateRectangleGeometry(This, rectangle, rectangleGeometry) \
    ((This)->lpVtbl->Base.Base.CreateRectangleGeometry((ID2D1Factory *)This, rectangle, rectangleGeometry))

#define ID2D1Factory2_CreateRoundedRectangleGeometry(This, roundedRectangle, roundedRectangleGeometry) \
    ((This)->lpVtbl->Base.Base.CreateRoundedRectangleGeometry((ID2D1Factory *)This, roundedRectangle, roundedRectangleGeometry))

#define ID2D1Factory2_CreateEllipseGeometry(This, ellipse, ellipseGeometry) \
    ((This)->lpVtbl->Base.Base.CreateEllipseGeometry((ID2D1Factory *)This, ellipse, ellipseGeometry))

#define ID2D1Factory2_CreateGeometryGroup(This, fillMode, geometries, geometriesCount, geometryGroup) \
    ((This)->lpVtbl->Base.Base.CreateGeometryGroup((ID2D1Factory *)This, fillMode, geometries, geometriesCount, geometryGroup))

#define ID2D1Factory2_CreateTransformedGeometry(This, sourceGeometry, transform, transformedGeometry) \
    ((This)->lpVtbl->Base.Base.CreateTransformedGeometry((ID2D1Factory *)This, sourceGeometry, transform, transformedGeometry))

#define ID2D1Factory2_CreateWicBitmapRenderTarget(This, target, renderTargetProperties, renderTarget) \
    ((This)->lpVtbl->Base.Base.CreateWicBitmapRenderTarget((ID2D1Factory *)This, target, renderTargetProperties, renderTarget))

#define ID2D1Factory2_CreateHwndRenderTarget(This, renderTargetProperties, hwndRenderTargetProperties, hwndRenderTarget) \
    ((This)->lpVtbl->Base.Base.CreateHwndRenderTarget((ID2D1Factory *)This, renderTargetProperties, hwndRenderTargetProperties, hwndRenderTarget))

#define ID2D1Factory2_CreateDxgiSurfaceRenderTarget(This, dxgiSurface, renderTargetProperties, renderTarget) \
    ((This)->lpVtbl->Base.Base.CreateDxgiSurfaceRenderTarget((ID2D1Factory *)This, dxgiSurface, renderTargetProperties, renderTarget))

#define ID2D1Factory2_CreateDCRenderTarget(This, renderTargetProperties, dcRenderTarget) \
    ((This)->lpVtbl->Base.Base.CreateDCRenderTarget((ID2D1Factory *)This, renderTargetProperties, dcRenderTarget))

#define ID2D1Factory2_CreateStrokeStyle(This, strokeStyleProperties, dashes, dashesCount, strokeStyle) \
    ((This)->lpVtbl->Base.CreateStrokeStyle((ID2D1Factory1 *)This, strokeStyleProperties, dashes, dashesCount, strokeStyle))

#define ID2D1Factory2_CreatePathGeometry(This, pathGeometry) \
    ((This)->lpVtbl->Base.CreatePathGeometry((ID2D1Factory1 *)This, pathGeometry))

#define ID2D1Factory2_CreateDrawingStateBlock(This, drawingStateDescription, textRenderingParams, drawingStateBlock) \
    ((This)->lpVtbl->Base.CreateDrawingStateBlock((ID2D1Factory1 *)This, drawingStateDescription, textRenderingParams, drawingStateBlock))

#define ID2D1Factory2_CreateGdiMetafile(This, metafileStream, metafile) \
    ((This)->lpVtbl->Base.CreateGdiMetafile((ID2D1Factory1 *)This, metafileStream, metafile))

#define ID2D1Factory2_RegisterEffectFromStream(This, classId, propertyXml, bindings, bindingsCount, effectFactory) \
    ((This)->lpVtbl->Base.RegisterEffectFromStream((ID2D1Factory1 *)This, classId, propertyXml, bindings, bindingsCount, effectFactory))

#define ID2D1Factory2_RegisterEffectFromString(This, classId, propertyXml, bindings, bindingsCount, effectFactory) \
    ((This)->lpVtbl->Base.RegisterEffectFromString((ID2D1Factory1 *)This, classId, propertyXml, bindings, bindingsCount, effectFactory))

#define ID2D1Factory2_UnregisterEffect(This, classId) \
    ((This)->lpVtbl->Base.UnregisterEffect((ID2D1Factory1 *)This, classId))

#define ID2D1Factory2_GetRegisteredEffects(This, effects, effectsCount, effectsReturned, effectsRegistered) \
    ((This)->lpVtbl->Base.GetRegisteredEffects((ID2D1Factory1 *)This, effects, effectsCount, effectsReturned, effectsRegistered))

#define ID2D1Factory2_GetEffectProperties(This, effectId, properties) \
    ((This)->lpVtbl->Base.GetEffectProperties((ID2D1Factory1 *)This, effectId, properties))

#define ID2D1Factory2_CreateDevice(This, dxgiDevice, d2dDevice1) \
    ((This)->lpVtbl->CreateDevice(This, dxgiDevice, d2dDevice1))

typedef interface ID2D1CommandSink1 ID2D1CommandSink1;

typedef struct ID2D1CommandSink1Vtbl
{
    
    ID2D1CommandSinkVtbl Base;
    
    
    STDMETHOD(SetPrimitiveBlend1)(
        ID2D1CommandSink1 *This,
        D2D1_PRIMITIVE_BLEND primitiveBlend 
        ) PURE;
} ID2D1CommandSink1Vtbl;

interface ID2D1CommandSink1
{
    CONST struct ID2D1CommandSink1Vtbl *lpVtbl;
};


#define ID2D1CommandSink1_QueryInterface(This, riid, ppv) \
    ((This)->lpVtbl->Base.Base.QueryInterface((IUnknown *)This, riid, ppv))

#define ID2D1CommandSink1_AddRef(This) \
    ((This)->lpVtbl->Base.Base.AddRef((IUnknown *)This))

#define ID2D1CommandSink1_Release(This) \
    ((This)->lpVtbl->Base.Base.Release((IUnknown *)This))

#define ID2D1CommandSink1_BeginDraw(This) \
    ((This)->lpVtbl->Base.BeginDraw((ID2D1CommandSink *)This))

#define ID2D1CommandSink1_EndDraw(This) \
    ((This)->lpVtbl->Base.EndDraw((ID2D1CommandSink *)This))

#define ID2D1CommandSink1_SetAntialiasMode(This, antialiasMode) \
    ((This)->lpVtbl->Base.SetAntialiasMode((ID2D1CommandSink *)This, antialiasMode))

#define ID2D1CommandSink1_SetTags(This, tag1, tag2) \
    ((This)->lpVtbl->Base.SetTags((ID2D1CommandSink *)This, tag1, tag2))

#define ID2D1CommandSink1_SetTextAntialiasMode(This, textAntialiasMode) \
    ((This)->lpVtbl->Base.SetTextAntialiasMode((ID2D1CommandSink *)This, textAntialiasMode))

#define ID2D1CommandSink1_SetTextRenderingParams(This, textRenderingParams) \
    ((This)->lpVtbl->Base.SetTextRenderingParams((ID2D1CommandSink *)This, textRenderingParams))

#define ID2D1CommandSink1_SetTransform(This, transform) \
    ((This)->lpVtbl->Base.SetTransform((ID2D1CommandSink *)This, transform))

#define ID2D1CommandSink1_SetPrimitiveBlend(This, primitiveBlend) \
    ((This)->lpVtbl->Base.SetPrimitiveBlend((ID2D1CommandSink *)This, primitiveBlend))

#define ID2D1CommandSink1_SetUnitMode(This, unitMode) \
    ((This)->lpVtbl->Base.SetUnitMode((ID2D1CommandSink *)This, unitMode))

#define ID2D1CommandSink1_Clear(This, color) \
    ((This)->lpVtbl->Base.Clear((ID2D1CommandSink *)This, color))

#define ID2D1CommandSink1_DrawGlyphRun(This, baselineOrigin, glyphRun, glyphRunDescription, foregroundBrush, measuringMode) \
    ((This)->lpVtbl->Base.DrawGlyphRun((ID2D1CommandSink *)This, baselineOrigin, glyphRun, glyphRunDescription, foregroundBrush, measuringMode))

#define ID2D1CommandSink1_DrawLine(This, point0, point1, brush, strokeWidth, strokeStyle) \
    ((This)->lpVtbl->Base.DrawLine((ID2D1CommandSink *)This, point0, point1, brush, strokeWidth, strokeStyle))

#define ID2D1CommandSink1_DrawGeometry(This, geometry, brush, strokeWidth, strokeStyle) \
    ((This)->lpVtbl->Base.DrawGeometry((ID2D1CommandSink *)This, geometry, brush, strokeWidth, strokeStyle))

#define ID2D1CommandSink1_DrawRectangle(This, rect, brush, strokeWidth, strokeStyle) \
    ((This)->lpVtbl->Base.DrawRectangle((ID2D1CommandSink *)This, rect, brush, strokeWidth, strokeStyle))

#define ID2D1CommandSink1_DrawBitmap(This, bitmap, destinationRectangle, opacity, interpolationMode, sourceRectangle, perspectiveTransform) \
    ((This)->lpVtbl->Base.DrawBitmap((ID2D1CommandSink *)This, bitmap, destinationRectangle, opacity, interpolationMode, sourceRectangle, perspectiveTransform))

#define ID2D1CommandSink1_DrawImage(This, image, targetOffset, imageRectangle, interpolationMode, compositeMode) \
    ((This)->lpVtbl->Base.DrawImage((ID2D1CommandSink *)This, image, targetOffset, imageRectangle, interpolationMode, compositeMode))

#define ID2D1CommandSink1_DrawGdiMetafile(This, gdiMetafile, targetOffset) \
    ((This)->lpVtbl->Base.DrawGdiMetafile((ID2D1CommandSink *)This, gdiMetafile, targetOffset))

#define ID2D1CommandSink1_FillMesh(This, mesh, brush) \
    ((This)->lpVtbl->Base.FillMesh((ID2D1CommandSink *)This, mesh, brush))

#define ID2D1CommandSink1_FillOpacityMask(This, opacityMask, brush, destinationRectangle, sourceRectangle) \
    ((This)->lpVtbl->Base.FillOpacityMask((ID2D1CommandSink *)This, opacityMask, brush, destinationRectangle, sourceRectangle))

#define ID2D1CommandSink1_FillGeometry(This, geometry, brush, opacityBrush) \
    ((This)->lpVtbl->Base.FillGeometry((ID2D1CommandSink *)This, geometry, brush, opacityBrush))

#define ID2D1CommandSink1_FillRectangle(This, rect, brush) \
    ((This)->lpVtbl->Base.FillRectangle((ID2D1CommandSink *)This, rect, brush))

#define ID2D1CommandSink1_PushAxisAlignedClip(This, clipRect, antialiasMode) \
    ((This)->lpVtbl->Base.PushAxisAlignedClip((ID2D1CommandSink *)This, clipRect, antialiasMode))

#define ID2D1CommandSink1_PushLayer(This, layerParameters1, layer) \
    ((This)->lpVtbl->Base.PushLayer((ID2D1CommandSink *)This, layerParameters1, layer))

#define ID2D1CommandSink1_PopAxisAlignedClip(This) \
    ((This)->lpVtbl->Base.PopAxisAlignedClip((ID2D1CommandSink *)This))

#define ID2D1CommandSink1_PopLayer(This) \
    ((This)->lpVtbl->Base.PopLayer((ID2D1CommandSink *)This))

#define ID2D1CommandSink1_SetPrimitiveBlend1(This, primitiveBlend) \
    ((This)->lpVtbl->SetPrimitiveBlend1(This, primitiveBlend))


#endif

           
#ifdef __cplusplus
extern "C"
{
#endif

#if NTDDI_VERSION >= NTDDI_WINBLUE
    FLOAT WINAPI 
    D2D1ComputeMaximumScaleFactor(
        _In_ CONST D2D1_MATRIX_3X2_F *matrix
        ); 
#endif // #if NTDDI_VERSION >= NTDDI_WINBLUE
        
#ifdef __cplusplus
}
#endif
        


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */
#pragma endregion
#include <d2d1_2helper.h>
#endif // #ifndef _D2D1_2_H_
