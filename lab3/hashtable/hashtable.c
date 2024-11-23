#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "hashtable.h"
#include "mem.h"
#include "../set/set.h" 
#include "hash.h"


typedef struct hashtable {
    set_t **slots; //double pointers, an array of pointers to sets
    int num_slots;
} hashtable_t;


/**************** functions ****************/
/**************** hashtable_new ****************/

hashtable_t* hashtable_new(const int num_slots) {
    
    if (num_slots < 0) {
        return NULL;
    }

    // Allocate memory for the hashtable structure
    hashtable_t* hashtable = (hashtable_t*) malloc(sizeof(hashtable_t)); 
        
    
    // Check for memory allocation failure
    if (hashtable == NULL) {
        return NULL;
    }

    // Allocate memory for the slots (array of pointers to sets)
    hashtable->slots = (set_t**) mem_malloc(num_slots * sizeof(set_t*));
    
    // Check for memory allocation failure
    if (hashtable->slots == NULL) {
        return NULL;
    }

    // create an empty set in each slot
    for (int i = 0; i < num_slots; i++) {
        hashtable->slots[i] = set_new();
    }
    hashtable->num_slots = num_slots;

    return hashtable;

}

/**************** hashtable_insert ****************/

bool hashtable_insert(hashtable_t* ht, const char* key, void* item) {

    if (ht == NULL || key == NULL || item == NULL) {
    return false;
    }

    int hash = hash_jenkins(key, ht->num_slots);

    // Check if key already exists
    if (set_find(ht->slots[hash], key)) {
        return false;
    }

    else{

    // copy the key
    char *keyCopy = malloc(strlen(key) + 1);
    strcpy(keyCopy, key);

    set_insert(ht->slots[hash], keyCopy, item);
    return true; 
}
}
        


/**************** hashtable_find ****************/

void* hashtable_find(hashtable_t* ht, const char* key) {

    if (ht != NULL && key != NULL) {
    
        int hash = hash_jenkins(key, ht->num_slots);

        return set_find(ht->slots[hash], key);
    
    } 
    
    else {
        return NULL;
    }
}

/**************** hashtable_print ****************/

void 
hashtable_print(hashtable_t* ht, FILE* fp, void (*itemprint)(FILE* fp, const char* key, void* item)) {
    if (fp == NULL) {
        return;
    }

    if (ht != NULL) {
        fputs("(null)", fp);
        return;
    }

    // Iterate through the ht
    for (int i = 0; i < ht->num_slots; i++) {
        //Print each set
        fprintf(fp, "Slot %d:", i);
        set_print(ht->slots[i], fp, (*itemprint));
    }
}

/**************** hashtable_iterate ****************/

void 
hashtable_iterate(hashtable_t* ht, void* arg, void (*itemfunc)(void* arg, const char* key, void* item) ) {
    if (ht == NULL || itemfunc == NULL ) {
        return;
    }

    else {
        for (int i = 0; i < ht->num_slots; i++ ) {
        set_iterate(ht->slots[i], arg, (*itemfunc));
    }
  }
}

/**************** hashtable_delete ****************/

void hashtable_delete(hashtable_t* ht, void (*itemdelete)(void* item) ) {
    if (ht == NULL) {
        return;
    }

    else {
        for (int i = 0; i < ht->num_slots; i++ ) {
            set_delete(ht->slots[i], (*itemdelete));
        }
    }

    free(ht->slots);
    free(ht);
}