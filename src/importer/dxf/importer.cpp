#include <importer.h>
#include <interface.h>

#include <common/exception.h>

#include <libdxfrw/libdxfrw.h>

namespace Importer::Dxf
{

Importer::Importer(const std::string& filename)
{
	Interface interface(*this);

	dxfRW rw(filename.c_str());
	if (!rw.read(&interface, false)) {
		throw Common::FileException();
	}
}

Geometry::Polyline::List &&Importer::polylines()
{
	return std::move(m_polylines);
}

void operator<<(Importer &importer, const Geometry::Polyline::List &polylines)
{
	importer.m_polylines.insert(importer.m_polylines.begin(), polylines.begin(), polylines.end());
}

}
