/* THIS FILE IS AUTOGENERATED FROM PeerConnectionObserver.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_PeerConnectionObserverBinding_h
#define mozilla_dom_PeerConnectionObserverBinding_h

#include "PeerConnectionObserverEnumsBinding.h"
#include "js/RootingAPI.h"
#include "jspubtd.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/CallbackInterface.h"
#include "mozilla/dom/Nullable.h"
#include "mozilla/dom/ToJSValue.h"
#include "nsWeakReference.h"

class nsDOMDataChannel;

namespace mozilla {

class DOMMediaStream;

namespace dom {

class MediaStreamTrack;
struct NativePropertyHooks;
class PeerConnectionObserver;
struct PeerConnectionObserverAtoms;
class ProtoAndIfaceCache;
class RTCPeerConnection;
struct RTCStatsReportInternal;

} // namespace dom

} // namespace mozilla

namespace mozilla {
namespace dom {

namespace PeerConnectionObserverBinding {

  typedef mozilla::dom::PeerConnectionObserver NativeType;

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

  bool
  ConstructorEnabled(JSContext* aCx, JS::Handle<JSObject*> aObj);

  const JSClass*
  GetJSClass();

  bool
  Wrap(JSContext* aCx, mozilla::dom::PeerConnectionObserver* aObject, nsWrapperCache* aCache, JS::Handle<JSObject*> aGivenProto, JS::MutableHandle<JSObject*> aReflector);

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

} // namespace PeerConnectionObserverBinding



class PeerConnectionObserverJSImpl : public CallbackInterface
{
public:
  explicit inline PeerConnectionObserverJSImpl(JSContext* aCx, JS::Handle<JSObject*> aCallback, nsIGlobalObject* aIncumbentGlobal)
    : CallbackInterface(aCx, aCallback, aIncumbentGlobal)
  {
  }

  void OnCreateOfferSuccess(const nsAString& offer, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnCreateOfferError(uint32_t name, const nsAString& message, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnCreateAnswerSuccess(const nsAString& answer, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnCreateAnswerError(uint32_t name, const nsAString& message, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnSetLocalDescriptionSuccess(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnSetRemoteDescriptionSuccess(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnSetLocalDescriptionError(uint32_t name, const nsAString& message, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnSetRemoteDescriptionError(uint32_t name, const nsAString& message, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnAddIceCandidateSuccess(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnAddIceCandidateError(uint32_t name, const nsAString& message, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnIceCandidate(uint16_t level, const nsAString& mid, const nsAString& candidate, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnNegotiationNeeded(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnGetStatsSuccess(const RTCStatsReportInternal& report, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnGetStatsError(uint32_t name, const nsAString& message, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnReplaceTrackSuccess(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnReplaceTrackError(uint32_t name, const nsAString& message, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void NotifyDataChannel(nsDOMDataChannel& channel, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnStateChange(PCObserverStateType state, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnAddStream(DOMMediaStream& stream, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnRemoveStream(DOMMediaStream& stream, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnAddTrack(MediaStreamTrack& track, const Sequence<OwningNonNull<DOMMediaStream>>& streams, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnRemoveTrack(MediaStreamTrack& track, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void __Init(RTCPeerConnection& domPC, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  inline bool
  operator==(const PeerConnectionObserverJSImpl& aOther) const
  {
    return CallbackInterface::operator==(aOther);
  }

private:
  static bool
  InitIds(JSContext* cx, PeerConnectionObserverAtoms* atomsCache);
};


class PeerConnectionObserver final : public nsSupportsWeakReference,
                                     public nsWrapperCache
{
public:
  NS_DECL_CYCLE_COLLECTING_ISUPPORTS
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS(PeerConnectionObserver)

private:
  RefPtr<PeerConnectionObserverJSImpl> mImpl;
  nsCOMPtr<nsISupports> mParent;

public:
  PeerConnectionObserver(JS::Handle<JSObject*> aJSImplObject, nsIGlobalObject* aParent);

private:
  ~PeerConnectionObserver();

public:
  nsISupports* GetParentObject() const;

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aGivenProto) override;

  static already_AddRefed<PeerConnectionObserver> Constructor(const GlobalObject& global, JSContext* cx, RTCPeerConnection& domPC, ErrorResult& aRv);

  void OnCreateOfferSuccess(const nsAString& offer, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnCreateOfferError(uint32_t name, const nsAString& message, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnCreateAnswerSuccess(const nsAString& answer, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnCreateAnswerError(uint32_t name, const nsAString& message, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnSetLocalDescriptionSuccess(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnSetRemoteDescriptionSuccess(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnSetLocalDescriptionError(uint32_t name, const nsAString& message, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnSetRemoteDescriptionError(uint32_t name, const nsAString& message, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnAddIceCandidateSuccess(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnAddIceCandidateError(uint32_t name, const nsAString& message, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnIceCandidate(uint16_t level, const nsAString& mid, const nsAString& candidate, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnNegotiationNeeded(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnGetStatsSuccess(const RTCStatsReportInternal& report, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnGetStatsError(uint32_t name, const nsAString& message, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnReplaceTrackSuccess(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnReplaceTrackError(uint32_t name, const nsAString& message, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void NotifyDataChannel(nsDOMDataChannel& channel, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnStateChange(PCObserverStateType state, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnAddStream(DOMMediaStream& stream, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnRemoveStream(DOMMediaStream& stream, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnAddTrack(MediaStreamTrack& track, const Sequence<OwningNonNull<DOMMediaStream>>& streams, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void OnRemoveTrack(MediaStreamTrack& track, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  static bool
  _Create(JSContext* cx, unsigned argc, JS::Value* vp);
};


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_PeerConnectionObserverBinding_h
