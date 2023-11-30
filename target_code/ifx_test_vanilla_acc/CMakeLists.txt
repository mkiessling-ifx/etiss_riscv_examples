# CMAKE file for the Apache TVM accelerator example

set(VANILLA_IRQ 20)

add_executable_etiss( ifx_test_vanilla_acc 
	main.c vanilla_acc.c 
)
target_compile_options(ifx_test_vanilla_acc PRIVATE -DVANILLA_IRQ=${VANILLA_IRQ})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(etiss_ini_file)
SET(INI_FILE ${CMAKE_CURRENT_BINARY_DIR}/ifx_test_vanilla_acc.ini)

update_config( FILE ${INI_FILE} SECTION "Plugin VanillaAccelerator" TOPIC "plugin.VanillaAccelerator.baseaddr" VALUE 0x70001000)
update_config( FILE ${INI_FILE} SECTION "Plugin VanillaAccelerator" TOPIC "plugin.VanillaAccelerator.irqline"  VALUE ${VANILLA_IRQ})
update_config( FILE ${INI_FILE} SECTION "BoolConfigurations"        TOPIC "arch.enable_semihosting"            VALUE true)
