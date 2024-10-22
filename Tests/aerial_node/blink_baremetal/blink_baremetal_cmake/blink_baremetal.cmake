set(SDK_PATH "C:/Users/t1nou/SimplicityStudio/SDKs/simplicity_sdk")
set(COPIED_SDK_PATH "simplicity_sdk_2024.6.2")

add_library(slc_blink_baremetal OBJECT
    "${SDK_PATH}/hardware/board/src/sl_board_control_gpio.c"
    "${SDK_PATH}/hardware/board/src/sl_board_init.c"
    "${SDK_PATH}/hardware/driver/configuration_over_swo/src/sl_cos.c"
    "${SDK_PATH}/platform/common/src/sl_assert.c"
    "${SDK_PATH}/platform/common/src/sl_core_cortexm.c"
    "${SDK_PATH}/platform/common/src/sl_syscalls.c"
    "${SDK_PATH}/platform/Device/SiliconLabs/EFR32MG22/Source/startup_efr32mg22.c"
    "${SDK_PATH}/platform/Device/SiliconLabs/EFR32MG22/Source/system_efr32mg22.c"
    "${SDK_PATH}/platform/driver/debug/src/sl_debug_swo.c"
    "${SDK_PATH}/platform/driver/leddrv/src/sl_led.c"
    "${SDK_PATH}/platform/driver/leddrv/src/sl_simple_led.c"
    "${SDK_PATH}/platform/emlib/src/em_burtc.c"
    "${SDK_PATH}/platform/emlib/src/em_cmu.c"
    "${SDK_PATH}/platform/emlib/src/em_core.c"
    "${SDK_PATH}/platform/emlib/src/em_emu.c"
    "${SDK_PATH}/platform/emlib/src/em_gpio.c"
    "${SDK_PATH}/platform/emlib/src/em_msc.c"
    "${SDK_PATH}/platform/emlib/src/em_rtcc.c"
    "${SDK_PATH}/platform/emlib/src/em_system.c"
    "${SDK_PATH}/platform/emlib/src/em_timer.c"
    "${SDK_PATH}/platform/service/clock_manager/src/sl_clock_manager.c"
    "${SDK_PATH}/platform/service/clock_manager/src/sl_clock_manager_hal_s2.c"
    "${SDK_PATH}/platform/service/clock_manager/src/sl_clock_manager_init.c"
    "${SDK_PATH}/platform/service/clock_manager/src/sl_clock_manager_init_hal_s2.c"
    "${SDK_PATH}/platform/service/device_init/src/sl_device_init_dcdc_s2.c"
    "${SDK_PATH}/platform/service/device_init/src/sl_device_init_emu_s2.c"
    "${SDK_PATH}/platform/service/device_manager/clocks/sl_device_clock_efr32xg22.c"
    "${SDK_PATH}/platform/service/device_manager/devices/sl_device_peripheral_hal_efr32xg22.c"
    "${SDK_PATH}/platform/service/device_manager/src/sl_device_clock.c"
    "${SDK_PATH}/platform/service/device_manager/src/sl_device_peripheral.c"
    "${SDK_PATH}/platform/service/interrupt_manager/src/sl_interrupt_manager_cortexm.c"
    "${SDK_PATH}/platform/service/memory_manager/src/sl_memory_manager_region.c"
    "${SDK_PATH}/platform/service/sleeptimer/src/sl_sleeptimer.c"
    "${SDK_PATH}/platform/service/sleeptimer/src/sl_sleeptimer_hal_burtc.c"
    "${SDK_PATH}/platform/service/sleeptimer/src/sl_sleeptimer_hal_prortc.c"
    "${SDK_PATH}/platform/service/sleeptimer/src/sl_sleeptimer_hal_rtcc.c"
    "${SDK_PATH}/platform/service/sleeptimer/src/sl_sleeptimer_hal_timer.c"
    "${SDK_PATH}/platform/service/system/src/sl_system_init.c"
    "${SDK_PATH}/platform/service/system/src/sl_system_process_action.c"
    "../app.c"
    "../autogen/sl_board_default_init.c"
    "../autogen/sl_event_handler.c"
    "../autogen/sl_simple_led_instances.c"
    "../blink.c"
    "../main.c"
)

target_include_directories(slc_blink_baremetal PUBLIC
   "../config"
   "../autogen"
   "../."
    "${SDK_PATH}/platform/Device/SiliconLabs/EFR32MG22/Include"
    "${SDK_PATH}/platform/common/inc"
    "${SDK_PATH}/hardware/board/inc"
    "${SDK_PATH}/platform/service/clock_manager/inc"
    "${SDK_PATH}/platform/service/clock_manager/src"
    "${SDK_PATH}/platform/CMSIS/Core/Include"
    "${SDK_PATH}/hardware/driver/configuration_over_swo/inc"
    "${SDK_PATH}/platform/driver/debug/inc"
    "${SDK_PATH}/platform/service/device_manager/inc"
    "${SDK_PATH}/platform/service/device_init/inc"
    "${SDK_PATH}/platform/emlib/inc"
    "${SDK_PATH}/platform/service/interrupt_manager/inc"
    "${SDK_PATH}/platform/service/interrupt_manager/inc/arm"
    "${SDK_PATH}/platform/driver/leddrv/inc"
    "${SDK_PATH}/platform/service/memory_manager/inc"
    "${SDK_PATH}/platform/common/toolchain/inc"
    "${SDK_PATH}/platform/service/system/inc"
    "${SDK_PATH}/platform/service/sleeptimer/inc"
)

