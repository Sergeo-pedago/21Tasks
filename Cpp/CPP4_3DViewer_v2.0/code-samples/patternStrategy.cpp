/*  Strategy is used when you have several algorithms for one
    purpose. Let us have several ways to render the scene: 
    wired (only verticies and edges are visible), filled
    (faces are visible too) and shaded (light and shadows are
    applied).   */

/*  This is our "strategy" base class, that is used to render
    image   */
class Renderer 
{
    public:
    //<...>
    virtual _2DImage render(_3DScene *scene)
    {
        //<...>
    }
};

/*  This is the viewport through which we can observe the scene.
    It is the context for the concrete strategy */
class Viewport
{
    private:
        Renderer *renderer;
        Canvas *canvas;
    public:
        Viewport(Renderer* r):renderer(r)
        {
            //<...>
        }

        // Here we can set Renderer a.k.a Strategy
        void setRenderer(Renderer *r)
        {
            delete this->renderer;
            this->renderer = r;
        }

        // Using strategy
        void drawCanvas(_3DScene *scene)
        {
            _2DImage image = this->renderer->render(scene);
            //<...>
        }

        //<...>
};

/*  Here we have some specific strategies to render our scene
    for every possible option. Every class overrides render
    method and implements it with specific algorythm. */

class WiredRenderer : public Renderer
{
    //<...>

    _2DImage render(_3DScene *scene) override {
        // Rendering scene in "wired" mode
    }

    //<...>
};

class FilledRenderer : public Renderer
{
    //<...>

    _2DImage render(_3DScene *scene) override {
        // Rendering scene in "filled" mode
    }

    //<...>
};

class ShadedRenderer : public Renderer
{
    //<...>

    _2DImage render(_3DScene *scene) override {
        // Rendering scene in "shaded" mode
    }

    //<...>
};

// Let our view has several viewports
class SomeView 
{
    private:
        Viewport *v1;
        Viewport *v2;
        Viewport *v3;
    public:
        SomeView()
        {
            v1 = new Viewport(new WiredRenderer());
            v2 = new Viewport(new FilledRenderer());
            v3 = new Viewport(new ShadedRenderer());
        }
        void draw(_3DScene *scene)
        {
            v1->drawCanvas(scene);
            v2->drawCanvas(scene);
            v3->drawCanvas(scene);
        }

        //...
}
