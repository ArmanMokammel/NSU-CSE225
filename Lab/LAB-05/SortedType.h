#ifndef SORTEDTYPE_H_INCLUDED
#define SORTEDTYPE_H_INCLUDED

const int MAX_ITEMS = 5; //Setting the max number of items for the array to be 5

template <class ItemType>
class SortedType
{
    public:
        SortedType(); //Constructor
        void MakeEmpty(); //To clear out the array
        bool IsFull(); //Check if the array is full
        int LengthIs(); //Get the length of the array
        void InsertItem(ItemType); //Insert an [ItemType] item into the array
        void DeleteItem(ItemType); //Delete an [ItemType] item from the array
        void RetrieveItem(ItemType&, bool&); //Get an [ItemType] item from the array
        void ResetList(); //Resets the currentPosition counter of the array
        void GetNextItem(ItemType&); //Gets the item after the currentPosition

    private:
        int length;
        ItemType arr[MAX_ITEMS];
        int currentPos;
};

#endif