/***********************************************************************************************************
*											���ô�ӡģ��
*  Ŀ��: ��ҪΪ�˹���Osp��ӡ��
*  �÷�: ��������ϳɵĴ�ӡ
*		1����������ʹ��CNmsPrint::Print( "Vmp", "�ն�״̬ MtId=%d", tMt.GetEqpID() ); 
*		2����Ҫһ��ע�������"Vmp"��User����ʹ�������ӡ
*			���ַ�ʽע�ᡣa������CNmsPrint��RegUser��RegUserS��ע�ᣬǰ��һ���������û����ڶ������ַ���
							���������ڶ����������ڸ��ӣ�ͨ���������Ҫ����ϳɴ�ӡ������Ч����ʱ��
							====Vmp==== �ն�״̬ MtId=1           ���ִ�ӡ��Ҫע��CNmsPrint::RegUserS( "Vmp", "====Vmp====" );
						  b����һ��ע�᷽ʽһ�㲻���ã���Ϊ��Ҫ�������ŵ����õ�ģ���е��ã������ǵڶ���
							��telnet��ֱ��ʹ��regusers reguser������ע�ᣬ����������һ��
							ע�����˹��󣬼ǵ���openlogs��openlog����ע����û��������Ϳ��Դ�ӡ��
************************************************************************************************************/

#ifndef NMSPRINT_20100730
#define NMSPRINT_20100730

#pragma warning(disable:4244)  // conversion from 'unsigned long' to 'unsigned char', possible loss of data
#pragma warning(disable:4018)  // signed/unsigned mismatch
#pragma warning(disable:4786)  // identifier over 255

#include <map>
#include <string>
using namespace std;
#include "kdvtype.h"
#include "kdvdef.h"
#include "osp.h"
#pragma comment(lib,"osplib.lib")

#define MAX_NAME_LEN 1024

// �û���Ϣ
typedef struct tagRegUserInfo
{
	BOOL32 bLogOpen; 
	s8 achName[MAX_NAME_LEN];
}TRegUserInfo,*PTRegUserInfo;

/*---------------------------------------------------------------------
* ��	����CNmsPrint
* ��    �ܣ��ṩһ��ͳһ�Ĵ�ӡ�ӿ�
* ����˵����
* �޸ļ�¼��
* ����			�汾		�޸���		�޸ļ�¼
* 2010/07/30	v1.0		Ĳ��ï		����
----------------------------------------------------------------------*/
#define NMS_PRINT_ID_DEFAULT_OPEN "Default"

#define NMSAPI extern "C"			__declspec(dllexport)
class CNmsPrint
{
public:
	static BOOL32 Printf( s8* pUser, const s8* pScrip , ... );
public:
	// Ĭ�ϴ�ӡ����
	static char* strNmsDefaultScrip;

	// ע���û�
//	static BOOL32 RegUser( u32 dwUserID , s8* pUserName );
	
	static BOOL32 RegUser( s8* pKey, s8* pUserName );
	/*---------------------------------------------------------------------
	* �� �� ����OpenLog 
	* ��    �ܣ��򿪿��� ͨ��������ס��ID��������ǵã������ȵ���showalluser
	* ����˵����[in] dwUserID Ψһ��ʶID
	* �� �� ֵ��
	* �޸ļ�¼��
	* ����			�汾		�޸���		�޸ļ�¼
	* 2010/08/13	v1.0		Ĳ��ï		����
	----------------------------------------------------------------------*/
	static BOOL32 OpenLog( u32 dwIndex );
	
	/*---------------------------------------------------------------------
	* �� �� ����OpenLog
	* ��    �ܣ�ͨ���û����򿪿���
	* ����˵����
	* �� �� ֵ��
	* �޸ļ�¼��
	* ����			�汾		�޸���		�޸ļ�¼
	* 2010/08/13	v1.0		Ĳ��ï		����
	----------------------------------------------------------------------*/
	static BOOL32 OpenLog( s8* pUser );
	
	
	/*---------------------------------------------------------------------
	* �� �� ����CloseLog
	* ��    �ܣ��رտ���
	* ����˵����
	* �� �� ֵ��
	* �޸ļ�¼��
	* ����			�汾		�޸���		�޸ļ�¼
	* 2010/08/13	v1.0		Ĳ��ï		����
	----------------------------------------------------------------------*/
	static BOOL32 CloseLog( u32 dwUserID );
	
	
	/*---------------------------------------------------------------------
	* �� �� ����CloseLog
	* ��    �ܣ��رտ���
	* ����˵����
	* �� �� ֵ��
	* �޸ļ�¼��
	* ����			�汾		�޸���		�޸ļ�¼
	* 2010/08/13	v1.0		Ĳ��ï		����
	----------------------------------------------------------------------*/
	static BOOL32 CloseLog( s8* pUser );
	
	/*---------------------------------------------------------------------
	* �� �� ����IsLogOpen
	* ��    �ܣ������Ƿ��
	* ����˵����
	* �� �� ֵ��
	* �޸ļ�¼��
	* ����			�汾		�޸���		�޸ļ�¼
	* 2010/08/13	v1.0		Ĳ��ï		����
	----------------------------------------------------------------------*/
	static BOOL32 IsLogOpen( s8* pUserName );
	
	
	/*---------------------------------------------------------------------
	* �� �� ����IsLogOpen
	* ��    �ܣ������Ƿ��
	* ����˵����
	* �� �� ֵ��
	* �޸ļ�¼��
	* ����			�汾		�޸���		�޸ļ�¼
	* 2010/08/13	v1.0		Ĳ��ï		����
	----------------------------------------------------------------------*/
	static BOOL32 IsLogOpen( u32 dwUserId );
	
	/*---------------------------------------------------------------------
	* �� �� ����GetRegUserInfo
	* ��    �ܣ����ע���û���Ϣ
	* ����˵����
	* �� �� ֵ��
	* �޸ļ�¼��
	* ����			�汾		�޸���		�޸ļ�¼
	* 2010/08/13	v1.0		Ĳ��ï		����
	----------------------------------------------------------------------*/
	static PTRegUserInfo GetRegUserInfo( u32 dwIndex );
	static PTRegUserInfo GetRegUserInfo( s8* pUser );
	
	static map< string, PTRegUserInfo > m_mapUserS;
};

#endif // NMSPRINT_20100730