#hello word extension

##install

	path/phpize  && ./configure --with-php-config=/path/php-config
    make && sudo make install
    sudo vim /path/php.ini   //add extension=/path/hello_word.so
    
## function

	void   echo_hello_php();   // 等价于 echo "hello php";
    string return_hello_php(); // echo return_hello_php(); 
    
## RETURN_STRINGL( str ,len , duplicate ) 

###参数

>str       字符串
>len       字符串长度
>duplicate 是否拷贝

`RETURN_STRINGL` 函数实现

	#define ZVAL_STRINGL(z, s, l, duplicate) do {	\
		const char *__s=(s); int __l=l;			\		
		zval *__z = (z);						\
		Z_STRLEN_P(__z) = __l;					\		//定义zval z的长度
        // duplacate 为true的时候 使用estrndup来分配内存拷贝字符串,否则使用原字符串
		Z_STRVAL_P(__z) = (duplicate?estrndup(__s, __l):(char*)__s);\  //
        //定义 __z为字符串类型
		Z_TYPE_P(__z) = IS_STRING;				\
	} while (0)
    
    