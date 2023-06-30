# Rendering with ray tracing

The ray-tracing algorithm, with its conceptual simplicity, involves a lot of calculations, the number of which depends on the accuracy degree in modelling the rays' travel through the scene.
As already mentioned, backward ray tracing is used in practice, i.e. the rays come from the observer's eye, as in the case of ray casting. However, the difference between these two methods is quite significant, although some of the authors of study guides see the two methods as synonymous.

With backwards ray tracing, the rays emitted from the observer not only determine the visibility of the object, but also its visual characteristics. It is enough to mathematically describe the shape of a scene object and specify a number of coefficients, and so, if the ray behavior model is described in enough detail, the pixel color itself will be obtained, without the need for additional approaches to shading or calculating the color of the object.

## Types of light sources

The intensity of a pixel is determined mostly by its degree of illumination. With backward ray tracing, this means that, in general, the visibility of a pixel is affected by whether the ray ends its path in the light source because the backward path of the ray reaching the observer's eye must, by definition, end exactly at the light source.

- A point source is a material point in space that emits rays in different directions. In practice, a model defined by a point in space and intensity is used for the backward trace. The probability of the ray hitting a material point in space is, of course, practically zero. That is why the intensity is calculated from the cosine of the angle between the vector of the ray passing near the source and the vector connecting the point of last refraction and the point source itself.

- Directional light - some point light sources are so far away and so bright, such as the sun, that its rays can be considered parallel. So it is possible to describe the light source by a three-dimensional vector and intensity. In this case, the intensity of each pixel is calculated from the cosine of the angle between the vector of the ray leaving the scene and the direction of the light source

- Global illumination - some background intensity value, or basic intensity in the shade. In the real world, completely black shadows are very rare and do not look realistic.

## Factors affecting the ray path.

In general, to calculate the illuminance of an individual pixel, the amount of light brought in by each light source is calculated and added together to get a number that represents the total amount of light a pixel receives. Then you can multiply the surface color at that point by that amount to get the exact color shade the pixel should be painted with.

The magic of ray tracing begins the moment the processing of ray collisions with objects occurs.

### Matte objects

Matte appearance of the object depends on its properties rather than the light source and determines the color of pixel. At the microscopic level, at which optics actually works, all surfaces are usually approximated by an even plane, which means that the reflected ray is calculated only according to the established properties of the object and the normal at that point as if the ray is just reflected from the plane. There are two types of reflection related to this concept: diffuse reflection and specular reflection. Matte objects have a low specular reflection, while glossy objects have a high specular reflection. Matte objects have a rough surface, and the rays behave a little more unpredictably, relative to the normal, when reflected. In other words, the more often the reflected vectors are close to the case where the angle of incidence equals the angle of reflection, the glossier the object appears. So, according to Lambert's law - the incident light scatters in all directions with the same intensity. The illuminance of a point is proportional to the fraction of its area visible from the source.

$`I_p = I_a + \sum^n_{i=1} I_i \frac{\langle \vec{N},\vec{L_i} \rangle}{|\vec{N}||\vec{L_i}|}`$, where

$`I_p`$ is the intensity at point $`p`$

$`I_a`$ is the background intensity value, scattered light

$`I_i`$ is the intensity of $`i`$ light source

$`\vec{N}`$ is the vector of the polygon normal encountered at the point $`p`$

$`\vec{L_i}`$ is the vector connecting the center of the polygon and the light source

It is also important that only those terms for which you fulfill $`\langle \vec{N},\vec{L_i} \rangle > 0`$ are summed, because a negative scalar product can occur only if the angle between the normal and the direction of the light source is obtuse.
The physical meaning of this phenomenon is that the vector of the normal to the surface becomes negative. The back of the polygon is illuminated. But since we are working with impermeable solid objects, this approach makes no sense. If you simply remove this condition and do not invert the normal, the negative intensity will make this polygon even darker than the background intensity, which also makes no sense.

#### Shadows

Usually shadows are divided into 2 types: attached shadows and cast shadows. Attached shadows appear automatically if the considerations mentioned above are followed. With cast shadows, i.e shadows cast on other objects, things are a little more complicated. For this you need to know whether the rays from the light sources overlap with other objects. Additional rays coming from light sources and capturing the first intersection with any object, are used for this purpose. Now, the ray continues its journey through this object without refraction, and if it captures another intersection, then at this point the object cannot be illuminated by the source that emitted the ray. The calculation of shadows can be optimized by using a property of shadows called shadow coherence. If some point is in the object's shadow, the point next to it will also be in this shadow. When searching for objects between a point and a light source to determine if the point is in shadow, intersections with all other objects are usually checked. However, if you know that the point just next to it is in the shadow of a certain object, you can first check the intersections with that object. If it is found, then there is no need to check all the other objects.

### Specular reflections

The specular reflection is one of the main properties that makes ray tracing stand out. Just note that in ray tracing when it hits a specular surface, the angle of incidence equals the angle of reflection, and the color of a given point is not the color of the object, but it is calculated according to the color of the reflected ray. The color after reflection can be either the background color if the reflection left the scene or the color of another object if the reflection hit that object. Moreover, the specular reflection can be combined with the object's own color and its diffuse reflection, giving the specular surface a color.

### Transparency and refraction

When the ray hits translucent objects, it splits into two: one bouncing off the object and the other passing through and refracting. The color at a point is the superposition of the two resulting colors, calculated by tracing these two rays. The degree of transparency and refraction is included in the corresponding coefficients. If the object is completely transparent, i.e. transparency coefficient is equal to one, there is no reflection, and the ray is only refracted.

But since the speed of light propagation depends on the environment, there is such a phenomenon as refraction of light. In other words, a ray of light can be refracted depending on the environment in which it enters. This effect becomes noticeable right at the junction of two different environments, i.e. at the surface boundaries of objects. Since we assume that our objects are filled with homogeneous material, we can suppose that the refracting index will also be the same over the entire volume of the object. Then the refraction can be calculated from Snell's law:

$`\frac{sin\alpha_1}{sin\alpha_2} = \frac{n_2}{n_1}`$, where

$`\alpha_1`$ and $`\alpha_2`$ are the angle between the ray and the surface normal before and after refraction

$`n_1`$ and $`n_2`$ are the refracting index of light for the first and second environments

Note that refraction occurs not only when the ray enters the object environment, but also when it leaves it, i.e. every time the environment changes.

### Consideration of surface curvature of polygonal models

With polygonal models, i.e. models made up of flat faces, using the above considerations as it is can be problematic. The point is that some models that imply smooth surfaces approximated by polygons, such as a polygonal ball or torus, will look faceted if polygonal normals are used. If you approximate the position of the normals for each point, similar to Phong's shading method, from the normals to the polygons' own vertexes, models with solid edges, such as a cube, will not look realistic. Therefore, in the case of ray tracing, it is necessary to provide for the modes of edges, such as hard edges and smooth edges, and to use approximated normals and normals to the surfaces, respectively.
When both the first and the second type of edges are present within the same model, you can always use interpolation of normals for each point when processing the obj file, but in this case, set a different normal for each polygon. If a polygon is supposed to have solid edges, all its vertexes must have the same normal equal to the normal of the face. In the opposite case, the standard normals to vertexes equal to the sum of normals of adjacent polygons are used. Some obj files provide comprehensive information about the normals of each vertex of each polygon (and the same vertex for different polygons may have different normals).
