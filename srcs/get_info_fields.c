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


// this function simply takes the info extracted from stat and returns the owner of the file
// in the form of a string
// unfortunately malloc cannot be avoided here since we never know the exact length of the 
// username
char                 *extract_owner(struct stat buf)
{
    struct passwd *pwd;
    uid_t uid;

    uid = buf.st_uid;
    pwd = getpwuid(uid);
    return (pwd->pw_name);
}


char                *extract_group(struct stat buf)
{
    struct     group *grp;
    gid_t      gid;

    gid = buf.st_gid;
    grp = getgrgid(gid);
    return(grp->gr_name);
}

// This function allocates a string which represents the permissions within 
// stat buffer / st.mode
// AVOID MALLOC HERE!
void                extract_permissions_mode(struct stat buf, char *string)
{
    string[0] = *((S_ISDIR(buf.st_mode)) ? "d" : "-");
    string[1] = *((buf.st_mode & S_IRUSR) ? "r" : "-");
    string[2] = *((buf.st_mode & S_IWUSR) ? "w" : "-");
    string[3] = *((buf.st_mode & S_IXUSR) ? "x" : "-");
    string[4] = *((buf.st_mode & S_IRGRP) ? "r" : "-");
    string[5] = *((buf.st_mode & S_IWGRP) ? "w" : "-");
    string[6] = *((buf.st_mode & S_IXGRP) ? "x" : "-");
    string[7] = *((buf.st_mode & S_IROTH) ? "r" : "-");
    string[8] = *((buf.st_mode & S_IWOTH) ? "w" : "-");
    string[9] = *((buf.st_mode & S_IXOTH) ? "x" : "-");
    string[10] = '\0';

    // Use the S_ISLINK function later
   // printf("The file %s a symbolic link\n", (S_ISLNK(buf.st_mode)) ? "is" : "is not");
}

// gets the size of the file
char                *extract_file_size(struct stat buf)
{
    char *file_size;

    file_size = NULL;
    if (!(file_size = ft_itoa(buf.st_size)))
        exit (-1);
    return (file_size);
}

// gets the number of hard links into a string
char                *extract_nbr_of_links(struct stat buf)
{
    char *nbr_links;

    nbr_links = NULL;
    if (!(nbr_links = ft_itoa(buf.st_nlink)))
        exit (-1);
    return (nbr_links);
}


// This function acts as an extractor of information
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
    extract_permissions_mode(buf, tmp->fields->mode);
    extract_date_time(buf, tmp->fields);
    tmp->fields->st_blocks = (long long int)buf.st_blocks;
    tmp->fields->owner = extract_owner(buf);
    tmp->fields->group = extract_group(buf);
    tmp->fields->size = extract_file_size(buf);
    tmp->fields->links = extract_nbr_of_links(buf);
	return (file->fields);
}