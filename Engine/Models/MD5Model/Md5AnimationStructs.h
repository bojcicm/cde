#pragma once

#include "pch.h"
#include "Md5Structs.h"

namespace vxe {
	
	struct BoundingBoxBorders
	{
		DirectX::XMFLOAT3 min;
		DirectX::XMFLOAT3 max;
	};

	struct AnimationJointInfo
	{
		std::wstring name;
		int parentID;

		int flags;
		int startIndex;
	};
	
	struct FrameData
	{
		int frameID;
		std::vector<float> frameData;
	};

	struct FrameSkeleton
	{
		JointList joints;
	};

	typedef std::vector<BoundingBoxBorders> BoundingBoxList;
	typedef std::vector<AnimationJointInfo> AnimationJointInfoList;
	typedef std::vector<FrameData> FrameDataList;
	typedef std::vector<FrameSkeleton> FrameSkeletonList;
}