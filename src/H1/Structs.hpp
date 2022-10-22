#pragma once
#include <d3d11.h>

#define assert_sizeof(__ASSET__, __SIZE__) static_assert(sizeof(__ASSET__) == __SIZE__)
#define assert_offsetof(__ASSET__, __VARIABLE__, __OFFSET__) static_assert(offsetof(__ASSET__, __VARIABLE__) == __OFFSET__)

#pragma pack(push, 8)

namespace ZoneTool
{
	namespace H1
	{
		typedef float vec_t;
		typedef vec_t vec2_t[2];
		typedef vec_t vec3_t[3];
		typedef vec_t vec4_t[4];

		template <std::size_t N>
		struct VecInternal
		{
			float data[N];
		};

		struct dummy
		{
		};

		enum scr_string_t : std::int32_t
		{
		};

		enum XAssetType
		{
			ASSET_TYPE_PHYSPRESET,
			ASSET_TYPE_PHYSCOLLMAP,
			ASSET_TYPE_PHYSWATERPRESET,
			ASSET_TYPE_PHYSWORLDMAP,
			ASSET_TYPE_PHYSCONSTRAINT,
			ASSET_TYPE_XANIM,
			ASSET_TYPE_XMODEL_SURFS,
			ASSET_TYPE_XMODEL,
			ASSET_TYPE_MATERIAL,
			ASSET_TYPE_COMPUTESHADER,
			ASSET_TYPE_VERTEXSHADER,
			ASSET_TYPE_HULLSHADER,
			ASSET_TYPE_DOMAINSHADER,
			ASSET_TYPE_PIXELSHADER,
			ASSET_TYPE_VERTEXDECL,
			ASSET_TYPE_TECHNIQUE_SET,
			ASSET_TYPE_IMAGE,
			ASSET_TYPE_SOUND,
			ASSET_TYPE_SOUNDSUBMIX,
			ASSET_TYPE_SOUND_CURVE,
			ASSET_TYPE_LPF_CURVE,
			ASSET_TYPE_REVERB_CURVE,
			ASSET_TYPE_SOUND_CONTEXT,
			ASSET_TYPE_LOADED_SOUND,
			ASSET_TYPE_COL_MAP_SP,
			ASSET_TYPE_COM_MAP,
			ASSET_TYPE_GLASS_MAP,
			ASSET_TYPE_AIPATHS,
			ASSET_TYPE_VEHICLE_TRACK,
			ASSET_TYPE_MAP_ENTS,
			ASSET_TYPE_FX_MAP,
			ASSET_TYPE_GFX_MAP,
			ASSET_TYPE_LIGHT_DEF,
			ASSET_TYPE_UI_MAP,
			ASSET_TYPE_MENUFILE,
			ASSET_TYPE_MENU,
			ASSET_TYPE_ANIMCLASS,
			ASSET_TYPE_LOCALIZE_ENTRY,
			ASSET_TYPE_ATTACHMENT,
			ASSET_TYPE_WEAPON,
			ASSET_TYPE_SNDDRIVERGLOBALS,
			ASSET_TYPE_FX,
			ASSET_TYPE_IMPACT_FX,
			ASSET_TYPE_SURFACE_FX,
			ASSET_TYPE_AITYPE,
			ASSET_TYPE_MPTYPE,
			ASSET_TYPE_CHARACTER,
			ASSET_TYPE_XMODELALIAS,
			ASSET_TYPE_RAWFILE,
			ASSET_TYPE_SCRIPTFILE,
			ASSET_TYPE_STRINGTABLE,
			ASSET_TYPE_LEADERBOARDDEF,
			ASSET_TYPE_VIRTUAL_LEADERBOARD,
			ASSET_TYPE_STRUCTUREDDATADEF,
			ASSET_TYPE_DDL,
			ASSET_TYPE_PROTO,
			ASSET_TYPE_TRACER,
			ASSET_TYPE_VEHICLE,
			ASSET_TYPE_ADDON_MAP_ENTS,
			ASSET_TYPE_NET_CONST_STRINGS,
			ASSET_TYPE_REVERB_PRESET,
			ASSET_TYPE_LUA_FILE,
			ASSET_TYPE_SCRIPTABLE,
			ASSET_TYPE_EQUIPMENT_SND_TABLE,
			ASSET_TYPE_VECTORFIELD,
			ASSET_TYPE_DOPPLER_PRESET,
			ASSET_TYPE_PARTICLE_SIM_ANIMATION,
			ASSET_TYPE_LASER,
			ASSET_TYPE_SKELETONSCRIPT,
			ASSET_TYPE_CLUT,
			ASSET_TYPE_TTF,
			ASSET_TYPE_COUNT
		};

		struct FxEffectDef;

		struct Bounds
		{
			vec3_t midPoint;
			vec3_t halfSize;
		};

		struct PhysPreset
		{
			const char* __ptr64 name;
			char __pad0[32];
			const char* __ptr64 sndAliasPrefix;
			char __pad1[48];
		}; static_assert(sizeof(PhysPreset) == 0x60);

		struct dmMeshNode_array_t
		{
			char __pad0[16];
		};

		struct dmMeshTriangle
		{
			char __pad0[32];
		};

		struct dmMeshData
		{
			dmMeshNode_array_t* __ptr64 meshNodes;
			vec4_t* __ptr64 vec4_array0;
			dmMeshTriangle* __ptr64 meshTriangles;
			char __pad0[36];
			unsigned int count0;
			unsigned int count1;
			unsigned int count2;
			char __pad1[8];
		}; static_assert(sizeof(dmMeshData) == 0x50);

		struct dmSubEdge
		{
			int value;
		};

		struct dmPolytopeData
		{
			vec4_t* __ptr64 vec4_array0;
			vec4_t* __ptr64 vec4_array1;
			unsigned short* __ptr64 uint16_array0;
			unsigned short* __ptr64 uint16_array1;
			dmSubEdge* __ptr64 edges;
			unsigned char* __ptr64 uint8_array0;
			char __pad0[12];
			unsigned int count0;
			unsigned int count1;
			unsigned int count2;
			char __pad1[40];
		}; static_assert(sizeof(dmPolytopeData) == 0x70);

		struct PhysGeomInfo
		{
			dmPolytopeData* __ptr64 data;
		};

		struct PhysMass
		{
			float centerOfMass[3];
			float momentsOfInertia[3];
			float productsOfInertia[3];
		};

		struct PhysCollmap
		{
			const char* __ptr64 name;
			unsigned int count;
			PhysGeomInfo* __ptr64 geoms;
			PhysMass mass;
			Bounds bounds;
		}; static_assert(sizeof(PhysCollmap) == 0x58);

		struct PhysWaterPreset
		{
			const char* __ptr64 name;
			char __pad0[64];
			FxEffectDef* __ptr64 fx0;
			FxEffectDef* __ptr64 fx1;
			FxEffectDef* __ptr64 fx2;
			FxEffectDef* __ptr64 fx3;
			FxEffectDef* __ptr64 fx4;
			FxEffectDef* __ptr64 fx5;
			FxEffectDef* __ptr64 fx6;
		}; static_assert(sizeof(PhysWaterPreset) == 0x80);

		struct PhysWaterVolumeDef
		{
			PhysWaterPreset* __ptr64 physWaterPreset;
			char __pad0[12];
			scr_string_t string;
			char __pad1[8];
		}; static_assert(sizeof(PhysWaterVolumeDef) == 0x20);
		static_assert(offsetof(PhysWaterVolumeDef, string) == 20);

		struct PhysBrushModel
		{
			union
			{
				std::uint64_t id;
				char __pad0[8];
			};
		};

		struct PhysWorld
		{
			const char* __ptr64 name;
			PhysBrushModel* __ptr64 models;
			dmPolytopeData* __ptr64 polytopeDatas;
			dmMeshData* __ptr64 meshDatas;
			PhysWaterVolumeDef* __ptr64 waterVolumes;
			unsigned int modelsCount;
			unsigned int polytopeDatasCount;
			unsigned int meshDatasCount;
			unsigned int waterVolumesCount;
		}; static_assert(sizeof(PhysWorld) == 0x38);

		struct PhysConstraint
		{
			const char* __ptr64 name;
			char __pad0[32];
		}; static_assert(sizeof(PhysConstraint) == 0x28);

		struct Packed128
		{
			std::uint64_t p0;
			std::uint64_t p1;
		};

		struct GfxDrawSurfFields
		{
			unsigned __int64 objectId : 16;
			unsigned __int64 reflectionProbeIndex : 8;
			unsigned __int64 hasGfxEntIndex : 1;
			unsigned __int64 customIndex : 5;
			unsigned __int64 materialSortedIndex : 13;
			unsigned __int64 tessellation : 3;
			unsigned __int64 prepass : 2;
			unsigned __int64 useHeroLighting : 1;
			unsigned __int64 sceneLightEnvIndex : 16;
			unsigned __int64 viewModelRender : 1;
			unsigned __int64 surfType : 4;
			unsigned __int64 primarySortKey : 6;
			unsigned __int64 unused : 30;
		};

		union GfxDrawSurf
		{
			GfxDrawSurfFields fields;
			Packed128 packed;
		};

		struct GfxComputeShaderLoadDef
		{
			unsigned char* __ptr64 program;
			unsigned int programSize;
			char __pad[4];
		};

		struct ComputeShaderProgram
		{
			ID3D11ComputeShader* __ptr64 cs;
			GfxComputeShaderLoadDef loadDef;
		};

		struct ComputeShader
		{
			const char* __ptr64 name;
			ComputeShaderProgram prog;
		}; static_assert(sizeof(ComputeShader) == 0x20);

		struct GfxVertexShaderLoadDef
		{
			unsigned char* __ptr64 program;
			unsigned int programSize;
			unsigned int microCodeCrc;
		};

		struct MaterialVertexShaderProgram
		{
			ID3D11VertexShader* __ptr64 vs;
			GfxVertexShaderLoadDef loadDef;
		};

		struct MaterialVertexShader
		{
			const char* __ptr64 name;
			MaterialVertexShaderProgram prog;
		}; static_assert(sizeof(MaterialVertexShader) == 0x20);

		struct GfxPixelShaderLoadDef
		{
			unsigned char* __ptr64 program;
			unsigned int programSize;
			unsigned int microCodeCrc;
		};

		struct MaterialPixelShaderProgram
		{
			ID3D11PixelShader* __ptr64 ps;
			GfxPixelShaderLoadDef loadDef;
		};

		struct MaterialPixelShader
		{
			const char* __ptr64 name;
			MaterialPixelShaderProgram prog;
		}; static_assert(sizeof(MaterialPixelShader) == 0x20);

		struct GfxHullShaderLoadDef
		{
			unsigned char* __ptr64 program;
			unsigned int programSize;
			char __pad[4];
		};

		struct MaterialHullShaderProgram
		{
			ID3D11HullShader* __ptr64 hs;
			GfxHullShaderLoadDef loadDef;
		};

		struct MaterialHullShader
		{
			const char* __ptr64 name;
			MaterialHullShaderProgram prog;
		}; static_assert(sizeof(MaterialHullShader) == 0x20);

		struct GfxDomainShaderLoadDef
		{
			unsigned char* __ptr64 program;
			unsigned int programSize;
			char __pad[4];
		};

		struct MaterialDomainShaderProgram
		{
			ID3D11DomainShader* __ptr64 ds;
			GfxDomainShaderLoadDef loadDef;
		};

		struct MaterialDomainShader
		{
			const char* __ptr64 name;
			MaterialDomainShaderProgram prog;
		}; static_assert(sizeof(MaterialDomainShader) == 0x20);

		struct MaterialArgumentCodeConst
		{
			unsigned short index;
			unsigned char firstRow;
			unsigned char rowCount;
		};

		union MaterialArgumentDef
		{
			const float* __ptr64 literalConst;
			MaterialArgumentCodeConst codeConst;
			unsigned int codeSampler;
			unsigned int nameHash;
		};

		struct MaterialShaderArgument
		{
			unsigned char type;
			unsigned char shader;
			unsigned short dest;
			MaterialArgumentDef u;
		}; static_assert(sizeof(MaterialShaderArgument) == 0x10);

		struct MaterialStreamRouting
		{
			unsigned char source;
			unsigned char dest;
			unsigned char mask;
		};

		struct MaterialVertexStreamRouting
		{
			MaterialStreamRouting data[32];
			ID3D11InputLayout* __ptr64 decl[250];
		};

		struct MaterialVertexDeclaration
		{
			const char* __ptr64 name;
			unsigned char streamCount;
			bool hasOptionalSource;
			MaterialVertexStreamRouting routing;
		}; static_assert(sizeof(MaterialVertexDeclaration) == 0x840);

		struct MaterialPass
		{
			MaterialVertexShader* __ptr64 vertexShader;
			MaterialVertexDeclaration* __ptr64 vertexDecl;
			MaterialHullShader* __ptr64 hullShader;
			MaterialDomainShader* __ptr64 domainShader;
			MaterialPixelShader* __ptr64 pixelShader;
			unsigned char pixelOutputMask;
			unsigned char perPrimArgCount;
			unsigned char perObjArgCount;
			unsigned char stableArgCount;
			unsigned short perPrimArgSize;
			unsigned short perObjArgSize;
			unsigned short stableArgSize;
			unsigned short zone;
			unsigned char perPrimConstantBuffer;
			unsigned char perObjConstantBuffer;
			unsigned char stableConstantBuffer;
			unsigned int customBufferFlags;
			unsigned char customSamplerFlags;
			unsigned char precompiledIndex;
			unsigned char stageConfig;
			MaterialShaderArgument* __ptr64 args;
		};

		struct MaterialTechniqueHeader
		{
			const char* __ptr64 name;
			unsigned short flags;
			unsigned short passCount;
		};

		struct MaterialTechnique
		{
			//const char* __ptr64 name;
			//unsigned short flags;
			//unsigned short passCount;
			MaterialTechniqueHeader hdr;
			MaterialPass passArray[1];
		};

		struct MaterialTechniqueSet
		{
			const char* __ptr64 name;
			unsigned short flags;
			unsigned char worldVertFormat;
			unsigned char preDisplacementOnlyCount;
			MaterialTechnique* __ptr64 techniques[252];
		}; static_assert(sizeof(MaterialTechniqueSet) == 0x7F0);

		static_assert(offsetof(MaterialTechniqueSet, techniques) == 16);

		struct GfxImage;

		struct WaterWritable
		{
			float floatTime;
		};

		struct water_t
		{
			WaterWritable writable;
			float* __ptr64 H0X;
			float* __ptr64 H0Y;
			float* __ptr64 wTerm;
			int M;
			int N;
			float Lx;
			float Lz;
			float gravity;
			float windvel;
			float winddir[2];
			float amplitude;
			GfxImage* __ptr64 image;
			GfxImage* __ptr64 stagingImage;
		};

		union MaterialTextureDefInfo
		{
			GfxImage* __ptr64 image;
			water_t* __ptr64 water;
		};

		struct MaterialTextureDef
		{
			unsigned int nameHash;
			char nameStart;
			char nameEnd;
			unsigned char samplerState;
			unsigned char semantic;
			MaterialTextureDefInfo u;
		}; static_assert(sizeof(MaterialTextureDef) == 0x10);

		struct MaterialConstantDef
		{
			unsigned int nameHash;
			char name[12];
			float literal[4];
		}; static_assert(sizeof(MaterialConstantDef) == 0x20);

		struct GfxStateBits
		{
			unsigned int loadBits[6]; // loadbits[3], blendstatebits[3]
			unsigned short zone;
			unsigned char depthStencilState[10];
			unsigned char blendState;
			unsigned char rasterizerState;
		}; static_assert(sizeof(GfxStateBits) == 0x28);

		struct MaterialConstantBufferDef
		{
			unsigned int vsDataSize;
			unsigned int hsDataSize;
			unsigned int dsDataSize;
			unsigned int psDataSize;
			unsigned int vsOffsetDataSize;
			unsigned int hsOffsetDataSize;
			unsigned int dsOffsetDataSize;
			unsigned int psOffsetDataSize;
			unsigned char* __ptr64 vsData;
			unsigned char* __ptr64 hsData;
			unsigned char* __ptr64 dsData;
			unsigned char* __ptr64 psData;
			unsigned short* __ptr64 vsOffsetData;
			unsigned short* __ptr64 hsOffsetData;
			unsigned short* __ptr64 dsOffsetData;
			unsigned short* __ptr64 psOffsetData;
			ID3D11Buffer* __ptr64 vsConstantBuffer;
			ID3D11Buffer* __ptr64 hsConstantBuffer;
			ID3D11Buffer* __ptr64 dsConstantBuffer;
			ID3D11Buffer* __ptr64 psConstantBuffer;
		};

		enum SurfaceTypeBits : std::uint64_t
		{
			SURFTYPE_BITS_NONE = 0x0,
			SURFTYPE_BITS_DEFAULT = 0x1,
			SURFTYPE_BITS_BARK = 0x2,
			SURFTYPE_BITS_CARPET = 0x4,
			SURFTYPE_BITS_CLOTH = 0x8,
			SURFTYPE_BITS_CONCRETE = 0x10,
			SURFTYPE_BITS_DIRT = 0x20,
			SURFTYPE_BITS_FLESH = 0x40,
			SURFTYPE_BITS_FOLIAGE_DEBRIS = 0x80,
			SURFTYPE_BITS_GLASS = 0x100,
			SURFTYPE_BITS_GRASS = 0x200,
			SURFTYPE_BITS_GRAVEL = 0x400,
			SURFTYPE_BITS_ICE = 0x800,
			SURFTYPE_BITS_METAL_SOLID = 0x1000,
			SURFTYPE_BITS_METAL_GRATE = 0x2000,
			SURFTYPE_BITS_MUD = 0x4000,
			SURFTYPE_BITS_PAPER = 0x8000,
			SURFTYPE_BITS_PLASTER = 0x10000,
			SURFTYPE_BITS_ROCK = 0x20000,
			SURFTYPE_BITS_SAND = 0x40000,
			SURFTYPE_BITS_SNOW = 0x80000,
			SURFTYPE_BITS_WATER_WAIST = 0x100000,
			SURFTYPE_BITS_WOOD_SOLID = 0x200000,
			SURFTYPE_BITS_ASPHALT = 0x400000,
			SURFTYPE_BITS_CERAMIC = 0x800000,
			SURFTYPE_BITS_PLASTIC_SOLID = 0x1000000,
			SURFTYPE_BITS_RUBBER = 0x2000000,
			SURFTYPE_BITS_FRUIT = 0x4000000,
			SURFTYPE_BITS_PAINTEDMETAL = 0x8000000,
			SURFTYPE_BITS_RIOTSHIELD = 0x10000000,
			SURFTYPE_BITS_SLUSH = 0x20000000,
			SURFTYPE_BITS_ASPHALT_WET = 0x40000000,
			SURFTYPE_BITS_ASPHALT_DEBRIS = 0x80000000,
			SURFTYPE_BITS_CONCRETE_WET = 0x100000000,
			SURFTYPE_BITS_CONCRETE_DEBRIS = 0x200000000,
			SURFTYPE_BITS_FOLIAGE_VEGETATION = 0x400000000,
			SURFTYPE_BITS_FOLIAGE_LEAVES = 0x800000000,
			SURFTYPE_BITS_GRASS_TALL = 0x1000000000,
			SURFTYPE_BITS_METAL_HOLLOW = 0x2000000000,
			SURFTYPE_BITS_METAL_VEHICLE = 0x4000000000,
			SURFTYPE_BITS_METAL_THIN = 0x8000000000,
			SURFTYPE_BITS_METAL_WET = 0x10000000000,
			SURFTYPE_BITS_METAL_DEBRIS = 0x20000000000,
			SURFTYPE_BITS_PLASTIC_HOLLOW = 0x40000000000,
			SURFTYPE_BITS_PLASTIC_TARP = 0x80000000000,
			SURFTYPE_BITS_ROCK_WET = 0x100000000000,
			SURFTYPE_BITS_ROCK_DEBRIS = 0x200000000000,
			SURFTYPE_BITS_WATER_ANKLE = 0x400000000000,
			SURFTYPE_BITS_WATER_KNEE = 0x800000000000,
			SURFTYPE_BITS_WOOD_HOLLOW = 0x1000000000000,
			SURFTYPE_BITS_WOOD_WET = 0x2000000000000,
			SURFTYPE_BITS_WOOD_DEBRIS = 0x4000000000000,
			SURFTYPE_BITS_CUSHION = 0x8000000000000,
		};

		struct MaterialInfo
		{
			const char* __ptr64 name;
			unsigned char gameFlags;
			unsigned char sortKey;
			unsigned char textureAtlasRowCount;
			unsigned char textureAtlasColumnCount;
			unsigned char textureAtlasFrameBlend;
			unsigned char textureAtlasAsArray;
			unsigned char renderFlags;
			GfxDrawSurf drawSurf;
			SurfaceTypeBits surfaceTypeBits;
			unsigned int hashIndex;
		}; static_assert(sizeof(MaterialInfo) == 48);

		struct Material
		{
			union
			{
				const char* __ptr64 name;
				MaterialInfo info;
			};
			unsigned char stateBitsEntry[252];
			unsigned char textureCount;
			unsigned char constantCount;
			unsigned char stateBitsCount;
			unsigned char stateFlags;
			unsigned char cameraRegion;
			unsigned char materialType;
			unsigned char layerCount;
			unsigned char assetFlags;
			MaterialTechniqueSet* __ptr64 techniqueSet;
			MaterialTextureDef* __ptr64 textureTable;
			MaterialConstantDef* __ptr64 constantTable;
			GfxStateBits* __ptr64 stateBitsTable;
			unsigned char constantBufferIndex[252];
			char __pad0[4];
			MaterialConstantBufferDef* __ptr64 constantBufferTable;
			unsigned char constantBufferCount;
			const char* __ptr64* __ptr64 subMaterials;
		}; static_assert(sizeof(Material) == 0x270);

		static_assert(offsetof(Material, textureCount) == 0x12C);
		static_assert(offsetof(Material, techniqueSet) == 0x138);
		static_assert(offsetof(Material, textureTable) == 0x140);
		static_assert(offsetof(Material, constantTable) == 0x148);
		static_assert(offsetof(Material, stateBitsTable) == 0x150);
		static_assert(offsetof(Material, constantBufferTable) == 0x258);
		static_assert(offsetof(Material, constantBufferCount) == 0x260);
		static_assert(offsetof(Material, subMaterials) == 0x268);

		struct GfxImageLoadDef
		{
			char levelCount;
			char numElements;
			char pad[2];
			int flags;
			int format;
			int resourceSize;
			char data[1];
		};

		struct GfxTexture
		{
			union
			{
				ID3D11Texture1D* __ptr64 linemap;
				ID3D11Texture2D* __ptr64 map;
				ID3D11Texture3D* __ptr64 volmap;
				ID3D11Texture2D* __ptr64 cubemap;
				GfxImageLoadDef* __ptr64 loadDef;
			};
			ID3D11ShaderResourceView* __ptr64 shaderView;
			ID3D11ShaderResourceView* __ptr64 shaderViewAlternate;
		};

		struct Picmip
		{
			unsigned char platform[2];
		};

		struct GfxImageStreamData
		{
			unsigned short width;
			unsigned short height;
			unsigned int pixelSize;
		};

		enum MapType : std::uint8_t
		{
			MAPTYPE_NONE = 0x0,
			MAPTYPE_INVALID1 = 0x1,
			MAPTYPE_1D = 0x2,
			MAPTYPE_2D = 0x3,
			MAPTYPE_3D = 0x4,
			MAPTYPE_CUBE = 0x5,
			MAPTYPE_ARRAY = 0x6,
			MAPTYPE_COUNT = 0x7,
		};

		struct GfxImage
		{
			GfxTexture texture;
			DXGI_FORMAT imageFormat;
			MapType mapType;
			unsigned char semantic;
			unsigned char category;
			unsigned char flags;
			Picmip picmip;
			char __pad0[2];
			unsigned int dataLen1;
			unsigned int dataLen2;
			unsigned short width;
			unsigned short height;
			unsigned short depth;
			unsigned short numElements;
			unsigned char levelCount;
			unsigned char streamed;
			char __pad1[2];
			unsigned char* __ptr64 pixelData;
			GfxImageStreamData streams[4];
			const char* __ptr64 name;
		}; static_assert(sizeof(GfxImage) == 0x68);

		struct GfxLightImage
		{
			GfxImage* __ptr64 image;
			unsigned char samplerState;
		};

		struct GfxLightDef
		{
			const char* __ptr64 name;
			GfxLightImage attenuation;
			GfxLightImage cucoloris;
			int lmapLookupStart;
		}; static_assert(sizeof(GfxLightDef) == 0x30);

		struct GfxColorFloat
		{
			float array[4];
		};

		enum snd_alias_type_t : std::int8_t
		{
			SAT_UNKNOWN = 0x0,
			SAT_LOADED = 0x1,
			SAT_STREAMED = 0x2,
			SAT_PRIMED = 0x3,
			SAT_COUNT = 0x4,
		};

		struct StreamFileNameRaw
		{
			const char* __ptr64 dir;
			const char* __ptr64 name;
		};

		struct StreamFileNamePacked
		{
			unsigned __int64 offset;
			unsigned __int64 length;
		};

		union StreamFileInfo
		{
			StreamFileNameRaw raw;
			StreamFileNamePacked packed;
		};

		struct StreamFileName
		{
			bool isLocalized;
			bool isStreamed;
			unsigned short fileIndex;
			StreamFileInfo info;
		};

		struct StreamedSound
		{
			StreamFileName filename;
			unsigned int totalMsec;
		};

		struct LoadedSoundInfo
		{
			char* __ptr64 data;
			unsigned int sampleRate;
			unsigned int dataByteCount;
			unsigned int numSamples;
			char channels;
			char numBits;
			char blockAlign;
			short format;
			int loadedSize;
		}; static_assert(sizeof(LoadedSoundInfo) == 0x20);

