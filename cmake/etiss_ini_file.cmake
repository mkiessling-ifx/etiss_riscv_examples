
function(update_config)
    set(prefix EIF)
    set(singleValues FILE SECTION TOPIC VALUE)
    set(multiValues  )

    include(CMakeParseArguments)

    cmake_parse_arguments(${prefix}
                    "${flags}"
                    "${singleValues}"
                    "${multiValues}"
                    ${ARGN})

    # TODO: add some error and sanity checking ;-)                        

    set (EXECUTE_COMMAND python ${CMAKE_SOURCE_DIR}/cmake/configupdate.py ${EIF_FILE} ${EIF_SECTION} ${EIF_TOPIC} ${EIF_VALUE})

    execute_process(COMMAND ${EXECUTE_COMMAND} RESULT_VARIABLE rv)
    if(${rv})
        message(FATAL_ERROR "configupdate.py returns error: " ${rv} )
    endif()
endfunction()

