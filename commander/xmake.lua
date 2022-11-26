includes("../common")

target("commander")

    set_kind("static")
    add_files("*.c")
    add_files("container/*.c")
    add_files("commands/*.c")
    add_files("commands/*/*.c")

    add_includedirs("./",  {public = true})
    add_includedirs("container",  {public = false})
    add_includedirs("commands",  {public = false})

    add_deps("common")


