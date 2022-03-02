#ifndef RAYMARCHER_H
#define RAYMARCHER_H

#include "GlobalShader.h"

class FRayMarcherVS : public FGlobalShader
{
	DECLARE_EXPORTED_SHADER_TYPE(FRayMarcherVS, Global, VOLUMETRICRAYMARCHER_API);

	FRayMarcherVS() { }

	FRayMarcherVS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		:FGlobalShader(Initializer)
	{

	}

	static bool ShouldCache(EShaderPlatform Platform)
	{
		return true;
	}
};

class FRayMarcherPS : public FGlobalShader
{
	DECLARE_EXPORTED_SHADER_TYPE(FRayMarcherPS, Global, VOLUMETRICRAYMARCHER_API);

	FShaderParameter ColorParam;

	FRayMarcherPS() { }

	FRayMarcherPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FGlobalShader(Initializer)
	{
		ColorParam.Bind(Initializer.ParameterMap, TEXT("Color"), SPF_Mandatory);
	}

	static void ModifyCompilationEnvironment(EShaderPlatform Platform, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Platform, OutEnvironment);

		// Add defines for shader code
		//OutEnvironment.SetDefine(TEXT("DEFINE"), 1);
	}

	static bool ShouldCache(EShaderPlatform Platform)
	{
		return true;
	}

	virtual bool Serialize(FArchive& Ar) override
	{
		bool bShaderHasOutdatedParameters = FGlobalShader::Serialize(Ar);
		Ar << ColorParam;
		return bShaderHasOutdatedParameters;
	}

	// Example how to set ColorParam parameter
	void SetColor(FRHICommandList& RHICmdList, const FLinearColor& Color)
	{
		SetShaderValue(RHICmdList, GetPixelShader(), ColorParam);
	}
};

void RenderMyTest(FRHICommandList& RHICmdList, ERHIFeatureLevel::Type FeatureLevel, const FLinearColor& Color)
{
	// Get the collection of Global Shaders
	auto ShaderMap = GetGlobalShaderMap(FeatureLevel);

	// Get the actual shader instances off the ShaderMap
	TShaderMapRef MyVS(ShaderMap);
	TShaderMapRef MyPS(ShaderMap);

	// Declare a bound shader state using those shaders and apply it to the command list
	static FGlobalBoundShaderState MyTestBoundShaderState;
	SetGlobalBoundShaderState(RHICmdList, FeatureLevel, MyTestBoundShaderState, GetVertexDeclarationFVector4(), *MyVS, *MyPS);

	// Call our function to set up parameters
	MyPS->SetColor(RHICmdList, Color);

	// Setup the GPU in prep for drawing a solid quad
	RHICmdList.SetRasterizerState(TStaticRasterizerState::GetRHI());
	RHICmdList.SetBlendState(TStaticBlendState<>::GetRHI());
	RHICmdList.SetDepthStencilState(TStaticDepthStencilState::GetRHI(), 0);

	// Setup the vertices
	FVector4 Vertices[4];
	Vertices[0].Set(-1.0f, 1.0f, 0, 1.0f);
	Vertices[1].Set(1.0f, 1.0f, 0, 1.0f);
	Vertices[2].Set(-1.0f, -1.0f, 0, 1.0f);
	Vertices[3].Set(1.0f, -1.0f, 0, 1.0f);

	// Draw the quad
	DrawPrimitiveUP(RHICmdList, PT_TriangleStrip, 2, Vertices, sizeof(Vertices[0]));
}

static TAutoConsoleVariable CVarMyTest(
	TEXT("r.MyTest"),
	0,
	TEXT("Test My Global Shader, set it to 0 to disable, or to 1, 2 or 3 for fun!"),
	ECVF_RenderThreadSafe
);


#endif // RAYMARCHER_H
