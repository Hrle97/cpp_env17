#ifndef FWA_CORE_CLEANUP_OPS_HPP
#undef FWA_CORE_CLEANUP_OPS_HPP


#if FWA_UNDEF_OPS


// getters

// member getters

#undef MEM_NAME
#undef MEM_TYPE

#undef _GETTER_NAME
#undef GETTER_NAME

#undef GET_MEM


// const and mutable

#undef GETTER_BODY_IMPL

#undef GETTER_BODY

#undef GETTER_FML

#undef GETTER

#undef _MEM_GETTER_TMP

#undef _MEM_GETTER

#undef MEM_GETTER_TMP

#undef MEM_GETTER


// const or mutable

#undef SINGLE_GETTER_BODY_IMPL

// cmp

#undef CMP_GETTER_BODY

#undef CMP_GETTER_FML

#undef CMP_GETTER

#undef MEM_CMP_GETTER

#undef MEM_CMP_REF_GETTER

// runtime

// const

#undef CONST_GETTER_BODY

#undef CONST_GETTER_FML

#undef CONST_GETTER

#undef MEM_VAL_GETTER

#undef MEM_CONST_GETTER

// mutable

#undef MUT_GETTER_BODY

#undef MUT_GETTER_FML

#undef MUT_GETTER

#undef MEM_MUT_GETTER_TMP

#undef MEM_MUT_GETTER


// members

#undef DEF_MEM_TYPE
#undef DEF_DEDUCED_MEM_TYPE

#undef DECL_MEM
#undef DEF_MEM
#undef DEF_DEDUCED_MEM
#undef DEF_NIL_MEM

#undef DECL

#undef DEF

#undef MEM

#undef NIL

#undef _DECL

#undef _DEF

#undef _MEM

#undef _NIL


// singleton getters

#undef PROTECTED_SINGLETON_NAME
#undef PUBLIC_SINGLETON_NAME

#undef GET_SINGLETON


#undef DECL_SINGLETON_GETTER

#undef _SINGLETON_GETTER

#undef SINGLETON_GETTER

#undef CONST_SINGLETON_GETTER

#undef THREADED_MUT_SINGLETON_GETTER

#undef THREADED_CONST_SINGLETON_GETTER


// lifetime

// names


// modular definitions

#undef DEF_DEFAULT_CONSTRUCT_AUTO
#undef DEF_DEFAULT_CONSTRUCT_MANUAL

#undef DEF_COPY_AUTO
#undef DEF_COPY_MANUAL
#undef DEF_MOVE_AUTO
#undef DEF_MOVE_MANUAL

#undef DEF_OPERATOR_COPY_MOVE
#undef DEF_OPERATOR_MOVE

#undef DEF_DESTRUCT


// modular lifetime

#undef DELETE_METHOD
#undef DEFAULT_METHOD

#undef WRAP_LIFETIME_ATTRIBUTE


#undef DECL_DEFAULT_CONSTRUCTOR

#undef DECL_DELETED_DEFAULT_CONSTRUCTOR

#undef DECL_NO_ATTRIBUTE_DEFAULT_CONSTRUCTOR

#undef DECL_NOEX_DEFAULT_CONSTRUCTOR

#undef DECL_CMP_DEFAULT_CONSTRUCTOR

#undef DECL_SUPER_DEFAULT_CONSTRUCTOR

#undef DECL_SUB_DEFAULT_CONSTRUCTOR

#undef DEF_DEFAULT_DEFAULT_CONSTRUCTOR

#undef DEF_AUTO_DEFAULT_CONSTRUCTOR

#undef DEF_MANUAL_DEFAULT_CONSTRUCTOR


#undef DECL_COPY_MOVE_CONSTRUCTORS

#undef DECL_DELETED_COPY_MOVE_CONSTRUCTORS

#undef DECL_NO_ATTRIBUTE_COPY_MOVE_CONSTRUCTORS

