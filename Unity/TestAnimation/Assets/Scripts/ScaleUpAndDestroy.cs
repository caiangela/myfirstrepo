using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ScaleUpAndDestroy : MonoBehaviour {


    public  float MaxScale = 1.1f;
    public float  ScaleTime = 3.0f;

	// Use this for initialization
	void Start () {
        StartCoroutine(ScaleUp(MaxScale, 100, ScaleTime));     //Run a Coroutine to scale object
	}
	
    float   AnimCurve(float vTime, float vScaleTo) {
        return ((Mathf.Sin(vTime*Mathf.PI+3.0f*Mathf.PI/2)+1)/2.0f)*(vScaleTo-1.0f)+1.0f;      //Uses a Sin() to link the ellapsed time to the object scale
    }

    IEnumerator ScaleUp(float vMaxSize,int vSteps,float vTime) {        //Will 
        float tCurrent = 0f;
        float tStep = vTime / vSteps;
        while(tCurrent < vTime) {
            float tScale = AnimCurve(tCurrent,vMaxSize);  //Uses the animation curve function to get a new scale 
            transform.localScale = Vector3.one * tScale;        //Scale Object
            tCurrent += tStep;
            yield return new WaitForSeconds(vTime/vSteps);      //Delay until it needs to scale again
        }
        Destroy(gameObject,1.0f);       //Destroy it after 1 second
    }
}
