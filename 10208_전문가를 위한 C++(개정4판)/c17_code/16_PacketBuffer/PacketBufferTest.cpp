#include "PacketBuffer.h"
#include <iostream>

using namespace std;

class IPPacket final
{
public:
	IPPacket(int id) : mID(id) {}
	int getID() const { return mID; }

private:
	int mID;
};

int main()
{
	PacketBuffer<IPPacket> ipPackets(3);

	// 패킷 네 개를 추가한다.
	for (int i = 1; i <= 4; ++i) {
		if (!ipPackets.bufferPacket(IPPacket(i))) {
			cout << "Packet " << i << " dropped (queue is full)." << endl;
		}
	}

	while (true) {
		try {
			IPPacket packet = ipPackets.getNextPacket();
			cout << "Processing packet " << packet.getID() << endl;
		} catch (const out_of_range&) {
			cout << "Queue is empty." << endl;
			break;
		}
	}
	return 0;
}
