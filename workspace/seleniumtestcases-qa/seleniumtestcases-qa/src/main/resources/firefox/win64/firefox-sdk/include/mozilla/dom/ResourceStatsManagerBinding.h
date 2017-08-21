/* THIS FILE IS AUTOGENERATED FROM ResourceStatsManager.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_ResourceStatsManagerBinding_h
#define mozilla_dom_ResourceStatsManagerBinding_h

#include "js/RootingAPI.h"
#include "jspubtd.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/CallbackInterface.h"
#include "mozilla/dom/Nullable.h"
#include "mozilla/dom/ToJSValue.h"
#include "nsWeakReference.h"

namespace mozilla {
namespace dom {

struct NativePropertyHooks;
class Promise;
class ProtoAndIfaceCache;
class ResourceStatsAlarm;
struct ResourceStatsAlarmAtoms;
struct ResourceStatsAlarmOptions;
struct ResourceStatsAlarmOptionsAtoms;
class ResourceStatsManager;
struct ResourceStatsManagerAtoms;
struct ResourceStatsOptions;
struct ResourceStatsOptionsAtoms;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

enum class ResourceType : uint32_t {
  Network,
  Power,
  EndGuard_
};

namespace ResourceTypeValues {
extern const EnumEntry strings[3];
} // namespace ResourceTypeValues

bool
ToJSValue(JSContext* aCx, ResourceType aArgument, JS::MutableHandle<JS::Value> aValue);


enum class SystemService : uint32_t {
  Ota,
  Tethering,
  EndGuard_
};

namespace SystemServiceValues {
extern const EnumEntry strings[3];
} // namespace SystemServiceValues

bool
ToJSValue(JSContext* aCx, SystemService aArgument, JS::MutableHandle<JS::Value> aValue);


struct ResourceStatsAlarmOptions : public DictionaryBase
{
  JS::Value mData;
  Optional<uint64_t> mStartTime;

  ResourceStatsAlarmOptions();

  explicit inline ResourceStatsAlarmOptions(const FastDictionaryInitializer& )
    : mData(JS::UndefinedValue())
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

private:
  ResourceStatsAlarmOptions(const ResourceStatsAlarmOptions&) = delete;
  void operator=(const ResourceStatsAlarmOptions) = delete;

  static bool
  InitIds(JSContext* cx, ResourceStatsAlarmOptionsAtoms* atomsCache);

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
struct FastResourceStatsAlarmOptions : public ResourceStatsAlarmOptions
{
  inline FastResourceStatsAlarmOptions()
    : ResourceStatsAlarmOptions(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct ResourceStatsOptions : public DictionaryBase
{
  nsString mComponent;
  nsString mManifestURL;
  Nullable<SystemService> mServiceType;

  ResourceStatsOptions();

  explicit inline ResourceStatsOptions(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline ResourceStatsOptions(const ResourceStatsOptions& aOther)
  {
    *this = aOther;
  }

  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value", bool passedToJSImpl = false);

  bool
  Init(const nsAString& aJSON);

  bool
  ToObjectInternal(JSContext* cx, JS::MutableHandle<JS::Value> rval) const;

  bool
  ToJSON(nsAString& aJSON) const;

  void
  TraceDictionary(JSTracer* trc);

  void
  operator=(const ResourceStatsOptions& aOther);

private:
  static bool
  InitIds(JSContext* cx, ResourceStatsOptionsAtoms* atomsCache);
};

namespace binding_detail {
struct FastResourceStatsOptions : public ResourceStatsOptions
{
  inline FastResourceStatsOptions()
    : ResourceStatsOptions(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


namespace ResourceStatsAlarmBinding {

  typedef mozilla::dom::ResourceStatsAlarm NativeType;

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
  Wrap(JSContext* aCx, mozilla::dom::ResourceStatsAlarm* aObject, nsWrapperCache* aCache, JS::Handle<JSObject*> aGivenProto, JS::MutableHandle<JSObject*> aReflector);

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

} // namespace ResourceStatsAlarmBinding



namespace ResourceStatsManagerBinding {

  typedef mozilla::dom::ResourceStatsManager NativeType;

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
  Wrap(JSContext* aCx, mozilla::dom::ResourceStatsManager* aObject, nsWrapperCache* aCache, JS::Handle<JSObject*> aGivenProto, JS::MutableHandle<JSObject*> aReflector);

  template <class T>
  inline JSObject* Wrap(JSContext* aCx, T* aObject, JS::Handle<JSObject*> aGivenProto)
  {
    JS::Rooted<JSObject*> reflector(aCx);
    return Wrap(aCx, aObject, aObject, aGivenProto, &reflector) ? reflector.get() : nullptr;
  }

  void
  ClearCachedResourceTypesValue(mozilla::dom::ResourceStatsManager* aObject);

  void
  CreateInterfaceObjects(JSContext* aCx, JS::Handle<JSObject*> aGlobal, ProtoAndIfaceCache& aProtoAndIfaceCache, bool aDefineOnGlobal);

  JS::Handle<JSObject*>
  GetProtoObjectHandle(JSContext* aCx, JS::Handle<JSObject*> aGlobal);

  JS::Handle<JSObject*>
  GetConstructorObjectHandle(JSContext* aCx, JS::Handle<JSObject*> aGlobal, bool aDefineOnGlobal = true);

  JSObject*
  GetConstructorObject(JSContext* aCx, JS::Handle<JSObject*> aGlobal);

} // namespace ResourceStatsManagerBinding



class ResourceStatsAlarmJSImpl : public CallbackInterface
{
public:
  explicit inline ResourceStatsAlarmJSImpl(JSContext* aCx, JS::Handle<JSObject*> aCallback, nsIGlobalObject* aIncumbentGlobal)
    : CallbackInterface(aCx, aCallback, aIncumbentGlobal)
  {
  }

  inline bool
  operator==(const ResourceStatsAlarmJSImpl& aOther) const
  {
    return CallbackInterface::operator==(aOther);
  }

  uint32_t GetAlarmId(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  ResourceType GetType(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetComponent(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  Nullable<SystemService> GetServiceType(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetManifestURL(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  uint64_t GetThreshold(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetData(JS::MutableHandle<JS::Value> aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

private:
  static bool
  InitIds(JSContext* cx, ResourceStatsAlarmAtoms* atomsCache);
};


class ResourceStatsAlarm final : public nsSupportsWeakReference,
                                 public nsWrapperCache
{
public:
  NS_DECL_CYCLE_COLLECTING_ISUPPORTS
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS(ResourceStatsAlarm)

private:
  RefPtr<ResourceStatsAlarmJSImpl> mImpl;
  nsCOMPtr<nsISupports> mParent;

public:
  ResourceStatsAlarm(JS::Handle<JSObject*> aJSImplObject, nsIGlobalObject* aParent);

private:
  ~ResourceStatsAlarm();

public:
  nsISupports* GetParentObject() const;

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aGivenProto) override;

  uint32_t GetAlarmId(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  ResourceType GetType(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void GetComponent(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  Nullable<SystemService> GetServiceType(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void GetManifestURL(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  uint64_t GetThreshold(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void GetData(JS::MutableHandle<JS::Value> aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  static bool
  _Create(JSContext* cx, unsigned argc, JS::Value* vp);
};


class ResourceStatsManagerJSImpl : public CallbackInterface
{
public:
  explicit inline ResourceStatsManagerJSImpl(JSContext* aCx, JS::Handle<JSObject*> aCallback, nsIGlobalObject* aIncumbentGlobal)
    : CallbackInterface(aCx, aCallback, aIncumbentGlobal)
  {
  }

  already_AddRefed<Promise> GetStats(const ResourceStatsOptions& statsOptions, const Nullable<uint64_t>& start, const Nullable<uint64_t>& end, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<Promise> ClearStats(const ResourceStatsOptions& statsOptions, const Nullable<uint64_t>& start, const Nullable<uint64_t>& end, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<Promise> ClearAllStats(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<Promise> AddAlarm(uint64_t threshold, const ResourceStatsOptions& statsOptions, const ResourceStatsAlarmOptions& alarmOptions, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<Promise> GetAlarms(const ResourceStatsOptions& statsOptions, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<Promise> RemoveAlarm(uint32_t alarmId, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<Promise> RemoveAllAlarms(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<Promise> GetAvailableComponents(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void __Init(ResourceType type, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  inline bool
  operator==(const ResourceStatsManagerJSImpl& aOther) const
  {
    return CallbackInterface::operator==(aOther);
  }

  void GetResourceTypes(nsTArray<nsString>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  uint32_t GetSampleRate(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  uint64_t GetMaxStorageAge(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

private:
  static bool
  InitIds(JSContext* cx, ResourceStatsManagerAtoms* atomsCache);
};


class ResourceStatsManager final : public nsSupportsWeakReference,
                                   public nsWrapperCache
{
public:
  NS_DECL_CYCLE_COLLECTING_ISUPPORTS
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS(ResourceStatsManager)

private:
  RefPtr<ResourceStatsManagerJSImpl> mImpl;
  nsCOMPtr<nsISupports> mParent;

public:
  ResourceStatsManager(JS::Handle<JSObject*> aJSImplObject, nsIGlobalObject* aParent);

private:
  ~ResourceStatsManager();

public:
  nsISupports* GetParentObject() const;

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aGivenProto) override;

  static already_AddRefed<ResourceStatsManager> Constructor(const GlobalObject& global, JSContext* cx, ResourceType type, ErrorResult& aRv);

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<Promise> GetStats(const ResourceStatsOptions& statsOptions, const Nullable<uint64_t>& start, const Nullable<uint64_t>& end, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<Promise> ClearStats(const ResourceStatsOptions& statsOptions, const Nullable<uint64_t>& start, const Nullable<uint64_t>& end, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<Promise> ClearAllStats(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<Promise> AddAlarm(uint64_t threshold, const ResourceStatsOptions& statsOptions, const ResourceStatsAlarmOptions& alarmOptions, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<Promise> GetAlarms(const ResourceStatsOptions& statsOptions, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<Promise> RemoveAlarm(uint32_t alarmId, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<Promise> RemoveAllAlarms(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<Promise> GetAvailableComponents(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetResourceTypes(nsTArray<nsString>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  uint32_t GetSampleRate(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  uint64_t GetMaxStorageAge(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  static bool
  _Create(JSContext* cx, unsigned argc, JS::Value* vp);
};


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_ResourceStatsManagerBinding_h