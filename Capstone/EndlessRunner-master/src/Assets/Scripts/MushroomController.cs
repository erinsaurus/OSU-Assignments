﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MushroomController : MonoBehaviour {

    [SerializeField] SoundEffectsManager sfx;
    [SerializeField] AudioClip squishSound;
    public Vector2 velocity;
     public bool isMovingLeft;
     public LayerMask floorMask;

     // Use this for initialization
     void Start()
     {
          GetComponent<Rigidbody2D>().freezeRotation = true;
          velocity.x = 0.5f;
          isMovingLeft = false;
     }
	
	// Update is called once per frame
	void Update () {
          MoveMushroom();          
	}


     void MoveMushroom()
     {          
           Vector3 pos = transform.localPosition;
           Vector3 scale = transform.localScale;

               
          CheckWallCollision();
          if (isMovingLeft)
          {
               pos.x -= velocity.x * Time.deltaTime;
          }
          else
          {
               pos.x += velocity.x * Time.deltaTime;
          }   

          transform.localPosition = pos;
          transform.localScale = scale;          
          
     }


     void CheckWallCollision()
     {
          bool leftCollision = Physics2D.Raycast(transform.position, Vector2.left, 0.09f, floorMask);
          bool rightCollision = Physics2D.Raycast(transform.position, Vector2.right, 0.09f, floorMask);          
          Debug.DrawRay(transform.position, Vector2.right * 0.09f, Color.red);
          Debug.DrawRay(transform.position, Vector2.left * 0.09f, Color.red);

          if (leftCollision)
          {
               isMovingLeft = false;               
          }
          else if (rightCollision)
          {
               isMovingLeft = true;               
          }
     }
}
