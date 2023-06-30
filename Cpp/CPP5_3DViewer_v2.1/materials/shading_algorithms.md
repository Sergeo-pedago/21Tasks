# Basic shading approaches

At a basic level, to shade some pixel of an image, it is enough to know the intensity of this pixel expressed through three components: R, G, and B channels. The pixel intensity is calculated as the intensity of that part of the object that is depicted on the given pixel. The intensity of the object depends on position of the light sources. Several approaches can be used to calculate the intensity of any part of an object:

## Flat shading

The intensity is calculated once for each polygon, and is its average value:

$` I=I_0 cos \phi `$, if $`0 \leq \phi \leq \pi / 2`$, else $`I = 0`$.

Here, the angle $\phi`$ is the angle between the surface normal and the direction vector to the light source, and $`I_0`$ is the base value of the light source intensity.

## Gouraud shading

The intensity is interpolated for any pixel that makes up the two-dimensional polygon representation. The object turns out more "smooth". This requires:

- Calculation of vertex normals of a polygon, by vector addition of normals to surfaces of adjacent vertex faces. Thus, to calculate vertex *A*, we have to add the vectors of normals to faces *1*, *2*, *3*, and *4*.

- Calculation of the vertices intensity by the formula $`I=I_0 cos \phi`$ if $`0 \leq \phi \leq \pi / 2`$, else $`I = 0`$.

- Calculation of the intensity of all polygon inner pixels, by two-dimensional linear intensity interpolation. Let $`O`$ be some arbitrary pixel inside the polygon, then draw a horizontal straight line through the point $`O`$ and denote the points of intersection with edges of the face as $`P`$ and $`Q`$. Then the intensity $`O`$ can be linearly interpolated on the segment $`PQ`$, as follows:

$`I_O = (1 - \frac{|PO|}{|PQ|})I_P + \frac{|PO|}{|PQ|}I_Q`$

The intensities for points $`P`$ and $`Q`$ are similarly interpolated on the corresponding edges with known values of intensities for vertices.

The method can be largely optimized, because the intensity within one horizontal line for each pixel can be calculated from the previous one by adding a fixed value, i.e. it has a linear increase/decrease. Similarly, the change of intensities for points on edges is linear. It is always better to implement linear interpolation incrementally.

## Phong shading

Fong's shading method develops the idea of Gouraud's shading, but in this case it is not the intensity value, but the normalized normal vector itself that is interpolated. Thus, the method involves the following steps:

- Calculate the normals of polygon vertices (vertexes), by vector addition of normals to the surfaces of adjacent vertex faces. Vectors are normalized.

- The normal vector (all three components) is linearly interpolated for each pixel in the same way as the intensity in the Gouraud shading method.

- Calculate the intensity for the new vector.

Phong takes a little longer to calculate, since interpolation of three vector component values, instead of just one intensity value, is required, but the result is more accurate.
