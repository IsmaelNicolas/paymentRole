#include <iostream>
#include "TextTable.h"
#define log(val) std::cout<<val<<std::endl;
#define log_2(val_1,val_2) std::cout<<val_1<<val_2<<std::endl;
#define console_log(val) std::cout<<val;
#define console_log_2(val,val_1) std::cout<<val<<val_1;

// Nodo Doble
template<class T>
class DoublyNode{
	public:	
		T data;
		DoublyNode* next;
		DoublyNode* prev;
		DoublyNode();
		DoublyNode(T);
};

template<class T>
DoublyNode<T>::DoublyNode(){
	this->next = nullptr;
	this->prev = nullptr;
	this-data = nullptr;
}

template<class T>
DoublyNode<T>::DoublyNode(T data){
	this->next = nullptr;
	this->prev = nullptr;
	this->data = data;
}

//Nodo Simple
template<class T>
class Node
{
public:

    T data;
    Node* next;
    Node();
    Node(T); 
    friend bool operator==(Node<T> &nd_1,Node<T> &nd_2)
    {
        if((nd_1.data == nd_2.data))
        {
            return true;
        }
        return false;
    }
    friend std::ostream &operator <<(std::ostream&out,const Node<T> &node)
    {out<<node.data;return out;}
};

template<class T>
Node<T>::Node()
{
    this->data = nullptr;
    this->next = nullptr;
}
template<typename T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = nullptr;
}


template<class T>
class CircularLinkedList{
	
	public:
		
		DoublyNode<T>* head;
		DoublyNode<T>* tail;
		CircularLinkedList();
		void insertEnd(T);
		void insertBegin(T);	
		void printList();
		int getSize();
	private: 
		int size;
	
};

