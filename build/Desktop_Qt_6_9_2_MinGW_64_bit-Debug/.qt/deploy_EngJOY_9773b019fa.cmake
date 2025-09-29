include("C:/EngJOY/EngJOY/build/Desktop_Qt_6_9_2_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/EngJOY-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "C:/EngJOY/EngJOY/build/Desktop_Qt_6_9_2_MinGW_64_bit-Debug/EngJOY.exe"
    GENERATE_QT_CONF
)
