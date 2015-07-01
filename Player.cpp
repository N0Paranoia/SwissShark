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
	this->InitPlayer();
}

Player::~Player()
{
	//dtor
}

void Player::InitPlayer()
{
	playerRect.x = 1*TILE_SIZE;
	playerRect.y = 2*TILE_SIZE;
	playerRect.w = 3*TILE_SIZE;
	playerRect.h = 32;
	
	playerSprite.x = 1*TILE_SIZE;
	playerSprite.y = 2*TILE_SIZE;
	playerSprite.w = 240;
	playerSprite.h = 96;
	
	Xvel = 0;
	Yvel = 0;
	Jvel = 0;
	swimmingSpeed = 8;
	
	frame = 0;
	StartFrameLeft = 4;
	EndFrameLeft = 7;
	StartFrameLeftSaw = 12;
	StartFrameLeftSword = 20;
	EndFrameLeftSaw = 15;
	EndFrameLeftSword = 23;
	StartFrameRight = 0;
	EndFrameRight = 3;
	StartFrameRightSaw = 8;
	StartFrameRightSawAttack =24;
	StartFrameLeftSawAttack =26;
	StartFrameRightSword = 16;
	StartFrameRightSwordAttack =28;
	StartFrameLeftSwordAttack =30;
	EndFrameRightSaw = 11;
	EndFrameRightSawAttack = 25;
	EndFrameLeftSawAttack = 27;
	EndFrameRightSword = 19;
	EndFrameRightSawAttack = 29;
	EndFrameLeftSawAttack = 31;
	IdleFrameLeft = 4;
	IdleFrameLeftSaw = 12;
	IdleFrameLeftSword = 20;
	IdleFrameRight = 0;
	IdleFrameRightSaw = 8;
	IdleFrameRightSword = 16;
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
	
	WinObjective = {43*TILE_SIZE,9*TILE_SIZE, TILE_SIZE/4,2*TILE_SIZE};
	
	pObjects.InitObjects();
}

