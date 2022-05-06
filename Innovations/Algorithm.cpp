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

//QPSK��ӳ��
void CAlgorithm::RunAlgorithm(const float *InitParam, const float *pdInput1, const float *pdInput2, const int InputSize,
                             int& OutputSize, float& OutputRate, float **pdOutput)
{
    float InputRate = InitParam[0];                        //���������
    bool IsSoftDec  = (InitParam[2] > 0.5f) ? true:false;  //�Ƿ���Ӳ��(��������)

    //���ӳ��������������
    OutputSize = InputSize*QM;
    OutputRate = InputRate*QM;

    //����ռ�
    m_OutputBuf.clear();
    m_OutputBuf.resize(OutputSize);

    //qpsk��ӳ��
    for (int idx = 0;idx < InputSize;idx++)
    {
        if (pdInput1[idx] < 0.0f)  m_OutputBuf[2 * idx + 0] = 3.3f;
        else                       m_OutputBuf[2 * idx + 0] = 0.0f;
        if (pdInput2[idx] < 0.0f)  m_OutputBuf[2 * idx + 1] = 3.3f;
        else                       m_OutputBuf[2 * idx + 1] = 0.0f;
    }

    //���
    if (OutputSize > 0)
    {
        *pdOutput = &m_OutputBuf[0];
    }
}

//�������
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
