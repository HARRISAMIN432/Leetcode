function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    return arr.map((n : number, i : number) => {
        return fn(n, i);
    })
};