/*****************************************************************************/
/**
 * @file    hcBucketSort.h
 * @authors	Max Maldonado (nuup20@gmail.com)
 * @date    junio 2019
 * @brief
 *
 * @bug     No known bugs.
 */
 /*****************************************************************************/
#pragma once

/************************************************************************/
/* Includes                                                             */
/************************************************************************/
#include "hcUtilitiesPrerequisites.h"
#include "hcConversion.h"
#include "hcUID.h"
#include "hcFile.h"

#include "hcPlatformMath.h"
#define Math PlatformBaseMath

namespace hcEngineSDK
{
  template<typename _TYPE>
  class HastTable_Uni
  {
  public:

    /**
     * Create a Bucket Sort Object with 19 buckets.
     */
    HastTable_Uni()
    {
      this->m_buckets.resize(67);

      this->m_a = std::rand() % 71;

      this->m_b = std::rand() % 71;

      this->m_p = 97;

      return;
    }

    /**
     * Create a Bucket Sort Object with N buckets.
     *
     * @param Number of buckets. ( Be sure to enter a prime number ).
     *
     */
    HastTable_Uni(const uint32 & _num_buckets)
    {
      this->m_buckets.resize(_num_buckets);
      return;
    }

    /**
     * Object's destructor
     */
    ~HastTable_Uni()
    {}

    /**
     * Adds a new object to this Bucket Sort.
     */
    void
    insert(_TYPE * _p_element, const uint32 & _id)
    {
      uint32 bucket_id = this->hash(_id);

      this->m_buckets[bucket_id].push_back(_p_element);

      return;
    }

    /**
     * Get an object by its UID.
     *
     * @param UID of the desired object.
     *
     * @return Object
     */
    _TYPE *
      get(const uint32 & _id)
    {
      // get the bucket id by his id.

      uint32 bucket_id = this->hash(_id);

      // search object

      for (_TYPE * element : this->m_buckets[bucket_id])
      {
        if (element.getNumber() == _id)
        {
          return element;
        }
      }

      return nullptr;
    }

    /**
     * Get an object by its UID.
     *
     * @param UID of the desired object.
     *
     * @return Object
     */
    _TYPE *
      get(const UID & _uid)
    {
      // get the bucket id by his id.

      uint32 bucket_id = this->hash(_uid.getNumber());

      // search object

      for (_TYPE * element : this->m_buckets[bucket_id])
      {
        if (element->getNumber() == _uid)
        {
          return element;
        }
      }

      return nullptr;
    }

    /**
      * Gets an object by his name.
      *
      * @param Object's name.
      *
      * @return Object.
      */
    _TYPE *
      get(const String & _name)
    {
      return nullptr;
    }
    
    String
    getInfo()
    {
      String csv = "";
      
      uint32 slots_size = this->m_buckets.size();
      for (uint32 index = 0; index < slots_size; ++index)
      {
        csv += CONVERT::IntToString(index);
        csv += ",";
        csv += CONVERT::IntToString(this->m_buckets[index].size());
        csv += "\n";
      }

      return csv;
    }

  private:

    uint32
    hash(uint32 _id)
    {      
      uint32 bucket_id = (this->m_a * _id) + this->m_b;

      bucket_id = bucket_id % this->m_p;
      bucket_id = bucket_id % this->m_buckets.size();

      return bucket_id;
    }

    /**
     * List of Buckets
     */
    Vector<Vector<_TYPE*>> m_buckets;

    float m_a;

    float m_b;

    uint32 m_p;

  };
}
