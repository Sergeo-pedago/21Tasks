#include <iostream>
#include <string>     
using namespace std;                

// Let us have very complicated class structure for rendering the scene

class _3DSceneLoader
{
  //<...>
};

class _2DTextureReader
{
  //<...>
};

class Projector
{
  //<...>
};

class Rasterizator
{
  //<...>
};

class ImageSaver
{
  //<...>
};

/* And instead letting it as it is right now, we can offer a high-level class
that is easy to use without understanding the guts of this library */

class Facade
{
    private:
        _3DSceneLoader *sceneLoader;
        _2DTextureReader *textureReader;
        Projector *projector;
        Rasterizator *rasterizator;
        ImageSaver *imageSaver;
    //<...>
    public:
        // Encapsulate whole rendering pipeline here
        void RenderTheScene(string inputFilename, string outputFilename) 
        {
            _3DScene scene = sceneLoader->loadMainSceneFile(inputFilename);
            TexturesMap texturesMap = textureReader->openTextures(scene.getTexturesList());
            Camera viewPoint = scene.getCamera();
            //<...>
            imageSaver->save(outputFilename);
        }
}
