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

#include <gtest/gtest.h>

#include <Controller/Settings.hpp>

/**
 * This test case tests Settings class construction.
 */
TEST(Settings, Construction)
{
    Controller::Settings* settings = Controller::Settings::GetInstance();

    // Make sure you don't get nullptr
    ASSERT_NE(settings, nullptr);

    // Check the stability of singleton creation
    ASSERT_EQ(settings, Controller::Settings::GetInstance());
    ASSERT_EQ(settings, Controller::Settings::GetInstance());
    ASSERT_EQ(settings, Controller::Settings::GetInstance());
    ASSERT_EQ(settings, Controller::Settings::GetInstance());

    Controller::Settings::ReleaseInstance();
}

TEST(Settings, GettersAndSetters)
{
    Controller::Settings* settings = Controller::Settings::GetInstance();

    // Make sure you don't get nullptr
    ASSERT_NE(settings, nullptr);

    settings->SetInputFileName("test_input.txt");
    ASSERT_STREQ(settings->GetInputFileName().c_str(), "test_input.txt");

    settings->SetOutputFileName("test_output.txt");
    ASSERT_STREQ(settings->GetOutputFileName().c_str(), "test_output.txt");

    Controller::Settings::ReleaseInstance();
}
