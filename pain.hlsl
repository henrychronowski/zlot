//Global Functions

#define MAX_DIST 10000.0
#define MAX_STEPS 100
#define EPSILON 0.0001

float sceneSDF(float3 pos)
{
    return lenght(pos) - 40.0f;
}

float raymarch(float3 camPos, float3 rayDir)
{
    float length = 0;

    for(int i = 0; i < MAX_SEPS; i++)
    {
        float3 nextPos = camPos + (rayDir * length);

        float dist = sceneSDF(nextPos);

        length += dist;

        if(dist <= EPSILON || depth > MAX_DIST)
            break;
    }
    return length;
}

float3 estimateNormals(float3 pos) {
  return normalize( float3(
  	sceneSDF(float3( pos.x + EPSILON, pos.yz ) )
    - sceneSDF(float3( pos.x - EPSILON, pos.yz) ),
    sceneSDF( float3( pos.x, pos.y + EPSILON, pos.z) )
    - sceneSDF( float3( pos.x, pos.y - EPSILON, pos.z ) ),
    sceneSDF( float3(pos.xy, pos.z + EPSILON) )
    - sceneSDF( float3( pos.xy, pos.z - EPSILON ) )
  ));
}



// Ray March node

float length = raymarch(CameraPosition, RayDirection);

if(length >= MAX_DIST)
    return float4(0.0, 0.0, 0.0, 0.0);

//float3 normal = estimateNormals( CameraPosition + (RayDirection * length));
//return float4( normal, 1.0 );
float3 lightDir = normalize( float3( -0.3, -1.0, -0.3 ));

float3 normal = estimateNormals( CameraPosition + RayDirection*length);

// the diffuse color of the surface
float3 diffuseColor = float3( 0.8, 0.2, 0.0 );

// calculate the amount of light hitting the surface
float diffuseLight = clamp( dot( -lightDir, normal ), 0, 1 );

// amount of ambient light applied to entire surface
float ambientLight = 0.2;

// calculate specular reflections
float3 reflectDir = reflect( -lightDir, normal );
float specular = pow( clamp( dot( reflectDir, RayDirection ), 0.0, 1.0 ), 16.0 );


float3 result = (diffuseLight + ambientLight) * diffuseColor + specular;
return float4(result, 1.0);