		struct LoadedSound
		{
			const char* __ptr64 name;
			StreamFileName filename;
			LoadedSoundInfo info;
		}; static_assert(sizeof(LoadedSound) == 0x40);

		struct PrimedSound
		{
			LoadedSound* __ptr64 loadedPart;
			StreamFileName streamedPart;
			int dataOffset; // not sure
			int totalSize; // not sure
		}; static_assert(sizeof(PrimedSound) == 0x28);

		union SoundFileRef
		{
			LoadedSound* __ptr64 loadSnd;
			StreamedSound streamSnd;
			PrimedSound primedSnd;
		};

		struct SoundFile
		{
			snd_alias_type_t type;
			bool exists;
			SoundFileRef u;
		};

		struct SndContext
		{
			const char* __ptr64 name;
			char __pad0[8];
		};

		struct SndCurve
		{
			bool isDefault;
			union
			{
				const char* __ptr64 filename;
				const char* __ptr64 name;
			};
			unsigned short knotCount;
			float knots[16][2];
		}; static_assert(sizeof(SndCurve) == 0x98);

		struct SpeakerLevels
		{
			char speaker;
			char numLevels;
			float levels[2];
		};

		struct ChannelMap
		{
			int speakerCount;
			SpeakerLevels speakers[6];
		};

		struct SpeakerMap
		{
			bool isDefault;
			const char* __ptr64 name;
			int unknown;
			ChannelMap channelMaps[2][2];
		}; static_assert(sizeof(SpeakerMap) == 0x148);

		struct DopplerPreset
		{
			const char* __ptr64 name;
			float speedOfSound;
			float playerVelocityScale;
			float minPitch;
			float maxPitch;
			float smoothing;
		}; static_assert(sizeof(DopplerPreset) == 0x20);

		union SoundAliasFlags
		{
			struct _
			{
				unsigned int looping : 1;
				unsigned int isMaster : 1;
				unsigned int isSlave : 1;
				unsigned int fullDryLevel : 1;
				unsigned int noWetLevel : 1;
				unsigned int is3d : 1;
				unsigned int type : 2;
			};
			unsigned int intValue;
		};

		struct snd_alias_t
		{
			const char* __ptr64 aliasName;
			const char* __ptr64 subtitle;
			const char* __ptr64 secondaryAliasName;
			const char* __ptr64 chainAliasName;
			SoundFile* __ptr64 soundFile;
			const char* __ptr64 mixerGroup;
			short poly;
			short polyGlobal;
			char polyEntityType;
			char polyGlobalType;
			char dspBusIndex;
			char priority;
			char __pad0[12]; // unknown
			float volMin;
			float volMax;
			short volModIndex;
			float pitchMin;
			float pitchMax;
			float distMin;
			float distMax;
			float velocityMin;
			int flags;
			char masterPriority;
			float masterPercentage;
			float slavePercentage;
			char playbackPercentage;
			float probability;
			char u1; // value: 0-4
			SndContext* __ptr64 sndContext;
			unsigned char sequence;
			float lfePercentage;
			float centerPercentage;
			int startDelay;
			SndCurve* __ptr64 sndCurve;
			float envelopMin;
			float envelopMax;
			SndCurve* __ptr64 lpfCurve;
			SndCurve* __ptr64 hpfCurve;
			SndCurve* __ptr64 reverbSendCurve;
			SpeakerMap* __ptr64 speakerMap;
			float reverbWetMixOverride;
			float reverbMultiplier;
			float smartPanDistance2d;
			float smartPanDistance3d;
			float smartPanAttenuation3d;
			float envelopPercentage;
			short stereo3dAngle;
			//char __padding4[2]; // padding
			float stereo3dStart;
			float stereo3dEnd;
			unsigned char allowDoppler;
			//char __padding5[3]; // padding
			DopplerPreset* __ptr64 dopplerPreset;
			float u2;
			//char __padding6[4]; // padding
		};

		static_assert(sizeof(snd_alias_t) == 256);

		struct snd_alias_context_list
		{
			short unk;
		};

		struct snd_alias_list_t
		{
			union
			{
				const char* __ptr64 aliasName;
				const char* __ptr64 name;
			};
			snd_alias_t* __ptr64 head;
			snd_alias_context_list* __ptr64 contextList;
			unsigned char count;
			unsigned char contextListCount;
			char __pad0[6];
		};

		struct LocalizeEntry
		{
			const char* __ptr64 value;
			const char* __ptr64 name;
		}; static_assert(sizeof(LocalizeEntry) == 0x10);

		struct TriggerModel
		{
			int contents;
			unsigned short hullCount;
			unsigned short firstHull;
		};

		struct TriggerHull
		{
			Bounds bounds;
			int contents;
			unsigned short slabCount;
			unsigned short firstSlab;
		};

		struct TriggerSlab
		{
			float dir[3];
			float midPoint;
			float halfSize;
		};

		struct MapTriggers
		{
			unsigned int count;
			TriggerModel* __ptr64 models;
			unsigned int hullCount;
			TriggerHull* __ptr64 hulls;
			unsigned int slabCount;
			TriggerSlab* __ptr64 slabs;
		};

		struct ClientTriggerAabbNode
		{
			Bounds bounds;
			unsigned short firstChild;
			unsigned short childCount;
		};

		struct ClientTriggers
		{
			MapTriggers trigger;
			unsigned short numClientTriggerNodes;
			ClientTriggerAabbNode* __ptr64 clientTriggerAabbTree;
			unsigned int triggerStringLength;
			char* __ptr64 triggerString;
			short* __ptr64 unk0;
			short* __ptr64 unk1;
			short* __ptr64 unk2;
			short* __ptr64 triggerType;
			vec3_t* __ptr64 origins;
			float* __ptr64 scriptDelay;
			short* __ptr64 unk3;
			short* __ptr64 unk4;
			short* __ptr64 unk5;
			short* __ptr64 unk6;
			short* __ptr64 unk7;
			short* __ptr64 unk8;
		}; static_assert(sizeof(ClientTriggers) == 0xB0);

		struct ClientTriggerBlendNode
		{
			float pointA[3];
			float pointB[3];
			unsigned short triggerA;
			unsigned short triggerB;
		};

		struct ClientTriggerBlend
		{
			unsigned short numClientTriggerBlendNodes;
			ClientTriggerBlendNode* __ptr64 blendNodes;
		};

		struct SpawnPointEntityRecord
		{
			unsigned short index;
			scr_string_t name;
			scr_string_t target;
			scr_string_t script_noteworthy;
			scr_string_t unknown;
			float origin[3];
			float angles[3];
		};

		struct SpawnPointRecordList
		{
			unsigned short spawnsCount;
			SpawnPointEntityRecord* __ptr64 spawns;
		};

		struct SplinePointEntityRecord
		{
			int splineId;
			int splineNodeId;
			char* __ptr64 splineNodeLabel;
			float splineNodeTension;
			float origin[3];
			float corridorDims[2];
			float tangent[3];
			float distToNextNode;
			vec3_t* __ptr64 positionCubic;
			vec3_t* __ptr64 tangentQuadratic;
		};

		struct SplinePointRecordList
		{
			unsigned short splinePointCount;
			float splineLength;
			SplinePointEntityRecord* __ptr64 splinePoints;
		};

		struct SplineRecordList
		{
			unsigned short splineCount;
			SplinePointRecordList* __ptr64 splines;
		};

		struct MapEnts
		{
			const char* __ptr64 name;
			char* __ptr64 entityString;
			int numEntityChars;
			MapTriggers trigger;
			ClientTriggers clientTrigger;
			ClientTriggerBlend clientTriggerBlend;
			SpawnPointRecordList spawnList;
			SplineRecordList splineList;
		}; static_assert(sizeof(MapEnts) == 0x128);

		struct AddonMapEnts
		{
			const char* __ptr64 name;
			char* __ptr64 entityString;
			int numEntityChars;
			MapTriggers trigger;
			void* __ptr64 info;
			unsigned int numSubModels;
			void* __ptr64 cmodels;
			void* __ptr64 models;
			char __pad0[0x20];
		};

		static_assert(sizeof(AddonMapEnts) == 136);

		struct RawFile
		{
			const char* __ptr64 name;
			int compressedLen;
			int len;
			const char* __ptr64 buffer;
		}; static_assert(sizeof(RawFile) == 0x18);

		struct ScriptFile
		{
			const char* __ptr64 name;
			int compressedLen;
			int len;
			int bytecodeLen;
			const char* __ptr64 buffer;
			char* __ptr64 bytecode;
		}; static_assert(sizeof(ScriptFile) == 0x28);

		struct StringTableCell
		{
			const char* __ptr64 string;
			int hash;
		};

		struct StringTable
		{
			const char* __ptr64 name;
			int columnCount;
			int rowCount;
			StringTableCell* __ptr64 values;
		}; static_assert(sizeof(StringTable) == 0x18);

		struct StructuredDataEnumEntry
		{
			scr_string_t string;
			unsigned short index;
		};

		struct StructuredDataEnum
		{
			int entryCount;
			int reservedEntryCount;
			StructuredDataEnumEntry* __ptr64 entries;
		};

		enum StructuredDataTypeCategory
		{
			DATA_INT = 0x0,
			DATA_BYTE = 0x1,
			DATA_BOOL = 0x2,
			DATA_STRING = 0x3,
			DATA_ENUM = 0x4,
			DATA_STRUCT = 0x5,
			DATA_INDEXED_ARRAY = 0x6,
			DATA_ENUM_ARRAY = 0x7,
			DATA_FLOAT = 0x8,
			DATA_SHORT = 0x9,
			DATA_COUNT = 0xA,
		};

		union StructuredDataTypeUnion
		{
			unsigned int stringDataLength;
			int enumIndex;
			int structIndex;
			int indexedArrayIndex;
			int enumedArrayIndex;
			int index;
		};

		struct StructuredDataType
		{
			StructuredDataTypeCategory type;
			StructuredDataTypeUnion u;
		};

		enum StructuredDataValidationType
		{
			VALIDATION_NONE = 0x0,
		};

		struct StructuredDataStructProperty
		{
			scr_string_t name;
			StructuredDataType type;
			unsigned int offset;
			StructuredDataValidationType validation;
		};

		struct StructuredDataStruct
		{
			int propertyCount;
			StructuredDataStructProperty* __ptr64 properties;
			int size;
			unsigned int bitOffset;
		};

		struct StructuredDataIndexedArray
		{
			int arraySize;
			StructuredDataType elementType;
			unsigned int elementSize;
		};

		struct StructuredDataEnumedArray
		{
			int enumIndex;
			StructuredDataType elementType;
			unsigned int elementSize;
		};

		struct StructuredDataDef
		{
			int version;
			unsigned int formatChecksum;
			int enumCount;
			StructuredDataEnum* __ptr64 enums;
			int structCount;
			StructuredDataStruct* __ptr64 structs;
			int indexedArrayCount;
			StructuredDataIndexedArray* __ptr64 indexedArrays;
			int enumedArrayCount;
			StructuredDataEnumedArray* __ptr64 enumedArrays;
			StructuredDataType rootType;
			unsigned int size;
		}; static_assert(sizeof(StructuredDataDef) == 0x58);

		struct StructuredDataDefSet
		{
			const char* __ptr64 name;
			unsigned int defCount;
			StructuredDataDef* __ptr64 defs;
		}; static_assert(sizeof(StructuredDataDefSet) == 0x18);

		enum NetConstStringType
		{
		};

		enum NetConstStringSource
		{
		};

		struct NetConstStrings
		{
			const char* __ptr64 name;
			NetConstStringType stringType;
			NetConstStringSource sourceType;
			unsigned int entryCount;
			const char* __ptr64* __ptr64 stringList;
		}; static_assert(sizeof(NetConstStrings) == 0x20);

		struct LuaFile
		{
			const char* __ptr64 name;
			int len;
			char strippingType;
			const char* __ptr64 buffer;
		}; static_assert(sizeof(LuaFile) == 0x18);

		struct TTFDef
		{
			const char* __ptr64 name;
			int fileLen;
			const char* __ptr64 file;
			void* __ptr64 ftFace;
		}; static_assert(sizeof(TTFDef) == 0x20);

		struct FxParticleSimAnimationHeader
		{
			float playbackRate;
			float duration;
			unsigned int frameCount;
			float minX;
			float minY;
			float minZ;
			float boundsXDelta;
			float boundsYDelta;
			float boundsZDelta;
			float maxWidth;
			float maxHeight;
			unsigned int colorTableSize;
			unsigned int particleDataCount;
			bool evalVisStatePerParticle;
			bool sortParticlesAtRuntime;
		};

		struct FxParticleSimAnimationParticleData
		{
			unsigned short xNormalizedPos;
			unsigned short yNormalizedPos;
			unsigned short zNormalizedPos;
			unsigned short xNormalizedWidth;
			unsigned short yNormalizedHeight;
			unsigned short orientation;
			unsigned short lifetime;
			unsigned short particleID;
			unsigned short xNormalizedPosNextFrame;
			unsigned short yNormalizedPosNextFrame;
			unsigned short zNormalizedPosNextFrame;
			unsigned short xNormalizedWidthNextFrame;
			unsigned short yNormalizedHeightNextFrame;
			short orientationDelta;
			unsigned short colorTableIndex;
			unsigned short nextColorTableIndex;
		};

		struct FxParticleSimAnimationFrame
		{
			unsigned int particleDataOffset;
			unsigned int numActiveParticles;
		};

		struct FxParticleSimAnimation
		{
			const char* __ptr64 name;
			Material* __ptr64 material;
			FxParticleSimAnimationHeader header;
			FxParticleSimAnimationParticleData* __ptr64 particleData;
			FxParticleSimAnimationFrame* __ptr64 frames;
			GfxColorFloat* __ptr64 colorTable;
		};

		enum FxElemType : std::uint8_t
		{
			FX_ELEM_TYPE_SPRITE_BILLBOARD = 0,
			FX_ELEM_TYPE_SPRITE_ORIENTED = 1,
			FX_ELEM_TYPE_SPRITE_ROTATED = 2,
			FX_ELEM_TYPE_TAIL = 3,
			FX_ELEM_TYPE_LINE = 4,
			FX_ELEM_TYPE_TRAIL = 5,
			FX_ELEM_TYPE_FLARE = 6,
			FX_ELEM_TYPE_PARTICLE_SIM_ANIMATION = 7,
			FX_ELEM_TYPE_CLOUD = 8,
			FX_ELEM_TYPE_SPARK_CLOUD = 9,
			FX_ELEM_TYPE_SPARK_FOUNTAIN = 10,
			FX_ELEM_TYPE_MODEL = 11,
			FX_ELEM_TYPE_OMNI_LIGHT = 12,
			FX_ELEM_TYPE_SPOT_LIGHT = 13,
			FX_ELEM_TYPE_SOUND = 14,
			FX_ELEM_TYPE_DECAL = 15,
			FX_ELEM_TYPE_RUNNER = 16,
			FX_ELEM_TYPE_VECTORFIELD = 17,
		};

		struct FxFloatRange
		{
			float base;
			float amplitude;
		};

		struct FxSpawnDefLooping
		{
			int intervalMsec;
			int count;
		};

		struct FxIntRange
		{
			int base;
			int amplitude;
		};

		struct FxSpawnDefOneShot
		{
			FxIntRange count;
		};

		union FxSpawnDef
		{
			FxSpawnDefLooping looping;
			FxSpawnDefOneShot oneShot;
		};

		struct FxElemAtlas
		{
			unsigned char behavior;
			unsigned char index;
			unsigned char fps;
			unsigned char loopCount;
			unsigned char colIndexBits;
			unsigned char rowIndexBits;
			short entryCount;
		};

		struct FxEffectDef;
		union FxEffectDefRef
		{
			FxEffectDef* __ptr64 handle;
			const char* __ptr64 name;
		};

		struct FxElemVec3Range
		{
			float base[3];
			float amplitude[3];
			float unk_vec[3];
		};

		struct FxElemVelStateInFrame
		{
			FxElemVec3Range velocity;
			FxElemVec3Range totalDelta;
		};

		struct FxElemVelStateSample
		{
			FxElemVelStateInFrame local;
			FxElemVelStateInFrame world;
		}; static_assert(sizeof(FxElemVelStateSample) == 144);

		struct FxElemVisualState
		{
			float color[4];
			float unlitHDRScale;
			float rotationDelta;
			float rotationTotal;
			float size[2];
			float scale;
			char __pad0[16];
		};

		struct FxElemVisStateSample
		{
			FxElemVisualState base;
			FxElemVisualState amplitude;
		}; static_assert(sizeof(FxElemVisStateSample) == 112);

		struct FxElemMarkVisuals
		{
			Material* __ptr64 materials[3];
		};

		struct XModel;
		union FxElemVisuals
		{
			const void* __ptr64 anonymous;
			Material* __ptr64 material;
			XModel* __ptr64 model;
			FxEffectDefRef effectDef;
			const char* __ptr64 soundName;
			const char* __ptr64 vectorFieldName;
			GfxLightDef* __ptr64 lightDef;
			FxParticleSimAnimation* __ptr64 particleSimAnimation;
		};

		union FxElemDefVisuals
		{
			FxElemMarkVisuals* __ptr64 markArray;
			FxElemVisuals* __ptr64 array;
			FxElemVisuals instance;
		};

		struct FxTrailVertex
		{
			float pos[2];
			float normal[2];
			float texCoord[2];
			char __pad0[8];
		}; static_assert(sizeof(FxTrailVertex) == 32);

		struct FxTrailDef
		{
			int scrollTimeMsec;
			int repeatDist;
			float invSplitDist;
			float invSplitArcDist;
			float invSplitTime;
			char __pad0[12];
			int vertCount;
			FxTrailVertex* __ptr64 verts;
			int indCount;
			unsigned short* __ptr64 inds;
		}; static_assert(sizeof(FxTrailDef) == 0x40);
		static_assert(offsetof(FxTrailDef, verts) == 40);
		static_assert(offsetof(FxTrailDef, inds) == 56);
		static_assert(offsetof(FxTrailDef, vertCount) == 32);
		static_assert(offsetof(FxTrailDef, indCount) == 48);

		struct FxSparkFountainDef
		{
			float gravity;
			float bounceFrac;
			float bounceRand;
			float sparkSpacing;
			float sparkLength;
			int sparkCount;
			float loopTime;
			float velMin;
			float velMax;
			float velConeFrac;
			float restSpeed;
			float boostTime;
			float boostFactor;
		}; static_assert(sizeof(FxSparkFountainDef) == 0x34);

		struct FxSpotLightDef
		{
			float fovInnerFraction;
			float startRadius;
			float endRadius;
			float brightness;
			float maxLength;
			int exponent;
			char __pad0[24];
		}; static_assert(sizeof(FxSpotLightDef) == 0x30);

		struct FxOmniLightDef
		{
			char __pad0[16];
		}; static_assert(sizeof(FxOmniLightDef) == 0x10);

		struct FxFlareDef
		{
			float position;
			int angularRotCount;
			int flags;
			FxFloatRange depthScaleRange;
			FxFloatRange depthScaleValue;
			FxFloatRange radialRot;
			FxFloatRange radialScaleX;
			FxFloatRange radialScaleY;
			float dir[3];
			int intensityXIntervalCount;
			int intensityYIntervalCount;
			int srcCosIntensityIntervalCount;
			int srcCosScaleIntervalCount;
			float* __ptr64 intensityX;
			float* __ptr64 intensityY;
			float* __ptr64 srcCosIntensity;
			float* __ptr64 srcCosScale;
		}; static_assert(sizeof(FxFlareDef) == 0x70);

		struct FxDecalDef
		{
			char __pad0[3];
		};

		union FxElemExtendedDefPtr
		{
			char* __ptr64 unknownDef;
			FxTrailDef* __ptr64 trailDef;
			FxSparkFountainDef* __ptr64 sparkFountainDef;
			FxSpotLightDef* __ptr64 spotLightDef;
			FxOmniLightDef* __ptr64 omniLightDef;
			FxFlareDef* __ptr64 flareDef;
			FxDecalDef* __ptr64 decalDef;
		};

		struct FxElemDef
		{
			int flags;
			int flags2;
			FxSpawnDef spawn;
			FxFloatRange spawnRange;
			FxFloatRange fadeInRange;
			FxFloatRange fadeOutRange;
			float spawnFrustumCullRadius;
			FxIntRange spawnDelayMsec;
			FxIntRange lifeSpanMsec;
			FxFloatRange spawnOrigin[3];
			char __pad0[4];
			FxFloatRange spawnOffsetRadius;
			FxFloatRange spawnOffsetHeight;
			char __pad1[8];
			FxFloatRange spawnAngles[3];
			FxFloatRange angularVelocity[3];
			FxFloatRange initialRotation;
			FxFloatRange gravity;
			FxFloatRange reflectionFactor;
			FxElemAtlas atlas;
			FxElemType elemType;
			unsigned char elemLitType;
			unsigned char visualCount;
			unsigned char velIntervalCount;
			unsigned char visStateIntervalCount;
			FxElemVelStateSample* __ptr64 velSamples;
			FxElemVisStateSample* __ptr64 visSamples;
			FxElemDefVisuals visuals;
			Bounds collBounds;
			FxEffectDefRef effectOnImpact;
			FxEffectDefRef effectOnDeath;
			FxEffectDefRef effectEmitted;
			FxFloatRange emitDist;
			FxFloatRange emitDistVariance;
			FxElemExtendedDefPtr extended;
			unsigned char sortOrder;
			unsigned char lightingFrac;
			unsigned char useItemClip;
			unsigned char fadeInfo;
			int randomSeed;
			char __pad2[16];
		}; static_assert(sizeof(FxElemDef) == 0x140);

		static_assert(offsetof(FxElemDef, spawnOrigin) == 60);
		static_assert(offsetof(FxElemDef, spawnOffsetRadius) == 88);
		static_assert(offsetof(FxElemDef, spawnOffsetHeight) == 96);
		static_assert(offsetof(FxElemDef, spawnAngles) == 112);
		static_assert(offsetof(FxElemDef, spawnDelayMsec) == 44);
		static_assert(offsetof(FxElemDef, lifeSpanMsec) == 52);
		static_assert(offsetof(FxElemDef, spawn) == 8);
		static_assert(offsetof(FxElemDef, visualCount) == 194);
		static_assert(offsetof(FxElemDef, effectOnDeath) == 256);
		static_assert(offsetof(FxElemDef, spawnAngles) == 112);
		static_assert(offsetof(FxElemDef, elemType) == 192);
		static_assert(offsetof(FxElemDef, visSamples) == 0xD0);
		static_assert(offsetof(FxElemDef, visuals) == 0xD8);
		static_assert(offsetof(FxElemDef, effectOnImpact) == 0xF8);
		static_assert(offsetof(FxElemDef, effectOnDeath) == 0x100);
		static_assert(offsetof(FxElemDef, effectEmitted) == 0x108);
		static_assert(offsetof(FxElemDef, extended) == 0x120);
		static_assert(offsetof(FxElemDef, effectEmitted) == 0x108);
		static_assert(offsetof(FxElemDef, visStateIntervalCount) == 0xC4);
		static_assert(offsetof(FxElemDef, visualCount) == 194);
		static_assert(offsetof(FxElemDef, velIntervalCount) == 0xC3);

		struct FxEffectDef
		{
			const char* __ptr64 name;
			int flags;
			int totalSize;
			int msecLoopingLife;
			int elemDefCountLooping;
			int elemDefCountOneShot;
			int elemDefCountEmission;
			float elemMaxRadius;
			float occlusionQueryDepthBias;
			int occlusionQueryFadeIn;
			int occlusionQueryFadeOut;
			FxFloatRange occlusionQueryScaleRange;
			float xU_01;
			FxElemDef* __ptr64 elemDefs;
		}; static_assert(sizeof(FxEffectDef) == 0x48);

		static_assert(offsetof(FxEffectDef, elemDefs) == 0x40);
		static_assert(offsetof(FxEffectDef, elemDefCountLooping) == 0x14);
		static_assert(offsetof(FxEffectDef, elemDefCountOneShot) == 0x18);
		static_assert(offsetof(FxEffectDef, elemDefCountEmission) == 0x1C);

		struct XModelIKData
		{
			unsigned char charDataLen;
			unsigned char floatDataLen;
			unsigned char int32DataLen;
			unsigned char stringsCount;
			char* __ptr64 charData;
			float* __ptr64 floatData;
			int* __ptr64 int32Data;
			scr_string_t* __ptr64 strings;
		}; static_assert(sizeof(XModelIKData) == 0x28);

		struct SkeletonScriptCode
		{
			char __pad0[4];
		};

		struct SkeletonScript
		{
			const char* __ptr64 name;
			XModelIKData ikData;
			unsigned short codeLen;
			SkeletonScriptCode* __ptr64 code;
		}; static_assert(sizeof(SkeletonScript) == 0x40);

		static_assert(offsetof(SkeletonScript, ikData) == 8);
		static_assert(offsetof(XModelIKData, strings) == 32);
		static_assert(offsetof(XModelIKData, stringsCount) == 3);
		static_assert(offsetof(XModelIKData, int32Data) == 24);
		static_assert(offsetof(XModelIKData, int32DataLen) == 2);
		static_assert(offsetof(XModelIKData, floatData) == 16);
		static_assert(offsetof(XModelIKData, floatDataLen) == 1);

		union XAnimDynamicFrames
		{
			unsigned char(*__ptr64 _1)[3];
			unsigned short(*__ptr64 _2)[3];
		};

		union XAnimDynamicIndices
		{
			unsigned char _1[1];
			unsigned short _2[1];
		};

		struct XAnimPartTransFrames
		{
			float mins[3];
			float size[3];
			XAnimDynamicFrames frames;
			XAnimDynamicIndices indices;
		};

		union XAnimPartTransData
		{
			XAnimPartTransFrames frames;
			float frame0[3];
		};

		struct XAnimPartTrans
		{
			unsigned short size;
			unsigned char smallTrans;
			XAnimPartTransData u;
		};

