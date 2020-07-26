struct btree { char elem; btree* right; btree* left; };

void input(btree *&b, int m);
void straight(btree *&b, int &counter);
void back(btree *&b, int &counter);
void rekurs(btree *&b, int &counter);
void terminal(btree *&b, int &counter);