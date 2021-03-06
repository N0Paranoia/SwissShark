#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <SDL_image.h>
#include "Tile.h"
#include <iostream>
#include "Constants.h"

using namespace std;

class Player
{
	private:
		enum State
		{
			state_idle,
			state_walking,
			state_attacking,
		};

		enum Direction
		{
			left,
			right,
			up,
			down,
			jump
		};
		
		enum Weapon
		{
			noweapon,
			saw,
			sword
		};
		
		int _state;
		int _weaponType;
		
		
		const Uint8* keyState;
		int Xvel;
		int Yvel;
		int Jvel;
		int swimmingSpeed;
		int runningSpeed;

		int frame;
		int StartFrameLeft;
		int EndFrameLeft;
		int StartFrameLeftSaw;
		int StartFrameLeftSword;
		int EndFrameLeftSaw;
		int EndFrameLeftSword;
		int StartFrameRight;
		int EndFrameRight;
		int StartFrameRightSaw;
		int StartFrameRightSawAttack;
		int StartFrameLeftSawAttack;
		int StartFrameRightSword;
		int StartFrameRightSwordAttack;
		int StartFrameLeftSwordAttack;
		int EndFrameRightSaw;
		int EndFrameRightSawAttack;
		int EndFrameLeftSawAttack;
		int EndFrameRightSword;
		int EndFrameRightSwordAttack;
		int EndFrameLeftSwordAttack;
		int IdleFrameLeft;
		int IdleFrameLeftSaw;
		int IdleFrameLeftSword;
		int IdleFrameRight;
		int IdleFrameRightSaw;
		int IdleFrameRightSword;
		int frameCounter;
		int frameSpeed;
		int frameSwitch;

		int jumpCount;
		int jumpSpeed;
		int jumpHeight;

		int climbingSpeed;

		bool WalkingLeft;
		bool WalkingRight;
		bool SwimmingUp;
		bool SwimmingDown;
		bool FacingLeft;
		bool FacingRight;
		bool isRunning;
		bool isFalling;
		bool canJump;
		bool isJumping;

		bool canEnterDoor;
		bool isClimbing;

		bool attack;
		bool isAttacking;
		bool block;
		bool isBlocking;
		
		int attackEnergy;
		int blockEnergy;

		int maxEnergy;
		int energy;
		bool energyRecover;
		int maxHealth;
		int health;
		
		SDL_Rect PlayerClips[42];

		SDL_Rect HealthBar;
		SDL_Rect StaminBar;
		SDL_Rect WinObjective;
		
	public:
		//Collision box
		SDL_Rect playerRect;
		SDL_Rect playerSprite;
		
		SDL_Rect AttackBox;
		SDL_Rect WeaponBox;
		SDL_Rect WeaponSprite;

		SDL_Rect collisionBox;
		
		Player();
		virtual ~Player();
		void InitPlayer();
		void Input(Tile* tiles[]);
		int LoadMedia(SDL_Renderer* Renderer);
		void Move(int Dir, Tile* tiles[]);
		void Attack();
		void SwitchWeapon(int type);
		void CheckObjects();
		void CheckMovingObjects(int ObjX, int ObjY, int ObjW, int ObjH);
		int Health(int hit);
		int Energy(int action);
		void Render(SDL_Renderer* Renderer, SDL_Rect* camera);
		void Cleanup();
		int CheckWinStatus();
		
		bool destroyedDoor;
		bool kiledDiver;
		bool pickedUpSaw;
		bool pickedUpSword;

	protected:
};

#endif // PLAYER_H
