#include "Player.h"
#include "Textures.h"
#include "Constants.h"
#include "Collision.h"
#include "Objects.h"

//Texture playerTexture;
Textures SpriteSheetTexture;
Collision pCollision;
Objects pObjects;

Player::Player()
{
	playerRect.x = 1*TILE_SIZE;
	playerRect.y = 2*TILE_SIZE;
	playerRect.w = 3*TILE_SIZE;
	playerRect.h = 32;
	
	playerSprite.x = 1*TILE_SIZE;
	playerSprite.y = 2*TILE_SIZE;
	playerSprite.w = 192;
	playerSprite.h = 96;
	
	WeaponSprite.x = 1*TILE_SIZE;
	WeaponSprite.y = 2*TILE_SIZE;
	WeaponSprite.w = TILE_SIZE;
	WeaponSprite.h = 20;
	
	Xvel = 0;
	Yvel = 0;
	Jvel = 0;
	swimmingSpeed = 8;
	frame = 0;
	StartFrameLeft = 4;
	EndFrameLeft = 7;
	StartFrameRight = 0;
	EndFrameRight = 3;
	IdleFrameLeft = 4;
	IdleFrameRight = 0;
	frameCounter = 0;
	frameSpeed = 12;
	frameSwitch = 60;

	jumpSpeed = 8;
	jumpCount = 0;
	jumpHeight = 60;

	WalkingLeft = false;
	WalkingRight = false;
	SwimmingUp =  false;
	SwimmingDown = false;
	FacingLeft = false;
	FacingRight = true;

	isFalling = true;

	canJump = true;
	isJumping = false;

	attack = false;
	isAttacking = false;
	block = false;
	isBlocking = false;

	maxHealth = 100;
	health = maxHealth;
	maxEnergy = 100;
	energy = maxEnergy;
	energyRecover = true;

	attackEnergy = 25;
	blockEnergy = 25;

	_state = state_idle;
	
	destroyedDoor = false;
	kiledDiver = false;
	pickedUpSaw = false;
	pickedUpSword = false;
	
	_weaponType = noweapon;
	
	WinObjective = {43*TILE_SIZE,9*TILE_SIZE, TILE_SIZE,2*TILE_SIZE};
}

Player::~Player()
{
	//dtor
}

int Player::LoadMedia(SDL_Renderer* Renderer)
{
	//Load Player spritesheet
	if((SpriteSheetTexture.LoadFromFile(Renderer, "../assets/spriteSheet.png")) == NULL)
	{
		cout << "Unable to load Player Texture! SDL_Error: " << SDL_GetError() << endl;
		return false;
	}
	else
	{
		PlayerClips[0].x = 0 * playerSprite.w;
		PlayerClips[0].y = 0 * playerSprite.h;
		PlayerClips[0].w = playerSprite.w;
		PlayerClips[0].h = playerSprite.h;

		PlayerClips[1].x = 1 * playerSprite.w;
		PlayerClips[1].y = 0 * playerSprite.h;
		PlayerClips[1].w = playerSprite.w;
		PlayerClips[1].h = playerSprite.h;

		PlayerClips[2].x = 2 * playerSprite.w;
		PlayerClips[2].y = 0 * playerSprite.h;
		PlayerClips[2].w = playerSprite.w;
		PlayerClips[2].h = playerSprite.h;

		PlayerClips[3].x = 3 * playerSprite.w;
		PlayerClips[3].y = 0 * playerSprite.h;
		PlayerClips[3].w = playerSprite.w;
		PlayerClips[3].h = playerSprite.h;
		
		PlayerClips[4].x = 0 * playerSprite.w;
		PlayerClips[4].y = 1 * playerSprite.h;
		PlayerClips[4].w = playerSprite.w;
		PlayerClips[4].h = playerSprite.h;

		PlayerClips[5].x = 1 * playerSprite.w;
		PlayerClips[5].y = 1 * playerSprite.h;
		PlayerClips[5].w = playerSprite.w;
		PlayerClips[5].h = playerSprite.h;

		PlayerClips[6].x = 2 * playerSprite.w;
		PlayerClips[6].y = 1 * playerSprite.h;
		PlayerClips[6].w = playerSprite.w;
		PlayerClips[6].h = playerSprite.h;

		PlayerClips[7].x = 3 * playerSprite.w;
		PlayerClips[7].y = 1 * playerSprite.h;
		PlayerClips[7].w = playerSprite.w;
		PlayerClips[7].h = playerSprite.h;
		
		PlayerClips[8].x = 0 * WeaponSprite.w;
		PlayerClips[8].y = 2 * playerSprite.h;
		PlayerClips[8].w = WeaponSprite.w;
		PlayerClips[8].h = WeaponSprite.h;
		
		PlayerClips[9].x = 1 * WeaponSprite.w;
		PlayerClips[9].y = 2 * playerSprite.h;
		PlayerClips[9].w = WeaponSprite.w;
		PlayerClips[9].h = WeaponSprite.h;
		
		PlayerClips[10].x = 0 * WeaponSprite.w;
		PlayerClips[10].y = 2 * playerSprite.h + 1*WeaponSprite.h;
		PlayerClips[10].w = WeaponSprite.w;
		PlayerClips[10].h = WeaponSprite.h;
		
		PlayerClips[11].x = 1 * WeaponSprite.w;
		PlayerClips[11].y = 2 * playerSprite.h +1*WeaponSprite.h;
		PlayerClips[11].w = WeaponSprite.w;
		PlayerClips[11].h = WeaponSprite.h;
		
		PlayerClips[12].x = 3 * WeaponSprite.w;
		PlayerClips[12].y = 2 * playerSprite.h;
		PlayerClips[12].w = WeaponSprite.w;
		PlayerClips[12].h = WeaponSprite.h;
		
		PlayerClips[13].x = 4 * WeaponSprite.w;
		PlayerClips[13].y = 2 * playerSprite.h;
		PlayerClips[13].w = WeaponSprite.w;
		PlayerClips[13].h = WeaponSprite.h;
		
		PlayerClips[14].x = 3 * WeaponSprite.w;
		PlayerClips[14].y = 2 * playerSprite.h + 1*WeaponSprite.h;
		PlayerClips[14].w = WeaponSprite.w;
		PlayerClips[14].h = WeaponSprite.h;
		
		PlayerClips[15].x = 4 * WeaponSprite.w;
		PlayerClips[15].y = 2 * playerSprite.h +1*WeaponSprite.h;
		PlayerClips[15].w = WeaponSprite.w;
		PlayerClips[15].h = WeaponSprite.h;
	}
	return true;
}

