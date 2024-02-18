# 
# ALI SAHBAZ
#
# 
# MY DESIGN PATTERNS WORKSHOP 
#
# Date          : 17.02.2024
# By            : Ali Şahbaz
# e-mail        : ali_sahbaz@outlook.com 
#
  

set(SOURCES
    main.cpp
    app/circle_draw.cpp
    app/square_draw.cpp
)

include_directories(app)
include_directories(service)

add_executable(main ${SOURCES}  )
 