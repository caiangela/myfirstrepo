using UnityEngine;
using UnityEngine.UI; // needed for UI.Text
using System.Collections;

public class Poing : MonoBehaviour {
  // The three objects in our game
  // note that by putting "public" in front of your variables
  // they become visible to the inspector.
  public GameObject Ball;
  public GameObject LeftBat;
  public GameObject RightBat;
  public GameObject BottomBat;

  // The scores
  public Text LeftText;
  public Text RightText;
  int losingScore = 0;
  int gainingScore = 0;

  // Speeds and dimensions
  public float DeltaT = 1.0f / 60; // Note we do not use Time.deltaTime
  public float BatSpeed = 4.0f;
  public float BallSpeed = 8.0f;
  public float CourtHeight = 3.0f;
  public float CourtWidth = 3.0f;

  // Current ball velocity
  public Vector3 BallVel = new Vector3(0, 0, 0);

  // We are always in one of these states:
  public enum State {
    ServingLeft,   // Ball is attached to the left bat about to serve.
    ServingRight,  // Ball is attached to the right bat about to serve.
    ServingUp,     // Ball is attached to the bottom bat about to serve.
    Playing,       // Ball is moving
    GameOver,      // Someone has lost.
  };
  public State state;

	// Use this for initialization
	void Start () {
    state = State.ServingLeft;
    losingScore = 0;
    gainingScore = 0;
    LeftText.text = "" + losingScore;
    RightText.text = "" + gainingScore;
	}
	
	// Update is called once per frame
	void Update () {
    // Animate the bats. This happens in all states.
    Vector3 batUp = new Vector3(0, BatSpeed * DeltaT, 0);
    Vector3 batSlide = new Vector3(BatSpeed * DeltaT, 0, 0);

    // Handle left bat
    if (Input.GetKey("w")) {
      LeftBat.transform.Translate(batUp);
    } else if (Input.GetKey("s")) {
      LeftBat.transform.Translate(-batUp);
    }

    // Handle right bat
    if (Input.GetKey("up")) {
      RightBat.transform.Translate(batUp);
    } else if (Input.GetKey("down")) {
      RightBat.transform.Translate(-batUp);
    }

    //Handle bottom bat
    if (Input.GetKey(",")) {
      BottomBat.transform.Translate(-batSlide);
    }
    else if (Input.GetKey("/")) {
      BottomBat.transform.Translate(batSlide);
    }

      switch (state) {
      case State.ServingLeft:
        // In this state we are serving
        // Stick the ball to the left bat
        Ball.transform.position = LeftBat.transform.position + new Vector3(1, 0, 0);
        if (Input.GetKey("d")) {
          state = State.Playing;
          BallVel = new Vector3(BallSpeed, BallSpeed, 0);
        }
        break;

      case State.ServingRight:
        // In this state we are serving
        // Stick the ball to the right bat
        Ball.transform.position = RightBat.transform.position + new Vector3(-1, 0, 0);
        if (Input.GetKey("left")) {
          state = State.Playing;
          BallVel = new Vector3(-BallSpeed, BallSpeed, 0);
        }
        break;

      case State.ServingUp:
       // In this state we are serving
       //Strick the ball to the bottom bat
       Ball.transform.position = BottomBat.transform.position + new Vector3(0, 1, 0);
       if (Input.GetKey(".")) {
          state = State.Playing;
          BallVel = new Vector3(BallSpeed, BallSpeed, 0);
        }
        break;

      case State.Playing:
        // In this state we are playing and must animate the ball.
        Transform t = Ball.transform;

        // move the ball
        t.Translate(BallVel * DeltaT);

        // bounce the ball
        if (t.position.y > CourtHeight) {
          t.position = new Vector3(t.position.x, CourtHeight, t.position.y);
          BallVel = new Vector3(BallVel.x, -BallSpeed, 0);
        } /*else if (t.position.y < -CourtHeight) {
          t.position = new Vector3(t.position.x, -CourtHeight, t.position.y);
          BallVel = new Vector3(BallVel.x, BallSpeed, 0);
        }*/

        // bat collision
        Vector3 leftDiff = (t.position - LeftBat.transform.position);
        Vector3 rightDiff = (t.position - RightBat.transform.position);
        Vector3 bottomDiff = (t.position - BottomBat.transform.position);
        if (BallVel.x < 0 && Mathf.Abs(leftDiff.x) < 0.4f && Mathf.Abs(leftDiff.y) < 0.8f) {
          BallVel = new Vector3(BallSpeed, BallVel.y, 0);
        } else if (BallVel.x > 0 && Mathf.Abs(rightDiff.x) < 0.4f && Mathf.Abs(rightDiff.y) < 0.8f) {
          BallVel = new Vector3(-BallSpeed, BallVel.y, 0);
        } else if (BallVel.y < 0 && Mathf.Abs(bottomDiff.y) < 0.4f && Mathf.Abs(bottomDiff.x) < 0.8f) {
          BallVel = new Vector3(BallSpeed, -BallVel.y, 0);
        }
                // new score for single player
                if (t.position.x > CourtWidth) {
                    state = State.ServingRight;
                    losingScore++;
                    LeftText.text = "" + losingScore;
                    if (losingScore == 10) state = State.GameOver;
                }
                else if (t.position.x < -CourtWidth) {
                    state = State.ServingLeft;
                    losingScore++;
                    LeftText.text = "" + losingScore;
                    if (losingScore == 10) state = State.GameOver;
                }
                else if (t.position.y < -CourtHeight) {
                    state = State.ServingUp;
                    losingScore++;
                    LeftText.text = "" + losingScore;
                    if (losingScore == 10) state = State.GameOver;
                }
                /*else if (BallVel.y < 0 && Mathf.Abs(bottomDiff.y) < 0.4f && Mathf.Abs(bottomDiff.x) < 0.8f) {
                    gainingScore++;
                    RightText.text = "" + gainingScore;
                    if (gainingScore == 10) state = State.GameOver;
                }*/
                break;
                                    /*
                                    // score
                                    if (t.position.x > CourtWidth) {
                                    state = State.ServingRight;
                                    LeftScore++;
                                    LeftText.text = "" + LeftScore;
                                    if (LeftScore == 10) state = State.GameOver;
                                    } else if (t.position.x < -CourtWidth) {
                                    state = State.ServingLeft;
                                    RightScore++;
                                    RightText.text = "" + RightScore;
                                    if (RightScore == 10) state = State.GameOver;
                                    }
                                    break;*/

        case State.GameOver:
        // The game is over, do nothing.
        break;
    }
	}
}


