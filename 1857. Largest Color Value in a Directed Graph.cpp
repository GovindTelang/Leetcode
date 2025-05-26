   Node *refHead = head;
        Node *temp = (head!=(head->next))?head->next:head;
        Node *newNode = new Node(data);
        Node *tail = head;
       
        if(newNode->data <= head->data)
        {
            while (tail->next != head)
                tail = tail->next;
    
            newNode->next = head;
            head = newNode;
            tail->next = head;
            return head;
        }
        
        if(((newNode->data)>(refHead->data)) && ((newNode->data)<=(temp->data)))
        {
            newNode->next = refHead->next;
            refHead->next = newNode;
            
            return head;
        }
        
        while(temp!=head && temp->next!=head)
        {
            if(((newNode->data)>(temp->data)) && (newNode->data)<=(temp->next->data))
            {
                newNode->next = temp->next;
                temp->next = newNode;
                
                return head;
            }
            temp = temp->next;
        }
        
        if(temp->next == head)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            head = newNode->next;
        }

        return head;