target_compile_definitions(slc_blink_baremetal PUBLIC
    "DEBUG_EFM=1"
    "EFR32MG22E224F512IM40=1"
    "HARDWARE_BOARD_DEFAULT_RF_BAND_2400=1"
    "HARDWARE_BOARD_SUPPORTS_1_RF_BAND=1"
    "HARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1"
    "HFXO_FREQ=38400000"
    "SL_BOARD_NAME=\"BRD4002A\""
    "SL_BOARD_REV=\"A07\""
    "SL_COMPONENT_CATALOG_PRESENT=1"
    "CMSIS_NVIC_VIRTUAL=1"
    "CMSIS_NVIC_VIRTUAL_HEADER_FILE=\"cmsis_nvic_virtual.h\""
    "SL_CODE_COMPONENT_CORE=core"
    "SL_CODE_COMPONENT_SLEEPTIMER=sleeptimer"
)

target_link_libraries(slc_blink_baremetal PUBLIC
    "-Wl,--start-group"
    "gcc"
    "c"
    "m"
    "nosys"
    "-Wl,--end-group"
)
target_compile_options(slc_blink_baremetal PUBLIC
    $<$<COMPILE_LANGUAGE:C>:-mcpu=cortex-m33>
    $<$<COMPILE_LANGUAGE:C>:-mthumb>
    $<$<COMPILE_LANGUAGE:C>:-mfpu=fpv5-sp-d16>
    $<$<COMPILE_LANGUAGE:C>:-mfloat-abi=hard>
    $<$<COMPILE_LANGUAGE:C>:-Wall>
    $<$<COMPILE_LANGUAGE:C>:-Wextra>
    $<$<COMPILE_LANGUAGE:C>:-Os>
    $<$<COMPILE_LANGUAGE:C>:-fdata-sections>
    $<$<COMPILE_LANGUAGE:C>:-ffunction-sections>
    $<$<COMPILE_LANGUAGE:C>:-fomit-frame-pointer>
    "$<$<COMPILE_LANGUAGE:C>:SHELL:-imacros sl_gcc_preinclude.h>"
    $<$<COMPILE_LANGUAGE:C>:-mcmse>
    $<$<COMPILE_LANGUAGE:C>:--specs=nano.specs>
    $<$<COMPILE_LANGUAGE:C>:-g>
    $<$<COMPILE_LANGUAGE:CXX>:-mcpu=cortex-m33>
    $<$<COMPILE_LANGUAGE:CXX>:-mthumb>
    $<$<COMPILE_LANGUAGE:CXX>:-mfpu=fpv5-sp-d16>
    $<$<COMPILE_LANGUAGE:CXX>:-mfloat-abi=hard>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    $<$<COMPILE_LANGUAGE:CXX>:-Wall>
    $<$<COMPILE_LANGUAGE:CXX>:-Wextra>
    $<$<COMPILE_LANGUAGE:CXX>:-Os>
    $<$<COMPILE_LANGUAGE:CXX>:-fdata-sections>
    $<$<COMPILE_LANGUAGE:CXX>:-ffunction-sections>
    $<$<COMPILE_LANGUAGE:CXX>:-fomit-frame-pointer>
    "$<$<COMPILE_LANGUAGE:CXX>:SHELL:-imacros sl_gcc_preinclude.h>"
    $<$<COMPILE_LANGUAGE:CXX>:-mcmse>
    $<$<COMPILE_LANGUAGE:CXX>:--specs=nano.specs>
    $<$<COMPILE_LANGUAGE:CXX>:-g>
    $<$<COMPILE_LANGUAGE:ASM>:-mcpu=cortex-m33>
    $<$<COMPILE_LANGUAGE:ASM>:-mthumb>
    $<$<COMPILE_LANGUAGE:ASM>:-mfpu=fpv5-sp-d16>
    $<$<COMPILE_LANGUAGE:ASM>:-mfloat-abi=hard>
    "$<$<COMPILE_LANGUAGE:ASM>:SHELL:-imacros sl_gcc_preinclude.h>"
    "$<$<COMPILE_LANGUAGE:ASM>:SHELL:-x assembler-with-cpp>"
)

set(post_build_command )
set_property(TARGET slc_blink_baremetal PROPERTY C_STANDARD 17)
set_property(TARGET slc_blink_baremetal PROPERTY CXX_STANDARD 17)
set_property(TARGET slc_blink_baremetal PROPERTY CXX_EXTENSIONS OFF)

target_link_options(slc_blink_baremetal INTERFACE
    -mcpu=cortex-m33
    -mthumb
    -mfpu=fpv5-sp-d16
    -mfloat-abi=hard
    -T${CMAKE_CURRENT_LIST_DIR}/../autogen/linkerfile.ld
    --specs=nano.specs
    "SHELL:-Xlinker -Map=$<TARGET_FILE_DIR:blink_baremetal>/blink_baremetal.map"
    -Wl,--gc-sections
    -Wl,--no-warn-rwx-segments
)

# BEGIN_SIMPLICITY_STUDIO_METADATA=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END_SIMPLICITY_STUDIO_METADATA
