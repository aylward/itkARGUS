/*=========================================================================
 *
 *  Copyright Kitware
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         https://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

/**
 *
 * Defines macros for defining set/get functions of inputs of shadow classes
 * that do python wrapping
 *
 *  \ingroup itkARGUS
 */

#ifndef argusWrappingMacros_h
#define argusWrappingMacros_h

/** Boolean macro */
#define argusWrapBooleanMacro( name, wrap_filter_object_name )   \
  void name##On( void ) const                            \
    {                                                    \
    this->m_##wrap_filter_object_name->name##On();       \
    }                                                    \
  void name##Off( void ) const                           \
    {                                                    \
    this->m_##wrap_filter_object_name->name##Off();      \
    }

/** Get input of fundamental type */
#define argusWrapGetMacro( name, type, wrap_filter_object_name )   \
  type Get##name( void ) const                            \
    {                                                             \
    return this->m_##wrap_filter_object_name->Get##name();        \
    }

/** Get pointer to input of object type. */
#define argusWrapGetObjectMacro( name, type, wrap_filter_object_name )    \
  type * Get##name( void )                                       \
    {                                                                    \
    return this->m_##wrap_filter_object_name->Get##name();               \
    }

/** Get a const pointer to input of object type. */
#define argusWrapGetConstObjectMacro( name, type, wrap_filter_object_name )   \
  const type * Get##name( void ) const                               \
    {                                                                        \
    return this->m_##wrap_filter_object_name->Get##name();                   \
    }

/** Get a const reference to input of object type. */
#define argusWrapGetConstReferenceMacro( name, type, wrap_filter_object_name ) \
  const type & Get##name( void ) const                                        \
    {                                                                         \
    return this->m_##wrap_filter_object_name->Get##name();                    \
    }

