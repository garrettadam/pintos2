#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"
#include "devices/shutdown.h"
#include "threads/vaddr.h"
 
static void syscall_handler (struct intr_frame *);
// Syscall Function prototypes
void halt(void);
void exit(int status);
pid_t exec(const char *cmd_line );
int wait(pid_t pid);
bool create(const char *file, unsigned initial_size);
bool remove(const char *file);
int open(const char *file);
int filesize(int fd);
int read(int fd, void *buffer, unsigned size);
int write(int fd, const void *buffer, unsigned size);
void seek(int fd, unsigned position);
unsigned tell(int fd);
void close(int fd);
// Helper function prototypes
bool is_valid_ptr(const void *vaddr); // Checks to see that ptr is pointing to user space addr
int argument(struct intr_frame *f, int num);// Gets argument from stack, num is the argument number 1-3
void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f) 
{
	printf("System call!");
	int arg1, arg2, arg3;
	int sys_num = (*(int *)f->esp);
	switch(sys_num)
	{
		case SYS_HALT:
			halt();
			printf("halt");
			break;
	
		case SYS_EXIT:
			arg1 = argument(f, 1);
			exit(arg1);
			break;

		case SYS_EXEC:
			arg1 = argument(f, 1);
			
			break;

		case SYS_WAIT:
			arg1 = argument(f, 1);
			break;

		case SYS_CREATE:
			arg1 = argument(f, 1);
			arg2 = argument(f, 2);
			
			break;

		case SYS_REMOVE:
			arg1 = argument(f, 1);
			break;

		case SYS_OPEN:
			arg1 = argument(f, 1);
			break;

		case SYS_FILESIZE:
			arg1 = argument(f, 1);
			break;

		case SYS_READ:
			arg1 = argument(f, 1);
			arg2 = argument(f, 2);
			arg3 = argument(f, 3);
			break;

		case SYS_WRITE:
			arg1 = argument(f, 1);
			arg2 = argument(f, 2);
			arg3 = argument(f, 3);	
			break;

		case SYS_SEEK:
			arg1 = argument(f, 1);
			arg2 = argument(f, 2);
			break;

		case SYS_TELL:
			arg1 = argument(f, 1);
			break;

		case SYS_CLOSE:
			arg1 = argument(f, 1);
			break;

		default:
			printf("default");
			exit(-1);
			break;
	}
}

void halt(void)
{
	shutdown_power_off();
}

void exit(int status)
{
	struct thread* cur = thread_current();
	cur->info->ex_status = status;
	printf("%s: exit(%d)\n", cur->name, status);
	thread_exit();
}

pid_t exec(const char *cmd_line)
{
	pid_t pid;
	pid = (pid_t) process_execute(cmd_line);
	if(pid == -1)
	{
		return -1;
	}	
}

int wait(pid_t pid)
{

}

bool create(const char*file, unsigned initial_size)
{
}

bool remove(const char *file)
{
}

int open(const char *file)
{
}

int filesize(int fd)
{
}

int read(int fd, void *buffer, unsigned size)
{
}

int write(int fd, const void *buffer, unsigned size)
{
}

void seek(int fd, unsigned position)
{
}

unsigned tell(int fd)
{
}

void close(int fd)
{
}

// Checks to see if pointer is valid  
bool is_valid_ptr(const void *vaddr)
{
	if(is_user_vaddr(vaddr))
	{
		return true;
	}

	else
	{
		return false;
	}
}

// Gets argument data from stack
int argument(struct intr_frame *f, int n)
{
	return *(int *)(f->esp + (4*n));
}  
