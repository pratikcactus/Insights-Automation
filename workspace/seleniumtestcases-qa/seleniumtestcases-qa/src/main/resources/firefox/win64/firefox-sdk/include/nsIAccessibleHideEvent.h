/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessibleHideEvent.idl
 */

#ifndef __gen_nsIAccessibleHideEvent_h__
#define __gen_nsIAccessibleHideEvent_h__


#ifndef __gen_nsIAccessibleEvent_h__
#include "nsIAccessibleEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleHideEvent */
#define NS_IACCESSIBLEHIDEEVENT_IID_STR "2051709a-4e0d-4be5-873d-b49d1dee35fa"

#define NS_IACCESSIBLEHIDEEVENT_IID \
  {0x2051709a, 0x4e0d, 0x4be5, \
    { 0x87, 0x3d, 0xb4, 0x9d, 0x1d, 0xee, 0x35, 0xfa }}

class NS_NO_VTABLE nsIAccessibleHideEvent : public nsIAccessibleEvent {
 public:

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEHIDEEVENT_IID)

  /* readonly attribute nsIAccessible targetParent; */
  NS_IMETHOD GetTargetParent(nsIAccessible * *aTargetParent) = 0;

  /* readonly attribute nsIAccessible targetNextSibling; */
  NS_IMETHOD GetTargetNextSibling(nsIAccessible * *aTargetNextSibling) = 0;

  /* readonly attribute nsIAccessible targetPrevSibling; */
  NS_IMETHOD GetTargetPrevSibling(nsIAccessible * *aTargetPrevSibling) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleHideEvent, NS_IACCESSIBLEHIDEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEHIDEEVENT \
  NS_IMETHOD GetTargetParent(nsIAccessible * *aTargetParent) override; \
  NS_IMETHOD GetTargetNextSibling(nsIAccessible * *aTargetNextSibling) override; \
  NS_IMETHOD GetTargetPrevSibling(nsIAccessible * *aTargetPrevSibling) override; 

/* Use this macro when declaring the members of this interface when the
   class doesn't implement the interface. This is useful for forwarding. */
#define NS_DECL_NON_VIRTUAL_NSIACCESSIBLEHIDEEVENT \
  NS_METHOD GetTargetParent(nsIAccessible * *aTargetParent); \
  NS_METHOD GetTargetNextSibling(nsIAccessible * *aTargetNextSibling); \
  NS_METHOD GetTargetPrevSibling(nsIAccessible * *aTargetPrevSibling); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEHIDEEVENT(_to) \
  NS_IMETHOD GetTargetParent(nsIAccessible * *aTargetParent) override { return _to GetTargetParent(aTargetParent); } \
  NS_IMETHOD GetTargetNextSibling(nsIAccessible * *aTargetNextSibling) override { return _to GetTargetNextSibling(aTargetNextSibling); } \
  NS_IMETHOD GetTargetPrevSibling(nsIAccessible * *aTargetPrevSibling) override { return _to GetTargetPrevSibling(aTargetPrevSibling); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEHIDEEVENT(_to) \
  NS_IMETHOD GetTargetParent(nsIAccessible * *aTargetParent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetParent(aTargetParent); } \
  NS_IMETHOD GetTargetNextSibling(nsIAccessible * *aTargetNextSibling) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetNextSibling(aTargetNextSibling); } \
  NS_IMETHOD GetTargetPrevSibling(nsIAccessible * *aTargetPrevSibling) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetPrevSibling(aTargetPrevSibling); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleHideEvent : public nsIAccessibleHideEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEHIDEEVENT

  nsAccessibleHideEvent();

private:
  ~nsAccessibleHideEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAccessibleHideEvent, nsIAccessibleHideEvent)

nsAccessibleHideEvent::nsAccessibleHideEvent()
{
  /* member initializers and constructor code */
}

nsAccessibleHideEvent::~nsAccessibleHideEvent()
{
  /* destructor code */
}

/* readonly attribute nsIAccessible targetParent; */
NS_IMETHODIMP nsAccessibleHideEvent::GetTargetParent(nsIAccessible * *aTargetParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessible targetNextSibling; */
NS_IMETHODIMP nsAccessibleHideEvent::GetTargetNextSibling(nsIAccessible * *aTargetNextSibling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessible targetPrevSibling; */
NS_IMETHODIMP nsAccessibleHideEvent::GetTargetPrevSibling(nsIAccessible * *aTargetPrevSibling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleHideEvent_h__ */
