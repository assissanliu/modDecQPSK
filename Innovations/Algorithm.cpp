#include "StdAfx.h"
#include "Algorithm.h"
#include "Innovations.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(CAlgorithm, CDialog)

CAlgorithm::CAlgorithm(CWnd* pParent /*=NULL*/)
           : CDialog(IDD_DIALOG1, pParent)
{
}

CAlgorithm::~CAlgorithm()
{
}

void CAlgorithm::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAlgorithm, CDialog)
    ON_BN_CLICKED(IDOK, &CAlgorithm::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CAlgorithm::OnBnClickedCancel)
    ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()

void CAlgorithm::Reset(const float *InitParam)
{
    m_OutputBuf.resize(0);
}

//QPSK解映射
void CAlgorithm::RunAlgorithm(const float *InitParam, const float *pdInput1, const float *pdInput2, const int InputSize,
                             int& OutputSize, float& OutputRate, float **pdOutput)
{
    float InputRate = InitParam[0];                        //输入采样率
    bool IsSoftDec  = (InitParam[2] > 0.5f) ? true:false;  //是否软硬解(界面设置)

    //解调映射参数及输出参数
    OutputSize = InputSize*QM;
    OutputRate = InputRate*QM;

    //分配空间
    m_OutputBuf.clear();
    m_OutputBuf.resize(OutputSize);

    //qpsk解映射
    for (int idx = 0;idx < InputSize;idx++)
    {
        if (pdInput1[idx] < 0.0f)  m_OutputBuf[2 * idx + 0] = 3.3f;
        else                       m_OutputBuf[2 * idx + 0] = 0.0f;
        if (pdInput2[idx] < 0.0f)  m_OutputBuf[2 * idx + 1] = 3.3f;
        else                       m_OutputBuf[2 * idx + 1] = 0.0f;
    }

    //输出
    if (OutputSize > 0)
    {
        *pdOutput = &m_OutputBuf[0];
    }
}

//界面控制
void CAlgorithm::OnBnClickedOk()
{
    ShowWindow(SW_HIDE);
}

void CAlgorithm::OnBnClickedCancel()
{
    ShowWindow(SW_HIDE);
}

void CAlgorithm::OnEnChangeEdit()
{
    ShowWindow(SW_HIDE);
}

void CAlgorithm::OnShowWindow(BOOL bShow, UINT nStatus)
{
    CDialog::OnShowWindow(bShow, nStatus);
    if (bShow)
    {
        CString value2str;
    }
}

BOOL CAlgorithm::OnInitDialog()
{
    CDialog::OnInitDialog();
    return TRUE;
}
