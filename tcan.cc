// 
#include <vector>
#include <tins/tins.h>
using namespace Tins;
using namespace std;

int main() {
  vector<Packet> vt;

  Sniffer sniffer("wlo1");
  while (vt.size() !=10) {
    // next_packet returns a PtrPacket, which can be implicitly cnverted to Packet
    vt.push_back(sniffer.next_packet ());
  }
  // Done, now let's check the packets
  for (const auto& packet : vt) {
    // Is there an IP PDU somewhere?
    if (packet.pdu()->find_pdu<IP>()) {
      // Just print timestamp's seconds and IP source address
      cout << "At: " << packet.timestamp().seconds()
      << "-" << packet.pdu()->rfind_pdu<IP>().src_addr() << endl;
    }
  }
}
