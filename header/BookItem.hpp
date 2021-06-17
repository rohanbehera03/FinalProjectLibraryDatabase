#ifndef LIBRARYSYSTEM_BOOKITEM_HPP
#define LIBRARYSYSTEM_BOOKITEM_HPP
#include "Date.hpp"


//class BookItem : public Book {
class BookItem {
private:
    Date checkoutDate;
    Date dueDate;
public:
    BookItem();
    BookItem(const BookItem &bookItem);
    BookItem(Date &checkOutDate, Date &dueDate);
    Date getCheckoutDate();
    void setCheckoutDate(Date checkoutDate);
    Date getDueDate();
    void setDueDate(Date dueDate);
};


#endif //LIBRARYSYSTEM_BOOKITEM_HPP
