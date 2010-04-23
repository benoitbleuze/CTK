SET(KIT ${PROJECT_NAME})

CREATE_TEST_SOURCELIST(Tests ${KIT}CppTests.cxx
  ctkAddRemoveComboBoxTest1.cpp
  ctkButtonGroupTest1.cpp
  ctkCollapsibleButtonTest1.cpp
  ctkCollapsibleGroupBoxTest1.cpp
  ctkColorPickerButtonTest1.cpp
  ctkCoordinatesWidgetTest1.cpp
  ctkDoubleRangeSliderTest1.cpp
  ctkDoubleSliderTest1.cpp
  ctkFittedTextBrowserTest1.cpp
  ctkMatrixWidgetTest1.cpp
  ctkRangeSliderTest1.cpp
  ctkSliderSpinBoxWidgetTest1.cpp
  ctkTitleComboBoxTest1.cpp
  ctkTreeComboBoxTest1.cpp
  #EXTRA_INCLUDE TestingMacros.h
  )

SET (TestsToRun ${Tests})
REMOVE (TestsToRun ${KIT}CppTests.cxx)

SET(LIBRARY_NAME ${PROJECT_NAME})

ADD_EXECUTABLE(${KIT}CppTests ${Tests})
TARGET_LINK_LIBRARIES(${KIT}CppTests ${LIBRARY_NAME})

SET( KIT_TESTS ${CXX_TEST_PATH}/${KIT}CppTests)
IF(WIN32)
  SET(KIT_TESTS ${CXX_TEST_PATH}/${CMAKE_BUILD_TYPE}/${KIT}CppTests)
ENDIF(WIN32)

MACRO( SIMPLE_TEST  TESTNAME )
  ADD_TEST( ${TESTNAME} ${KIT_TESTS} ${TESTNAME} )
  SET_PROPERTY(TEST ${TESTNAME} PROPERTY LABELS ${PROJECT_NAME})
ENDMACRO( SIMPLE_TEST  )

#
# Add Tests
#

SIMPLE_TEST( ctkAddRemoveComboBoxTest1 )
SIMPLE_TEST( ctkButtonGroupTest1 )
SIMPLE_TEST( ctkCollapsibleButtonTest1 )
SIMPLE_TEST( ctkCollapsibleGroupBoxTest1 )
SIMPLE_TEST( ctkColorPickerButtonTest1 )
SIMPLE_TEST( ctkCoordinatesWidgetTest1 )
SIMPLE_TEST( ctkDoubleRangeSliderTest1 )
SIMPLE_TEST( ctkDoubleSliderTest1 )
SIMPLE_TEST( ctkFittedTextBrowserTest1 )
SIMPLE_TEST( ctkMatrixWidgetTest1 )
SIMPLE_TEST( ctkSliderSpinBoxWidgetTest1 )
SIMPLE_TEST( ctkTitleComboBoxTest1 )
SIMPLE_TEST( ctkTreeComboBoxTest1 )