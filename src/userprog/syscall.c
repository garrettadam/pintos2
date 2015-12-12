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
bool is_valid_ptr(const void *vaddr); 

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
			printf("exit");
			break;

		case SYS_EXEC:
			printf("execute call");
			break;

		case SYS_WAIT:
			printf("wait");
			break;

		case SYS_CREATE:
			printf("create");
			break;

		case SYS_REMOVE:
			printf("remove");
			break;

		case SYS_OPEN:
			printf("open");
			break;

		case SYS_FILESIZE:
			printf("filesize");
			break;

		case SYS_READ:
			printf("read");
			break;

		case SYS_WRITE:
			printf("write");
			break;

		case SYS_SEEK:
			printf("seek");
			break;

		case SYS_TELL:
			printf("tell");
			break;

		case SYS_CLOSE:
			printf("close");
			break;

		default:
			printf("default");
			exit(-1);
			break;
	}
	thread_exit();
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

int write(int fd, const void *buffer, unsigned size){

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