int Player::LoadMedia(SDL_Renderer* Renderer)
{
	//Load Player spritesheet
	if((SpriteSheetTexture.LoadFromFile(Renderer, "assets/spriteSheet.png")) == NULL)
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
		
		PlayerClips[8].x = 0 * playerSprite.w;
		PlayerClips[8].y = 2 * playerSprite.h;
		PlayerClips[8].w = playerSprite.w;
		PlayerClips[8].h = playerSprite.h;
		
		PlayerClips[9].x = 1 * playerSprite.w;
		PlayerClips[9].y = 2 * playerSprite.h;
		PlayerClips[9].w = playerSprite.w;
		PlayerClips[9].h = playerSprite.h;
		
		PlayerClips[10].x = 2 * playerSprite.w;
		PlayerClips[10].y = 2 * playerSprite.h;
		PlayerClips[10].w = playerSprite.w;
		PlayerClips[10].h = playerSprite.h;
		
		PlayerClips[11].x = 3 * playerSprite.w;
		PlayerClips[11].y = 2 * playerSprite.h;
		PlayerClips[11].w = playerSprite.w;
		PlayerClips[11].h = playerSprite.h;
		
		PlayerClips[12].x = 0 * playerSprite.w;
		PlayerClips[12].y = 3 * playerSprite.h;
		PlayerClips[12].w = playerSprite.w;
		PlayerClips[12].h = playerSprite.h;
		
		PlayerClips[13].x = 1 * playerSprite.w;
		PlayerClips[13].y = 3 * playerSprite.h;
		PlayerClips[13].w = playerSprite.w;
		PlayerClips[13].h = playerSprite.h;
		
		PlayerClips[14].x = 2 * playerSprite.w;
		PlayerClips[14].y = 3 * playerSprite.h;
		PlayerClips[14].w = playerSprite.w;
		PlayerClips[14].h = playerSprite.h;
		
		PlayerClips[15].x = 3 * playerSprite.w;
		PlayerClips[15].y = 3 * playerSprite.h;
		PlayerClips[15].w = playerSprite.w;
		PlayerClips[15].h = playerSprite.h;
		
		PlayerClips[16].x = 0 * playerSprite.w;
		PlayerClips[16].y = 4 * playerSprite.h;
		PlayerClips[16].w = playerSprite.w;
		PlayerClips[16].h = playerSprite.h;
		
		PlayerClips[17].x = 1 * playerSprite.w;
		PlayerClips[17].y = 4 * playerSprite.h;
		PlayerClips[17].w = playerSprite.w;
		PlayerClips[17].h = playerSprite.h;
		
		PlayerClips[18].x = 2 * playerSprite.w;
		PlayerClips[18].y = 4 * playerSprite.h;
		PlayerClips[18].w = playerSprite.w;
		PlayerClips[18].h = playerSprite.h;
		
		PlayerClips[19].x = 3 * playerSprite.w;
		PlayerClips[19].y = 4 * playerSprite.h;
		PlayerClips[19].w = playerSprite.w;
		PlayerClips[19].h = playerSprite.h;
		
		PlayerClips[20].x = 0 * playerSprite.w;
		PlayerClips[20].y = 5 * playerSprite.h;
		PlayerClips[20].w = playerSprite.w;
		PlayerClips[20].h = playerSprite.h;
		
		PlayerClips[21].x = 1 * playerSprite.w;
		PlayerClips[21].y = 5 * playerSprite.h;
		PlayerClips[21].w = playerSprite.w;
		PlayerClips[21].h = playerSprite.h;
		
		PlayerClips[22].x = 2 * playerSprite.w;
		PlayerClips[22].y = 5 * playerSprite.h;
		PlayerClips[22].w = playerSprite.w;
		PlayerClips[22].h = playerSprite.h;
		
		PlayerClips[23].x = 3 * playerSprite.w;
		PlayerClips[23].y = 5 * playerSprite.h;
		PlayerClips[23].w = playerSprite.w;
		PlayerClips[23].h = playerSprite.h;
		
		//Attack Animation saw Right
		PlayerClips[24].x = 4 * playerSprite.w;
		PlayerClips[24].y = 2 * playerSprite.h;
		PlayerClips[24].w = playerSprite.w;
		PlayerClips[24].h = playerSprite.h;
		
		PlayerClips[25].x = 5 * playerSprite.w;
		PlayerClips[25].y = 2 * playerSprite.h;
		PlayerClips[25].w = playerSprite.w;
		PlayerClips[25].h = playerSprite.h;
		//Attack Animation saw Left
		PlayerClips[26].x = 4 * playerSprite.w;
		PlayerClips[26].y = 3 * playerSprite.h;
		PlayerClips[26].w = playerSprite.w;
		PlayerClips[26].h = playerSprite.h;
		
		PlayerClips[27].x = 5 * playerSprite.w;
		PlayerClips[27].y = 3 * playerSprite.h;
		PlayerClips[27].w = playerSprite.w;
		PlayerClips[27].h = playerSprite.h;
		
		//Attack Animation sword Right
		PlayerClips[28].x = 4 * playerSprite.w;
		PlayerClips[28].y = 4 * playerSprite.h;
		PlayerClips[28].w = playerSprite.w;
		PlayerClips[28].h = playerSprite.h;
		
		PlayerClips[29].x = 5 * playerSprite.w;
		PlayerClips[29].y = 4 * playerSprite.h;
		PlayerClips[29].w = playerSprite.w;
		PlayerClips[29].h = playerSprite.h;
		//Attack Animation sword Left
		PlayerClips[30].x = 4 * playerSprite.w;
		PlayerClips[30].y = 5 * playerSprite.h;
		PlayerClips[30].w = playerSprite.w;
		PlayerClips[30].h = playerSprite.h;
		
		PlayerClips[31].x = 5 * playerSprite.w;
		PlayerClips[31].y = 5 * playerSprite.h;
		PlayerClips[31].w = playerSprite.w;
		PlayerClips[31].h = playerSprite.h;
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
/*	if(pCollision.VarCollision(playerRect, pObjects.Fisherman()))
	{
		this->Health(25);
	}*/
	if(pCollision.VarCollision(playerRect, pObjects.Diver()))
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
			if(pCollision.VarCollision(AttackBox, pObjects.DiverHose()))
			{
				int killDiver = 11;
				pObjects.Update(killDiver);
				kiledDiver = true;
			}
			break;
	}
}

