// ==========================================================================
//
// License, schmlicense! This is for learning!
//
// ==========================================================================
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

class FiveDice : public olc::PixelGameEngine {

public:

    FiveDice() {
        sAppName = "Five Dice";
    }

    std::vector<uint8_t> vRolled;

public:
    void DrawDie(const olc::vi2d& vPos,
                 const uint8_t nFace,
                 const olc::vi2d& vSize = { 64, 64},
                 const olc::Pixel colFace = olc::DARK_RED,
                 const olc::Pixel colSpot = olc::WHITE) {
        //Draw background
        FillRect(vPos, vSize, colFace);

        int32_t nColL = int32_t(double(vSize.x) * 0.25);
        int32_t nColM = int32_t(double(vSize.x) * 0.5);
        int32_t nColR = int32_t(double(vSize.x) * 0.75);

        int32_t nRowT = int32_t(double(vSize.y) * 0.25);
        int32_t nRowM = int32_t(double(vSize.y) * 0.5);
        int32_t nRowB = int32_t(double(vSize.y) * 0.75);

        int32_t nRad = int32_t(double(nColL) * 0.4); // scale the spot size

        /*     switch(nFace)
             {        // Does order of drawing matter here?
                 case 1:
                     FillCircle(vPos + olc::vi2d(nColM, nRowM), nRad, colSpot);
                     break;
                 case 2:
                     FillCircle(vPos + olc::vi2d(nColL, nRowT), nRad, colSpot);
                     FillCircle(vPos + olc::vi2d(nColR, nRowB), nRad, colSpot);
                     break;
                 case 3:
                     FillCircle(vPos + olc::vi2d(nColL, nRowT), nRad, colSpot);
                     FillCircle(vPos + olc::vi2d(nColM, nRowM), nRad, colSpot);
                     FillCircle(vPos + olc::vi2d(nColR, nRowB), nRad, colSpot);
                     break;
                 case 4:
                     FillCircle(vPos + olc::vi2d(nColL, nRowT), nRad, colSpot);
                     FillCircle(vPos + olc::vi2d(nColR, nRowB), nRad, colSpot);
                     FillCircle(vPos + olc::vi2d(nColL, nRowB), nRad, colSpot);
                     FillCircle(vPos + olc::vi2d(nColR, nRowT), nRad, colSpot);
                     break;
                 case 5:
                     FillCircle(vPos + olc::vi2d(nColL, nRowT), nRad, colSpot);
                     FillCircle(vPos + olc::vi2d(nColL, nRowB), nRad, colSpot);
                     FillCircle(vPos + olc::vi2d(nColR, nRowB), nRad, colSpot);
                     FillCircle(vPos + olc::vi2d(nColM, nRowM), nRad, colSpot);
                     FillCircle(vPos + olc::vi2d(nColR, nRowT), nRad, colSpot);
                     break;
                 case 6:
                     FillCircle(vPos + olc::vi2d(nColL, nRowT), nRad, colSpot);
                     FillCircle(vPos + olc::vi2d(nColL, nRowB), nRad, colSpot);
                     FillCircle(vPos + olc::vi2d(nColR, nRowB), nRad, colSpot);
                     FillCircle(vPos + olc::vi2d(nColR, nRowT), nRad, colSpot);
                     FillCircle(vPos + olc::vi2d(nColL, nRowM), nRad, colSpot);
                     FillCircle(vPos + olc::vi2d(nColR, nRowM), nRad, colSpot);
                     break;
             }*/

        /*if ((std::set<uint8_t>{2, 3, 4, 5, 6}).count(nFace) > 0)
            FillCircle(vPos + olc::vi2d(nColL, nRowT), nRad, colSpot);
        if ((std::set<uint8_t>{6}).count(nFace) > 0)
            FillCircle(vPos + olc::vi2d(nColL, nRowM), nRad, colSpot);
        if ((std::set<uint8_t>{4, 5, 6}).count(nFace) > 0)
            FillCircle(vPos + olc::vi2d(nColL, nRowB), nRad, colSpot);

        *//*       if((std::set<uint8_t>{1, 3, 5}).count(nFace) > 0)
                   FillCircle(vPos + olc::vi2d(nColM,nRowM), nRad, colSpot);

       *//*
        if ((std::set<uint8_t>{4, 5, 6}).count(nFace) > 0)
            FillCircle(vPos + olc::vi2d(nColR, nRowT), nRad, colSpot);
        if ((std::set<uint8_t>{6}).count(nFace) > 0)
            FillCircle(vPos + olc::vi2d(nColR, nRowM), nRad, colSpot);
        if ((std::set<uint8_t>{2, 3, 4, 5, 6}).count(nFace) > 0)
            FillCircle(vPos + olc::vi2d(nColR, nRowB), nRad, colSpot);*/

        if (nFace & 1) /// if it's odd
        {
            FillCircle(vPos + olc::vi2d(nColM, nRowM), nRad, colSpot);
        }

        if (nFace > 1)
        {
            FillCircle(vPos + olc::vi2d(nColL, nRowT), nRad, colSpot);
            FillCircle(vPos + olc::vi2d(nColR, nRowB), nRad, colSpot);
        }

        if(nFace > 3)
        {
            FillCircle(vPos + olc::vi2d(nColL, nRowB), nRad, colSpot);
            FillCircle(vPos + olc::vi2d(nColR, nRowT), nRad, colSpot);
        }

        if(nFace == 6)
        {
            FillCircle(vPos + olc::vi2d(nColL, nRowM), nRad, colSpot);
            FillCircle(vPos + olc::vi2d(nColR, nRowM), nRad, colSpot);
        }
    }

