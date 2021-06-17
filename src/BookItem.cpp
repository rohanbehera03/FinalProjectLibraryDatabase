#include "../header/BookItem.hpp"

BookItem::BookItem() {

}

BookItem::BookItem(const BookItem &bookItem) {
    checkoutDate = bookItem.checkoutDate;
    dueDate = bookItem.dueDate;
}
BookItem::BookItem(Date &cDate, Date &dDate)  {
    checkoutDate = cDate;
    dueDate = dDate;
}

void BookItem::setCheckoutDate(Date aDate) {
    checkoutDate.setDay(aDate.getDay());
    checkoutDate.setMonth(aDate.getMonth());
    checkoutDate.setYear(aDate.getYear());
}

Date BookItem::getCheckoutDate() {
    return checkoutDate;
}

Date BookItem::getDueDate() {
    return dueDate;
}

void BookItem::setDueDate(Date dDate) {
    dueDate.setDay(dDate.getDay());
    dueDate.setMonth(dDate.getMonth());
    dueDate.setYear(dDate.getYear());
}
