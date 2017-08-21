/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessibleStateChangeEvent.idl
 */

#ifndef __gen_nsIAccessibleStateChangeEvent_h__
#define __gen_nsIAccessibleStateChangeEvent_h__


#ifndef __gen_nsIAccessibleEvent_h__
#include "nsIAccessibleEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleStateChangeEvent */
#define NS_IACCESSIBLESTATECHANGEEVENT_IID_STR "58b74954-1835-46ed-9ccd-c906490106f6"

#define NS_IACCESSIBLESTATECHANGEEVENT_IID \
  {0x58b74954, 0x1835, 0x46ed, \
    { 0x9c, 0xcd, 0xc9, 0x06, 0x49, 0x01, 0x06, 0xf6 }}

class NS_NO_VTABLE nsIAccessibleStateChangeEvent : public nsIAccessibleEvent {
 public:

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLESTATECHANGEEVENT_IID)

  /* readonly attribute unsigned long state; */
  NS_IMETHOD GetState(uint32_t *aState) = 0;

  /* readonly attribute boolean isExtraState; */
  NS_IMETHOD GetIsExtraState(bool *aIsExtraState) = 0;

  /* readonly attribute boolean isEnabled; */
  NS_IMETHOD GetIsEnabled(bool *aIsEnabled) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleStateChangeEvent, NS_IACCESSIBLESTATECHANGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLESTATECHANGEEVENT \
  NS_IMETHOD GetState(uint32_t *aState) override; \
  NS_IMETHOD GetIsExtraState(bool *aIsExtraState) override; \
  NS_IMETHOD GetIsEnabled(bool *aIsEnabled) override; 

/* Use this macro when declaring the members of this interface when the
   class doesn't implement the interface. This is useful for forwarding. */
#define NS_DECL_NON_VIRTUAL_NSIACCESSIBLESTATECHANGEEVENT \
  NS_METHOD GetState(uint32_t *aState); \
  NS_METHOD GetIsExtraState(bool *aIsExtraState); \
  NS_METHOD GetIsEnabled(bool *aIsEnabled); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLESTATECHANGEEVENT(_to) \
  NS_IMETHOD GetState(uint32_t *aState) override { return _to GetState(aState); } \
  NS_IMETHOD GetIsExtraState(bool *aIsExtraState) override { return _to GetIsExtraState(aIsExtraState); } \
  NS_IMETHOD GetIsEnabled(bool *aIsEnabled) override { return _to GetIsEnabled(aIsEnabled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLESTATECHANGEEVENT(_to) \
  NS_IMETHOD GetState(uint32_t *aState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_IMETHOD GetIsExtraState(bool *aIsExtraState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsExtraState(aIsExtraState); } \
  NS_IMETHOD GetIsEnabled(bool *aIsEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsEnabled(aIsEnabled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleStateChangeEvent : public nsIAccessibleStateChangeEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLESTATECHANGEEVENT

  nsAccessibleStateChangeEvent();

private:
  ~nsAccessibleStateChangeEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAccessibleStateChangeEvent, nsIAccessibleStateChangeEvent)

nsAccessibleStateChangeEvent::nsAccessibleStateChangeEvent()
{
  /* member initializers and constructor code */
}

nsAccessibleStateChangeEvent::~nsAccessibleStateChangeEvent()
{
  /* destructor code */
}

/* readonly attribute unsigned long state; */
NS_IMETHODIMP nsAccessibleStateChangeEvent::GetState(uint32_t *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isExtraState; */
NS_IMETHODIMP nsAccessibleStateChangeEvent::GetIsExtraState(bool *aIsExtraState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isEnabled; */
NS_IMETHODIMP nsAccessibleStateChangeEvent::GetIsEnabled(bool *aIsEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleStateChangeEvent_h__ */
