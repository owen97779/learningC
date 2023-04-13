### 1)
    void *my_malloc(size_t n)
    {
        void *p = malloc(n);

        if(p == NULL)
        {
            printf("Error\n");
            exit(1);
        }

        return p;
    }

### 2)

    void *duplicate(const char *str)
    {
        char *p = malloc(strlen(str) + 1);

        if(p == NULL)
        {
            return p;
        }

        strcpy(p, str);

        return p;
    }

### 3)
    int *create_array(int n, int initial_value)
    {
        int *p = malloc(n * sizeof(int));

        if(p == NULL)
        {
            return NULL;
        }

        for(int i = 0; i < n; i++)
        {
            p[i] = initial_value;
        }

        return p;
    }

### 4)
    p = (struct rectangle *) malloc(sizeof(struct rectangle));
    if(p == NULL)
    {
        exit(1);
    }
    p->upper_left = {10, 25};
    p->lower_right = {20, 15};

### 5)
Suppose that *f* and *p* are declared as follows:
    
    struct{
        union {
            char a, b;
            int c;
        } d;
        int e[5];
    } f, *p, = &f;

Which of the following statements are legal?

a) p->b = ' ';

Illegal

b) p->e[3] = 10;

Legal

c) (* p).d.a = '*';

Legal

d) p->d->c = 20;

Illegal

### 6) 
Modify the `delete_from_list` function so that it uses only one pointer variable instead of two (`cur` and `prev`).

    struct node *delete_from_list(struct node **list, int n)
    {
        struct node *entry = *list;

        while(entry)
        {
            if(entry->value == n)
            {
                *list = list->next;
                free(list);
                break;
            }
            list = &entry->next;
            entry = entry->next;
        }
    }

### 7)
....