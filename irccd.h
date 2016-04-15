#ifndef IRCCD_H_INCLUDED
#define IRCCD_H_INCLUDED

/* Maximum length of some strings */
#define MAX_BUF 4096
#define MAX_LINE 1024
#define CHAN_LEN 128
/* Command definitions, might change to pure ints */
#define CONN_MOD 'c' // connect to a host
#define DISC_MOD 'd' // disconnect from a host
#define QUIT_MOD 'Q' // quit mode
#define WRITE_MOD 'w' // write to channel
#define JOIN_MOD 'j' // join channel 
#define PART_MOD 'p' // part from channel
#define LOG_MOD 'l' // log chat display
#define LIST_MOD 'L' // list channels
#define NICK_MOD 'n' // nickname mode
#define RAW_MOD 'R' // raw message to irc with no formatting

#define DEBUG 1 // toggles debug

/* linked list for all Channels */
typedef struct Channel Channel;
struct Channel {
    char *name;
    struct Channel *next;
};

typedef struct Conn_Info Conn_Info;
struct Conn_Info {
    /* Connection info */
    char host[CHAN_LEN];
    char channel[CHAN_LEN];
    unsigned int port;
    char nick[CHAN_LEN];
    char realname[CHAN_LEN];
    int sockfd; //socket
};

/* internal functions */
int spawn_reader(int sockfd);

/* The backbone of most other functions here */
int send_msg(int sockfd, char *out);
int read_msg(int sockfd, char *recvline);

/* The commands sent to this irc daemon */
int host_conn(char *server, unsigned int port, int *sockfd);
int add_chan(Channel *head, char *name);
int rm_chan(Channel *head, char *name);
void list_chan(Channel *head);


/* Utility functions */
int test_conn(int sockfd);
void kill_children(int pid, int ecode);

#endif