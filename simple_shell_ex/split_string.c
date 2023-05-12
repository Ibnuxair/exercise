/**
 * split_string - split a string into an array of words
 * @str: the string to split
 * @delim: the delimiter character
 *
 * Return: an array of words
 */

char **split_string(char *str, const char *delim)
{
	int i, j, len;
	int tokens_num = 0, in_token = 0;
	char **tokens = NULL;
	char *token = NULL;

	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (strchr(delim, str[i]) != NULL)
		{
			if (in_token)
			{
				tokens_num++;
				in_token = 0;
			}
		}
		else
		{
			if (!in_token)
			{
				tokens_num++;
				in_token = 1;
			}
		}
	}
	if (in_token)
		tokens_num++;

	tokens = malloc(sizeof(char *) * (tokens_num + 1));
	if (tokens == NULL) {
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	in_token = 0;
	j = 0;
	for (i = 0; i < len; i++)
	{
		if (strchr(delim, str[i]) != NULL)
		{
			if (in_token)
			{
				in_token = 0;
				token[j] = '\0';
				j = 0;
				tokens[num_tokens - 1] = token;
				token = NULL;
			}
		}
		else
		{
			if (!in_token)
			{
				in_token = 1;
				token = malloc(sizeof(char) * (len - i + 1));
				if (token == NULL)
				{
					perror("Memory allocation error");
					exit(EXIT_FAILURE);
				}
			}
			token[j++] = str[i];
		}
	}
	if (in_token)
	{
		token[j] = '\0';
		tokens[tokens_num - 1] = token;
	}
	tokens[tokens_num] = NULL;

	return tokens;
}
