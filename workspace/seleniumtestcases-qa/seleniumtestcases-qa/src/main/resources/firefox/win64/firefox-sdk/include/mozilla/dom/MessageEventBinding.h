/* THIS FILE IS AUTOGENERATED FROM MessageEvent.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_MessageEventBinding_h
#define mozilla_dom_MessageEventBinding_h

#include "EventBinding.h"
#include "js/RootingAPI.h"
#include "jspubtd.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/MessagePort.h"
#include "mozilla/dom/Nullable.h"
#include "mozilla/dom/UnionMember.h"

class nsGlobalWindow;
class nsPIDOMWindowOuter;

namespace mozilla {
namespace dom {

class MessageEvent;
struct MessageEventAtoms;
struct MessageEventInitAtoms;
class MessagePort;
struct NativePropertyHooks;
class OwningWindowOrMessagePort;
class OwningWindowProxyOrMessagePort;
class ProtoAndIfaceCache;
class WindowOrMessagePort;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

void
ImplCycleCollectionTraverse(nsCycleCollectionTraversalCallback& aCallback, OwningWindowOrMessagePort& aUnion, const char* aName, uint32_t aFlags = 0);


void
ImplCycleCollectionTraverse(nsCycleCollectionTraversalCallback& aCallback, OwningWindowProxyOrMessagePort& aUnion, const char* aName, uint32_t aFlags = 0);


void
ImplCycleCollectionUnlink(OwningWindowOrMessagePort& aUnion);


void
ImplCycleCollectionUnlink(OwningWindowProxyOrMessagePort& aUnion);


class WindowOrMessagePort
{
  friend class WindowOrMessagePortArgument;
  enum Type
  {
    eUninitialized,
    eWindow,
    eMessagePort
  };

  union Value
  {
    UnionMember<NonNull<nsGlobalWindow> > mWindow;
    UnionMember<NonNull<mozilla::dom::MessagePort> > mMessagePort;

  };

  Type mType;
  Value mValue;

  WindowOrMessagePort(const WindowOrMessagePort&) = delete;
  void operator=(const WindowOrMessagePort) = delete;
public:
  explicit inline WindowOrMessagePort()
    : mType(eUninitialized)
  {
  }

  inline ~WindowOrMessagePort()
  {
    Uninit();
  }

  inline NonNull<nsGlobalWindow>&
  RawSetAsWindow()
  {
    if (mType == eWindow) {
      return mValue.mWindow.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eWindow;
    return mValue.mWindow.SetValue();
  }

  inline NonNull<nsGlobalWindow>&
  SetAsWindow()
  {
    if (mType == eWindow) {
      return mValue.mWindow.Value();
    }
    Uninit();
    mType = eWindow;
    return mValue.mWindow.SetValue();
  }

  inline bool
  IsWindow() const
  {
    return mType == eWindow;
  }

  inline NonNull<nsGlobalWindow>&
  GetAsWindow()
  {
    MOZ_ASSERT(IsWindow(), "Wrong type!");
    return mValue.mWindow.Value();
  }

  inline nsGlobalWindow&
  GetAsWindow() const
  {
    MOZ_ASSERT(IsWindow(), "Wrong type!");
    return mValue.mWindow.Value();
  }

  inline NonNull<mozilla::dom::MessagePort>&
  RawSetAsMessagePort()
  {
    if (mType == eMessagePort) {
      return mValue.mMessagePort.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eMessagePort;
    return mValue.mMessagePort.SetValue();
  }

  inline NonNull<mozilla::dom::MessagePort>&
  SetAsMessagePort()
  {
    if (mType == eMessagePort) {
      return mValue.mMessagePort.Value();
    }
    Uninit();
    mType = eMessagePort;
    return mValue.mMessagePort.SetValue();
  }

  inline bool
  IsMessagePort() const
  {
    return mType == eMessagePort;
  }

  inline NonNull<mozilla::dom::MessagePort>&
  GetAsMessagePort()
  {
    MOZ_ASSERT(IsMessagePort(), "Wrong type!");
    return mValue.mMessagePort.Value();
  }

  inline mozilla::dom::MessagePort&
  GetAsMessagePort() const
  {
    MOZ_ASSERT(IsMessagePort(), "Wrong type!");
    return mValue.mMessagePort.Value();
  }

  inline void
  Uninit()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eWindow: {
        DestroyWindow();
        break;
      }
      case eMessagePort: {
        DestroyMessagePort();
        break;
      }
    }
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyWindow()
  {
    MOZ_ASSERT(IsWindow(), "Wrong type!");
    mValue.mWindow.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyMessagePort()
  {
    MOZ_ASSERT(IsMessagePort(), "Wrong type!");
    mValue.mMessagePort.Destroy();
    mType = eUninitialized;
  }
};


class OwningWindowOrMessagePort : public AllOwningUnionBase
{
  friend void ImplCycleCollectionUnlink(OwningWindowOrMessagePort& aUnion);
  enum Type
  {
    eUninitialized,
    eWindow,
    eMessagePort
  };

  union Value
  {
    UnionMember<OwningNonNull<nsGlobalWindow> > mWindow;
    UnionMember<OwningNonNull<mozilla::dom::MessagePort> > mMessagePort;

  };

  Type mType;
  Value mValue;

public:
  explicit inline OwningWindowOrMessagePort()
    : mType(eUninitialized)
  {
  }

  explicit inline OwningWindowOrMessagePort(const OwningWindowOrMessagePort& aOther)
    : mType(eUninitialized)
  {
    *this = aOther;
  }

  inline ~OwningWindowOrMessagePort()
  {
    Uninit();
  }

  OwningNonNull<nsGlobalWindow>&
  RawSetAsWindow();

  OwningNonNull<nsGlobalWindow>&
  SetAsWindow();

  bool
  TrySetToWindow(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsWindow() const
  {
    return mType == eWindow;
  }

  inline OwningNonNull<nsGlobalWindow>&
  GetAsWindow()
  {
    MOZ_ASSERT(IsWindow(), "Wrong type!");
    return mValue.mWindow.Value();
  }

  inline OwningNonNull<nsGlobalWindow> const &
  GetAsWindow() const
  {
    MOZ_ASSERT(IsWindow(), "Wrong type!");
    return mValue.mWindow.Value();
  }

  OwningNonNull<mozilla::dom::MessagePort>&
  RawSetAsMessagePort();

  OwningNonNull<mozilla::dom::MessagePort>&
  SetAsMessagePort();

  bool
  TrySetToMessagePort(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsMessagePort() const
  {
    return mType == eMessagePort;
  }

  inline OwningNonNull<mozilla::dom::MessagePort>&
  GetAsMessagePort()
  {
    MOZ_ASSERT(IsMessagePort(), "Wrong type!");
    return mValue.mMessagePort.Value();
  }

  inline OwningNonNull<mozilla::dom::MessagePort> const &
  GetAsMessagePort() const
  {
    MOZ_ASSERT(IsMessagePort(), "Wrong type!");
    return mValue.mMessagePort.Value();
  }

  void
  Uninit();

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

  void
  operator=(const OwningWindowOrMessagePort& aOther);

private:
  void
  DestroyWindow();

  void
  DestroyMessagePort();
};


class WindowProxyOrMessagePort
{
  friend class WindowProxyOrMessagePortArgument;
  enum Type
  {
    eUninitialized,
    eWindowProxy,
    eMessagePort
  };

  union Value
  {
    UnionMember<nsPIDOMWindowOuter* > mWindowProxy;
    UnionMember<NonNull<mozilla::dom::MessagePort> > mMessagePort;

  };

  Type mType;
  Value mValue;

  WindowProxyOrMessagePort(const WindowProxyOrMessagePort&) = delete;
  void operator=(const WindowProxyOrMessagePort) = delete;
public:
  explicit inline WindowProxyOrMessagePort()
    : mType(eUninitialized)
  {
  }

  inline ~WindowProxyOrMessagePort()
  {
    Uninit();
  }

  inline nsPIDOMWindowOuter*&
  RawSetAsWindowProxy()
  {
    if (mType == eWindowProxy) {
      return mValue.mWindowProxy.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eWindowProxy;
    return mValue.mWindowProxy.SetValue();
  }

  inline nsPIDOMWindowOuter*&
  SetAsWindowProxy()
  {
    if (mType == eWindowProxy) {
      return mValue.mWindowProxy.Value();
    }
    Uninit();
    mType = eWindowProxy;
    return mValue.mWindowProxy.SetValue();
  }

  inline bool
  IsWindowProxy() const
  {
    return mType == eWindowProxy;
  }

  inline nsPIDOMWindowOuter*&
  GetAsWindowProxy()
  {
    MOZ_ASSERT(IsWindowProxy(), "Wrong type!");
    return mValue.mWindowProxy.Value();
  }

  inline nsPIDOMWindowOuter*
  GetAsWindowProxy() const
  {
    MOZ_ASSERT(IsWindowProxy(), "Wrong type!");
    return mValue.mWindowProxy.Value();
  }

  inline NonNull<mozilla::dom::MessagePort>&
  RawSetAsMessagePort()
  {
    if (mType == eMessagePort) {
      return mValue.mMessagePort.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eMessagePort;
    return mValue.mMessagePort.SetValue();
  }

  inline NonNull<mozilla::dom::MessagePort>&
  SetAsMessagePort()
  {
    if (mType == eMessagePort) {
      return mValue.mMessagePort.Value();
    }
    Uninit();
    mType = eMessagePort;
    return mValue.mMessagePort.SetValue();
  }

  inline bool
  IsMessagePort() const
  {
    return mType == eMessagePort;
  }

  inline NonNull<mozilla::dom::MessagePort>&
  GetAsMessagePort()
  {
    MOZ_ASSERT(IsMessagePort(), "Wrong type!");
    return mValue.mMessagePort.Value();
  }

  inline mozilla::dom::MessagePort&
  GetAsMessagePort() const
  {
    MOZ_ASSERT(IsMessagePort(), "Wrong type!");
    return mValue.mMessagePort.Value();
  }

  inline void
  Uninit()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eWindowProxy: {
        DestroyWindowProxy();
        break;
      }
      case eMessagePort: {
        DestroyMessagePort();
        break;
      }
    }
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyWindowProxy()
  {
    MOZ_ASSERT(IsWindowProxy(), "Wrong type!");
    mValue.mWindowProxy.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyMessagePort()
  {
    MOZ_ASSERT(IsMessagePort(), "Wrong type!");
    mValue.mMessagePort.Destroy();
    mType = eUninitialized;
  }
};


class OwningWindowProxyOrMessagePort : public AllOwningUnionBase
{
  friend void ImplCycleCollectionUnlink(OwningWindowProxyOrMessagePort& aUnion);
  enum Type
  {
    eUninitialized,
    eWindowProxy,
    eMessagePort
  };

  union Value
  {
    UnionMember<RefPtr<nsPIDOMWindowOuter> > mWindowProxy;
    UnionMember<OwningNonNull<mozilla::dom::MessagePort> > mMessagePort;

  };

  Type mType;
  Value mValue;

public:
  explicit inline OwningWindowProxyOrMessagePort()
    : mType(eUninitialized)
  {
  }

  explicit inline OwningWindowProxyOrMessagePort(const OwningWindowProxyOrMessagePort& aOther)
    : mType(eUninitialized)
  {
    *this = aOther;
  }

  inline ~OwningWindowProxyOrMessagePort()
  {
    Uninit();
  }

  RefPtr<nsPIDOMWindowOuter>&
  RawSetAsWindowProxy();

  RefPtr<nsPIDOMWindowOuter>&
  SetAsWindowProxy();

  bool
  TrySetToWindowProxy(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsWindowProxy() const
  {
    return mType == eWindowProxy;
  }

  inline RefPtr<nsPIDOMWindowOuter>&
  GetAsWindowProxy()
  {
    MOZ_ASSERT(IsWindowProxy(), "Wrong type!");
    return mValue.mWindowProxy.Value();
  }

  inline RefPtr<nsPIDOMWindowOuter> const &
  GetAsWindowProxy() const
  {
    MOZ_ASSERT(IsWindowProxy(), "Wrong type!");
    return mValue.mWindowProxy.Value();
  }

  OwningNonNull<mozilla::dom::MessagePort>&
  RawSetAsMessagePort();

  OwningNonNull<mozilla::dom::MessagePort>&
  SetAsMessagePort();

  bool
  TrySetToMessagePort(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsMessagePort() const
  {
    return mType == eMessagePort;
  }

  inline OwningNonNull<mozilla::dom::MessagePort>&
  GetAsMessagePort()
  {
    MOZ_ASSERT(IsMessagePort(), "Wrong type!");
    return mValue.mMessagePort.Value();
  }

  inline OwningNonNull<mozilla::dom::MessagePort> const &
  GetAsMessagePort() const
  {
    MOZ_ASSERT(IsMessagePort(), "Wrong type!");
    return mValue.mMessagePort.Value();
  }

  void
  Uninit();

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

  void
  operator=(const OwningWindowProxyOrMessagePort& aOther);

private:
  void
  DestroyWindowProxy();

  void
  DestroyMessagePort();
};


struct MessageEventInit : public EventInit
{
  JS::Value mData;
  Optional<nsString> mLastEventId;
  Optional<nsString> mOrigin;
  Optional<Nullable<Sequence<OwningNonNull<mozilla::dom::MessagePort>>>> mPorts;
  Nullable<OwningWindowOrMessagePort > mSource;

  MessageEventInit();

  explicit inline MessageEventInit(const FastDictionaryInitializer& )
    : EventInit(FastDictionaryInitializer()),
      mData(JS::UndefinedValue())
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

private:
  MessageEventInit(const MessageEventInit&) = delete;
  void operator=(const MessageEventInit) = delete;

  static bool
  InitIds(JSContext* cx, MessageEventInitAtoms* atomsCache);

public:
  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value", bool passedToJSImpl = false);

  bool
  Init(const nsAString& aJSON);

  bool
  ToObjectInternal(JSContext* cx, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceDictionary(JSTracer* trc);
};

namespace binding_detail {
struct FastMessageEventInit : public MessageEventInit
{
  inline FastMessageEventInit()
    : MessageEventInit(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


namespace MessageEventBinding {

  typedef mozilla::dom::MessageEvent NativeType;

  // We declare this as an array so that retrieving a pointer to this
  // binding's property hooks only requires compile/link-time resolvable
  // address arithmetic.  Declaring it as a pointer instead would require
  // doing a run-time load to fetch a pointer to this binding's property
  // hooks.  And then structures which embedded a pointer to this structure
  // would require a run-time load for proper initialization, which would
  // then induce static constructors.  Lots of static constructors.
  extern const NativePropertyHooks sNativePropertyHooks[];

  JSObject*
  DefineDOMInterface(JSContext* aCx, JS::Handle<JSObject*> aGlobal, JS::Handle<jsid> id, bool aDefineOnGlobal);

  const JSClass*
  GetJSClass();

  bool
  Wrap(JSContext* aCx, mozilla::dom::MessageEvent* aObject, nsWrapperCache* aCache, JS::Handle<JSObject*> aGivenProto, JS::MutableHandle<JSObject*> aReflector);

  template <class T>
  inline JSObject* Wrap(JSContext* aCx, T* aObject, JS::Handle<JSObject*> aGivenProto)
  {
    JS::Rooted<JSObject*> reflector(aCx);
    return Wrap(aCx, aObject, aObject, aGivenProto, &reflector) ? reflector.get() : nullptr;
  }

  void
  CreateInterfaceObjects(JSContext* aCx, JS::Handle<JSObject*> aGlobal, ProtoAndIfaceCache& aProtoAndIfaceCache, bool aDefineOnGlobal);

  JS::Handle<JSObject*>
  GetProtoObjectHandle(JSContext* aCx, JS::Handle<JSObject*> aGlobal);

  JS::Handle<JSObject*>
  GetConstructorObjectHandle(JSContext* aCx, JS::Handle<JSObject*> aGlobal, bool aDefineOnGlobal = true);

  JSObject*
  GetConstructorObject(JSContext* aCx, JS::Handle<JSObject*> aGlobal);

} // namespace MessageEventBinding



} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_MessageEventBinding_h