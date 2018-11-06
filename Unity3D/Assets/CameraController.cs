using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraController : MonoBehaviour {
    public int rotSpeed;
    public Transform transform;
    public float x=0f, y=0f, z=0f;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKey(KeyCode.UpArrow))
        {
            x += rotSpeed * Time.deltaTime;
        }else if (Input.GetKey(KeyCode.DownArrow))
        {
            x -= rotSpeed * Time.deltaTime;
        }else if (Input.GetKey(KeyCode.RightArrow))
        {
            y += rotSpeed * Time.deltaTime;
        }else if (Input.GetKey(KeyCode.LeftArrow))
        {
            y -= rotSpeed * Time.deltaTime;
        }
        transform.localRotation = Quaternion.Euler(x, y, z);
    }
}