		struct XAnimDeltaPartQuatDataFrames2
		{
			short(*__ptr64 frames)[2];
			XAnimDynamicIndices indices;
		};

		union XAnimDeltaPartQuatData2
		{
			XAnimDeltaPartQuatDataFrames2 frames;
			short frame0[2];
		};

		struct XAnimDeltaPartQuat2
		{
			unsigned short size;
			XAnimDeltaPartQuatData2 u;
		};

		struct XAnimDeltaPartQuatDataFrames
		{
			short(*__ptr64 frames)[4];
			XAnimDynamicIndices indices;
		};

		union XAnimDeltaPartQuatData
		{
			XAnimDeltaPartQuatDataFrames frames;
			short frame0[4];
		};

		struct XAnimDeltaPartQuat
		{
			unsigned short size;
			XAnimDeltaPartQuatData u;
		};

		struct XAnimDeltaPart
		{
			XAnimPartTrans* __ptr64 trans;
			XAnimDeltaPartQuat2* __ptr64 quat2;
			XAnimDeltaPartQuat* __ptr64 quat;
		};

		union XAnimIndices
		{
			unsigned char* __ptr64 _1;
			unsigned short* __ptr64 _2;
			void* __ptr64 data;
		};

		struct XAnimNotifyInfo
		{
			scr_string_t name;
			float time;
		};

		enum XAnimPartsFlags : std::uint8_t
		{
			ANIM_NONE = 0x0,
			ANIM_LOOP = 0x1,
			ANIM_DELTA = 0x2,
			ANIM_DELTA_3D = 0x4,
			ANIM_DEFAULT = 0x8,
		};

		typedef float BlendShapeWeight;
		typedef char XAnimScriptedViewmodelAnimData;

		struct XAnimParts
		{
			const char* __ptr64 name; // 0
			unsigned short dataByteCount; // 8
			unsigned short dataShortCount; // 10
			unsigned short dataIntCount; // 12
			unsigned short numframes; // 14
			unsigned char flags; // 15
			unsigned char boneCount[10]; // 16
			char u1; // unused?
			char u2; // unused?
			unsigned char notifyCount; // 29
			unsigned char assetType; // 30
			unsigned char ikType; // 31
			unsigned int randomDataByteCount; // 32
			unsigned int randomDataShortCount; // 36
			unsigned int randomDataIntCount; // 40
			unsigned int indexCount; // 44
			float framerate;  // 48
			float frequency; // 56
			scr_string_t* __ptr64 names; // 56
			char* __ptr64 dataByte; // 64
			short* __ptr64 dataShort; // 72
			int* __ptr64 dataInt; // 80
			short* __ptr64 randomDataShort; // 88
			unsigned char* __ptr64 randomDataByte; // 96
			int* __ptr64 randomDataInt; // 104
			XAnimIndices indices; // 112
			XAnimNotifyInfo* __ptr64 notify; // 120
			XAnimDeltaPart* __ptr64 deltaPart; // 128
			const char* __ptr64 secondaryName; // 136
			short u3; // unknown
			unsigned short blendShapeWeightCount; // 146
			short u4; // unused? padding?
			scr_string_t* __ptr64 blendShapeWeightNames; // 152
			char(*__ptr64 blendShapeWeightUnknown1)[3]; // 160
			unsigned short* __ptr64 blendShapeWeightUnknown2; // 168
			unsigned short* __ptr64 blendShapeWeightUnknown3; // 176
			unsigned short* __ptr64 blendShapeWeightUnknown4; // 184
			BlendShapeWeight* __ptr64 blendShapeWeights; // 192
			std::uint64_t u5; // unused?
			XAnimScriptedViewmodelAnimData* __ptr64 scriptedViewmodelAnimData; // 208 // count = 8
		}; static_assert(sizeof(XAnimParts) == 0xD8);

		union PackedUnitVec
		{
			unsigned int packed;
		};

		union PackedTexCoords
		{
			unsigned int packed;
		};

		union GfxColor
		{
			unsigned char array[4];
			unsigned int packed;
		};

		struct GfxPackedVertex
		{
			float xyz[3];
			float binormalSign;
			GfxColor color;
			PackedTexCoords texCoord;
			PackedUnitVec normal;
			PackedUnitVec tangent;
		};

		struct GfxPackedMotionVertex
		{
			float xyz[3];
			float binormalSignAndHeight;
			GfxColor pieceIndex;
			PackedTexCoords texCoord;
			PackedUnitVec normal;
			PackedUnitVec tangent;
		};

		union GfxVertexUnion0
		{
			GfxPackedVertex* __ptr64 packedVerts0;
			GfxPackedMotionVertex* __ptr64 packedMotionVerts0;
			void* __ptr64 verts0;
		};

		struct Face
		{
			unsigned short v1;
			unsigned short v2;
			unsigned short v3;
		};

		struct XSurfaceCollisionAabb
		{
			unsigned short mins[3];
			unsigned short maxs[3];
		};

		struct XSurfaceCollisionNode
		{
			XSurfaceCollisionAabb aabb;
			unsigned short childBeginIndex;
			unsigned short childCount;
		};

		struct XSurfaceCollisionLeaf
		{
			unsigned short triangleBeginIndex;
		};

		struct XSurfaceCollisionTree
		{
			float trans[3];
			float scale[3];
			unsigned int nodeCount;
			XSurfaceCollisionNode* __ptr64 nodes;
			unsigned int leafCount;
			XSurfaceCollisionLeaf* __ptr64 leafs;
		};

		struct XRigidVertList
		{
			unsigned short boneOffset;
			unsigned short vertCount;
			unsigned short triOffset;
			unsigned short triCount;
			XSurfaceCollisionTree* __ptr64 collisionTree;
		};

		struct UnknownXSurface0
		{
			float xyz[3];
			PackedUnitVec normal;
		};

		struct BlendVertsUnknown
		{
			unsigned short b[15];
			unsigned short blendVertCountIndex; // 30
		}; static_assert(sizeof(BlendVertsUnknown) == 32);

		struct XSubdivRigidVertList
		{
			unsigned int firstFace;
			unsigned int faceCount;
			unsigned int firstRegularPatch;
			unsigned int regularPatchCount;
		};

		struct XSurfaceSubdivLevel
		{
			XSubdivRigidVertList* __ptr64 rigidVertLists;
			unsigned int faceCount;
			unsigned int regularPatchCount;
			unsigned int regularPatchOffset;
			unsigned int facePointCount;
			unsigned int facePointValence4Count;
			unsigned int facePointBufferSize;
			unsigned int edgePointCount;
			unsigned int edgePointSmoothEnd;
			unsigned int edgePointUVBorderEnd;
			unsigned int vertexPointCount;
			unsigned int vertexPointValence4Count;
			unsigned int vertexPointBufferSize;
			unsigned int normalCount;
			unsigned int normalBufferSize;
			unsigned int transitionPointCount;
			unsigned int vertCount;
			unsigned int vertOffset;
			unsigned short* __ptr64 faceIndices;
			unsigned short* __ptr64 regularPatchIndices;
			unsigned int* __ptr64 regularPatchFlags;
			unsigned int* __ptr64 facePoints;
			unsigned int* __ptr64 edgePoints;
			unsigned int* __ptr64 vertexPoints;
			unsigned int* __ptr64 normals;
			unsigned int* __ptr64 transitionPoints;
			float* __ptr64 regularPatchCones;
			ID3D11Buffer* __ptr64 regularPatchIndexBuffer;
			ID3D11Buffer* __ptr64 faceIndexBuffer;
			ID3D11ShaderResourceView* __ptr64 regularPatchIndexBufferView;
			ID3D11ShaderResourceView* __ptr64 regularPatchFlagsView;
			ID3D11ShaderResourceView* __ptr64 facePointsView;
			ID3D11ShaderResourceView* __ptr64 edgePointsView;
			ID3D11ShaderResourceView* __ptr64 vertexPointsView;
			ID3D11ShaderResourceView* __ptr64 normalsView;
			ID3D11ShaderResourceView* __ptr64 transitionPointsView;
			ID3D11ShaderResourceView* __ptr64 regularPatchConesView;
		}; static_assert(sizeof(XSurfaceSubdivLevel) == 0xE8);

		struct GfxSubdivCache
		{
			unsigned int size;
			ID3D11Buffer* __ptr64 subdivCacheBuffer;
			ID3D11ShaderResourceView* __ptr64 subdivCacheView;
		}; static_assert(sizeof(GfxSubdivCache) == 0x18);

		struct XSurfaceSubdivInfo
		{
			XSurfaceSubdivLevel* __ptr64 levels;
			char __pad0[24];
			GfxSubdivCache cache;
		}; static_assert(sizeof(XSurfaceSubdivInfo) == 0x38);

		struct BlendShapeVert
		{
			char __pad0[32];
		};

		struct BlendShape
		{
			unsigned int vertCount;
			BlendShapeVert* __ptr64 verts;
			ID3D11Buffer* __ptr64 blendShapeVertsBuffer;
			ID3D11ShaderResourceView* __ptr64 blendShapeVertsView;
		};

		typedef char alignCompBufByte_t;
		typedef unsigned short alignVertBufFloat16Vec2_t[2];
		typedef unsigned short alignCompBufUShort_t;
		typedef float alignCompBufFloat_t;
		typedef unsigned short XBlendInfo;

		enum XSurfaceFlags : std::uint16_t
		{
			SURF_FLAG_VERTCOL_GREY = 0x1,
			SURF_FLAG_VERTCOL_NONE = 0x2,
			SURF_FLAG_SKINNED = 0x4,
			SURF_FLAG_REACTIVE_MOTION = 0x8,
			SURF_FLAG_LIGHTMAP_COORDS = 0x10,
			SURF_FLAG_TENSION = 0x20,
		};

		struct XSurface
		{
			unsigned short flags;
			unsigned short vertCount;
			unsigned short triCount;
			unsigned char rigidVertListCount;
			unsigned char subdivLevelCount;
			short blendVertCounts[8];
			GfxVertexUnion0 verts0;
			Face* __ptr64 triIndices;
			Face* __ptr64 triIndices2;
			ID3D11Buffer* __ptr64 vb0;
			ID3D11ShaderResourceView* __ptr64 vb0View;
			ID3D11Buffer* __ptr64 indexBuffer;
			XRigidVertList* __ptr64 rigidVertLists;
			UnknownXSurface0* __ptr64 unknown0;
			XBlendInfo* __ptr64 blendVerts;
			BlendVertsUnknown* __ptr64 blendVertsTable;
			ID3D11Buffer* __ptr64 blendVertsBuffer;
			ID3D11ShaderResourceView* __ptr64 blendVertsView;
			alignVertBufFloat16Vec2_t* __ptr64 lmapUnwrap;
			ID3D11Buffer* __ptr64 vblmapBuffer;
			ID3D11ShaderResourceView* __ptr64 vblmapView;
			XSurfaceSubdivInfo* __ptr64 subdiv;
			alignCompBufFloat_t* __ptr64 tensionData;
			alignCompBufUShort_t* __ptr64 tensionAccumTable;
			ID3D11Buffer* __ptr64 tensionAccumTableBuffer;
			ID3D11ShaderResourceView* __ptr64 tensionAccumTableView;
			ID3D11Buffer* __ptr64 tensionDataBuffer;
			ID3D11ShaderResourceView* __ptr64 tensionDataView;
			ID3D11ShaderResourceView* __ptr64 indexBufferView;
			BlendShape* __ptr64 blendShapes;
			unsigned int blendShapesCount;
			unsigned int vertexLightingIndex;
			char __pad0[4];
			int partBits[8];
			char __pad1[4];
		}; static_assert(sizeof(XSurface) == 0x108);

		struct XModelSurfs
		{
			const char* __ptr64 name;
			XSurface* __ptr64 surfs;
			unsigned short numsurfs;
			int partBits[8];
		}; static_assert(sizeof(XModelSurfs) == 0x38);

		struct ReactiveMotionModelPart
		{
			char __pad0[32];
		}; static_assert(sizeof(ReactiveMotionModelPart) == 32);

		struct XModelLodInfo
		{
			float dist; // 0
			unsigned short numsurfs; // 4
			unsigned short surfIndex; // 6
			XModelSurfs* __ptr64 modelSurfs; // 8
			int partBits[8]; // 16 20 24 28 32 36 40 44
			XSurface* __ptr64 surfs; // 48
			ReactiveMotionModelPart* __ptr64 reactiveMotionParts; // 56 (sizeof struct = 32) (reactiveMotionParts?)
			char __pad0[5]; // 64 (something must be here)
			char numReactiveMotionParts; // 69 (numReactiveMotionParts?)
			char __pad1[2]; // 70 (padding?)
		}; static_assert(sizeof(XModelLodInfo) == 72);

		struct XModelAngle
		{
			short x;
			short y;
			short z;
			short base;
		};

		struct XModelTagPos
		{
			float x;
			float y;
			float z;
		};

		struct DObjAnimMat
		{
			float quat[4];
			float trans[3];
			float transWeight;
		};

		struct ReactiveMotionModelTweaks
		{
			float scale[4];
		};

		struct XModelCollSurf_s
		{
			Bounds bounds;
			int boneIdx;
			int contents;
			int surfFlags;
		};

		struct XBoneInfo
		{
			Bounds bounds;
			union
			{
				float radiusSquared;
				unsigned int radiusSquaredAsInt;
			};
		};

		struct BlendShapeWeightMap
		{
			unsigned short weightIndex;
			unsigned short targetIndex;
			float fullWeight;
		};

		struct ExtentBounds
		{
			vec3_t mins;
			vec3_t maxs;
		};

		struct MdaoVolume
		{
			ExtentBounds bounds;
			unsigned __int16 cellCount[3];
			unsigned __int16 parentBoneIndex;
			GfxImage* __ptr64 volumeData;
		}; static_assert(sizeof(MdaoVolume) == 0x28);

		struct XPhysBoneInfo
		{
			PhysPreset* __ptr64 physPreset;
			PhysConstraint* __ptr64 physContraint;
			PhysCollmap* __ptr64 physCollmap;
			char __pad0[8];
		}; static_assert(sizeof(XPhysBoneInfo) == 0x20);

		enum XModelFlags : std::uint16_t
		{
			XMODEL_FLAG_COMPOSITE = 0x400,
		};

		struct XModel
		{
			const char* __ptr64 name; // 0
			unsigned char numBones; // 8
			unsigned char numRootBones; // 9
			unsigned char numsurfs; // 10
			unsigned char lodRampType; // 11
			unsigned char numBonePhysics; // 12
			unsigned char numCompositeModels; // 13
			char __pad0[2]; // 14-16
			float scale; // 16
			unsigned int noScalePartBits[8]; // 20
			scr_string_t* __ptr64 boneNames; // 56
			unsigned char* __ptr64 parentList; // 64
			XModelAngle* __ptr64 tagAngles; // 72
			XModelTagPos* __ptr64 tagPositions; // 80
			unsigned char* __ptr64 partClassification; // 88
			DObjAnimMat* __ptr64 baseMat; // 96
			ReactiveMotionModelTweaks* __ptr64 reactiveMotionTweaks; // 104
			Material* __ptr64* __ptr64 materialHandles; // 112
			XModelLodInfo lodInfo[6]; // 120
			char numLods; // 552
			char collLod; // 553
			char __pad1[2]; // 554-556
			short flags; // 556
			short numCollSurfs; // 558
			XModelCollSurf_s* __ptr64 collSurfs; // 560
			XBoneInfo* __ptr64 boneInfo; // 568
			int contents;
			float radius;
			Bounds bounds;
			unsigned short* __ptr64 invHighMipRadius; // 608
			MdaoVolume* __ptr64 mdaoVolumes; // 616
			unsigned short mdaoVolumeCount; // 624
			unsigned short targetCount; // 626
			unsigned short numberOfWeights; // 628
			unsigned short numberOfWeightMaps; // 630
			scr_string_t* __ptr64 weightNames; // 632
			BlendShapeWeightMap* __ptr64 blendShapeWeightMap; // 640
			PhysPreset* __ptr64 physPreset; // 648
			PhysCollmap* __ptr64 physCollmap; // 656
			float quantization;
			int memUsage;
			SkeletonScript* __ptr64 skeletonScript; // 672
			XModel* __ptr64* __ptr64 compositeModels; // 680
			XPhysBoneInfo* __ptr64 bonePhysics; // 688
		};  static_assert(sizeof(XModel) == 0x2B8);

		enum activeReticleType_t : std::int32_t
		{
			VEH_ACTIVE_RETICLE_NONE = 0x0,
			VEH_ACTIVE_RETICLE_PIP_ON_A_STICK = 0x1,
			VEH_ACTIVE_RETICLE_BOUNCING_DIAMOND = 0x2,
			VEH_ACTIVE_RETICLE_COUNT = 0x3,
		};

		enum playerAnimType_t : std::uint8_t
		{
			PLAYERANIMTYPE_NONE = 0x0,
			PLAYERANIMTYPE_OTHER = 0x1,
			PLAYERANIMTYPE_PISTOL = 0x2,
			PLAYERANIMTYPE_SMG = 0x3,
			PLAYERANIMTYPE_AUTORIFLE = 0x4,
			PLAYERANIMTYPE_SNIPER = 0x5,
			PLAYERANIMTYPE_ROCKET_LAUNCHER = 0x6,
			PLAYERANIMTYPE_GRENADE = 0x7,
			PLAYERANIMTYPE_M203 = 0x8,
			PLAYERANIMTYPE_HOLD = 0x9,
			PLAYERANIMTYPE_BRIEFCASE = 0xA,
			PLAYERANIMTYPE_RIOTSHIELD = 0xB,
			PLAYERANIMTYPE_LAPTOP = 0xC,
			PLAYERANIMTYPE_THROWINGKNIFE = 0xD,
			PLAYERANIMTYPE_MINIGUN = 0xE,
			PLAYERANIMTYPE_SMG_BULLPUP = 0x1F,
			PLAYERANIMTYPE_AUTOFILE_BULLPUP = 0x10,
			PLAYERANIMTYPE_SNIPER_BULLPUP = 0x11,
			PLAYERANIMTYPE_KILLSTREAKTRIGGER = 0x12,
			PLAYERANIMTYPE_TROPHYSYSTEM = 0x13,
			PLAYERANIMTYPE_COMBATKNIFE = 0x14,
			PLAYERANIMTYPE_NUM = 0x15,
		};

		enum weapType_t : std::int32_t
		{
			WEAPCLASS_NONE = 0x0,
			WEAPCLASS_BULLET = 0x1,
			WEAPCLASS_GRENADE = 0x2,
			WEAPCLASS_PROJECTILE = 0x3,
			WEAPCLASS_RIOTSHIELD = 0x4,
			WEAPCLASS_ENERGY = 0x5,
			WEAPCLASS_NUM = 0x6,
		};

		enum weapClass_t : std::int32_t
		{
			WEAPTYPE_RIFLE = 0x1,
			WEAPTYPE_SNIPER = 0x2,
			WEAPTYPE_MG = 0x3,
			WEAPTYPE_SMG = 0x4,
			WEAPTYPE_SPREAD = 0x5,
			WEAPTYPE_PISTOL = 0x6,
			WEAPTYPE_ROCKETLAUNCHER = 0x7,
			WEAPTYPE_TURRET = 0x8,
			WEAPTYPE_THROWINGKNIFE = 0x9,
			WEAPTYPE_NON_PLAYER = 0xA,
			WEAPTYPE_ITEM = 0xB,
			WEAPTYPE_CONE = 0xC,
			WEAPTYPE_BEAM = 0xD,
			WEAPTYPE_SHIELD = 0xE,
			WEAPTYPE_HOVER = 0xF,
			WEAPTYPE_CLOAK = 0x10,
			WEAPTYPE_PING = 0x11,
			WEAPTYPE_REPULSOR = 0x12,
			WEAPTYPE_ADRENALINE = 0x13,
			WEAPTYPE_HEALTH = 0x14,
			WEAPTYPE_MUTE = 0x15,
			WEAPTYPE_UNDERWATER = 0x16,
			WEAPTYPE_BALL = 0x17,
			WEAPTYPE_NUM = 0x18,
		};

		enum weapInventoryType_t : std::int32_t
		{
			WEAPINVENTORY_PRIMARY = 0x0,
			WEAPINVENTORY_OFFHAND = 0x1,
			WEAPINVENTORY_ITEM = 0x2,
			WEAPINVENTORY_ALTMODE = 0x3,
			WEAPINVENTORY_EXCLUSIVE = 0x4,
			WEAPINVENTORY_SCAVENGER = 0x5,
			WEAPINVENTORYCOUNT = 0x6,
		};

		enum weapFireType_t : std::int32_t
		{
			WEAPON_FIRETYPE_FULLAUTO = 0x0,
			WEAPON_FIRETYPE_SINGLESHOT = 0x1,
			WEAPON_FIRETYPE_BURSTFIRE2 = 0x2,
			WEAPON_FIRETYPE_BURSTFIRE3 = 0x3,
			WEAPON_FIRETYPE_BURSTFIRE4 = 0x4,
			WEAPON_FIRETYPE_DOUBLEBARREL = 0x5,
			WEAPON_FIRETYPECOUNT = 0x6,
			WEAPON_FIRETYPE_BURSTFIRE_FIRST = 0x2,
			WEAPON_FIRETYPE_BURSTFIRE_LAST = 0x4,
		};

		enum PenetrateType : std::uint32_t
		{
			PENETRATE_TYPE_NONE = 0x0,
			PENETRATE_TYPE_SMALL = 0x1,
			PENETRATE_TYPE_MEDIUM = 0x2,
			PENETRATE_TYPE_LARGE = 0x3,
			PENETRATE_TYPE_COUNT = 0x4,
		};

		enum ImpactType : std::int32_t
		{

		};

		enum weapStance_t : std::int32_t
		{
			WEAPSTANCE_STAND = 0x0,
			WEAPSTANCE_DUCK = 0x1,
			WEAPSTANCE_PRONE = 0x2,
			WEAPSTANCE_NUM = 0x3,
		};

		enum OffhandClass : std::uint32_t
		{
			OFFHAND_CLASS_NONE = 0x0,
			OFFHAND_CLASS_FRAG_GRENADE = 0x1,
			OFFHAND_CLASS_SMOKE_GRENADE = 0x2,
			OFFHAND_CLASS_FLASH_GRENADE = 0x3,
			OFFHAND_CLASS_OTHER = 0x9,
			OFFHAND_CLASS_COUNT = 0xA,
		};

		enum weapProjExposion_t : std::int32_t
		{
			WEAPPROJEXP_GRENADE = 0x0,
			WEAPPROJEXP_ROCKET = 0x1,
			WEAPPROJEXP_FLASHBANG = 0x2,
			WEAPPROJEXP_NONE = 0x3,
			WEAPPROJEXP_DUD = 0x4,
			WEAPPROJEXP_SMOKE = 0x5,
			WEAPPROJEXP_HEAVY = 0x6,
			WEAPPROJEXP_NUM = 0x7,
		};

		enum weapAdsFireMode_t : std::int32_t
		{
			WEAPADSFIREMODE_NUM = 0x3,
		};

		enum weapGreebleType_t : std::int32_t
		{
			WEAPGREEBLE_NONE = 0x0,
			WEAPGREEBLE_ACCURACYLEVEL1 = 0x1,
			WEAPGREEBLE_ACCURACYLEVEL2 = 0x2,
			WEAPGREEBLE_FIRERATELEVEL1 = 0x3,
			WEAPGREEBLE_FIRERATELEVEL2 = 0x4,
			WEAPGREEBLE_NUM = 0x5,
		};

		enum weapAutoReloadType_t : std::int32_t
		{

		};

		enum weapFireBarrels_t : std::int32_t
		{

		};

		enum weapFireTimeInterpolation_t : std::int32_t
		{

		};

		enum WeaponSlotRestriction : std::int32_t
		{
			SLOT_RESTRICTION_NONE = 0x0,
			SLOT_RESTRICTION_OPEN = 0x1,
			SLOT_RESTRICTION_PRESET = 0x2,
			SLOT_RESTRICTION_COUNT = 0x3,
		};

		enum AttachmentType : std::int32_t
		{
			ATTACHMENT_SCOPE = 0x0,
			ATTACHMENT_UNDERBARREL = 0x1,
			ATTACHMENT_OTHER = 0x2,
			ATTACHMENT_COUNT = 0x3,
		};

		struct AttChargeInfo
		{
			char __pad0[28];
		}; static_assert(sizeof(AttChargeInfo) == 28);

		struct AttHybridSettings
		{
			char __pad0[72];
		}; static_assert(sizeof(AttHybridSettings) == 72);

		union WAFieldParm
		{
			char p_char;
			bool p_bool;
			int p_int;
			float p_float;
			const char* __ptr64 string;
		};

		enum WAFieldType : std::uint8_t
		{
			WAFIELD_TYPE_STRING = 0,
			WAFIELD_TYPE_INT = 4,
			WAFIELD_TYPE_BOOL = 6,
			WAFIELD_TYPE_FLOAT = 7,
			WAFIELD_TYPE_FLOAT32 = 9,
			WAFIELD_TYPE_FX = 10,
			WAFIELD_TYPE_MODEL = 11,
			WAFIELD_TYPE_ANIM = 12,
			WAFIELD_TYPE_MATERIAL = 13,
			WAFIELD_TYPE_SOUND = 15,
			WAFIELD_TYPE_TRACER = 16,
		};

		enum WAFieldCode : std::uint8_t
		{
			FIELD_OP_STRING_SET = 0,
			FIELD_OP_STRING_REPLACE = 1,
			FIELD_OP_STRING_APPEND = 2,
			FIELD_OP_NUMBER_BEGIN = 3,
			FIELD_OP_NUMBER_SET = 3,
			FIELD_OP_NUMBER_END = 6,
			FIELD_OP_COUNT = 7,
		};

