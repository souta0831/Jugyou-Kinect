#pragma once

#include "ESGLib.h"
#include "GameScene/GameScene.hpp"
#include "math.h"

#include <iostream>
#include <fstream>

class KinectTracking
{
   //キネクトのハンドル
   HRESULT hr;

   //ログファイル書き出し
   std::ofstream logfile;

   //ユーザの骨格情報
   NUI_SKELETON_FRAME Skeleton;

public:
   //今回は両腕と両手を取得します
   //それぞれのX,Y,Z軸
   //[0]:X軸 (←左|-0.6程度～+0.6程度|右→)
   //[1]:Y軸 (↓下|-0.5程度～+0.5程度|上↑)
   //[2]:Z軸 (距離依存、近いほど0に近くなるが0.6程度の45cmくらいまで)
   float LEFT_ELBOW[3];
   float LEFT_HAND[3];
   float RIGHT_ELBOW[3];
   float RIGHT_HAND[3];


   //KinectTrackingメンバ関数

   //最初に呼び出します(初期化も兼ねています)
   void connect()
   {
	//書き込みモードでログデータを書き出し
	logfile.open("KinectTracking_logData.txt", std::ios_base::out);
	//初期化
	hr = NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON);

	//取得できない場合は強制終了
	if (FAILED(hr))
	{
	   logfile << "Error" << std::endl;
	   exit(1);
	}

	//初期化
	for (int i = 0; i < 3; i++)
	{
	   LEFT_ELBOW[i] = 0;
	   LEFT_HAND[i] = 0;
	   RIGHT_ELBOW[i] = 0;
	   RIGHT_HAND[i] = 0;
	}
   }

   //データ取得(取得間隔を入れてください)
   void getdata(unsigned int interval)
   {
	//座りモードで読み込みます
	hr = NuiSkeletonTrackingEnable(0, NUI_SKELETON_TRACKING_FLAG_ENABLE_SEATED_SUPPORT);
	//Kinectから骨格情報の取得
	NuiSkeletonGetNextFrame(0, &Skeleton);

	//最大6人まで認識できますがおそらく2人までしかまともに機能しません
	for (int i = 0; i < NUI_SKELETON_COUNT; i++)
	{
	   if (Skeleton.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED)
	   {

		//骨格データの取得
		//左ひじ
		LEFT_ELBOW[0] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_LEFT].x;
		LEFT_ELBOW[1] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_LEFT].y;
		LEFT_ELBOW[2] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_LEFT].z;
		//左手
		LEFT_HAND[0] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].x;
		LEFT_HAND[1] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].y;
		LEFT_HAND[2] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].z;
		//右ひじ
		RIGHT_ELBOW[0] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT].x;
		RIGHT_ELBOW[1] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT].y;
		RIGHT_ELBOW[2] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT].z;
		//左手
		RIGHT_HAND[0] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].x;
		RIGHT_HAND[1] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].y;
		RIGHT_HAND[2] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].z;
		//ログに書き出し
		logfile << "左ひじ:(" << LEFT_ELBOW[0] << "," << LEFT_ELBOW[1] << "," << LEFT_ELBOW[2] << "),\t";
		logfile << "右ひじ:(" << RIGHT_ELBOW[0] << "," << RIGHT_ELBOW[1] << "," << RIGHT_ELBOW[2] << ")" << std::endl;
		logfile << "左 手 :(" << LEFT_HAND[0] << "," << LEFT_HAND[1] << "," << LEFT_HAND[2] << "),\t";
		logfile << "右 手 :(" << RIGHT_HAND[0] << "," << RIGHT_HAND[1] << "," << RIGHT_HAND[2] << ")" << std::endl;

		//デバッグ用としてここに表示します
		print_console();

		//取得間隔
		Sleep(interval);
	   }
	}
   }

   //コンソール表示
   void print_console()
   {
	
	//std::cout << "左ひじ:(" << LEFT_ELBOW[0] << "," << LEFT_ELBOW[1] << "," << LEFT_ELBOW[2] << "),\t";
	//std::cout << "右ひじ:(" << RIGHT_ELBOW[0] << "," << RIGHT_ELBOW[1] << "," << RIGHT_ELBOW[2] << ")" << std::endl;
	//std::cout << "左 手 :(" << LEFT_HAND[0] << "," << LEFT_HAND[1] << "," << LEFT_HAND[2] << "),\t";
	//std::cout << "右 手 :(" << RIGHT_HAND[0] << "," << RIGHT_HAND[1] << "," << RIGHT_HAND[2] << ")" << std::endl << std::endl;
   }
};

class GameMain : public CGameScene {
public:
	GameMain() : DefaultFont(GraphicsDevice.CreateDefaultFont())
	{
//		ContentRootDirectory(_T("Content"));
	}

	virtual ~GameMain()
	{
#ifdef _INC_SQUIRREL
		Squirrel.ReleaseAllScripts();
#endif
#ifdef _INC_NUI
		NUI.ReleaseAllKinects();
#endif
#ifdef _INC_LIVE2D
		Live2D.ReleaseAllModels();
#endif
#ifdef _INC_EFFEKSEER
		Effekseer.ReleaseAllEffects();
#endif
#ifdef _INC_DIRECT2D
		Direct2D.ReleaseAllResources();
#endif
		MediaManager.ReleaseAllMedia();

		SoundDevice.ReleaseAllMusics();
		SoundDevice.ReleaseAllSounds();

		GraphicsDevice.ReleaseAllRenderTargets();
		GraphicsDevice.ReleaseAllStateBlocks();
		GraphicsDevice.ReleaseAllFonts();
		GraphicsDevice.ReleaseAllSprites();
		GraphicsDevice.ReleaseAllAnimationModels();
		GraphicsDevice.ReleaseAllModels();
		GraphicsDevice.ReleaseAllVertexBuffers();
		GraphicsDevice.ReleaseAllEffects();

		Finalize();
	}

public:
	virtual bool Initialize();

	virtual int  Update();
	virtual void Draw();

	// 関数宣言
	void	CheckPose(int poseLevel, NUI_SKELETON_FRAME& skeleton);	//(ポーズ番号, 判定対象ボーン)
	Vector3 GetVector3byTwoPosition(_Vector4 v41, _Vector4 v42);	//関節間のベクトル
	float	GetAnglebyTwoVector(Vector3 v31, Vector3 v32);			//二つのベクトルの角度
	Vector2 TransformSkeltonPosition(_Vector4 pos);					//スケルトン座標を二次に変換
	float	GetDistbyTwoPosition(Vector2 pos1, Vector2 pos2);		//二点間の距離


private:
	void Finalize();
	FONT DefaultFont;

private:
	// 変数宣言
	MODEL model_;
	Vector3 model_position_;
	CAMERA camera_;
	SPRITE bg;
	Vector3 bg_position_;
	int  color_flg_;
	
	KINECT kinect;
	KinectTracking _kt;
	NUITLVERTEX   bone[20];
	
};

