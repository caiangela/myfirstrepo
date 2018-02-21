using System.Collections;
using System.Collections.Generic;
using UnityEngine;


[RequireComponent(typeof(Camera))]

public class TrackingCamera : MonoBehaviour {

    public  Transform   TrackedObject;

    Camera mCamera;

    Vector3 mCameraPosition;

    public  BoxCollider2D mViewRect;

    // Use this for initialization
    void Start () {
        if(TrackedObject!=null) {
            mCamera = GetComponent<Camera>();
            mCameraPosition = mCamera.transform.position;
            if (mViewRect == null) { //Keep inside Camera view
                Debug.LogWarningFormat("{0:s} No BoxCollider to define Camara Rect, camera free to track anywhere", gameObject.name);
            }
        } else {
            Debug.LogWarningFormat("{0:s} TrackedObject not set, not tracking", gameObject.name);
        }
    }

    // Update is called once per frame, locks camera to background and player
    void Update () {
        if(TrackedObject!=null) {
            float tCamHeight = mCamera.orthographicSize;
            float tCamWidth = tCamHeight * mCamera.aspect;
            if (mViewRect) {
                if (TrackedObject.transform.position.x - tCamWidth >= mViewRect.bounds.center.x - mViewRect.bounds.extents.x && TrackedObject.transform.position.x + tCamWidth <= mViewRect.bounds.center.x + mViewRect.bounds.extents.x) {
                    mCameraPosition.x = TrackedObject.position.x;
                }
                if (TrackedObject.transform.position.y - tCamHeight >= mViewRect.bounds.center.y - mViewRect.bounds.extents.y && TrackedObject.transform.position.y + tCamHeight <= mViewRect.bounds.center.y + mViewRect.bounds.extents.y) {
                    mCameraPosition.y = TrackedObject.position.y;
                }
                mCamera.transform.position = mCameraPosition;
            } else {
                mCameraPosition.x = TrackedObject.position.x;
                mCameraPosition.y = TrackedObject.position.y;
                mCamera.transform.position = mCameraPosition;
            }
        }
    }
}
