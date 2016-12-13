#ifndef __GLOSSYREFLECTIVE__
#define __GLOSSYREFLECTIVE__

#include "Phong.h"

class GlossyReflector : public Phong {
public:

	// constructors etc ...
	GlossyReflector(void);

	GlossyReflector(const GlossyReflector& rm);

	GlossyReflector& operator= (const GlossyReflector& rhs);

	virtual GlossyReflector* clone(void) const;

	~GlossyReflector(void);


	void set_samples(const int num_samples, const float exp);

	void set_kr(const float k);

	void set_exponent(const float exp);

	virtual RGBColor area_light_shade(ShadeRec& sr);

private:

	GlossySpecular* glossy_specular_brdf;
};

inline void
GlossyReflector::set_samples(const int num_samples, const float exp) {
	glossy_specular_brdf->set_samples(num_samples, exp);
}

inline void
GlossyReflector::set_kr(const float k) {
	glossy_specular_brdf->set_ks(k);
}

inline void
GlossyReflector::set_exponent(const float exp) {
	glossy_specular_brdf->set_exp(exp);
}


#endif