void Player::Input(Tile* tiles[])
{
    WalkingLeft = false;
    WalkingRight = false;

    keyState = SDL_GetKeyboardState(NULL);

    switch(_state)
	{
		case state_idle:
			Xvel = 0;
			Yvel = 0;
			SwimmingUp = false;
			SwimmingDown = false;
			WalkingLeft = false;
			WalkingRight = false;
			if(keyState[SDL_SCANCODE_A])
			{
				_state = state_walking;
			}
			if(keyState[SDL_SCANCODE_D])
			{
				_state = state_walking;
			}
			if(keyState[SDL_SCANCODE_S])
			{
				_state = state_walking;
			}
			if(keyState[SDL_SCANCODE_W])
			{
				_state = state_walking;
			}
			if(!keyState[SDL_SCANCODE_W])
			{
				canEnterDoor = true;
			}
			if(keyState[SDL_SCANCODE_L])
			{
				_state = state_attacking;
			}
			if(!keyState[SDL_SCANCODE_L])
			{
				isAttacking = false;
			}
			if(keyState[SDL_SCANCODE_E])
			{
				this->SwitchWeapon();
			}
			break;
			
		case state_walking:
			if(keyState[SDL_SCANCODE_A])
			{
				//To compensate fot verical movement
				if(keyState[SDL_SCANCODE_W] || keyState[SDL_SCANCODE_S])
				{
					Xvel = -(swimmingSpeed/2);
				}
				else
				{
					Xvel = -swimmingSpeed;
				}
				this->Move(left, tiles);
				this->CheckObjects();
				WalkingLeft = true;
				FacingRight = false;
				FacingLeft = true;
			}
			else if(keyState[SDL_SCANCODE_D])
			{
				//To compensate fot verical movement
				if(keyState[SDL_SCANCODE_W] || keyState[SDL_SCANCODE_S])
				{
					Xvel = swimmingSpeed/2;
				}
				else
				{
					Xvel = swimmingSpeed;
				}
				this->Move(right, tiles);
				this->CheckObjects();
				WalkingRight = true;
				FacingLeft = false;
				FacingRight = true;
			}
			else
			{
				_state = state_idle;
			}
			if (keyState[SDL_SCANCODE_W])
			{
				//To compensate fot verical movement
				if(keyState[SDL_SCANCODE_A] || keyState[SDL_SCANCODE_D])
				{
					Yvel = -(swimmingSpeed/2);
				}
				else
				{
					Yvel = -swimmingSpeed;
				}
				SwimmingUp = true;
				this->CheckObjects();
				this->Move(up, tiles);
			}
			else if(keyState[SDL_SCANCODE_S])
			{
				//To compensate fot verical movement
				if(keyState[SDL_SCANCODE_A] || keyState[SDL_SCANCODE_D])
				{
					Yvel = swimmingSpeed/2;
				}
				else
				{
					Yvel = swimmingSpeed;
				}
				SwimmingDown = true;
				this->CheckObjects();
				this->Move(down, tiles);
			}			
			else
			{
				_state = state_idle;
			}
			if(keyState[SDL_SCANCODE_L])
			{
				_state = state_attacking;
			}
			if(keyState[SDL_SCANCODE_E])
			{
				this->SwitchWeapon();
			}
			break;
			
		case state_attacking:
			if(keyState[SDL_SCANCODE_L])
			{
				attack = true;
				this->Attack();
				this->CheckObjects();
			}
			else
			{
				attack = false;
				this->Attack();
			}
			break;
	}
}

