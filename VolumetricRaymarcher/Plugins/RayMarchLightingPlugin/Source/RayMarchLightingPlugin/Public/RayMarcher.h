// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GlobalShader.h"

/**
 * 
 */
class RAYMARCHLIGHTINGPLUGIN_API RayMarcher
{
public:
	RayMarcher();
	~RayMarcher();
};


// This can go on a header or cpp file
class FVertexShaderDeclaration : public FGlobalShader
{
    DECLARE_SHADER_TYPE(FVertexShaderDeclaration, Global);

    FVertexShaderDeclaration() { }
    FVertexShaderDeclaration(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
        : FGlobalShader(Initializer)
    {
    }

    static bool ShouldCache(EShaderPlatform Platform)
    {
        return true;
    }
};

//class FMyTestPS : public FGlobalShader
//{
//    DECLARE_EXPORTED_SHADER_TYPE(FMyTestPS, Global, /*MYMODULE_API*/);
//
//    FShaderParameter MyColorParameter;
//
//    FMyTestPS() { }
//    FMyTestPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
//        : FGlobalShader(Initializer)
//    {
//        MyColorParameter.Bind(Initializer.ParameterMap, TEXT("MyColor"), SPF_Mandatory);
//    }
//
//    static void ModifyCompilationEnvironment(EShaderPlatform Platform, FShaderCompilerEnvironment& OutEnvironment)
//    {
//        FGlobalShader::ModifyCompilationEnvironment(Platform, OutEnvironment);
//        // Add your own defines for the shader code
//        OutEnvironment.SetDefine(TEXT("MY_DEFINE"), 1);
//    }
//
//    static bool ShouldCache(EShaderPlatform Platform)
//    {
//        // Could skip compiling for Platform == SP_METAL for example
//        return true;
//    }
//
//    // FShader interface.
//    virtual bool Serialize(FArchive& Ar) override
//    {
//        bool bShaderHasOutdatedParameters = FGlobalShader::Serialize(Ar);
//        Ar << MyColorParameter;
//        return bShaderHasOutdatedParameters;
//    }
//
//    void SetColor(FRHICommandList& RHICmdList, const FLinearColor& Color)
//    {
//        SetShaderValue(RHICmdList, GetPixelShader(), MyColorParameter, Color);
//    }
//};