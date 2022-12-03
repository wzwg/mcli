includes("../base")

target("commander")
    set_kind("static")

    add_cflags("-pedantic", "-Wall", "-Werror", "-pedantic-errors", {force=true})
    
    add_files("*.c")
    add_files("container/*.c")

    add_includedirs("./",  {public = true})
    add_includedirs("container",  {public = false})

    add_deps("base")


