#include "postgres.h"

#include "fmgr.h"
#include "utils/builtins.h"

#include <stdlib.h>

PG_MODULE_MAGIC_EXT(
					.name = "random_string",
					.version = PG_VERSION
);

PG_FUNCTION_INFO_V1(generate_random_string);

#define MAX_RANDOMSTRING_LEN    1000

static const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

Datum
generate_random_string(PG_FUNCTION_ARGS)
{
	int			length = 0;
	char	   *result = NULL;
	int			charset_len = strlen(charset);

	length = PG_GETARG_INT32(0);

	if (length > MAX_RANDOMSTRING_LEN)
		ereport(WARNING,
				errmsg("Requestend length exeedes limit. It will be limited by %d",
					   MAX_RANDOMSTRING_LEN));
	else if (length < 0)
		ereport(ERROR,
				errmsg("Invalid requestend length : %d", length));

	length = Min(length, MAX_RANDOMSTRING_LEN);
	result = palloc0_array(char, length + 1);

	for (int i = 0; i < length; i++)
	{
		result[i] = charset[rand() % charset_len];
	}
	result[length] = '\0';

	PG_RETURN_TEXT_P(cstring_to_text(result));
}
