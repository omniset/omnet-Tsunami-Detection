//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "WSN_UAS.h"
#include <string.h>
#include <omnetpp.h>

Define_Module(Tower);
Define_Module(Tower1);
Define_Module(Tower2);

using namespace omnetpp;

void Tower::initialize()
{

}

void Tower::handleMessage(cMessage *msg)
{
    // Forward the received message to the output gate
    send(msg, "out");
}

void Tower1::initialize()
{

}

void Tower1::handleMessage(cMessage *msg)
{
    // Forward the received message to the output gate
    send(msg, "out");
}

void Tower2::initialize()
{

}

void Tower2::handleMessage(cMessage *msg)
{
    // Forward the received message to the output gate
    send(msg, "out");
}
