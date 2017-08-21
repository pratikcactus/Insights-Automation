/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDivertableChannel.idl
 */

#ifndef __gen_nsIDivertableChannel_h__
#define __gen_nsIDivertableChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
namespace mozilla {
namespace net {
class ChannelDiverterChild;
}
}
class nsIStreamListener; /* forward declaration */


/* starting interface:    nsIDivertableChannel */
#define NS_IDIVERTABLECHANNEL_IID_STR "7a9bf52d-f828-4b31-b8df-b40fdd37d007"

#define NS_IDIVERTABLECHANNEL_IID \
  {0x7a9bf52d, 0xf828, 0x4b31, \
    { 0xb8, 0xdf, 0xb4, 0x0f, 0xdd, 0x37, 0xd0, 0x07 }}

class NS_NO_VTABLE nsIDivertableChannel : public nsISupports {
 public:

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDIVERTABLECHANNEL_IID)

  /* ChannelDiverterChild divertToParent (); */
  NS_IMETHOD DivertToParent(mozilla::net::ChannelDiverterChild **_retval) = 0;

  /* void unknownDecoderInvolvedKeepData (); */
  NS_IMETHOD UnknownDecoderInvolvedKeepData(void) = 0;

  /* void unknownDecoderInvolvedOnStartRequestCalled (); */
  NS_IMETHOD UnknownDecoderInvolvedOnStartRequestCalled(void) = 0;

  /* readonly attribute bool divertingToParent; */
  NS_IMETHOD GetDivertingToParent(bool *aDivertingToParent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDivertableChannel, NS_IDIVERTABLECHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDIVERTABLECHANNEL \
  NS_IMETHOD DivertToParent(mozilla::net::ChannelDiverterChild **_retval) override; \
  NS_IMETHOD UnknownDecoderInvolvedKeepData(void) override; \
  NS_IMETHOD UnknownDecoderInvolvedOnStartRequestCalled(void) override; \
  NS_IMETHOD GetDivertingToParent(bool *aDivertingToParent) override; 

/* Use this macro when declaring the members of this interface when the
   class doesn't implement the interface. This is useful for forwarding. */
#define NS_DECL_NON_VIRTUAL_NSIDIVERTABLECHANNEL \
  NS_METHOD DivertToParent(mozilla::net::ChannelDiverterChild **_retval); \
  NS_METHOD UnknownDecoderInvolvedKeepData(void); \
  NS_METHOD UnknownDecoderInvolvedOnStartRequestCalled(void); \
  NS_METHOD GetDivertingToParent(bool *aDivertingToParent); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDIVERTABLECHANNEL(_to) \
  NS_IMETHOD DivertToParent(mozilla::net::ChannelDiverterChild **_retval) override { return _to DivertToParent(_retval); } \
  NS_IMETHOD UnknownDecoderInvolvedKeepData(void) override { return _to UnknownDecoderInvolvedKeepData(); } \
  NS_IMETHOD UnknownDecoderInvolvedOnStartRequestCalled(void) override { return _to UnknownDecoderInvolvedOnStartRequestCalled(); } \
  NS_IMETHOD GetDivertingToParent(bool *aDivertingToParent) override { return _to GetDivertingToParent(aDivertingToParent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDIVERTABLECHANNEL(_to) \
  NS_IMETHOD DivertToParent(mozilla::net::ChannelDiverterChild **_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DivertToParent(_retval); } \
  NS_IMETHOD UnknownDecoderInvolvedKeepData(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UnknownDecoderInvolvedKeepData(); } \
  NS_IMETHOD UnknownDecoderInvolvedOnStartRequestCalled(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UnknownDecoderInvolvedOnStartRequestCalled(); } \
  NS_IMETHOD GetDivertingToParent(bool *aDivertingToParent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDivertingToParent(aDivertingToParent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDivertableChannel : public nsIDivertableChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDIVERTABLECHANNEL

  nsDivertableChannel();

private:
  ~nsDivertableChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDivertableChannel, nsIDivertableChannel)

nsDivertableChannel::nsDivertableChannel()
{
  /* member initializers and constructor code */
}

nsDivertableChannel::~nsDivertableChannel()
{
  /* destructor code */
}

/* ChannelDiverterChild divertToParent (); */
NS_IMETHODIMP nsDivertableChannel::DivertToParent(mozilla::net::ChannelDiverterChild **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unknownDecoderInvolvedKeepData (); */
NS_IMETHODIMP nsDivertableChannel::UnknownDecoderInvolvedKeepData()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unknownDecoderInvolvedOnStartRequestCalled (); */
NS_IMETHODIMP nsDivertableChannel::UnknownDecoderInvolvedOnStartRequestCalled()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute bool divertingToParent; */
NS_IMETHODIMP nsDivertableChannel::GetDivertingToParent(bool *aDivertingToParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDivertableChannel_h__ */
