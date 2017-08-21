/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIWinTaskbar.idl
 */

#ifndef __gen_nsIWinTaskbar_h__
#define __gen_nsIWinTaskbar_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIBaseWindow_h__
#include "nsIBaseWindow.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocShell; /* forward declaration */

class nsITaskbarTabPreview; /* forward declaration */

class nsITaskbarWindowPreview; /* forward declaration */

class nsITaskbarPreviewController; /* forward declaration */

class nsITaskbarProgress; /* forward declaration */

class nsITaskbarOverlayIconController; /* forward declaration */

class nsIJumpListBuilder; /* forward declaration */

class mozIDOMWindow; /* forward declaration */


/* starting interface:    nsIWinTaskbar */
#define NS_IWINTASKBAR_IID_STR "11751471-9246-4c72-a80f-0c7df765d640"

#define NS_IWINTASKBAR_IID \
  {0x11751471, 0x9246, 0x4c72, \
    { 0xa8, 0x0f, 0x0c, 0x7d, 0xf7, 0x65, 0xd6, 0x40 }}

class NS_NO_VTABLE nsIWinTaskbar : public nsISupports {
 public:

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWINTASKBAR_IID)

  /* readonly attribute boolean available; */
  NS_IMETHOD GetAvailable(bool *aAvailable) = 0;

  /* readonly attribute AString defaultGroupId; */
  NS_IMETHOD GetDefaultGroupId(nsAString & aDefaultGroupId) = 0;

  /* nsITaskbarTabPreview createTaskbarTabPreview (in nsIDocShell shell, in nsITaskbarPreviewController controller); */
  NS_IMETHOD CreateTaskbarTabPreview(nsIDocShell *shell, nsITaskbarPreviewController *controller, nsITaskbarTabPreview * *_retval) = 0;

  /* nsITaskbarWindowPreview getTaskbarWindowPreview (in nsIDocShell shell); */
  NS_IMETHOD GetTaskbarWindowPreview(nsIDocShell *shell, nsITaskbarWindowPreview * *_retval) = 0;

  /* nsITaskbarProgress getTaskbarProgress (in nsIDocShell shell); */
  NS_IMETHOD GetTaskbarProgress(nsIDocShell *shell, nsITaskbarProgress * *_retval) = 0;

  /* nsITaskbarOverlayIconController getOverlayIconController (in nsIDocShell shell); */
  NS_IMETHOD GetOverlayIconController(nsIDocShell *shell, nsITaskbarOverlayIconController * *_retval) = 0;

  /* nsIJumpListBuilder createJumpListBuilder (); */
  NS_IMETHOD CreateJumpListBuilder(nsIJumpListBuilder * *_retval) = 0;

  /* void setGroupIdForWindow (in mozIDOMWindow aParent, in AString aIdentifier); */
  NS_IMETHOD SetGroupIdForWindow(mozIDOMWindow *aParent, const nsAString & aIdentifier) = 0;

  /* void prepareFullScreen (in mozIDOMWindow aWindow, in boolean aFullScreen); */
  NS_IMETHOD PrepareFullScreen(mozIDOMWindow *aWindow, bool aFullScreen) = 0;

  /* [noscript] void prepareFullScreenHWND (in voidPtr aWindow, in boolean aFullScreen); */
  NS_IMETHOD PrepareFullScreenHWND(void *aWindow, bool aFullScreen) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWinTaskbar, NS_IWINTASKBAR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWINTASKBAR \
  NS_IMETHOD GetAvailable(bool *aAvailable) override; \
  NS_IMETHOD GetDefaultGroupId(nsAString & aDefaultGroupId) override; \
  NS_IMETHOD CreateTaskbarTabPreview(nsIDocShell *shell, nsITaskbarPreviewController *controller, nsITaskbarTabPreview * *_retval) override; \
  NS_IMETHOD GetTaskbarWindowPreview(nsIDocShell *shell, nsITaskbarWindowPreview * *_retval) override; \
  NS_IMETHOD GetTaskbarProgress(nsIDocShell *shell, nsITaskbarProgress * *_retval) override; \
  NS_IMETHOD GetOverlayIconController(nsIDocShell *shell, nsITaskbarOverlayIconController * *_retval) override; \
  NS_IMETHOD CreateJumpListBuilder(nsIJumpListBuilder * *_retval) override; \
  NS_IMETHOD SetGroupIdForWindow(mozIDOMWindow *aParent, const nsAString & aIdentifier) override; \
  NS_IMETHOD PrepareFullScreen(mozIDOMWindow *aWindow, bool aFullScreen) override; \
  NS_IMETHOD PrepareFullScreenHWND(void *aWindow, bool aFullScreen) override; 

