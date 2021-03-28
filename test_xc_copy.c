#include "xs.h"

static void print_xs_info(xs *s, char *name)
{
	printf("%s, address: %p, ref_count: %d\nstring: %s\n", name, xs_data(s), xs_get_refcnt(s), xs_data(s));
	return;
}

int main(int argc, char *argv[])
{
	//xs string = *xs_tmp("foobarbarfoobarbarfoobarbar");
	xs string = *xs_tmp("foobarbarfoobarfoobarbarfoobarfoobarbarfoobarfoobarbarfoobarfoobarbarfoobarfoobarbarfoobarfoobarbarfoobarfoobarbarfoobarfoobarbarfoobarfoobarbarfoobarfoobarbarfoobarfoobarbarfoobarfoobarbarfoobarfoobarbarfoobarfoobarbarfoobarfoobarbarfoobarfoobarbarfoobarfoobarbarfoobar");
	xs copyString;
    xs_copy(&copyString, &string);
    print_xs_info(&string, "org");
    print_xs_info(&copyString, "cpy");

    xs prefix = *xs_tmp("((("), suffix = *xs_tmp(")))");
    xs_concat(&copyString, &prefix, &suffix);
    print_xs_info(&string, "org");
    print_xs_info(&copyString, "cpy_after_modify");
	/*
    xs string = *xs_tmp("\n foobarbar \n\n\n");
    xs_trim(&string, "\n ");
    printf("[%s] : %2zu\n", xs_data(&string), xs_size(&string));

    xs prefix = *xs_tmp("((("), suffix = *xs_tmp(")))");
    xs_concat(&string, &prefix, &suffix);
    printf("[%s] : %2zu\n", xs_data(&string), xs_size(&string));
    */
    return 0;
}