// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GlobalShader.h"
#include "ShaderParameterStruct.h"
#include "Runtime/RenderCore/Public/PixelShaderUtils.h"

/**
 * 
 */
//class RAYMARCHLIGHTINGPLUGIN_API RayMarcher
//{
//public:
//	RayMarcher();
//	~RayMarcher();
//
//    void RenderTest(FRHICommandList& RHICmdList, ERHIFeatureLevel::Type FeatureLevel, const FLinearColor& Color);
//};
//
//class FSimpleScreenVertexBuffer : public FVertexBuffer
//{
//public:
//    /** Initialize the RHI for this rendering resource */
//    void InitRHI()
//    {
//        TResourceArray<FFilterVertex, VERTEXBUFFER_ALIGNMENT> Vertices;
//        Vertices.SetNumUninitialized(6);
//
//        Vertices[0].Position = FVector4(-1, 1, 0, 1);
//        Vertices[0].UV = FVector2D(0, 0);
//
//        Vertices[1].Position = FVector4(1, 1, 0, 1);
//        Vertices[1].UV = FVector2D(1, 0);
//
//        Vertices[2].Position = FVector4(-1, -1, 0, 1);
//        Vertices[2].UV = FVector2D(0, 1);
//
//        Vertices[3].Position = FVector4(1, -1, 0, 1);
//        Vertices[3].UV = FVector2D(1, 1);
//
//        // Create vertex buffer. Fill buffer with initial data upon creation
//        FRHIResourceCreateInfo CreateInfo(&Vertices);
//        VertexBufferRHI = RHICreateVertexBuffer(Vertices.GetResourceDataSize(), BUF_Static, CreateInfo);
//    }
//};
//TGlobalResource<FSimpleScreenVertexBuffer> GSimpleScreenVertexBuffer;
//
//
//// This can go on a header or cpp file
//class RAYMARCHLIGHTINGPLUGIN_API FVertexShaderDeclaration : public FGlobalShader
//{
//public:
//    DECLARE_GLOBAL_SHADER(FVertexShaderDeclaration)
//
//    // Setup the shader's permutation domain. If no dimensions, can do FPermutationDomain = FShaderPermutationNone.
//    using FPermutationDomain = FShaderPermutationNone;
//    
//    FVertexShaderDeclaration() { }
//
//    // Constructor using an initializer object. We can bind parameters here so that our C++ code
//    // can interface with USF, enabling us to set shader parameters from code.
//    FVertexShaderDeclaration(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
//        : FGlobalShader(Initializer)
//    {
//    }
//
//    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
//    {
//        return true;
//    }
//};
//
//class RAYMARCHLIGHTINGPLUGIN_API FPixelShaderDeclaration : public FGlobalShader
//{
//public:
//    DECLARE_GLOBAL_SHADER(FPixelShaderDeclaration);
//    SHADER_USE_PARAMETER_STRUCT(FPixelShaderDeclaration, FGlobalShader)
//        BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
//        SHADER_PARAMETER(FVector4, Color)
//    END_SHADER_PARAMETER_STRUCT()
//
//
//    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
//    {
//        return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
//    }
//};




