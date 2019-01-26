typedef float4 point;
typedef float4 vector;
typedef float4 color;
typedef float4 sphere;

vector
Bounce( vector in, vector n )
{
	vector out = in - n*(vector)( 2.*dot(in.xyz, n.xyz) );
	out.w = 0.;
	return out;
}

vector
BounceSphere( point p, vector v, sphere s )
{
	vector n;
	n.xyz = fast_normalize( p.xyz - s.xyz );
	n.w = 0.;
	return Bounce( v, n );
}

bool
IsInsideSphere( point p, sphere s )
{
	float r = fast_length( p.xyz - s.xyz );
	return  ( r < s.w );
}

kernel
void
Particle( global point *dPobj, global vector *dVel, global color *dCobj )
{
	const float4 G = (float4) (0., -9.8, 0., 0.);
	const float  DT = 0.1;
	const sphere Sphere1 = (sphere)(0., -1000., 0., 1000.); // Internal sphere
	const sphere Sphere2 = (sphere)(0., 0., 0., 2400.); // Bounding sphere
	int gid = get_global_id(0);

	point  p = dPobj[gid];
	vector v = dVel[gid];

	point  pp = p + v*DT + G*(point)(.5*DT*DT);
	vector vp = v + G*DT;
	pp.w = 1.;
	vp.w = 0.;

	// Detect collision with the smalller, internal sphere.
	if (IsInsideSphere(pp, Sphere1))
	{
		vp = BounceSphere(p, v, Sphere1);
		pp = p + vp*DT + G*(point)(.5*DT*DT);
		color c1 = (color)(.3, .3, 1., 1.);
		dCobj[gid] = c1;
	}

	// Detect collision with the larger, bounding sphere.
	if (!IsInsideSphere(pp, Sphere2))
	{
		vp = BounceSphere(p, v, Sphere2);
		pp = p + vp*DT + G*(point)(.5*DT*DT);
		color c2 = (color)(0.25, 9., 0.25, 1.);
		dCobj[gid] = c2;
	}

	// Update the particle's position and velocity.
	dPobj[gid] = pp;
	dVel[gid] = vp;

}

