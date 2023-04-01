all: ray-tracer
	
run: ray-tracer
	./ray-tracer.exe

ray-tracer:
	gcc src/*.c -o ray-tracer.exe
	
clean:
	del ray-tracer.exe
	
clean-all: clean
	del *.png
	del *.jpg