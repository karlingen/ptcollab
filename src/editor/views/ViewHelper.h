#ifndef VIEWHELPER_H
#define VIEWHELPER_H

#include <QColor>
#include <QPainter>
#include <QPainterPath>

#include "MooClock.h"

extern void drawCursor(const QPoint &position, QPainter &painter,
                       const QColor &color, const QString &username,
                       qint64 uid);
extern void drawCurrentPlayerPosition(QPainter &painter, MooClock *moo_clock,
                                      int height, qreal clockPerPx,
                                      bool drawHead);
extern void drawRepeatAndEndBars(QPainter &painter, const MooClock *moo_clock,
                                 qreal clockPerPx, int height);
extern void handleWheelEventWithModifier(QWheelEvent *event,
                                         PxtoneClient *client, bool scaleY);

extern QColor halfWhite, slightTint;

template <typename T>
T clamp(T x, T lo, T hi) {
  if (x < lo) return lo;
  if (x > hi) return hi;
  return x;
}

extern int lerp(double r, int a, int b);

constexpr int EVENTMAX_VELOCITY = 128;
struct Brush {
  int hue;
  int muted_saturation;
  int base_saturation;
  int muted_brightness;
  int base_brightness;
  int on_brightness;

  Brush(int hue, int muted_saturation = 48, int base_saturation = 255,
        int muted_brightness = 96, int base_brightness = 204,
        int on_brightness = 255)
      : hue(hue),
        muted_saturation(muted_saturation),
        base_saturation(base_saturation),
        muted_brightness(muted_brightness),
        base_brightness(base_brightness),
        on_brightness(on_brightness) {}
  Brush(double hue) : Brush(int(hue * 360)){};

  QColor toQColor(int velocity, bool on, int alpha) const {
    int brightness =
        lerp(double(velocity) / EVENTMAX_VELOCITY, muted_brightness,
             on ? on_brightness : base_brightness);
    int saturation = lerp(double(velocity) / EVENTMAX_VELOCITY,
                          muted_saturation, base_saturation);
    return QColor::fromHsl(hue, saturation, brightness, alpha);
  }
};

extern const Brush brushes[];
extern const int NUM_BRUSHES;
extern int nonnegative_modulo(int x, int m);

#endif  // VIEWHELPER_H