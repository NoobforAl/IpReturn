# IP Return

simple API with written With C, this API return only your IP!

For writ API i use this pkg : [ulfius](https://github.com/babelouest/ulfius)

## How Run ?

Two way for run this program:

1 - Run docker

Build image:
> docker build --pull --rm -f "Dockerfile" -t ipreturn:latest "."

And Run container:
> docker run -d -p 8080:8080 ipreturn

2 - Run with gcc compiler

You need linux machine (i use arch linux for this program).

Install gcc:
> sudo pacman install gcc

Install make:
> sudo pacman install make

Install ulfius:
>sudo pacman isntall ulfius

And run code:
> make run

And you can test Program:
> curl 127.0.0.1:8080

OutPut:

```txt
127.0.0.1
```
