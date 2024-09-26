class MyCalendar {
public:
    std::map<int, int> bookings;  // This will store the start and end times.

    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = bookings.lower_bound(end);  // Find the first booking with start >= end
        if (it != bookings.begin()) {
            --it;  // Check the previous booking
            if (it->second > start) {
        // If the previous booking ends after the new booking's start, there's an overlap.
                return false;
            }
        }
        bookings[start] = end;  // Insert the new booking if no overlap
        return true;   
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
