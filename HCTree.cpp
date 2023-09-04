#include "HCTree.hpp"
#include <algorithm>

void build(const vector<int>& freqs){
	priority_queue<HCNode*, vector<HCNode*>, HCNodePtrComp> pq;
    for (int i = 0; i < freqs.size(); i++) {
		HCNode* newNode = new HCNode;
		HCNode->count = freqs[i];
		newNode->c0 = nullptr;
		newNode->c1 = nullptr;
		pq.push(newNode);
	}

	int count = 0;
	int numberLeaves = pq.size();
	while (pq.size() > 1) {
		HCNode* node0 = pq.top();
		if (count <= numberLeaves) {
			this.leaves.push_back(node0);
			count++;
		} 
		pq.pop();
		HCNoode* node1 = pq.top();
		if (count <= numberLeaves) {
			this.leaves.push_back(node1);
			count++;
		}
		pq.pop();

		HCNode* parentNode = new HCNode;
		parentNode->c0 = node0;
		parentNode->c1 = node1;
		parentNode->count = node0->count + node1->count;

		pq.push(parentNode);
	}

	this.root = pq.top();
}

HCTree::~HCTree() {	
	HCNode* nodeParser = this.root;
	while (nodeParser != nullptr) {
		HCNode* nodeHolder = nodeParser;
		delete nodeHolder;
		nodeParser = noderParser->c0;
	}		
	delete nodeParser;																																	
}

void encode(unsigned char symbol, FancyOutputStream & out) const {
	if (this.root != nullptr) {
		HCNode* curr = this.root;

		auto boolean = std::find(this.leaves.begin(), this.leaves.end(), curr);
		while (boolean == this.leaves.end()) {
			if (symbol == curr->c0->symbol) {
				out.write_bit(0);
				curr = curr->c0;
			} else {
				out.write_bit(1);
				curr = curr->c1;
			}

			auto boolean = std::find(this.leaves.begin(), this.leaves.end(), curr);
		}
	}
}

unsigned char decode(FancyInputStream & in) const {
	if (this.root != nullptr) {
		HCNode* curr = this.root;

		auto boolean = std::find(this.leaves.begin(), this.leaves.end(), curr);
		while (boolean == this.leaves.end()) {
			int bitValue = in.read_bit();
			if (bitValue == 0) {
				curr = curr->c0;
			} else {
				curr = curr->c1;
			}

			auto boolean = std::find(this.leaves.begin(), this.leaves.end(), curr);
		}
		return curr->symbol;
	}
}
