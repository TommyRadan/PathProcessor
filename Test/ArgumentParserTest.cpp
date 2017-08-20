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

#include <Controller/ArgumentParser.hpp>
#include <Controller/Settings.hpp>

/**
 * This test case tests empty input to ArgumentParser.
 */
TEST(ArgumentParser, EmptyInput)
{
    Controller::Settings* settings = Controller::Settings::GetInstance();

    std::string defaultInput = settings->GetInputFileName();
    std::string defaultOutput = settings->GetOutputFileName();

    char* args[] = {
            (char*)"AppName",
            nullptr
    };

    EXPECT_TRUE(Controller::ParseArguments(1, args));

    EXPECT_STREQ(defaultInput.c_str(), settings->GetInputFileName().c_str());
    EXPECT_STREQ(defaultOutput.c_str(), settings->GetOutputFileName().c_str());

    settings->ReleaseInstance();
}

/**
 * This test case tests inputting --input and --output to the parser.
 */
TEST(ArgumentParser, InputAndOutput)
{
    Controller::Settings* settings = Controller::Settings::GetInstance();

    char* args[] = {
            (char*)"AppName",
            (char*)"--input",
            (char*)"testingInput.txt",
            (char*)"--output",
            (char*)"testingOutput.txt",
            nullptr
    };

    EXPECT_TRUE(Controller::ParseArguments(5, args));

    EXPECT_STREQ("testingInput.txt", settings->GetInputFileName().c_str());
    EXPECT_STREQ("testingOutput.txt", settings->GetOutputFileName().c_str());

    settings->ReleaseInstance();
}

/**
 * This test case test parsing failure.
 */
TEST(ArgumentParser, NegativeTest)
{
    Controller::Settings* settings = Controller::Settings::GetInstance();

    char* args[] = {
            (char*)"AppName",
            (char*)"--input",
            (char*)"testingInput.txt",
            (char*)"-non-existing-argument",
            (char*)"testing",
            nullptr
    };

    EXPECT_FALSE(Controller::ParseArguments(5, args));

    settings->ReleaseInstance();
}
