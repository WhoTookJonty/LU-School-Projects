#pragma once

#include "ABag.h"
#include "dictionaryADT.h"
#include "kvpair.h"
#include <memory> //smart pointer library

template <typename Key, typename E>

class BDictionary : public Dictionary<Key, E> {
public:
    BDictionary()   // Default constructor
    {
        dictionary = new ABag<KVpair<Key, E>>;
    }        
    ~BDictionary() { delete dictionary; }         // Base destructor - deallocates dictionary pointer memry
   
    //Calls Abag function, emptyBag, deletes all objects in vector AKA the "bag"
    void clear() {
        dictionary->emptyBag();
    }

    // Inserts a new Key (k) Value (e) pair record into the bag
    bool insert(const Key& k, const E& e) {
        bool insertSuccess = false;
       unique_ptr <KVpair<Key, E>> kvpair = make_unique<KVpair<Key, E>>(k, e); //smart pointer

        if (dictionary->size() <= dictionary->bagCapacity()) { //checks if there is space in the bag
            dictionary->addItem(*kvpair); //adds smart pointer Key Value pair into the bag
            insertSuccess = true; //updates boolean value
        }  
        
        return insertSuccess;
    }
    // Looks for a record using the key and if found does the following:
  // - updates the E& rtnVal
  // - removes the record from the dictionary
  // - returns true
  // If the record is not found the function returns false.
    bool remove(const Key& k, E& rtnVal) {
        unique_ptr <KVpair<Key, E>> kvpair = make_unique<KVpair<Key, E>>(k, rtnVal); //smart pointer to hold Key Value pair

        bool found = dictionary->remove(*kvpair); //searches for and removes an object in the bag whose KeyValue pair matches the passed in smart pointer

        if (found)
        {
            rtnVal = kvpair->value(); //sets rtnVal to the smart pointer value from the remove function in Abag
        }

        return found; //if true then remove was successful, if false then unsucessful
    }
    // Takes an arbitrary record from the dictionary and does the following:
  // - updates the E& returnValue
  // - removes the record from the dictionary
  // - returns true
  // If the dictionary is empty the function returns false.
    bool removeAny(E& returnValue) {
        bool success = false;
        unique_ptr <KVpair<Key, E>> kvpair = make_unique<KVpair<Key, E>>(); //smart pointer 

        success = dictionary->removeTop(*kvpair); //Sets kvpair to the topvalue of the bag which is then removed from the dictionary. 
                                                  //If this returns true then the bag was not empty and kvpair is updated

        if (success)
        {
            returnValue = kvpair->value(); 
        }
        return success;
    }

    //Function to find an object in the dictionary that matches a Key (k) Value (returnValue) pair
    bool find(const Key& k, E& returnValue) const {
        bool found = false;
        unique_ptr <KVpair<Key, E>> kvpair = make_unique<KVpair<Key, E>>(k, returnValue); //smart pointer

        if (dictionary->find(*kvpair)) //calls Abag function to search for object of the same Key Value pair
        {
            returnValue = kvpair->value();
            found = true;
        }

        return found;

    }
    //Returns size of dictionary
    int size() { 
       return dictionary->size();
    }


private:

    ABag<KVpair<Key, E>>* dictionary; 
  
   
};