/** Set input of fundamental type */
#define argusWrapSetMacro( name, type, wrap_filter_object_name )   \
  void Set##name( type value )                              \
    {                                                             \
    if( this->m_##wrap_filter_object_name->Get##name() != value ) \
      {                                                           \
      this->m_##wrap_filter_object_name->Set##name( value );      \
      this->Modified();                                           \
      }                                                           \
    }

/** Set input of fundamental type */
#define argusWrapForceSetMacro( name, type, wrap_filter_object_name )   \
  void Set##name( type value )                              \
    {                                                             \
    this->m_##wrap_filter_object_name->Set##name( value );      \
    this->Modified();                                           \
    }

/** Set input using pointer to object type */
#define argusWrapSetObjectMacro( name, type, wrap_filter_object_name )   \
  void Set##name( type * value )                                \
    {                                                                   \
    if( this->m_##wrap_filter_object_name->Get##name() != value )       \
      {                                                                 \
      this->m_##wrap_filter_object_name->Set##name( value );            \
      this->Modified();                                                 \
      }                                                                 \
    }

/** Set input using pointer to object type, without testing if changed */
#define argusWrapForceSetObjectMacro( name, type, wrap_filter_object_name ) \
  void Set##name( type * value )                                           \
    {                                                                      \
    this->m_##wrap_filter_object_name->Set##name( value );                 \
    this->Modified();                                                      \
    }

/** Set input using reference to object type */
#define argusWrapSetReferenceMacro( name, type, wrap_filter_object_name )  \
  void Set##name( type & value )                                          \
    {                                                                     \
    if( this->m_##wrap_filter_object_name->Get##name() != value )         \
      {                                                                   \
      this->m_##wrap_filter_object_name->Set##name( value );              \
      this->Modified();                                                   \
      }                                                                   \
    }

/** Set input using reference to object type */
#define argusWrapForceSetReferenceMacro( name, type, wrap_filter_object_name )  \
  void Set##name( const type & value )                                        \
    {                                                                   \
    this->m_##wrap_filter_object_name->Set##name( value );              \
    this->Modified();                                                   \
    }

/** Add input using reference to object type */
#define argusWrapAddMacro( name, type, wrap_filter_object_name )  \
  void Add##name( type value )                                        \
    {                                                                   \
    this->m_##wrap_filter_object_name->Add##name( value );              \
    this->Modified();                                                   \
    }

/** Set Nth in an object list */
#define argusWrapSetNthMacro( name, type, wrap_filter_object_name )  \
  void Set##name( unsigned int i, type value )                        \
    {                                                                   \
    this->m_##wrap_filter_object_name->Set##name( i, value );           \
    this->Modified();                                                   \
    }

/** Set input using const pointer to object type */
#define argusWrapSetConstObjectMacro( name, type, wrap_filter_object_name ) \
  void Set##name( const type * value )                                     \
    {                                                                      \
    if( this->m_##wrap_filter_object_name->Get##name() != value )          \
      {                                                                    \
      this->m_##wrap_filter_object_name->Set##name( value );               \
      this->Modified();                                                    \
      }                                                                    \
    }

#define argusWrapAddConstObjectMacro( name, type, wrap_filter_object_name ) \
  void Add##name( const type * value )                                     \
    {                                                                      \
    this->m_##wrap_filter_object_name->Add##name( value );               \
    this->Modified();                                                    \
    }

/** Set Nth in an const pointer object list */
#define argusWrapSetNthObjectMacro( name, type, wrap_filter_object_name )  \
  void Set##name( unsigned int i, type * value )                        \
    {                                                                   \
    this->m_##wrap_filter_object_name->Set##name( i, value );           \
    this->Modified();                                                   \
    }

/** Set Nth in an const pointer object list */
#define argusWrapSetNthConstObjectMacro( name, type, wrap_filter_object_name )  \
  void Set##name( unsigned int i, const type * value )                        \
    {                                                                   \
    this->m_##wrap_filter_object_name->Set##name( i, value );           \
    this->Modified();                                                   \
    }

/** Get Nth in an object list */
#define argusWrapGetNthMacro( name, type, wrap_filter_object_name )  \
  type Get##name( unsigned int i )                        \
    {                                                                   \
    return this->m_##wrap_filter_object_name->Get##name( i );           \
    }

/** Get Nth in an object list */
#define argusWrapGetNthObjectMacro( name, type, wrap_filter_object_name )  \
  type * Get##name( unsigned int i )                        \
    {                                                                   \
    return this->m_##wrap_filter_object_name->Get##name( i );           \
    }

/** Get Nth in an object list */
#define argusWrapGetNthConstObjectMacro( name, type, wrap_filter_object_name )  \
  const type * Get##name( unsigned int i )                        \
    {                                                                   \
    return this->m_##wrap_filter_object_name->Get##name( i );           \
    }

/** Get Nth in an object list */
#define argusWrapGetNthConstReferenceMacro( name, type, wrap_filter_object_name )  \
  const type & Get##name( unsigned int i )                        \
    {                                                                   \
    return this->m_##wrap_filter_object_name->Get##name( i );           \
    }

/** Set input using const pointer to object type */
#define argusWrapForceSetConstObjectMacro( name, type,                    \
  wrap_filter_object_name )                                              \
  void Set##name( const type * value )                                   \
    {                                                                    \
    this->m_##wrap_filter_object_name->Set##name( value );               \
    this->Modified();                                                    \
    }

/** Set input using const reference to object type */
#define argusWrapSetConstReferenceMacro( name, type, wrap_filter_object_name ) \
  void Set##name( const type & value )                                \
    {                                                                 \
    if( this->m_##wrap_filter_object_name->Get##name() != value )     \
      {                                                               \
      this->m_##wrap_filter_object_name->Set##name( value );          \
      this->Modified();                                               \
      }                                                               \
    }

/** Set input using const reference to object type */
#define argusWrapForceSetConstReferenceMacro( name, type,              \
  wrap_filter_object_name )                                           \
  void Set##name( const type & value )                                \
    {                                                                 \
    this->m_##wrap_filter_object_name->Set##name( value );            \
    this->Modified();                                                 \
    }

/** Redirect call to a function of the same named in the wrapped filter */
#define argusWrapCallMacro( name, wrap_filter_object_name )   \
  void name()                                                \
    {                                                        \
    this->m_##wrap_filter_object_name->name();               \
    }

/** Redirect call to a function of the same named in the wrapped filter */
#define argusWrapCallWithConstReferenceArgMacro( name, type, wrap_filter_object_name )   \
  void name( const type & value )                                        \
    {                                                              \
    this->m_##wrap_filter_object_name->name( value );              \
    }

/** Redirect call to a function of the same named in the wrapped filter */
#define argusWrapCallOverrideMacro( name, wrap_filter_object_name )   \
  void name() override                                       \
    {                                                        \
    this->m_##wrap_filter_object_name->name();               \
    }

/** Redirect call to Update() wrapped filter's Update() */
#define argusWrapUpdateMacro( wrap_filter_object_name )                   \
  argusWrapCallOverrideMacro( Update, wrap_filter_object_name )                   \

#endif
