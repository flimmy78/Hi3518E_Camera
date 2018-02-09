/******************************************************************************

                  ��Ȩ���� (C), 2012-2022, Goscam

 ******************************************************************************
  �� �� ��   : sample_venc.h
  �� �� ��   : ����
  ��    ��   : mr.iubing
  ��������   : 2014��3��21��
  ����޸�   :
  ��������   : sample_venc.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2014��3��21��
    ��    ��   : mr.iubing
    �޸�����   : �����ļ�

******************************************************************************/

#ifndef __SAMPLE_REGION_H__
#define __SAMPLE_REGION_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

//cjb add 20140605
#include "global.h"
#include "hi_common.h"

#if 1
//--------------------------------cjb add---------------------------------
//ADD CJB 20140531
//====================================
//��˼�涨ÿ��������ֻ֧��4 ��osd��������
//���Ҫ����osd �������޸�������������
#define   REAL_HZ16_COUNT		  8170							//5165
#define   CAM_TITLE_LEN           16		//8�����֣� 16���ַ�
//#define   VENC_MAX_CHN_NUM        64 v200 ��Ϊ16
#define   VENC_MAX_CHN_NUM        64 // ����64��ʵ��ֻ�õ�2����ֹĳЩ�ط�������64�����飬������Χ���ϴ���

#define   GOS_MAX_OSD_NUM	      48   //(4*3*3)
#define   GOS_MAX_OSD_PER_GROUP   2
#define   GOS_MAX_TITLE_NUM       256
#define   GOS_MAX_TITLE_LINE      11
#define   GOS_OSD_TYPE_TIME			        0
#define   GOS_OSD_TYPE_TITLE		        1
#define   GOS_OSD_TYPE_MENU                 2
#define   GOS_OSD_TYPE_PTZ                  3
#define   GOS_OSD_DEAFULT_POS_X			    0
#define   GOS_OSD_DEAFULT_TIME_POS_Y		0
#define   GOS_OSD_DEAFULT_TITLE_POS_Y	   (576 - 32 - 0)
#define   GOS_OSD_MAX_BUFF_LENGTH	        81920			//80k
#define   MAX_VIDEO_NUM				        1			//�����Ƶ����·��
#define   VIDEO_NUM	                        1
#define   GOS_OSD_COLOR_BLACK		    0x8000
#define   GOS_OSD_COLOR_WHITE		    0xFFFF
#define   GOS_OSD_COLOR_RED			    0xFC00
#define   GOS_OSD_COLOR_YELLOW		    0xFFE0
#define   GOS_OSD_COLOR_CYAN			0x83FF
#define   GOS_OSD_COLOR_BLUE			0x801F
//====================================
typedef struct _OSD_LOGO_T_S
{
    unsigned int     width;								/* out */
    unsigned int     height;								/* out */
    unsigned int     stride;								/* in  */
    unsigned char    pRGBBuffer[GOS_OSD_MAX_BUFF_LENGTH];   /* in  */
}OSD_LOGO_T_S;

//=========================================
//��Ƶ�����㷨
//=========================================
typedef enum  _GOS_VIDEO_ENCODER_E
{
		GOS_VENC_NONE   = 0x0,
		GOS_VENC_H264   = 0x01,
		GOS_VENC_MPEG4  = 0x02,
		GOS_VENC_MJPEG  = 0x03,
		GOS_VENC_JPEG   = 0x04,
}GOS_VIDEO_ENCODER_E;

typedef struct _OSD_POS_T
{
    int		x;								
	int     y;
}PACKED OSD_POS_T;

typedef struct _HI_OSD_ORG
{
	UInt16      nOrgX;       //osd ��������Ͻ�X����
	UInt16      nOrgY;       //osd ��������Ͻ�Y����
}PACKED HI_OSD_ORG, *PHI_OSD_ORG;

typedef struct _HI_OSD_COLOR
{
	UInt16       bgColor;     //osd ������ɫ
	UInt16       fgColor;     //osd ǰ����ɫ 
	UInt16		 bgAlpha;     //osd ����͸����
	UInt16		 fgAlpha;	  //osd ǰ��͸����
	UInt16		 edgeColor;	  //osd ǰ����Ե��ɫ	
	UInt16       selColor;    //osd �˵�ѡ������ɫ
}PACKED HI_OSD_COLOR, *PHI_OSD_COLOR;

