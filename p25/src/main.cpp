#include "Twitter.hpp"


int main(){
    RedeSocial twitter;
    int i;

    // registrando usuarios
    for(i=1; i<=4; i++)
        twitter.registarUsuario("u"+to_string(i), "usuario"+to_string(i));


    // usuarios registrados
    Usuario* u1 = twitter.buscarUsuario("u1");
    Usuario* u2 = twitter.buscarUsuario("u2");
    Usuario* u3 = twitter.buscarUsuario("u3");
    Usuario* u4 = twitter.buscarUsuario("u4");

    // fazendo tweets
    Tweet t1(u1, "tweet1-u1");
    Tweet t2(u1, "tweet2-u1");
    u1->postaTweet(&t1);
    u1->postaTweet(&t2);
    
    Tweet t3(u2, "tweet1-u2");
    Tweet t4(u2, "tweet2-u2");
    Tweet t5(u2, "tweet3-u2");
    u2->postaTweet(&t3);
    u2->postaTweet(&t4);
    u2->postaTweet(&t5);

    Tweet t6(u3, "tweet1-u3");
    u3->postaTweet(&t6);

    Tweet t7(u4, "tweet1-u4");
    Tweet t8(u4, "tweet2-u4");
    u4->postaTweet(&t7);
    u4->postaTweet(&t8);

    // seguindo
    u1->seguir(u2);
    u1->seguir(u3);
    u1->seguir(u4);

    u2->seguir(u1);
    u2->seguir(u4);

    u3->seguir(u1);
    u3->seguir(u2);

    u4->seguir(u1);
    u4->seguir(u3);

    // listar user
    cout << "Usuarios: \n";
    for(Usuario* u: twitter.listarUsuarios()){
        cout << u->toStringCompleto() << endl;
    }

    // listar tweets
    cout << "\n\nTweets: \n";
    for(Tweet* t : RedeSocial::listarTweets()){
        cout << t->toString() << endl;
    }

    // feeds
    vector<Tweet*> feed;
    
    cout << "\n\nFeed de " + u1->toStringUser() + ": \n";
    feed = u1->receberFeed();
    for(Tweet* t : feed){
        cout << t->toString() << endl;
    }

    cout << "\nFeed de " + u2->toStringUser() + ": \n";
    feed = u2->receberFeed();
    for(Tweet* t : feed){
        cout << t->toString() << endl;
    }

    cout << "\nFeed de " + u3->toStringUser() + ": \n";
    feed = u3->receberFeed();
    for(Tweet* t : feed){
        cout << t->toString() << endl;
    }

    cout << "\nFeed de " + u4->toStringUser() + ": \n";
    feed = u4->receberFeed();
    for(Tweet* t : feed){
        cout << t->toString() << endl;
    }

    return 0;
}