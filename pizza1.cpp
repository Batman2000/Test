#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class pizza
{
public:
    string type_of_spices;
    int cost;
    string size;
    virtual void info() = 0;
};

class robots_pizza: public pizza
{
public:
    int how_many_motor_oils;
    robots_pizza()
    {
        cout << "type number of motor oils";
        cin >> how_many_motor_oils;
    }
    ~robots_pizza(){}
    void info()
    {
        cout << "Your pizza contains from " << how_many_motor_oils << " oils and contains " << type_of_spices << " spices"<< endl;
        cout << "It will cost " << cost << " dollars and will have size " << size << endl;
    }
};

class mans_pizza: public pizza
{
public:
    int how_many_types_of_cheese;
    mans_pizza()
    {
        cout << "type number of cheeses";
        cin >> how_many_types_of_cheese;
    }
    ~mans_pizza(){}
    void info()
    {
        cout << "Your pizza contains from " << how_many_types_of_cheese << " kinds of cheese and contains " << type_of_spices << " spices"<< endl;
        cout << "It will cost " << cost << " dollars and will have size " << size << endl;
    }
};

class pizzabuilder
{
public:
    pizzabuilder(){}
    ~pizzabuilder(){}
    pizza *result;
    void capcha()
    {
        int a = (rand())%10;
        int b = (rand())%10;
        cout << "Type answer, proove that u r not a robot " << a << '+' << b <<'=';
        int k;
        cin >> k;
        if(k == a+b)
        {
            result = new mans_pizza;
        }
        else
        {
            result = new robots_pizza;
        }
    }
    pizza* return_res()
    {
        return result;
    }

    virtual void get_cost() = 0;
    virtual void get_size() = 0;
    virtual void get_spices() = 0;
};

class pepperoni: public pizzabuilder
{
public:
    pepperoni()
    {

    }
    ~pepperoni(){}
    void get_cost()
    {
        result->cost = 500;
    }
    void get_size()
    {
        cout << "Type 1 if u want small pizza and 2 either";
        int x;
        cin >> x;
        if(x == 1)
        {
            result->size = "small";
        }
        else
        {
            result->size = "big";
        }
    }
    void get_spices()
    {
        cout << "Press one if u want italian and 2 if u want french spices";
        int x;
        cin >> x;
        if(x == 1)
        {
            result->type_of_spices = "italian";
        }
        else
        {
            result->type_of_spices = "french";
        }
    }

};
class cheeses: public pizzabuilder
{
public:
    cheeses()
    {

    }
    ~cheeses(){}
    void get_cost()
    {
        result->cost = 750;
    }
    void get_size()
    {
        result->size = "big";
    }
    void get_spices()
    {
        cout << "Press one if u want italian and 2 if u want french spices";
        int x;
        cin >> x;
        if(x == 1)
        {
            result->type_of_spices = "italian";
        }
        else
        {
            result->type_of_spices = "french";
        }
    }

};


class Pizzeria {
public:
    string chief;
    pizzabuilder *custom;

    Pizzeria() {

    }

    ~Pizzeria() {}

    void clients_decision(pizzabuilder *decision) {
        custom = decision;
    }

    pizza *return_res() {
        return custom->return_res();
    }

    void cook_dough()
    {
        cout << "here is cooking dough, it depends on size of pizza";
    }
    void add_spices()
    {
        cout << "here are adding spices that people need";
    }
    void cook_everything_else() {
        cout << "here are preaparing all other parts of pizza";
    }

    void pack_pizza()
    {
        cout << "serving and packing pizza";
    }
    void deliver()
    {
        cout << "here is going process of delivery";
    }
    void auto_cook()
    {
        cook_dough();
        add_spices();
        cook_everything_else();
        pack_pizza();
        deliver();
    }

    virtual void setchief() = 0;


};

class MansPizzeria: public Pizzeria
{
public:
    MansPizzeria()
    {

    }
    ~MansPizzeria(){}

    mans_pizza *for_us;
    void setchief()
    {
        chief = "man";
    }


};

class RobotsPizzeria: public Pizzeria
{
public:
    RobotsPizzeria()
    {

    }
    ~RobotsPizzeria(){}

    robots_pizza *for_them;
    void setchief()
    {
        chief = "robot";
    }


};



int main() {
    cout << "Hi, here is Pizzeria of Future!" << endl;
    cout << "do u want to create pizza by yourself?(type yes or no) p.s. custom pizza is made only by men";
    string ans;
    cin >> ans;
    if(ans == "no") {
        string s;
        cout << "choose pizzeria type";
        cin >> s;
        if (s == "robot") {
            RobotsPizzeria *robo = new RobotsPizzeria;
            robo->setchief();
            cout << "choose pepperoni or cheeses";
            string q;
            cin >> q;
            if (q == "pepperoni") {
                pepperoni hmm();
                robo->clients_decision(&hmm);

            } else {
                cheeses hmm;
                robo->clients_decision(&hmm);
            }
            robo->auto_cook();
            pizza *final = robo->return_res();
            final->info();
        } else {
            MansPizzeria *man = new MansPizzeria;
            man->setchief();
            cout << "choose pepperoni or cheeses";
            string q;
            cin >> q;
            if(q == "pepperoni") {
                pepperoni hmm;
                man->clients_decision(&hmm);

            }
            else
            {
                cheeses hmm;
                man->clients_decision(&hmm);
            }
            man->auto_cook();
            pizza *final = man->return_res();
            final->info();
        }
    }
    else
    {
        MansPizzeria *man = new MansPizzeria;
        cout << "choose size: big or small?";
        string s;
        cin >> s;
        man->custom->result->size = s;
        if(s == "big")
        {
            man->custom->result->cost = 750;
        }
        else
        {
            man->custom->result->cost = 500;
        }
        cout << "choose spices: italian or french?";
        string h;
        cin >> h;
        man->custom->result->type_of_spices = h;
        man->auto_cook();
        pizza *ans = man->return_res();
        ans->info();

    }
    return 0;
}
