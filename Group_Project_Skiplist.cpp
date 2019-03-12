 
void insertElement(int key) {
	Node* current = header;
	Node* update[MAXLVL + 1];
	for (int i = 0 ; i < MAXLVL + 1 ; i ++) {
		update[i] = NULL;
	}
	for (int i = level; i >= 0; i--) {
		while (current->forward[i] != NULL && current->forward[i]->key < key) {
			current = current->forward[i];
			update[i] = current;
		}
	}
	current = current->forward[0];
	if (current == NULL || current->key != key) {
		int rlevel = randomLevel();
		if (rlevel > level) {
			for (int i = level + 1; i < rlevel + 1; i++) {
				update[i] = header;
				level = rlevel;
			}
		}
	Node* n = createNode(key, rlevel);
	for (int i = 0; i <= rlevel; i++) {
		n->forward[i] = update[i]->forward[i];
		update[i]->forward[i] = n;
	}
	cout << "Successfully Inserted key " << key << "\n";
	}
}
