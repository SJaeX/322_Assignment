/**
 * label_weight_pair.h
 * @author Jon Beck
 * @version 5 march 2019
 */

#ifndef LABEL_WEIGHT_PAIR
#define LABEL_WEIGHT_PAIR

#include <climits>
#include <sstream>
#include <utility>

/**
 * A class to provide a pair consisting of an integer label and an
 * integer weight, both non-negative.
 */
class LabelWeightPair
{
 public:
  /**
   * constructor
   * @param label the identifying key of the pair
   * @param weight the weight by which the pair is sorted
   */
  LabelWeightPair(size_t label, unsigned weight)
  {
    data = std::make_pair(label, weight);
  }

  /**
   * getter for the identifying key
   * @return the key
   */
  size_t get_label() const
  {
    return data.first;
  }

  /**
   * getter for the weight of the pair
   * @return the weight
   */
  unsigned get_weight() const
  {
    return data.second;
  }

  /**
   * setter for the weight field
   * @param new_weight the new weight to be stored
   */
  void set_weight(unsigned new_weight)
  {
    data.second = new_weight;
  }

  /**
   * the method that allows two pairs to be compared by their weights,
   * with ties broken by the labels
   */
  bool operator<(const LabelWeightPair & rhs) const
  {
    if (data.second == rhs.get_weight())
    {
      return data.first < rhs.get_label();
    }
    return data.second < rhs.get_weight();
  }

  /**
   * get a string representation of the item
   * @return a string representation
   */
  std::string to_string() const
  {
    std::string result {std::to_string(data.first) + ':'};
    if (data.second == UINT_MAX)
    {
      return result + "inf";
    }
    return result + std::to_string(data.second);
  }

 private:
  std::pair<size_t, unsigned> data;
};

#endif
