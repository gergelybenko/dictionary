cmake_minimum_required( VERSION 3.16.3 )

set( MAIN_EXEC_NAME dictionary )

execute_process( COMMAND pg_config --includedir OUTPUT_VARIABLE PG_CONFIG_INCLUDEDIR )

# Load packages
set( Boost_USE_STATIC_LIBS ON )
find_package( Boost REQUIRED COMPONENTS date_time log )
find_package( SOCI REQUIRED )

# Create main executable
add_executable( ${MAIN_EXEC_NAME} main.cpp )

target_compile_features( ${MAIN_EXEC_NAME} PRIVATE cxx_std_17 )

target_include_directories( ${MAIN_EXEC_NAME}
    PRIVATE ${SOCI_INCLUDE_DIRS}
    PRIVATE ${PG_CONFIG_INCLUDEDIR}
)

target_link_libraries( ${MAIN_EXEC_NAME}
    PRIVATE Boost::log
    PRIVATE SOCI::soci_core
    PRIVATE SOCI::soci_postgresql
)
