/*
 * Copyright (c) 2021-2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CAMERA_METADATA_ITEM_INFO_H
#define CAMERA_METADATA_ITEM_INFO_H

#include "camera_metadata_operator.h"

namespace OHOS {
namespace CameraStandard {
const static size_t OHOS_CAMERA_METADATA_TYPE_SIZE[META_NUM_TYPES] = {
    [META_TYPE_BYTE]     = sizeof(uint8_t),
    [META_TYPE_INT32]    = sizeof(int32_t),
    [META_TYPE_UINT32]   = sizeof(uint32_t),
    [META_TYPE_FLOAT]    = sizeof(float),
    [META_TYPE_INT64]    = sizeof(int64_t),
    [META_TYPE_DOUBLE]   = sizeof(double),
    [META_TYPE_RATIONAL] = sizeof(camera_rational_t)
};

static uint32_t g_ohosCameraSectionBounds[OHOS_SECTION_COUNT][2] = {
    [OHOS_SECTION_CAMERA_PROPERTIES]  = {OHOS_CAMERA_PROPERTIES_START, OHOS_CAMERA_PROPERTIES_END},
    [OHOS_SECTION_CAMERA_SENSOR]      = {OHOS_CAMERA_SENSOR_START, OHOS_CAMERA_SENSOR_END},
    [OHOS_SECTION_CAMERA_SENSOR_INFO] = {OHOS_CAMERA_SENSOR_INFO_START, OHOS_CAMERA_SENSOR_INFO_END},
    [OHOS_SECTION_CAMERA_STATISTICS]  = {OHOS_CAMERA_STATISTICS_START, OHOS_CAMERA_STATISTICS_END},
    [OHOS_SECTION_CAMERA_CONTROL]     = {OHOS_DEVICE_CONTROL_START, OHOS_DEVICE_CONTROL_END},
    [OHOS_SECTION_DEVICE_EXPOSURE]    = {OHOS_DEVICE_EXPOSURE_START, OHOS_DEVICE_EXPOSURE_END},
    [OHOS_SECTION_DEVICE_FOCUS]       = {OHOS_DEVICE_FOCUS_START, OHOS_DEVICE_FOCUS_END},
    [OHOS_SECTION_DEVICE_FLASH]       = {OHOS_DEVICE_FLASH_START, OHOS_DEVICE_FLASH_END},
    [OHOS_SECTION_DEVICE_ZOOM]        = {OHOS_DEVICE_ZOOM_START, OHOS_DEVICE_ZOOM_END},
    [OHOS_SECTION_STREAM_ABILITY]     = {OHOS_STREAM_ABILITY_START, OHOS_STREAM_ABILITY_END},
    [OHOS_SECTION_STREAM_JPEG]        = {OHOS_STREAM_JPEG_START, OHOS_STREAM_JPEG_END},
};

static item_info_t g_ohosCameraProperties[OHOS_CAMERA_PROPERTIES_END - OHOS_CAMERA_PROPERTIES_START] = {
    [OHOS_ABILITY_CAMERA_POSITION - OHOS_CAMERA_PROPERTIES_START] = {"cameraPosition", META_TYPE_BYTE, 1},
    [OHOS_ABILITY_CAMERA_TYPE - OHOS_CAMERA_PROPERTIES_START] = {"cameraType", META_TYPE_BYTE, 1},
    [OHOS_ABILITY_CAMERA_CONNECTION_TYPE - OHOS_CAMERA_PROPERTIES_START] = {"cameraConnectionType", META_TYPE_BYTE, 1},
};

static item_info_t g_ohosCameraSensor[OHOS_CAMERA_SENSOR_END - OHOS_CAMERA_SENSOR_START] = {
    [OHOS_SENSOR_EXPOSURE_TIME - OHOS_CAMERA_SENSOR_START] = {"exposureTime", META_TYPE_INT64, 1},
    [OHOS_SENSOR_COLOR_CORRECTION_GAINS - OHOS_CAMERA_SENSOR_START] = {"colorCorrectuonGain", META_TYPE_FLOAT, 1},
};

static item_info_t g_ohosCameraSensorInfo[OHOS_CAMERA_SENSOR_INFO_END - OHOS_CAMERA_SENSOR_INFO_START] = {
    [OHOS_SENSOR_INFO_ACTIVE_ARRAY_SIZE - OHOS_CAMERA_SENSOR_INFO_START] = {"activeArraySize", META_TYPE_INT32, -1},
    [OHOS_SENSOR_INFO_SENSITIVITY_RANGE - OHOS_CAMERA_SENSOR_INFO_START] = {"sensitivityRange", META_TYPE_INT32, -1},
    [OHOS_SENSOR_INFO_MAX_FRAME_DURATION - OHOS_CAMERA_SENSOR_INFO_START] = {"maxFrameDuration", META_TYPE_INT64, 1},
    [OHOS_SENSOR_INFO_PHYSICAL_SIZE - OHOS_CAMERA_SENSOR_INFO_START] = {"physicalSize", META_TYPE_FLOAT, 1},
    [OHOS_SENSOR_INFO_PIXEL_ARRAY_SIZE - OHOS_CAMERA_SENSOR_INFO_START] = {"pixelArraySize", META_TYPE_INT32, -1},
};

static item_info_t g_ohosCameraStatistics[OHOS_CAMERA_STATISTICS_END - OHOS_CAMERA_STATISTICS_START] = {
    [OHOS_STATISTICS_FACE_DETECT_MODE - OHOS_CAMERA_STATISTICS_START] = {"faceDetectMode", META_TYPE_BYTE, 1},
    [OHOS_STATISTICS_HISTOGRAM_MODE - OHOS_CAMERA_STATISTICS_START] = {"histogramMode", META_TYPE_BYTE, 1},
    [OHOS_STATISTICS_FACE_IDS - OHOS_CAMERA_STATISTICS_START] = {"faceIds", META_TYPE_INT32, -1},
    [OHOS_STATISTICS_FACE_LANDMARKS - OHOS_CAMERA_STATISTICS_START] = {"faceLandmarks", META_TYPE_INT32, -1},
    [OHOS_STATISTICS_FACE_RECTANGLES - OHOS_CAMERA_STATISTICS_START] = {"faceRectangles", META_TYPE_INT32, -1},
    [OHOS_STATISTICS_FACE_SCORES - OHOS_CAMERA_STATISTICS_START] = {"faceScores", META_TYPE_BYTE, -1},
};

static item_info_t g_ohosCameraControl[OHOS_DEVICE_CONTROL_END - OHOS_DEVICE_CONTROL_START] = {
    [OHOS_CONTROL_AE_ANTIBANDING_MODE - OHOS_DEVICE_CONTROL_START] = {"aeAntibandingMode", META_TYPE_BYTE, 1},
    [OHOS_CONTROL_AE_EXPOSURE_COMPENSATION - OHOS_DEVICE_CONTROL_START] =
        {"aeExposureCompensation", META_TYPE_INT32, 1},
    [OHOS_CONTROL_AE_LOCK - OHOS_DEVICE_CONTROL_START] = {"aeLock", META_TYPE_BYTE, 1},
    [OHOS_CONTROL_AE_MODE - OHOS_DEVICE_CONTROL_START] = {"aeMode", META_TYPE_BYTE, 1},
    [OHOS_CONTROL_AE_REGIONS - OHOS_DEVICE_CONTROL_START] = {"aeRegions", META_TYPE_INT32, -1},
    [OHOS_CONTROL_AE_TARGET_FPS_RANGE - OHOS_DEVICE_CONTROL_START] = {"aeTargetFpsRange", META_TYPE_INT32, -1},
    [OHOS_CONTROL_AF_MODE - OHOS_DEVICE_CONTROL_START] = {"afMode", META_TYPE_BYTE, 1},
    [OHOS_CONTROL_AF_REGIONS - OHOS_DEVICE_CONTROL_START] = {"afRegions", META_TYPE_INT32, -1},
    [OHOS_CONTROL_AF_TRIGGER - OHOS_DEVICE_CONTROL_START] = {"afTrigger", META_TYPE_BYTE, 1},
    [OHOS_CONTROL_AF_TRIGGER_ID - OHOS_DEVICE_CONTROL_START] = {"afTriggerId", META_TYPE_INT32, 1},
    [OHOS_CONTROL_AF_STATE - OHOS_DEVICE_CONTROL_START] = {"afState", META_TYPE_BYTE, 1},
    [OHOS_CONTROL_AWB_LOCK - OHOS_DEVICE_CONTROL_START] = {"awbLock", META_TYPE_BYTE, 1},
    [OHOS_CONTROL_AWB_MODE - OHOS_DEVICE_CONTROL_START] = {"awbMode", META_TYPE_BYTE, 1},
    [OHOS_CONTROL_AWB_REGIONS - OHOS_DEVICE_CONTROL_START] = {"awbRegions", META_TYPE_INT32, -1},
    [OHOS_CONTROL_AE_AVAILABLE_ANTIBANDING_MODES - OHOS_DEVICE_CONTROL_START] =
        {"aeAvailableAntibandingModes", META_TYPE_BYTE, -1},
    [OHOS_CONTROL_AE_AVAILABLE_MODES - OHOS_DEVICE_CONTROL_START] = {"aeAvailableModes", META_TYPE_BYTE, -1},
    [OHOS_CONTROL_AE_AVAILABLE_TARGET_FPS_RANGES - OHOS_DEVICE_CONTROL_START] =
        {"aeAvailableTargetFpsRanges", META_TYPE_INT32, -1},
    [OHOS_CONTROL_AE_COMPENSATION_RANGE - OHOS_DEVICE_CONTROL_START] = {"aeCompensationRange", META_TYPE_INT32, -1},
    [OHOS_CONTROL_AE_COMPENSATION_STEP - OHOS_DEVICE_CONTROL_START] = {"aeCompensationStep", META_TYPE_RATIONAL, 1},
    [OHOS_CONTROL_AF_AVAILABLE_MODES - OHOS_DEVICE_CONTROL_START] = {"afAvailableModes", META_TYPE_BYTE, -1},
    [OHOS_CONTROL_AWB_AVAILABLE_MODES - OHOS_DEVICE_CONTROL_START] = {"awbAvailableModes", META_TYPE_BYTE, -1},
    [OHOS_CONTROL_CAPTURE_MIRROR_SUPPORTED - OHOS_DEVICE_CONTROL_START] = {"mirrorSupported", META_TYPE_BYTE, 1},
    [OHOS_CONTROL_CAPTURE_MIRROR - OHOS_DEVICE_CONTROL_START] = {"mirror", META_TYPE_BYTE, 1},
};

static item_info_t g_ohosDeviceExposure[OHOS_DEVICE_EXPOSURE_END - OHOS_DEVICE_EXPOSURE_START] = {
    [OHOS_ABILITY_DEVICE_AVAILABLE_EXPOSUREMODES - OHOS_DEVICE_EXPOSURE_START] =
        {"exposureAvailableModes", META_TYPE_BYTE, -1},
    [OHOS_CONTROL_EXPOSUREMODE - OHOS_DEVICE_EXPOSURE_START] = {"exposureMode", META_TYPE_BYTE, 1},
};

static item_info_t g_ohosDeviceFocus[OHOS_DEVICE_FOCUS_END - OHOS_DEVICE_FOCUS_START] = {
    [OHOS_ABILITY_DEVICE_AVAILABLE_FOCUSMODES - OHOS_DEVICE_FOCUS_START] = {"focusAvailablesModes", META_TYPE_BYTE, -1},
    [OHOS_CONTROL_FOCUSMODE - OHOS_DEVICE_FOCUS_START] = {"focusMode", META_TYPE_BYTE, 1},
};

static item_info_t g_ohosDeviceFlash[OHOS_DEVICE_FLASH_END - OHOS_DEVICE_FLASH_START] = {
    [OHOS_ABILITY_DEVICE_AVAILABLE_FLASHMODES - OHOS_DEVICE_FLASH_START] = {"flashAvailablesModes", META_TYPE_BYTE, -1},
    [OHOS_CONTROL_FLASHMODE - OHOS_DEVICE_FLASH_START] = {"flashMode", META_TYPE_BYTE, 1},
    [OHOS_CONTROL_FLASH_STATE - OHOS_DEVICE_FLASH_START] = {"flashstate", META_TYPE_BYTE, 1},
};

static item_info_t g_ohosDeviceZoom[OHOS_DEVICE_ZOOM_END - OHOS_DEVICE_ZOOM_START] = {
    [OHOS_ABILITY_ZOOM_RATIO_RANGE - OHOS_DEVICE_ZOOM_START] = {"zoomRange", META_TYPE_FLOAT, -1},
    [OHOS_CONTROL_ZOOM_RATIO - OHOS_DEVICE_ZOOM_START] = {"zoomRatio", META_TYPE_FLOAT, 1},
    [OHOS_CONTROL_ZOOM_CROP_REGION - OHOS_DEVICE_ZOOM_START] = {"zoomCropRegion", META_TYPE_INT32, -1},
    [OHOS_ABILITY_ZOOM_CAP - OHOS_DEVICE_ZOOM_START] = {"zoomCap", META_TYPE_INT32, -1},
    [OHOS_ABILITY_SCENE_ZOOM_CAP - OHOS_DEVICE_ZOOM_START] = {"sceneZoomCap", META_TYPE_INT32, -1},
};

static item_info_t g_ohosStreamAbility[OHOS_STREAM_ABILITY_END - OHOS_STREAM_ABILITY_START] = {
    [OHOS_ABILITY_STREAM_AVAILABLE_BASIC_CONFIGURATIONS - OHOS_STREAM_ABILITY_START] =
        {"streamAvailableConfigurations", META_TYPE_INT32, -1},
    [OHOS_STREAM_AVAILABLE_FORMATS - OHOS_STREAM_ABILITY_START] = {"streamAvailableFormats", META_TYPE_INT32, -1},
};

static item_info_t g_ohosStreamJpeg[OHOS_STREAM_JPEG_END - OHOS_STREAM_JPEG_START] = {
    [OHOS_JPEG_GPS_COORDINATES - OHOS_STREAM_JPEG_START] = {"gpsCoordinates", META_TYPE_DOUBLE, -1},
    [OHOS_JPEG_GPS_PROCESSING_METHOD - OHOS_STREAM_JPEG_START] = {"gpsProcessingMethod", META_TYPE_BYTE, 1},
    [OHOS_JPEG_GPS_TIMESTAMP - OHOS_STREAM_JPEG_START] = {"gpsTimestamp", META_TYPE_INT64, 1},
    [OHOS_JPEG_ORIENTATION - OHOS_STREAM_JPEG_START] = {"orientation", META_TYPE_INT32, 1},
    [OHOS_JPEG_QUALITY - OHOS_STREAM_JPEG_START] = {"quality", META_TYPE_BYTE, 1},
    [OHOS_JPEG_THUMBNAIL_QUALITY - OHOS_STREAM_JPEG_START] = {"thumbnailQuality", META_TYPE_BYTE, 1},
    [OHOS_JPEG_THUMBNAIL_SIZE - OHOS_STREAM_JPEG_START] = {"thumbnailSize", META_TYPE_INT32, -1},
    [OHOS_JPEG_AVAILABLE_THUMBNAIL_SIZES - OHOS_STREAM_JPEG_START] = {"availableThumbnailSizes", META_TYPE_INT32, -1},
    [OHOS_JPEG_MAX_SIZE - OHOS_STREAM_JPEG_START] = {"maxSize", META_TYPE_INT32, 1},
    [OHOS_JPEG_SIZE - OHOS_STREAM_JPEG_START] = {"size", META_TYPE_INT32, 1},
};

const static item_info_t *g_ohosItemInfo[OHOS_SECTION_COUNT] = {
    g_ohosCameraProperties,
    g_ohosCameraSensor,
    g_ohosCameraSensorInfo,
    g_ohosCameraStatistics,
    g_ohosCameraControl,
    g_ohosDeviceExposure,
    g_ohosDeviceFocus,
    g_ohosDeviceFlash,
    g_ohosDeviceZoom,
    g_ohosStreamAbility,
    g_ohosStreamJpeg,
};
} // namespace CameraStandard
} // namespace OHOS
#endif /* CAMERA_METADATA_ITEM_INFO_H */
