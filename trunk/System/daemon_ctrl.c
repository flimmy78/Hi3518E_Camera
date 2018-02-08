#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CONFIG_APPS_WDT
#ifdef CONFIG_APPS_WDT

#define COMMAND_SIZE 256
#define CONSOLE_NAME_SIZE 32
#define MAXENV	16		/* Number of env. vars */

/*���̼�ع��ܵ���غ궨��*/
#define PS_COMMAND "ps -a"  
#define SCAN(buf) (sscanf(buf,"%d %s %s %s",pid,s[0],s[1],cmd) == 4) 
#define UPGPROC_NUM 4               /*������ؽ��̵���Ŀ*/
#define KEYPROC_NUM 3               /*����ؽ��̵���Ŀ*/
#define PSLINE_LENGTH 256           /*PS����һ����ʾ������ַ���*/
#define PROCNAME_LENGTH 30          /*�������Ƶ�����ַ���*/
#define PIDNUMBER 1                 /*��Ҫ���ҵ��������н��̸���(ͬһ�����ж��pid�����)*/
#define PS_ASSISTITEM_NUM 3         /*PS�����г���pid�������֮���������Եĸ���*/
#define PS_ASSISTITEM_LENGTH 32     /*PS�����г���pid�������֮������������������ַ���*/
static int proc_monitor(char *process);

static int lookup_pid(char *name, pid_t *pids, int n)  
{  
    FILE *fp;  
    char buf[PSLINE_LENGTH], cmd[PROCNAME_LENGTH], s[PS_ASSISTITEM_NUM][PS_ASSISTITEM_LENGTH];  
    pid_t *pid;  
   
    if ((fp = popen(PS_COMMAND, "r")) == NULL)  
        return -1;
   
    pid = pids;  
    while (n > 0 && fgets(buf, sizeof(buf), fp))  
        if (SCAN(buf) && strstr(cmd, name))
            pid++, n--;  
   
    pclose(fp);  
    return pid - pids;  
}  

static int proc_monitor(char *process)  
{  
    pid_t pids[PIDNUMBER];  
    int n, i = 0;  
   
    if ((n = lookup_pid(process, pids, PIDNUMBER)) == -1) {  
        printf("Error reading pid of %s %d!",process, pids[i]);
        return -1;  
    }  
	
    return n;  
}

int main(int argc, char* argv[])
{
	int procnum,procexist;

	/*�ؼ��������鶨�壬
	  ��չ��ü���ʱ��ֻ��Ҫ�޸Ĵ˴��ľ���������ƣ����޸ĺ궨�弴��*/
	char key_proc[KEYPROC_NUM][PROCNAME_LENGTH]={"boa" ,"zero_cmd_ether", "rpc_stream"};

	while(1)
	{
		procexist = 0;
		for(procnum=0;procnum < KEYPROC_NUM;procnum++)
		{
			procexist = proc_monitor(key_proc[procnum]);
			if(procexist < 1 )
			{
				//sleep(5);
				if(procnum == 0)
					system("/usr/sbin/boa&");
				else if(procnum == 1)
					system("/usr/bin/zero_cmd_ether&");	
				else if(procnum == 2)
					system("/usr/bin/rpc_stream&");	
			}					
		}
		sleep(1000 * 3);
	}


	return 0;
}
#endif