		struct WAField
		{
			unsigned char index;
			unsigned char fieldType; //WAFieldType fieldType;
			unsigned char code; // WAFieldCode code;
			WAFieldParm parm;
		}; static_assert(sizeof(WAField) == 16);

		struct WeaponAttachment
		{
			union
			{
				const char* __ptr64 szInternalName;
				const char* __ptr64 name;
			};
			const char* __ptr64 szDisplayName; // 8
			AttachmentType type; // 16
			weapType_t weaponType; // 20
			weapClass_t weapClass; // 24
			XModel* __ptr64* __ptr64 worldModels; // 32 (2 xmodels)
			XModel* __ptr64* __ptr64 viewModels; // 40 (2 xmodels)
			XModel* __ptr64* __ptr64 reticleViewModels; // 48 (64 xmodels)
			snd_alias_list_t* __ptr64* __ptr64 bounceSounds; // 56 (53 sounds)
			snd_alias_list_t* __ptr64* __ptr64 rollingSounds; // 64 (53 sounds)
			AttChargeInfo* __ptr64 chargeInfo; // 72
			AttHybridSettings* __ptr64 hybridSettings; // 80
			scr_string_t* __ptr64 stringArray1; // 88 (4 strings) (hideTags?)
			scr_string_t* __ptr64 stringArray2; // 96 (4 strings) (showTags?)
			unsigned short* __ptr64 waFieldOffsets; // 104
			WAField* __ptr64 waFields; // 112
			unsigned int waFieldsCount; // 120 (MAX_ATTACH_FIELDS_PER_WEAPON = 256)
			char __pad0[14];
			bool riotShield; // 138
			char __pad1[5];
			// size: 144
		}; static_assert(sizeof(WeaponAttachment) == 0x90);
		static_assert(offsetof(WeaponAttachment, riotShield) == 138);

		struct AnimOverrideEntry
		{
			unsigned short attachment1;
			unsigned short attachment2;
			XAnimParts* __ptr64 overrideAnim;
			XAnimParts* __ptr64 altmodeAnim;
			//unsigned int animTreeType;
			int animTime;
			int altTime;
		}; static_assert(sizeof(AnimOverrideEntry) == 32);

		struct SoundOverrideEntry
		{
			unsigned short attachment1;
			unsigned short attachment2;
			snd_alias_list_t* __ptr64 overrideSound;
			snd_alias_list_t* __ptr64 altmodeSound;
			//unsigned int soundType;
		}; static_assert(sizeof(SoundOverrideEntry) == 24);

		struct FXOverrideEntry
		{
			unsigned short attachment1;
			unsigned short attachment2;
			FxEffectDef* __ptr64 overrideFX;
			FxEffectDef* __ptr64 altmodeFX;
			//unsigned int fxType;
		}; static_assert(sizeof(FXOverrideEntry) == 24);

		struct ReloadStateTimerEntry
		{
			int attachment;
			int reloadAddTime;
			int reloadEmptyAddTime;
			int reloadStartAddTime;
		}; static_assert(sizeof(ReloadStateTimerEntry) == 16);

		struct NoteTrackToSoundEntry
		{
			int attachment;
			scr_string_t* __ptr64 notetrackSoundMapKeys;
			scr_string_t* __ptr64 notetrackSoundMapValues;
		}; static_assert(sizeof(NoteTrackToSoundEntry) == 24);

		struct TracerDef
		{
			const char* __ptr64 name;
			Material* __ptr64 material;
			FxEffectDef* __ptr64 effect;
			unsigned int drawInterval;
			float speed;
			float beamLength;
			float beamWidth;
			float screwRadius;
			float screwDist;
			float colors[5][4];
		}; static_assert(sizeof(TracerDef) == 0x80);

		struct LaserDef
		{
			const char* __ptr64 name;
			Material* __ptr64 laserMaterial;
			Material* __ptr64 laserLightMaterial;
			FxEffectDef* __ptr64 effect;
			LaserDef* __ptr64 altLaser;
			scr_string_t* __ptr64 value;
			char __pad0[104];
		}; static_assert(sizeof(LaserDef) == 0x98);

		struct TurretHydraulicSettings
		{
			float minVelocity;
			float maxVelocity; // unused or padding
			snd_alias_list_t* __ptr64 verticalSound;
			snd_alias_list_t* __ptr64 verticalStopSound;
			snd_alias_list_t* __ptr64 horizontalSound;
			snd_alias_list_t* __ptr64 horizontalStopSound;
		}; static_assert(sizeof(TurretHydraulicSettings) == 40);

		enum weapOverlayReticle_t : std::int32_t
		{
			WEAPOVERLAYRETICLE_NONE = 0x0,
			WEAPOVERLAYRETICLE_CROSSHAIR = 0x1,
			WEAPOVERLAYRETICLE_NUM = 0x2,
		};

		struct ADSOverlay
		{
			Material* __ptr64 shader;
			Material* __ptr64 shaderLowRes;
			Material* __ptr64 shaderEMP;
			Material* __ptr64 shaderEMPLowRes;
			weapOverlayReticle_t reticle;
			float xU_01;
			float xU_02;
			float width;
			float height;
			float widthSplitscreen;
			float heightSplitscreen;
		}; static_assert(sizeof(ADSOverlay) == 0x40);

		enum weaponIconRatioType_t : std::int32_t
		{
			WEAPON_ICON_RATIO_1TO1 = 0x0,
			WEAPON_ICON_RATIO_2TO1 = 0x1,
			WEAPON_ICON_RATIO_4TO1 = 0x2,
			WEAPON_ICON_RATIO_COUNT = 0x3,
		};

		enum WeapStickinessType : std::int32_t
		{
			WEAPSTICKINESS_NONE = 0x0,
			WEAPSTICKINESS_ALL = 0x1,
			WEAPSTICKINESS_ALL_ORIENT = 0x2,
			WEAPSTICKINESS_GROUND = 0x3,
			WEAPSTICKINESS_GROUND_WITH_YAW = 0x4,
			WEAPSTICKINESS_KNIFE = 0x5,
			WEAPSTICKINESS_COUNT = 0x6,
		};

		enum guidedMissileType_t : std::int32_t
		{
			MISSILE_GUIDANCE_NONE = 0x0,
			MISSILE_GUIDANCE_SIDEWINDER = 0x1,
			MISSILE_GUIDANCE_HELLFIRE = 0x2,
			MISSILE_GUIDANCE_JAVELIN = 0x3,
			MISSILE_GUIDANCE_UNKNOWN0 = 0x4,
			MISSILE_GUIDANCE_UNKNOWN1 = 0x5,
			MISSILE_GUIDANCE_UNKNOWN2 = 0x6,
			MISSILE_GUIDANCE_COUNT = 0x7,
		};

		enum WeapOverlayInteface_t : std::int32_t
		{
			WEAPOVERLAYINTERFACE_NONE = 0x0,
			WEAPOVERLAYINTERFACE_JAVELIN = 0x1,
			WEAPOVERLAYINTERFACE_TURRETSCOPE = 0x2,
			WEAPOVERLAYINTERFACECOUNT = 0x3,
		};

		enum weapAnimFiles_t : std::int32_t
		{
			WEAP_ANIM_INVALID = -1,
			NUM_WEAP_ANIMS = 202,
		};

		struct StateTimers
		{
			int fireDelay; // 1640 * __ptr64 x
			int meleeDelay; // 1644 * __ptr64 x
			int meleeChargeDelay; // 1648 * __ptr64 x
			int detonateDelay; // 1652 * __ptr64 x
			int fireTime; // 1656 * __ptr64 x
			int rechamberTime; // 1660 * __ptr64 x
			int rechamberTimeOneHanded; // 1664 * __ptr64 x
			int rechamberBoltTime; // 1668 * __ptr64 x
			int holdFireTime; // 1672 * __ptr64 x
			int grenadePrimeReadyToThrowTime; // 1676 * __ptr64 x
			int detonateTime; // 1680 * __ptr64 x
			int meleeTime; // 1684 * __ptr64 x
			int meleeChargeTime; // 1688 * __ptr64 x
			int reloadTime; // 1692 * __ptr64 x
			int reloadShowRocketTime; // 1696 * __ptr64 x
			int reloadEmptyTime; // 1700 * __ptr64 x
			int reloadAddTime; // 1704 * __ptr64 x
			int reloadEmptyAddTime; // 1708 * __ptr64 x
			int reloadStartTime; // 1712 * __ptr64 x
			int reloadStartAddTime; // 1716 * __ptr64 x
			int reloadEndTime; // 1720 * __ptr64 x
			int reloadTimeDualWield; // 1724 * __ptr64 x
			int reloadAddTimeDualWield; // 1728 * __ptr64 x
			int reloadEmptyDualMag; // 1732 * __ptr64 x
			int reloadEmptyAddTimeDualMag; // 1736 * __ptr64 x
			int u25; // 1740 * __ptr64 x // (unused)
			int u26; // 1744 * __ptr64 x // (unused)
			int dropTime; // 1748 * __ptr64 x
			int raiseTime; // 1752 * __ptr64 x
			int altDropTime; // 1756 * __ptr64 x
			int altRaiseTime; // 1760 * __ptr64 x
			int quickDropTime; // 1764 * __ptr64 x
			int quickRaiseTime; // 1768 * __ptr64 x
			int firstRaiseTime; // 1772 * __ptr64 x
			int breachRaiseTime; // 1776 * __ptr64 x
			int emptyRaiseTime; // 1780 * __ptr64 x
			int emptyDropTime; // 1784 * __ptr64 x
			int sprintInTime; // 1788 * __ptr64 x
			int sprintLoopTime; // 1792 * __ptr64 x
			int sprintOutTime; // 1796 * __ptr64 x
			int stunnedTimeBegin; // 1800 * __ptr64 x
			int stunnedTimeLoop; // 1804 * __ptr64 x
			int stunnedTimeEnd; // 1808 * __ptr64 x
			int nightVisionWearTime; // 1812 * __ptr64 x
			int nightVisionWearTimeFadeOutEnd; // 1816 * __ptr64 x
			int nightVisionWearTimePowerUp; // 1820 * __ptr64 x
			int nightVisionRemoveTime; // 1824 * __ptr64 x
			int nightVisionRemoveTimePowerDown; // 1828 * __ptr64 x
			int nightVisionRemoveTimeFadeInStart; // 1832 * __ptr64 x
			int aiFuseTime; // 1836 * __ptr64 x
			int fuseTime; // 1840 * __ptr64 x
			int missileTime; // 1844 * __ptr64 x
			int primeTime; // 1848 * __ptr64 x
			bool bHoldFullPrime; // 1852 * __ptr64 x
			int blastFrontTime; // 1856 * __ptr64 x
			int blastRightTime; // 1860 * __ptr64 x
			int blastBackTime; // 1864 * __ptr64 x
			int blastLeftTime; // 1868 * __ptr64 x
			int u58; // 1872 * __ptr64 x (unused)
			int u59; // 1876 * __ptr64 x (unused)
			int u60; // 1880 * __ptr64 x (unused)
			int u61; // 1884 * __ptr64 x (unused)
			int u62; // 1888 * __ptr64 x (unused)
			int u63; // 1892 * __ptr64 x (unused)
			int u64; // 1896 * __ptr64 x (unused)
			int u65; // 1900 * __ptr64 x (unused)
			int u66; // 1904 * __ptr64 x (unused)
			int u67; // 1908 * __ptr64 x (unused)
			int u68; // 1912 * __ptr64 x (unused)
			int offhandSwitchTime; // 1916 * __ptr64 x
			int u70; // 1920 * __ptr64 x (unknown)
			int u71; // 1924 * __ptr64 x (unknown)
			int u72; // 1928 * __ptr64 x (unknown)
			int u73; // 1932 * __ptr64 x (unknown)
			int u74; // 1936 * __ptr64 x (unknown)
			int u75; // 1936 * __ptr64 x (unknown)
			int u76; // 1936 * __ptr64 x (unknown)
			int u77; // 1936 * __ptr64 x (unknown)
			int u78; // 1936 * __ptr64 x (unknown)
		}; static_assert(sizeof(StateTimers) == 316);