/* Use this macro when declaring the members of this interface when the
   class doesn't implement the interface. This is useful for forwarding. */
#define NS_DECL_NON_VIRTUAL_NSIWINTASKBAR \
  NS_METHOD GetAvailable(bool *aAvailable); \
  NS_METHOD GetDefaultGroupId(nsAString & aDefaultGroupId); \
  NS_METHOD CreateTaskbarTabPreview(nsIDocShell *shell, nsITaskbarPreviewController *controller, nsITaskbarTabPreview * *_retval); \
  NS_METHOD GetTaskbarWindowPreview(nsIDocShell *shell, nsITaskbarWindowPreview * *_retval); \
  NS_METHOD GetTaskbarProgress(nsIDocShell *shell, nsITaskbarProgress * *_retval); \
  NS_METHOD GetOverlayIconController(nsIDocShell *shell, nsITaskbarOverlayIconController * *_retval); \
  NS_METHOD CreateJumpListBuilder(nsIJumpListBuilder * *_retval); \
  NS_METHOD SetGroupIdForWindow(mozIDOMWindow *aParent, const nsAString & aIdentifier); \
  NS_METHOD PrepareFullScreen(mozIDOMWindow *aWindow, bool aFullScreen); \
  NS_METHOD PrepareFullScreenHWND(void *aWindow, bool aFullScreen); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWINTASKBAR(_to) \
  NS_IMETHOD GetAvailable(bool *aAvailable) override { return _to GetAvailable(aAvailable); } \
  NS_IMETHOD GetDefaultGroupId(nsAString & aDefaultGroupId) override { return _to GetDefaultGroupId(aDefaultGroupId); } \
  NS_IMETHOD CreateTaskbarTabPreview(nsIDocShell *shell, nsITaskbarPreviewController *controller, nsITaskbarTabPreview * *_retval) override { return _to CreateTaskbarTabPreview(shell, controller, _retval); } \
  NS_IMETHOD GetTaskbarWindowPreview(nsIDocShell *shell, nsITaskbarWindowPreview * *_retval) override { return _to GetTaskbarWindowPreview(shell, _retval); } \
  NS_IMETHOD GetTaskbarProgress(nsIDocShell *shell, nsITaskbarProgress * *_retval) override { return _to GetTaskbarProgress(shell, _retval); } \
  NS_IMETHOD GetOverlayIconController(nsIDocShell *shell, nsITaskbarOverlayIconController * *_retval) override { return _to GetOverlayIconController(shell, _retval); } \
  NS_IMETHOD CreateJumpListBuilder(nsIJumpListBuilder * *_retval) override { return _to CreateJumpListBuilder(_retval); } \
  NS_IMETHOD SetGroupIdForWindow(mozIDOMWindow *aParent, const nsAString & aIdentifier) override { return _to SetGroupIdForWindow(aParent, aIdentifier); } \
  NS_IMETHOD PrepareFullScreen(mozIDOMWindow *aWindow, bool aFullScreen) override { return _to PrepareFullScreen(aWindow, aFullScreen); } \
  NS_IMETHOD PrepareFullScreenHWND(void *aWindow, bool aFullScreen) override { return _to PrepareFullScreenHWND(aWindow, aFullScreen); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWINTASKBAR(_to) \
  NS_IMETHOD GetAvailable(bool *aAvailable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAvailable(aAvailable); } \
  NS_IMETHOD GetDefaultGroupId(nsAString & aDefaultGroupId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultGroupId(aDefaultGroupId); } \
  NS_IMETHOD CreateTaskbarTabPreview(nsIDocShell *shell, nsITaskbarPreviewController *controller, nsITaskbarTabPreview * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTaskbarTabPreview(shell, controller, _retval); } \
  NS_IMETHOD GetTaskbarWindowPreview(nsIDocShell *shell, nsITaskbarWindowPreview * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTaskbarWindowPreview(shell, _retval); } \
  NS_IMETHOD GetTaskbarProgress(nsIDocShell *shell, nsITaskbarProgress * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTaskbarProgress(shell, _retval); } \
  NS_IMETHOD GetOverlayIconController(nsIDocShell *shell, nsITaskbarOverlayIconController * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOverlayIconController(shell, _retval); } \
  NS_IMETHOD CreateJumpListBuilder(nsIJumpListBuilder * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateJumpListBuilder(_retval); } \
  NS_IMETHOD SetGroupIdForWindow(mozIDOMWindow *aParent, const nsAString & aIdentifier) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGroupIdForWindow(aParent, aIdentifier); } \
  NS_IMETHOD PrepareFullScreen(mozIDOMWindow *aWindow, bool aFullScreen) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PrepareFullScreen(aWindow, aFullScreen); } \
  NS_IMETHOD PrepareFullScreenHWND(void *aWindow, bool aFullScreen) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PrepareFullScreenHWND(aWindow, aFullScreen); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWinTaskbar : public nsIWinTaskbar
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWINTASKBAR

  nsWinTaskbar();

