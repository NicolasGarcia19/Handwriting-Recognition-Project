add_library(pa5-sys-lib
    ece2400-stdlib.cc
    HRSBinarySearch.cc
    HRSLinearSearch.cc
    HRSTableSearch.cc
    HRSTreeSearch.cc
    Image.cc
    mnist-utils.cc
)

function(add_pa_exec bin srcs)
  add_executable(${bin} ${srcs})
  target_link_libraries(${bin} PUBLIC
    pa5-sys-lib
    m # math
  )
endfunction()

add_pa_exec(image-adhoc image-adhoc.cc)
add_pa_exec(sort-adhoc sort-adhoc.cc)
add_pa_exec(table-adhoc table-adhoc.cc)
add_pa_exec(tree-adhoc tree-adhoc.cc)
add_pa_exec(vector-adhoc vector-adhoc.cc)

function(add_pa_test bin srcs)
  add_pa_exec(${bin} ${srcs})
  add_test(NAME ${bin}
         COMMAND ${bin})
endfunction()