		struct WeaponDef
		{
			union
			{
				const char* __ptr64 szInternalName;
				const char* __ptr64 name;
			};
			const char* __ptr64 szDisplayName; // 8
			const char* __ptr64 szOverlayName; // 16
			const char* __ptr64 szAttachmentName;
			const char* __ptr64 szUnknownName;
			XModel* __ptr64* __ptr64 gunModel; // 24 (2 xmodels)
			XModel* __ptr64 handModel; // 32
			XModel* __ptr64 unknownModel; // 40
			XModel* __ptr64* __ptr64 reticleViewModels; // 48 (64 xmodels)
			const char* __ptr64 szModeName; // 56
			XAnimParts* __ptr64* __ptr64 szXAnimsRightHanded; // 64 (190 xanims)
			XAnimParts* __ptr64* __ptr64 szXAnimsLeftHanded; // 72 (190 xanims)
			scr_string_t* __ptr64 hideTags; // 80 (32 xstrings)
			WeaponAttachment* __ptr64* __ptr64 attachments; // 88 (weaponDef + 1332 attachments)
			XAnimParts* __ptr64* __ptr64 szXAnims; // 96 (190 xanims)
			AnimOverrideEntry* __ptr64 animOverrides; // 104 (weaponDef + 1333 overrides)
			SoundOverrideEntry* __ptr64 soundOverrides; // 112 (weaponDef + 1334 overrides)
			FXOverrideEntry* __ptr64 fxOverrides; // 120 (weaponDef + 1335 overrides)
			ReloadStateTimerEntry* __ptr64 reloadOverrides; // 128 (weaponDef + 1336 overrides)
			NoteTrackToSoundEntry* __ptr64 notetrackOverrides; // 136 (weaponDef + 1337 overrides)
			scr_string_t* __ptr64 notetrackSoundMapKeys; // 144 (36 xstrings)
			scr_string_t* __ptr64 notetrackSoundMapValues; // 152 (36 xstrings)
			scr_string_t* __ptr64 notetrackRumbleMapKeys; // 160 (16 xstrings)
			scr_string_t* __ptr64 notetrackRumbleMapValues; // 168 (16 xstrings)
			scr_string_t* __ptr64 notetrackFXMapKeys; // 176 (16 xstrings)
			FxEffectDef* __ptr64* __ptr64 notetrackFXMapValues; // 184 (16 effects)
			scr_string_t* __ptr64 notetrackFXMapTagValues; // 192 (16 xstrings)
			scr_string_t* __ptr64 notetrackUnknownKeys; // 200 (16 xstrings)
			char* __ptr64 notetrackUnknown; // 208 (16 chars)
			scr_string_t* __ptr64 notetrackUnknownValues; // 216 (16 xstrings)
			const char* __ptr64 szAltWeaponName; // 224
			FxEffectDef* __ptr64 viewFlashEffect; // 232
			FxEffectDef* __ptr64 viewBodyFlashEffect; // 240
			FxEffectDef* __ptr64 worldFlashEffect; // 248
			FxEffectDef* __ptr64 viewFlashADSEffect; // 256
			FxEffectDef* __ptr64 viewBodyFlashADSEffect; // 264
			FxEffectDef* __ptr64 effect06; // 272
			FxEffectDef* __ptr64 effect07; // 280
			FxEffectDef* __ptr64 effect08; // 288
			FxEffectDef* __ptr64 effect09; // 296
			FxEffectDef* __ptr64 effect10; // 304
			FxEffectDef* __ptr64 effect11; // 312
			FxEffectDef* __ptr64 effect12; // 320
			snd_alias_list_t* __ptr64 pickupSound; // 1
			snd_alias_list_t* __ptr64 pickupSoundPlayer; // 2
			snd_alias_list_t* __ptr64 ammoPickupSound; // 3
			snd_alias_list_t* __ptr64 ammoPickupSoundPlayer; // 4
			snd_alias_list_t* __ptr64 projectileSound; // 5
			snd_alias_list_t* __ptr64 pullbackSound; // 6
			snd_alias_list_t* __ptr64 pullbackSoundPlayer; // 7
			snd_alias_list_t* __ptr64 pullbackSoundQuick; // 8
			snd_alias_list_t* __ptr64 pullbackSoundQuickPlayer; // 9
			snd_alias_list_t* __ptr64 fireSound;  // 10
			snd_alias_list_t* __ptr64 fireSoundPlayer;  // 11
			snd_alias_list_t* __ptr64 fireSoundPlayerLeft;  // 12
			snd_alias_list_t* __ptr64 fireSoundPlayerRight;  // 13
			snd_alias_list_t* __ptr64 sound14;  // 14
			snd_alias_list_t* __ptr64 sound15;  // 15
			snd_alias_list_t* __ptr64 sound16;  // 16
			snd_alias_list_t* __ptr64 sound17;  // 17
			snd_alias_list_t* __ptr64 sound18;  // 18
			snd_alias_list_t* __ptr64 fireLoopSound;  // 19
			snd_alias_list_t* __ptr64 fireLoopSoundPlayer;  // 20
			snd_alias_list_t* __ptr64 sound21;  // 21
			snd_alias_list_t* __ptr64 sound22;  // 22
			snd_alias_list_t* __ptr64 sound23;  // 23
			snd_alias_list_t* __ptr64 sound24;  // 24
			snd_alias_list_t* __ptr64 sound25;  // 25
			snd_alias_list_t* __ptr64 sound26;  // 26
			snd_alias_list_t* __ptr64 fireStopSound;  // 27
			snd_alias_list_t* __ptr64 fireStopSoundPlayer;  // 28
			snd_alias_list_t* __ptr64 sound29;  // 29
			snd_alias_list_t* __ptr64 sound30;  // 30
			snd_alias_list_t* __ptr64 sound31;  // 31
			snd_alias_list_t* __ptr64 sound32;  // 32
			snd_alias_list_t* __ptr64 sound33;  // 33
			snd_alias_list_t* __ptr64 fireFirstSound;  // 34
			snd_alias_list_t* __ptr64 fireFirstSoundPlayer;  // 35
			snd_alias_list_t* __ptr64 fireSound2;  // 36
			snd_alias_list_t* __ptr64 fireSoundPlayer2;  // 37
			snd_alias_list_t* __ptr64 fireSpecialSound;  // 38
			snd_alias_list_t* __ptr64 fireSpecialSoundPlayer;  // 39
			snd_alias_list_t* __ptr64 emptyFireSound;  // 40
			snd_alias_list_t* __ptr64 emptyFireSoundPlayer;  // 41
			snd_alias_list_t* __ptr64 emptyFireSoundPlayerLeft;  // 42
			snd_alias_list_t* __ptr64 emptyFireSoundPlayerRight;  // 43
			snd_alias_list_t* __ptr64 emptyFireSoundReleasePlayer;  // 44
			snd_alias_list_t* __ptr64 emptyFireSoundReleasePlayerLeft;  // 45
			snd_alias_list_t* __ptr64 emptyFireSoundReleasePlayerRight;  // 46
			snd_alias_list_t* __ptr64 sound47;  // 47
			snd_alias_list_t* __ptr64 meleeSwipeSound;  // 48
			snd_alias_list_t* __ptr64 meleeSwipeSoundPlayer;  // 49
			snd_alias_list_t* __ptr64 meleeHitSound;  // 50
			snd_alias_list_t* __ptr64 meleeHitSoundPlayer;  // 51
			snd_alias_list_t* __ptr64 meleeMissSound;  // 52
			snd_alias_list_t* __ptr64 meleeMissSoundPlayer;  // 53
			snd_alias_list_t* __ptr64 sound54;  // 54
			snd_alias_list_t* __ptr64 sound55;  // 55
			snd_alias_list_t* __ptr64 sound56;  // 56
			snd_alias_list_t* __ptr64 sound57;  // 57
			snd_alias_list_t* __ptr64 sound58;  // 58
			snd_alias_list_t* __ptr64 sound59;  // 59
			snd_alias_list_t* __ptr64 sound60;  // 60
			snd_alias_list_t* __ptr64 sound61;  // 61
			snd_alias_list_t* __ptr64 sound62;  // 62
			snd_alias_list_t* __ptr64 sound63;  // 63
			snd_alias_list_t* __ptr64 sound64;  // 64
			snd_alias_list_t* __ptr64 sound65;  // 65
			snd_alias_list_t* __ptr64 nightVisionWearSound;  // 66
			snd_alias_list_t* __ptr64 nightVisionWearSoundPlayer;  // 67
			snd_alias_list_t* __ptr64 nightVisionRemoveSound;  // 68
			snd_alias_list_t* __ptr64 nightVisionRemoveSoundPlayer;  // 69
			snd_alias_list_t* __ptr64 raiseSound;  // 70
			snd_alias_list_t* __ptr64 raiseSoundPlayer;  // 71
			snd_alias_list_t* __ptr64 raiseSoundPlayerLeft;  // 72
			snd_alias_list_t* __ptr64 raiseSoundPlayerRight;  // 73
			snd_alias_list_t* __ptr64 sound74;  // 74
			snd_alias_list_t* __ptr64 quickRaiseSoundPlayer;  // 75
			snd_alias_list_t* __ptr64 quickRaiseSoundPlayerLeft;  // 76
			snd_alias_list_t* __ptr64 quickRaiseSoundPlayerRight;  // 77
			snd_alias_list_t* __ptr64 raiseSound2;  // 78
			snd_alias_list_t* __ptr64 sound79;  // 79
			snd_alias_list_t* __ptr64 sound80;  // 80
			snd_alias_list_t* __ptr64 sound81;  // 81
			snd_alias_list_t* __ptr64 putawaySound;  // 82
			snd_alias_list_t* __ptr64 putawaySoundPlayer;  // 83
			snd_alias_list_t* __ptr64 putawaySoundPlayerLeft;  // 84
			snd_alias_list_t* __ptr64 putawaySoundPlayerRight;  // 85
			snd_alias_list_t* __ptr64 sound86;  // 86
			snd_alias_list_t* __ptr64 sound87;  // 87
			snd_alias_list_t* __ptr64 adsEnterSoundPlayer;  // 88
			snd_alias_list_t* __ptr64 adsLeaveSoundPlayer;  // 89
			snd_alias_list_t* __ptr64 adsCrosshairEnemySound;  // 90
			snd_alias_list_t* __ptr64* __ptr64 bounceSound; // 920 (53 sounds)
			snd_alias_list_t* __ptr64* __ptr64 rollingSound; // 928 (53 sounds)
			FxEffectDef* __ptr64 viewShellEjectEffect; // 936
			FxEffectDef* __ptr64 worldShellEjectEffect; // 944
			FxEffectDef* __ptr64 viewLastShotEjectEffect; // 952
			FxEffectDef* __ptr64 worldLastShotEjectEffect; // 960
			FxEffectDef* __ptr64 viewMagEjectEffect; // 968
			Material* __ptr64 reticleCenter; // 976
			Material* __ptr64 reticleSide; // 984
			XModel* __ptr64* __ptr64 worldModel; // 992 (2 xmodels)
			XModel* __ptr64 worldClipModel; // 1000
			XModel* __ptr64 rocketModel; // 1008
			XModel* __ptr64 knifeModel; // 1016
			XModel* __ptr64 worldKnifeModel; // 1024
			Material* __ptr64 hudIcon; // 1032
			Material* __ptr64 pickupIcon; // 1040
			Material* __ptr64 unknownIcon2; // 1048
			Material* __ptr64 unknownIcon3; // 1056
			Material* __ptr64 unknownIcon4; // 1064
			Material* __ptr64 ammoCounterIcon; // 1072
			const char* __ptr64 szAmmoName; // 1080
			const char* __ptr64 szClipName; // 1088
			const char* __ptr64 szSharedAmmoCapName; // 1096
			PhysCollmap* __ptr64 physCollmap; // 1104
			PhysPreset* __ptr64 physPreset; // 1112
			const char* __ptr64 szUseHintString; // 1120
			const char* __ptr64 dropHintString; // 1128
			float* __ptr64 locationDamageMultipliers; // 1136 (22 floats)
			const char* __ptr64 fireRumble; // 1144
			const char* __ptr64 fireMedRumble; // 1152
			const char* __ptr64 fireHighRumble; // 1160
			const char* __ptr64 meleeImpactRumble; // 1168
			TracerDef* __ptr64 tracer1; // 1176
			TracerDef* __ptr64 tracer2; // 1184
			LaserDef* __ptr64 laser; // 1192
			snd_alias_list_t* __ptr64 turretOverheatSound; // 1200
			FxEffectDef* __ptr64 turretOverheatEffect; // 1208
			const char* __ptr64 turretBarrelSpinRumble; // 1216
			snd_alias_list_t* __ptr64 turretBarrelSpinMaxSnd; // 1224
			snd_alias_list_t* __ptr64 turretBarrelSpinUpSnd[4]; // 1232
			snd_alias_list_t* __ptr64 turretBarrelSpinDownSnd[4]; // 1264
			snd_alias_list_t* __ptr64 missileConeSoundAlias; // 1296
			snd_alias_list_t* __ptr64 missileConeSoundAliasAtBase; // 1304
			XModel* __ptr64 stowOffsetModel; // 1312
			TurretHydraulicSettings* __ptr64 turretHydraulicSettings; // 1320
			int altWeapon; // 1328
			unsigned char numWeaponAttachments; // 1332
			unsigned char numAnimOverrides; // 1333
			unsigned char numSoundOverrides; // 1334
			unsigned char numFXOverrides; // 1335
			unsigned char numReloadStateTimerOverrides; // 1336
			unsigned char numNotetrackOverrides; // 1337
			playerAnimType_t playerAnimType; // 1338
			char __pad000[1];
			weapType_t weapType; // 1340
			weapClass_t weapClass; // 1344
			PenetrateType penetrateType; // 1348
			float penetrateDepth; // 1352
			ImpactType impactType; // 1356
			weapInventoryType_t inventoryType; // 1360
			weapFireType_t fireType; // 1364
			weapFireBarrels_t fireBarrels; // 1368
			weapAdsFireMode_t adsFireMode; // 1372
			float burstFireCooldown; // 1376
			weapGreebleType_t greebleType; // 1380
			weapAutoReloadType_t autoReloadType; // 1384
			WeaponSlotRestriction slotRestriction; // 1388
			OffhandClass offhandClass; // 1392
			weapStance_t stance; // 1396
			int reticleCenterSize; // 1400
			int reticleSideSize; // 1404
			int reticleMinOfs; // 1408
			activeReticleType_t activeReticleType; // 1412
			float standMove[3]; // 1416 1420 1424
			float standRot[3]; // 1428 1432 1436
			float strafeMove[3]; // 1440 1444 1448
			float strafeRot[3]; // 1452 1456 1460
			float duckedOfs[3]; // 1464 1468 1472
			float duckedMove[3]; // 1476 1480 1484
			float duckedRot[3]; // 1488 1492 1496
			float proneOfs[3]; // 1500 1504 1508
			float proneMove[3]; // 1512 1516 1520
			float proneRot[3]; // 1524 1528 1532
			float unkVec1[3];
			float unkVec2[3];
			float posMoveRate; // 1536
			float posProneMoveRate; // 1540
			float standMoveMinSpeed; // 1544
			float duckedMoveMinSpeed; // 1548
			float proneMoveMinSpeed; // 1552
			float posRotRate; // 1556
			float posProneRotRate; // 1560
			weaponIconRatioType_t hudIconRatio; // 1564
			weaponIconRatioType_t pickupIconRatio; // 1568
			weaponIconRatioType_t ammoCounterIconRatio; // 1572
			int ammoCounterClip; // 1576
			int startAmmo; // 1580
			int ammoIndex; // 1752
			char ammoIndexUnknown; // 1588 (runtime variable)
			char __pad002[3]; // padding?
			int clipIndex; // 1592 (runtime variable)
			char clipIndexUnknown; // 1596 (runtime variable)
			char __pad003[3]; // padding?
			int maxAmmo; // 1600
			int minAmmoReq; // 1604
			int clipSize; // 1608
			int shotCount; // 1612
			int sharedAmmoCapIndex; // 1616
			int sharedAmmoCap; // 1620
			int damage; // 1624
			int playerDamage; // 1628
			int meleeDamage; // 1632
			int damageType; // 1636
			StateTimers stateTimers; // 1640
			StateTimers akimboStateTimers; // 1940
			float autoAimRange; // 2240
			float aimAssistRange; // 2244
			float aimAssistRangeAds; // 2248
			float aimPadding; // 2252
			float enemyCrosshairRange; // 2256 
			float moveSpeedScale; // 2260
			float adsMoveSpeedScale; // 2264
			float sprintDurationScale; // 2268
			float adsZoomFov; // 2272
			float adsZoomInFrac; // 2276
			float adsZoomOutFrac; // 2280
			float adsSceneBlur; // 2284 (1401FC630) : float
			float fU_007; // 2288 (1400CF870) : float (related to scene blur)
			float xU_008; // 2292 X
			ADSOverlay overlay; // 2296
			WeapOverlayInteface_t overlayInterface; // 2352
			float adsBobFactor; // 2356
			float adsViewBobMult; // 2360
			float hipSpreadStandMin; // 2364
			float hipSpreadDuckedMin; // 2368
			float hipSpreadProneMin; // 2372
			float hipSpreadStandMax; // 2376
			float xU_009; // 2380 X
			float xU_010; // 2384 X
			float hipSpreadDuckedMax; // 2388
			float hipSpreadProneMax; // 2392
			float hipSpreadDecayRate; // 2396
			float hipSpreadFireAdd; // 2400
			float hipSpreadTurnAdd; // 2404
			float hipSpreadMoveAdd; // 2408
			float hipSpreadDuckedDecay; // 2412
			float hipSpreadProneDecay; // 2416
			float hipReticleSidePos; // 2420
			float adsIdleAmount; // 2424
			float hipIdleAmount; // 2428
			float adsIdleSpeed; // 2432
			float hipIdleSpeed; // 2436f
			float idleCrouchFactor; // 2440
			float idleProneFactor; // 2444
			float gunMaxPitch; // 2448
			float gunMaxYaw; // 2452
			float adsIdleLerpStartTime; // 2456
			float adsIdleLerpTime; // 2460
			int adsTransInTime; // 2464
			int xU_011; // 2468 X
			int adsTransOutTime; // 2472
			float xU_012; // 2476 X
			float swayMaxAngle; // 2480
			float swayLerpSpeed; // 2484
			float swayPitchScale; // 2488
			float swayYawScale; // 2492
			float swayVertScale; // 2496
			float swayHorizScale; // 2500
			float swayShellShockScale; // 2504
			float adsSwayMaxAngle; // 2508
			float adsSwayLerpSpeed; // 2512
			float adsSwayPitchScale; // 2516
			float adsSwayYawScale; // 2520
			float adsSwayHorizScale; // 2524
			float adsSwayVertScale; // 2528
			float adsViewErrorMin; // 2532
			float adsViewErrorMax; // 2536
			float adsFireAnimFrac; // 2540
			float dualWieldViewModelOffset; // 2544
			float scopeDriftDelay; // 2548
			float scopeDriftLerpInTime; // 2552
			float scopeDriftSteadyTime; // 2556
			float scopeDriftLerpOutTime; // 2560
			float scopeDriftSteadyFactor; // 2564
			float scopeDriftUnsteadyFactor; // 2568
			float bobVerticalFactor; // 2572
			float bobHorizontalFactor; // 2576
			float bobViewVerticalFactor; // 2580
			float bobViewHorizontalFactor; // 2584
			float stationaryZoomFov; // 2588
			float stationaryZoomDelay; // 2592
			float stationaryZoomLerpInTime; // 2596
			float stationaryZoomLerpOutTime; // 2600
			float adsDofStart; // 2604
			float adsDofEnd; // 2608
			float xU_020; // 2612 X
			Material* __ptr64 killIcon; // 2616
			Material* __ptr64 dpadIcon; // 2624
			Material* __ptr64 hudProximityWarningIcon; // 2632
			weaponIconRatioType_t killIconRatio; // 2640
			weaponIconRatioType_t dpadIconRatio; // 2644
			int fireAnimLength; // 2648
			int fireAnimLengthAkimbo; // 2652
			int inspectAnimTime; // 2656
			int reloadAmmoAdd; // 2660
			int reloadStartAdd; // 2664
			int ammoDropStockMin; // 2668
			int ammoDropStockMax; // 2672
			int ammoDropClipPercentMin; // 2676
			int ammoDropClipPercentMax; // 2680
			int explosionRadius; // 2684
			int explosionRadiusMin; // 2688
			int explosionInnerDamage; // 2692
			int explosionOuterDamage; // 2696
			float damageConeAngle; // 2700
			float bulletExplDmgMult; // 2704
			float bulletExplRadiusMult; // 2708
			int projectileSpeed; // 2712
			int projectileSpeedUp; // 2716
			int projectileSpeedForward; // 2720
			int projectileActivateDist; // 2724
			float projLifetime; // 2728
			float timeToAccelerate; // 2732
			float projectileCurvature; // 2736
			float xU_021; // 2740 X
			const char* __ptr64 projectileName; // 2744
			XModel* __ptr64 projectileModel; // 2752
			FxEffectDef* __ptr64 projExplosionEffect; // 2760
			FxEffectDef* __ptr64 projDudEffect; // 2768
			snd_alias_list_t* __ptr64 projExplosionSound; // 2776
			snd_alias_list_t* __ptr64 projDudSound; // 2784
			weapProjExposion_t projExplosion; // 2792
			WeapStickinessType stickiness; // 2796
			float lowAmmoWarningThreshold; // 2800
			float ricochetChance; // 2804
			int riotShieldHealth; // 2808
			float riotShieldDamageMult; // 2812
			float* __ptr64 parallelBounce; // 2816 (53 floats)
			float* __ptr64 perpendicularBounce; // 2824 (53 floats)
			FxEffectDef* __ptr64 projTrailEffect; // 2832
			FxEffectDef* __ptr64 projBeaconEffect; // 2840
			float projectileColor[3]; // 2848 2852 2856
			guidedMissileType_t guidedMissileType; // 2860
			float maxSteeringAccel; // 2864
			int projIgnitionDelay; // 2868
			FxEffectDef* __ptr64 projIgnitionEffect; // 2872
			snd_alias_list_t* __ptr64 projIgnitionSound; // 2880
			float adsAimPitch; // 2888
			float adsCrosshairInFrac; // 2892
			float adsCrosshairOutFrac; // 2896
			int adsGunKickReducedKickBullets; // 2900
			float adsGunKickReducedKickPercent; // 2904
			float adsGunKickPitchMin; // 2908
			float adsGunKickPitchMax; // 2912
			float adsGunKickYawMin; // 2916
			float adsGunKickYawMax; // 2920
			float adsGunKickMagMin; // 2924
			float adsGunKickAccel; // 2928
			float adsGunKickSpeedMax; // 2932
			float adsGunKickSpeedDecay; // 2936
			float adsGunKickStaticDecay; // 2940
			float adsViewKickPitchMin; // 2944
			float adsViewKickPitchMax; // 2948
			float adsViewKickYawMin; // 2952
			float adsViewKickYawMax; // 2956
			float adsViewKickMagMin; // 2960
			float adsViewKickCenterSpeed; // 2964
			float adsViewScatterMin; // 2968 X
			float adsViewScatterMax; // 2972 X
			float adsSpread; // 2976
			int hipGunKickReducedKickBullets; // 2980
			float hipGunKickReducedKickPercent; // 2984
			float hipGunKickPitchMin; // 2988
			float hipGunKickPitchMax; // 2992
			float hipGunKickYawMin; // 2996
			float hipGunKickYawMax; // 3000
			float hipGunKickMagMin; // 3004
			float hipGunKickAccel; // 3008
			float hipGunKickSpeedMax; // 3012
			float hipGunKickSpeedDecay; // 3016
			float hipGunKickStaticDecay; // 3020
			float hipViewKickPitchMin; // 3024
			float hipViewKickPitchMax; // 3028
			float hipViewKickYawMin; // 3032
			float hipViewKickYawMax; // 3036
			float hipViewKickMagMin; // 3040
			float hipViewKickCenterSpeed; // 3044
			float hipViewScatterMin; // 3048 //*
			float hipViewScatterMax; // 3052 //*
			float xU_043; // 3056 //*
			int adsReloadTransTime; // 3060
			float fightDist; // 3064
			float maxDist; // 3068
			const char* __ptr64 accuracyGraphName[2]; // 3072
			vec2_t* __ptr64 accuracyGraphKnots[2]; // 3088
			vec2_t* __ptr64 originalAccuracyGraphKnots[2]; // 3104
			short accuracyGraphKnotCount[2]; // 3120
			int positionReloadTransTime; // 3124 X
			float leftArc; // 3128
			float rightArc; // 3132
			float topArc; // 3136
			float bottomArc; // 3140
			float accuracy; // 3144
			float aiSpread; // 3148
			float playerSpread; // 3152
			float minTurnSpeed[2]; //3156
			float maxTurnSpeed[2]; // 3164
			float pitchConvergenceTime; // 3172
			float yawConvergenceTime; // 3176
			float suppressTime; // 3180
			float maxRange; // 3184
			float animHorRotateInc; // 3188
			float playerPositionDist; // 3192
			unsigned int useHintStringIndex; // 3196 (runtime variable)
			unsigned int dropHintStringIndex; // 3200 (runtime variable)
			float horizViewJitter; // 3204
			float vertViewJitter; // 3208
			float scanSpeed; // 3212
			float scanAccel; // 3216
			int scanPauseTime; // 3220
			char __pad[12];
			const char* __ptr64 szScript; // 3224
			int minDamage; // 3232
			int midDamage; // 3236
			int minPlayerDamage; // 3240
			int midPlayerDamage; // 3244
			float maxDamageRange; // 3248
			float minDamageRange; // 3252
			int iU_045; // 3256 X
			int iU_046; // 3260 X
			int iU_047; // 3264 X
			int iU_048; // 3268 X
			float fU_049; // 3272 X
			float fU_050; // 3276 X
			float destabilizationRateTime; // 3280
			float destabilizationCurvatureMax; // 3284
			int destabilizeDistance; // 3288
			float turretADSTime; // 3292
			float turretFov; // 3296 X
			float turretFovADS; // 3300 X
			float turretScopeZoomRate; // 3304 X
			float turretScopeZoomMin; // 3308 X
			float turretScopeZoomMax; // 3312 X
			float xU_056; // 3316 X
			float xU_057; // 3320 X
			float xU_058; // 3324 X
			float xU_059; // 3328 X
			float turretBarrelSpinSpeed; // 3332
			float turretBarrelSpinUpTime; // 3336
			float turretBarrelSpinDownTime; // 3340 X
			float missileConeSoundRadiusAtTop; // 3344 X
			float missileConeSoundRadiusAtBase; // 3348 X
			float missileConeSoundHeight; // 3352 X
			float missileConeSoundOriginOffset; // 3356 X
			float missileConeSoundVolumescaleAtCore; // 3360 X
			float missileConeSoundVolumescaleAtEdge; // 3364 X
			float missileConeSoundVolumescaleCoreSize; // 3368 X
			float missileConeSoundPitchAtTop; // 3372 X
			float missileConeSoundPitchAtBottom; // 3376 X
			float missileConeSoundPitchTopSize; // 3380 X
			float missileConeSoundPitchBottomSize; // 3384 X
			float missileConeSoundCrossfadeTopSize; // 3388 X
			float missileConeSoundCrossfadeBottomSize; // 3392 X
			float aim_automelee_lerp; // 3396
			float aim_automelee_range; // 3400
			float aim_automelee_region_height; // 3404
			float aim_automelee_region_width; // 3408
			float player_meleeHeight; // 3412
			float player_meleeRange; // 3416
			float player_meleeWidth; // 3420
			float signatureFireTime; // 3424
			int signatureNumBullets; // 3428
			weapFireTimeInterpolation_t fireTimeInterpolationType; // 3432
			int xU_075; // 3436 X
			int ammoUsedPerShot; // 3440
			int xU_076; // 3444 X
			int xU_077; // 3448 X
			int xU_078; // 3452 X
			int iU_079; // 3456 // int numBulletTags (BG_ShowHideTagsBasedOnAltMode)
			int iU_080; // 3460 // int tagForAmmo (1400C77D0)
			scr_string_t stowTag; // 3464
			bool bU_081; // 3468 X
			bool unknownReticleBooleanValue1; // 3469 (CG_DrawCrosshair)
			bool unknownReticleBooleanValue2; // 3470 (CG_DrawCrosshair)
			bool turretADSEnabled; // 3471 X
			bool knifeAttachTagLeft; // 3472
			bool knifeAlwaysAttached; // 3473
			bool meleeOverrideValues; // 3474
			bool bU_083; // 3475 X
			bool bU_084; // 3476 X
			bool sharedAmmo; // 3477
			bool lockonSupported; // 3478
			bool requireLockonToFire; // 3479
			bool isAirburstWeapon; // 3480 X
			bool bigExplosion; // 3481 X
			bool noAdsWhenMagEmpty; // 3482
			bool avoidDropCleanup; // 3483
			bool inheritsPerks; // 3484
			bool crosshairColorChange; // 3485
			bool rifleBullet; // 3486
			bool armorPiercing; // 3487
			bool boltAction; // 3488
			bool aimDownSight; // 3489
			bool canHoldBreath; // 3490
			bool meleeOnly; // 3491
			bool bU_085; // 3492 bool isMeleeAnimDelayed;? (0x14009FDC0)(1401F2BC0)
			bool bU_086; // 3493 X bool oldWeaponBot;?
			bool canVariableZoom; // 3494
			bool rechamberWhileAds; // 3495
			bool bulletExplosiveDamage; // 3496
			bool cookOffHold; // 3497
			bool reticleSpin45; // 3498 X
			bool reticleSideEnabled; // 3499
			bool clipOnly; // 3500
			bool noAmmoPickup; // 3501
			bool disableSwitchToWhenEmpty; // 3502
			bool bU_088; // 3503 (14017E520) bool hiddenAmmo;?
			bool hasMotionTracker; // 3504
			bool bU_089; // 3505 X
			bool noDualWield; // 3506
			bool flipKillIcon; // 3507
			bool actionSlotShowAmmo; // 3508
			bool noPartialReload; // 3509
			bool segmentedReload; // 3510
			bool multipleReload; // 3511
			bool blocksProne; // 3512
			bool silenced; // 3513
			bool isRollingGrenade; // 3514
			bool projExplosionEffectForceNormalUp; // 3515
			bool projExplosionEffectInheritParentDirection; // 3516
			bool projImpactExplode; // 3517
			bool projTrajectoryEvents; // 3518 X
			bool projWhizByEnabled; // 3519 X
			bool stickToPlayers; // 3520 X
			bool stickToVehicles; // 3521 X
			bool stickToTurrets; // 3522 X
			bool thrownSideways; // 3523 X
			bool hasDetonatorEmptyThrow; // 3524
			bool hasDetonatorDoubleTap; // 3525
			bool disableFiring; // 3526
			bool timedDetonation; // 3527
			bool bU_090; // 3528 (G_FireGrenade)(CheckCrumpleMissile) bool usesGrenadeTimer?
			bool bU_091; // 3529 (G_FireRocket) bool usesRocketTimer?
			bool rotate; // 3530
			bool holdButtonToThrow; // 3531 X
			bool freezeMovementWhenFiring; // 3532
			bool thermalScope; // 3533
			bool thermalToggle; // 3534
			bool outlineEnemies; // 3535
			bool altModeSameWeapon; // 3536
			bool turretBarrelSpinEnabled; // 3537
			bool missileConeSoundEnabled; // 3538 X
			bool missileConeSoundPitchshiftEnabled; // 3539 X
			bool missileConeSoundCrossfadeEnabled; // 3540 X
			bool offhandHoldIsCancelable; // 3541
			bool doNotAllowAttachmentsToOverrideSpread; // 3542
			bool useFastReloadAnims; // 3543 (140202800)
			bool dualMagReloadSupported; // 3544
			bool reloadStopsAlt; // 3545 X
			bool bU_092; // 3546 X
			bool alwaysShatterGlassOnImpact; // 3547
			bool oldWeapon; // 3548
			bool bU_093; // 3549 bool isC4;? (BulletRicochet)(PM_Weapon_OffHandPrepare)
			bool bU_094; // 3550 (BG_WeaponFireRecoil)(Missile_Impact)
			bool xU_095; // 3551 X
			bool hasCounterSilencer; // 3552 (BG_HasCounterSilencer)
			bool xU_097; // 3553 X
			bool xU_098; // 3554 X
			bool disableVariableAutosimRate; // 3555
			bool bU_100; // 3556 (CG_Missile)
			bool bU_101; // 3557 (CG_Missile)
			bool bU_102; // 3558 (CG_Missile)
			bool bU_103; // 3559 (CG_Missile)
			bool bU_104; // 3560 X
			bool cloakedWeapon; // 3561 (BG_IsWeaponCloaked)
			bool adsHideWeapon; // 3562 (0x1401fa7aa)
			bool adsHideHands; // 3563 (0x1401fa78a)
			bool bU_108; // 3564 X
			bool adsBlurSceneEnabled; // 3565 (BG_GetADSSceneBlur)
			bool usesSniperScope; // 3566 (BG_UsingSniperScope)
			bool bU_111; // 3567 (140499130) (14049CE70) (14049B890) (14049B680)
			bool bU_112; // 3568 X
			bool bU_113; // 3569 X
			bool bU_114; // 3570 (BG_ShowHideTagsBasedOnAltMode)
			bool bU_115; // 3571 (BG_ShowHideTagsBasedOnAltMode)
			float xU_03_1;
			float adsDofPhysicalFStop; // 3572 (BG_ADSDOFPhysicalFStop)
			float adsDofPhysicalFocusDistance; // 3576 (BG_ADSDOFPhysicalFocusDistance)
			float autosimSpeedScalar; // 3580 (BG_GetAutosimSpeedScalar)
			float explosionReactiveMotionParts[5]; // 3584 (BG_GetExplosionReactiveMotionParams)
			char __pad_unknown[12]; // 3604
			//1400C7650
			// size: 3616
		}; static_assert(sizeof(WeaponDef) == 0xF08);

		static_assert(offsetof(WeaponDef, gunModel) == 0x28);
		static_assert(offsetof(WeaponDef, handModel) == 0x30);
		static_assert(offsetof(WeaponDef, szModeName) == 0x48);
		static_assert(offsetof(WeaponDef, szXAnimsLeftHanded) == 88);
		static_assert(offsetof(WeaponDef, hideTags) == 0x60);
		static_assert(offsetof(WeaponDef, attachments) == 104);
		static_assert(offsetof(WeaponDef, numReloadStateTimerOverrides) == 1480);
		static_assert(offsetof(WeaponDef, viewFlashADSEffect) == 272);
		static_assert(offsetof(WeaponDef, viewBodyFlashADSEffect) == 280);
		static_assert(offsetof(WeaponDef, reticleCenter) == 1120);
		static_assert(offsetof(WeaponDef, reticleSide) == 1128);
		static_assert(offsetof(WeaponDef, projTrailEffect) == 3040);
		static_assert(offsetof(WeaponDef, projBeaconEffect) == 3048);
		static_assert(offsetof(WeaponDef, projIgnitionEffect) == 3080);
		static_assert(offsetof(WeaponDef, projIgnitionSound) == 3088);
		static_assert(offsetof(WeaponDef, accuracyGraphName) == 3280);
		static_assert(offsetof(WeaponDef, accuracyGraphKnots) == 3296);
		static_assert(offsetof(WeaponDef, originalAccuracyGraphKnots) == 3312);
		static_assert(offsetof(WeaponDef, accuracyGraphName[1]) == 3288);
		static_assert(offsetof(WeaponDef, accuracyGraphKnots[1]) == 3304);
		static_assert(offsetof(WeaponDef, originalAccuracyGraphKnots[1]) == 3320);
		static_assert(offsetof(WeaponDef, szScript) == 3448);
		static_assert(offsetof(WeaponDef, stowTag) == 3688);

		static_assert(offsetof(WeaponDef, ammoIndex) == 1752);
		static_assert(offsetof(WeaponDef, standMoveMinSpeed) == 1712);
		static_assert(offsetof(WeaponDef, weapType) == 1484);
		static_assert(offsetof(WeaponDef, altWeapon) == 1472);
		static_assert(offsetof(WeaponDef, clipIndex) == 1760);
		static_assert(offsetof(WeaponDef, burstFireCooldown) == 1520);
		static_assert(offsetof(WeaponDef, greebleType) == 1524);

		struct cplane_s
		{
			float normal[3];
			float dist;
			unsigned char type;
			//unsigned char pad[3];
		}; assert_sizeof(cplane_s, 20);

		enum CSurfaceFlags : std::uint32_t
		{
			SURF_FLAG_DEFAULT = 0x00000000,
			SURF_FLAG_BARK = 0x00100000,
			SURF_FLAG_BRICK = 0x00200000,
			SURF_FLAG_CARPET = 0x00300000,
			SURF_FLAG_CLOTH = 0x00400000,
			SURF_FLAG_CONCRETE = 0x00500000,
			SURF_FLAG_DIRT = 0x00600000,
			SURF_FLAG_FLESH = 0x00700000,
			SURF_FLAG_FOLIAGE_DEBRIS = 0x00800000,
			SURF_FLAG_GLASS = 0x00900000,
			SURF_FLAG_GRASS = 0x00A00000,
			SURF_FLAG_GRAVEL = 0x00B00000,
			SURF_FLAG_ICE = 0x00C00000,
			SURF_FLAG_METAL_SOLID = 0x00D00000,
			SURF_FLAG_METAL_GRATE = 0x00E00000,
			SURF_FLAG_MUD = 0x00F00000,
			SURF_FLAG_PAPER = 0x01000000,
			SURF_FLAG_PLASTER = 0x01100000,
			SURF_FLAG_ROCK = 0x01200000,
			SURF_FLAG_SAND = 0x01300000,
			SURF_FLAG_SNOW = 0x01400000,
			SURF_FLAG_WATER_WAIST = 0x01500000,
			SURF_FLAG_WOOD_SOLID = 0x01600000,
			SURF_FLAG_ASPHALT = 0x01700000,
			SURF_FLAG_CERAMIC = 0x01800000,
			SURF_FLAG_PLASTIC_SOLID = 0x01900000,
			SURF_FLAG_RUBBER = 0x01A00000,
			SURF_FLAG_FRUIT = 0x01B00000,
			SURF_FLAG_PAINTEDMETAL = 0x01C00000,
			SURF_FLAG_RIOTSHIELD = 0x01D00000,
			SURF_FLAG_SLUSH = 0x01E00000,
			SURF_FLAG_ASPHALT_WET = 0x01F00000,
			SURF_FLAG_ASPHALT_DEBRIS = 0x02000000,
			SURF_FLAG_CONCRETE_WET = 0x02100000,
			SURF_FLAG_CONCRETE_DEBRIS = 0x02200000,
			SURF_FLAG_FOLIAGE_VEGETATION = 0x02300000,
			SURF_FLAG_FOLIAGE_LEAVES = 0x02400000,
			SURF_FLAG_GRASS_TALL = 0x02500000,
			SURF_FLAG_METAL_HOLLOW = 0x02600000,
			SURF_FLAG_METAL_VEHICLE = 0x02700000,
			SURF_FLAG_METAL_THIN = 0x02800000,
			SURF_FLAG_METAL_WET = 0x02900000,
			SURF_FLAG_METAL_DEBRIS = 0x02A00000,
			SURF_FLAG_PLASTIC_HOLLOW = 0x02B00000,
			SURF_FLAG_PLASTIC_TARP = 0x02C00000,
			SURF_FLAG_ROCK_WET = 0x02D00000,
			SURF_FLAG_ROCK_DEBRIS = 0x02E00000,
			SURF_FLAG_WATER_ANKLE = 0x02F00000,
			SURF_FLAG_WATER_KNEE = 0x03000000,
			SURF_FLAG_WATER_HOLLOW = 0x03100000,
			SURF_FLAG_WOOD_HOLLOW = 0x03200000,
			SURF_FLAG_WOOD_DEBRIS = 0x03300000,
			SURF_FLAG_CUSHION = 0x03400000,
			SURF_FLAG_CLIPMISSILE = 0x00000000,
			SURF_FLAG_AI_NOSIGHT = 0x00000000,
			SURF_FLAG_CLIPSHOT = 0x00000000,
			SURF_FLAG_PLAYERCLIP = 0x00000000,
			SURF_FLAG_MONSTERCLIP = 0x00000000,
			SURF_FLAG_AICLIPALLOWDEATH = 0x00000000,
			SURF_FLAG_VEHICLECLIP = 0x00000000,
			SURF_FLAG_ITEMCLIP = 0x00000000,
			SURF_FLAG_NODROP = 0x00000000,
			SURF_FLAG_NONSOLID = 0x00004000,
			SURF_FLAG_NOGRAPPLE = 0x00008000,
			SURF_FLAG_DETAIL = 0x00000000,
			SURF_FLAG_STRUCTURAL = 0x00000000,
			SURF_FLAG_PORTAL = 0x80000000,
			SURF_FLAG_CANSHOOTCLIP = 0x00000000,
			SURF_FLAG_ORIGIN = 0x00000000,
			SURF_FLAG_SKY = 0x00000004,
			SURF_FLAG_NOCASTSHADOW = 0x00040000,
			SURF_FLAG_PHYSICSGEOM = 0x00000000,
			SURF_FLAG_LIGHTPORTAL = 0x00000000,
			SURF_FLAG_OUTDOORBOUNDS = 0x00000000,
			SURF_FLAG_SLICK = 0x00000002,
			SURF_FLAG_NOIMPACT = 0x00000010,
			SURF_FLAG_NOMARKS = 0x00000020,
			SURF_FLAG_NOPENETRATE = 0x00000100,
			SURF_FLAG_LADDER = 0x00000008,
			SURF_FLAG_NODAMAGE = 0x00000001,
			SURF_FLAG_MANTLEON = 0x04000000,
			SURF_FLAG_MANTLEOVER = 0x08000000,
			SURF_FLAG_STAIRS = 0x00000200,
			SURF_FLAG_SOFT = 0x00001000,
			SURF_FLAG_NOSTEPS = 0x00002000,
			SURF_FLAG_NODRAW = 0x00000080,
			SURF_FLAG_NOLIGHTMAP = 0x00000400,
			SURF_FLAG_NODLIGHT = 0x00020000,
			SURF_FLAG_TRANSSORT = 0x00080000,
		};

