#if 0
	***	hlms_uv_count0	2
	***	hlms_pose	0
	***	hlms_uv_count	1
	***	diffuse_map0_idx	0
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
	***	syntax	-334286542
	***	hlms_tangent4	0
	***	metal	-1698855755
	***	diffuse_map	1
	***	hlms_render_depth_only	0
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
	***	out_uv0_swizzle	xy
	DONE DUMPING PIECES
#endif

//#include "SyntaxHighlightingMisc.h"


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



	
float4x4 UNPACK_MAT4( StructuredBuffer<float4> matrixBuf, uint pixelIdx )
{
	float4 row1 = matrixBuf[int(pixelIdx << 2u)];
	float4 row2 = matrixBuf[int((pixelIdx << 2u) + 1u)];
	float4 row3 = matrixBuf[int((pixelIdx << 2u) + 2u)];
	float4 row4 = matrixBuf[int((pixelIdx << 2u) + 3u)];

	return transpose( float4x4( row1, row2, row3, row4 ) );
}


	// START UNIFORM DECLARATION
	
	//Uniforms that change per pass
	CONST_BUFFER_STRUCT_BEGIN( PassBuffer, 0 )
	{
		//Vertex shader
		
			float4x4 viewProj[2];
		
		
		
		
		//Pixel Shader
		float4 invWindowSize;
		
	}
	CONST_BUFFER_STRUCT_END( passBuf );

	
	
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

	
		
			// Most common path
			#define masterMatrix worldViewProj
		
	



// START UNIFORM D3D DECLARATION
ReadOnlyBuffer( 0, float4, worldMatBuf );

// END UNIFORM D3D DECLARATION

struct VS_INPUT
{
	float4 vertex : POSITION;
	float4 colour : COLOR0;

	float2 uv0 : TEXCOORD0;
	uint drawId : DRAWID;
	
};

struct PS_INPUT
{

	
		
			FLAT_INTERPOLANT( uint drawId, 0 );
		
		
			INTERPOLANT( float4 colour, 1 );
		
		
			INTERPOLANT( float2 uv0, 2 );
	
	

	float4 gl_Position : SV_Position;

	
	
	
	
};

PS_INPUT main( VS_INPUT input )
{
	PS_INPUT outVs;
	
	
	
		
			float4x4 worldViewProj = UNPACK_MAT4( worldMatBuf, finalDrawId );
		

		
			outVs_Position = mul( inVs_vertex, masterMatrix );
		
	

	
		
			outVs.colour = inVs_colour;
			
		

		

		
			
				outVs.uv0.xy =
						inVs_uv0.xy;
			
		

		
			outVs.drawId = finalDrawId;
		
	

	
	

	

	

	

	return outVs;
}
