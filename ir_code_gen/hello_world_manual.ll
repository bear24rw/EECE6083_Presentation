declare i32 @puts(i8*)
@global_str = constant [13 x i8] c"Hello World!\00"
define i32 @main () {
    %str_ptr = getelementptr [13 x i8]* @global_str, i64 0, i64 0
    call i32 @puts(i8* %str_ptr)
    ret i32 0
}
