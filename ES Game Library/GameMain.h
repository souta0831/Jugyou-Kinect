#pragma once

#include "ESGLib.h"
#include "GameScene/GameScene.hpp"
#include "math.h"

#include <iostream>
#include <fstream>

class KinectTracking
{
   //�L�l�N�g�̃n���h��
   HRESULT hr;

   //���O�t�@�C�������o��
   std::ofstream logfile;

   //���[�U�̍��i���
   NUI_SKELETON_FRAME Skeleton;

public:
   //����͗��r�Ɨ�����擾���܂�
   //���ꂼ���X,Y,Z��
   //[0]:X�� (����|-0.6���x�`+0.6���x|�E��)
   //[1]:Y�� (����|-0.5���x�`+0.5���x|�な)
   //[2]:Z�� (�����ˑ��A�߂��ق�0�ɋ߂��Ȃ邪0.6���x��45cm���炢�܂�)
   float LEFT_ELBOW[3];
   float LEFT_HAND[3];
   float RIGHT_ELBOW[3];
   float RIGHT_HAND[3];


   //KinectTracking�����o�֐�

   //�ŏ��ɌĂяo���܂�(�����������˂Ă��܂�)
   void connect()
   {
	//�������݃��[�h�Ń��O�f�[�^�������o��
	logfile.open("KinectTracking_logData.txt", std::ios_base::out);
	//������
	hr = NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON);

	//�擾�ł��Ȃ��ꍇ�͋����I��
	if (FAILED(hr))
	{
	   logfile << "Error" << std::endl;
	   exit(1);
	}

	//������
	for (int i = 0; i < 3; i++)
	{
	   LEFT_ELBOW[i] = 0;
	   LEFT_HAND[i] = 0;
	   RIGHT_ELBOW[i] = 0;
	   RIGHT_HAND[i] = 0;
	}
   }

   //�f�[�^�擾(�擾�Ԋu�����Ă�������)
   void getdata(unsigned int interval)
   {
	//���胂�[�h�œǂݍ��݂܂�
	hr = NuiSkeletonTrackingEnable(0, NUI_SKELETON_TRACKING_FLAG_ENABLE_SEATED_SUPPORT);
	//Kinect���獜�i���̎擾
	NuiSkeletonGetNextFrame(0, &Skeleton);

	//�ő�6�l�܂ŔF���ł��܂��������炭2�l�܂ł����܂Ƃ��ɋ@�\���܂���
	for (int i = 0; i < NUI_SKELETON_COUNT; i++)
	{
	   if (Skeleton.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED)
	   {

		//���i�f�[�^�̎擾
		//���Ђ�
		LEFT_ELBOW[0] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_LEFT].x;
		LEFT_ELBOW[1] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_LEFT].y;
		LEFT_ELBOW[2] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_LEFT].z;
		//����
		LEFT_HAND[0] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].x;
		LEFT_HAND[1] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].y;
		LEFT_HAND[2] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].z;
		//�E�Ђ�
		RIGHT_ELBOW[0] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT].x;
		RIGHT_ELBOW[1] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT].y;
		RIGHT_ELBOW[2] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT].z;
		//����
		RIGHT_HAND[0] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].x;
		RIGHT_HAND[1] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].y;
		RIGHT_HAND[2] = Skeleton.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].z;
		//���O�ɏ����o��
		logfile << "���Ђ�:(" << LEFT_ELBOW[0] << "," << LEFT_ELBOW[1] << "," << LEFT_ELBOW[2] << "),\t";
		logfile << "�E�Ђ�:(" << RIGHT_ELBOW[0] << "," << RIGHT_ELBOW[1] << "," << RIGHT_ELBOW[2] << ")" << std::endl;
		logfile << "�� �� :(" << LEFT_HAND[0] << "," << LEFT_HAND[1] << "," << LEFT_HAND[2] << "),\t";
		logfile << "�E �� :(" << RIGHT_HAND[0] << "," << RIGHT_HAND[1] << "," << RIGHT_HAND[2] << ")" << std::endl;

		//�f�o�b�O�p�Ƃ��Ă����ɕ\�����܂�
		print_console();

		//�擾�Ԋu
		Sleep(interval);
	   }
	}
   }

   //�R���\�[���\��
   void print_console()
   {
	
	//std::cout << "���Ђ�:(" << LEFT_ELBOW[0] << "," << LEFT_ELBOW[1] << "," << LEFT_ELBOW[2] << "),\t";
	//std::cout << "�E�Ђ�:(" << RIGHT_ELBOW[0] << "," << RIGHT_ELBOW[1] << "," << RIGHT_ELBOW[2] << ")" << std::endl;
	//std::cout << "�� �� :(" << LEFT_HAND[0] << "," << LEFT_HAND[1] << "," << LEFT_HAND[2] << "),\t";
	//std::cout << "�E �� :(" << RIGHT_HAND[0] << "," << RIGHT_HAND[1] << "," << RIGHT_HAND[2] << ")" << std::endl << std::endl;
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

	// �֐��錾
	void	CheckPose(int poseLevel, NUI_SKELETON_FRAME& skeleton);	//(�|�[�Y�ԍ�, ����Ώۃ{�[��)
	Vector3 GetVector3byTwoPosition(_Vector4 v41, _Vector4 v42);	//�֐ߊԂ̃x�N�g��
	float	GetAnglebyTwoVector(Vector3 v31, Vector3 v32);			//��̃x�N�g���̊p�x
	Vector2 TransformSkeltonPosition(_Vector4 pos);					//�X�P���g�����W��񎟂ɕϊ�
	float	GetDistbyTwoPosition(Vector2 pos1, Vector2 pos2);		//��_�Ԃ̋���


private:
	void Finalize();
	FONT DefaultFont;

private:
	// �ϐ��錾
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