private:
  ~nsWinTaskbar();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsWinTaskbar, nsIWinTaskbar)

nsWinTaskbar::nsWinTaskbar()
{
  /* member initializers and constructor code */
}

nsWinTaskbar::~nsWinTaskbar()
{
  /* destructor code */
}

/* readonly attribute boolean available; */
NS_IMETHODIMP nsWinTaskbar::GetAvailable(bool *aAvailable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString defaultGroupId; */
NS_IMETHODIMP nsWinTaskbar::GetDefaultGroupId(nsAString & aDefaultGroupId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITaskbarTabPreview createTaskbarTabPreview (in nsIDocShell shell, in nsITaskbarPreviewController controller); */
NS_IMETHODIMP nsWinTaskbar::CreateTaskbarTabPreview(nsIDocShell *shell, nsITaskbarPreviewController *controller, nsITaskbarTabPreview * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITaskbarWindowPreview getTaskbarWindowPreview (in nsIDocShell shell); */
NS_IMETHODIMP nsWinTaskbar::GetTaskbarWindowPreview(nsIDocShell *shell, nsITaskbarWindowPreview * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITaskbarProgress getTaskbarProgress (in nsIDocShell shell); */
NS_IMETHODIMP nsWinTaskbar::GetTaskbarProgress(nsIDocShell *shell, nsITaskbarProgress * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITaskbarOverlayIconController getOverlayIconController (in nsIDocShell shell); */
NS_IMETHODIMP nsWinTaskbar::GetOverlayIconController(nsIDocShell *shell, nsITaskbarOverlayIconController * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIJumpListBuilder createJumpListBuilder (); */
NS_IMETHODIMP nsWinTaskbar::CreateJumpListBuilder(nsIJumpListBuilder * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setGroupIdForWindow (in mozIDOMWindow aParent, in AString aIdentifier); */
NS_IMETHODIMP nsWinTaskbar::SetGroupIdForWindow(mozIDOMWindow *aParent, const nsAString & aIdentifier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void prepareFullScreen (in mozIDOMWindow aWindow, in boolean aFullScreen); */
NS_IMETHODIMP nsWinTaskbar::PrepareFullScreen(mozIDOMWindow *aWindow, bool aFullScreen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void prepareFullScreenHWND (in voidPtr aWindow, in boolean aFullScreen); */
NS_IMETHODIMP nsWinTaskbar::PrepareFullScreenHWND(void *aWindow, bool aFullScreen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWinTaskbar_h__ */
