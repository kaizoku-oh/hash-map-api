# 🚀 Hash Map API
Portable hash map implementation in C

## 🔨 Running the examples

```bash
$ gcc -Wall examples/example2.c src/api_hash_map.c -Iinclude -o examples/example2
$ examples/example2
Hash map is initialized successfully

Item is added successfully
Item is added successfully
Item is added successfully

key: alice
value: 23

key: bob
value: 45

key: eve
value: 67
$ 
```

## ✅ TODO

- [x] Create a non generic api that can store and retrieve persons structures

- [x] Try to think of it as adding/retrieving key-value structures and refactor code accordingly

- [x] Add API error types

- [x] Make it safe to manipulate non null terminated strings

- [ ] Add hashmap definition macro to easily pass context between function calls

- [ ] Remove C dependencies and make types portable

- [ ] Add collision detection

- [ ] Add collision resolving

- [ ] Enhance the hashing function

- [ ] Try to think of a way to make the API more generic by making the key a string and the value a void pointer that points to user defined data

- [ ] Add doxygene documentation

- [ ] Add Arduino wrapper

- [ ] Add unit tests

- [ ] Publish API as a PIO package

- [ ] Add the possibility for hardware accelerated hashing

- [ ] Add CI/CD pipeline
