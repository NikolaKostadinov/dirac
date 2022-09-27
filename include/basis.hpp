class Basis
{
    public:

        Basis();
        virtual ~Basis();

        virtual unsigned int size();
        virtual unsigned int xSize();
        virtual unsigned int ySize();
        virtual unsigned int zSize();
        
        virtual float xStart();
        virtual float yStart();
        virtual float zStart();
        virtual float xEnd();
        virtual float yEnd();
        virtual float zEnd();

        virtual float dx();
        virtual float dy();
        virtual float dz();
        
        virtual float xLength();
        virtual float yLength();
        virtual float zLength();
};