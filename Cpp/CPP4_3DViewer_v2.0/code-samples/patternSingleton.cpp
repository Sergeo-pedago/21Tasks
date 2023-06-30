/* Let us have some object we want to be sure to be only one,
   meaning if we want to access it anytime we access the same
   instance, not the new instance by calling constructor.
   Examples: data, database connection, file instance... */

class SomeData 
{
    private:
        static SomeData *instance;

    protected:
        SomeData() 
        {
            /* Here we are creating our instance, the constructor 
               is called only once. It is protected to not allow
               publicly creating new instances. */
        }

        /* Singleton does not have public copy and move constructors */
        SomeData(const SomeData &other);
        SomeData(SomeData &&other);
        void operator=(const SomeData &other);

        ~SomeData()
        {
            delete instance;
        }

    public:
        /* Accessing singleton */
        static SomeData* getInstance()
        {
            if (!instance) 
            {
                /*  For the first getInstance() call or
                    just in case if we lose our instance */
                instance = new SomeData();
            }

            return instance;
        }
};

/* Now you can create somewhere an instance, calling getInstance() the first time.
   This will lead to static instance being determined and then static 
   getInstnace() will return always the same object. */
