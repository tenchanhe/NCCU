def get_from_cache(key):
    key = key
    def decorator(func):
        def wrapper(*args, **kwargs):
            if bool(args):
                rkey = key + '-uid-' + str(args[0])
                print(rkey)

                key = key + '-uid-' + str(args[0])
                print(key) # UnboundLocalError: local variable 'key' referenced before assignment
            else:
                print("no_arg")
            
            return func(key)

        return wrapper
    return decorator

@get_from_cache(key='hihi')
def print_out(key):
    print(key)


print_out(23)
