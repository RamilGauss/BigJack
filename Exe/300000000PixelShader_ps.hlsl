#if 0
	***	hlms_uv_count0	2
	***	hlms_pose	0
	***	hlms_uv_count	1
	***	diffuse_map0_idx	0
	***	hlms_disable_stage	0
	***	texcoord	3
	***	fast_shader_build_hack	1
	***	glsl	635204550
	***	uv_diffuse0	0
	***	out_uv_count	1
	***	hlms_high_quality	0
	***	samplerStateStart	2
	***	alpha_test	0
	***	glsles	1070293233
	***	out_uv0_out_uv	0
	***	hlms_identity_viewproj	1
	***	diffuse_map0	1
	***	out_uv0_texture_matrix	0
	***	hlms_alpha_to_coverage	0
	***	hlms_pose_normals	0
	***	hlms_pose_half	0
	***	hlms_alphablend	1
	***	num_textures	1
	***	hlslvk	1841745752
	***	hlms_shadow_uses_depth_texture	0
	***	hlms_tangent	0
	***	hlms_bones_per_vertex	0
	***	out_uv0_tex_unit	0
	***	alpha_test_shadow_caster_only	0
	***	materials_per_buffer	2
	***	hlms_skeleton	0
	***	out_uv0_source_uv	0
	***	partial_pso_clip_distances	0
	***	syntax	-334286542
	***	hlms_tangent4	0
	***	metal	-1698855755
	***	diffuse_map	1
	***	hlms_render_depth_only	0
	***	full_pso_clip_distances	0
	***	textureMaps0	2
	***	hlms_qtangent	0
	***	out_uv_half_count0	2
	***	diffuse	0
	***	out_uv_half_count	1
	***	diffuse_map0_sampler	0
	***	hlms_normal	0
	***	num_samplers	1
	***	glslvk	-338983575
	***	hlsl	-334286542
	***	hlms_colour	1
	DONE DUMPING PROPERTIES
	***	blend_mode_idx3	@insertpiece( NormalNonPremul)
	***	uv_diffuse_swizzle0	xy
	***	blend_mode_idx11	@insertpiece( NormalNonPremul)
	***	blend_mode_idx2	@insertpiece( NormalNonPremul)
	***	blend_mode_idx14	@insertpiece( NormalNonPremul)
	***	blend_mode_idx5	@insertpiece( NormalNonPremul)
	***	blend_mode_idx8	@insertpiece( NormalNonPremul)
	***	blend_mode_idx10	@insertpiece( NormalNonPremul)
	***	blend_mode_idx9	@insertpiece( NormalNonPremul)
	***	blend_mode_idx15	@insertpiece( NormalNonPremul)
	***	blend_mode_idx6	@insertpiece( NormalNonPremul)
	***	blend_mode_idx7	@insertpiece( NormalNonPremul)
	***	blend_mode_idx1	@insertpiece( NormalNonPremul)
	***	blend_mode_idx0	@insertpiece( NormalNonPremul)
	***	blend_mode_idx12	@insertpiece( NormalNonPremul)
	***	blend_mode_idx4	@insertpiece( NormalNonPremul)
	***	blend_mode_idx13	@insertpiece( NormalNonPremul)
	***	diffuse_map0_tex_swizzle	xxxy
	DONE DUMPING PIECES
#endif

#define ushort uint
#define ushort3 uint3
#define ushort4 uint4
#define ogre_float4x3 float4x3

//Short used for read operations. It's an int in GLSL & HLSL. An ushort in Metal
#define rshort int
#define rshort2 int2
#define rint int
//Short used for write operations. It's an int in GLSL. An ushort in HLSL & Metal
#define wshort2 uint2
#define wshort3 uint3

#define toFloat3x3( x ) ((float3x3)(x))
#define buildFloat3x3( row0, row1, row2 ) transpose( float3x3( row0, row1, row2 ) )

#define min3( a, b, c ) min( a, min( b, c ) )
#define max3( a, b, c ) max( a, max( b, c ) )

#define INLINE
#define NO_INTERPOLATION_PREFIX nointerpolation
#define NO_INTERPOLATION_SUFFIX

#define PARAMS_ARG_DECL
#define PARAMS_ARG

#define floatBitsToUint(x) asuint(x)
#define uintBitsToFloat(x) asfloat(x)
#define floatBitsToInt(x) asint(x)
#define fract frac
#define lessThan( a, b ) (a < b)

#define inVs_vertexId input.vertexId
#define inVs_vertex input.vertex
#define inVs_normal input.normal
#define inVs_tangent input.tangent
#define inVs_binormal input.binormal
#define inVs_blendWeights input.blendWeights
#define inVs_blendIndices input.blendIndices
#define inVs_qtangent input.qtangent
#define inVs_colour input.colour

	#define inVs_drawId input.drawId


#define finalDrawId input.drawId


	#define inVs_uv0 input.uv0

#define outVs_Position outVs.gl_Position
#define outVs_viewportIndex outVs.gl_ViewportIndex
#define outVs_clipDistance0 outVs.gl_ClipDistance0.x

#define gl_SampleMaskIn0 gl_SampleMask
#define interpolateAtSample( interp, subsample ) EvaluateAttributeAtSample( interp, subsample )
#define findLSB firstbitlow
#define findMSB firstbithigh
#define mod( a, b ) (a - b * floor(a / b))

