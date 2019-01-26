﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class FlyingTurtleController : MonoBehaviour
{

     public float gravity;
     public Vector2 velocity;
     public bool isMovingLeft = true;
     public LayerMask groundEnemyMask;
     private Rigidbody2D rb;
     public LayerMask playerLayer;
     private bool grounded = false;
     private bool shouldDie;
     private float deathTimer = 0;
     public float timeBeforeDestroy = 1.0f;
     private Animator myAnimator;
     private bool neverHit = true;
     private bool invincible = false;
     Coroutine invincibleCoroutine = null;
     Coroutine recovering = null;
     private float recoveryWaitTime = 4f;
     private float recoveryTime = 2f;
     private bool isGrounded = true;
     private float jumpPower = 3.5f;

     public enum EnemyState
     {
          walking,
          flying,
          shellIdle,
          movingShell
     }

     public EnemyState state;

     // Use this for initialization
     void Start()
     {
          rb = GetComponent<Rigidbody2D>();
          rb.freezeRotation = true;
          enabled = false;
          gravity = 20f;
          velocity.x = 0.5f;
          myAnimator = GetComponent<Animator>();
          state = EnemyState.flying;
          myAnimator.SetBool("flying", true);
     }

     // Update is called once per frame
     void Update()
     {          
          UpdateEnemyPosition();
          CheckAbove();

          if (state == EnemyState.walking || state == EnemyState.flying)
          {
               CheckWallCollisionWalking();
          }
          else if (state == EnemyState.shellIdle)
          {
               CheckWallCollisionIdleShell();
          }
          else
          {
               CheckWallCollisionMovingShell();
          }
          //checkDeath();
     }


     private void OnBecameVisible()
     {
          enabled = true;
     }

     void UpdateEnemyPosition()
     {
          if (state != EnemyState.shellIdle && !shouldDie)
          {
               Vector3 pos = transform.localPosition;
               Vector3 scale = transform.localScale;

               if (isMovingLeft)
               {
                    pos.x -= velocity.x * Time.deltaTime;
               }
               else
               {
                    pos.x += velocity.x * Time.deltaTime;
               }
               
               if (state == EnemyState.flying)
               {
                    GroundCheck();
                    if (isGrounded == true)
                    {
                         rb.velocity = new Vector2(rb.velocity.x, jumpPower);
                    }
               }                

               transform.localPosition = pos;
               transform.localScale = scale;
          }          
     }

     void GroundCheck()
     {
          RaycastHit2D left, middle, right;
          left = Physics2D.Raycast(new Vector2(transform.localPosition.x - 0.06f, transform.localPosition.y - .1f), Vector2.down, 0.04f, groundEnemyMask);
          middle = Physics2D.Raycast(new Vector2(transform.localPosition.x, transform.localPosition.y - .1f), Vector2.down, 0.04f, groundEnemyMask);
          right = Physics2D.Raycast(new Vector2(transform.localPosition.x + 0.06f, transform.localPosition.y - .1f), Vector2.down, 0.04f, groundEnemyMask);

          if (left.collider != null || middle.collider != null || right.collider != null)
          {
               isGrounded = true;
          }
          else
          {
               isGrounded = false;
          }
     }


     void CheckWallCollisionWalking()
     {
          bool leftCollision, rightCollision;        
          leftCollision = Physics2D.Raycast(transform.position, Vector2.left, 0.1f, groundEnemyMask);
          rightCollision = Physics2D.Raycast(transform.position, Vector2.right, 0.1f, groundEnemyMask);

          if (leftCollision)
          {
               isMovingLeft = false;
               transform.localScale = new Vector2(-1f, 1f);
          }
          else if (rightCollision)
          {
               isMovingLeft = true;
               transform.localScale = new Vector2(1f, 1f);
          }
     }

     void CheckWallCollisionIdleShell()
     {
          RaycastHit2D leftCollision, rightCollision;
          leftCollision = Physics2D.Raycast(transform.position, Vector2.left, 0.097f, playerLayer);
          rightCollision = Physics2D.Raycast(transform.position, Vector2.right, 0.097f, playerLayer);          
          if (leftCollision.collider != null || rightCollision.collider != null)
          {
               if (leftCollision.collider != null)
               {                    
                    state = EnemyState.movingShell;
                    isMovingLeft = false;
                    velocity.x = 2f;
               }
               else
               {
                    state = EnemyState.movingShell;
                    isMovingLeft = true;
                    velocity.x = 2f;
               }
               StartCoroutine(Invincible());
               neverHit = false;
          }
     }
     void CheckWallCollisionMovingShell()
     {
          RaycastHit2D groundEnemyCollision;

          if (isMovingLeft)
          {
               groundEnemyCollision = Physics2D.Raycast(transform.position, Vector2.left, 0.1f, groundEnemyMask);               
          }
          else
          {
               groundEnemyCollision = Physics2D.Raycast(transform.position, Vector2.right, 0.1f, groundEnemyMask);               
          }         
          
          if (groundEnemyCollision.collider != null)
          {
               if (groundEnemyCollision.collider != null)
               {
                    if (groundEnemyCollision.collider.gameObject.layer == LayerMask.NameToLayer("enemyLayer"))
                    {
                         if (groundEnemyCollision.collider.tag == "Goomba")
                         {
                              groundEnemyCollision.collider.gameObject.GetComponent<GoombaController>().StarDeath();
                         }
                         else if (groundEnemyCollision.collider.tag == "Turtle")
                         {
                              groundEnemyCollision.collider.gameObject.GetComponent<TurtleController>().StarDeath();
                         }
                         else if (groundEnemyCollision.collider.tag == "FlyingTurtle")
                         {
                              groundEnemyCollision.collider.gameObject.GetComponent<FlyingTurtleController>().StarDeath();
                         }
                    }
                    else
                    {
                         isMovingLeft = !isMovingLeft;
                    }
               }
               else
               {
                    isMovingLeft = !isMovingLeft;
               }
          }          
     }

     void CheckAbove()
     {
          RaycastHit2D aboveLeft, aboveMiddle, aboveRight, hitRay;
          if (state == EnemyState.walking)
          {
               aboveLeft = Physics2D.Raycast(new Vector2(transform.position.x - 0.06f, transform.position.y + 0.02f), Vector2.up, 0.05f, playerLayer);
               aboveMiddle = Physics2D.Raycast(new Vector2(transform.position.x, transform.position.y + 0.02f), Vector2.up, 0.05f, playerLayer);
               aboveRight = Physics2D.Raycast(new Vector2(transform.position.x + 0.06f, transform.position.y + 0.02f), Vector2.up, 0.05f, playerLayer);
          }
          else
          {
               aboveRight = Physics2D.Raycast(new Vector2(transform.position.x - 0.08f, transform.position.y + 0.05f), Vector2.up, 0.04f, playerLayer);
               aboveMiddle = Physics2D.Raycast(new Vector2(transform.position.x, transform.position.y + 0.05f), Vector2.up, 0.04f, playerLayer);
               aboveLeft = Physics2D.Raycast(new Vector2(transform.position.x + 0.08f, transform.position.y + 0.05f), Vector2.up, 0.04f, playerLayer);
          }

          if (aboveLeft.collider != null || aboveMiddle.collider != null || aboveRight.collider != null)
          {
               if (aboveLeft.collider != null)
               {
                    hitRay = aboveLeft;
               }
               else if (aboveRight.collider != null)
               {
                    hitRay = aboveRight;
               }
               else
               {
                    hitRay = aboveMiddle;
               }

               if (hitRay.collider.tag == "Player")
               {
                    Debug.Log(hitRay);
                    OnHitAboveFromMario();
               }
          }
     }

     void OnHitAboveFromMario()
     {
          if (!invincible)
          {
               if (state == EnemyState.flying)
               {
                    state = EnemyState.walking;
                    myAnimator.SetBool("flying", false);
                    velocity.x = 0.5f;
               }
               else if (state == EnemyState.walking)
               {
                    if (neverHit)
                    {
                         StartCoroutine(Recovering());
                    }
                    
                    state = EnemyState.shellIdle;
                    velocity.x = 0;
                    myAnimator.SetBool("idleShell", true);                    
               }
               else if (state == EnemyState.shellIdle)
               {
                    neverHit = false;
                    state = EnemyState.movingShell;
                    velocity.x = 2f;
                    isMovingLeft = false;                    
               }
               else
               {
                    ScoreKeeping.scoreValue += 100;
                    state = EnemyState.shellIdle;
                    velocity.x = 0;
               }
               StartCoroutine(Invincible());
          }
     }

     public IEnumerator Invincible()
     {
          if (invincibleCoroutine != null)
          {
               StopCoroutine(invincibleCoroutine);
          }

          invincible = true;          
          yield return new WaitForSeconds(0.3f);
          invincible = false;
     }

     public IEnumerator Recovering()
     {
          float currentTime = 0f;

          while (currentTime < recoveryWaitTime)
          {
               currentTime += 0.1f;
               if (!neverHit)
               {
                    yield break;
               }
               yield return new WaitForSeconds(0.1f);
          }

          currentTime = 0;
          myAnimator.SetBool("recovering", true);
          while (currentTime < recoveryTime)
          {
               currentTime += 0.1f;
               if (!neverHit)
               {
                    myAnimator.SetBool("recovering", false);
                    yield break;
               }
               yield return new WaitForSeconds(0.1f);
          }
          state = EnemyState.walking;
          velocity.x = 0.5f;
          myAnimator.SetBool("recovering", false);
          myAnimator.SetBool("idleShell", false);
          yield return null;
     }

     public void StarDeath()
     {
          ScoreKeeping.scoreValue += 100;
          myAnimator.SetBool("idleShell", true);
          myAnimator.SetBool("flying", false);
          GetComponent<Collider2D>().enabled = false;
          transform.rotation = new Quaternion(180, 0, 0, 0);
          rb.velocity = new Vector2(0.5f, 2f);
          shouldDie = true;
     }
}
