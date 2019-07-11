/*****************************************************************************/
/**
 * @file    hcNode.h
 * @authors	Max Maldonado (nuup20@gmail.com)
 * @date    julio 2019
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

namespace hcEngineSDK
{
  template<typename _Type>
  class Node
  {
    public:
      Node();

      Node(_Type);

      /**
       * Node
       *
       * @param Node * pointer to parent.
       * @param Node * pointer to left.
       * @param Node * pointer to right.
       */
      Node
      (
        _Type,
        Node<_Type> *,
        Node<_Type> *,
        Node<_Type> *
      );

      Node(const Node &);

      ~Node();

      bool
      operator==(const Node &) const;

      bool
      operator!=(const Node &) const;

      bool
      operator<(const Node &) const;

      bool
      operator<=(const Node &) const;

      bool
      operator>(const Node &) const;

      bool
      operator>=(const Node &) const;

      void
      insert(Node<_Type> *);

      Node<_Type> *
      search(_Type);

  private:

    _Type  m_obj;

    Node<_Type> * m_p_right;

    Node<_Type> * m_p_left;

    Node<_Type> * m_p_parent;

    friend class Tree;
  };

  template<typename _Type>
  inline Node<_Type>::Node()
    : m_obj(nullptr),
      m_p_parent(nullptr),
      m_p_left(nullptr),
      m_p_right(nullptr)     
  {}

  template<typename _Type>
  inline Node<_Type>::Node(_Type _obj)
  {
    this->m_obj = _obj;
  }

  template<typename _Type>
  inline Node<_Type>::Node
  (
    _Type         _obj, 
    Node<_Type>*  _p_parent, 
    Node<_Type>*  _p_left, 
    Node<_Type>*  _p_right
  )
  {
    this->m_obj = _obj;
    this->m_p_parent = _p_parent;
    this->m_p_left = _p_left;
    this->m_p_right = _p_right;

    return;
  }

  template<typename _Type>
  inline Node<_Type>::Node(const Node & _node)
    : m_obj(_node.m_obj)
  { 
    if (this->m_p_left != nullptr)
    {
      delete this->m_p_left;
    }

    if (this->m_p_right != nullptr)
    {
      delete this->m_p_right;
    }

    return;
  }

  template<typename _Type>
  inline Node<_Type>::~Node()
  { }

  template<typename _Type>
  inline bool 
  Node<_Type>::operator==(const Node & _node) const
  {
    return this->m_obj == _node.m_obj;
  }

  template<typename _Type>
  inline bool 
  Node<_Type>::operator!=(const Node & _node) const
  {
    return this->m_obj != _node.m_obj;
  }

  template<typename _Type>
  inline bool 
  Node<_Type>::operator<(const Node & _node) const
  {
    return this->m_obj < _node.m_obj;
  }

  template<typename _Type>
  inline bool 
  Node<_Type>::operator<=(const Node & _node) const
  {
    return this->m_obj <= _node.m_obj;
  }

  template<typename _Type>
  inline bool 
  Node<_Type>::operator>(const Node & _node) const
  {
    return this->m_obj > _node.m_obj;
  }

  template<typename _Type>
  inline bool 
  Node<_Type>::operator>=(const Node & _node) const
  {
    return this->m_obj >= _node;
  }

  template<typename _Type>
  inline void 
  Node<_Type>::insert(Node<_Type> * _p_node)
  {
    if (*this >= *_p_node)
    {
      if (!this->m_p_left)
      {
        _p_node->m_p_parent = this;
        this->m_p_left = _p_node;
      }
      else
      {
        this->m_p_left->insert(_p_node);
      }
    }
    else
    {
      if (!this->m_p_right)
      {
        _p_node->m_p_parent = this;
        this->m_p_right = _p_node;
      }
      else
      {
        this->m_p_right->insert(_p_node);
      }
    }

    return;
  }

  template<typename _Type>
  inline Node<_Type>* 
  Node<_Type>::search(_Type _obj)
  {
    if (this->m_obj == _obj)
    {
      return this;
    }

    if (this->m_obj >= _obj)
    {
      if (!this->m_p_left)
      {
        return nullptr;
      }
      else
      {
        return this->m_p_left->search(_obj);
      }
    }
    else
    {
      if (!this->m_p_right)
      {
        return nullptr;
      }
      else
      {
        return this->m_p_right->search(_obj);
      }
    }
  }
}
