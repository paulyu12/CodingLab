class TreeNode1 {
public:
    TreeNode1(const string &s, int c) :
        value(s), count(c), left(nullptr), right(nullptr), use(new int(1)) {}

    TreeNode1(TreeNode1 &rhs) :
        value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right), use(rhs.use) { ++ *use; }

    TreeNode1& operator=(TreeNode1 &rhs) {
        ++ *rhs.use;

        if (-- *use == 0) {
            delete use;
            if (left) delete left;
            if (right) delete right;
        }

        value = rhs.value;
        count = rhs.count;
        left = rhs.left;
        right = rhs.right;
        use = rhs.use;

        return *this;
    }

    ~TreeNode1() {
        if (-- *use == 0) {
            delete use;
            if (left) delete left;
            if (right) delete right;
        }
    }

private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;

    int *use;
};
