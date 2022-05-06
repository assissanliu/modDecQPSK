#pragma once
#define QM 2

class CAlgorithm : public CDialog
{
    DECLARE_DYNAMIC(CAlgorithm)

public:
    CAlgorithm(CWnd* pParent = NULL);   // ��׼���캯��
    virtual ~CAlgorithm();

    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();
    afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
    afx_msg void OnEnChangeEdit();
    virtual BOOL OnInitDialog();

    // �Ի�������
#ifdef AFX_DESIGN_TIME
    enum {  IDD = IDD_DIALOG1 };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

    DECLARE_MESSAGE_MAP()

public:
    void Reset(const float *InitParam);
    void RunAlgorithm(const float *InitParam, const float *pdInput1, const float *pdInput2, const int InputSize,
                     int& OutputSize, float& OutputRate, float **pdOutput);
private:
    //������ݻ���
    vector<float> m_OutputBuf;
};