#undef DECL_NOEX_COPY_MOVE_CONSTRUCTORS

#undef DECL_CMP_COPY_MOVE_CONSTRUCTORS

#undef DECL_SUPER_COPY_MOVE_CONSTRUCTORS

#undef DECL_SUB_COPY_MOVE_CONSTRUCTORS

#undef DEF_DEFAULT_COPY_MOVE_CONSTRUCTORS

#undef DEF_AUTO_COPY_MOVE_CONSTRUCTORS

#undef DEF_MANUAL_COPY_MOVE_CONSTRUCTORS


#undef DECL_ASSIGNMENT_OPERATORS

#undef DECL_DELETED_ASSIGNMENT_OPERATORS

#undef DECL_NO_ATTRIBUTE_ASSIGNMENT_OPERATORS

#undef DECL_NOEX_ASSIGNMENT_OPERATORS

#undef DECL_CMP_ASSIGNMENT_OPERATORS

#undef DECL_SUPER_ASSIGNMENT_OPERATORS

#undef DECL_SUB_ASSIGNMENT_OPERATORS

#undef DEF_DEFAULT_ASSIGNMENT_OPERATORS

#undef DEF_AUTO_ASSIGNMENT_OPERATORS

#undef DEF_MANUAL_ASSIGNMENT_OPERATORS


#undef DECL_DESTRUCTOR

#undef DECL_DELETED_DESTRUCTOR

#undef DECL_NO_ATTRIBUTE_DESTRUCTOR

#undef DECL_NOEX_DESTRUCTOR

#undef DECL_CMP_DESTRUCTOR

#undef DECL_SUPER_DESTRUCTOR

#undef DECL_SUB_DESTRUCTOR

#undef DEF_DEFAULT_DESTRUCTOR

#undef DEF_AUTO_DESTRUCTOR

#undef DEF_MANUAL_DESTRUCTOR


// manual methods

#undef DECL_LIFETIME_FUN

#undef DECL_CONSTRUCT

#undef DECL_COPY
#undef DECL_MOVE
#undef DEF_MOVE
#undef DECL_COPY_MOVE

#undef DECL_DESTRUCT


// lifetime

// default

#undef ELABORATE_DEFAULT_LIFE

#undef ELABORATE_DEFAULT_NOCON_LIFE

#undef DEFAULT_LIFE

#undef DEFAULT_NOCON_LIFE

// auto

#undef ELABORATE_AUTO_LIFE

#undef ELABORATE_AUTO_NOCON_LIFE

#undef AUTO_LIFE

#undef AUTO_NOCON_LIFE

// manual

#undef ELABORATE_MANUAL_LIFE

#undef ELABORATE_MANUAL_NOCON_LIFE

#undef MANUAL_LIFE

#undef MANUAL_NOCON_LIFE

#undef SIMPLE_MANUAL_LIFE

#undef SIMPLE_MANUAL_NOCON_LIFE

// const lifetime

// default

#undef ELABORATE_DEFAULT_CONST_LIFE

#undef DEFAULT_CONST_LIFE

// auto

#undef ELABORATE_AUTO_LIFE

#undef ELABORATE_AUTO_NOCON_LIFE

#undef AUTO_LIFE

#undef AUTO_NOCON_LIFE

// manual

#undef ELABORATE_MANUAL_LIFE

#undef ELABORATE_MANUAL_NOCON_LIFE

#undef MANUAL_LIFE

#undef MANUAL_NOCON_LIFE

#undef SIMPLE_MANUAL_LIFE

#undef SIMPLE_MANUAL_NOCON_LIFE

// const lifetime

// default

#undef ELABORATE_DEFAULT_CONST_LIFE

#undef DEFAULT_CONST_LIFE

// auto

#undef ELABORATE_AUTO_CONST_LIFE

#undef AUTO_CONST_LIFE

// manual

#undef ELABORATE_MANUAL_CONST_LIFE

