/*
 *
 * Copyright 2017-2019 Tomislav Radanovic
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

#include <Controller/Settings.hpp>

static Controller::Settings* settingsInstance = nullptr;

namespace Controller
{
    /**
     * Singleton GetInstance method for Settings class.
     *
     * @return Returns pointer to system-wide unique Settings pointer.
     */
    Settings *Settings::GetInstance()
    {
        if (settingsInstance == nullptr)
        {
            settingsInstance = new Settings();
        }
        return settingsInstance;
    }

    /**
     * Singleton ReleaseInstance method for releasing the Settings class.
     */
    void Settings::ReleaseInstance()
    {
        if (settingsInstance != nullptr)
        {
            delete settingsInstance;
            settingsInstance = nullptr;
        }
    }

    /**
     * Getter for Input File Name.
     *
     * @return Input File Name.
     */
    const std::string& Settings::GetInputFileName() const
    {
        return m_InputFileName;
    }

    /**
     * Setter for Input File Name.
     *
     * @param fileName - Input File Name.
     */
    void Settings::SetInputFileName(const std::string& fileName)
    {
        m_InputFileName = fileName;
    }

    /**
     * Getter for Output File Name.
     *
     * @return Output File Name.
     */
    const std::string& Settings::GetOutputFileName() const
    {
        return m_OutputFileName;
    }

    /**
     * Setter for Output File Name.
     *
     * @param fileName - Output File Name.
     */
    void Settings::SetOutputFileName(const std::string& fileName)
    {
        m_OutputFileName = fileName;
    }

    /**
     * Getter for working area X.
     *
     * @return Working area X.
     */
    const float Settings::GetWorkingAreaX() const
    {
        return m_WorkingAreaX;
    }

    /**
     * Setter for working area X.
     *
     * @param x - X coordinate of the working area.
     */
    void Settings::SetWorkingAreaX(float x)
    {
        m_WorkingAreaX = x;
    }

    /**
     * Getter for working area Y.
     *
     * @return Working area Y.
     */
    const float Settings::GetWorkingAreaY() const
    {
        return m_WorkingAreaY;
    }

    /**
     * Setter for working area Y.
     *
     * @param y - Y coordinate of the working area.
     */
    void Settings::SetWorkingAreaY(float y)
    {
        m_WorkingAreaY = y;
    }

    /**
     * Getter for working area Z.
     *
     * @return Working area Z.
     */
    const float Settings::GetWorkingAreaZ() const
    {
        return m_WorkingAreaZ;
    }

    /**
     * Setter for working area Z.
     *
     * @param z - Z coordinate of the working area.
     */
    void Settings::SetWorkingAreaZ(float z)
    {
        m_WorkingAreaZ = z;
    }

    /**
     * Getter for subdivision X.
     *
     * @return Subdivision X.
     */
    const int Settings::GetSubdivisionX() const
    {
        return m_SubdivisionX;
    }

    /**
     * Setter for subdivision X.
     *
     * @param x - Subdivision X.
     */
    void Settings::SetSubdivisionX(int x)
    {
        m_SubdivisionX = x;
    }

    /**
     * Getter for subdivision Y.
     *
     * @return Subdivision Y.
     */
    const int Settings::GetSubdivisionY() const
    {
        return m_SubdivisionY;
    }

    /**
     * Setter for subdivision Y.
     *
     * @param x - Subdivision Y.
     */
    void Settings::SetSubdivisionY(int y)
    {
        m_SubdivisionY = y;
    }

    /**
     * Getter for subdivision Z.
     *
     * @return Subdivision Z.
     */
    const int Settings::GetSubdivisionZ() const
    {
        return m_SubdivisionZ;
    }

    /**
     * Setter for subdivision Z.
     *
     * @param x - Subdivision Z.
     */
    void Settings::SetSubdivisionZ(int z)
    {
        m_SubdivisionZ = z;
    }

    /**
     * Getter for spindle radius.
     *
     * @return Spindle radius.
     */
    const float Settings::GetSpindleRadius() const
    {
        return m_SpindleRadius;
    }

    /**
     * Setter for spindle radius.
     *
     * @param radius - Spindle radius.
     */
    void Settings::SetSpindleRadius(float radius)
    {
        m_SpindleRadius = radius;
    }

    /**
     * Getter for spindle angle.
     *
     * @return Spindle angle.
     */
    const float Settings::GetSpindleAngle() const
    {
        return m_SpindleAngle;
    }

    /**
     * Setter for spindle angle.
     *
     * @param angle - Spindle angle.
     */
    void Settings::SetSpindleAngle(float angle)
    {
        m_SpindleAngle = angle;
    }

    /**
     * Default constructor for the Settings class.
     */
    Settings::Settings()
    {
        m_InputFileName = "input.stl";
        m_OutputFileName = "output.gcode";

        m_WorkingAreaX = 2.5f;
        m_WorkingAreaY = 0.5f;
        m_WorkingAreaZ = 1.0f;

        m_SubdivisionX = 25;
        m_SubdivisionY = 5;
        m_SubdivisionZ = 10;

        m_SpindleRadius = 0.01f;
        m_SpindleAngle = 30.0f;
    }
}