		struct ClipMaterial
		{
			const char* __ptr64 name;
			int surfaceFlags;
			int contents;
		}; assert_sizeof(ClipMaterial, 16);

		struct cLeafBrushNodeLeaf_t
		{
			unsigned short* __ptr64 brushes;
		};

		struct cLeafBrushNodeChildren_t
		{
			float dist;
			float range;
			unsigned short childOffset[2];
		};

		union cLeafBrushNodeData_t
		{
			cLeafBrushNodeLeaf_t leaf;
			cLeafBrushNodeChildren_t children;
		};

		struct cLeafBrushNode_s
		{
			unsigned char axis;
			short leafBrushCount;
			int contents;
			cLeafBrushNodeData_t data;
		}; assert_sizeof(cLeafBrushNode_s, 24);

		typedef unsigned short LeafBrush;

		struct BrushesCollisionTree
		{
			unsigned int leafbrushNodesCount;
			cLeafBrushNode_s* __ptr64 leafbrushNodes;
			unsigned int numLeafBrushes;
			LeafBrush* __ptr64 leafbrushes;
		}; assert_sizeof(BrushesCollisionTree, 32);

		union CollisionAabbTreeIndex
		{
			int firstChildIndex;
			int partitionIndex;
		};

		struct CollisionAabbTree
		{
			float midPoint[3];
			unsigned short materialIndex;
			unsigned short childCount;
			float halfSize[3];
			CollisionAabbTreeIndex u;
		}; assert_sizeof(CollisionAabbTree, 32);

		struct PatchesCollisionTree
		{
			int aabbTreeCount;
			CollisionAabbTree* __ptr64 aabbTrees;
		}; assert_sizeof(PatchesCollisionTree, 16);

		struct SModelAabbNode
		{
			Bounds bounds;
			unsigned short firstChild;
			unsigned short childCount;
		}; assert_sizeof(SModelAabbNode, 28);

		struct SModelsCollisionTree
		{
			unsigned short numStaticModels;
			unsigned short smodelNodeCount;
			SModelAabbNode* __ptr64 smodelNodes;
		}; assert_sizeof(SModelsCollisionTree, 16);

		struct cbrushside_t
		{
			unsigned int planeIndex;
			unsigned short materialNum;
			unsigned char firstAdjacentSideOffset;
			unsigned char edgeCount;
		}; assert_sizeof(cbrushside_t, 8);

		typedef unsigned char cbrushedge_t;

		struct cbrush_t
		{
			unsigned short numsides;
			unsigned short glassPieceIndex;
			cbrushside_t* __ptr64 sides;
			cbrushedge_t* __ptr64 baseAdjacentSide;
			short axialMaterialNum[2][3];
			unsigned char firstAdjacentSideOffsets[2][3];
			unsigned char edgeCount[2][3];
		}; assert_sizeof(cbrush_t, 48);
		assert_offsetof(cbrush_t, sides, 8);

		struct BrushesCollisionData
		{
			unsigned int numBrushSides;
			cbrushside_t* __ptr64 brushSides;
			unsigned int numBrushEdges;
			cbrushedge_t* __ptr64 brushEdges;
			unsigned int numBrushes;
			cbrush_t* __ptr64 brushes;
			Bounds* __ptr64 brushBounds;
			int* __ptr64 brushContents;
		};

		static_assert(sizeof(BrushesCollisionData) == 0x40);

		struct CollisionBorder
		{
			float distEq[3];
			float zBase;
			float zSlope;
			float start;
			float length;
		}; assert_sizeof(CollisionBorder, 28);

		struct CollisionPartition
		{
			unsigned char triCount;
			unsigned char borderCount;
			unsigned char firstVertSegment;
			int firstTri;
			CollisionBorder* __ptr64 borders;
		}; assert_sizeof(CollisionPartition, 16);

		struct PatchesCollisionData
		{
			unsigned int vertCount;
			vec3_t* __ptr64 verts;
			int triCount;
			unsigned short* __ptr64 triIndices;
			unsigned char* __ptr64 triEdgeIsWalkable;
			int borderCount;
			CollisionBorder* __ptr64 borders;
			int partitionCount;
			CollisionPartition* __ptr64 partitions;
		}; assert_sizeof(PatchesCollisionData, 72);

		struct cStaticModel_s
		{
			XModel* __ptr64 xmodel;
			float origin[3];
			float invScaledAxis[3][3];
			Bounds absBounds;
			int lightingHandle;
		}; assert_sizeof(cStaticModel_s, 88);

		struct SModelsCollisionData
		{
			unsigned int numStaticModels;
			cStaticModel_s* __ptr64 staticModelList;
		}; assert_sizeof(SModelsCollisionData, 16);

		struct ClipInfo
		{
			int planeCount;
			cplane_s* __ptr64 planes;
			unsigned int numMaterials;
			ClipMaterial* __ptr64 materials;
			BrushesCollisionTree bCollisionTree;
			PatchesCollisionTree pCollisionTree;
			SModelsCollisionTree sCollisionTree;
			BrushesCollisionData bCollisionData;
			PatchesCollisionData pCollisionData;
			SModelsCollisionData sCollisionData;
		}; assert_sizeof(ClipInfo, 0xF8);
		assert_offsetof(ClipInfo, planes, 8);
		assert_offsetof(ClipInfo, bCollisionTree, 32);
		assert_offsetof(ClipInfo, pCollisionTree, 64);
		assert_offsetof(ClipInfo, sCollisionTree, 80);
		assert_offsetof(ClipInfo, bCollisionData, 96);
		assert_offsetof(ClipInfo, pCollisionData, 160);
		assert_offsetof(ClipInfo, sCollisionData, 232);
		assert_offsetof(ClipInfo, bCollisionData.brushes, 136);

		struct cNode_t
		{
			cplane_s* __ptr64 plane;
			short children[2];
		}; assert_sizeof(cNode_t, 16);

		struct cLeaf_t
		{
			unsigned int firstCollAabbIndex;
			unsigned int collAabbCount;
			int brushContents;
			int terrainContents;
			Bounds bounds;
			int leafBrushNode;
		}; assert_sizeof(cLeaf_t, 44);

		struct cmodel_t
		{
			Bounds bounds;
			float radius;
			ClipInfo* __ptr64 info;
			cLeaf_t leaf;
		}; assert_sizeof(cmodel_t, 88);

		assert_offsetof(cmodel_t, info, 32);

		struct Stage
		{
			const char* __ptr64 name;
			float origin[3];
			unsigned short triggerIndex;
			unsigned char sunPrimaryLightIndex;
			unsigned int unk;
		}; assert_sizeof(Stage, 32);

		enum DynEntityType : std::int32_t
		{
			DYNENT_TYPE_INVALID = 0x0,
			DYNENT_TYPE_CLUTTER = 0x1,
			DYNENT_TYPE_DESTRUCT = 0x2,
			DYNENT_TYPE_HINGE = 0x3,
			DYNENT_TYPE_SCRIPTABLEINST = 0x4,
			DYNENT_TYPE_SCRIPTABLEPHYSICS = 0x5,
			DYNENT_TYPE_LINKED = 0x6,
			DYNENT_TYPE_LINKED_NOSHADOW = 0x7,
			DYNENT_TYPE_COUNT = 0x8,
		};

		struct GfxPlacement
		{
			float quat[4];
			float origin[3];
		};

		struct DynEntityHingeDef
		{
			float axisOrigin[3];
			float axisDir[3];
			bool isLimited;
			float angleMin;
			float angleMax;
			float momentOfInertia;
			float friction;
		}; assert_sizeof(DynEntityHingeDef, 44);

		struct DynEntityLinkToDef
		{
			int anchorIndex;
			float originOffset[3];
			float angleOffset[3];
		}; assert_sizeof(DynEntityLinkToDef, 28);

		struct DynEntityDef
		{
			DynEntityType type;
			GfxPlacement pose;
			XModel* __ptr64 baseModel;
			unsigned short brushModel;
			unsigned short physicsBrushModel;
			unsigned short scriptableIndex;
			unsigned short health;
			FxEffectDef* __ptr64 destroyFx;
			snd_alias_list_t* __ptr64 sound;
			PhysPreset* __ptr64 physPreset;
			DynEntityHingeDef* __ptr64 hinge;
			DynEntityLinkToDef* __ptr64 linkTo;
			PhysMass mass;
			int contents;
			char __pad0[8];
		}; assert_sizeof(DynEntityDef, 136);

		struct DynEntityPose
		{
			GfxPlacement pose;
			float radius;
			char __pad0[4];
		}; assert_sizeof(DynEntityPose, 36);

		struct Hinge
		{
			float angle;
			float quat[4];
			float angularVel;
			float torqueAccum;
			bool active;
			float autoDisableTimeLeft;
			DynEntityHingeDef* __ptr64 def;
			PhysPreset* __ptr64 physPreset;
			float centerOfMassRelToAxisOriginAtAngleZero[3];
		};

		struct DynEntityClient
		{
			__int64 physObjId;
			unsigned short flags;
			unsigned short lightingHandle;
			unsigned short health;
			Hinge* __ptr64 hinge;
			XModel* __ptr64 activeModel;
			int contents;
		}; assert_sizeof(DynEntityClient, 40);

		struct DynEntityColl
		{
			unsigned short sector;
			unsigned short nextEntInSector;
			float linkMins[2];
			float linkMaxs[2];
		}; assert_sizeof(DynEntityColl, 20);

		enum ScriptableEventType : std::int32_t
		{
			SCRIPTABLE_EVENT_MODEL = 0x0,
			SCRIPTABLE_EVENT_FX = 0x1,
			SCRIPTABLE_EVENT_STOP_FX = 0x2,
			SCRIPTABLE_EVENT_SOUND = 0x3,
			SCRIPTABLE_EVENT_ANIMATION = 0x4,
			SCRIPTABLE_EVENT_EXPLODE = 0x5,
			SCRIPTABLE_EVENT_HEALTHDRAIN = 0x6,
			SCRIPTABLE_EVENT_PHYSICSLAUNCH = 0x7,
			SCRIPTABLE_EVENT_LIGHTSETTINGS = 0x8,
			SCRIPTABLE_EVENT_SUNLIGHTSETTINGS = 0x9,
			SCRIPTABLE_EVENT_SHAKE = 0xA,
			SCRIPTABLE_EVENT_TRANSLATE = 0xB,
			SCRIPTABLE_EVENT_ROTATE = 0xC,
			SCRIPTABLE_EVENT_STATECHANGE = 0xD,
			SCRIPTABLE_EVENT_COUNT = 0xE,
		};

		struct ScriptableEventModelDef
		{
			XModel* __ptr64 model;
		}; assert_sizeof(ScriptableEventModelDef, 8);

		struct ScriptableEventFxDef
		{
			FxEffectDef* __ptr64 handle;
			scr_string_t tagName;
			unsigned short loopTime;
			unsigned char loopTimeStreamIndex;
			bool tagUseAngles;
		}; assert_sizeof(ScriptableEventFxDef, 16);

		struct ScriptableEventStopFxDef
		{
			FxEffectDef* __ptr64 handle;
			scr_string_t tagName;
			unsigned short loopTime;
			unsigned char loopTimeStreamIndex;
			bool tagUseAngles;
		}; assert_sizeof(ScriptableEventFxDef, 16);

		struct ScriptableEventSoundDef
		{
			snd_alias_list_t* __ptr64 alias;
			bool looping;
		}; assert_sizeof(ScriptableEventSoundDef, 16);

		struct ScriptableEventAnimationDef
		{
			const char* __ptr64 animName;
			bool override;
			bool stateful;
			unsigned char animEntryIndex;
			unsigned char animPlaybackStreamIndex;
			unsigned short timeOffsetMin;
			unsigned short timeOffsetMax;
			unsigned short playbackRateMin;
			unsigned short playbackRateMax;
			unsigned short blendTime;
		}; assert_sizeof(ScriptableEventAnimationDef, 24);

		struct ScriptableEventExplodeDef
		{
			unsigned short forceMin;
			unsigned short forceMax;
			unsigned short radius;
			unsigned short damageMin;
			unsigned short damageMax;
			bool aiAvoid;
		}; assert_sizeof(ScriptableEventExplodeDef, 12);

		struct ScriptableEventHealthDef
		{
			unsigned short amount;
			unsigned short interval;
			unsigned short badPlaceRadius;
			unsigned char streamIndex;
		}; assert_sizeof(ScriptableEventHealthDef, 8);

		struct ScriptableEventPhysicsDef
		{
			XModel* __ptr64 model;
			unsigned char launchDirX;
			unsigned char launchDirY;
			unsigned char launchDirZ;
			unsigned short explForceScale;
			unsigned short bulletForceScale;
		}; assert_sizeof(ScriptableEventPhysicsDef, 16);

		struct ScriptableEventLightSettingsDef
		{
			unsigned char color[4];
			unsigned char lightIndexConstIndex;
			unsigned char transStateStreamIndex;
			unsigned char useColor;
			unsigned char useStateTransitionTime;
			unsigned short intensityScaleMin;
			unsigned short intensityScaleMax;
			unsigned short radiusScaleMin;
			unsigned short radiusScaleMax;
			unsigned short transitionTimeMin;
			unsigned short transitionTimeMax;
			const char* __ptr64 noteworthy;
		}; assert_sizeof(ScriptableEventLightSettingsDef, 32);
		assert_offsetof(ScriptableEventLightSettingsDef, noteworthy, 24);

		struct ScriptableEventSunlightSettingsDef
		{
			unsigned char color[4];
			unsigned char transStateStreamIndex;
			unsigned char flags;
			unsigned short intensityScaleMin;
			unsigned short intensityScaleMax;
			unsigned short pitchMin;
			unsigned short pitchMax;
			unsigned short headingMin;
			unsigned short headingMax;
			unsigned short transitionTimeMin;
			unsigned short transitionTimeMax;
			char __pad0[6];
		}; assert_sizeof(ScriptableEventSunlightSettingsDef, 28);

		struct ScriptableEventShakeDef
		{
			const char* __ptr64 rumbleName;
			unsigned short duration;
			unsigned short durationFadeUp;
			unsigned short durationFadeDown;
			unsigned short radius;
			unsigned short exponent;
			unsigned short scaleEarthquake;
			unsigned char scalePitch;
			unsigned char scaleYaw;
			unsigned char scaleRoll;
			unsigned char frequencyPitch;
			unsigned char frequencyYaw;
			unsigned char frequencyRoll;
			unsigned char flags;
		}; assert_sizeof(ScriptableEventShakeDef, 32);

		struct ScriptableEventTranslateDef
		{
			char __pad0[24];
			const char* __ptr64 str;
		}; assert_sizeof(ScriptableEventTranslateDef, 32);

		struct ScriptableEventRotateDef
		{
			char __pad0[24];
			const char* __ptr64 str;
		}; assert_sizeof(ScriptableEventTranslateDef, 32);

		struct ScriptableEventStateChangeDef
		{
			unsigned char targetIndex;
			unsigned char delayStreamIndex;
			unsigned short delayMin;
			unsigned short delayMax;
		}; assert_sizeof(ScriptableEventStateChangeDef, 6);

		union ScriptableEventDataUnion
		{
			ScriptableEventModelDef setModel;
			ScriptableEventFxDef playFx;
			ScriptableEventStopFxDef stopFx;
			ScriptableEventSoundDef playSound;
			ScriptableEventAnimationDef playAnim;
			ScriptableEventExplodeDef doExplosion;
			ScriptableEventHealthDef healthDrain;
			ScriptableEventPhysicsDef physicsLaunch;
			ScriptableEventLightSettingsDef lightSettings;
			ScriptableEventSunlightSettingsDef sunlightSettings;
			ScriptableEventShakeDef shake;
			ScriptableEventTranslateDef translate;
			ScriptableEventRotateDef rotate;
			ScriptableEventStateChangeDef stateChange;
		};

		struct ScriptableEventDef
		{
			ScriptableEventType type;
			ScriptableEventDataUnion data;
		};

		struct ScriptableStateDef
		{
			scr_string_t name;
			scr_string_t tagName;
			ScriptableEventDef* __ptr64 onEnterEvents;
			unsigned char onEnterEventCount;
			unsigned char damageFlags;
			unsigned char damageParentTransferRate;
			unsigned char damageParentReceiveRate;
			unsigned short maxHealth;
		}; assert_sizeof(ScriptableStateDef, 24);

		struct ScriptablePartDef
		{
			ScriptableStateDef* __ptr64 states;
			scr_string_t name;
			unsigned char stateCount;
			unsigned char flags;
			unsigned char eventStreamTimeRemainIndex;
			unsigned char eventStreamNextChangeTimeIndex;
		}; assert_sizeof(ScriptablePartDef, 16);

		enum ScriptableNotetrackType : std::int32_t
		{
			SCRIPTABLE_NT_FX = 0x0,
			SCRIPTABLE_NT_SOUND = 0x1,
			SCRIPTABLE_NT_COUNT = 0x2,
		};

		struct ScriptableNotetrackFxDef
		{
			FxEffectDef* __ptr64 handle;
			scr_string_t tagName;
			bool useAngles;
		};

		struct ScriptableNotetrackSoundDef
		{
			snd_alias_list_t* __ptr64 alias;
		};

		union ScriptableNotetrackDataUnion
		{
			ScriptableNotetrackFxDef playFx;
			ScriptableNotetrackSoundDef playSound;
		};

		struct ScriptableNotetrackDef
		{
			scr_string_t name;
			ScriptableNotetrackType type;
			ScriptableNotetrackDataUnion data;
		};

		enum ScriptableType : std::int32_t
		{
			SCRIPTABLE_TYPE_GENERAL = 0x0,
			SCRIPTABLE_TYPE_CHARACTER = 0x1,
			SCRIPTABLE_TYPE_COUNT = 0x2,
		};

		struct ScriptableDef
		{
			const char* __ptr64 name;
			XModel* __ptr64 baseModel;
			const char* __ptr64 baseCollisionBrush;
			const char* __ptr64 destroyedCollisionBrush;
			ScriptablePartDef* __ptr64 parts;
			ScriptableNotetrackDef* __ptr64 notetracks;
			ScriptableType type;
			unsigned char flags;
			unsigned char partCount;
			unsigned char serverInstancePartCount;
			unsigned char serverControlledPartCount;
			unsigned char notetrackCount;
			unsigned char eventStreamSize;
			unsigned char eventConstantsSize;
		}; assert_sizeof(ScriptableDef, 0x40);
		assert_offsetof(ScriptableDef, partCount, 53);
		assert_offsetof(ScriptableDef, eventConstantsSize, 58);

		struct ScriptableInstanceTargetData
		{
			char __pad0[68];
		}; assert_sizeof(ScriptableInstanceTargetData, 68);

		struct ScriptableInstancePartState
		{
			unsigned short curHealth;
			unsigned char lastExecutedStateIndex;
			unsigned char stateIndex;
		}; assert_sizeof(ScriptableInstancePartState, 4);

		struct ScriptableInstance
		{
			ScriptableDef* __ptr64 def;
			unsigned char* __ptr64 eventConstantsBuf;
			ScriptableInstanceTargetData* __ptr64 targetData;
			float origin[3];
			float angles[3];
			char __pad0[24];
			scr_string_t targetname;
			unsigned short preBrushModel;
			unsigned short postBrushModel;
			unsigned char flags;
			unsigned char targetDataCount;
			char __pad1[6];
			XModel* __ptr64 currentModel;
			ScriptableInstancePartState* __ptr64 partStates;
			unsigned char* __ptr64 eventStreamBuf;
			unsigned int currentPartBits[8];
			unsigned int damageOwnerEntHandle;
			unsigned short updateNextInstance;
			unsigned short linkedObject;
		}; assert_sizeof(ScriptableInstance, 152);
		assert_offsetof(ScriptableInstance, targetData, 16);
		assert_offsetof(ScriptableInstance, targetname, 72);
		assert_offsetof(ScriptableInstance, currentModel, 88);
		assert_offsetof(ScriptableInstance, partStates, 96);
		assert_offsetof(ScriptableInstance, eventStreamBuf, 104);

		struct ScriptableAnimationEntry
		{
			const char* __ptr64 animName;
			unsigned __int64 runtimeBuf;
		}; assert_sizeof(ScriptableAnimationEntry, 16);

		struct ScriptableMapEnts
		{
			unsigned int instanceStateSize;
			unsigned int instanceCount;
			unsigned int reservedInstanceCount;
			ScriptableInstance* __ptr64 instances;
			unsigned int animEntryCount;
			ScriptableAnimationEntry* __ptr64 animEntries;
			unsigned int replicatedInstanceCount;
		}; assert_sizeof(ScriptableMapEnts, 48);
		assert_offsetof(ScriptableMapEnts, instances, 16);
		assert_offsetof(ScriptableMapEnts, animEntries, 32);

		struct sphere_tree_t
		{
			char __pad0[8];
			int unk_count;
			char __pad1[4];
			unsigned int* __ptr64 unk;
			char __pad2[8];
		}; assert_sizeof(sphere_tree_t, 32);
		assert_offsetof(sphere_tree_t, unk_count, 8);
		assert_offsetof(sphere_tree_t, unk, 16);

		struct sphere_tree_obj_t
		{
			char __pad0[20];
		}; assert_sizeof(sphere_tree_obj_t, 20);

		struct sphere_tree_data_t
		{
			int sphereTreeCount;
			sphere_tree_t* __ptr64 sphereTree;
			int sphereTreeObjCount;
			sphere_tree_obj_t* __ptr64 sphereTreeObj;
		}; assert_sizeof(sphere_tree_data_t, 32);

		struct grapple_magnet_t
		{
			char __pad0[40];
		}; assert_sizeof(grapple_magnet_t, 40);

		struct grapple_data_t
		{
			sphere_tree_data_t sphereTreeData;
			grapple_magnet_t* __ptr64 magnet;
			unsigned int magnetCount;
			char __pad0[4];
		}; assert_sizeof(grapple_data_t, 48);

		struct /*alignas(128)*/ clipMap_t
		{
			const char* __ptr64 name; // 0
			int isInUse; // 8
			ClipInfo info; // 16
			ClipInfo* __ptr64 pInfo; // 264
			unsigned int numNodes; // 272
			cNode_t* __ptr64 nodes; // 280
			unsigned int numLeafs; // 288
			cLeaf_t* __ptr64 leafs; // 296
			unsigned int numSubModels; // 304
			cmodel_t* __ptr64 cmodels; // 312
			MapEnts* __ptr64 mapEnts; // 320
			Stage* __ptr64 stages; // 328
			unsigned char stageCount; // 336
			MapTriggers stageTrigger; // 344
			unsigned short dynEntCount[2];
			DynEntityDef* __ptr64 dynEntDefList[2];
			DynEntityPose* __ptr64 dynEntPoseList[2];
			DynEntityClient* __ptr64 dynEntClientList[2];
			DynEntityColl* __ptr64 dynEntCollList[2];
			unsigned int dynEntAnchorCount; // 464
			scr_string_t* __ptr64 dynEntAnchorNames; // 472
			ScriptableMapEnts scriptableMapEnts; // 480
			grapple_data_t grappleData; // 528
			unsigned int checksum;
			char __pad0[60]; // alignment padding
		}; assert_sizeof(clipMap_t, 0x280);
		assert_offsetof(clipMap_t, info, 16);
		assert_offsetof(clipMap_t, pInfo, 264);
		assert_offsetof(clipMap_t, nodes, 280);
		assert_offsetof(clipMap_t, leafs, 296);
		assert_offsetof(clipMap_t, cmodels, 312);
		assert_offsetof(clipMap_t, stageTrigger, 344);
		assert_offsetof(clipMap_t, scriptableMapEnts, 480);
		assert_offsetof(clipMap_t, grappleData, 528);


