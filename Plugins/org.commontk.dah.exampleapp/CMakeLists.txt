PROJECT(org_commontk_dah_exampleapp)

SET(PLUGIN_export_directive "org_commontk_example_dicomapp_EXPORT")

SET(PLUGIN_SRCS
  ctkExampleDicomAppLogic_p.h
  ctkExampleDicomAppPlugin_p.h
  ctkExampleDicomAppLogic.cpp
  ctkExampleDicomAppPlugin.cpp
)

# Files which should be processed by Qts moc
SET(PLUGIN_MOC_SRCS
  ctkExampleDicomAppLogic_p.h
  ctkExampleDicomAppPlugin_p.h
)

# Qt Designer files which should be processed by Qts uic
SET(PLUGIN_UI_FORMS
)

# QRC Files which should be compiled into the plugin
SET(PLUGIN_resources
)

#Compute the plugin dependencies
ctkMacroGetTargetLibraries(PLUGIN_target_libraries)

ctkMacroBuildPlugin(
  NAME ${PROJECT_NAME}
  EXPORT_DIRECTIVE ${PLUGIN_export_directive}
  SRCS ${PLUGIN_SRCS}
  MOC_SRCS ${PLUGIN_MOC_SRCS}
  UI_FORMS ${PLUGIN_UI_FORMS}
  RESOURCES ${PLUGIN_resources}
  TARGET_LIBRARIES ${PLUGIN_target_libraries}
)
