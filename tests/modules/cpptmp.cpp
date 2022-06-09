    template <typename T, std::size_t N>
    T bitrange(unsigned start, unsigned end, std::bitset<N>&& bits) {
      unsigned mask = ((1 << end) - 1) << start;
      return bits & mask;
    }
