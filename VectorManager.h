//
// Created by f on 5/2/2024.
//

#ifndef VECTORMANAGER_H
#define VECTORMANAGER_H
#include <vector>
#include <iostream>
#include <memory>


namespace VecM
{
    class VectorManager
    {
    public:
        VectorManager();

        //func


        //vars
        //std::pmr::vector<float> simpleVector;
        std::unique_ptr<std::pmr::vector<float>> simpleVector;

        ~VectorManager() = default;
    };
}

#endif //VECTORMANAGER_H
