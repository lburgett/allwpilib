// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "hal/simulation/PDPData.h"

#include "../PortsInternal.h"
#include "hal/simulation/SimDataValue.h"

extern "C" {
void HALSIM_ResetPDPData(int32_t index) {}

#define DEFINE_CAPI(TYPE, CAPINAME, RETURN) \
  HAL_SIMDATAVALUE_STUB_CAPI(TYPE, HALSIM, PDP##CAPINAME, RETURN)

DEFINE_CAPI(HAL_Bool, Initialized, false)
DEFINE_CAPI(double, Temperature, 0)
DEFINE_CAPI(double, Voltage, 0)
HAL_SIMDATAVALUE_STUB_CAPI_CHANNEL(double, HALSIM, PDPCurrent, 0)

void HALSIM_GetPDPAllCurrents(int32_t index, double* currents) {
  for (int i = 0; i < hal::kNumPDPChannels; i++) {
    currents[i] = 0;
  }
}

void HALSIM_SetPDPAllCurrents(int32_t index, const double* currents) {}

void HALSIM_RegisterPDPAllNonCurrentCallbacks(int32_t index, int32_t channel,
                                              HAL_NotifyCallback callback,
                                              void* param,
                                              HAL_Bool initialNotify) {}
}  // extern "C"
