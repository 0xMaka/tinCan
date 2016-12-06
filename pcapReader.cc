// pcap reader
#include <tins/tins.h>
#include <iostream>
#include <stddef.h>
using namespace std;
using namespace Tins;

size_t counter(0);

bool count_packets(const PDU &) {
  counter++;
  // Always keep looping. When the end of this file is found,
  // our callback will simply not be called again.
  return true;
}

int main() {
  FileSniffer sniffer("/tmp/some_pcap_file.pcap");
  sniffer.sniff_loop(count_packets);
  cout << "There are " << counter << " packets in the pcap file." << endl;
}
