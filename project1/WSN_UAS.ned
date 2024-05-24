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

import ned.IdealChannel;


//
// TODO auto-generated module
//
simple Tower
{
    gates:
        input in[2];
        output out;
}

simple Tower1
{
    gates:
        input in[2];
        output out;
}

simple Tower2
{
    gates:
        input in[2];
        output out;
}

network UAS
{
    @display("bgb=864.006,676.598;bgi=background/bg_omnetpp,s");
    submodules:

        sensorLaut1: SensorLaut {
            @display("p=59.74,334.75;i=block/sink;is=n");
        }
        sensorGempa1: SensorGempa {
            @display("p=111.520004,594.32;i=block/broadcast;is=n");
        }
        tower: Tower {
            @display("p=234.26,111.618;i=device/antennatower");
        }
        tower1: Tower1 {
            @display("p=432.692,111.618;i=device/antennatower");
        }
        tower2: Tower2 {
            @display("p=668.33,99.215996;i=device/antennatower");
        }
        sensorLaut2: SensorLaut {
            @display("p=316.88,334.56;i=block/sink;is=n");
        }
        sensorGempa2: SensorGempa {
            @display("p=432.48,594.32;i=block/broadcast;is=n");
        }
        sensorLaut3: SensorLaut {
            @display("p=603.84,348.16;i=block/sink;is=n");
        }
        sensorGempa3: SensorGempa {
            @display("p=730.32,594.32;i=block/broadcast;is=n");
        }
        computer: Computer {
            @display("p=58.48,36.72;i=old/comp2");
        }
    connections:
        sensorLaut1.out --> IdealChannel --> tower.in[0];
        sensorGempa1.out --> IdealChannel --> tower.in[1];
        sensorLaut2.out --> IdealChannel --> tower1.in[0];
        sensorGempa2.out --> IdealChannel --> tower1.in[1];
        sensorLaut3.out --> IdealChannel --> tower2.in[0];
        sensorGempa3.out --> IdealChannel --> tower2.in[1];
        tower.out --> IdealChannel --> computer.in[0];
        tower1.out --> IdealChannel --> computer.in[1];
        tower2.out --> IdealChannel --> computer.in[2];
}
