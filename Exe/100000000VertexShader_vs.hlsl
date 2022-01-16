#if 0
	***	hlms_pose	0
	***	first_valid_detail_map_nm	0
	***	hlms_dual_paraboloid_mapping	0
	***	hlms_lights_spotparams	0
	***	set0_texture_slot_end	1
	***	hlms_lights_area_approx	0
	***	fast_shader_build_hack	1
	***	glsl	635204550
	***	hlms_high_quality	0
	***	hlms_num_shadow_map_lights	0
	***	hlms_lights_directional	0
	***	hlms_shadowcaster	1
	***	samplerStateStart	1
	***	alpha_test	0
	***	glsles	1070293233
	***	hw_gamma_write	1
	***	hlms_shadowcaster_directional	1
	***	hlms_pssm_splits	0
	***	hlms_pose_normals	0
	***	hlms_pose_half	0
	***	hlms_lights_spot	0
	***	hlms_alphablend	0
	***	hlms_num_shadow_map_textures	0
	***	hlslvk	1841745752
	***	hlms_shadow_uses_depth_texture	1
	***	materials_per_buffer	2
	***	hw_gamma_read	1
	***	hlms_skeleton	0
	***	forward3d	0
	***	syntax	-334286542
	***	hlms_lights_point	0
	***	metal	-1698855755
	***	s_lights_directional_non_caster	0
	***	uv_diffuse	0
	***	hlms_lights_attenuation	0
	***	hlms_render_depth_only	1
	***	set1_texture_slot_end	1
	***	use_planar_reflections	0
	***	glslvk	-338983575
	***	hlsl	-334286542
	DONE DUMPING PROPERTIES
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



	
		#define worldViewMat worldView
	

	
float4x4 UNPACK_MAT4( StructuredBuffer<float4> matrixBuf, uint pixelIdx )
{
	float4 row1 = matrixBuf[int(pixelIdx << 2u)];
	float4 row2 = matrixBuf[int((pixelIdx << 2u) + 1u)];
	float4 row3 = matrixBuf[int((pixelIdx << 2u) + 2u)];
	float4 row4 = matrixBuf[int((pixelIdx << 2u) + 3u)];

	return transpose( float4x4( row1, row2, row3, row4 ) );
}

	
float4x3 UNPACK_MAT4x3( StructuredBuffer<float4> matrixBuf, uint pixelIdx )
{
	float4 row1 = matrixBuf[int(pixelIdx << 2u)];
	float4 row2 = matrixBuf[int((pixelIdx << 2u) + 1u)];
	float4 row3 = matrixBuf[int((pixelIdx << 2u) + 2u)];

	return transpose( float3x4( row1, row2, row3 ) );
}


	// START UNIFORM DECLARATION
	
struct ShadowReceiverData
{
	float4x4 texViewProj;

	float2 shadowDepthRange;
	float normalOffsetBias;
	float padding;
	float4 invShadowMapSize;
};

struct Light
{
	
		float3 position;
		uint lightMask;
	
	float4 diffuse;		//.w contains numNonCasterDirectionalLights
	float3 specular;


#define lightTexProfileIdx spotDirection.w
};

#define numNonCasterDirectionalLights lights[0].diffuse.w

#define areaLightDiffuseMipmapStart areaApproxLights[0].diffuse.w
#define areaLightNumMipmapsSpecFactor areaApproxLights[0].specular.w

#define numAreaApproxLights areaApproxLights[0].doubleSided.y
#define numAreaApproxLightsWithMask areaApproxLights[0].doubleSided.z

#define numAreaLtcLights areaLtcLights[0].points[0].w
#define numAreaLtcLights areaLtcLights[0].points[0].w

struct AreaLight
{
	
		float3 position;
		uint lightMask;
	
	float4 diffuse;		//[0].w contains diffuse mipmap start
	float4 specular;	//[0].w contains mipmap scale
	float4 attenuation;	//.w contains texture array idx
	//Custom 2D Shape:
	//  direction.xyz direction
	//  direction.w invHalfRectSize.x
	//  tangent.xyz tangent
	//  tangent.w invHalfRectSize.y
	float4 direction;
	float4 tangent;
	float4 doubleSided;	//.y contains numAreaApproxLights
						//.z contains numAreaApproxLightsWithMask
	
};