#undef MANUAL_CONST_LIFE

#undef SIMPLE_MANUAL_CONST_LIFE

// singleton lifetime

// default

#undef ELABORATE_DEFAULT_SINGLE_LIFE

#undef DEFAULT_SINGLE_LIFE

// auto

#undef ELABORATE_AUTO_SINGLE_LIFE

#undef AUTO_SINGLE_LIFE

// manual

#undef ELABORATE_MANUAL_SINGLE_LIFE

#undef MANUAL_SINGLE_LIFE

#undef SIMPLE_MANUAL_SINGLE_LIFE


// comparison

// names and getter calls

#undef IS_VALID_NAME
#undef CHECK_IS_VALID

#undef HASH_NAME
#undef GET_HASH

#undef EQUALS_NAME
#undef CHECK_EQUALS
#undef CHECK_TEMPLATE_EQUALS

#undef HASH_EQ_NAME
#undef CHECK_HASH_EQ
#undef CHECK_TEMPLATE_HASH_EQ

#undef LESS_NAME
#undef CHECK_LESS
#undef CHECK_TEMPLATE_LESS


// non tmp modular

// validity

#undef DEFINE_NULLPTR_EQ_OPERATOR

#undef DEFINE_NULLPTR_NE_OPERATOR

#undef DEFINE_IS_INVALID

#undef DEFINE_BOOL_OPERATOR

#undef DEFINE_STATIC_IS_VALID

#undef DECLARE_IS_VALID_FUNCTION


// hash

#undef DEFINE_CALCULATE_HASH

#undef DEFINE_HASH_OPERATOR

#undef DEFINE_STATIC_HASH

#undef DECLARE_HASH_FUNCTION


// possibly tmp modular

#undef DECLARE_BINARY_CHECK

#undef DECLARE_STATIC_BINARY_CHECK


#undef DECLARE_NO_TEMPLATE_BINARY_CHECK

#undef DECLARE_TEMPLATE_BINARY_CHECK

#undef DECLARE_STATIC_TEMPLATE_BINARY_CHECK


#undef HASH_EQ_TEMPLATE_CONDITION

#undef STATIC_HASH_EQ_TEMPLATE_CONDITION

#undef EQUALITY_TEMPLATE_CONDITION

#undef STATIC_EQUALITY_TEMPLATE_CONDITION

#undef COMPARISON_TEMPLATE_CONDITION

#undef STATIC_COMPARISON_TEMPLATE_CONDITION


#undef DECLARE_HASH_EQ_TEMPLATE_BINARY_CHECK

#undef DECLARE_HASH_EQ_STATIC_TEMPLATE_BINARY_CHECK

#undef DECLARE_EQUALITY_TEMPLATE_BINARY_CHECK

#undef DECLARE_EQUALITY_STATIC_TEMPLATE_BINARY_CHECK

#undef DECLARE_COMPARISON_TEMPLATE_BINARY_CHECK

#undef DECLARE_COMPARISON_STATIC_TEMPLATE_BINARY_CHECK


// hash

#undef DEFINE_HASH_EQ

#undef DEFINE_HASH_IS_EQUAL_TO

#undef DEFINE_HASH_IS_NOT_EQUAL_TO

#undef DEFINE_STATIC_HASH_EQ


#undef DEFINE_TEMPLATE_HASH_EQ

#undef DEFINE_TEMPLATE_HASH_IS_EQUAL_TO

#undef DEFINE_TEMPLATE_HASH_IS_NOT_EQUAL_TO

#undef DEFINE_STATIC_TEMPLATE_HASH_EQ


// equality

#undef DEFINE_EQ_OPERATOR

#undef DEFINE_NE_OPERATOR

#undef DEFINE_IS_EQUAL_TO

#undef DEFINE_IS_NOT_EQUAL_TO

#undef DEFINE_STATIC_EQUALS

#undef DECLARE_EQUALS_FUNCTION


