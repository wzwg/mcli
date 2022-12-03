target("base")
    set_kind("static")
    add_cflags("-pedantic", "-Wall", "-Werror", "-pedantic-errors", {force=true})

    add_files("*.c")
    add_includedirs("./",  {public = true})