struct AreaLtcLight
{
	
		float3 position;
		uint lightMask;
	
	float4 diffuse;			//.w contains attenuation range
	float4 specular;		//.w contains doubleSided
	float4 points[4];		//.w contains numAreaLtcLights
							//points[1].w, points[2].w, points[3].w contain obbFadeFactorLtc.xyz
	
};





//Uniforms that change per pass
CONST_BUFFER_STRUCT_BEGIN( PassBuffer, 0 )
{
	//Vertex shader (common to both receiver and casters)

	float4x4 viewProj;







	//Vertex shader
	
	float2 depthRange;




	



	
	

	

#define pccVctMinDistance		pccVctMinDistance_invPccVctInvDistance_rightEyePixelStartX_envMapNumMipmaps.x
#define invPccVctInvDistance	pccVctMinDistance_invPccVctInvDistance_rightEyePixelStartX_envMapNumMipmaps.y
#define rightEyePixelStartX		pccVctMinDistance_invPccVctInvDistance_rightEyePixelStartX_envMapNumMipmaps.z
#define envMapNumMipmaps		pccVctMinDistance_invPccVctInvDistance_rightEyePixelStartX_envMapNumMipmaps.w

#define aspectRatio			aspectRatio_planarReflNumMips_unused2.x
#define planarReflNumMips	aspectRatio_planarReflNumMips_unused2.y
}
CONST_BUFFER_STRUCT_END( passBuf );



#define light0Buf		passBuf
#define light1Buf		passBuf
#define light2Buf		passBuf

// use_light_buffers


	
		//Uniforms that change per Item/Entity
		CONST_BUFFER( InstanceBuffer, 2 )
		{
			//.x =
			//The lower 9 bits contain the material's start index.
			//The higher 23 bits contain the world matrix start index.
			//
			//.y =
			//shadowConstantBias. Send the bias directly to avoid an
			//unnecessary indirection during the shadow mapping pass.
			//Must be loaded with uintBitsToFloat
			//
			//.z =
			//lightMask. Ogre must have been compiled with OGRE_NO_FINE_LIGHT_MASK_GRANULARITY
			
				uint4 worldMaterialIdx[2];
			
		};
	
	
	// END UNIFORM DECLARATION

	

    



struct VS_INPUT
{
	float4 vertex : POSITION;










	uint drawId : DRAWID;
	
};

struct PS_INPUT
{
	
	
		
	

	
		
		
		
	
	

	float4 gl_Position: SV_Position;

	

	
	
	
	
};

// START UNIFORM D3D DECLARATION
ReadOnlyBuffer( 0, float4, worldMatBuf );

// END UNIFORM D3D DECLARATION

PS_INPUT main( VS_INPUT input )
{
	PS_INPUT outVs;

	
	
	// Define inputPos using inVs_vertex.
	
		#define inputPos inVs_vertex
	

	// Define inputNormal and inputTangent using inVs_normal, inVs_tangent, inVs_qtangent
	
		
			#define inputNormal inVs_normal
		
		
			#define inputTangent inVs_tangent
		
	

	
		ogre_float4x3 worldMat = UNPACK_MAT4x3( worldMatBuf, inVs_drawId );
		

		float4 worldPos = float4( mul(inVs_vertex, worldMat).xyz, 1.0f );
		
	

	

	

	
	
	
	//Lighting is in view space
	
	
	
	
        
			
				outVs_Position = mul( worldPos, passBuf.viewProj );
			
		
	


	
	
		
			
				float shadowConstantBias = -uintBitsToFloat( worldMaterialIdx[inVs_drawId].y ) * passBuf.depthRange.y;
			
		

		

		

		
			//We can't make the depth buffer linear without Z out in the fragment shader;
			//however we can use a cheap approximation ("pseudo linear depth")
			//see http://www.yosoygames.com.ar/wp/2014/01/linear-depth-buffer-my-ass/
			
				outVs_Position.z = outVs_Position.z + shadowConstantBias;
			
		

		
	

	/// hlms_uv_count will be 0 on shadow caster passes w/out alpha test
	


	


	

	

	

	

	return outVs;
}
