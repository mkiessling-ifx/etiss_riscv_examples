
function(update_config EIF_FILE EIF_SECTION EIF_TOPIC EIF_VALUE)

    if(NOT EXISTS ${EIF_FILE})
        message(FATAL_ERROR "*** ERROR: File: " ${EIF_FILE} " does not exist!")
    endif()

    set (EXECUTE_COMMAND python ${CMAKE_SOURCE_DIR}/cmake/configupdate.py ${EIF_FILE} ${EIF_SECTION} ${EIF_TOPIC} ${EIF_VALUE})

    execute_process(COMMAND ${EXECUTE_COMMAND} RESULT_VARIABLE rv)
    if(${rv})
        message(FATAL_ERROR "configupdate.py returns error: " ${rv} )
    endif()
endfunction()