typedef struct _GOS_OSD_LOGO
{
	VENC_GRP     vencGroup ;   //osd ������ӵ��ı�����
	UInt8        nStatus   ;   //1 ��ʾ 0 ����
	UInt8        nOsdLine  ;   //osd ��Ļ������
	UInt8        nOsdFontH ;
	UInt8        nOsdFontW ;
	UInt16		 nWidth    ;    //osd ����Ŀ�� 
	UInt16		 nHeight   ;    //osd ����ĸ߶� 
	UInt16       nImageWidth;
	UInt16       nImageHeight;
	Int16        nFontInt  ;    //osd �ַ����
	UInt16       nVencFeild;
	UInt8        nOsdTitleMaxLen; ////������һ���ַ��ĸ���
	UInt8        nOsdTitleFlag[GOS_MAX_TITLE_LINE]; //osd ���֧��8 �� ���ÿһ��osd ��һ���ַ���osdtitle �е�λ��
	UInt8        nOsdTitleLen[GOS_MAX_TITLE_LINE];  //���ÿһ��osd �ĳ���
	char         szOsdTitle[GOS_MAX_TITLE_NUM];   //osd ������Ļ��Ϣ
	HI_OSD_ORG   osdPos    ;   //
	HI_OSD_COLOR osdColor  ;   //
	UInt8        *pBmpBuf;
	int			 regHdl;		//osd ������
	int          nSelLine  ;    //��ǵ�ǰ��Ϊѡ����
} PACKED GOS_OSD_LOGO, *PGOS_OSD_LOGO;

typedef struct _GOS_OSD_CTRL_ST
{
	unsigned int		Show;						
	unsigned short		X;							
	unsigned short		Y;
}PACKED GOS_OSD_CTRL_ST ;

//��Ƶ������Ϣ�����ʡ�֡�ʡ�
typedef struct _VideoEnc_Info 
{
	UInt32		Bitrate[3];					 //����(����������)
	UInt16 		FrameRate[3];				 //֡��(����������)		
	UInt32		BitrateCount[3];			 //����ͳ��(����������)
	UInt16 		FrameRateCount[3];			 //֡��ͳ��(����������)		
}PACKED VideoEnc_Info;

typedef struct _GOS_OSD_CTRL
{
    int                 nOsdColor;
    char                osdtitle[64];
    GOS_OSD_CTRL_ST	    stDateOSD; 		    //OSD����	        
    GOS_OSD_CTRL_ST	    stTimeOSD; 	        //OSD����	
    GOS_OSD_CTRL_ST	    stBitrateOSD;       //OSD����	
    GOS_OSD_CTRL_ST 	stTitleOSD;         //OSD����	
    VideoEnc_Info       _VideoEncInfo[1];   //OSDˢ��
}PACKED GOS_OSD_CTRL;

GOS_OSD_LOGO *HI_Create_Osd(int index, GOS_OSD_LOGO **ppLog, VENC_GRP vencGroup,  
						    HI_OSD_ORG	osdOrg, HI_OSD_COLOR osdColor, 
 							char *pSzTitle, Int16 nFontInt, UInt8 nShow);
int  HI_OSD_Parse_OsdTitle(GOS_OSD_LOGO *pOsdLogo);
int  HI_OSD_Get_BmpSize(GOS_OSD_LOGO *pOsdLogo);
int  HI_OSD_Set_Show(GOS_OSD_LOGO *pOsdLogo, int show);
int  HI_Create_Osd_Reg(GOS_OSD_LOGO *pOsdLogo);
int  HI_OSD_Create_Bitmap(GOS_OSD_LOGO *pOsdLogo);
int  HI_OSD_Refresh_Color(GOS_OSD_LOGO *pOsdLogo);
int  HI_OSD_Refresh_Title(GOS_OSD_LOGO *pOsdLogo);
int  HI_OSD_Refresh_Org(GOS_OSD_LOGO *pOsdLogo);
int HI_OSD_Check_ImaSizeChange(GOS_OSD_LOGO *pOsdLogo);
int  HI_OSD_Destroy(GOS_OSD_LOGO *pOsdLogo);
int  HI_OSD_Build(GOS_OSD_LOGO *pOsdLogo);
int  HI_OSD_GetCharBit(unsigned char *in, short qu, short wei, short fontSize);
int  HI_OSD_DrawBitmapBit(int  x_pos, UInt8 *bitmap, UInt16 fColor, UInt16 bColor,
						  UInt16 edgeColor, UInt8 *bmpBuffer, UInt16 bmpWidth,
						  UInt16 fontSize);
