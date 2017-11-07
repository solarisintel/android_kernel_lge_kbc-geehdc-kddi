/*                                                                           
        
                  
  
               
                                              
                                                                                                    
                                                                                                            
                                                                                  
     
                
                            
                                                                                
                                                  
  
                                                                                            
 */



//#define LG_FW_HSIC_EMS_DEBUG
#define EMS_RESET_SOC_ONLY_CHECK
#define EMS_LOG_FORMAT_LEN_FILE_NAME	(50)
#define EMS_LOG_FORMAT_LEN_LINE			(4)
#define EMS_LOG_FORMAT_LEN_ERR_MSG		(80)
#define EMS_LOG_FORMAT_LEN_SW_VER		(50)

/* START - EMS packet header, data */

typedef struct
{
	u16 mode; // mode is always 1 ( 0:test mode, 1:EMS mode )
	u16 total_size;
	u32 arch_type;
} sEMS_RX_Header;

typedef struct
{
	sEMS_RX_Header header;
	char filename[EMS_LOG_FORMAT_LEN_FILE_NAME];
	int line;
	char msg[EMS_LOG_FORMAT_LEN_ERR_MSG];
	char sw_ver[EMS_LOG_FORMAT_LEN_SW_VER];
} sEMS_RX_Data;
typedef struct 
{
	bool				valid;		// 0: invalid, 1: valid
	sEMS_RX_Data		rx_data;	// contains debugging information
} sEMS_PRx_Data;
/* END - EMS packet header, data */

int sysmon_hsic_debug_bridge_read(char *data, int size);
void hsic_debug_display_log(void *buff);
void sysmon_hsic_debug_suspend(int hsic_suspend);
void sysmon_hsic_debug_disconnect(void);
void sysmon_hsic_debug_in_busy(int in_busy_hsic_read);