#define outPs_colour0 outPs.colour0
#define OGRE_Sample( tex, sampler, uv ) tex.Sample( sampler, uv )
#define OGRE_SampleLevel( tex, sampler, uv, lod ) tex.SampleLevel( sampler, uv, lod )
#define OGRE_SampleArray2D( tex, sampler, uv, arrayIdx ) tex.Sample( sampler, float3( uv, arrayIdx ) )
#define OGRE_SampleArray2DLevel( tex, sampler, uv, arrayIdx, lod ) tex.SampleLevel( sampler, float3( uv, arrayIdx ), lod )
#define OGRE_SampleArrayCubeLevel( tex, sampler, uv, arrayIdx, lod ) tex.SampleLevel( sampler, float4( uv, arrayIdx ), lod )
#define OGRE_SampleGrad( tex, sampler, uv, ddx, ddy ) tex.SampleGrad( sampler, uv, ddx, ddy )
#define OGRE_SampleArray2DGrad( tex, sampler, uv, arrayIdx, ddx, ddy ) tex.SampleGrad( sampler, float3( uv, arrayIdx ), ddx, ddy )
#define OGRE_ddx( val ) ddx( val )
#define OGRE_ddy( val ) ddy( val )
#define OGRE_Load2D( tex, iuv, lod ) tex.Load( int3( iuv, lod ) )
#define OGRE_LoadArray2D( tex, iuv, arrayIdx, lod ) tex.Load( int4( iuv, arrayIdx, lod ) )
#define OGRE_Load2DMS( tex, iuv, subsample ) tex.Load( iuv, subsample )

#define OGRE_Load3D( tex, iuv, lod ) tex.Load( int4( iuv, lod ) )

#define bufferFetch( buffer, idx ) buffer.Load( idx )
#define bufferFetch1( buffer, idx ) buffer.Load( idx ).x

#define structuredBufferFetch( buffer, idx ) buffer[idx]


	#define ReadOnlyBuffer( slot, varType, varName ) StructuredBuffer<varType> varName : register(t##slot)
	#define readOnlyFetch( bufferVar, idx ) bufferVar[idx]
	#define readOnlyFetch1( bufferVar, idx ) bufferVar[idx].x


#define OGRE_Texture3D_float4 Texture3D

#define OGRE_ArrayTex( declType, varName, arrayCount ) declType varName[arrayCount]

#define OGRE_SAMPLER_ARG_DECL( samplerName ) , SamplerState samplerName
#define OGRE_SAMPLER_ARG( samplerName ) , samplerName

#define CONST_BUFFER( bufferName, bindingPoint ) cbuffer bufferName : register(b##bindingPoint)
#define CONST_BUFFER_STRUCT_BEGIN( structName, bindingPoint ) cbuffer structName : register(b##bindingPoint) { struct _##structName
#define CONST_BUFFER_STRUCT_END( variableName ) variableName; }

#define FLAT_INTERPOLANT( decl, bindingPoint ) nointerpolation decl : TEXCOORD##bindingPoint
#define INTERPOLANT( decl, bindingPoint ) decl : TEXCOORD##bindingPoint

#define OGRE_OUT_REF( declType, variableName ) out declType variableName
#define OGRE_INOUT_REF( declType, variableName ) inout declType variableName

#define OGRE_ARRAY_START( type ) {
#define OGRE_ARRAY_END }


// START UNIFORM DECLARATION

// END UNIFORM DECLARATION

struct PS_INPUT
{
	
	
		
			FLAT_INTERPOLANT( uint drawId, 0 );
		
		
			INTERPOLANT( float4 colour, 1 );
		
		
			INTERPOLANT( float2 uv0, 2 );
	
	

};


	
		
			Texture2D textureMaps0 : register(t2);
		
	



	SamplerState samplerState0 : register(s2);


	struct PS_OUTPUT
	{
		
			
				float4 colour0 : SV_Target0;
			
		

		
	};



	
		#define DiffuseSampler0 samplerState0
		
			#define SampleDiffuse0( tex, sampler, uv ) OGRE_Sample( tex, sampler, uv )
			#define DiffuseTexture0 textureMaps0
		

		
			#define DiffuseUV0 inPs.uv0.xy
		
	

	// START UNIFORM DECLARATION
	
	
		
	struct Material
	{
		float4 alpha_test_threshold;
		float4 diffuse;

		
			uint4 indices0_3;
			uint4 indices4_7;
		

		
	};

	
		CONST_BUFFER( MaterialBuf, 1 )
		{
			Material materialArray[2];
		};
	

		
		//Uniforms that change per Item/Entity
		CONST_BUFFER( InstanceBuffer, 2 )
		{
			//.x =
			//Contains the material's start index.
			//
			//.y =
			//shadowConstantBias. Send the bias directly to avoid an
			//unnecessary indirection during the shadow mapping pass.
			//Must be loaded with uintBitsToFloat
			//
			//.z =
			//Contains 0 or 1 to index into passBuf.viewProj[]. Only used
			//if hlms_identity_viewproj_dynamic is set.
			
				uint4 worldMaterialIdx[2];
			
		};
	
	
	
	// END UNIFORM DECLARATION




PS_OUTPUT main
(
	PS_INPUT inPs
	
)
{
	PS_OUTPUT outPs;
	
	
		
	float4 diffuseCol = float4( 1.0f, 1.0f, 1.0f, 1.0f );

	
		
	
		
			ushort materialId	= worldMaterialIdx[inPs.drawId].x & 0x1FFu;
			#define material materialArray[materialId]
		
	

	

	

	// Decode diffuse indices (for array textures)
	
		ushort diffuseIdx0 = material.indices0_3.x & 0x0000FFFFu;
		
		
		
		
		
		
		
	

	
		// Load base image
		diffuseCol = SampleDiffuse0( DiffuseTexture0, DiffuseSampler0,
									 DiffuseUV0  ).xxxy;
	

	// Load each additional layer and blend it
	

	// Apply material colour
	
		diffuseCol *= inPs.colour;
	

	

	

	
		outPs_colour0 = diffuseCol;
	

	
	
	


	return outPs;

}
