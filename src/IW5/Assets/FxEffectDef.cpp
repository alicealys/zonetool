#include "stdafx.hpp"
#include "H1/Assets/FxEffectDef.hpp"

namespace ZoneTool
{
	namespace IW5
	{
		/*H1::FxElemType convert_elem_type(IW5::FxElemType type)
		{
			switch (type)
			{
			case IW5::FX_ELEM_TYPE_SPRITE_BILLBOARD:
				return H1::FX_ELEM_TYPE_SPRITE_BILLBOARD;
				break;
			case IW5::FX_ELEM_TYPE_SPRITE_ORIENTED:
				return H1::FX_ELEM_TYPE_SPRITE_ORIENTED;
				break;
			case IW5::FX_ELEM_TYPE_TAIL:
				return H1::FX_ELEM_TYPE_TAIL;
				break;
			case IW5::FX_ELEM_TYPE_TRAIL:
				return H1::FX_ELEM_TYPE_TRAIL;
				break;
			case IW5::FX_ELEM_TYPE_CLOUD:
				return H1::FX_ELEM_TYPE_CLOUD;
				break;
			case IW5::FX_ELEM_TYPE_SPARKCLOUD:
				return H1::FX_ELEM_TYPE_SPARK_CLOUD;
				break;
			case IW5::FX_ELEM_TYPE_SPARKFOUNTAIN:
				return H1::FX_ELEM_TYPE_SPARK_FOUNTAIN;
				break;
			case IW5::FX_ELEM_TYPE_MODEL:
				return H1::FX_ELEM_TYPE_MODEL;
				break;
			case IW5::FX_ELEM_TYPE_OMNI_LIGHT:
				return H1::FX_ELEM_TYPE_OMNI_LIGHT;
				break;
			case IW5::FX_ELEM_TYPE_SPOT_LIGHT:
				return H1::FX_ELEM_TYPE_SPOT_LIGHT;
				break;
			case IW5::FX_ELEM_TYPE_SOUND:
				return H1::FX_ELEM_TYPE_SOUND;
				break;
			case IW5::FX_ELEM_TYPE_DECAL:
				return H1::FX_ELEM_TYPE_DECAL;
				break;
			case IW5::FX_ELEM_TYPE_RUNNER:
				return H1::FX_ELEM_TYPE_RUNNER;
				break;
			}

			return H1::FX_ELEM_TYPE_SPRITE_BILLBOARD;
		}

		H1::FxElemLitType generate_elem_lit_type(IW5::FxElemType type)
		{
			switch (type)
			{
			case IW5::FX_ELEM_TYPE_SPRITE_BILLBOARD:
				return H1::FX_ELEM_LIT_TYPE_LIGHTGRID_FRAME_SPRITE;
				break;
			case IW5::FX_ELEM_TYPE_SPRITE_ORIENTED:
				return H1::FX_ELEM_LIT_TYPE_LIGHTGRID_SPAWN_SINGLE;
				break;
			case IW5::FX_ELEM_TYPE_TAIL:
				return H1::FX_ELEM_LIT_TYPE_LIGHTGRID_FRAME_SPRITE;
				break;
			case IW5::FX_ELEM_TYPE_TRAIL:
				return H1::FX_ELEM_LIT_TYPE_LIGHTGRID_FRAME_VERTEX;
				break;
			case IW5::FX_ELEM_TYPE_CLOUD:
				return H1::FX_ELEM_LIT_TYPE_LIGHTGRID_SPAWN_SINGLE;
				break;
			case IW5::FX_ELEM_TYPE_SPARKCLOUD:
				return H1::FX_ELEM_LIT_TYPE_LIGHTGRID_SPAWN_SINGLE;
				break;
			case IW5::FX_ELEM_TYPE_SPARKFOUNTAIN:
				return H1::FX_ELEM_LIT_TYPE_LIGHTGRID_FRAME_SPRITE;
				break;
			case IW5::FX_ELEM_TYPE_MODEL:
				return H1::FX_ELEM_LIT_TYPE_LIGHTGRID_SPAWN_SINGLE;
				break;
			case IW5::FX_ELEM_TYPE_OMNI_LIGHT:
				return H1::FX_ELEM_LIT_TYPE_LIGHTGRID_SPAWN_SINGLE;
				break;
			case IW5::FX_ELEM_TYPE_SPOT_LIGHT:
				return H1::FX_ELEM_LIT_TYPE_NONE;
				break;
			case IW5::FX_ELEM_TYPE_SOUND:
				return H1::FX_ELEM_LIT_TYPE_LIGHTGRID_SPAWN_SINGLE;
				break;
			case IW5::FX_ELEM_TYPE_DECAL:
				return H1::FX_ELEM_LIT_TYPE_NONE;
				break;
			case IW5::FX_ELEM_TYPE_RUNNER:
				return H1::FX_ELEM_LIT_TYPE_LIGHTGRID_SPAWN_SINGLE;
				break;
			}

			return H1::FX_ELEM_LIT_TYPE_NONE;
		}

		void GenerateH1FxElemDef(H1::FxElemDef* h1_elem, FxElemDef* elem, ZoneMemory* mem)
		{
			h1_elem->flags = elem->flags; // convert? should be the same...
			h1_elem->flags2 = 0;
			memcpy(&h1_elem->spawn, &elem->spawn, sizeof(FxSpawnDef));
			memcpy(&h1_elem->spawnRange, &elem->spawnRange, sizeof(FxFloatRange));
			memcpy(&h1_elem->fadeInRange, &elem->fadeInRange, sizeof(FxFloatRange));
			memcpy(&h1_elem->fadeOutRange, &elem->fadeOutRange, sizeof(FxFloatRange));
			h1_elem->spawnFrustumCullRadius = elem->spawnFrustumCullRadius;
			memcpy(&h1_elem->spawnDelayMsec, &elem->spawnDelayMsec, sizeof(FxIntRange));
			memcpy(&h1_elem->lifeSpanMsec, &elem->lifeSpanMsec, sizeof(FxIntRange));
			memcpy(&h1_elem->spawnOrigin, &elem->spawnOrigin, sizeof(FxFloatRange[3]));
			memcpy(&h1_elem->spawnOffsetRadius, &elem->spawnOffsetRadius, sizeof(FxFloatRange));
			memcpy(&h1_elem->spawnOffsetHeight, &elem->spawnOffsetHeight, sizeof(FxFloatRange));
			memcpy(&h1_elem->spawnAngles, &elem->spawnAngles, sizeof(FxFloatRange[3]));
			memcpy(&h1_elem->angularVelocity, &elem->angularVelocity, sizeof(FxFloatRange[3]));
			memcpy(&h1_elem->initialRotation, &elem->initialRotation, sizeof(FxFloatRange));
			memcpy(&h1_elem->gravity, &elem->gravity, sizeof(FxFloatRange));
			memcpy(&h1_elem->reflectionFactor, &elem->reflectionFactor, sizeof(FxFloatRange));
			memcpy(&h1_elem->atlas, &elem->atlas, sizeof(FxElemAtlas));
			h1_elem->elemType = convert_elem_type(elem->elemType);
			h1_elem->elemLitType = generate_elem_lit_type(elem->elemType); //H1::FX_ELEM_LIT_TYPE_NONE; // ?
			h1_elem->visualCount = elem->visualCount;
			h1_elem->velIntervalCount = elem->velIntervalCount;
			h1_elem->visStateIntervalCount = elem->visStateIntervalCount;

			REINTERPRET_CAST_SAFE(h1_elem->velSamples, elem->velSamples);

			if (elem->visSamples)
			{
				h1_elem->visSamples = mem->Alloc<H1::FxElemVisStateSample>(elem->visStateIntervalCount + 1);
				for (int i = 0; i < elem->visStateIntervalCount + 1; i++)
				{
					// check

					h1_elem->visSamples[i].base.color[0] = static_cast<int>(elem->visSamples[i].base.color[0]) / 255.0f;
					h1_elem->visSamples[i].base.color[1] = static_cast<int>(elem->visSamples[i].base.color[1]) / 255.0f;
					h1_elem->visSamples[i].base.color[2] = static_cast<int>(elem->visSamples[i].base.color[2]) / 255.0f;
					h1_elem->visSamples[i].base.color[3] = static_cast<int>(elem->visSamples[i].base.color[3]) / 255.0f;
					h1_elem->visSamples[i].base.rotationA = elem->visSamples[i].base.rotationTotal;
					h1_elem->visSamples[i].base.rotationB = elem->visSamples[i].base.rotationTotal;
					h1_elem->visSamples[i].base.rotationC = elem->visSamples[i].base.rotationTotal;
					// pad
					memcpy(&h1_elem->visSamples[i].base.size, &elem->visSamples[i].base.size, sizeof(float[2]));
					h1_elem->visSamples[i].base.scale = elem->visSamples[i].base.scale;
					// pad2
					h1_elem->visSamples[i].base.pad2[1] = -0.0f;

					h1_elem->visSamples[i].amplitude.color[0] = static_cast<int>(elem->visSamples[i].amplitude.color[0]) / 255.0f;
					h1_elem->visSamples[i].amplitude.color[1] = static_cast<int>(elem->visSamples[i].amplitude.color[1]) / 255.0f;
					h1_elem->visSamples[i].amplitude.color[2] = static_cast<int>(elem->visSamples[i].amplitude.color[2]) / 255.0f;
					h1_elem->visSamples[i].amplitude.color[3] = static_cast<int>(elem->visSamples[i].amplitude.color[3]) / 255.0f;
					h1_elem->visSamples[i].amplitude.rotationA = elem->visSamples[i].base.rotationTotal;
					h1_elem->visSamples[i].amplitude.rotationB = elem->visSamples[i].base.rotationTotal;
					h1_elem->visSamples[i].amplitude.rotationC = elem->visSamples[i].base.rotationTotal;
					// pad
					memcpy(&h1_elem->visSamples[i].amplitude.size, &elem->visSamples[i].amplitude.size, sizeof(float[2]));
					h1_elem->visSamples[i].amplitude.scale = elem->visSamples[i].amplitude.scale;
					// pad2
					h1_elem->visSamples[i].amplitude.pad2[1] = -0.0f;

					if (elem->visSamples[i].base.rotationTotal)
					{
						auto x = 0;
					}
				}
			}

			if (elem->elemType == FX_ELEM_TYPE_DECAL)
			{
				h1_elem->visuals.markArray = mem->Alloc<H1::FxElemMarkVisuals>(elem->visualCount);
				for (int i = 0; i < elem->visualCount; i++)
				{
					h1_elem->visuals.markArray[i].materials[0] = reinterpret_cast<H1::Material*>(elem->visuals.markArray[i].materials[0]);
					h1_elem->visuals.markArray[i].materials[1] = reinterpret_cast<H1::Material*>(elem->visuals.markArray[i].materials[1]);
					h1_elem->visuals.markArray[i].materials[2] = nullptr;
				}
			}
			else if (elem->visualCount > 1)
			{
				h1_elem->visuals.array = mem->Alloc<H1::FxElemVisuals>(elem->visualCount);
				for (int i = 0; i < elem->visualCount; i++)
				{
					// this is fine
					h1_elem->visuals.array[i].anonymous = elem->visuals.array[i].anonymous;
				}
			}
			else if (elem->visualCount)
			{
				// this is fine
				h1_elem->visuals.instance.anonymous = elem->visuals.instance.anonymous;
			}

			memcpy(&h1_elem->collBounds, &elem->collMins, sizeof(float[3][2]));

			h1_elem->effectOnImpact.name = elem->effectOnImpact.name;
			h1_elem->effectOnDeath.name = elem->effectOnDeath.name;
			h1_elem->effectEmitted.name = elem->effectEmitted.name;
			memcpy(&h1_elem->emitDist, &elem->emitDist, sizeof(FxFloatRange));
			memcpy(&h1_elem->emitDistVariance, &elem->emitDistVariance, sizeof(FxFloatRange));

			switch (elem->elemType)
			{
			case FX_ELEM_TYPE_TRAIL:
				h1_elem->extended.trailDef = mem->Alloc<H1::FxTrailDef>();

				// check
				h1_elem->extended.trailDef->scrollTimeMsec = elem->extended.trailDef->scrollTimeMsec;
				h1_elem->extended.trailDef->repeatDist = elem->extended.trailDef->repeatDist;
				h1_elem->extended.trailDef->invSplitDist = elem->extended.trailDef->invSplitDist;
				h1_elem->extended.trailDef->invSplitArcDist = elem->extended.trailDef->invSplitArcDist;
				h1_elem->extended.trailDef->invSplitTime = elem->extended.trailDef->invSplitTime;
				// pad

				h1_elem->extended.trailDef->vertCount = elem->extended.trailDef->vertCount;
				h1_elem->extended.trailDef->verts = mem->Alloc<H1::FxTrailVertex>(h1_elem->extended.trailDef->vertCount);
				for (int i = 0; i < h1_elem->extended.trailDef->vertCount; i++)
				{
					// check
					memcpy(&h1_elem->extended.trailDef->verts[i].pos, &elem->extended.trailDef->verts[i].pos, sizeof(float[2]));
					memcpy(&h1_elem->extended.trailDef->verts[i].normal, &elem->extended.trailDef->verts[i].normal, sizeof(float[2]));
					memcpy(&h1_elem->extended.trailDef->verts[i].texCoord, &elem->extended.trailDef->verts[i].texCoord, sizeof(float[2]));
					// pad
				}

				h1_elem->extended.trailDef->indCount = elem->extended.trailDef->indCount;
				REINTERPRET_CAST_SAFE(h1_elem->extended.trailDef->inds, elem->extended.trailDef->inds);
				break;
			case FX_ELEM_TYPE_SPARKFOUNTAIN:
				// check
				REINTERPRET_CAST_SAFE(h1_elem->extended.sparkFountainDef, elem->extended.sparkFountain);
				break;
			case FX_ELEM_TYPE_SPOT_LIGHT:
				// check
				h1_elem->extended.spotLightDef = mem->Alloc<H1::FxSpotLightDef>();
				h1_elem->extended.spotLightDef->fovInnerFraction = elem->extended.spotLightDef->fovInnerFraction;
				h1_elem->extended.spotLightDef->startRadius = elem->extended.spotLightDef->startRadius;
				h1_elem->extended.spotLightDef->endRadius = elem->extended.spotLightDef->endRadius;
				h1_elem->extended.spotLightDef->brightness = elem->extended.spotLightDef->brightness;
				h1_elem->extended.spotLightDef->maxLength = elem->extended.spotLightDef->maxLength;
				h1_elem->extended.spotLightDef->exponent = elem->extended.spotLightDef->exponent;
				// pad
				break;
			case FX_ELEM_TYPE_OMNI_LIGHT:
				h1_elem->extended.omniLightDef = mem->Alloc<H1::FxOmniLightDef>();
				// todo?
				break;
			default:
				h1_elem->extended.unknownDef = elem->extended.unknownDef;
				break;
			}

			// check:
			h1_elem->sortOrder = elem->sortOrder;
			h1_elem->lightingFrac = elem->lightingFrac;
			h1_elem->useItemClip = elem->useItemClip;
			h1_elem->fadeInfo = elem->fadeInfo;
			h1_elem->randomSeed = elem->pad; // check

			// pad
			h1_elem->__pad0; // bounds?

			h1_elem->__pad0[2] = 1.0f;
			h1_elem->__pad0[3] = 1.0f;
			h1_elem->__pad0[5] = -1.0f;
		}

		H1::FxEffectDef* GenerateH1FxEffectDef(FxEffectDef* asset, ZoneMemory* mem)
		{
			auto* h1_asset = mem->Alloc<H1::FxEffectDef>();
			h1_asset->name = asset->name;

			h1_asset->flags = asset->flags; // convert? should be the same...
			h1_asset->totalSize = asset->totalSize;
			h1_asset->msecLoopingLife = asset->msecLoopingLife;
			h1_asset->elemDefCountLooping = asset->elemDefCountLooping;
			h1_asset->elemDefCountOneShot = asset->elemDefCountOneShot;
			h1_asset->elemDefCountEmission = asset->elemDefCountEmission;
			h1_asset->elemMaxRadius = 0;
			h1_asset->occlusionQueryDepthBias = asset->occlusionQueryDepthBias;
			h1_asset->occlusionQueryFadeIn = asset->occlusionQueryFadeIn;
			h1_asset->occlusionQueryFadeOut = asset->occlusionQueryFadeOut;
			h1_asset->occlusionQueryScaleRange.base = asset->occlusionQueryScaleRange.base;
			h1_asset->occlusionQueryScaleRange.amplitude = asset->occlusionQueryScaleRange.amplitude;

			h1_asset->elemDefs = mem->Alloc<H1::FxElemDef>(asset->elemDefCountLooping + asset->elemDefCountOneShot + asset->elemDefCountEmission);
			for (auto i = 0; i < asset->elemDefCountLooping + asset->elemDefCountOneShot + asset->elemDefCountEmission; i++)
			{
				GenerateH1FxElemDef(&h1_asset->elemDefs[i], &asset->elemDefs[i], mem);
			}

			return h1_asset;
		}*/

		void IFxEffectDef::dump(FxEffectDef* asset, ZoneMemory* mem)
		{
			/*// generate h1 fx
			auto* h1_asset = GenerateH1FxEffectDef(asset, mem);

			// dump fx
			H1::IFxEffectDef::dump(h1_asset);*/
		}
	}
}