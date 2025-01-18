#ifndef PAIR
#define PAIR

template <typename L, typename R>
class Pair{

    private:
        L left;
        R right;
    public:
        Pair(L left, R right): left(left), right(right){

        }
        Pair(const Pair& pair){
            this->left = pair.left;
            this->right = pair.right;
        }
        Pair& operator=(const Pair& pair){
            this->left = pair.left;
            this->right = pair.right;
        }

        Pair& operator==(const Pair& pair){
            return this->left == pair.left && this->right == pair.right;
        }

        R operator+(){
            return this->right;
        }
        L operator-(){
            return this->left;
        }
};

#endif