		enum GfxLightType : std::uint8_t
		{
			GFX_LIGHT_TYPE_NONE = 0x0,
			GFX_LIGHT_TYPE_DIR = 0x1,
			GFX_LIGHT_TYPE_SPOT = 0x2,
			GFX_LIGHT_TYPE_OMNI = 0x3,
			GFX_LIGHT_TYPE_COUNT = 0x4,
			GFX_LIGHT_TYPE_DIR_SHADOWMAP = 0x4,
			GFX_LIGHT_TYPE_SPOT_SHADOWMAP = 0x5,
			GFX_LIGHT_TYPE_OMNI_SHADOWMAP = 0x6,
			GFX_LIGHT_TYPE_COUNT_WITH_SHADOWMAP_VERSIONS = 0x7,
			GFX_LIGHT_TYPE_SPOT_SHADOWMAP_CUCOLORIS = 0x7,
			GFX_LIGHT_TYPE_COUNT_WITH_ALL_VERSIONS = 0x8,
		};

		struct ComPrimaryLight
		{
			GfxLightType type; // 0
			unsigned char canUseShadowMap; // 1
			unsigned char needsDynamicShadows; // 2
			unsigned char exponent; // 3
			unsigned char isVolumetric; // 4
			char __pad0[15];
			float color[3]; // 8 12 16
			float dir[3]; // 20 24 28
			float up[3]; // 32 36 40
			float origin[3]; // 44 48 52
			float fadeOffsetRt[2];
			float radius;
			float bulbRadius;
			float bulbLength[3];
			float cosHalfFovOuter; // 84
			float cosHalfFovInner; // 88
			float cosHalfFovExpanded; // 92
			float rotationLimit; // 96
			float translationLimit; // 100
			float cucRotationOffsetRad; // 104
			float cucRotationSpeedRad; // 108
			float cucScrollVector[2]; // 112 116
			float cucScaleVector[2]; // 120 124
			float cucTransVector[2]; // 128 132
			const char* __ptr64 defName; // 136
		};

		assert_sizeof(ComPrimaryLight, 160);
		assert_offsetof(ComPrimaryLight, defName, 152);
		assert_offsetof(ComPrimaryLight, origin, 56);
		assert_offsetof(ComPrimaryLight, dir, 32);
		assert_offsetof(ComPrimaryLight, cosHalfFovOuter, 96);
		assert_offsetof(ComPrimaryLight, rotationLimit, 108);

		struct ComPrimaryLightEnv
		{
			unsigned short primaryLightIndices[4];
			unsigned char numIndices;
		}; assert_sizeof(ComPrimaryLightEnv, 10);

		struct ComWorld
		{
			const char* __ptr64 name;
			int isInUse;
			unsigned int primaryLightCount;
			ComPrimaryLight* __ptr64 primaryLights;
			unsigned int primaryLightEnvCount;
			ComPrimaryLightEnv* __ptr64 primaryLightEnvs;
		}; assert_sizeof(ComWorld, 0x28);

		struct G_GlassPiece
		{
			unsigned short damageTaken;
			unsigned short collapseTime;
			int lastStateChangeTime;
			unsigned char impactDir;
			unsigned char impactPos[2];
		}; assert_sizeof(G_GlassPiece, 12);

		struct G_GlassName
		{
			char* __ptr64 nameStr;
			scr_string_t name; // set during runtime from nameStr, G_InitGlass
			unsigned short pieceCount;
			unsigned short* __ptr64 pieceIndices;
		}; assert_sizeof(G_GlassName, 24);

		struct G_GlassData
		{
			G_GlassPiece* __ptr64 glassPieces;
			unsigned int pieceCount;
			unsigned short damageToWeaken;
			unsigned short damageToDestroy;
			unsigned int glassNameCount;
			G_GlassName* __ptr64 glassNames;
			unsigned char pad[108];
		}; assert_sizeof(G_GlassData, 0x90);

		struct GlassWorld
		{
			const char* __ptr64 name;
			G_GlassData* __ptr64 g_glassData;
		}; assert_sizeof(GlassWorld, 0x10);

		struct FxGlassDef
		{
			float halfThickness;
			float texVecs[2][2];
			GfxColor color;
			Material* __ptr64 material;
			Material* __ptr64 materialShattered;
			PhysPreset* __ptr64 physPreset;
			FxEffectDef* __ptr64 pieceBreakEffect;
			FxEffectDef* __ptr64 shatterEffect;
			FxEffectDef* __ptr64 shatterSmallEffect;
			FxEffectDef* __ptr64 crackDecalEffect;
			snd_alias_list_t* __ptr64 damagedSound;
			snd_alias_list_t* __ptr64 destroyedSound;
			snd_alias_list_t* __ptr64 destroyedQuietSound;
			char __pad[8];
			int numCrackRings;
			bool isOpaque;
		}; assert_sizeof(FxGlassDef, 120);

		struct FxSpatialFrame
		{
			float quat[4];
			float origin[3];
			char __pad0[4];
		};

		struct $03A8A7B39FA20F64B5AB79125E07CD62
		{
			FxSpatialFrame frame;
			float radius;
		};

		union FxGlassPiecePlace
		{
			$03A8A7B39FA20F64B5AB79125E07CD62 __s0;
			unsigned int nextFree;
		}; assert_sizeof(FxGlassPiecePlace, 36);

		struct FxGlassPieceState
		{
			float texCoordOrigin[2];
			unsigned int supportMask;
			unsigned short initIndex;
			unsigned short geoDataStart;
			unsigned short lightingIndex;
			unsigned char defIndex;
			unsigned char pad[3];
			unsigned char vertCount;
			unsigned char holeDataCount;
			unsigned char crackDataCount;
			unsigned char fanDataCount;
			unsigned short flags;
			float areaX2;
		}; assert_sizeof(FxGlassPieceState, 32);

		struct FxGlassPieceDynamics
		{
			int fallTime;
			__int64 physObjId;
			__int64 physJointId;
			float vel[3];
			float avel[3];
		}; assert_sizeof(FxGlassPieceDynamics, 48);

		struct FxGlassVertex
		{
			short x;
			short y;
		};

		struct FxGlassHoleHeader
		{
			unsigned short uniqueVertCount;
			unsigned char touchVert;
			unsigned char pad[1];
		};

		struct FxGlassCrackHeader
		{
			unsigned short uniqueVertCount;
			unsigned char beginVertIndex;
			unsigned char endVertIndex;
		};

		union FxGlassGeometryData
		{
			FxGlassVertex vert;
			FxGlassHoleHeader hole;
			FxGlassCrackHeader crack;
			unsigned char asBytes[4];
			short anonymous[2];
		}; assert_sizeof(FxGlassGeometryData, 4);

		struct FxGlassInitPieceState
		{
			FxSpatialFrame frame;
			float radius;
			float texCoordOrigin[2];
			unsigned int supportMask;
			float areaX2;
			unsigned short lightingIndex;
			unsigned char defIndex;
			unsigned char vertCount;
			unsigned char fanDataCount;
			unsigned char pad[1];
		}; assert_sizeof(FxGlassInitPieceState, 60);

		struct FxGlassSystem
		{
			int time;
			int prevTime;
			unsigned int defCount;
			unsigned int pieceLimit;
			unsigned int pieceWordCount;
			unsigned int cellCount;
			unsigned int activePieceCount; //
			unsigned int firstFreePiece; //
			unsigned int geoDataLimit;
			unsigned int geoDataCount;
			unsigned int initGeoDataCount;
			//
			FxGlassDef* __ptr64 defs;
			FxGlassPiecePlace* __ptr64 piecePlaces;
			FxGlassPieceState* __ptr64 pieceStates;
			FxGlassPieceDynamics* __ptr64 pieceDynamics;
			FxGlassGeometryData* __ptr64 geoData;
			unsigned int* __ptr64 isInUse;
			unsigned int* __ptr64 cellBits;
			unsigned char* __ptr64 visData;
			float(*__ptr64 linkOrg)[3];
			float* __ptr64 halfThickness;
			unsigned short* __ptr64 lightingHandles;
			FxGlassGeometryData* __ptr64 initGeoData;
			bool needToCompactData; //
			unsigned char initCount; //
			float effectChanceAccum; //
			int lastPieceDeletionTime; //
			unsigned int initPieceCount;
			FxGlassInitPieceState* __ptr64 initPieceStates;
		}; assert_sizeof(FxGlassSystem, 168);
		assert_offsetof(FxGlassSystem, initPieceStates, 160);

		struct FxWorld
		{
			const char* __ptr64 name;
			FxGlassSystem glassSys;
		}; assert_sizeof(FxWorld, 0xB0);

		struct GfxSky
		{
			int skySurfCount;
			int* __ptr64 skyStartSurfs;
			GfxImage* __ptr64 skyImage;
			unsigned char skySamplerState;
			Bounds bounds;
		}; assert_sizeof(GfxSky, 56);

		struct mnode_t
		{
			unsigned short unk0;
			unsigned short unk1;
		};

		struct GfxWorldDpvsPlanes
		{
			int cellCount;
			cplane_s* __ptr64 planes;
			mnode_t* __ptr64 nodes;
			unsigned int* __ptr64 sceneEntCellBits;
		}; assert_sizeof(GfxWorldDpvsPlanes, 32);

		assert_offsetof(GfxWorldDpvsPlanes, planes, 8);
		assert_offsetof(GfxWorldDpvsPlanes, nodes, 16);
		assert_offsetof(GfxWorldDpvsPlanes, sceneEntCellBits, 24);

		struct GfxCellTreeCount
		{
			int aabbTreeCount;
		};

		struct GfxAabbTree
		{
			Bounds bounds;
			int childrenOffset;
			unsigned short childCount;
			unsigned short smodelIndexCount;
			unsigned short* __ptr64 smodelIndexes;
			int startSurfIndex;
			unsigned short surfaceCount;
			unsigned short pad;
		}; assert_sizeof(GfxAabbTree, 48);
		assert_offsetof(GfxAabbTree, childrenOffset, 24);
		assert_offsetof(GfxAabbTree, childCount, 28);
		assert_offsetof(GfxAabbTree, smodelIndexCount, 30);
		assert_offsetof(GfxAabbTree, smodelIndexes, 32);
		assert_offsetof(GfxAabbTree, startSurfIndex, 40);
		assert_offsetof(GfxAabbTree, surfaceCount, 44);

		struct GfxCellTree
		{
			GfxAabbTree* __ptr64 aabbTree;
		};

		struct GfxPortal;
		struct GfxPortalWritable
		{
			bool isQueued;
			bool isAncestor;
			unsigned char recursionDepth;
			unsigned char hullPointCount;
			float(*__ptr64 hullPoints)[2];
			GfxPortal* __ptr64 queuedParent;
		};

		struct DpvsPlane
		{
			float coeffs[4];
		};

		struct GfxPortal
		{
			GfxPortalWritable writable;
			DpvsPlane plane;
			float(*__ptr64 vertices)[3];
			unsigned short cellIndex;
			unsigned short closeDistance;
			unsigned char vertexCount;
			float hullAxis[2][3];
		}; assert_sizeof(GfxPortal, 80);
		assert_offsetof(GfxPortal, vertices, 40);
		assert_offsetof(GfxPortal, vertexCount, 52);

		struct GfxCell
		{
			Bounds bounds;
			short portalCount;
			unsigned char reflectionProbeCount;
			unsigned char reflectionProbeReferenceCount;
			GfxPortal* __ptr64 portals;
			unsigned char* __ptr64 reflectionProbes;
			unsigned char* __ptr64 reflectionProbeReferences;
		}; assert_sizeof(GfxCell, 56);
		assert_offsetof(GfxCell, portalCount, 24);
		assert_offsetof(GfxCell, reflectionProbeCount, 26);
		assert_offsetof(GfxCell, reflectionProbeReferenceCount, 27);
		assert_offsetof(GfxCell, portals, 32);
		assert_offsetof(GfxCell, reflectionProbes, 40);
		assert_offsetof(GfxCell, reflectionProbeReferences, 48);

		struct GfxPortalGroupInfo
		{
			char __pad0[4];
		};

		struct GfxPortalGroup
		{
			const char* __ptr64 group;
			GfxPortalGroupInfo* __ptr64 info;
			char __pad0[8];
			int infoCount;
		};

		assert_sizeof(GfxPortalGroup, 32);
		assert_offsetof(GfxPortalGroup, infoCount, 24);

		struct GfxReflectionProbeVolume
		{
			unsigned short* __ptr64 data;
			unsigned int count;
		}; assert_sizeof(GfxReflectionProbeVolume, 16);

		struct GfxReflectionProbe
		{
			float origin[3];
			GfxReflectionProbeVolume* __ptr64 probeVolumes;
			unsigned int probeVolumeCount;
		}; assert_sizeof(GfxReflectionProbe, 32);
		assert_offsetof(GfxReflectionProbe, probeVolumeCount, 24);

		struct GfxReflectionProbeReferenceOrigin
		{
			float origin[3];
		};

		struct GfxReflectionProbeReference
		{
			unsigned char index;
		};

		struct GfxRawTexture
		{
			char __pad0[32];
		}; assert_sizeof(GfxRawTexture, 32);

		struct GfxLightmapArray
		{
			GfxImage* __ptr64 primary;
			GfxImage* __ptr64 secondary;
		};

		struct GfxWorldVertex
		{
			float xyz[3];
			float binormalSign;
			GfxColor color;
			float texCoord[2];
			float lmapCoord[2];
			PackedUnitVec normal;
			PackedUnitVec tangent;
		}; assert_sizeof(GfxWorldVertex, 44);

		union GfxWorldVertex0Union
		{
			GfxWorldVertex* __ptr64 vertices;
		};

		struct GfxWorldVertexData
		{
			GfxWorldVertex* __ptr64 vertices;
			ID3D11Buffer* __ptr64 worldVb;
			ID3D11ShaderResourceView* __ptr64 worldVbView;
		}; assert_sizeof(GfxWorldVertexData, 24);

		struct GfxWorldVertexLayerData
		{
			unsigned char* __ptr64 data;
			ID3D11Buffer* __ptr64 layerVb;
			ID3D11ShaderResourceView* __ptr64 layerVbView;
		}; assert_sizeof(GfxWorldVertexLayerData, 24);

		struct GfxDisplacementParms
		{
			char __pad0[16];
		}; assert_sizeof(GfxDisplacementParms, 16);

		struct GfxWorldDraw
		{
			unsigned int reflectionProbeCount;
			GfxImage* __ptr64* __ptr64 reflectionProbes;
			GfxReflectionProbe* __ptr64 reflectionProbeOrigins;
			GfxRawTexture* __ptr64 reflectionProbeTextures;
			unsigned int reflectionProbeReferenceCount;
			GfxReflectionProbeReferenceOrigin* __ptr64 reflectionProbeReferenceOrigins;
			GfxReflectionProbeReference* __ptr64 reflectionProbeReferences;
			int lightmapCount;
			GfxLightmapArray* __ptr64 lightmaps;
			GfxRawTexture* __ptr64 lightmapPrimaryTextures;
			GfxRawTexture* __ptr64 lightmapSecondaryTextures;
			GfxImage* __ptr64 lightmapOverridePrimary;
			GfxImage* __ptr64 lightmapOverrideSecondary;
			int u1[2];
			int u2[2];
			int u3;
			unsigned int trisType;
			unsigned int vertexCount;
			GfxWorldVertexData vd;
			unsigned int vertexLayerDataSize;
			GfxWorldVertexLayerData vld;
			unsigned int indexCount;
			unsigned short* __ptr64 indices;
			ID3D11Buffer* __ptr64 indexBuffer;
			ID3D11ShaderResourceView* __ptr64 indexBufferView;
			int displacementParmsCount;
			GfxDisplacementParms* __ptr64 displacementParms;
			ID3D11Buffer* __ptr64 displacementParmsBuffer;
			ID3D11ShaderResourceView* __ptr64 displacementParmsBufferView;
		}; assert_sizeof(GfxWorldDraw, 256);
		assert_offsetof(GfxWorldDraw, reflectionProbeTextures, 24);
		assert_offsetof(GfxWorldDraw, lightmaps, 64);
		assert_offsetof(GfxWorldDraw, lightmapOverrideSecondary, 96);
		assert_offsetof(GfxWorldDraw, vertexCount, 128);
		assert_offsetof(GfxWorldDraw, vd, 136);
		assert_offsetof(GfxWorldDraw, vld, 168);
		assert_offsetof(GfxWorldDraw, indexCount, 192);
		assert_offsetof(GfxWorldDraw, indices, 200);
		assert_offsetof(GfxWorldDraw, displacementParmsCount, 224);
		assert_offsetof(GfxWorldDraw, displacementParms, 232);

		struct GfxLightGridEntry
		{
			unsigned int colorsIndex;
			unsigned short primaryLightEnvIndex;
			unsigned char unused;
			unsigned char needsTrace;
		}; assert_sizeof(GfxLightGridEntry, 8);

		struct GfxLightGridColors
		{
			unsigned char colorVec6[56][6];
		}; assert_sizeof(GfxLightGridColors, 336);

		struct GfxLightGridColorsHDR
		{
			unsigned char colorVec6[56][6];
		}; assert_sizeof(GfxLightGridColorsHDR, 336);

		struct GfxLightGridTree
		{
			unsigned char maxDepth;
			int nodeCount;
			int leafCount;
			int coordMinGridSpace[3];
			int coordMaxGridSpace[3];
			int coordHalfSizeGridSpace[3];
			int defaultColorIndexBitCount;
			int defaultLightIndexBitCount;
			unsigned int* __ptr64 p_nodeTable;
			int leafTableSize;
			unsigned char* __ptr64 p_leafTable;
		}; assert_sizeof(GfxLightGridTree, 80);

		struct GfxLightGrid
		{
			bool hasLightRegions;
			bool useSkyForLowZ;
			unsigned int lastSunPrimaryLightIndex;
			unsigned short mins[3];
			unsigned short maxs[3];
			unsigned int rowAxis;
			unsigned int colAxis;
			unsigned short* __ptr64 rowDataStart;
			unsigned int rawRowDataSize;
			unsigned char* __ptr64 rawRowData;
			unsigned int entryCount;
			GfxLightGridEntry* __ptr64 entries;
			unsigned int colorCount;
			GfxLightGridColors* __ptr64 colors;
			char __pad0[24];
			int tableVersion;
			int paletteVersion;
			char rangeExponent8BitsEncoding;
			char rangeExponent12BitsEncoding;
			char rangeExponent16BitsEncoding;
			unsigned char stageCount;
			float* __ptr64 stageLightingContrastGain;
			unsigned int paletteEntryCount;
			int* __ptr64 paletteEntryAddress;
			unsigned int paletteBitstreamSize;
			unsigned char* __ptr64 paletteBitstream;
			GfxLightGridColorsHDR skyLightGridColors;
			GfxLightGridColorsHDR defaultLightGridColors;
			GfxLightGridTree tree[3];
		}; assert_sizeof(GfxLightGrid, 1080);
		assert_offsetof(GfxLightGrid, rowDataStart, 32);
		assert_offsetof(GfxLightGrid, rawRowData, 48);
		assert_offsetof(GfxLightGrid, entries, 64);
		assert_offsetof(GfxLightGrid, colors, 80);
		assert_offsetof(GfxLightGrid, paletteVersion, 116);
		assert_offsetof(GfxLightGrid, rangeExponent8BitsEncoding, 120);
		assert_offsetof(GfxLightGrid, stageCount, 123);
		assert_offsetof(GfxLightGrid, stageLightingContrastGain, 128);
		assert_offsetof(GfxLightGrid, paletteEntryCount, 136);
		assert_offsetof(GfxLightGrid, paletteEntryAddress, 144);
		assert_offsetof(GfxLightGrid, paletteBitstreamSize, 152);
		assert_offsetof(GfxLightGrid, paletteBitstream, 160);
		assert_offsetof(GfxLightGrid, tree, 840);

		struct GfxBrushModelWritable
		{
			Bounds bounds;
			vec3_t origin;
			vec4_t quat;
			int mdaoVolumeProcessed;
		};

		struct GfxBrushModel
		{
			GfxBrushModelWritable writable;
			Bounds bounds;
			float radius;
			unsigned int startSurfIndex;
			unsigned short surfaceCount;
			int mdaoVolumeIndex;
		}; assert_sizeof(GfxBrushModel, 96);

		struct MaterialMemory
		{
			Material* __ptr64 material;
			int memory;
		}; assert_sizeof(MaterialMemory, 16);

		struct sunflare_t
		{
			bool hasValidData;
			Material* __ptr64 spriteMaterial;
			Material* __ptr64 flareMaterial;
			float spriteSize;
			float flareMinSize;
			float flareMinDot;
			float flareMaxSize;
			float flareMaxDot;
			float flareMaxAlpha;
			int flareFadeInTime;
			int flareFadeOutTime;
			float blindMinDot;
			float blindMaxDot;
			float blindMaxDarken;
			int blindFadeInTime;
			int blindFadeOutTime;
			float glareMinDot;
			float glareMaxDot;
			float glareMaxLighten;
			int glareFadeInTime;
			int glareFadeOutTime;
			float sunFxPosition[3];
		}; assert_sizeof(sunflare_t, 112);

		struct XModelDrawInfo
		{
			unsigned char hasGfxEntIndex;
			unsigned char lod;
			unsigned short surfId;
		};

		struct GfxSceneDynModel
		{
			XModelDrawInfo info;
			unsigned short dynEntId;
		}; assert_sizeof(GfxSceneDynModel, 6);

		struct BModelDrawInfo
		{
			unsigned short surfId;
		};

		struct GfxSceneDynBrush
		{
			BModelDrawInfo info;
			unsigned short dynEntId;
		}; assert_sizeof(GfxSceneDynBrush, 4);

		struct GfxShadowGeometry
		{
			unsigned short surfaceCount;
			unsigned short smodelCount;
			unsigned int* __ptr64 sortedSurfIndex;
			unsigned short* __ptr64 smodelIndex;
		}; assert_sizeof(GfxShadowGeometry, 24);

		struct GfxLightRegionAxis
		{
			float dir[3];
			float midPoint;
			float halfSize;
		}; assert_sizeof(GfxLightRegionAxis, 20);

		struct GfxLightRegionHull
		{
			float kdopMidPoint[9];
			float kdopHalfSize[9];
			unsigned int axisCount;
			GfxLightRegionAxis* __ptr64 axis;
		}; assert_sizeof(GfxLightRegionHull, 88);

		struct GfxLightRegion
		{
			unsigned int hullCount;
			GfxLightRegionHull* __ptr64 hulls;
		}; assert_sizeof(GfxLightRegion, 16);

		struct GfxStaticModelInst
		{
			float mins[3];
			float maxs[3];
			float lightingOrigin[3];
		}; assert_sizeof(GfxStaticModelInst, 36);

		struct srfTriangles_t
		{
			unsigned int vertexLayerData;
			unsigned int firstVertex;
			float maxEdgeLength;
			int unk;
			unsigned short vertexCount;
			unsigned short triCount;
			unsigned int baseIndex;
		};

		struct GfxSurfaceLightingAndFlagsFields
		{
			unsigned char lightmapIndex;
			unsigned char reflectionProbeIndex;
			unsigned short primaryLightEnvIndex;
			unsigned char flags;
			unsigned char unused[3];
		};

		union GfxSurfaceLightingAndFlags
		{
			GfxSurfaceLightingAndFlagsFields fields;
			unsigned __int64 packed;
		};

		struct GfxSurface
		{
			srfTriangles_t tris;
			Material* __ptr64 material;
			GfxSurfaceLightingAndFlags laf;
		}; assert_sizeof(GfxSurface, 40);
		assert_offsetof(GfxSurface, material, 24);

		struct GfxSurfaceBounds
		{
			Bounds bounds;
			char __pad0[11];
			char flags;
		}; assert_sizeof(GfxSurfaceBounds, 36);

		struct GfxPackedPlacement
		{
			float origin[3];
			float axis[3][3];
			float scale;
		};

		enum StaticModelFlag : std::int16_t
		{
			STATIC_MODEL_FLAG_NO_CAST_SHADOW = 0x10,
			STATIC_MODEL_FLAG_GROUND_LIGHTING = 0x20,
			STATIC_MODEL_FLAG_LIGHTGRID_LIGHTING = 0x40,
			STATIC_MODEL_FLAG_VERTEXLIT_LIGHTING = 0x80,
			STATIC_MODEL_FLAG_LIGHTMAP_LIGHTING = 0x100,
			STATIC_MODEL_FLAG_ALLOW_FXMARK = 0x200,
			STATIC_MODEL_FLAG_REACTIVEMOTION = 0x400,
			STATIC_MODEL_FLAG_ANIMATED_VERTS = 0x800,
		};

		struct GfxStaticModelDrawInst
		{
			XModel* __ptr64 model;
			GfxPackedPlacement placement;
			unsigned short cullDist;
			unsigned short flags;
			unsigned short lightingHandle;
			unsigned short staticModelId;
			short unk0;
			unsigned short primaryLightEnvIndex;
			char unk1;
			unsigned char reflectionProbeIndex;
			unsigned char firstMtlSkinIndex;
			unsigned char sunShadowFlags;
		};
		assert_sizeof(GfxStaticModelDrawInst, 80);
		assert_offsetof(GfxStaticModelDrawInst, model, 0);
		assert_offsetof(GfxStaticModelDrawInst, cullDist, 60);
		assert_offsetof(GfxStaticModelDrawInst, flags, 62);
		assert_offsetof(GfxStaticModelDrawInst, lightingHandle, 64);
		assert_offsetof(GfxStaticModelDrawInst, primaryLightEnvIndex, 70);
		assert_offsetof(GfxStaticModelDrawInst, reflectionProbeIndex, 73); // maybe wrong
		assert_offsetof(GfxStaticModelDrawInst, firstMtlSkinIndex, 74);

