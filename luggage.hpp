#ifndef LUGGAGE_HPP
#define LUGGAGE_HPP

#include <stdexcept>

// Abstract Luggage class
class Luggage {
  public:
    // Get/Calculate the volume of the specific luggage
    virtual unsigned int getVolume() const = 0;
};


// Examples of concrete luggages
class Trunk: public Luggage {
  public:
    /**
     * Trunk is a reactangle box with a fixed volume
     * 
     * @pre sizes can't be less than 1
     */
    Trunk(unsigned int length, unsigned int width, unsigned int height) {
      if (length < 1 || width < 1 || height < 1) {
        throw std::invalid_argument("ERR: sizes can't be less than 1");
      }
      size.length = length;
      size.width = width;
      size.height = height;
    };
    unsigned int getVolume() const {
      return size.height * size.width * size.length;
    };

  private:
    struct {
      unsigned int length;
      unsigned int width;
      unsigned int height;
    } size;
};
class Backpack: public Luggage {
  public:
    /**
     * Backpack is a flexible luggage with a volume which evolves regarding the filled level
     * 
     * @pre minVolume can't be less than 1
     * @param minVolume volume when the backpack is empty
     * @param maxVolume volume when the backpack is full
     * @param defaultLevel initial filling level of the backpack, default 50%
     */
    Backpack(unsigned int minVolume, unsigned int maxVolume, unsigned int defaultLevel = 50) {
      if (minVolume < 1) {
        throw std::out_of_range("ERR: Backpack min volume can't be less than 0");
      } else if (maxVolume < minVolume) {
        throw std::invalid_argument("ERR: Backpack max volume can't be less than min volume");
      }
      setLevel(defaultLevel);
      this->maxVolume = maxVolume;
      this->minVolume = minVolume;
    };
    unsigned int getVolume() const {
      return (level/100.0)*(maxVolume - minVolume) + minVolume;
    };

    // Level representing how filled is the bag
    void setLevel(unsigned int newLevel){
      if (newLevel > 100 || newLevel < 0) {
        throw std::out_of_range("ERR: Backpack level incorrect: 0 <= level <= 100");
      }
      level = newLevel;
    };
    unsigned int getLevel() const {
      return level;
    };

  private:
    unsigned int maxVolume;
    unsigned int minVolume;
    // Filled level in percents (0-100)
    unsigned int level;
};

#endif