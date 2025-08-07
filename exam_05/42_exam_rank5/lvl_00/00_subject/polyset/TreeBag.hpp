#ifndef D09AC97A_15D4_42A1_9BB2_A47C189A0A46
#define D09AC97A_15D4_42A1_9BB2_A47C189A0A46
#ifndef TREE_BAG_HPP
#define TREE_BAG_HPP

#include "Bag.hpp"

class TreeBag: virtual public Bag {
	protected:
		struct Node {
			int value;
			Node* left;
			Node* right;
		};
		Node* root;

	public:
		TreeBag();
		TreeBag(const TreeBag& other);
		~TreeBag();
		TreeBag& operator=(const TreeBag& other);
		
		Node* extractTree();
		void setTree(Node*);
		virtual void insert(int);
		virtual void insert(int* array, int size);
		virtual void print() const;
		virtual void clear();

	private:
		static void destroyTree(Node*);
		static void printNode(Node*);
		static Node *copyNode(Node*);
};

#endif


#endif /* D09AC97A_15D4_42A1_9BB2_A47C189A0A46 */
