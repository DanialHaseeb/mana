# Space Age

Given an age in seconds, calculate how old someone would be on:

   - Mercury: orbital period $0.2408467$ Earth years
   - Venus: orbital period $0.61519726$ Earth years
   - Earth: orbital period $1.0$ Earth years, $365.25$ Earth days, or $31557600$
     seconds
   - Mars: orbital period $1.8808158$ Earth years
   - Jupiter: orbital period $11.862615$ Earth years
   - Saturn: orbital period $29.447498$ Earth years
   - Uranus: orbital period $84.016846$ Earth years
   - Neptune: orbital period $164.79132$ Earth years

So if you were told someone were $1\,000\,000\,000$ seconds old, you should be
able to say that they're $31.69$ Earth-years old.

If you're wondering why Pluto didn't make the cut, go watch
[this YouTube video](http://www.youtube.com/watch?v=Z_2gbGXzFbs).

## Topics

Some Rust topics you may want to read about while solving this problem:

- Traits, both the From trait and implementing your own traits
- Default method implementations for traits
- Macros, the use of a macro could reduce boilerplate and increase readability
  for this exercise. For instance,
  [a macro can implement a trait for multiple types at once](https://stackoverflow.com/questions/39150216/implementing-a-trait-for-multiple-types-at-once),
  though it is fine to implement `years_during` in the Planet trait itself.  A
  macro could define both the structs and their implementations.  Info to get
  started with macros canbe found at:

  - [The Macros chapter in The Rust Programming Language](https://doc.rust-lang.org/stable/book/ch19-06-macros.html)
  - [an older version of the Macros chapter with helpful detail](https://doc.rust-lang.org/1.30.0/book/first-edition/macros.html)
  - [Rust By Example](https://doc.rust-lang.org/stable/rust-by-example/macros.html)
