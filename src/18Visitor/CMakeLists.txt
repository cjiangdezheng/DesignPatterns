IF(MSVC) 

	ADD_DEFINITIONS(-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE)
	ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)
	SET(CMAKE_MFC_FLAG 2) 

ELSE(MSVC)

	SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall -O2 -fno-strict-aliasing")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wall -O2 -fno-strict-aliasing")

ENDIF(MSVC) 

set(Visitor_SRCS
	stdafx.cpp
	stdafx.h
	BaseVisitor.cpp
	BaseVisitor.h
	CommonEmployee.cpp
	CommonEmployee.h
	Employee.cpp
	Employee.h
	IVisitor.h
	Manager.cpp
	Manager.h
	Visitor.cpp

)

set(Visitor_SRCS_W
	targetver.h
	
)
set(Visitor_SRCS_U
#	XXX.cpp
)




include_directories(
	${PROJECT_SOURCE_DIR}/18Visitor
	)

	

IF(WIN32)
	ADD_EXECUTABLE(Visitor ${Visitor_SRCS} ${Visitor_SRCS_W})   
ELSE(WIN32)
	ADD_EXECUTABLE(Visitor ${Visitor_SRCS} ${Visitor_SRCS_U})   
ENDIF(WIN32)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
 
