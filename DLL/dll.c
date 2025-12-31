#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; 
    struct node *prev;
    struct node *next;
};

typedef struct node* NODE;

/* =========================================================
   BASIC OPERATIONS
   ========================================================= */

NODE createNode(int x) {
    NODE newNode = (NODE)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory not allocated\n");
        return NULL;
    }
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


NODE insertEnd(NODE head, int x) {
    NODE temp = createNode(x);
    if (head == NULL) return temp;

    NODE cur = head;
    while (cur->next != NULL)
        cur = cur->next;

    cur->next = temp;
    temp->prev = cur;
    return head;
}

void display(NODE head) {
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }
    NODE cur = head;
    printf("NULL <-> ");
    while (cur != NULL) {
        printf("%d <-> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

/* =========================================================
   NEW: IMAGE 1 REQUIREMENTS (PRIMITIVE OPERATIONS)
   (Insert Left, Delete by Value)
   ========================================================= */


NODE insertLeft(NODE head, int targetNodeValue, int newValue) {
    if (head == NULL) {
        printf("List is empty. Cannot search for %d\n", targetNodeValue);
        return NULL;
    }

    NODE cur = head;
    while (cur != NULL && cur->data != targetNodeValue) {
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Node with value %d not found.\n", targetNodeValue);
        return head;
    }

    NODE newNode = createNode(newValue);
    newNode->next = cur;
    newNode->prev = cur->prev;

    if (cur->prev != NULL) {
        cur->prev->next = newNode;
    } else {
        head = newNode; 
    }
    cur->prev = newNode;

    printf("Inserted %d to the left of %d.\n", newValue, targetNodeValue);
    return head;
}


NODE deleteByValue(NODE head, int key) {
    if (head == NULL) return NULL;

    NODE cur = head;
    while (cur != NULL && cur->data != key)
        cur = cur->next;

    if (cur == NULL) {
        printf("Value %d not found.\n", key);
        return head;
    }

    if (cur == head)
        head = head->next;
    if (cur->next != NULL)
        cur->next->prev = cur->prev;
    if (cur->prev != NULL)
        cur->prev->next = cur->next;

    free(cur);
    return head;
}

/* =========================================================
   QUESTION 10: MUSIC PLAYLIST SIMULATION
   ========================================================= */

NODE currentSong = NULL; 

void playSong(NODE songNode) {
    if (songNode) {
        currentSong = songNode;
        printf("Playing Song ID: %d\n", currentSong->data);
    } else {
        printf("No song selected.\n");
    }
}

void nextSong() {
    if (currentSong != NULL && currentSong->next != NULL) {
        currentSong = currentSong->next;
        printf("Moved to Next. Now Playing: %d\n", currentSong->data);
    } else {
        printf("End of Playlist.\n");
    }
}

void prevSong() {
    if (currentSong != NULL && currentSong->prev != NULL) {
        currentSong = currentSong->prev;
        printf("Moved to Prev. Now Playing: %d\n", currentSong->data);
    } else {
        printf("Start of Playlist.\n");
    }
}

NODE deleteCurrentSong(NODE head) {
    if (head == NULL || currentSong == NULL) return head;

    NODE toDelete = currentSong;

    if (toDelete->prev != NULL)
        toDelete->prev->next = toDelete->next;
    else
        head = toDelete->next; 

    if (toDelete->next != NULL)
        toDelete->next->prev = toDelete->prev;

    if (toDelete->next != NULL)
        currentSong = toDelete->next;
    else
        currentSong = toDelete->prev;

    printf("Deleted Song %d. ", toDelete->data);
    if (currentSong) printf("New Current: %d\n", currentSong->data);
    else printf("Playlist Empty.\n");

    free(toDelete);
    return head;
}

/* =========================================================
   QUESTION 3 / 18: REMOVE DUPLICATES (UNSORTED DLL)
   ========================================================= */

NODE removeDuplicatesDLL(NODE head) {
    NODE ptr1, ptr2, duplicate;
    ptr1 = head;

    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->data == ptr2->next->data) {
                duplicate = ptr2->next;
                ptr2->next = duplicate->next;
                if (duplicate->next != NULL)
                    duplicate->next->prev = ptr2;
                free(duplicate);
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    return head;
}

/* =========================================================
   MAIN FUNCTION
   ========================================================= */

int main() {
    NODE head = NULL;

    /* ---------- Q10: MUSIC PLAYLIST ---------- */
    /*
    head = insertEnd(head, 101);
    head = insertEnd(head, 102);
    head = insertEnd(head, 103);
    head = insertEnd(head, 104);
    
    display(head);
    playSong(head);       
    nextSong();           
    prevSong();           
    head = deleteCurrentSong(head); 
    display(head);
    */

    /* ---------- Q3/18: REMOVE DUPLICATES ---------- */
    /*
    head = insertEnd(head, 8);
    head = insertEnd(head, 7);
    head = insertEnd(head, 5);
    head = insertEnd(head, 8); 
    head = insertEnd(head, 7); 
    head = insertEnd(head, 8); 
    head = insertEnd(head, 1);
    
    printf("Original: ");
    display(head);

    head = removeDuplicatesDLL(head);

    printf("Cleaned:  ");
    display(head);
    */

    /* ---------- IMAGE 1 (PRIMITIVE OPS) ---------- */
    /*
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    
    printf("Original List: ");
    display(head);

    // Insert 15 to the LEFT of 20
    head = insertLeft(head, 20, 15);
    display(head);

    // Delete value 30
    head = deleteByValue(head, 30);
    display(head);
    */

    return 0;
}
