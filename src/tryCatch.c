// AFTER article
// "Пишем try-catch в C не привлекая внимания санитаров"
// LINK: https://habr.com/ru/post/701338/

// datatype of error can be everything
typedef void *data_t;
typedef void *err_t;

// to define an error function 
typedef void (*throw_t)(err_t);

