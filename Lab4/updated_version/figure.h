#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED

float VAR = 0.23;

class figure
{
    public:
        RECT r;

        virtual inline std::string get_name()=0;

        virtual inline int get_startX()=0;
        virtual inline int get_startY()=0;

        virtual inline int get_endX()=0;
        virtual inline int get_endY()=0;

        virtual inline int get_centerX()=0;
        virtual inline int get_centerY()=0;

        virtual inline int get_speed()=0;
        virtual inline int get_angle()=0;
        virtual inline int get_radius()=0;

        virtual inline int get_RGB_RED()=0;
        virtual inline int get_RGB_GREEN()=0;
        virtual inline int get_RGB_BLUE()=0;

        virtual void set_startX(int newVal)=0;
        virtual void set_startY(int newVal)=0;

        virtual void set_endX(int newVal)=0;
        virtual void set_endY(int newVal)=0;

        virtual void set_centerX(int newVal)=0;
        virtual void set_centerY(int newVal)=0;

        virtual void set_speed(int newVal)=0;
        virtual void set_angle(int newVal)=0;
        virtual void set_radius(int newVal)=0;

        virtual void set_RGB(int R, int G, int B)=0;
};

#endif // FIGURE_H_INCLUDED
