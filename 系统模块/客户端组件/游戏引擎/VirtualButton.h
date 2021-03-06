#ifndef VIRTUAL_BUTTON_HEAD_FILE
#define VIRTUAL_BUTTON_HEAD_FILE

#pragma once

#include "D3DTexture.h"
#include "LapseCount.h"
#include "VirtualWindow.h"
#include "GameEngineHead.h"

//////////////////////////////////////////////////////////////////////////////////

//虚拟按钮
class GAME_ENGINE_CLASS CVirtualButton : public CVirtualWindow
{
	//状态变量
protected:
	bool							m_bMouseDown;						//按下标志
	bool							m_bMouseMove;						//经过标志
	CRect							m_rcButtonRect;						//按钮区域

	//资源变量
protected:
	LPCTSTR							m_pszTypeName;						//资源类型
	LPCTSTR							m_pszResource;						//资源信息
	HINSTANCE						m_hResInstance;						//资源句柄

	//动画变量
protected:
	WORD							m_wImageIndex;						//过渡索引
	CLapseCount						m_ImageLapseCount;					//流逝计数

	//资源变量
protected:
	CD3DTexture						m_D3DTextureButton;					//按钮纹理

	//函数定义
public:
	//构造函数
	CVirtualButton();
	//析构函数
	virtual ~CVirtualButton();

	//系统事件
protected:
	//动画消息
	virtual VOID OnWindowMovie();
	//创建消息
	virtual VOID OnWindowCreate(CD3DDevice * pD3DDevice);
	//销毁消息
	virtual VOID OnWindowDestory(CD3DDevice * pD3DDevice);

	//重载函数
protected:
	//鼠标事件
	virtual VOID OnEventMouse(UINT uMessage, UINT nFlags, INT nXMousePos, INT nYMousePos);
	//按钮事件
	virtual VOID OnEventButton(UINT uButtonID, UINT uMessage, INT nXMousePos, INT nYMousePos);
	//绘画窗口
	virtual VOID OnEventDrawWindow(CD3DDevice * pD3DDevice, INT nXOriginPos, INT nYOriginPos);

	//功能函数
public:
	//设置区域
	VOID SetButtonRect(CRect rcButtonRect);
	//加载位图
	VOID SetButtonImage(CD3DDevice * pD3DDevice, LPCTSTR pszResource, LPCTSTR pszTypeName, HINSTANCE hResInstance);

	//内部函数
protected:
	//调整控件
	VOID RectifyControl(CD3DDevice * pD3DDevice);
};

//////////////////////////////////////////////////////////////////////////////////

#endif