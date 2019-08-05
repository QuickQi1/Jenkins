#pragma once
// Interface for the CMAPIProgress

class CMAPIProgress : public IMAPIProgress
{
public:
	CMAPIProgress(const wstring& lpszContext, _In_ HWND hWnd);
	virtual ~CMAPIProgress();

private:
	// IUnknown
	STDMETHODIMP QueryInterface(REFIID riid, LPVOID * ppvObj) override;
	STDMETHODIMP_(ULONG) AddRef() override;
	STDMETHODIMP_(ULONG) Release() override;

	// IMAPIProgress
	_Check_return_ STDMETHODIMP Progress(ULONG ulValue, ULONG ulCount, ULONG ulTotal) override;
	STDMETHODIMP GetFlags(ULONG* lpulFlags) override;
	STDMETHODIMP GetMax(ULONG* lpulMax) override;
	STDMETHODIMP GetMin(ULONG* lpulMin) override;
	STDMETHODIMP SetLimits(ULONG* lpulMin, ULONG* lpulMax, ULONG* lpulFlags) override;

	void OutputState(const wstring& lpszFunction) const;

	LONG m_cRef;
	ULONG m_ulMin;
	ULONG m_ulMax;
	ULONG m_ulFlags;
	wstring m_szContext;
	HWND m_hWnd;
};

_Check_return_ CMAPIProgress* GetMAPIProgress(const wstring& lpszContext, _In_ HWND hWnd);
