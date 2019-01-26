﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class DeathArea : MonoBehaviour {

     private void OnTriggerEnter2D(Collider2D collision)
     {
          if (collision.gameObject.layer == LayerMask.NameToLayer("enemyLayer"))
          {
              if (!Globals.TwoPlayer)
              {
                  Destroy(collision.gameObject);
              }
          }
          else if (collision.gameObject.tag == "Player")
          {
              StartCoroutine(collision.GetComponent<Player_Move>().Die());
          }

     }
}
