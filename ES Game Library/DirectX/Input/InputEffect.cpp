/*
================================================================================
					 オブジェクト指向＆＆ゲームプログラミング
	     Copyright (c) 2011 Human Academy Sendai. All rights reserved.
================================================================================

 【対象ＯＳ】
     Microsoft Windows 7以降

 【コンパイラ】
     Microsoft VisualC++ 2013

 【プログラム】
	 InputEffect.cpp
				入力デバイスエフェクトクラス

 【バージョン】
	 * Version    2015.10.00      2015/08/28  03:10:03

================================================================================
*/

#pragma once

//------------------------------------------------------------------------------
//	インクルードファイル
//------------------------------------------------------------------------------
#include "InputEffect.hpp"
#include <cassert>

//------------------------------------------------------------------------------
//	コンストラクタ
//------------------------------------------------------------------------------
CInputEffect::CInputEffect(IDirectInputEffect* pDIEffect)
{
	assert(pDIEffect != NULL);
	m_pDIEffect = pDIEffect;
	m_pDIEffect->AddRef();			// 参照カウンタインクリメント
}

//------------------------------------------------------------------------------
//	デストラクタ
//------------------------------------------------------------------------------
CInputEffect::~CInputEffect()
{
	m_pDIEffect->Unload();
	m_pDIEffect->Release();
}

//------------------------------------------------------------------------------
//	エフェクト開始
//------------------------------------------------------------------------------
bool CInputEffect::Start(const DWORD inIterations)
{
	if(m_pDIEffect->Start(inIterations, DIES_SOLO) != DI_OK) {
		::OutputDebugString(TEXT("*** Error - エフェクト開始失敗(CInputEffect_Star)\n"));
		return false;
	}

	return true;
}

//------------------------------------------------------------------------------
//	エフェクト再生チェック
//------------------------------------------------------------------------------
bool CInputEffect::IsPlaying()
{
	DWORD   State;
	m_pDIEffect->GetEffectStatus(&State);
	if((State & DIEGES_PLAYING) == 0)
		return false;

	return true;
}
