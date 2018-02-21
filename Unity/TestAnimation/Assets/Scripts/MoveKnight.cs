using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveKnight : MonoBehaviour {

    Animator mAni;      //Need a reference to animator to be able to talk to it
    Rigidbody2D mRB;

	// Use this for initialization
	void Start () {
        mAni = GetComponent<Animator>();        //Get Animator referecne for this GameObject
        mRB = GetComponent<Rigidbody2D>();      //Only used for physics
	}
	
	// Update is called once per frame
	void Update () {
        float   tMoveX = Input.GetAxis("Horizontal");     //Get player movement;
        bool tJump = Input.GetButton("Fire1");
        //Set the Parameters in the Animator
        mAni.SetFloat("Speed", Mathf.Abs(tMoveX));      ///Get Speed, we will deal with direction seperatly, so we only want absolute speed value
        mAni.SetInteger("Direction", (int)System.Math.Sign(tMoveX)); //Note I am using the standard Sign(), we wonat 1 for right, 0 for stop and -1 for left 
        mAni.SetBool("Jump", tJump);
	}

    private void OnTriggerEnter2D(Collider2D collision) {
        mAni.SetBool("Grounded", true);
    }

    private void OnTriggerExit2D(Collider2D collision) {
        mAni.SetBool("Grounded", false);
    }

    public  void    Jump() {
        if(mRB) {
            mRB.AddForce(Vector2.up * 10.0f, ForceMode2D.Impulse);
        }
    }
}
