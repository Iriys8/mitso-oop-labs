#include <iostream>
#include <string>

template <class chtoto>
class cvass {
    struct node {
        int prior = 0;
        chtoto info;
        void add_next(node* next) {
            this->next = next;
            return;
        };
        void add_prev(node* prev) {
            this->prev = prev;
            return;
        };
        node* get_next() {
            return next;
        };
        node* get_prev() {
            return prev;
        };
    private:
        //inline node(); // Ошибка	C2248	cvass<std::string>::node::node : невозможно обратиться к private член, объявленному в классе "cvass<std::string>::node"
        node* next = NULL;
        node* prev = NULL;
    };

    node* first = NULL;
    chtoto type_template;


public:
    inline cvass(int prior_add, chtoto info_add) {
        first = new node();
        first->prior = prior_add;
        first->info = info_add;
        type_template = info_add;
    }
    inline cvass(const cvass &ne_cvass) {
        first = ne_cvass.first;
        type_template = ne_cvass.type_template;
    }
    inline cvass(cvass&& ne_ne_cvass) {
        first = ne_ne_cvass.first;
        ne_ne_cvass.first = NULL;
        type_template = ne_ne_cvass.type_template;
        type_template = NULL;
    }
    ~cvass() {
        if (first != NULL) {
            node* current_node = first;
            while (current_node->get_next() != NULL)
                current_node = current_node->get_next();
            while (current_node->get_prev() != NULL) {
                current_node = current_node->get_prev();
                delete current_node->get_next();
            }
            delete current_node;
        }
    }
    void add(int prior_add, chtoto info_add) {
        if (first == NULL) {
            cvass(prior_add,info_add);
            return;
        }
        node* temp_node = first;
        while (temp_node->add_next(NULL)) {
            temp_node = temp_node->get_next();
        }
        node node_new = new node();
        node_new.prev = temp_node;
        node_new.info = info_add;
        node_new.prior = prior_add;
        temp_node->add_next(); &node_new;
        temp_node = NULL;
        return;
    }
    chtoto claim(int prior_find) {
        node* node_DAI_SVOI_INFORMATION = first;
        while (node_DAI_SVOI_INFORMATION->prior != prior_find && node_DAI_SVOI_INFORMATION->get_next() != NULL) {
            node_DAI_SVOI_INFORMATION = node_DAI_SVOI_INFORMATION->get_next();
        }
        if (node_DAI_SVOI_INFORMATION->get_next() == NULL && node_DAI_SVOI_INFORMATION->prior != prior_find) {
            std::cout << "Да нет такого приоретите! Бери первое значение и уходи!" << std::endl;
            return first->info;
        }
        chtoto temp = node_DAI_SVOI_INFORMATION->info;
        if (node_DAI_SVOI_INFORMATION == first && first->get_next() == NULL) {
            delete first;
            first = NULL;
            return temp;
        }
        else if (node_DAI_SVOI_INFORMATION == first && first->get_next() != NULL) {
            first = first->get_next();
            first->add_prev(NULL);
            delete node_DAI_SVOI_INFORMATION;
            return temp;
        }
        else if (node_DAI_SVOI_INFORMATION->get_next() == NULL && node_DAI_SVOI_INFORMATION->prior == prior_find) {
            node_DAI_SVOI_INFORMATION->get_prev()->add_next(NULL);
            delete node_DAI_SVOI_INFORMATION;
            return temp;
        }
        else {
            node* prev = node_DAI_SVOI_INFORMATION->get_prev();
            node* next = node_DAI_SVOI_INFORMATION->get_next();
            prev->add_next(node_DAI_SVOI_INFORMATION->get_next());
            next->add_prev(node_DAI_SVOI_INFORMATION->get_prev());
            delete node_DAI_SVOI_INFORMATION;
            prev = NULL;
            next = NULL;
            return temp;
        }
    }
    chtoto get_type_template() {
        return type_template;
    }
};

int main() {
    setlocale(0, "ru");
    cvass <int> vodka(1, 454);
    std::cout << vodka.claim(1);

}