void Player::CheckObjects()
{
	if(pCollision.VarCollision(playerRect, pObjects.Fisherman()))
	{
		this->Health(25);
	}
	switch(_weaponType)
	{
		case noweapon:
			if(pCollision.VarCollision(playerRect, pObjects.Item_Saw()))
			{
				int pickupSaw = 1;
				pObjects.Update(pickupSaw);
				pickedUpSaw = true;
				_weaponType = saw;
			}
			if(pCollision.VarCollision(playerRect, pObjects.Item_Sword()))
			{
				int pickupSword = 2;
				pObjects.Update(pickupSword);
				pickedUpSword = true;
				_weaponType = sword;
			}
			break;
		case saw:
			if(pCollision.VarCollision(playerRect, pObjects.Item_Sword()))
			{
				int pickupSword = 2;
				pObjects.Update(pickupSword);
				pickedUpSword = true;
				_weaponType = sword;
			}
			if(pCollision.VarCollision(AttackBox, pObjects.Door()))
			{
				int openDoor = 10;
				pObjects.Update(openDoor);
				destroyedDoor = true;
			}
			break;
		case sword:
			if(pCollision.VarCollision(playerRect, pObjects.Item_Saw()))
			{
				int pickupSaw = 1;
				pObjects.Update(pickupSaw);
				pickedUpSaw = true;
				_weaponType = saw;
			}
			if(pCollision.VarCollision(AttackBox, pObjects.Diver()))
			{
				int killDiver = 11;
				pObjects.Update(killDiver);
				kiledDiver = true;
			}
			break;
	}
}

void Player::Attack()
{
	if(attack)
	{
		if(Energy(NULL) > attackEnergy)
		{
			if(FacingLeft)
			{
				if(pickedUpSaw || pickedUpSword)
				{
					AttackBox = {this->playerRect.x - TILE_SIZE, this->playerRect.y + (playerRect.h/2 - 4), TILE_SIZE, 10};
				}
			}
			else if(FacingRight)
			{
				if(pickedUpSaw || pickedUpSword)
				{
					AttackBox = {this->playerRect.x + this->playerRect.w, this->playerRect.y + (playerRect.h/2 - 4), TILE_SIZE, 10};
				}
			}
			if(!isAttacking)
			{
				Energy(attackEnergy);
				isAttacking = true;
				energyRecover = false;
			}
		}
		else
		{
			if(FacingLeft)
			{
				AttackBox = {this->playerRect.x - TILE_SIZE, this->playerRect.y + (playerRect.h/2 - 4), NULL, NULL};
			}
			else if(FacingRight)
			{
				AttackBox = {this->playerRect.x + this->playerRect.w, this->playerRect.y + (playerRect.h/2 - 4), NULL, NULL};
			}
		}
	}
	else
	{
		AttackBox = {NULL, NULL, NULL, NULL};
		isAttacking = false;
		_state = state_idle;
		energyRecover = true;
	}
}

void Player::SwitchWeapon()
{
	switch(_weaponType)
	{
		case saw:
			if(pickedUpSword)
			{
				_weaponType = sword;
			}
			break;
		case sword:
			if(pickedUpSaw)
			{
				_weaponType = saw;
			}
			break;
	}
}

int Player::CheckWinStatus()
{
	if(pCollision.VarCollision(playerRect, WinObjective))
	{
		return 1;
	}
	return 0;
}

void Player::Move(int Dir, Tile* tiles[])
{
	if(Dir == left || Dir == right)
	{
		playerRect.x += Xvel;
	}
	// Horizontal collision handling
	if(playerRect.x < 0 || playerRect.x + playerRect.w > LEVEL_WIDTH*TILE_SIZE || pCollision.WallCollision(playerRect, tiles) || pCollision.VarCollision(playerRect, pObjects.Door()) || pCollision.VarCollision(playerRect, pObjects.Diver()))
	{
		playerRect.x -= Xvel;
	}
	if(Dir == up || Dir == down)
	{
		playerRect.y += Yvel;
	}
	// Vertical collision handling
	if(playerRect.y < 0 || playerRect.y + playerRect.h > LEVEL_HEIGHT*TILE_SIZE ||  pCollision.WallCollision(playerRect, tiles) || pCollision.VarCollision(playerRect, pObjects.Door()) || pCollision.VarCollision(playerRect, pObjects.Diver()))
	{
		playerRect.y -= Yvel;
	}
}

