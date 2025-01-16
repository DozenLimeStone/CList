#include <string.h>
#include <stdio.h>

struct list{
    void* lst;
    size_t elelen;
    size_t size;
};void initlist(struct list* lst,const size_t elelen){
    lst->elelen=elelen;
    lst->lst=malloc(elelen);
    lst->size=0;
}void addtolist(struct list* lst,void* ele){
    lst->size++;
    lst->lst=realloc(lst->lst,lst->size*lst->elelen);
    memcpy(lst->lst+(lst->elelen*(lst->size-1)),ele,lst->elelen);
}void inserttolist(struct list* lst,void* ele,const size_t index){
    lst->size++;
    lst->lst=realloc(lst->lst,lst->size*lst->elelen);
    memmove(lst->lst+(index+1)*lst->elelen,lst->lst+index*lst->elelen,(lst->size-index)*lst->elelen);
    memcpy(lst->lst+index*lst->elelen,ele,lst->elelen);
}void* getfromlist(struct list* lst,const size_t index){
    void* returnval=malloc(lst->elelen);
    memcpy(returnval,lst->lst+index*lst->elelen,lst->elelen);
    return returnval;
}void removelastfromlist(struct list* lst){
    lst->size--;
    memset(lst->lst+lst->size*lst->elelen,0,lst->elelen);
    lst->lst=realloc(lst->lst,lst->size*lst->elelen);
}void removefromlist(struct list* lst,const size_t index){
    memmove(lst->lst+lst->elelen*index,lst->lst+(index+1)*lst->elelen,(lst->size-index)*lst->elelen);
    lst->size--;
    lst->lst=realloc(lst->lst,lst->size*lst->elelen);
}void settolist(struct list* lst,void* ele,size_t index){
    memcpy(lst->lst+index*lst->elelen,ele,lst->elelen);
}//todo idk
