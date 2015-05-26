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
	playerRect.w = 2*TILE_SIZE;
	playerRect.h = TILE_SIZE;
	Xvel = 0;
	Yvel = 0;
	Jvel = 0;
	walkingSpeed = 4;
	runningSpeed = 8;
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
	isRunning = false;

	isFalling = true;

	isClimbing = false;
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
		PlayerClips[0].x = 0 * playerRect.w;
		PlayerClips[0].y = 0 * playerRect.h;
		PlayerClips[0].w = playerRect.w;
		PlayerClips[0].h = playerRect.h;

		PlayerClips[1].x = 1 * playerRect.w;
		PlayerClips[1].y = 0 * playerRect.h;
		PlayerClips[1].w = playerRect.w;
		PlayerClips[1].h = playerRect.h;

		PlayerClips[2].x = 2 * playerRect.w;
		PlayerClips[2].y = 0 * playerRect.h;
		PlayerClips[2].w = playerRect.w;
		PlayerClips[2].h = playerRect.h;

		PlayerClips[3].x = 3 * playerRect.w;
		PlayerClips[3].y = 0 * playerRect.h;
		PlayerClips[3].w = playerRect.w;
		PlayerClips[3].h = playerRect.h;

		PlayerClips[4].x = 4 * playerRect.w;
		PlayerClips[4].y = 0 * playerRect.h;
		PlayerClips[4].w = playerRect.w;
		PlayerClips[4].h = playerRect.h;

		PlayerClips[5].x = 5 * playerRect.w;
		PlayerClips[5].y = 0 * playerRect.h;
		PlayerClips[5].w = playerRect.w;
		PlayerClips[5].h = playerRect.h;

		PlayerClips[6].x = 6 * playerRect.w;
		PlayerClips[6].y = 0 * playerRect.h;
		PlayerClips[6].w = playerRect.w;
		PlayerClips[6].h = playerRect.h;

		PlayerClips[7].x = 7 * playerRect.w;
		PlayerClips[7].y = 0 * playerRect.h;
		PlayerClips[7].w = playerRect.w;
		PlayerClips[7].h = playerRect.h;

		PlayerClips[8].x = 8 * playerRect.w;
		PlayerClips[8].y = 0 * playerRect.h;
		PlayerClips[8].w = playerRect.w;
		PlayerClips[8].h = playerRect.h;

		PlayerClips[9].x = 9 * playerRect.w;
		PlayerClips[9].y = 0 * playerRect.h;
		PlayerClips[9].w = playerRect.w;
		PlayerClips[9].h = playerRect.h;

		PlayerClips[10].x = 10 * playerRect.w;
		PlayerClips[10].y = 0 * playerRect.h;
		PlayerClips[10].w = playerRect.w;
		PlayerClips[10].h = playerRect.h;

		PlayerClips[11].x = 11 * playerRect.w;
		PlayerClips[11].y = 0 * playerRect.h;
		PlayerClips[11].w = playerRect.w;
		PlayerClips[11].h = playerRect.h;

		PlayerClips[12].x = 12 * playerRect.w;
		PlayerClips[12].y = 0 * playerRect.h;
		PlayerClips[12].w = playerRect.w;
		PlayerClips[12].h = playerRect.h;

		PlayerClips[13].x = 13 * playerRect.w;
		PlayerClips[13].y = 0 * playerRect.h;
		PlayerClips[13].w = playerRect.w;
		PlayerClips[13].h = playerRect.h;

		PlayerClips[14].x = 14 * playerRect.w;
		PlayerClips[14].y = 0 * playerRect.h;
		PlayerClips[14].w = playerRect.w;
		PlayerClips[14].h = playerRect.h;

		PlayerClips[15].x = 15 * playerRect.w;
		PlayerClips[15].y = 0 * playerRect.h;
		PlayerClips[15].w = playerRect.w;
		PlayerClips[15].h = playerRect.h;

		PlayerClips[16].x = 16 * playerRect.w;
		PlayerClips[16].y = 0 * playerRect.h;
		PlayerClips[16].w = playerRect.w;
		PlayerClips[16].h = playerRect.h;

		PlayerClips[17].x = 17 * playerRect.w;
		PlayerClips[17].y = 0 * playerRect.h;
		PlayerClips[17].w = playerRect.w;
		PlayerClips[17].h = playerRect.h;
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
				Xvel = -walkingSpeed;
				this->Move(left, tiles);
				WalkingLeft = true;
				FacingRight = false;
				FacingLeft = true;
			}
			else if(keyState[SDL_SCANCODE_D])
           {
				Xvel = walkingSpeed;
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
				Yvel = -walkingSpeed;
				this->Move(up, tiles);
			}
			else if(keyState[SDL_SCANCODE_S])
			{
				Yvel = walkingSpeed;
				this->Move(down, tiles);
			}
			
			else
			{
				_state = state_idle;
			}
			if(keyState[SDL_SCANCODE_LSHIFT] || keyState[SDL_SCANCODE_RSHIFT])
			{
				isRunning = true;
				cout << "run" << endl;
			}
			else
			{
				isRunning = false;
			}
			if(keyState[SDL_SCANCODE_SPACE])
			{
				Jvel = -jumpSpeed;
				this->Jump(tiles);
			}
			if(keyState[SDL_SCANCODE_L])
			{
				_state = state_attacking;
			}
			break;
			
		case state_jumping:

			break;
			
		case state_climbing:
			if(keyState[SDL_SCANCODE_W])
			{
				Yvel = -walkingSpeed;
				this->Move(down, tiles);
				this->Climb(up, tiles);
			}
			else if(keyState[SDL_SCANCODE_S])
			{
				Yvel = walkingSpeed;
				this->Move(down, tiles);
				this->Climb(down, tiles);
			}
			else if(keyState[SDL_SCANCODE_A] || keyState[SDL_SCANCODE_D])
			{
				isClimbing = false;
				_state = state_idle;
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

void Player::Jump(Tile* tiles[])
{
	if(isRunning)
	{
		playerRect.y += Jvel;
		isClimbing = false;
		//Jumping collision handeling
		if(playerRect.y < 0 || playerRect.y + playerRect.h > LEVEL_HEIGHT*TILE_SIZE ||  pCollision.WallCollision(playerRect, tiles))
			playerRect.y -= Jvel;
	}
}

void Player::Falling(Tile* tiles[])
{
	if(!isClimbing)
	{
		playerRect.y += GRAVITY;
		isFalling = true;
		if(pCollision.WallCollision(playerRect, tiles) || pCollision.CloudCollision(playerRect, tiles))
		{
			playerRect.y -=GRAVITY;
			isFalling = false;
		}
		if(pCollision.VarCollision(playerRect, tiles, TILE_SLOPE_LEFT))
		{
			if(playerRect.y + playerRect.h >= (TILE_SIZE - ((playerRect.x-1) + playerRect.w) % TILE_SIZE) + ((playerRect.y + playerRect.h )/ TILE_SIZE)*TILE_SIZE)
			{
				playerRect.y -=GRAVITY;
				isFalling = false;
			}
		}
		if(pCollision.VarCollision(playerRect, tiles, TILE_SLOPE_RIGHT))
		{
			if(playerRect.y + playerRect.h >= ((playerRect.x) % TILE_SIZE) + ((playerRect.y + playerRect.h)/ TILE_SIZE)*TILE_SIZE)
			{
				playerRect.y -=GRAVITY;
				isFalling = false;
			}
		}
	}
}

void Player::Climb(int Dir, Tile* tiles[])
{
	if(pCollision.VarCollision(playerRect, tiles, TILE_LADDER) || pCollision.VarCollision(playerRect, tiles, TILE_LADDER_TOP))
	{
		if(Dir == up || down)
		{
			_state = state_climbing;
			playerRect.y += Yvel;
			isClimbing = true;
			isFalling = false;
			if(playerRect.y < 0 || playerRect.y + playerRect.h > LEVEL_HEIGHT*TILE_SIZE ||  pCollision.WallCollision(playerRect, tiles))
				playerRect.y -= Yvel;
		}
	}
	else
	{
		isClimbing = false;
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

void Player::Block()
{
	if(block)
	{
		if(Energy(NULL) > blockEnergy)
		{
			if(FacingLeft)
			{
				ShieldBox = {this->playerRect.x - 10, this->playerRect.y, 10, playerRect.h};
			}
			else if(FacingRight)
			{
				ShieldBox = {this->playerRect.x + this->playerRect.w, this->playerRect.y, 10, playerRect.h};
			}
			if(!isBlocking)
			{
				Energy(blockEnergy);
				isBlocking = true;
				energyRecover = false;
			}
		}
		else
		{
			if(FacingLeft)
			{
				ShieldBox = {this->playerRect.x - 2, this->playerRect.y, 2, playerRect.h};
			}
			if(FacingRight)
			{
				ShieldBox = {this->playerRect.x + this->playerRect.w, this->playerRect.y, 2, playerRect.h};
			}
		}
	}
	else
	{
		ShieldBox = {NULL, NULL, NULL, NULL};
		isBlocking = false;
		_state = state_idle;
		energyRecover = true;
	}
}

void Player::Move(int Dir, Tile* tiles[])
{
	if(!isAttacking)
	{
		if(Dir == left || Dir == right)
			playerRect.x += Xvel;
		// Horizontal collision handling
		if(playerRect.x < 0 || playerRect.x + playerRect.w > LEVEL_WIDTH*TILE_SIZE || pCollision.WallCollision(playerRect, tiles))
			playerRect.x -= Xvel;

		if(Dir == up || Dir == down)
			playerRect.y += Yvel;
		// Vertical collision handling
		if(playerRect.y < 0 || playerRect.y + playerRect.h > LEVEL_HEIGHT*TILE_SIZE ||  pCollision.WallCollision(playerRect, tiles))
			playerRect.y -= Yvel;
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
	playerBox = {playerRect.x - camera->x, playerRect.y - camera->y, playerRect.w, playerRect.h};
	SDL_RenderDrawRect(Renderer, &playerBox);
	
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
	//Create New Rectangle for shield for the camera compisation
	Shield = {ShieldBox.x - camera->x, ShieldBox.y - camera->y, ShieldBox.w, ShieldBox.h};
	SDL_RenderFillRect(Renderer, &Shield);
}

void Player::Cleanup()
{
	SpriteSheetTexture.Free();
}