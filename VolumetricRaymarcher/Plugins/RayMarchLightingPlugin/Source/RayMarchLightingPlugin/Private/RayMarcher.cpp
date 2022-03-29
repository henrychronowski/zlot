// Fill out your copyright notice in the Description page of Project Settings.

#include "RayMarcher.h"
#include "RHICommandList.h"

RayMarcher::RayMarcher()
{
}

RayMarcher::~RayMarcher()
{
}

void RayMarcher::RenderTest(FRHICommandList& RHICmdList, ERHIFeatureLevel::Type FeatureLevel, const FLinearColor& Color)
{
	auto ShaderMap = GetGlobalShaderMap(FeatureLevel);
	TShaderMapRef<FVertexShaderDeclaration> VertexShader(ShaderMap);
	TShaderMapRef<FPixelShaderDeclaration> PixelShader(ShaderMap);

	// Set the graphic pipeline state.
	FGraphicsPipelineStateInitializer GraphicsPSOInit;
	RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);
	GraphicsPSOInit.BlendState = TStaticBlendState<>::GetRHI();
	GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
	GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
	GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = GFilterVertexDeclaration.VertexDeclarationRHI;
	GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
	GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
	GraphicsPSOInit.PrimitiveType = PT_TriangleStrip;
	SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);

	// Setup the pixel shader
	FPixelShaderDeclaration::FParameters PassParameters;
	PassParameters.Color = FVector4(0.0f, 0.0f, 1.0f, 1.0f);
	SetShaderParameters(RHICmdList, PixelShader, PixelShader.GetPixelShader(), PassParameters);

	// Setup the vertices
	FVector4 Vertices[4];
	Vertices[0].Set(-1.0f, 1.0f, 0, 1.0f);
	Vertices[1].Set(1.0f, 1.0f, 0, 1.0f);
	Vertices[2].Set(-1.0f, -1.0f, 0, 1.0f);
	Vertices[3].Set(1.0f, -1.0f, 0, 1.0f);

	// Draw
	RHICmdList.SetStreamSource(0, GSimpleScreenVertexBuffer.VertexBufferRHI, 0);
	RHICmdList.DrawPrimitive(0, 2, 1);

	RHICmdList.EndRenderPass();
}

IMPLEMENT_GLOBAL_SHADER(FVertexShaderDeclaration, "/RayMarchLightingPlugin/Shaders/Private/RayMarchLighting.usf", "MainVS", SF_Vertex)
IMPLEMENT_GLOBAL_SHADER(FPixelShaderDeclaration, "/RayMarchLightingPlugin/Shaders/Private/RayMarchLighting.usf", "MainPS", SF_Pixel)