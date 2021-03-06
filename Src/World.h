#ifndef __WORLD__
#define __WORLD__


// This file contains the declaration of the class World
// The World class does not have a copy constructor or an assignment operator, for the followign reasons:

// 1 	There's no need to copy construct or assign the World
// 2 	We wouldn't want to do this anyway, because the world can contain an arbitray amount of data
// 3 	These operations wouldn't work because the world is self-referencing:
//	 	the Tracer base class contains a pointer to the world. If we wrote a correct copy constructor for the 
// 	  	Tracer class, the World copy construtor would call itself recursively until we ran out of memory. 


#include <vector>

#include "ViewPlane.h"
#include "RGBColor.h"
#include "Tracer.h"
#include "GeometricObject.h"
#include "Sphere.h"
#include "Ray.h"
#include "SingleSphere.h"
#include "Camera.h"

#include "Light.h"


using namespace std;

class World {	
	public:
	
		ViewPlane					vp;
		RGBColor					background_color;
		Tracer*						tracer_ptr;
		Sphere sphere;
		vector<GeometricObject*>	objects;		

		RGBColor*					imageBuffer;

		Camera* camera_ptr;

		int imageWidth;
		int imageHeight;

		Light* ambient_ptr;
		vector<Light*> lights;
			

	public:
	
		World(void);												
		
		~World();
								
		void add_object(GeometricObject* object_ptr);	

		void build(void);
						
		RGBColor
		max_to_one(const RGBColor& c) const;
		
		RGBColor
		clamp_to_color(const RGBColor& c) const;
		
		void
		display_pixel(const int row, const int column, const RGBColor& pixel_color) const;

		ShadeRec
		hit_objects(const Ray& ray);
		
		bool outputPPMImage(string filePath);

		void set_camera(Camera* cam_ptr);

		void add_light(Light* light_ptr);

		void set_ambient_light(Light* light_ptr);
						
	private:
		
		void delete_objects(void);
		void delete_lights(void);
};


// ------------------------------------------------------------------ add_object




#endif
