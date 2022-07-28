#�������
src=$(wildcard ./*.c)
objs=$(patsubst %.c,%.o,$(src))
target=app
$(target):$(objs)
	gcc $(objs) -o $(target)
%.o:%.c
	gcc -c $< -o $@

.PHONY:clean
clean:
	rm -f $(objs) 
