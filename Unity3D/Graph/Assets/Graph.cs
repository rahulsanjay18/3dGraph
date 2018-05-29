using UnityEngine;

public delegate Vector3 GraphFunction(float u, float v, float t);

public enum FunctionName
{
    Sine,
    MultiSine,
    Sine2D,
    MultiSine2D,
    Ripple,
    Cylinder,
    Sphere,
    Torus
}

public class Graph : MonoBehaviour {

    public Transform pointPrefab;
    [Range(10,100)]
    public int resolution = 10;
    public FunctionName function;
    private Transform[] points;
    private GraphFunction graph;
    private const float pi = Mathf.PI;
    int i = 0;
    private GraphFunction[] functions =
    {
        Sine,
        MultiSine,
        Sine2D,
        MultiSine2DFunction,
        Ripple,
        Cylinder,
        Sphere,
        Torus
    };

    static Vector3 Sine(float x, float z, float t)
    {
        Vector3 p;
        p.x = x;
        p.y = Mathf.Sin(pi * (x + t));
        p.z = z;
        return p;
    }

    static Vector3 MultiSine(float x, float z, float t)
    {
        float y = Mathf.Sin(pi * (x + t));
        y += Mathf.Sin(2f * pi * (x + 2f * t)) / 2f;
        y *= 2f / 3f;
        Vector3 p;
        p.x = x;
        p.y = y;
        p.z = z;
        return p;
    }

    static Vector3 Sine2D(float x, float  z, float t)
    {
        float sinx = Mathf.Sin(pi * (x + t));
        float sinz = Mathf.Sin(pi * (z + t));
        Vector3 p;
        p.x = x;
        p.y = (sinx + sinz) * 0.5f;
        p.z = z;
        return p;
    }

    static Vector3 MultiSine2DFunction(float x, float z, float t)
    {
        float y = 4f * Mathf.Sin(pi * (x + z + t * 0.5f));
        y += Mathf.Sin(pi * (x + t));
        y += Mathf.Sin(2f * pi * (z + 2f * t)) * 0.5f;
        y *= 1f / 5.5f;
        Vector3 p;
        p.x = x;
        p.y = y;
        p.z = z;
        return p;
    }

    static Vector3 Ripple(float x, float z, float t)
    {
        float d = Mathf.Sqrt(x * x + z * z);
        float y = Mathf.Sin(pi * (4f * d - t));
        y /= 1f + 10f + d;
        Vector3 p;
        p.x = x;
        p.y = y;
        p.z = z;
        return p;
    }

    static Vector3 Cylinder(float u, float v, float t)
    {
        float radius = 0.8f + Mathf.Sin(pi * (6f * u + 2f * v + t)) * 0.2f;
        Vector3 p;
        p.x = radius * Mathf.Sin(pi * u);
        p.y = v;
        p.z = radius * Mathf.Cos(pi * u);
        return p;
    }

    static Vector3 Sphere(float u, float v, float t)
    {
        Vector3 p;
        float r = 0.8f + Mathf.Sin(pi * (6f * u + t)) * 0.1f;
        r += Mathf.Sin(pi * (4f * v + t)) * 0.1f;
        float s = r * Mathf.Cos(pi * 0.5f * v);
        p.x = s * Mathf.Sin(pi * u);
        p.y = r * Mathf.Sin(pi * 0.5f * v);
        p.z = s * Mathf.Cos(pi * u);
        return p;
    }

    static Vector3 Torus(float u, float v, float t)
    {
        Vector3 p;
        float r1 = 0.65f + Mathf.Sin(pi * (6f * u + t)) * 0.1f;
        float r2 = 0.2f + Mathf.Sin(pi * (4f * v + t)) * 0.05f;
        float s = r2 * Mathf.Cos(pi * v) + r1;
        p.x = s * Mathf.Sin(pi * u);
        p.y = r2 * Mathf.Sin(pi * v);
        p.z = s * Mathf.Cos(pi * u);
        return p;
    }

    void Awake()
    {
        float step = 2f / resolution;
        Vector3 scale = Vector3.one * step;
        Vector3 position;
        position.y = 0f;
        position.z = 0f;
        points = new Transform[resolution * resolution];
        for (int i = 0; i < points.Length; i++)
        {
            Transform point = Instantiate(pointPrefab);
            point.localScale = scale;
            point.SetParent(transform, false);
            points[i] = point;
        }
        graph = functions[(int)function];
    }

    void Update()
    {
        float step = 2f / resolution;
        float t = Time.time;
        for (int z = 0, i = 0; z < resolution; z++)
        {
            float v = (z + 0.5f) * step - 1f;
            for (int x = 0; x < resolution; x++, i++)
            {
                float u = (x + 0.5f) * step - 1f;
                points[i].localPosition = graph(u, v, t);
            }
        }
         if (Input.GetKey(KeyCode.Keypad1))
        {
            i = 0;
        }
        else if (Input.GetKey(KeyCode.Keypad2))
        {
            i = 1;
        }
        else if (Input.GetKey(KeyCode.Keypad3))
        {
            i = 2;
        }
        else if (Input.GetKey(KeyCode.Keypad4))
        {
            i = 3;
        }
        else if (Input.GetKey(KeyCode.Keypad5))
        {
            i = 4;
        }
        else if (Input.GetKey(KeyCode.Keypad6))
        {
            i = 5;
        }
        else if (Input.GetKey(KeyCode.Keypad7))
        {
            i = 6;
        }
        else if(Input.GetKey(KeyCode.Keypad8))
        {
            i = 7;
        }
        
            graph = functions[i];
    }
}
