#ifndef _PING_H  
#define _PING_H  

// Не готово!

#include <iostream>  
#include <string>  
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#elif !(_WIN32)
#include <netinet/ip_icmp.h>  
#include <netdb.h>  
#include <sys/socket.h>  
#include <sys/types.h>  
#include <sys/time.h>  
#include <arpa/inet.h>  
#include <unistd.h>  
#include <signal.h>
#endif
  
#define PACKET_SIZE     4096    
#define SEND_DATA_LEN   56    
#define ERROR           -1    
#define SUCCESS         1    
#define MAX_WAIT_TIME  3    
#define MAX_NO_PACKETS  4   
  
using namespace std;  
  
class DKping  
{  
public:  
    DKping(const char * ip, int timeout);    
    DKping(const DKping& orig);    
    virtual ~DKping();  
  
private:  
    std::string m_strIp;            //Used to save the IP entered by the user  
    std::string m_copy_Ip;          //This is also used to save the user's input IP, which is equivalent to a backup  
  
    int m_nSend;                   //Used to record the number of data packets sent  
    int m_nRecv;                   //Used to record the number of packets received  
    struct sockaddr_in m_dest_addr;     //The socket address used to save the target IP  
    struct sockaddr_in m_from_addr;     //Used to save the socket address from the target IP  
    char m_sendpacket[PACKET_SIZE];     //Used to save the sent ICMP packet  
    char m_recvpacket[PACKET_SIZE];     //Used to save the received ICMP packet  
    struct timeval m_tvrecv;            //The time of receiving the data packet  
    struct timeval m_begin_tvrecv;      //Start time to send data packet  
    struct timeval m_end_tvrecv;        //The time of the last received packet  
    double m_dTotalResponseTimes;       //The time from sending to receiving all data packets  
    int m_nSocketfd; //Socket  
      
    int m_nMaxTimeWait;         //The longest waiting time for each packet received  
public:  
    bool ping(int times);  
    //Create and close socket  
    bool CreateSocket();    
    bool CloseSocket();   
    //Send and receive an IP packet  
    void send_packet(void);    
    void recv_packet(void);  
    //Data packing and unpacking  
    int pack(int pack_no);  
    int unpack(char *buf, int len);  
    //Time calculation and information printing  
    void tv_sub(struct timeval *out, struct timeval *in);    
    void statistics(int sig);  
    //ICMP checksum calculation function  
    static unsigned short cal_chksum(unsigned short *addr, int len);  
};  
  
#endif  