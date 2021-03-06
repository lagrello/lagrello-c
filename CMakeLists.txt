cmake_minimum_required (VERSION 2.6)
project (CGenerator)

cmake_policy(SET CMP0063 NEW)

set(CMAKE_C_VISIBILITY_PRESET default)
set(CMAKE_CXX_VISIBILITY_PRESET default)
set(CMAKE_VISIBILITY_INLINES_HIDDEN OFF)
set(CMAKE_BUILD_TYPE Debug)

find_package(OpenSSL)

if (OPENSSL_FOUND)
	message (STATUS "OPENSSL found")
	set (CMAKE_C_FLAGS "-DOPENSSL")
	include_directories(${OPENSSL_INCLUDE_DIR})
	include_directories(${OPENSSL_INCLUDE_DIRS})
	link_directories(${OPENSSL_LIBRARIES})
	message(STATUS "Using OpenSSL ${OPENSSL_VERSION}")
else() 
	message (STATUS "OpenSSL Not found.")
endif()

set(pkgName "lagrello_api")

find_package(CURL 7.58.0 REQUIRED)
if(CURL_FOUND)
	include_directories(${CURL_INCLUDE_DIR})
	set(PLATFORM_LIBRARIES ${PLATFORM_LIBRARIES} ${CURL_LIBRARIES} )
else(CURL_FOUND)
	message(FATAL_ERROR "Could not find the CURL library and development files.")
endif()

set(SRCS
    src/list.c
    src/apiKey.c
    src/apiClient.c
    src/binary.c
    external/cJSON.c
    model/object.c
    model/activate_tenant_request.c
    model/create_tenant_request.c
    model/create_token_request.c
    model/create_user_request.c
    model/error.c
    model/paging.c
    model/tenant.c
    model/tenant_company_info.c
    model/token.c
    model/token_list.c
    model/totp_enable_request.c
    model/totp_enable_response.c
    model/update_tenant_request.c
    model/update_user_request.c
    model/user.c
    api/AuthAPI.c
    api/ImagesAPI.c
    api/InternalAPI.c
    api/TenantsAPI.c
    api/TokensAPI.c
    api/UsersAPI.c

)

set(HDRS
    include/apiClient.h
    include/list.h
    include/binary.h
    include/keyValuePair.h
    external/cJSON.h
    model/object.h
    model/activate_tenant_request.h
    model/create_tenant_request.h
    model/create_token_request.h
    model/create_user_request.h
    model/error.h
    model/paging.h
    model/tenant.h
    model/tenant_company_info.h
    model/token.h
    model/token_list.h
    model/totp_enable_request.h
    model/totp_enable_response.h
    model/update_tenant_request.h
    model/update_user_request.h
    model/user.h
    api/AuthAPI.h
    api/ImagesAPI.h
    api/InternalAPI.h
    api/TenantsAPI.h
    api/TokensAPI.h
    api/UsersAPI.h

)

# Add library with project file with projectname as library name
add_library(${pkgName} SHARED ${SRCS} ${HDRS})
# Link dependent libraries
target_link_libraries(${pkgName} ${CURL_LIBRARIES} )
#install library to destination
install(TARGETS ${pkgName} DESTINATION ${CMAKE_INSTALL_PREFIX})

# Setting file variables to null
set(SRCS "")
set(HDRS "")


## This section shows how to use the above compiled libary to compile the source files
## set source files
#set(SRCS
#    unit-tests/manual-AuthAPI.c
#    unit-tests/manual-ImagesAPI.c
#    unit-tests/manual-InternalAPI.c
#    unit-tests/manual-TenantsAPI.c
#    unit-tests/manual-TokensAPI.c
#    unit-tests/manual-UsersAPI.c
#)

##set header files
#set(HDRS
#)

## loop over all files in SRCS variable
#foreach(SOURCE_FILE ${SRCS})
#    # Get only the file name from the file as add_executable doesnot support executable with slash("/")
#    get_filename_component(FILE_NAME_ONLY ${SOURCE_FILE} NAME_WE)
#    # Remove .c from the file name and set it as executable name
#    string( REPLACE ".c" "" EXECUTABLE_FILE ${FILE_NAME_ONLY})
#    # Add executable for every source file in  SRCS
#    add_executable(unit-${EXECUTABLE_FILE} ${SOURCE_FILE})
#    # Link above created libary to executable and dependent libary curl
#    target_link_libraries(unit-${EXECUTABLE_FILE} ${CURL_LIBRARIES} ${pkgName} )
#endforeach(SOURCE_FILE ${SRCS})
