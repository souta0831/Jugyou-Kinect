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
	shape.InnerRadius = 1.0f;//“à‰~
	shape.OuterRadius = 2.0f;//ŠO‰~
	shape.Rings = 20;//’f–Ê
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

	model_->Move(0.0f, 0.0f, -5.0f);

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
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_Blue);
	if (color_flg_)
		return;

	GraphicsDevice.BeginScene();

	model_->Draw();

	SpriteBatch.Begin();

	SpriteBatch.Draw(*bg, bg_position_);

	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
