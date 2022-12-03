includes("../common")

target("controller")

    set_kind("static")
    add_files("*.c")

    add_includedirs("./",  {public = true})

    add_deps("common")
    add_deps("commander")



