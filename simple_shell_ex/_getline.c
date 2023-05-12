char *_getline(void) {
	char *lineptr = NULL;
	size_t len = 0;
	ssize_t nch_read;

	nch_read = getline(&line, &len, stdin);
	if (nread == -1)
	{
		// an error occurred or end-of-file was reached
		free(lineptr);
		return (NULL);
	}

	// remove the trailing newline character, if present
	if (lineptr[nch_read-1] == '\n')
		lineptr[nch_read-1] = '\0';

	return (lineptr);
}
