int is_prime(int x) {
    if (x < 2) return 0;
    if (x == 2 || x == 3) return 1;
    if (x % 2 == 0) return 0;
    int i = 3;
    while (i * i <= x) {
        if (x % i == 0) return 0;
        i += 2;
    }
    return 1;
}

int next_prime(int x) {
    while (!is_prime(x)) x++;
    return x;
}
