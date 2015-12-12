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
	int arg1, arg2, arg3;
	int sys_num = (*(int *)f->esp);
	switch(sys_num)
	{
		case SYS_HALT:
			halt();
			break;
	
		case SYS_EXIT:
			break;

		case SYS_EXEC:
			break;

		case SYS_WAIT:
			break;

		case SYS_CREATE:
			break;

		case SYS_REMOVE:
			break;

		case SYS_OPEN:
			break;

		case SYS_FILESIZE:
			break;

		case SYS_READ:
			break;

		case SYS_WRITE:
			break;

		case SYS_SEEK:
			break;

		case SYS_TELL:
			break;

		case SYS_CLOSE:
			break;

		default:
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
}

pid_t exec(const char *cmd_line)
{
}

int wait(pid_t pid)
{
	while(1)
	{
	}	

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