#undef DEFINE_TEMPLATE_EQ_OPERATOR

#undef DEFINE_TEMPLATE_NE_OPERATOR

#undef DEFINE_TEMPLATE_IS_EQUAL_TO

#undef DEFINE_TEMPLATE_IS_NOT_EQUAL_TO

#undef DEFINE_TEMPLATE_STATIC_EQUALS

#undef DECLARE_TEMPLATE_EQUALS_FUNCTION


// comparison

#undef DEFINE_LESS_OPERATOR

#undef DEFINE_IS_LESS_THAN

#undef DEFINE_GREATER_OPERATOR

#undef DEFINE_IS_GREATER_THAN

#undef DEFINE_LESS_OR_EQUAL_OPERATOR

#undef DEFINE_IS_LESS_THAN_OR_EQUAL_TO

#undef DEFINE_GREATER_OR_EQUAL_OPERATOR

#undef DEFINE_IS_GREATER_THAN_OR_EQUAL_TO

#undef DEFINE_STATIC_LESS

#undef DECLARE_LESS_FUNCTION


#undef DEFINE_TEMPLATE_LESS_OPERATOR

#undef DEFINE_TEMPLATE_IS_LESS_THAN

#undef DEFINE_TEMPLATE_GREATER_OPERATOR

#undef DEFINE_TEMPLATE_IS_GREATER_THAN

#undef DEFINE_TEMPLATE_LESS_OR_EQUAL_OPERATOR

#undef DEFINE_TEMPLATE_IS_LESS_THAN_OR_EQUAL_TO

#undef DEFINE_TEMPLATE_GREATER_OR_EQUAL_OPERATOR

#undef DEFINE_TEMPLATE_IS_GREATER_THAN_OR_EQUAL_TO

#undef DEFINE_TEMPLATE_STATIC_LESS

#undef DECLARE_TEMPLATE_LESS_FUNCTION


// non tmp compound

// validity

#undef ELABORATE_VALIDITY_ON

#undef ELABORATE_VALIDITY

#undef CMP_VALIDITY_ON
#undef NOEX_VALIDITY_ON
#undef SUPER_VALIDITY_ON
#undef SUB_VALIDITY_ON

#undef CMP_VALIDITY
#undef NOEX_VALIDITY
#undef SUPER_VALIDITY
#undef SUB_VALIDITY


// hash

#undef ELABORATE_HASH_ON

#undef ELABORATE_HASH

#undef CMP_HASH_ON
#undef NOEX_HASH_ON
#undef SUPER_HASH_ON
#undef SUB_HASH_ON

#undef CMP_HASH
#undef NOEX_HASH
#undef SUPER_HASH
#undef SUB_HASH


// possibly tmp compound

// hash

#undef ELABORATE_TMP_HASH_ON

#undef ELABORATE_TMP_HASH

#undef CMP_TMP_HASH_ON
#undef NOEX_TMP_HASH_ON
#undef SUPER_TMP_HASH_ON
#undef SUB_TMP_HASH_ON

#undef CMP_TMP_HASH
#undef NOEX_TMP_HASH
#undef SUPER_TMP_HASH
#undef SUB_TMP_HASH


// equality

#undef ELABORATE_EQUALITY_ON

#undef ELABORATE_EQUALITY

#undef CMP_EQUALITY_ON
#undef NOEX_EQUALITY_ON
#undef SUPER_EQUALITY_ON
#undef SUB_EQUALITY_ON

#undef CMP_EQUALITY
#undef NOEX_EQUALITY
#undef SUPER_EQUALITY
#undef SUB_EQUALITY


#undef ELABORATE_TMP_EQUALITY_ON

#undef ELABORATE_TMP_EQUALITY

#undef CMP_TMP_EQUALITY_ON
#undef NOEX_TMP_EQUALITY_ON
#undef SUPER_TMP_EQUALITY_ON
#undef SUB_TMP_EQUALITY_ON

