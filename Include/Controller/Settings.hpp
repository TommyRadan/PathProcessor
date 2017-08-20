/*
 *
 * Copyright 2017 Tomislav Radanovic
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#pragma once

#include <string>

namespace Controller
{
    /**
     * This global settings class is used for centralized settings managing.
     * Every application setting should be introduced here.
     */
    class Settings
    {
        Settings();

    public:
        static Settings* GetInstance();

        static void ReleaseInstance();

        const std::string& GetInputFileName() const;
        const std::string& GetOutputFileName() const;
        const float GetWorkingAreaX() const;
        const float GetWorkingAreaY() const;
        const float GetWorkingAreaZ() const;
        const int GetSubdivisionX() const;
        const int GetSubdivisionY() const;
        const int GetSubdivisionZ() const;

        void SetInputFileName(const std::string& fileName);
        void SetOutputFileName(const std::string& fileName);
        void SetWorkingAreaX(float x);
        void SetWorkingAreaY(float y);
        void SetWorkingAreaZ(float z);
        void SetSubdivisionX(int x);
        void SetSubdivisionY(int y);
        void SetSubdivisionZ(int z);


    private:
        std::string m_InputFileName;
        std::string m_OutputFileName;

        float m_WorkingAreaX;
        float m_WorkingAreaY;
        float m_WorkingAreaZ;

        int m_SubdivisionX;
        int m_SubdivisionY;
        int m_SubdivisionZ;
    };
}
