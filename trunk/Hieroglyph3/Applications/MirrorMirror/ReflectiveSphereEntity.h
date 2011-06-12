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
// ReflectiveSphereEntity
//
//--------------------------------------------------------------------------------
#ifndef ReflectiveSphereEntity_h
#define ReflectiveSphereEntity_h
//--------------------------------------------------------------------------------
#include "Entity3D.h"
#include "ViewParaboloidEnvMap.h"
//--------------------------------------------------------------------------------
namespace Glyph3
{
	class ReflectiveSphereEntity : public Entity3D
	{
	public:
		ReflectiveSphereEntity( );
		virtual ~ReflectiveSphereEntity( );

		virtual void PreRender( RendererDX11* pRenderer, VIEWTYPE view );
		virtual void Render( PipelineManagerDX11* pPipelineManager, IParameterManager* pParamManager, VIEWTYPE view );


	public:
		ResourcePtr ArgsBuffer;
		ViewParaboloidEnvMap* m_pParaboloidView;

		ResourcePtr ParticleTexture;
		int			ParaboloidSampler;
	};
};
//--------------------------------------------------------------------------------
#endif // ReflectiveSphereEntity_h