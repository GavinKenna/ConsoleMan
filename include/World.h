#ifndef WORLD_H
#define WORLD_H


class World
{
    public:
        World();
        virtual ~World();
        unsigned int GetWidth() { return m_Width; }
        void SetWidth(unsigned int val) { m_Width = val; }
        unsigned int GetHeight() { return m_Height; }
        void SetHeight(unsigned int val) { m_Height = val; }
        //char[][] GetMap() { return m_Map; }
       // void SetMap(char[][] val) { m_Map = val; }
    protected:
    private:
        unsigned int m_Width;
        unsigned int m_Height;
        //char[][] m_Map;
};

#endif // WORLD_H
