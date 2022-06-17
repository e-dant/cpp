namespace util {
auto isbitset(const unsigned bit, const unsigned bits) noexcept -> bool {
  return (1 == ((bit >> bits) & 1));
}
auto getbitrange(const unsigned start,
                 const unsigned end,
                 unsigned bits) noexcept -> unsigned {
  // greatest value this type can hold
  static constexpr const unsigned max_n = CHAR_BIT * sizeof(unsigned);
  const unsigned n = end - start;
  // return 0 if 'start' left-padded with infinite zeros
  if (start >= max_n)
    return 0;
  // drop bits before 'start'
  bits >>= start;
  // if gt/eq here, then return all bits.
  // it shouldn't be greater than, but it
  // doesn't hurt to test.
  if (n >= max_n)
    return bits;
  // if none of the above edge-cases, then
  // continue with a regular & mask (bits & ((1<<n)-1))
  // (after shifting to 'start' above)
  const unsigned mask = (1u << n) - 1; /* n '1's */
  return bits & mask;
}
unsigned int krgetbits(int start, int nbits, unsigned int bits) noexcept {
  return (bits >> (start + 1 - nbits)) & ~(~0 << nbits);
}
auto getbits(const unsigned start, const unsigned n, unsigned bits) noexcept
    -> unsigned {
  // greatest value this type can hold
  static constexpr const unsigned max_n = CHAR_BIT * sizeof(unsigned);
  // return 0 if 'start' left-padded with infinite zeros
  if (start >= max_n)
    return 0;
  // drop bits before 'start'
  bits >>= start;
  // if gt/eq here, then return all bits.
  // it shouldn't be greater than, but it
  // doesn't hurt to test.
  if (n >= max_n)
    return bits;
  // if none of the above edge-cases, then
  // continue with a regular & mask (bits & ((1<<n)-1))
  // (after shifting to 'start' above)
  const unsigned mask = (1u << n) - 1; /* n '1's */
  return bits & mask;
}
}  // namespace utill
