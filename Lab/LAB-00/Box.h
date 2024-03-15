#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

class Box
{
    private:
        int width, height, depth;

    public:
        Box();
        Box(int, int, int);
        //Can also write as Box(int width, int height, int depth);

        int getWidth();
        void setWidth(int width);

        int getHeight();
        void setHeight(int height);

        int getDepth();
        void setDepth(int depth);

        int volume();
};

#endif // BOX_H_INCLUDED
