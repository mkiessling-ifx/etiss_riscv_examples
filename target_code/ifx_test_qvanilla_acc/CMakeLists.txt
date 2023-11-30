string(CONCAT INI_FILE_APPEND 
	"[Plugin QVanillaAccelerator]\n"
	"plugin.QVanillaAccelerator.baseaddr=0x70000000\n"
	)

add_executable_etiss( ifx_test_qvanilla_acc 
	main.c qvanilla_acc.c 
)


