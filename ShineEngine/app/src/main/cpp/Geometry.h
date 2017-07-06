//
// Created by Administrator on 2017/7/5.
//

#ifndef SHINEENGINE_GEOMETRY_H
#define SHINEENGINE_GEOMETRY_H


class Size {
public:
    /**Width of the Size.*/
    float width;
    /**Height of the Size.*/
    float height;
    /**
    @{
    Constructor.
    @param width Width of the size.
    @param height Height of the size.
    @param other Copy constructor.
    @param point Conversion from a point.
     */
    Size();
    Size(float width, float height);
    Size(const Size& other);

    /**
    Check if two size is the same.
     * @js NA
     */
    bool equals(const Size& target) const;

    /**Size(0,0).*/
    static const Size ZERO;
};


#endif //SHINEENGINE_GEOMETRY_H
