#pragma once

class Object
{
public:
  Object();

  virtual ~Object();

  virtual void
  init();

  virtual unsigned int
  getBucketID();

  bool
  operator < (const Object &);

  bool
  operator <= (const Object &);

  bool
  operator > (const Object &);

  bool
  operator >= (const Object &);

protected:

  unsigned int m_bucket_id;
};
