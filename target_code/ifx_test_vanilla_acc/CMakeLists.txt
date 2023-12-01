# CMAKE file for the Apache TVM accelerator example

set(VANILLA_IRQ 20)

add_executable_etiss( ifx_test_vanilla_acc 
	main.c vanilla_acc.c 
)
target_compile_options(ifx_test_vanilla_acc PRIVATE -DVANILLA_IRQ=${VANILLA_IRQ})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(etiss_ini_file)
SET(INI_FILE ${CMAKE_CURRENT_BINARY_DIR}/ifx_test_vanilla_acc.ini)


update_config( ${INI_FILE} "Plugin VanillaAccelerator" "plugin.VanillaAccelerator.baseaddr" 0x70001000)

update_config( ${INI_FILE} "Plugin VanillaAccelerator" "plugin.VanillaAccelerator.baseaddr" 0x70001000)
update_config( ${INI_FILE} "Plugin VanillaAccelerator" "plugin.VanillaAccelerator.irqline"  ${VANILLA_IRQ})
update_config( ${INI_FILE} "BoolConfigurations"        "arch.enable_semihosting"            true)
update_config( ${INI_FILE} "BoolConfigurations"        "etiss.load_integrated_libraries"            true)

