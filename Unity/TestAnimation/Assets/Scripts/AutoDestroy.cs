using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AutoDestroy : MonoBehaviour {

    public  void    DestroyObject() {   //Called from Animation clip to delete the game object
        Destroy(gameObject);
    }
}
