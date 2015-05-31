#include "Player.h"
#include "Textures.h"
#include "Constants.h"
#include "Collision.h"
#include "Doors.h"

//Texture playerTexture;
Textures SpriteSheetTexture;
Collision pCollision;
Doors pDoors;

Player::Player()
{
	playerRect.x = 1*TILE_SIZE;
	playerRect.y = 2*TILE_SIZE;
	playerRect.w = 3*TILE_SIZE;
	playerRect.h = TILE_SIZE;
	
	playerSprite.x = 1*TILE_SIZE;
	playerSprite.y = 2*TILE_SIZE;
	playerSprite.w = 3*TILE_SIZE;
	playerSprite.h = TILE_SIZE;
	
	Xvel = 0;
	Yvel = 0;
	Jvel = 0;
	swimmingSpeed = 8;
	frame = 0;
	StartFrameLeft = 7;
	EndFrameLeft = 0;
	StartFrameRight = 10;
	EndFrameRight = 17;
	IdleFrameLeft = 8;
	IdleFrameRight = 9;
	frameCounter = 0;
	frameSpeed = 12;
	frameSwitch = 60;

	jumpSpeed = 8;
	jumpCount = 0;
	jumpHeight = 60;

	WalkingLeft = false;
	WalkingLeft = false;
	FacingLeft = false;
	FacingRight = true;

	isFalling = true;


	canEnterDoor = true;

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
	
	int _state = state_idle;
}

Player::~Player()
{
	//dtor
}

int Player::LoadMedia(SDL_Renderer* Renderer)
{
	//Load Player spritesheet
	if((SpriteSheetTexture.LoadFromFile(Renderer, "../assets/spriteSheet48.png")) == NULL)
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

		PlayerClips[4].x = 4 * playerSprite.w;
		PlayerClips[4].y = 0 * playerSprite.h;
		PlayerClips[4].w = playerSprite.w;
		PlayerClips[4].h = playerSprite.h;

		PlayerClips[5].x = 5 * playerSprite.w;
		PlayerClips[5].y = 0 * playerSprite.h;
		PlayerClips[5].w = playerSprite.w;
		PlayerClips[5].h = playerSprite.h;

		PlayerClips[6].x = 6 * playerSprite.w;
		PlayerClips[6].y = 0 * playerSprite.h;
		PlayerClips[6].w = playerSprite.w;
		PlayerClips[6].h = playerSprite.h;

		PlayerClips[7].x = 7 * playerSprite.w;
		PlayerClips[7].y = 0 * playerSprite.h;
		PlayerClips[7].w = playerSprite.w;
		PlayerClips[7].h = playerSprite.h;

		PlayerClips[8].x = 8 * playerSprite.w;
		PlayerClips[8].y = 0 * playerSprite.h;
		PlayerClips[8].w = playerSprite.w;
		PlayerClips[8].h = playerSprite.h;

		PlayerClips[9].x = 0 * playerSprite.w;
		PlayerClips[9].y = 1 * playerSprite.h;
		PlayerClips[9].w = playerSprite.w;
		PlayerClips[9].h = playerSprite.h;

		PlayerClips[10].x = 1 * playerSprite.w;
		PlayerClips[10].y = 1 * playerSprite.h;
		PlayerClips[10].w = playerSprite.w;
		PlayerClips[10].h = playerSprite.h;

		PlayerClips[11].x = 2 * playerSprite.w;
		PlayerClips[11].y = 1 * playerSprite.h;
		PlayerClips[11].w = playerSprite.w;
		PlayerClips[11].h = playerSprite.h;

		PlayerClips[12].x = 3 * playerSprite.w;
		PlayerClips[12].y = 1 * playerSprite.h;
		PlayerClips[12].w = playerSprite.w;
		PlayerClips[12].h = playerSprite.h;

		PlayerClips[13].x = 4 * playerSprite.w;
		PlayerClips[13].y = 1 * playerSprite.h;
		PlayerClips[13].w = playerSprite.w;
		PlayerClips[13].h = playerSprite.h;

		PlayerClips[14].x = 5 * playerSprite.w;
		PlayerClips[14].y = 1 * playerSprite.h;
		PlayerClips[14].w = playerSprite.w;
		PlayerClips[14].h = playerSprite.h;

		PlayerClips[15].x = 6 * playerSprite.w;
		PlayerClips[15].y = 1 * playerSprite.h;
		PlayerClips[15].w = playerSprite.w;
		PlayerClips[15].h = playerSprite.h;

		PlayerClips[16].x = 7 * playerSprite.w;
		PlayerClips[16].y = 1 * playerSprite.h;
		PlayerClips[16].w = playerSprite.w;
		PlayerClips[16].h = playerSprite.h;

		PlayerClips[17].x = 8 * playerSprite.w;
		PlayerClips[17].y = 1 * playerSprite.h;
		PlayerClips[17].w = playerSprite.w;
		PlayerClips[17].h = playerSprite.h;
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
			break;
			
		case state_attacking:
			if(keyState[SDL_SCANCODE_L])
			{
				attack = true;
				this->Attack();
			}
			else
			{
				attack = false;
				this->Attack();
			}
			break;
	}
}

