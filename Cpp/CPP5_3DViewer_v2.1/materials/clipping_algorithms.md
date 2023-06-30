# Basic approaches to removing hidden surfaces

## Z-buffer

The Z-buffer is a simple and intuitive algorithm for removing hidden surfaces. It is based on two special data structures - a frame buffer and a Z-buffer. Z-buffer is a matrix of screen pixels, each element of which contains the closest to the observer coordinate (in the observer's coordinate system) of the depth of some scene surface (the depth axis in the observer's coordinate system is conventionally considered as the Z axis). The frame buffer is a matrix of pixels with their intensities.
At first, the entire buffer is filled with the maximum depth value, then for each polygon of the scene, find those pixels for which the Z coordinate is smaller than the buffered value of the corresponding pixels; this value is put into the Z-buffer, and the corresponding intensity value is put into the frame buffer.

Here is a formal description of the Z-buffer algorithm:

- Fill the frame buffer with the background intensity or color value.

- Fill the Z-buffer with the maximum `z` value.

- Convert each polygon to a rasterized form in any order (rasterization).

- For each pixel in the polygon, calculate its depth `z.`

- Compare the depth `z` with the value in the `z0` buffer which is stored in the Z-buffer at the same position.

If `z > z0`, put the attribute of this polygon (intensity, color, etc.) into the frame buffer and replace the value in the buffer by `z`. Otherwise, do not perform any action.

## Ray casting

Ray casting algorithm is an algorithm for removing hidden surfaces, based on ray tracing throughout the observer's field of view. The polygons are projected onto the observer's screen and rasterized. A ray is cast for each pixel of the screen, detecting the first intersection with any object. This object is visible to that pixel. The intensity value for this pixel can be calculated when the object is rasterized as in the Z-buffer algorithm or can be obtained by tracing the ray further, taking into account its subsequent reflections and refractions to the light source (then Ray casting becomes Ray tracing). Ray tracing is a slightly more complicated approach, but gives a more realistic result.

Here is a formal description of the Ray casting algorithm:

- Convert each polygon to a rasterized form in any order (rasterization).

- Cast one ray per pixel in the screen.

- For each ray, find the intersection with the polygon that is closest to the observer.

- Calculate the intensity and fill the corresponding pixel of the image.