void Player::CheckMovingObjects(int ObjX, int ObjY, int ObjW, int ObjH)
{
	if(pCollision.CustomCollision(playerRect, ObjX, ObjY, ObjW, ObjH))
	{
		this->Health(25);
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
	if(playerRect.x < 0 || playerRect.x + playerRect.w > LEVEL_WIDTH*TILE_SIZE || pCollision.WallCollision(playerRect, tiles) || pCollision.VarCollision(playerRect, pObjects.Door()) || pCollision.VarCollision(playerRect, pObjects.DiverHose()))
	{
		playerRect.x -= Xvel;
	}
	if(Dir == up || Dir == down)
	{
		playerRect.y += Yvel;
	}
	// Vertical collision handling
	if(playerRect.y < 0 || playerRect.y + playerRect.h > LEVEL_HEIGHT*TILE_SIZE ||  pCollision.WallCollision(playerRect, tiles) || pCollision.VarCollision(playerRect, pObjects.Door()) || pCollision.VarCollision(playerRect, pObjects.DiverHose()))
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
		switch(_weaponType)
		{
			case noweapon:
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
				break;
			case saw:
			// Walking Animation
				if(FacingLeft)
				{
					if(WalkingLeft || SwimmingUp || SwimmingDown)
					{
						frame ++;
						frameCounter = 0;
						if(frame > EndFrameLeftSaw || frame < StartFrameLeftSaw)
						{
							frame = StartFrameLeftSaw;
						}
					}
					else if(isAttacking)
					{
						frame ++;
						frameCounter = 0;
						if(frame > EndFrameLeftSawAttack || frame < StartFrameLeftSawAttack)
						{
							frame = StartFrameLeftSawAttack;
						}
					}
					else
					{
						frame = IdleFrameLeftSaw;
					}
				}
				if(FacingRight)
				{
					if(WalkingRight || SwimmingUp || SwimmingDown)
					{
						frame ++;
						frameCounter = 0;
						if(frame > EndFrameRightSaw || frame < StartFrameRightSaw)
						{
							frame = StartFrameRightSaw;
						}
					}
					else if(isAttacking)
					{
						frame ++;
						frameCounter = 0;
						if(frame > EndFrameRightSawAttack || frame < StartFrameRightSawAttack)
						{
							frame = StartFrameRightSawAttack;
						}
					}
					else
					{
						frame = IdleFrameRightSaw;
					}
				}
				break;
			case sword:
			// Walking Animation
				if(FacingLeft)
				{
					if(WalkingLeft || SwimmingUp || SwimmingDown)
					{
						frame ++;
						frameCounter = 0;
						if(frame > EndFrameLeftSword || frame < StartFrameLeftSword)
						{
							frame = StartFrameLeftSword;
						}
					}
					else if(isAttacking)
					{
						frame ++;
						frameCounter = 0;
						if(frame > EndFrameLeftSwordAttack || frame < StartFrameLeftSwordAttack)
						{
							frame = StartFrameLeftSwordAttack;
						}
					}
					else
					{
						frame = IdleFrameLeftSword;
					}
				}
				if(FacingRight)
				{
					if(WalkingRight || SwimmingUp || SwimmingDown)
					{
						frame ++;
						frameCounter = 0;
						if(frame > EndFrameRightSword || frame < StartFrameRightSword)
						{
							frame = StartFrameRightSword;
						}
					}
					else if(isAttacking)
					{
						frame ++;
						frameCounter = 0;
						if(frame > EndFrameRightSwordAttack || frame < StartFrameRightSwordAttack)
						{
							frame = StartFrameRightSwordAttack;
						}
					}
					else
					{
						frame = IdleFrameRightSword;
					}
				}
				break;
		}
		cout << "Frame = " << frame << endl;
	}
	//Show collsiion box
	SDL_SetRenderDrawColor(Renderer, 0xff, 0x00, 0x00, 0xff);
	HealthBar = {10, 10, this->Health(0), 10};
	StaminBar = {10, 25, this->Energy(NULL), 10};
	SDL_RenderFillRect(Renderer, &HealthBar);
	SDL_SetRenderDrawColor(Renderer, 0x00, 0xff, 0x00, 0xFF );
	SDL_RenderFillRect(Renderer, &StaminBar);

	//Render Frame
	if(FacingLeft)
	{
		SpriteSheetTexture.Render(Renderer, (playerRect.x - TILE_SIZE) - camera->x, (playerRect.y - 32) - camera->y, &PlayerClips[frame]);
	}
	else if(FacingRight)
	{
		SpriteSheetTexture.Render(Renderer, (playerRect.x - TILE_SIZE) - camera->x, (playerRect.y - 32) - camera->y, &PlayerClips[frame]);
	}
}

void Player::Cleanup()
{
	SpriteSheetTexture.Free();
}
