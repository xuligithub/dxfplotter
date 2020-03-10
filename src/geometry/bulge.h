#pragma once

#include <common/aggregable.h>

#include <geometry/arc.h>
#include <geometry/utils.h>

#include <QVector2D>

namespace Geometry
{

class Bulge : public Common::Aggregable<Bulge>
{
private:
	QVector2D m_start;
	QVector2D m_end;

	float m_tangent;

public:
	/** Define a bulge
	 * @param start Starting point of the bulge
	 * @param end Ending point of the bulge
	 * @param tangent Tangent of a thourth of the arc angle.
	 * Negative tangent means the arc goes clockwise from start to end,
	 * otherwise anti clockwise from start to end.
	 */
	explicit Bulge(const QVector2D &start, const QVector2D &end, float tangent);
	Bulge() = default;

	const QVector2D &start() const;
	const QVector2D &end() const;

	void invert();

	bool isLine() const;
	Orientation orientation() const;

	Arc toArc() const;
};

}