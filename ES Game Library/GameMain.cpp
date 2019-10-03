// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load all of your content.
/// Initialize will enumerate through any components and initialize them as well.
/// </summary>
bool GameMain::Initialize()
{
	// TODO: Add your initialization logic here
	WindowTitle(_T("ES Game Library"));

	camera_->SetView(Vector3(0, 0, -3), Vector3(0, 0, 0));
	camera_->SetPerspectiveFieldOfView(45.0, 16.0f / 9.0f, 1.0f, 10000.0f);
	GraphicsDevice.SetCamera(camera_);

	SimpleShape shape;
	shape.Type = Shape_Torus;
	shape.InnerRadius = 1.0f;//ì‡â~
	shape.OuterRadius = 2.0f;//äOâ~
	shape.Rings = 20;//ífñ 
	shape.Sides = 10;
	model_ = GraphicsDevice.CreateModelFromSimpleShape(shape);
	model_->SetPosition(0.0f, 0.0f, 500.0f);
	Material mtrl;
	mtrl.Diffuse = Color(100.0f, 100.0f, 100.0f);
	model_->SetMaterial(mtrl);

	Light light;
	light.Type = Light_Directional;
	light.Direction = Vector3_Down;
	light.Diffuse = Color(1.0f, 1.0f, 1.0f);
	GraphicsDevice.SetLight(light);

	//Kinect
	Nui().Initialize(GraphicsDevice);
	kinect = Nui().CreateKinect(0);
	kinect->ColorStreamOpen(NUI_IMAGE_RESOLUTION_640x480);
	kinect->BackgroundRemovedEnable();
	kinect->SkeletonTrackingEnable();

	kinect->CameraSetAutoExposure(TRUE);
	kinect->CameraSetAutoWhiteBalance(TRUE);
	//bone = GraphicsDevice.CreateVertexBufferUP(sizeof(NUITLVERTEX) * 80, NUITLVERTEX::FVF());

	bg = GraphicsDevice.CreateSpriteFromFile(_T("th.jpg"));
	bg_position_ = Vector3(0.0f, 0.0f,SpriteBatch_BottomMost);



	color_flg_ = 0;

	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void GameMain::Finalize()
{
	// TODO: Add your finalization logic here

}

/// <summary>
/// Allows the game to run logic such as updating the world,
/// checking for collisions, gathering input, and playing audio.
/// </summary>
/// <returns>
/// Scene continued value.
/// </returns>
int GameMain::Update()
{
   

	// TODO: Add your update logic here
	KeyboardBuffer key_buffer = Keyboard->GetBuffer();

	model_->Move(0.0f, 0.0f, -2.5f);

	Vector3 pos = model_->GetPosition();

	if (color_flg_ <= 0) {
		if (key_buffer.IsPressed(Keys_Space))
		{
			if (pos.z <= 50.0f)
				color_flg_ = 10;
		}
	}
	else {
		color_flg_--;
	}

	if (pos.z < 0)
	{
		pos.z = 500;
		model_->SetPosition(pos);
	}

	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
   UINT   num = 0;
   NUI_SKELETON_FRAME   skeleton1;

   // TODO: Add your drawing code here
   GraphicsDevice.Clear(Color_Black);

   GraphicsDevice.BeginScene();
    model_->Draw();
   //	GraphicsDevice.SetRenderState(D3DRS_ZENABLE, FALSE);
   skeleton1 = kinect->GetSkeletonFrame();

   GraphicsDevice.SetRenderStateF(PointSize, 8.0f);
   num = kinect->SkeletonFrameToTLVBone(bone, skeleton1);
   GraphicsDevice.DrawUserPrimitives(PrimitiveType_LineList,  bone,  num,  bone[0].FVF());
   num = kinect->SkeletonFrameToTLVertex(bone, skeleton1);
   GraphicsDevice.DrawUserPrimitives(PrimitiveType_PointList, bone, num, bone[0].FVF());

   SpriteBatch.Begin();
  //SpriteBatch.Draw(kinect->GetColorFrame(), Vector3(0.0f, 120.0f, 1000.0f));
   //SpriteBatch.Draw(*bg, bg_position_);

	//CheckPose(1, skeleton1);
  
	SpriteBatch.End();

	GraphicsDevice.EndScene();

	
}

void GameMain::CheckPose(int poseLevel, NUI_SKELETON_FRAME& skeleton)
{
   //	NUI_SKELETON_FRAME   skeleton;

   UINT id;
   /*
	   for(id = 0; id < NUI_SKELETON_COUNT; id++) {
		   if(skeleton.SkeletonData[id].eTrackingState == NUI_SKELETON_TRACKED)
			   break;
	   }
   */
   TRACKED_INDEX tIndex = kinect->GetTrackedIndex(skeleton);
   id = tIndex.ZFront;

   //NUI_SKELETON_POSITION_ShoulderLeft

   //êkÇ¶ÇÈÇºÉnÅ[ÉgÅI
   if (poseLevel == 1) {

	if (skeleton.SkeletonData[id].SkeletonPositions[NUI_SKELETON_POSITION_FOOT_LEFT].y
	> skeleton.SkeletonData[id].SkeletonPositions[NUI_SKELETON_POSITION_FOOT_RIGHT].y) {

	   SpriteBatch.DrawString(DefaultFont, TEXT("îºêg"), Vector2(0.0f, 10.0f), Color_Red);
	}
	SpriteBatch.DrawString(DefaultFont, Vector2(0.0f, 30.0f), Color_White, TEXT("%.2f"), skeleton.SkeletonData[id].SkeletonPositions[NUI_SKELETON_POSITION_HEAD].y);

	Vector3 Elbow_RtoShoulder_R = GetVector3byTwoPosition
	(skeleton.SkeletonData[id].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT],
	   skeleton.SkeletonData[id].SkeletonPositions[NUI_SKELETON_POSITION_SHOULDER_RIGHT]);
	Vector3 Elbow_RtoWrist_R = GetVector3byTwoPosition
	(skeleton.SkeletonData[id].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT],
	   skeleton.SkeletonData[id].SkeletonPositions[NUI_SKELETON_POSITION_WRIST_RIGHT]);

	float angle = GetAnglebyTwoVector(Elbow_RtoShoulder_R, Elbow_RtoWrist_R);

	if (angle > 0 && angle < 95)
	   SpriteBatch.DrawString(DefaultFont, TEXT("âEéËäpìx"), Vector2(0.0f, 50.0f), Color_Red);

	SpriteBatch.DrawString(DefaultFont, Vector2(0.0f, 70.0f), Color_White, TEXT("%.2f"), angle);


	if (skeleton.SkeletonData[id].SkeletonPositions[NUI_SKELETON_POSITION_SHOULDER_LEFT].z
	> skeleton.SkeletonData[id].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_LEFT].z &&
	   skeleton.SkeletonData[id].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_LEFT].z
			> skeleton.SkeletonData[id].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].z) {

	   SpriteBatch.DrawString(DefaultFont, TEXT("ç∂éË"), Vector2(0.0f, 90.0f), Color_Red);
	}
   }

}

Vector2 GameMain::TransformSkeltonPosition(_Vector4 pos)
{
   return Vector2(pos.x, pos.y);
}

Vector3 GameMain::GetVector3byTwoPosition(_Vector4 v41, _Vector4 v42)
{
   Vector3 v3;

   v3.x = v41.x - v42.x;
   v3.y = v41.y - v42.y;
   v3.z = v41.z - v42.z;
   v3 = Vector3_Normalize(v3);

   return v3;
}

float GameMain::GetAnglebyTwoVector(Vector3 v31, Vector3 v32)
{
   return MathHelper_ToDegrees(Math_Acos(Vector3_Dot(v31, v32)));
}

float GameMain::GetDistbyTwoPosition(Vector2 pos1, Vector2 pos2)
{
   float xDistance = pos2.x - pos1.x;
   float yDistance = pos2.y - pos1.y;
   float dist = sqrt(abs(pow(xDistance, 2) + pow(yDistance, 2)));

   return dist;
}
