//
// Created by Michał Łaszczewski on 27/07/16.
//

#ifndef FASTANIM_RENDERLIST_H
#define FASTANIM_RENDERLIST_H

#include <vector>
#include <memory>
#include <functional>
#include <boost/iterator/filter_iterator.hpp>

namespace fanim {

  template<typename ElementType> class FastSet {
  public:
    std::vector<std::shared_ptr<ElementType>> buffer;

    FastSet() {}
    ~FastSet() {}

    int search;

    int add(std::shared_ptr<ElementType> element) {
      fgfx_log("BUFFER SIZE %d",(int)(buffer.size()));
      int len = buffer.size();
      if(len) {
        for (int i = search + 1; i != search; i = (i + 1) % len) {
          if (!buffer[i]) { // Found empty
            buffer[i] = element;
            search = i;
            return i;
          }
        }
      }
      search = len;
      buffer.resize(search+1024);
      buffer[search]=element;
      return search;
    }
    void remove(int id) {
      buffer[id] = nullptr;
    }
    void remove(std::shared_ptr<ElementType> element) {
      for(int i = 0; i < buffer.size(); i++) {
        if(buffer[i] == element) {
          buffer[i] = nullptr;
          return;
        }
      }
    }

    struct is_element {
      bool operator()(std::shared_ptr<ElementType> x) { return !!x; }
    };

    auto begin() {
      return boost::make_filter_iterator<is_element>(buffer.begin(), buffer.end());
    }
    auto end() {
      return boost::make_filter_iterator<is_element>(buffer.end(), buffer.end());
    }

    std::shared_ptr<ElementType>& operator[](unsigned int id) {
      return buffer[id];
    }
    const std::shared_ptr<ElementType>& operator[](unsigned int id) const {
      return buffer[id];
    }

    unsigned int size() {
      return buffer.size();
    }
  };

}

#endif //FASTANIM_RENDERLIST_H