void Player::GoTroughDoor(Tile* tiles[])
{
	if(pCollision.VarCollision(playerRect, tiles, TILE_DOOR))
	{
		if(canEnterDoor)
		{
			pDoors.Connection(&playerRect, NULL);
			canEnterDoor = false;
		}
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
				SwordBox = {this->playerRect.x - TILE_SIZE, this->playerRect.y + (TILE_SIZE/2 - 5), TILE_SIZE, 10};
			}
			else if(FacingRight)
			{
				SwordBox = {this->playerRect.x + this->playerRect.w, this->playerRect.y + (TILE_SIZE/2 - 5), TILE_SIZE, 10};
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
				SwordBox = {this->playerRect.x - TILE_SIZE, this->playerRect.y + TILE_SIZE/2, NULL, NULL};
			}
			else if(FacingRight)
			{
				SwordBox = {this->playerRect.x + this->playerRect.w, this->playerRect.y + TILE_SIZE/2, NULL, NULL};
			}
		}
	}
	else
	{
		SwordBox = {NULL, NULL, NULL, NULL};
		isAttacking = false;
		_state = state_idle;
		energyRecover = true;
	}
}

void Player::Move(int Dir, Tile* tiles[])
{
	if(Dir == left || Dir == right)
	{
		playerRect.x += Xvel;
	}
	// Horizontal collision handling
	if(playerRect.x < 0 || playerRect.x + playerRect.w > LEVEL_WIDTH*TILE_SIZE || pCollision.WallCollision(playerRect, tiles))
	{
		playerRect.x -= Xvel;
	}
	if(Dir == up || Dir == down)
	{
		playerRect.y += Yvel;
	}
	// Vertical collision handling
	if(playerRect.y < 0 || playerRect.y + playerRect.h > LEVEL_HEIGHT*TILE_SIZE ||  pCollision.WallCollision(playerRect, tiles))
	{
		playerRect.y -= Yvel;
	}
	//Slanted tiles collision handling
	if(pCollision.VarCollision(playerRect, tiles, TILE_SLOPE_LEFT) && Dir == right)
	{
		if((playerRect.x + playerRect.w) % TILE_SIZE == 0)
		{
			//Counters that the sum is 0 because he is entering the next tile (the playerRect.x -1 as used in the fall method leads to other collision problems)
			playerRect.y = TILE_SIZE - (TILE_SIZE) + ((playerRect.y-1)/ TILE_SIZE)*TILE_SIZE;
		}
		else if(TILE_SIZE - (playerRect.x + playerRect.w) % TILE_SIZE == 4)
		{
			//Counters going to fast and colliding in to next block
			playerRect.y = ((playerRect.y / TILE_SIZE) * TILE_SIZE)-4;
		}
		else if(playerRect.y + playerRect.h != (TILE_SIZE - ((playerRect.x) + playerRect.w) % TILE_SIZE) + ((playerRect.y + playerRect.h )/ TILE_SIZE)*TILE_SIZE)
		{
			playerRect.y = (TILE_SIZE - ((playerRect.x) + playerRect.w) % TILE_SIZE) + ((playerRect.y-1)/ TILE_SIZE)*TILE_SIZE;
		}
	}
	if(pCollision.VarCollision(playerRect, tiles, TILE_SLOPE_RIGHT) && Dir == left)
	{
		if((playerRect.x) % TILE_SIZE == 4)
		{
			//Counters getting stuck when running
			playerRect.y = ((playerRect.x-4) % TILE_SIZE) + ((playerRect.y-1)/ TILE_SIZE)*TILE_SIZE;
		}
		else if(playerRect.y + playerRect.h != ((playerRect.x) % TILE_SIZE) + ((playerRect.y + playerRect.h )/ TILE_SIZE)*TILE_SIZE)
		{
			playerRect.y = ((playerRect.x) % TILE_SIZE) + ((playerRect.y-1)/ TILE_SIZE)*TILE_SIZE;
		}
	}
}

int Player::Health()
{
	if(health <=0)
	{
		health =0;
	}
	return maxHealth;
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
		if(WalkingLeft)
		{

			frame --;
			frameCounter = 0;
			if(frame < EndFrameLeft || frame > StartFrameLeft)
			{
				frame = StartFrameLeft;
			}
		}
		else
		{
			//Idle frame left
			if(FacingLeft)
			{
				frame = IdleFrameLeft;
			}
		}
		if(WalkingRight)
		{
			frame ++;
			frameCounter = 0;
			if(frame  > EndFrameRight || frame < StartFrameRight)
			{
				frame = StartFrameRight;
			}
		}
		else
		{
			//Idle frame right
			if(FacingRight)
			{
				frame = IdleFrameRight;
			}
		}
	}
	//Show collsiion box
	SDL_SetRenderDrawColor(Renderer, 0xff, 0x00, 0x00, 0xff);
	//Create New REctangle for sword for the camera compisation
	Sword = {SwordBox.x - camera->x, SwordBox.y - camera->y, SwordBox.w, SwordBox.h};
	SDL_RenderFillRect(Renderer, &Sword);	
	HealthBar = {10, 10, this->Health(), 10};
	StaminBar = {10, 25, this->Energy(NULL), 10};
	SDL_RenderFillRect(Renderer, &HealthBar);
	SDL_SetRenderDrawColor(Renderer, 0x00, 0xff, 0x00, 0xFF );
	SDL_RenderFillRect(Renderer, &StaminBar);
	//Render Frame
	SpriteSheetTexture.Render(Renderer, playerRect.x - camera->x, playerRect.y - camera->y, &PlayerClips[frame]);
	SDL_SetRenderDrawColor(Renderer, 0x00, 0x00, 0xff, 0xff);
}

void Player::Cleanup()
{
	SpriteSheetTexture.Free();
}