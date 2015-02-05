#ifndef DIGITIZE_STATE_COLOR_PICKER_H
#define DIGITIZE_STATE_COLOR_PICKER_H

#include "DigitizeStateAbstractBase.h"

class DocumentModelFilter;

/// Digitizing state for selecting a color for DigitizeStateSegment. The basic strategy is that this
/// class acts like a special case of DlgSettingsFilter. Specifically, the pixel just selected by a
/// mouse click is used to change the segment filter for the currently specified curve
class DigitizeStateColorPicker : public DigitizeStateAbstractBase
{
public:
  /// Single constructor.
  DigitizeStateColorPicker(DigitizeStateContext &context);
  virtual ~DigitizeStateColorPicker();

  virtual QString activeCurve () const;
  virtual void begin();
  virtual QCursor cursor () const;
  virtual void end();
  virtual void handleKeyPress (Qt::Key key);
  virtual void handleMousePress (QPointF posScreen);
  virtual void handleMouseRelease (QPointF posScreen);

private:
  DigitizeStateColorPicker();

  DocumentModelFilter transformFilter (const QRgb &rgb,
                                       const DocumentModelFilter &modelFilterBefore,
                                       const QString &curveName);
};

#endif // DIGITIZE_STATE_COLOR_PICKER_H