#undef CMP_TMP_EQUALITY
#undef NOEX_TMP_EQUALITY
#undef SUPER_TMP_EQUALITY
#undef SUB_TMP_EQUALITY


// comparison

#undef ELABORATE_COMPARISON_ON

#undef ELABORATE_COMPARISON

#undef CMP_COMPARISON_ON
#undef NOEX_COMPARISON_ON
#undef SUPER_COMPARISON_ON
#undef SUB_COMPARISON_ON

#undef CMP_COMPARISON
#undef NOEX_COMPARISON
#undef SUPER_COMPARISON
#undef SUB_COMPARISON


#undef ELABORATE_TMP_COMPARISON_ON

#undef ELABORATE_TMP_COMPARISON

#undef CMP_TMP_COMPARISON_ON
#undef NOEX_TMP_COMPARISON_ON
#undef SUPER_TMP_COMPARISON_ON
#undef SUB_TMP_COMPARISON_ON

#undef CMP_TMP_COMPARISON
#undef NOEX_TMP_COMPARISON
#undef SUPER_TMP_COMPARISON
#undef SUB_TMP_COMPARISON


// compatibility

#undef ENABLE_IF_HASH_EQ_COMPAT
#undef ENABLE_IF_EQUALITY_COMPAT
#undef ENABLE_IF_COMPARISON_COMPAT

#undef ELABORATE_ENABLE_IF_COMPAT

#undef ENABLE_IF_COMPAT


#undef SFINAE_HASH_EQ_COMPAT
#undef SFINAE_EQUALITY_COMPAT
#undef SFINAE_COMPARISON_COMPAT

#undef ELABORATE_SFINAE_COMPAT

#undef SFINAE_COMPAT



// exception

// debug

#undef DEBUG_FLAG

// args

#undef EXCEPTION_POLICY_TYPE_NAME

#undef EXCEPTION_POLICY_TEMPLATE_ARGUMENT

#undef UNIGNORABLE_POLICY_TEMPLATE_ARGUMENT


#undef EXCEPTION_POLICY_ARGUMENT_NAME

#undef EXCEPTION_POLICY_RUNTIME_ARGUMENT

#undef UNIGNORABLE_POLICY_RUNTIME_ARGUMENT

// shorthands

#undef exc_name
#undef exc_arg
#undef unignore


// noex

#undef IS_NO_THROW_EXCEPTION_POLICY
#undef NOEX_IF_NO_THROW_EXCEPTION_POLICY

// shorthand

#undef is_noex_pol
#undef noex_pol


// when

#undef SHOULD_IGNORE_EXCEPTION
#undef SHOULD_EXIT_ON_EXCEPTION
#undef SHOULD_THROW_ON_EXCEPTION
#undef SHOULD_CHECK_EXCEPTIONS
#undef SHOULD_ADJUST_ON_EXCEPTION

// state

#undef WHEN_STATE_ELABORATE

#undef WHEN_STATE_SIMPLE

#undef WHEN_STATE

// arg

#undef WHEN_ARG_ELABORATE

#undef WHEN_ARG_SIMPLE

#undef WHEN_ARG

// id operations

#undef MAKE_ID

#undef DEFAULT_GET_ID_BODY
#undef DEFAULT_ID_HASH_BODY
#undef DEFAULT_ID_EQUALS_BODY

// no cmp because of reinterpret_cast...

#undef DEF_ELABORATE_ID_OPT

#undef DEF_ELABORATE_ID
#undef DEF_ELABORATE_TMP_ID

#undef DEF_ID_WITH_OPT
#undef DEF_ID_WITH
#undef DEF_TMP_ID_WITH

#undef DEF_ID_OPT
#undef DEF_ID
#undef DEF_TMP_ID


#endif // FWA_UNDEF_OPS


#endif // FWA_CORE_CLEANUP_OPS_HPP
