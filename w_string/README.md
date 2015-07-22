#RETURN

##function 

	string function return_string();  //echo website:http://www.widuu.com
    
##knowledge

>函数原型 

    #define ZEND_FN(name) zif_##name
    #define ZEND_NAMED_FUNCTION(name)	void name(INTERNAL_FUNCTION_PARAMETERS)
    #define ZEND_FUNCTION(name)		ZEND_NAMED_FUNCTION(ZEND_FN(name))
    
    #define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used TSRMLS_DC
    
    //函数展开效果
    void zif_return_string(int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used TSRMLS_DC)
 
> - `int ht`
> - `zval *return_value`，我们在函数内部修改这个指针，函数执行完成后，内核将把这个指针指向的zval返回给用户端的函数调用者。
> - `zval **return_value_ptr`，
> - `zval *this_ptr`，如果此函数是一个类的方法，那么这个指针的含义和PHP语言中$this变量差不多。
> - `int return_value_used`，代表用户端在调用此函数时有没有使用到它的返回值。 
    