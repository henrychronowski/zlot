// Fill out your copyright notice in the Description page of Project Settings.

#include "RayMarcher.h"

RayMarcher::RayMarcher()
{
}

RayMarcher::~RayMarcher()
{
}

IMPLEMENT_SHADER_TYPE(, FVertexShaderDeclaration, TEXT("/RayMarchLightingPlugin/RayMarchLighting.usf"), TEXT("MainComputeShader"), SF_Compute);