/*****************************************************************************/
/**
 * @file    hcTree.h
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
#include "hcNode.h"

namespace hcEngineSDK
{
  template<typename _Type>
  class Tree
  {
  public:

    Tree();

    ~Tree();

    void
    insert(_Type);

    Node<_Type>*
    search(_Type);

  private:

    Node<_Type> * m_p_root;

  };

  template<typename _Type>
  inline Tree<_Type>::Tree()
  {
  }

  template<typename _Type>
  inline Tree<_Type>::~Tree()
  {
    if (m_p_root)
    {
      delete this->m_p_root;
    }
    return;
  }

  template<typename _Type>
  inline void 
  Tree<_Type>::insert(_Type _obj)
  {
    Node<_Type> * p_node = new Node<_Type>(_obj);
    
    if (!m_p_root)
    {
      this->m_p_root = p_node;
      return;
    }

    m_p_root->insert(p_node);
    return;
  }

  template<typename _Type>
  inline Node<_Type>* 
  Tree<_Type>::search(_Type _obj)
  {
    Node<_Type> * p_node = new Node<_Type>(_obj);

    if (!m_p_root)
    {
      this->m_p_root = p_node;
      return;
    }

    return m_p_root->search(p_node);
    return;
  }
}
