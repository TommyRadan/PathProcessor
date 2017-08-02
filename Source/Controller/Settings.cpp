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

static Settings* settingsInstance = nullptr;

/**
 * Singleton GetInstance method for Settings class.
 *
 * @return Returns pointer to system-wide unique Settings pointer.
 */
Settings* Settings::GetInstance(void)
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
void Settings::ReleaseInstance(void)
{
    if (settingsInstance != nullptr)
    {
        delete settingsInstance;
        settingsInstance = nullptr;
    }
}

/**
 * Default constructor for the Settings class.
 */
Settings::Settings(void)
{
    /*
     * TODO: Add setting of default application settings.
     */
}
