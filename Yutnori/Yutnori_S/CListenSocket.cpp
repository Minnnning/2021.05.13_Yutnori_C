#include "pch.h"
#include "CListenSocket.h"
#include "Yutnori_SDlg.h"
#include "CChildSocket.h"


void CListenSocket::OnAccept(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CChildSocket* pChild = new CChildSocket;
	BOOL check = Accept(*pChild);
	if (check == FALSE) { delete pChild; return; } //����������
	
	//Ŭ���̾�Ʈ ������ �����ϸ� ����Ʈ�� �߰��Ѵ�.
	m_pChildSocketList.AddTail(pChild);

	//����ȭ�鿡 Ŭ���̾�Ʈ ���� ������ �����ش�.
	CString strSocketName; UINT uPort;
	pChild->GetPeerName(strSocketName, uPort);
	CString str; str.Format(_T("[%s:%u] ���� ������ �����մϴ�.\r\n"), strSocketName, uPort);
	CYutnoriSDlg* pMain = (CYutnoriSDlg*)AfxGetMainWnd();
	pMain->m_ctrlEdit.ReplaceSel(str);

	//Ŭ���̾�Ʈ���� ������ ���������� �˷��ش�.
	pChild->Send(str.GetBuffer(), str.GetLength());

	//CListenSocket ��ü�� �ּҸ� CChildSocket ��ü�� �����Ѵ�.
	pChild->m_pListenSocket = this;

	CAsyncSocket::OnAccept(nErrorCode);
}


void CListenSocket::Broadcast(CString strMessage)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.

	POSITION pos = m_pChildSocketList.GetHeadPosition();
	while (pos != NULL) {
		CChildSocket* pChild = (CChildSocket*)m_pChildSocketList.GetNext(pos);
		if (pChild != NULL) pChild->Send(strMessage.GetBuffer(), strMessage.GetLength());
	}
}
