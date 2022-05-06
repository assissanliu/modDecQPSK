// Innovations_3.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "Innovations.h"
#include "Algorithm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CInnovations_App, CWinApp)
END_MESSAGE_MAP()

CInnovations_App::CInnovations_App()
{
    // TODO: 在此处添加构造代码，
    // 将所有重要的初始化放置在 InitInstance 中
}

CInnovations_App theApp;


// CInnovations_App 初始化

BOOL CInnovations_App::InitInstance()
{
    CWinApp::InitInstance();

    return TRUE;
}

//创建一个算法对象，并返回算法对象指针
void *LtCreateObject()
{
    CAlgorithm *pAlgorithm = new CAlgorithm();
    pAlgorithm->Create(IDD_DIALOG1,NULL);
    return static_cast<void*>( pAlgorithm );
}

//删除一个算法对象，此函数期待的参数（pObject）正是LtCreateObject()的返回值
void LtDestroyObject( void * pObject )
{
    ASSERT( pObject != NULL );
    ASSERT( !IsBadWritePtr( pObject, sizeof(CAlgorithm) ) );
    CAlgorithm * pAlgorithm = static_cast<CAlgorithm *>( pObject );
    pAlgorithm->DestroyWindow();
    delete pAlgorithm;	//删除一个算法对象

}

void LtResetModule(void *pObject, const float *InitParam)
{
    ASSERT( pObject != NULL );
    ASSERT( !IsBadWritePtr( pObject, sizeof(CAlgorithm) ) );
    CAlgorithm * pAlgorithm = static_cast<CAlgorithm *>( pObject );
    pAlgorithm->Reset(InitParam);
}

//InitParam[0] 输入符号速率
//InitParam[1] 调制映射方式: 0-BPSK;1-QPSK;2-8PSK;3-16QAM;4-64QAM;5-256QAM
//InitParam[2] 硬解调软解调  0-硬解;1-软解
//pdInput1     I路输入数据
//pdInput2     Q路输入数据
//InputSize    输入数据大小
//OutputSize   输出数据大小
//OutputRate   输出符号速率
//pdOutput     解调输出
void LtDLLMain(void * pObject, const float *InitParam, const float *pdInput1, const float *pdInput2, const int InputSize,
               int& OutputSize, float& OutputRate, float **pdOutput)
{
    ASSERT( pObject != NULL );
    CAlgorithm * pAlgorithm = static_cast<CAlgorithm *>( pObject );
    pAlgorithm->RunAlgorithm(InitParam, pdInput1, pdInput2, InputSize,
                             OutputSize, OutputRate, pdOutput);
}

//显示算法操作界面(仅当算法对象是继承自CDialog类,才需编写此函数)
void LtShowWindow( void * pObject )
{
    ASSERT( pObject != NULL );
    ASSERT( !IsBadWritePtr( pObject, sizeof(CAlgorithm) ) );
    CAlgorithm * pAlgorithm = static_cast<CAlgorithm *>( pObject );
    pAlgorithm->ShowWindow( SW_SHOW );
}