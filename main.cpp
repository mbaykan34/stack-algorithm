//STACK PRACTICE
#include <iostream>
using namespace std;

//==================stack için önceden tanımlanan kapasite==============================
const int M=3;
//==========================STACK İÇİN SINIF TANIMI=====================================
template<class stType>
class stack{
    stType stck[M];            //stack deklerasyonu
    int tepe;
public:
    stack():tepe(-1){}         //default constructor; tepe'ye ilk değer -1 atandı.
    void push(stType);
    stType pop();
    bool isEmpty();
    int getTepe(){ return tepe;}   //bunu programı kontrol amacıyla ekledim.
};

//==============================PUSH() ÜYE FN===============================================

template<class stType>
void stack<stType>::push(stType deg){
    if(tepe>=2) {
        cerr<<"Stack dolu, eklenemedi,\n";
    }
    else{
    stck[++tepe]=deg;
    }
}
//===========================ISEMPTY ÜYE FN================================================
template<class stType>
bool stack<stType>::isEmpty(){
    if (tepe<0)         return true;
    else                return false;
}
//============================POP ÜYE FN================================================
template<class stType>
stType stack<stType>::pop(){
    if(isEmpty()){
        cerr<<"stack tamamen bos\n";
        return 0;
    }
    else
    return stck[tepe--];   //tepe değerini döndür.
}

//===============================APPLICATION FILE==========================================
int main()
{
    stack<int> stackNesne1;
    stackNesne1.push(12);                 //stack'e 12 değerinde eleman ekledik.
    //Bundan sonrası test amaçlı...
    cout<<stackNesne1.getTepe()<<endl;    //tepe değeri 0 olarak döndü; eklendi!
    cout<<stackNesne1.pop()<<endl;        //12  döndürdü. en tepeye 12 eklemiştik. doğru işledi.
    cout<<stackNesne1.getTepe()<<endl;    //-1 döndürdü. doğru tepeden eklediğimiz elemanı geri çıkardık.
    stackNesne1.pop();                    //stack boş ama bir eleman daha çıkarmaya çalıştım
    cout<<stackNesne1.getTepe()<<endl;    //-1 döndürdü,  başka eleman çıkarmadı. stack şu anda boş
    stackNesne1.push(100);
    stackNesne1.push(200);
    stackNesne1.push(300);                //stack'e 3 eleman ekledim. en tepede 300 oldu.
    cout<<stackNesne1.getTepe()<<endl;   //2 döndürdü.
    stackNesne1.push(400);                //stack'e eklenemeyecek
    stackNesne1.push(500);              //stack'e eklenemeyecek
    stackNesne1.push(600);              //stack'e eklenemeyecek
    cout<<stackNesne1.getTepe()<<endl;   //2 döndürdü. tepe 2...
    cout<<stackNesne1.pop()<<endl;          //stackden eleman çıkardım. en tepede 300 vardı. onu çıkardı.
    cout<<stackNesne1.getTepe()<<endl;      //stackden bir eleman çıkarınca tepe 1'e indi.
    cout<<stackNesne1.pop()<<endl;   //tepede 200 vardı. onu çıkardı.
    cout<<stackNesne1.pop()<<endl;    //tepede 100 vardı. onu çıkardı.
    cout<<stackNesne1.getTepe()<<endl;   //-1
    stackNesne1.pop();                  //çıkarmayacak
    stackNesne1.pop();                  //çıkarmayacak
    cout<<stackNesne1.getTepe()<<endl;  //tepe yine -1 döndürdü.
    return 0;
}

/*
 * Stack'ın kapasitesi önceden tanımlanır.
 * Stackde elemanlar tepeye eklenir, eleman çıkarılacağı zaman tepeden çıkarılır. LIFO
 * Sıralıdır.
 * üye fnlar: push():ekleme, pop(): çıkarma Bütün ekleme ve çıkarmalar sadece tepeden yapılır.
 * Overflow state: stack'ın tamamen dolması durumu; Underflow state: tamamen boş olma durumu
 */
