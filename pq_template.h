/**
 * @author framework by Jon Beck
 * @author completed by Your Name
 * @version date of last modification
 */

#ifndef PQ_H
#define PQ_H
#include <cassert>
#include <vector>

/**
 * class Javadoc description here
 */
template <typename Comparable> class PQ
{
 public:
  // no need for constructors, destructor, or operator= because
  // everything uses STL containers and immediate allocation

  void push(const Comparable & item)
  {
    heap.push_back(item);
    bubble_up(heap.size() - 1);
  }

  void pop()
  {
    // you implement this
  }

  const Comparable & top () const
  {
    assert(heap.size() > 0);
    return heap.at(0);
  }

  size_t find_position_of(size_t key) const
  {
    // you implement this
    return 0;
  }

  const Comparable & get_item_at_position(size_t position) const
  {
    assert(position < heap.size());
    return heap.at(position);
  }

  void change_weight(size_t position, unsigned new_weight)
  {
    // you implement this
  }

  size_t size() const
  {
    return heap.size();
  }

  std::string to_string() const
  {
    if (heap.size() == 0)
    {
      return "";
    }
    std::stringstream buffer;
    for (auto value : heap)
    {
        buffer << value.to_string() << ' ';
    }
    return buffer.str();
  }

 private:
  std::vector <Comparable> heap;

  void percolate_down(size_t position)
  {
    // you implement this
  }

  void bubble_up(size_t position)
  {
    // you implement this
  }
};

#endif
