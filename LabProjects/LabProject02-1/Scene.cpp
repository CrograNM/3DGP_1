#include "stdafx.h"
#include "Scene.h"
#include "GraphicsPipeline.h"

void CScene::BuildObjects() {
	//직육면체 메쉬를 생성한다.
	CCubeMesh* pCubeMesh = new CCubeMesh(8.0f, 8.0f, 8.0f);
	//게임 객체 2 개를 생성한다.
	m_nObjects = 2;
	m_ppObjects = new CGameObject * [m_nObjects];
	m_ppObjects[0] = new CGameObject();
	m_ppObjects[0]->SetMesh(pCubeMesh);
	m_ppObjects[0]->SetPosition(-8.5f, 0.0f, -14.0f);
	m_ppObjects[0]->SetRotation(0.0f, 0.0f, 0.0f);
	m_ppObjects[0]->SetRotationSpeed(5.0f, 30.0f, 9.0f);
	m_ppObjects[0]->SetColor(RGB(255, 0, 0));
	m_ppObjects[1] = new CGameObject();
	m_ppObjects[1]->SetMesh(pCubeMesh);
	m_ppObjects[1]->SetPosition(+8.5f, 0.0f, -14.0f);
	m_ppObjects[1]->SetRotation(0.0f, 0.0f, 0.0f);
	m_ppObjects[1]->SetRotationSpeed(30.0f, 9.0f, 5.0f);
	m_ppObjects[1]->SetColor(RGB(0, 0, 255));
}
void CScene::ReleaseObjects() {
	for (int i = 0; i < m_nObjects; i++) if (m_ppObjects[i]) delete
		m_ppObjects[i];
	if (m_ppObjects) delete[] m_ppObjects;
}
void CScene::Animate(float fElapsedTime) {
	for (int i = 0; i < m_nObjects; i++)
		m_ppObjects[i]->Animate(fElapsedTime);
} 
void CScene::Render(HDC hDCFrameBuffer, CCamera* pCamera) {
	//현재 카메라를 렌더링 파이프라인에 설정한다.
	if (pCamera) CGraphicsPipeline::SetCamera(pCamera);
	for (int i = 0; i < m_nObjects; i++) {
		//현재 게임 객체를 렌더링 파이프라인에 설정한다.
		CGraphicsPipeline::SetGameObject(m_ppObjects[i]);
		//현재 게임 객체를 렌더링한다.
		m_ppObjects[i]->Render(hDCFrameBuffer);
	}
}