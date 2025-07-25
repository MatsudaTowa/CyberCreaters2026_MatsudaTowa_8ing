//=============================================
//
//カメラのステートパターン[camera_state.h]
//Author Matsuda Towa
//
//=============================================
#ifndef _CAMERA_STATE_H_
#define _CAMERA_STATE_H_

#include "camera.h"

//=============================================
//前方宣言
//=============================================
class CCamera;

//=============================================
//カメラステートクラス
//=============================================
class CCameraState
{
public:
	/**
	 * @brief 自由視点
	 * @param [in]カメラポインタ
	 */
	virtual void FreeView([[maybe_unused]] CCamera* camera);
	/**
	 * @brief 三人称視点
	 * @param [in]カメラポインタ
	 */
	virtual void ThirdView([[maybe_unused]] CCamera* camera);
	/**
	 * @brief ウルト視点
	 * @param [in]カメラポインタ
	 */
	virtual void Ult([[maybe_unused]] CCamera* camera);
};

//=============================================
//自由なカメラ
//=============================================
class CFreeView : public CCameraState
{
public:
	/**
	 * @brief 自由視点
	 * @param [in]カメラポインタ
	 */
	virtual void FreeView(CCamera* camera)override;
private:
	static constexpr float FREEVIEW_LENGTH = 200.0f; //自由視点時の距離
};

//=============================================
//三人称状態
//=============================================
class CThirdView : public CCameraState
{
public:
	/**
	 * @brief 三人称視点
	 * @param [in]カメラポインタ
	 */
	virtual void ThirdView(CCamera* camera)override;
private:
	static constexpr float THIRDVIEW_LENGTH = 130.0f; //サードパーソンビュー時の距離
};

//=============================================
//ウルト状態
//=============================================
class CUltCameraState : public CCameraState
{
public:
	/**
	 * @brief ウルト視点
	 * @param [in]カメラポインタ
	 */
	virtual void Ult(CCamera* camera) override;
private:
	static constexpr float ULT_LENGTH = 200.0f; //ウルト時の距離
};

#endif // !_PLAYER_STATE_H
