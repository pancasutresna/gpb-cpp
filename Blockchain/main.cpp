#include "Blockchain.h"

int main() {
	Blockchain bChain = Blockchain();

	cout << "Mining block 1..." << endl;
	bChain.AddBlock(Block(1, "Block 1 data"));

	cout << "Mining block 2..." << endl;
	bChain.AddBlock(Block(2, "Block 2 data"));

	cout << "Mining block 3..." << endl;
	bChain.AddBlock(Block(3, "Block 3 data"));

	return 0;
}