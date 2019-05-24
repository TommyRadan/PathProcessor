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

#include <Controller/PathProcessing.hpp>
#include <Controller/CollisionDetection.hpp>
#include <Controller/Settings.hpp>

namespace Controller
{
    /**
     * This function processes the Point and updates its state.
     *
     * @param point - The Point to process.
     * @param mesh - The Mesh to process the Point with.
     *
     * @return True - Mesh is defined for the area.
     * @return False - Mesh is not defined for the area.
     */
    static bool ProcessThePoint(Geometry::Point& point, const Geometry::Mesh& mesh)
    {
        Controller::Settings* settings = Controller::Settings::GetInstance();

        float waz = settings->GetWorkingAreaZ();
        int sdz = settings->GetSubdivisionZ();
        float radius = settings->GetSpindleRadius();
        float angle = settings->GetSpindleAngle();

        float currX = point.GetX();
        float currY = point.GetY();

        if (!IsInCollision(Geometry::Cone { Geometry::Point { currX, currY, -waz/2 }, angle, radius}, mesh))
        {
            return false;
        }

        for (int i = 0; i < sdz; ++i)
        {
            const float currZ = waz / (sdz - 1) * i - waz / 2;
            const Geometry::Cone spindle {
                Geometry::Point { currX, currY, currZ },
                angle, radius
            };

            if (!IsInCollision(spindle, mesh))
            {
                point.SetZ(currZ);
                break;
            }
        }

        return true;
    }

    /**
     * This function processes the Path and updates its state.
     *
     * @param path - The Path to process.
     * @param mesh - The Mesh to process the Path with.
     */
    void ProcessThePath(Geometry::Path& path, const Geometry::Mesh& mesh)
    {
        for (auto& point : path.GetData())
        {
            if (!ProcessThePoint(point, mesh))
            {
                /*path.GetData().erase(std::find(path.GetData().begin(),
                                               path.GetData().end(),
                                               point));*/
            }
        }
    }
}