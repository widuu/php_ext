#RETURN

##function 

	string function return_string();  //echo website:http://www.widuu.com
    int    function return_long(1);   //echo 1, 必须要有一个参数

##knowledge

>函数原型 

    #define ZEND_FN(name) zif_##name
    #define ZEND_NAMED_FUNCTION(name)	void name(INTERNAL_FUNCTION_PARAMETERS)
    #define ZEND_FUNCTION(name)			ZEND_NAMED_FUNCTION(ZEND_FN(name))
    
    #define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used TSRMLS_DC
    
    //函数展开效果
    void zif_return_string(int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used TSRMLS_DC)

###INTERNAL_FUNCTION_PARAMETERS 参数说明
名称和类型|描述|访问宏
---|---|---
int ht	|用户实际传递参数的数量	|ZEND_NUM_ARGS()
zval *return_value	|PHP 变量的指针，可填充返回值传递给用户。默认值是 IS_NULL。	|RETVAL_*, RETURN_*
zval **return_value_ptr	|当返回引用时，PHP 将其设为变量的指针。不建议返回引用。|	 
zval *this_ptr	|假如这是一个方法调用，其指向存放 $this 对象的 PHP 变量。|	getThis()
int return_value_used	|指示返回值是否会被调用者使用的标志。 caller.	 |