int Player::Health(int hit)
{
	health = health - hit;
	if(health <=0)
	{
		health =0;
	}
	return health;
}

int Player::Energy(int action)
{
	if(energy <= 0)
	{
		energy = 0;
	}
	if(energyRecover && action == NULL && energy < maxEnergy)
	{
		energy ++;
	}
	energy = energy - action;
	return energy;
}

void Player::Render(SDL_Renderer* Renderer, SDL_Rect* camera)
{
	frameCounter += frameSpeed;
	if(frameCounter > frameSwitch)
	{
		// Walking Animation
		if(FacingLeft)
		{
			if(WalkingLeft || SwimmingUp || SwimmingDown)
			{
				frame ++;
				frameCounter = 0;
				if(frame > EndFrameLeft || frame < StartFrameLeft)
				{
					frame = StartFrameLeft;
				}
			}
			else
			{
				frame = IdleFrameLeft;
			}
		}
		if(FacingRight)
		{
			if(WalkingRight || SwimmingUp ||SwimmingDown)
			{
				frame ++;
				frameCounter = 0;
				if(frame > EndFrameRight || frame < StartFrameRight)
				{
					frame = StartFrameRight;
				}
			}
			else
			{
				frame = IdleFrameRight;
			}
		}
	}
	//Show collsiion box
	SDL_SetRenderDrawColor(Renderer, 0xff, 0x00, 0x00, 0xff);
	HealthBar = {10, 10, this->Health(0), 10};
	StaminBar = {10, 25, this->Energy(NULL), 10};
	SDL_RenderFillRect(Renderer, &HealthBar);
	SDL_RenderDrawRect(Renderer, &playerRect);
	SDL_SetRenderDrawColor(Renderer, 0x00, 0xff, 0x00, 0xFF );
	SDL_RenderFillRect(Renderer, &StaminBar);

	//Render Frame
	if(FacingLeft)
	{
		SpriteSheetTexture.Render(Renderer, playerRect.x - camera->x, (playerRect.y - 32) - camera->y, &PlayerClips[frame]);
		switch(_weaponType)
		{
			case saw:
				if(isAttacking)
				{
					SpriteSheetTexture.Render(Renderer, (this->playerRect.x - 40) - camera->x, (this->playerRect.y + (playerRect.h/2 - 8)) - camera->y, &PlayerClips[11]);
				}
				else
				{
					SpriteSheetTexture.Render(Renderer, (this->playerRect.x - 40) - camera->x, (this->playerRect.y + (playerRect.h/2 - 8)) - camera->y, &PlayerClips[10]);
				}
				break;
			case sword:
				if(isAttacking)
				{
					SpriteSheetTexture.Render(Renderer, (this->playerRect.x - 40) - camera->x, (this->playerRect.y + (playerRect.h/2 - 8)) - camera->y, &PlayerClips[15]);
				}
				else
				{
					SpriteSheetTexture.Render(Renderer, (this->playerRect.x - 40) - camera->x, (this->playerRect.y + (playerRect.h/2 - 8)) - camera->y, &PlayerClips[14]);
				}
				break;
			case noweapon:
				break;
		}
	}
	else if(FacingRight)
	{
		SpriteSheetTexture.Render(Renderer, playerRect.x - TILE_SIZE - camera->x, (playerRect.y - 32) - camera->y, &PlayerClips[frame]);
		switch(_weaponType)
		{
			case saw:
				if(isAttacking)
				{
					SpriteSheetTexture.Render(Renderer, (this->playerRect.x + (this->playerRect.w - 8)) - camera->x, (this->playerRect.y + (playerRect.h/2 - 8)) - camera->y, &PlayerClips[9]);
				}
				else
				{
					SpriteSheetTexture.Render(Renderer, (this->playerRect.x + (this->playerRect.w - 8)) - camera->x, (this->playerRect.y + (playerRect.h/2 - 8)) - camera->y, &PlayerClips[8]);
				}
				break;
			case sword:
				if(isAttacking)
				{
					SpriteSheetTexture.Render(Renderer, (this->playerRect.x + (this->playerRect.w - 8)) - camera->x, (this->playerRect.y + (playerRect.h/2 - 8)) - camera->y, &PlayerClips[13]);
				}
				else
				{
					SpriteSheetTexture.Render(Renderer, (this->playerRect.x + (this->playerRect.w - 8)) - camera->x, (this->playerRect.y + (playerRect.h/2 - 8)) - camera->y, &PlayerClips[12]);
				}
				break;
			case noweapon:
				break;
		}
	}
}

void Player::Cleanup()
{
	SpriteSheetTexture.Free();
}