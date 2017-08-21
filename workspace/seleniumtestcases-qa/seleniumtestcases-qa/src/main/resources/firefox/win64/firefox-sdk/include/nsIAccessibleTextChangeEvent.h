/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessibleTextChangeEvent.idl
 */

#ifndef __gen_nsIAccessibleTextChangeEvent_h__
#define __gen_nsIAccessibleTextChangeEvent_h__


#ifndef __gen_nsIAccessibleEvent_h__
#include "nsIAccessibleEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleTextChangeEvent */
#define NS_IACCESSIBLETEXTCHANGEEVENT_IID_STR "1fcc0dfa-93e6-48f4-bbd4-f80eb1d9f2e6"

#define NS_IACCESSIBLETEXTCHANGEEVENT_IID \
  {0x1fcc0dfa, 0x93e6, 0x48f4, \
    { 0xbb, 0xd4, 0xf8, 0x0e, 0xb1, 0xd9, 0xf2, 0xe6 }}

class NS_NO_VTABLE nsIAccessibleTextChangeEvent : public nsIAccessibleEvent {
 public:

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLETEXTCHANGEEVENT_IID)

  /* readonly attribute long start; */
  NS_IMETHOD GetStart(int32_t *aStart) = 0;

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* readonly attribute boolean isInserted; */
  NS_IMETHOD GetIsInserted(bool *aIsInserted) = 0;

  /* readonly attribute DOMString modifiedText; */
  NS_IMETHOD GetModifiedText(nsAString & aModifiedText) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleTextChangeEvent, NS_IACCESSIBLETEXTCHANGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLETEXTCHANGEEVENT \
  NS_IMETHOD GetStart(int32_t *aStart) override; \
  NS_IMETHOD GetLength(uint32_t *aLength) override; \
  NS_IMETHOD GetIsInserted(bool *aIsInserted) override; \
  NS_IMETHOD GetModifiedText(nsAString & aModifiedText) override; 

/* Use this macro when declaring the members of this interface when the
   class doesn't implement the interface. This is useful for forwarding. */
#define NS_DECL_NON_VIRTUAL_NSIACCESSIBLETEXTCHANGEEVENT \
  NS_METHOD GetStart(int32_t *aStart); \
  NS_METHOD GetLength(uint32_t *aLength); \
  NS_METHOD GetIsInserted(bool *aIsInserted); \
  NS_METHOD GetModifiedText(nsAString & aModifiedText); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLETEXTCHANGEEVENT(_to) \
  NS_IMETHOD GetStart(int32_t *aStart) override { return _to GetStart(aStart); } \
  NS_IMETHOD GetLength(uint32_t *aLength) override { return _to GetLength(aLength); } \
  NS_IMETHOD GetIsInserted(bool *aIsInserted) override { return _to GetIsInserted(aIsInserted); } \
  NS_IMETHOD GetModifiedText(nsAString & aModifiedText) override { return _to GetModifiedText(aModifiedText); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLETEXTCHANGEEVENT(_to) \
  NS_IMETHOD GetStart(int32_t *aStart) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStart(aStart); } \
  NS_IMETHOD GetLength(uint32_t *aLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD GetIsInserted(bool *aIsInserted) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInserted(aIsInserted); } \
  NS_IMETHOD GetModifiedText(nsAString & aModifiedText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetModifiedText(aModifiedText); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleTextChangeEvent : public nsIAccessibleTextChangeEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLETEXTCHANGEEVENT

  nsAccessibleTextChangeEvent();

private:
  ~nsAccessibleTextChangeEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAccessibleTextChangeEvent, nsIAccessibleTextChangeEvent)

nsAccessibleTextChangeEvent::nsAccessibleTextChangeEvent()
{
  /* member initializers and constructor code */
}

nsAccessibleTextChangeEvent::~nsAccessibleTextChangeEvent()
{
  /* destructor code */
}

/* readonly attribute long start; */
NS_IMETHODIMP nsAccessibleTextChangeEvent::GetStart(int32_t *aStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsAccessibleTextChangeEvent::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isInserted; */
NS_IMETHODIMP nsAccessibleTextChangeEvent::GetIsInserted(bool *aIsInserted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString modifiedText; */
NS_IMETHODIMP nsAccessibleTextChangeEvent::GetModifiedText(nsAString & aModifiedText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleTextChangeEvent_h__ */
