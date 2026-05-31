/**
 * @param {number} mass
 * @param {number[]} asteroids
 * @return {boolean}
 */
var asteroidsDestroyed = function(mass, asteroids) {
    asteroids.sort((a, b) => a - b);
    const n = asteroids.length
    for(let i = 0; i < n; i++) {
        if(asteroids[i] <= mass) mass += asteroids[i]
        else return false;
    }
    return true;
};