template<class T>
CircularLinkedList<T>::CircularLinkedList(){
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

template<class T>
int CircularLinkedList<T>::getSize(){return size;}

template<class T>
void CircularLinkedList<T>::printList(){
	DoublyNode<T>* tmp = this->head;
	while(tmp->next != this->head){
		std::cout<<tmp->data<<"-";
		tmp = tmp->next; 
	} 
	std::cout << tmp->data <<std::endl;
}

template<class T>
void CircularLinkedList<T>::insertEnd(T data){
	DoublyNode<T>* temp = new DoublyNode<T>(data);
	if(this->head == nullptr) {

		this->head = temp;
		this->head->next = this->head;
		this->head->prev = this->head;
		this->tail = this->head;
	}else{
		
		this->tail->next = temp;
		temp->next = this->head;
		this->tail = temp;
		this->head->prev = this->tail; 
		
	}
		this->size+=1;
	
}

template<class T>
void CircularLinkedList<T>::insertBegin(T data){
	DoublyNode<T>* temp = new DoublyNode<T>(data);
	
	if(this->head == nullptr) {

		this->head = temp;
		this->head->next = this->head;
		this->head->prev = this->head;
		this->tail = this->head;
	}else{
		
		this->tail->next = temp;
		temp->next = this->head;
		this->tail = temp;
		this->head->prev = this->tail; 
		
	}
		this->size+=1;
	
}

//Lista simple
namespace List
{

   template<class R>
    class ordered
    {
    private:
        Node<R> object;
        int size;
        
    public:
        ordered();
        bool insert(Node<R>);
        bool remove(Node<R>);
        bool clean(Node<R>);
        bool is_empy();
        ~ordered();
    };

    template <typename T>
    class simple
    {
    private:
        Node<T>* object;
        int size;
    
    public:
        simple();
        simple(Node<T>);
        void print_list();
        void print_list_map();
        bool push_back(T);
        bool push_font(Node<T>);
        bool push_after_node(Node<T>,Node<T>);
        bool pop_front(Node<T>);
        bool pop_back(Node<T>);
        bool remplace(Node<T>,Node<T>);
        bool clean();
        bool is_empy();
        int get_size();
        Node<T>* buscarCedula(std::string cedula);
        void printTable();
        void printRowNode(Node<T>* elementoEncontrado);

        Node<T>* get_node()const
        {
            return this->object;
        }

        friend bool operator==(List::simple<T>& list_1 ,List::simple<T>& list_2)
        {
            Node<T> *tmp_1 = list_1.get_node(); 
            Node<T> *tmp_2 = list_2.get_node(); 

            while (tmp_1->next != NULL || tmp_2->next != NULL)
            {
                if(tmp_1->data != tmp_2->data)
                    return false;

                tmp_1 = tmp_1->next;
                tmp_2 = tmp_2->next;
            }
            return true;
        }
        friend std::ostream &operator <<(std::ostream&out,const List::simple<T> &list)
        {
            if (list.size == 0)
            {
                out<<"[ empy ]";
                return out;
            }else
            {
                Node<T> *tmp = list.object; 
                //out<<std::endl;
                out<<"[";
                while (tmp->next != NULL)
                {
                    out<<*tmp<<",";
                    tmp = tmp->next;
                }
                out<<tmp->data<<"]";
                return out;
            }
            
        }
        void operator+=(const Node<T>& nd);
        void operator+=(const T& nd);
        bool operator>( List::simple<T>& list);
        bool operator<( List::simple<T>& list);

    };



template<class T>
simple<T>::simple() : object(NULL),size(0){}

template<class T>
bool simple<T>::is_empy() {return this->size==0? true:false;}

template<class T>
int simple<T>::get_size(){return this->size;}

template<typename T>
inline Node<T>* simple<T>::buscarCedula(std::string cedula)
{
    if (size == 0) {
        log("Lista vacia");
    }
    else {
        Node<T>* tmp = this->object;

            while (tmp != NULL)
            {
                if (tmp->data.get_nui() == cedula) {
                    //std::cout << tmp->data.name << "Encontrado" << std::endl;
                    //log(tmp->data);
                    //system("pause");
                    return tmp;
                }
                tmp = tmp->next;
             
            }       

    }
    return nullptr;
}

template<typename T>
inline void simple<T>::printTable()
{
    
    TextTable tabla('-', '|', '+');
    tabla.add("Cedula");
    tabla.add("Nomina");
    tabla.add("Cargo");
    tabla.add("Salario");
    tabla.add("M.H.S");
    tabla.add("M.H.E");
    tabla.add("T.IESS");
    tabla.add("F.R");
    tabla.add("Ingreso T");
    tabla.add("IESS");
    tabla.add("Anticipo");
    tabla.add("Egreso T");
    tabla.add("A Recibir");
    tabla.endOfRow();

    if (size == 0) {
        log("Lista vacia");
    }
    else {
        Node<T>* tmp = this->object;
        
            while (tmp != NULL)
            {
                tabla.add(string(tmp->data.nui));

                tabla.add(string(tmp->data.name));
                //tabla.add((tmp->data.position);
                //tabla.add((string(tmp->data.salary));
                //tabla.add((string(tmp->data.sup_hours));
                //tabla.add((string(tmp->data.overtime));
                //tabla.add((string(tmp->data.totalIncomeIess));
                //tabla.add((string(tmp->data.reserveFund));
                //tabla.add((string(tmp->data.totalIncome));
                //tabla.add((string(tmp->data.iess));
                //tabla.add((string(tmp->data.advance));
                //tabla.add((string(tmp->data.totalOutput));
                //tabla.add((string(tmp->data.toRecieve));

                tabla.endOfRow();
                tmp = tmp->next;
            }
            std::cout << tabla << std::endl;

    }
}

template<typename T>
inline void simple<T>::printRowNode(Node<T>* elementoEncontrado)
{
    std::cout << elementoEncontrado->data.name << "Encontrado" << std::endl;
    system("pause");
}



template<class T>
void simple<T>::operator+=(const Node<T> &nd)
{
    this->push_back(nd.data);
}

template<class T>
void simple<T>::operator+=(const T &nd)
{
    this->push_back(nd);
}

template<class T>
bool simple<T>::operator>(List::simple<T>& list)
{
    return this->size > list.get_size();
}

template<class T>
bool simple<T>::operator<( List::simple<T>& list)
{
    return this->size < list.get_size();
}


template<class T>
void simple<T>::print_list()
{
    if(size == 0){
        log("Lista vacia");
    }else{
        Node<T> *tmp = this->object; 
        log("Elementos:")
        
        while (tmp->next != NULL)
        {
            console_log_2(*tmp,",");
            tmp = tmp->next;
        }
            log(tmp->data);
    
    }

}

template<class T>
void simple<T>::print_list_map()
{
    if(size == 0){
        log("Lista vacia");
    }else{
        Node<T> *tmp = this->object; 
        log("Elementos:")
        
        while (tmp->next != NULL)
        {
        	for (auto const& x : tmp->data)
			{
			    std::cout << x.first  // string (key)
			              << ':' 
			              << x.second // string's value 
			              << std::endl;
			}
            //console_log_2(*tmp,"->");
            tmp = tmp->next;
        }
            log(tmp->data);
    }
}

template<class T>
bool simple<T>::push_back(T item)
{
    Node<T> *tmp = new  Node<T>(item); 
    if(this->size == 0 )
    {   
        try
        {   
            this->object=tmp;
            this->size += 1;
            return true;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return false;
        }   
    }
    else
    {
        try
        {
            Node<T> * tmp_1 = this->object;
            while (tmp_1->next != NULL)
            {
                tmp_1 = tmp_1->next;
            }
            tmp_1->next = tmp;
            this->size += 1;

        return true;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return false;
        }
        
        
    }
    

}

template<class T>
bool simple<T>::clean()
{
    Node<T> * tmp_1 = this->object;
    Node<T> * tmp_2;

    while (tmp_1->next != NULL)
    {
        tmp_2 = tmp_1;
        tmp_1 = tmp_1->next;
        tmp_2 = NULL;
    }
    this->size = 0; 
    return true;
}

}