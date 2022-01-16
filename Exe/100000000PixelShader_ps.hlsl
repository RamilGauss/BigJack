#if 0
	***	hlms_pose	0
	***	first_valid_detail_map_nm	0
	***	hlms_dual_paraboloid_mapping	0
	***	envprobe_map_sampler	1
	***	hlms_lights_spotparams	0
	***	envMapRegSampler	1
	***	emissive_map_sampler	1
	***	set0_texture_slot_end	1
	***	hlms_disable_stage	0
	***	NumPoseWeightVectors	0
	***	hlms_lights_area_approx	0
	***	specular_map_sampler	1
	***	texcoord	0
	***	fast_shader_build_hack	1
	***	glsl	635204550
	***	hlms_high_quality	0
	***	NumPoseWeightVectorsB	0
	***	hlms_num_shadow_map_lights	0
	***	hlms_lights_directional	0
	***	hlms_shadowcaster	1
	***	samplerStateStart	1
	***	alpha_test	0
	***	roughness_map_sampler	1
	***	glsles	1070293233
	***	hw_gamma_write	1
	***	detail_map_nm2_sampler	1
	***	hlms_shadowcaster_directional	1
	***	NumPoseWeightVectorsC	0
	***	hlms_pssm_splits	0
	***	hlms_pose_normals	0
	***	hlms_pose_half	0
	***	hlms_lights_spot	0
	***	detail_map1_sampler	1
	***	detail_map_nm3_sampler	1
	***	hlms_alphablend	0
	***	hlms_num_shadow_map_textures	0
	***	MoreThanOnePose	-1
	***	hlslvk	1841745752
	***	hlms_shadow_uses_depth_texture	1
	***	detail_map3_sampler	1
	***	NumPoseWeightVectorsA	0
	***	materials_per_buffer	2
	***	hw_gamma_read	1
	***	hlms_skeleton	0
	***	hlms_pssm_splits_minus_one	-1
	***	forward3d	0
	***	partial_pso_clip_distances	0
	***	syntax	-334286542
	***	NeedsMoreThan1BonePerVertex	-1
	***	hlms_lights_point	0
	***	diffuse_map_sampler	1
	***	metal	-1698855755
	***	detail_map_nm1_sampler	1
	***	s_lights_directional_non_caster	0
	***	uv_diffuse	0
	***	detail_weight_map_sampler	1
	***	hlms_lights_attenuation	0
	***	detail_map_nm0_sampler	1
	***	hlms_render_depth_only	1
	***	normal_map_tex_sampler	1
	***	MoreThanOnePoseWeightVector	-1
	***	detail_map2_sampler	1
	***	full_pso_clip_distances	0
	***	detail_map0_sampler	1
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


	#define UV_DIFFUSE(x) (x)
	#define UV_NORMAL(x) (x)
	#define UV_SPECULAR(x) (x)
	#define UV_ROUGHNESS(x) (x)
	#define UV_DETAIL_WEIGHT(x) (x)
	#define UV_DETAIL0(x) (x)
	#define UV_DETAIL1(x) (x)
	#define UV_DETAIL2(x) (x)
	#define UV_DETAIL3(x) (x)
	#define UV_DETAIL_NM0(x) (x)
	#define UV_DETAIL_NM1(x) (x)
	#define UV_DETAIL_NM2(x) (x)
	#define UV_DETAIL_NM3(x) (x)
	#define UV_EMISSIVE(x) (x)
	





	// START UNIFORM DECLARATION
	
	
	// END UNIFORM DECLARATION

	
		#define float_fresnel float
		#define make_float_fresnel( x ) x
	

	
	
		#define OGRE_DEPTH_CMP_GE( a, b ) (a) <= (b)
		#define OGRE_DEPTH_DEFAULT_CLEAR 0.0
	


	
		#define PASSBUF_ARG_DECL
		#define PASSBUF_ARG
	

	

	struct PixelData
	{
		
			float4 diffuse; //We only use the .w component, Alpha
		
	};

	#define SampleDetailWeightMap( tex, sampler, uv, arrayIdx ) OGRE_SampleArray2D( tex, sampler, uv, arrayIdx )
	
	
	
	
	
	

	

	

	

	

	
	
	
	
	





struct PS_INPUT
{

	
		
	

	
		
		
		
	
	

};

///!hlms_shadowcaster


	

	
		#define outDepth outPs.colour0
	








	struct PS_OUTPUT
	{
		
			
				
				
					float colour0 : SV_Depth;
				
			
		

		
	};


void main( PS_INPUT inPs )
{


	
	
	
	
	
	


	


}

