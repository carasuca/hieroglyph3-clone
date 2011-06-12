//--------------------------------------------------------------------------------
// This file is a portion of the Hieroglyph 3 Rendering Engine.  It is distributed
// under the MIT License, available in the root of this distribution and 
// at the following URL:
//
// http://www.opensource.org/licenses/mit-license.php
//
// Copyright (c) 2003-2010 Jason Zink 
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
// ViewSimulation
//
//--------------------------------------------------------------------------------
#ifndef ViewSimulation_h
#define ViewSimulation_h
//--------------------------------------------------------------------------------
#include "IRenderView.h"
#include "UnorderedAccessParameterDX11.h"
#include "ShaderResourceParameterDX11.h"
#include "VectorParameterDX11.h"
//--------------------------------------------------------------------------------
namespace Glyph3
{
	class Entity3D;

	// The basic particle structure that we will be using.

	struct Particle
	{
		Vector3f position;
		Vector3f direction;
		float    time;
	};

	
	class ViewSimulation : public IRenderView
	{
	public:
		ViewSimulation( RendererDX11& Renderer, int SizeX );

		virtual void Update( float fTime );
		virtual void PreDraw( RendererDX11* pRenderer );
		virtual void Draw( PipelineManagerDX11* pPipelineManager, IParameterManager* pParamManager );

		virtual void SetRenderParams( IParameterManager* pParamManager );
		virtual void SetUsageParams( IParameterManager* pParamManager );


		virtual ~ViewSimulation();

		ResourcePtr GetParticleCountConstantBuffer();
		ResourcePtr GetParticleCountIndirectArgsBuffer();

	protected:

		int m_iParticleCount;
		ResourcePtr ParticleStateBuffers[2];
		ResourcePtr ParticleCountCBBuffer; // Constant buffer
		ResourcePtr ParticleCountIABuffer; // Indirect args

		// The render effects that we will use for inserting particles and updating
		// their state in the simulation.

		RenderEffectDX11*	pParticleInsertion;
		RenderEffectDX11*	pParticleUpdate;
		bool bOneTimeInit;

		// The various rendering parameters that will be used by this render view.

		UnorderedAccessParameterDX11* pCurrentSimState;
		UnorderedAccessParameterDX11* pNextSimState;
		ShaderResourceParameterDX11* pSimState;
		VectorParameterDX11* pRandomVector;
	};
};
//--------------------------------------------------------------------------------
#endif // ViewSimulation_h