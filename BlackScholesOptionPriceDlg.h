
// BlackScholesOptionPriceDlg.h : header file
//

#pragma once


// CBlackScholesOptionPriceDlg dialog
class CBlackScholesOptionPriceDlg : public CDialogEx
{
// Construction
public:
	CBlackScholesOptionPriceDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BLACKSCHOLESOPTIONPRICE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	//double m_assetValue;
public:
	afx_msg void OnBnClickedOk();
	//double m_optionPrice;
	double m_currentAssetPrice;
private:
	double m_strikePrice;
	double m_maturity;
	double m_rate;
	double m_sigma;
	CString m_callOptionPrice;
	CString m_putOptionPrice;

	static CString DoubleToText(double theNumber);
};