    bool OnUserCreate() override {
        vRolled = { 1, 6, 3, 3, 5};
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {

        if (GetKey(olc::Key::SPACE).bReleased)
        {
            /*vRolled =
                {
                    uint8_t (rand() % 6 + 1),
                    uint8_t (rand() % 6 + 1),
                    uint8_t (rand() % 6 + 1),
                    uint8_t (rand() % 6 + 1),
                    uint8_t (rand() % 6 + 1),
                    uint8_t (rand() % 6 + 1)
                };

            std::transform(
                    vRolled.begin(),
                    vRolled.end(),
                    vRolled.begin(),
                    [](uint8_t) {return rand() % 6 + 1; }
                );*/

            std::generate(
                    vRolled.begin(),
                    vRolled.end(),
                    []() {return rand() % 6 + 1; }
            );

            std::sort(vRolled.begin(), vRolled.end());

        }


        int nScore_AllDice = std::accumulate(vRolled.begin(), vRolled.end(), 0);
        int nScore_CountOnes = std::count(vRolled.begin(), vRolled.end(), 1) * 1;
        int nScore_CountTwos = std::count(vRolled.begin(), vRolled.end(), 2) * 2;
        int nScore_CountThrees = std::count(vRolled.begin(), vRolled.end(), 3) * 3;
        int nScore_CountFours = std::count(vRolled.begin(), vRolled.end(), 4) * 4;
        int nScore_CountFives = std::count(vRolled.begin(), vRolled.end(), 1) * 1;
        int nScore_CountSixes = std::count(vRolled.begin(), vRolled.end(), 1) * 1;


        Clear(olc::DARK_GREEN);

        DrawDie({10, 10}, vRolled[0]);
        DrawDie({80, 10}, vRolled[1]);
        DrawDie({150, 10}, vRolled[2]);
        DrawDie({220, 10}, vRolled[3]);
        DrawDie({290, 10}, vRolled[4]);

        return true;
    }
};


int main() {
    FiveDice demo;

    if (demo.Construct(640 , 480, 4, 4))
        demo.Start();

    return 0;
}