#pragma once

class Object;

class Bucket
{
public:

  Bucket();

  virtual ~Bucket();

  virtual void
  add(Object *);

  virtual Object *
  get(const unsigned int _id);

protected:
};