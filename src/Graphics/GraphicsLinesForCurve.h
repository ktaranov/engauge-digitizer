#ifndef GRAPHICS_LINES_FOR_CURVE_H
#define GRAPHICS_LINES_FOR_CURVE_H

#include <QMap>

class GraphicsLine;
class GraphicsPoint;
class GraphicsScene;
class LineStyle;
class QGraphicsItem;

typedef QMap<int, GraphicsPoint*> GraphicsPointContainer;

/// This class stores the GraphicsLine objects for one Curve. The container is a QMap since that container
/// maintains order by key
class GraphicsLinesForCurve
{
public:
  /// Single constructor
  GraphicsLinesForCurve();

  /// Clear out existing point just prior to storing new set of points
  void resetPoints ();

  /// Add new point. The item/point pointers both point to the same object
  void savePoint (int ordinal,
                  GraphicsPoint *point);

  /// Remove stale lines and insert missing lines
  void updateLines (GraphicsScene &scene,
                    const LineStyle &lineStyle);

private:

  GraphicsPointContainer m_graphicsPoints;
};

#endif // GRAPHICS_LINES_FOR_CURVE_H
