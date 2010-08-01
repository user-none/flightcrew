/************************************************************************
**
**  Copyright (C) 2010  Strahinja Markovic
**
**  This file is part of FlightCrew.
**
**  FlightCrew is free software: you can redistribute it and/or modify
**  it under the terms of the GNU Lesser General Public License as published
**  by the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  FlightCrew is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU Lesser General Public License for more details.
**
**  You should have received a copy of the GNU Lesser General Public License
**  along with FlightCrew.  If not, see <http://www.gnu.org/licenses/>.
**
*************************************************************************/

#include <stdafx.h>
#include "PackageIsRoot.h"
#include <ToXercesStringConverter.h>

std::vector<Result> PackageIsRoot::ValidateXml( const xc::DOMDocument &document )
{
    xc::DOMElement *root_element = document.getDocumentElement();

    std::vector<Result> results;

    if ( !xc::XMLString::equals( root_element->getLocalName(), toX( "package" ) )  )
    {
        results.push_back( ResultWithNodeLocation( 
            ERROR_OPF_PACKAGE_NOT_ROOT, *root_element ) );
    }

    return results;
}