		struct GfxStaticModelVertexLighting
		{
			unsigned char visibility[4];
			unsigned short ambientColorFloat16[4];
			unsigned short highlightColorFloat16[4];
		}; assert_sizeof(GfxStaticModelVertexLighting, 20);

		struct GfxStaticModelVertexLightingInfo
		{
			GfxStaticModelVertexLighting* __ptr64 lightingValues;
			ID3D11Buffer* __ptr64 lightingValuesVb;
			int numLightingValues;
		};

		struct GfxStaticModelLightmapInfo
		{
			unsigned short cacheId[4];
			unsigned short unk1;
			unsigned short unk2;
			float unk3;
			int unk4;
			int unk5;
			/*
			unsigned short V0[4];
			unsigned short V1[4];
			unsigned short V2[4];
			*/
		};

		struct GfxStaticModelLighting
		{
			union
			{
				GfxStaticModelVertexLightingInfo info;
				GfxStaticModelLightmapInfo info2;
			};
		}; assert_sizeof(GfxStaticModelLighting, 24);

		struct GfxSubdivVertexLightingInfo
		{
			int vertexLightingIndex;
			ID3D11Buffer* __ptr64 vb;
			GfxSubdivCache cache;
		}; assert_sizeof(GfxSubdivVertexLightingInfo, 40);

		struct GfxDepthAndSurf
		{
			char __pad0[8];
		}; assert_sizeof(GfxDepthAndSurf, 8);

		typedef char* __ptr64 GfxWorldDpvsVoid;

		struct GfxWorldDpvsUnk
		{
			char __pad0[8];
			GfxStaticModelVertexLightingInfo info;
			char __pad1[24];
		};

		assert_sizeof(GfxWorldDpvsUnk, 56);

		struct GfxWorldDpvsStatic
		{
			unsigned int smodelCount; // 0
			unsigned int subdivVertexLightingInfoCount; // 4
			unsigned int staticSurfaceCount; // 8
			unsigned int litOpaqueSurfsBegin; // 12
			unsigned int litOpaqueSurfsEnd; // 16
			unsigned int unkSurfsBegin;
			unsigned int unkSurfsEnd;
			unsigned int litDecalSurfsBegin; // 28
			unsigned int litDecalSurfsEnd; // 32
			unsigned int litTransSurfsBegin; // 36
			unsigned int litTransSurfsEnd; // 40
			unsigned int shadowCasterSurfsBegin; // 44
			unsigned int shadowCasterSurfsEnd; // 48
			unsigned int emissiveSurfsBegin; // 52
			unsigned int emissiveSurfsEnd; // 56
			unsigned int smodelVisDataCount; // 60
			unsigned int surfaceVisDataCount; // 64
			unsigned int unkCount1; // 68
			unsigned int* __ptr64 smodelVisData[4]; // 72 80 88 96
			unsigned int* __ptr64 smodelUnknownVisData[27];
			unsigned int* __ptr64 surfaceVisData[4]; // 320 328 336 344
			unsigned int* __ptr64 surfaceUnknownVisData[27];
			unsigned int* __ptr64 smodelUmbraVisData[4]; // 568 576 584 592
			unsigned int* __ptr64 surfaceUmbraVisData[4]; // 600 608 616 624
			unsigned int unkCount2;
			unsigned int* __ptr64 lodData; // 632 // h2 640
			unsigned int* __ptr64 tessellationCutoffVisData; // 640
			unsigned int* __ptr64 sortedSurfIndex; // 648 656
			GfxStaticModelInst* __ptr64 smodelInsts; // 656
			GfxSurface* __ptr64 surfaces; // 664
			GfxSurfaceBounds* __ptr64 surfacesBounds; // 672
			GfxStaticModelDrawInst* __ptr64 smodelDrawInsts; // 680
			unsigned int* __ptr64 unknownSModelVisData1; // 688
			unsigned int* __ptr64 unknownSModelVisData2; // 696
			GfxStaticModelLighting* __ptr64 smodelLighting; // 704 (array)
			GfxSubdivVertexLightingInfo* __ptr64 subdivVertexLighting; // 712 (array)
			GfxDrawSurf* __ptr64 surfaceMaterials; // 720
			unsigned int* __ptr64 surfaceCastsSunShadow; // 728
			unsigned int sunShadowOptCount; // 736
			unsigned int sunSurfVisDataCount; // 740
			unsigned int* __ptr64 surfaceCastsSunShadowOpt; // 744
			GfxDepthAndSurf* __ptr64 surfaceDeptAndSurf; // 752
			GfxWorldDpvsVoid* __ptr64 constantBuffersLit; // 760
			GfxWorldDpvsVoid* __ptr64 constantBuffersAmbient; // 768
			GfxWorldDpvsUnk* __ptr64 gfx_unk;
			int usageCount; // 776
		};
		static_assert(sizeof(GfxWorldDpvsStatic) == 800);
		assert_offsetof(GfxWorldDpvsStatic, smodelDrawInsts, 688);
		assert_offsetof(GfxWorldDpvsStatic, surfaces, 672);
		assert_offsetof(GfxWorldDpvsStatic, lodData, 640);
		assert_offsetof(GfxWorldDpvsStatic, sortedSurfIndex, 656);
		assert_offsetof(GfxWorldDpvsStatic, tessellationCutoffVisData, 648);
		assert_offsetof(GfxWorldDpvsStatic, gfx_unk, 784);
		assert_offsetof(GfxWorldDpvsStatic, unkCount1, 68);

		struct GfxWorldDpvsDynamic
		{
			unsigned int dynEntClientWordCount[2]; // 0 4
			unsigned int dynEntClientCount[2]; // 8 12
			unsigned int* __ptr64 dynEntCellBits[2]; // 16 24
			unsigned char* __ptr64 dynEntVisData[2][4]; // 32 40 48 56 64 72 80 88
		}; assert_sizeof(GfxWorldDpvsDynamic, 96);

		struct GfxHeroOnlyLight
		{
			unsigned char type;
			unsigned char unused[3];
			float color[3];
			float dir[3];
			float up[3];
			float origin[3];
			float radius;
			float cosHalfFovOuter;
			float cosHalfFovInner;
			int exponent;
		}; assert_sizeof(GfxHeroOnlyLight, 68);

		typedef void* __ptr64 umbraTomePtr_t;

		struct GfxBuildInfo
		{
			const char* __ptr64 args0;
			const char* __ptr64 args1;
			const char* __ptr64 buildStartTime;
			const char* __ptr64 buildEndTime;
		}; assert_sizeof(GfxBuildInfo, 32);

		struct GfxWorld
		{
			const char* __ptr64 name; // 0
			const char* __ptr64 baseName; // 8
			unsigned int bspVersion; // 16
			int planeCount; // 20
			int nodeCount; // 24
			unsigned int surfaceCount; // 28
			int skyCount; // 32
			GfxSky* __ptr64 skies; // 40
			unsigned int portalGroupCount; // 48
			char __pad0[16];
			unsigned int lastSunPrimaryLightIndex; // 52
			unsigned int primaryLightCount; // 56
			unsigned int primaryLightEnvCount; // 60
			unsigned int sortKeyLitDecal; // 64
			unsigned int sortKeyEffectDecal; // 68
			unsigned int sortKeyTopDecal; // 72
			unsigned int sortKeyEffectAuto; // 76
			unsigned int sortKeyDistortion; // 80
			unsigned int sortKeyUnknown; // 84 - 104
			unsigned int sortKeyUnknown2; // 88 - 108
			char __pad1[4]; // 92 - 112
			GfxWorldDpvsPlanes dpvsPlanes; // 112
			GfxCellTreeCount* __ptr64 aabbTreeCounts; // 128
			GfxCellTree* __ptr64 aabbTrees; // 136
			GfxCell* __ptr64 cells; // 144
			GfxPortalGroup* __ptr64 portalGroup; // 152
			int unk_vec4_count_0; // 160
			char __pad2[4];
			vec4_t* __ptr64 unk_vec4_0; // 168
			GfxWorldDraw draw; // 176
			GfxLightGrid lightGrid; // 432
			int modelCount; // 1512
			GfxBrushModel* __ptr64 models; // 1520
			vec3_t mins1;
			vec3_t maxs1;
			vec3_t mins2;
			vec3_t maxs2;
			unsigned int checksum;
			int materialMemoryCount; // 1580
			MaterialMemory* __ptr64 materialMemory; // 1584
			sunflare_t sun; // 1592
			float outdoorLookupMatrix[4][4];
			GfxImage* __ptr64 outdoorImage; // 1768
			unsigned int* __ptr64 cellCasterBits; // 1776
			unsigned int* __ptr64 cellHasSunLitSurfsBits; // 1784
			GfxSceneDynModel* __ptr64 sceneDynModel; // 1792
			GfxSceneDynBrush* __ptr64 sceneDynBrush; // 1800
			unsigned int* __ptr64 primaryLightEntityShadowVis; // 1808
			unsigned int* __ptr64 primaryLightDynEntShadowVis[2]; // 1816 1824
			unsigned short* __ptr64 nonSunPrimaryLightForModelDynEnt; // 1832
			GfxShadowGeometry* __ptr64 shadowGeom; // 1840
			GfxShadowGeometry* __ptr64 shadowGeomOptimized; // 1848
			GfxLightRegion* __ptr64 lightRegion; // 1856
			GfxWorldDpvsStatic dpvs; // 1864
			GfxWorldDpvsDynamic dpvsDyn; // 2648
			unsigned int mapVtxChecksum;
			unsigned int heroOnlyLightCount; // 2748
			GfxHeroOnlyLight* __ptr64 heroOnlyLights; // 2752
			unsigned char fogTypesAllowed; // 2760
			unsigned int umbraTomeSize; // 2764
			char* __ptr64 umbraTomeData; // 2768
			umbraTomePtr_t umbraTomePtr; // 2776
			unsigned int mdaoVolumesCount; // 2784
			MdaoVolume* __ptr64 mdaoVolumes; // 2792
			char __pad3[32];
			GfxBuildInfo buildInfo; // 2832
		};

		assert_offsetof(GfxWorld, dpvs, 1880);
		assert_offsetof(GfxWorld, dpvsPlanes, 112);
		assert_offsetof(GfxWorld, primaryLightCount, 72);
		assert_offsetof(GfxWorld, lastSunPrimaryLightIndex, 68);
		assert_offsetof(GfxWorld, aabbTreeCounts, 144);
		assert_offsetof(GfxWorld, portalGroupCount, 48);
		assert_offsetof(GfxWorld, portalGroupCount, 48);
		assert_offsetof(GfxWorld, mdaoVolumesCount, 2816);
		assert_offsetof(GfxWorld, mdaoVolumes, 2824);
		assert_offsetof(GfxWorld, umbraTomeData, 2800);
		assert_offsetof(GfxWorld, umbraTomeSize, 2796);

		static_assert(sizeof(GfxWorld) == 0xB50);

		enum VehicleType
		{
			VEH_WHEELS_4 = 0x0,
			VEH_TANK = 0x1,
			VEH_PLANE = 0x2,
			VEH_BOAT = 0x3,
			VEH_ARTILLERY = 0x4,
			VEH_HELICOPTER = 0x5,
			VEH_SNOWMOBILE = 0x6,
			VEH_SUBMARINE = 0x7,
			VEH_UGV = 0x8,
			VEH_TYPE_COUNT = 0x9,
		};

		enum VehicleAxleType
		{
			VEH_AXLE_FRONT = 0x0,
			VEH_AXLE_REAR = 0x1,
			VEH_AXLE_ALL = 0x2,
			VEH_AXLE_COUNT = 0x3,
		};

		struct VehicleUnknown
		{
			char __pad[36];
		};

		static_assert(sizeof(VehicleUnknown) == 36);

		struct VehiclePhysDef
		{
			int physicsEnabled;
			const char* __ptr64 physPresetName;
			PhysPreset* __ptr64 physPreset;
			const char* __ptr64 unkString01;
			VehicleUnknown* __ptr64 vehicleUnknown01;
			const char* __ptr64 accelGraphName;
			VehicleAxleType steeringAxle;
			VehicleAxleType powerAxle;
			VehicleAxleType brakingAxle;
			float floatValues01[53];
		};

		static_assert(offsetof(VehiclePhysDef, physPreset) == 16);
		static_assert(offsetof(VehiclePhysDef, unkString01) == 24);
		static_assert(offsetof(VehiclePhysDef, physPresetName) == 8);
		static_assert(offsetof(VehiclePhysDef, vehicleUnknown01) == 32);
		static_assert(offsetof(VehiclePhysDef, accelGraphName) == 40);
		static_assert(sizeof(VehiclePhysDef) == 0x110);

		enum VehicleTurretFireType
		{
			VEH_TURRET_SINGLE_FIRE = 0x0,
			VEH_TURRET_DUAL_FIRE = 0x1,
			VEH_TURRET_ALT_FIRE = 0x2,
			VEH_TURRET_FIRE_TYPE_COUNT = 0x3,
		};

		struct VehicleDef
		{
			const char* __ptr64 internalName;
			VehicleType vehicleType;
			const char* __ptr64 useHintString;
			int health;
			float floatValues01[37]; // 184
			int intValues01[8];
			VehiclePhysDef vehPhysDef;
			float floatValues02[12]; // 48
			const char* __ptr64 unkString01;
			FxEffectDef* __ptr64 effect01; // 536
			FxEffectDef* __ptr64 effect02;
			FxEffectDef* __ptr64 effect03;
			FxEffectDef* __ptr64 effect04;
			FxEffectDef* __ptr64 effect05;
			float floatValues03[7]; // 168
			int intValues02[1];
			float floatValues04[32]; // 168
			int vehHelicopterSoftCollisions;
			int vehHelicopterUseGroundFX;
			FxEffectDef* __ptr64 vehHelicopterGroundFx;
			FxEffectDef* __ptr64 vehHelicopterGroundWaterFx;
			float floatValues05[78];
			const char* __ptr64 unkString02;
			float floatValues06[82];
			const char* __ptr64 turretWeaponName;
			WeaponDef* __ptr64 turretWeapon;
			float turretHorizSpanLeft;
			float turretHorizSpanRight;
			float turretVertSpanUp;
			float turretVertSpanDown;
			float turretHorizResistLeft;
			float turretHorizResistRight;
			float turretVertResistUp;
			float turretVertResistDown;
			float turretRotRate;
			VehicleTurretFireType turretFireType;
			snd_alias_list_t* __ptr64 turretSpinSnd;
			snd_alias_list_t* __ptr64 turretStopSnd;
			int trophyEnabled;
			float trophyRadius;
			float trophyInactiveRadius;
			int trophyAmmoCount;
			float trophyReloadTime;
			scr_string_t trophyTags[4];
			FxEffectDef* __ptr64 trophyExplodeFx;
			FxEffectDef* __ptr64 trophyFlashFx;
			Material* __ptr64 compassFriendlyIcon;
			Material* __ptr64 compassEnemyIcon;
			Material* __ptr64 compassFriendlyAltIcon;
			Material* __ptr64 compassEnemyAltIcon;
			int compassIconWidth;
			int compassIconHeight;
			snd_alias_list_t* __ptr64 idleLowSnd;
			snd_alias_list_t* __ptr64 idleHighSnd;
			snd_alias_list_t* __ptr64 engineLowSnd;
			snd_alias_list_t* __ptr64 engineHighSnd;
			snd_alias_list_t* __ptr64 sound01; // rename
			float engineSndSpeed;
			scr_string_t audioOriginTag;
			snd_alias_list_t* __ptr64 idleLowSndAlt;
			snd_alias_list_t* __ptr64 idleHighSndAlt;
			snd_alias_list_t* __ptr64 engineLowSndAlt;
			snd_alias_list_t* __ptr64 engineHighSndAlt;
			float engineSndSpeedAlt;
			scr_string_t audioOriginTagAlt;
			snd_alias_list_t* __ptr64 turretSpinSndAlt;
			snd_alias_list_t* __ptr64 turretStopSndAlt;
			snd_alias_list_t* __ptr64 engineStartUpSnd;
			int engineStartUpLength;
			snd_alias_list_t* __ptr64 engineShutdownSnd;
			snd_alias_list_t* __ptr64 engineIdleSnd;
			snd_alias_list_t* __ptr64 engineSustainSnd;
			snd_alias_list_t* __ptr64 engineRampUpSnd;
			int engineRampUpLength;
			snd_alias_list_t* __ptr64 engineRampDownSnd;
			int engineRampDownLength;
			snd_alias_list_t* __ptr64 suspensionSoftSnd;
			float suspensionSoftCompression;
			snd_alias_list_t* __ptr64 suspensionHardSnd;
			float suspensionHardCompression;
			snd_alias_list_t* __ptr64 collisionSnd;
			float collisionBlendSpeed;
			snd_alias_list_t* __ptr64 speedSnd;
			float speedSndBlendSpeed;
			const char* __ptr64 surfaceSndPrefix;
			snd_alias_list_t* __ptr64 surfaceSnds[53];
			float surfaceSndBlendSpeed;
			float slideVolume;
			float slideBlendSpeed;
			float inAirPitch;
			const char* __ptr64 soundTriggerOverrideZone;
			bool soundTriggerOverrideReverb;
			bool soundTriggerOverrideMix;
			bool soundTriggerOverrideFilter;
			bool soundTriggerOverrideOcclusion;
			bool soundTriggerOverrideAmbient;
			bool soundTriggerOverrideAmbientEvents;
			bool soundTriggerOverrideADSR;
		};

		static_assert(offsetof(VehicleDef, unkString01) == 528);
		static_assert(offsetof(VehicleDef, unkString02) == 1072);
		static_assert(offsetof(VehicleDef, turretWeaponName) == 1408);
		static_assert(offsetof(VehicleDef, turretSpinSnd) == 1464);
		static_assert(offsetof(VehicleDef, turretStopSnd) == 1472);
		static_assert(offsetof(VehicleDef, effect01) == 536);
		static_assert(offsetof(VehicleDef, compassFriendlyIcon) == 1536);
		static_assert(offsetof(VehicleDef, compassEnemyAltIcon) == 1560);
		//static_assert(offsetof(VehicleDef, effect07) == 752);
		static_assert(offsetof(VehicleDef, trophyTags) == 1500);
		static_assert(offsetof(VehicleDef, trophyExplodeFx) == 1520);
		static_assert(offsetof(VehicleDef, idleLowSnd) == 1576);
		static_assert(offsetof(VehicleDef, sound01) == 1608);
		static_assert(offsetof(VehicleDef, audioOriginTag) == 1620);
		static_assert(offsetof(VehicleDef, idleLowSndAlt) == 1624);
		static_assert(offsetof(VehicleDef, engineHighSndAlt) == 1648);
		static_assert(offsetof(VehicleDef, audioOriginTagAlt) == 1660);
		static_assert(offsetof(VehicleDef, turretSpinSndAlt) == 1664);
		static_assert(offsetof(VehicleDef, engineStartUpSnd) == 1680);
		static_assert(offsetof(VehicleDef, engineShutdownSnd) == 1696);
		static_assert(offsetof(VehicleDef, engineIdleSnd) == 1704);
		static_assert(offsetof(VehicleDef, engineSustainSnd) == 1712);
		static_assert(offsetof(VehicleDef, engineRampUpSnd) == 1720);
		static_assert(offsetof(VehicleDef, engineRampDownSnd) == 1736);
		static_assert(offsetof(VehicleDef, suspensionSoftSnd) == 1752);
		static_assert(offsetof(VehicleDef, suspensionHardSnd) == 1768);
		static_assert(offsetof(VehicleDef, collisionSnd) == 1784);
		static_assert(offsetof(VehicleDef, speedSnd) == 1800);
		static_assert(offsetof(VehicleDef, surfaceSndPrefix) == 1816);
		static_assert(offsetof(VehicleDef, surfaceSnds) == 1824);

#define sizeofmember(__struct__, __member__) sizeof(reinterpret_cast<__struct__* __ptr64 >(0)->__member__)

		static_assert(sizeofmember(VehicleDef, surfaceSnds) == 0x1A8);
		static_assert(offsetof(VehicleDef, soundTriggerOverrideZone) == 2264);
		static_assert(sizeof(VehicleDef) == 0x8E8);

		union XAssetHeader
		{
			void* __ptr64 data;
			PhysPreset* __ptr64 physPreset;
			PhysCollmap* __ptr64 physCollmap;
			PhysWaterPreset* __ptr64 physWaterPreset;
			PhysWorld* __ptr64 physWorld;
			PhysConstraint* __ptr64 physConstraint;
			XAnimParts* __ptr64 parts;
			XModelSurfs* __ptr64 modelSurfs;
			XModel* __ptr64 model;
			Material* __ptr64 material;
			ComputeShader* __ptr64 computeShader;
			MaterialVertexShader* __ptr64 vertexShader;
			MaterialHullShader* __ptr64 hullShader;
			MaterialDomainShader* __ptr64 domainShader;
			MaterialPixelShader* __ptr64 pixelShader;
			MaterialVertexDeclaration* __ptr64 vertexDecl;
			MaterialTechniqueSet* __ptr64 techniqueSet;
			GfxImage* __ptr64 image;
			snd_alias_list_t* __ptr64 sound;
			SndCurve* __ptr64 sndCurve;
			SndCurve* __ptr64 lpfCurve;
			SndCurve* __ptr64 reverbCurve;
			SndContext* __ptr64 sndContext;
			LoadedSound* __ptr64 loadSnd;
			LocalizeEntry* __ptr64 localize;
			MapEnts* __ptr64 mapEnts;
			GfxLightDef* __ptr64 lightDef;
			WeaponAttachment* __ptr64 attachment;
			WeaponDef* __ptr64 weapon;
			VehicleDef* __ptr64 vehicle;
			FxEffectDef* __ptr64 fx;
			RawFile* __ptr64 rawfile;
			ScriptFile* __ptr64 scriptfile;
			StringTable* __ptr64 stringTable;
			StructuredDataDefSet* __ptr64 structuredDataDefSet;
			NetConstStrings* __ptr64 netConstStrings;
			TracerDef* __ptr64 tracerDef;
			LuaFile* __ptr64 luaFile;
			DopplerPreset* __ptr64 doppler;
			FxParticleSimAnimation* __ptr64 particleSimAnimation;
			SkeletonScript* __ptr64 skeletonScript;
			TTFDef* __ptr64 ttfDef;
		};

		struct XAsset
		{
			XAssetType type;
			XAssetHeader header;
		};

		struct XAssetEntry
		{
			XAsset asset;
			char zoneIndex;
			volatile char inuseMask;
			unsigned int nextHash;
			unsigned int nextOverride;
			unsigned int nextPoolEntry;
		};

		struct ScriptStringList
		{
			int count;
			const char* __ptr64* __ptr64 strings;
		};

		union GfxZoneTableEntry
		{
			char* __ptr64 dataPtr;
			void* __ptr64 voidPtr;
			ID3D11Buffer* __ptr64 buffer;
			ID3D11DepthStencilState* __ptr64 depthStencilState;
			ID3D11BlendState* __ptr64 blendState;
		};

		typedef std::uint32_t GfxBlendStateBits[3];

		struct XGfxGlobals
		{
			unsigned int depthStencilStateCount;
			unsigned int blendStateCount;
			std::uint64_t* __ptr64 depthStencilStateBits;
			GfxBlendStateBits* __ptr64 blendStateBits;
			GfxZoneTableEntry* __ptr64 depthStencilStates;
			GfxZoneTableEntry* __ptr64 blendStates;
			unsigned int perPrimConstantBufferCount;
			unsigned int perObjConstantBufferCount;
			unsigned int stableConstantBufferCount;
			unsigned int* __ptr64 perPrimConstantBufferSizes;
			unsigned int* __ptr64 perObjConstantBufferSizes;
			unsigned int* __ptr64 stableConstantBufferSizes;
			GfxZoneTableEntry* __ptr64 perPrimConstantBuffers;
			GfxZoneTableEntry* __ptr64 perObjConstantBuffers;
			GfxZoneTableEntry* __ptr64 stableConstantBuffers;
		};

		struct XGlobals
		{
			XGfxGlobals* __ptr64 gfxGlobals;
		};

		struct XAssetList
		{
			ScriptStringList stringList;
			int assetCount;
			XAsset* __ptr64 assets;
			XGlobals* __ptr64 globals;
		};

		enum DBSyncMode
		{
			DB_LOAD_ASYNC = 0x0,
			DB_LOAD_SYNC = 0x1,
			DB_LOAD_ASYNC_WAIT_ALLOC = 0x2,
			DB_LOAD_ASYNC_FORCE_FREE = 0x3,
			DB_LOAD_ASYNC_NO_SYNC_THREADS = 0x4,
			DB_LOAD_SYNC_SKIP_ALWAYS_LOADED = 0x5,
		};

		enum DBAllocFlags : std::int32_t
		{
			DB_ZONE_NONE = 0x0,
			DB_ZONE_COMMON = 0x1,
			DB_ZONE_UI = 0x2,
			DB_ZONE_GAME = 0x4,
			DB_ZONE_LOAD = 0x8,
			DB_ZONE_DEV = 0x10,
			DB_ZONE_BASEMAP = 0x20,
			DB_ZONE_TRANSIENT_POOL = 0x40,
			DB_ZONE_TRANSIENT_MASK = 0x40,
			DB_ZONE_CUSTOM = 0x1000 // added for custom zone loading
		};

		struct XZoneInfo
		{
			const char* __ptr64 name;
			int allocFlags;
			int freeFlags;
		};

		struct XZoneInfoInternal
		{
			char name[64];
			int flags;
			int isBaseMap;
		};
	}
}

#pragma pop()