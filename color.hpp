#ifndef COLOR
#define COLOR

class Color{
    private:
        int R;
        int G;
        int B;
        int A;
    
    public:
        Color(){
        }
        Color(int _R, int _G, int _B, int _A){
            this->R = _R;
            this->G = _G;
            this->B = _B;
            this->A = _A;
        }
        int getR(){
            return this->R;
        }
        int getG(){
            return this->G;
        }
        int getB(){
            return this->B;
        }
        int getA(){
            return this->A;
        }
        void setR(int _R){
            this->R = _R;
        }
        void setG(int _G){
            this->G = _G;
        }
        void setB(int _B){
            this->B = _B;
        }
        void setA(int _A){
            this->A = _A;
        }
        void print(){
            std::cout << "R: " << R << " G: " << G << " B: " << B << std::endl;
        }
};

#endif