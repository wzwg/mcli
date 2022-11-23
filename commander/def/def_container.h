#ifndef __DEF_CONTAINER_H__
#define __DEF_CONTAINER_H__

typedef void (*stream_t)(char c, char status);

/** definition of container interface
 * duty
 *  store command name and value
 *  support searching command(to get value) by name
 *  support returning possible names by input name (to support autocompletion)
*/
typedef struct {
    void *p;
    int (*add_command)(void *p, const char *name, void *data);
    void *(*find_command)(void *p, const char *name);
    // status: 1-indicate end of a name; 2- indicate end of all
    int (*get_optional_commands)(void *p, stream_t stream); 
}itf_container_t;


#endif 