int  HI_OSD_DrawBitmapBit32(int x_pos, UInt8 *bitmap, UInt16 fColor, UInt16 bColor, 
						   UInt16 edgeColor, UInt8 *bmpBuffer, UInt16 bmpWidth,
						  UInt16 fontSize);
void HI_OSD_CreateBMP(int bTwoFeild,  int nSize, int bmpWidth, int space,
					  char *bmpBuffer, char *string, UInt16 fColor, 
					  UInt16 bColor, UInt16 edgeColor);
extern int GOS_OSD_Init();
extern int GOS_OSD_All_Refresh();
float GOS_OSD_GetOsdRateX(int nCh, int nMinEnc);
float GOS_OSD_GetOsdRateY(int nCh, int nMinEnc);
int   GOS_OSD_GetOrg(int nCh, int nEnc, int osdType, HI_OSD_ORG  *pOsdOrg);
int   GOS_OSD_GetTitle(int nCh, int bMin, int nOsdType, char *pTitle);
int   GOS_OSD_GetColor(int nCh, HI_OSD_COLOR *pOsdColor);
int   GOS_OSD_Destory(int nCh, int nEnc, int osdType);
int   GOS_OSD_Rebuild(int nCh, int nEnc, int osdType);
int   GOS_OSD_GetShow(int nCh, int bMin, int nOsdType);
int   GOS_OSD_GetFontInt(int nCh, int bMin, int nOsdType);
int   GOS_OSD_GetTimeTitle(int nCh, int bMin, char *pTitle);
int   GOS_Refresh_AllTime();
int   GOS_OSD_ChnOrg_Refresh(int nCh);
int   GOS_OSD_ChnAllName_Refresh(int nCh);
int   GOS_OSD_ChnTime_Refresh(int nCh);
int   GOS_OSD_AllTime_Refresh();
int   GOS_OSD_AllName_Refresh();
int   GOS_OSD_ChnColor_Refresh(int nCh);
int   GOS_OSD_ChnReBuild(int nCh);
int   GOS_OSD_Color_Refresh(int nCh, int nEnc, int osdType);
int   GOS_OSD_Show_Refresh(int nCh, int nMinEnc, int osdType);
int   GOS_OSD_ChnShow_Refresh(int nCh);
int   GOS_OSD_Org_Refresh(int nCh, int nEnc, int osdType);
int   GOS_OSD_ChName_Refresh(int nCh, int nMinEnc, int osdType);
int   GOS_OSD_Refresh_SelLine(int nCh, int nMin, int nType, int iLine);
int   GOS_VENC_GetVEncSize(int nCh, int nMinEnc, int *nEncWidth, int *nEncHeight, int *nEncType);
int   GOS_VENC_GetVencGroup(VENC_CHN VeChn);
int   GOS_OSD_GetFrameTitle(int nCh, int bMin, char *pTitle);
extern int	 GOS_PUB_MutexInit(pthread_mutex_t *mutex);
extern void  GOS_PUB_MutexDestroy(pthread_mutex_t *mutex);
extern void  GOS_PUB_MutexLock(pthread_mutex_t *mutex);
extern void  GOS_PUB_MutexUnlock(pthread_mutex_t *mutex);
extern int GOS_PUB_MutexTryLock(pthread_mutex_t *mutex);
//====================================

extern unsigned char   g_real_HZ16p[] ;						//���ֿ�					
extern unsigned char   g_real_HZ12p[]; 						//CJB
extern unsigned char   g_real_HZ8p[];  
extern GOS_OSD_CTRL    g_osd_control;
GOS_OSD_LOGO *pGOsd[GOS_MAX_OSD_NUM]; //={0}
//--------------------------------cjb add---------------------------------
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __SAMPLE_REGION_H__ */
