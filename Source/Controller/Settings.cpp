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
     * Default constructor for the Settings class.
     */
    Settings::Settings()
    {
        m_InputFileName = "input.stl";
        m_OutputFileName = "output.gcode";
    }
}
