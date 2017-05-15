#include "../includes/ft_ls.h"



// a function that simply allocates the size of t_fields which is the structure in the stack elems containing all the necessary info
t_fields *alloc_fields(void)
{
	t_fields *fields;
	fields = NULL;
	if (!(fields = (t_fields *)malloc(sizeof(t_fields))))
		exit(-1);
	return (fields);
}

// This function allocates a string which represents the permissions within 
// stat buffer / st.mode
// AVOID MALLOC HERE!
char *extract_permissions_mode(struct stat fileStat)
{

    // TODO finish this function by following the logic with the printfs, but instead of
    // outputting the permission, return a string with the permissions in them

	printf("File Permissions: \t");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");

    printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");

    return ("TEST");
}

// This function acts an extractor of information
// It extracts all the necessary information from a file by redirecting to subfunctions which will be respoinsible
// for extracting the specific information
t_fields			*get_file_info(t_stack *file)
{

	// a temp pointer for sanitary and isolated modification of the file
	t_stack *tmp;
	struct stat buf;          

	tmp = file;
	tmp->fields = alloc_fields(); // simply a function that allocates the fields in the stack element		
	if (stat(tmp->path, &buf) < 0)
		exit(-1);

	tmp->fields->mode = extract_permissions_mode(buf);

    ft_putendl(tmp->fields->mode);

	return (tmp->fields);
}