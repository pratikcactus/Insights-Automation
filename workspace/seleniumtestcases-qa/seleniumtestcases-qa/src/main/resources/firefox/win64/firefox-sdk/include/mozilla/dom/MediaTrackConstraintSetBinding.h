/* THIS FILE IS AUTOGENERATED FROM MediaTrackConstraintSet.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_MediaTrackConstraintSetBinding_h
#define mozilla_dom_MediaTrackConstraintSetBinding_h

#include "js/RootingAPI.h"
#include "jspubtd.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/Nullable.h"
#include "mozilla/dom/UnionTypes.h"

namespace mozilla {
namespace dom {

struct ConstrainBooleanParametersAtoms;
struct ConstrainDOMStringParametersAtoms;
struct ConstrainDoubleRangeAtoms;
struct ConstrainLongRangeAtoms;
struct NativePropertyHooks;
class OwningStringOrStringSequence;
class ProtoAndIfaceCache;
class StringOrStringSequence;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

struct ConstrainBooleanParameters : public DictionaryBase
{
  Optional<bool> mExact;
  Optional<bool> mIdeal;

  ConstrainBooleanParameters();

  explicit inline ConstrainBooleanParameters(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline ConstrainBooleanParameters(const ConstrainBooleanParameters& aOther)
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
  operator=(const ConstrainBooleanParameters& aOther);

private:
  static bool
  InitIds(JSContext* cx, ConstrainBooleanParametersAtoms* atomsCache);
};

namespace binding_detail {
struct FastConstrainBooleanParameters : public ConstrainBooleanParameters
{
  inline FastConstrainBooleanParameters()
    : ConstrainBooleanParameters(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct ConstrainDOMStringParameters : public DictionaryBase
{
  Optional<OwningStringOrStringSequence> mExact;
  Optional<OwningStringOrStringSequence> mIdeal;

  ConstrainDOMStringParameters();

  explicit inline ConstrainDOMStringParameters(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline ConstrainDOMStringParameters(const ConstrainDOMStringParameters& aOther)
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
  operator=(const ConstrainDOMStringParameters& aOther);

private:
  static bool
  InitIds(JSContext* cx, ConstrainDOMStringParametersAtoms* atomsCache);
};

namespace binding_detail {
struct FastConstrainDOMStringParameters : public ConstrainDOMStringParameters
{
  inline FastConstrainDOMStringParameters()
    : ConstrainDOMStringParameters(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct ConstrainDoubleRange : public DictionaryBase
{
  Optional<double> mExact;
  Optional<double> mIdeal;
  Optional<double> mMax;
  Optional<double> mMin;

  ConstrainDoubleRange();

  explicit inline ConstrainDoubleRange(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline ConstrainDoubleRange(const ConstrainDoubleRange& aOther)
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
  operator=(const ConstrainDoubleRange& aOther);

private:
  static bool
  InitIds(JSContext* cx, ConstrainDoubleRangeAtoms* atomsCache);
};

namespace binding_detail {
struct FastConstrainDoubleRange : public ConstrainDoubleRange
{
  inline FastConstrainDoubleRange()
    : ConstrainDoubleRange(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct ConstrainLongRange : public DictionaryBase
{
  Optional<int32_t> mExact;
  Optional<int32_t> mIdeal;
  Optional<int32_t> mMax;
  Optional<int32_t> mMin;

  ConstrainLongRange();

  explicit inline ConstrainLongRange(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline ConstrainLongRange(const ConstrainLongRange& aOther)
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
  operator=(const ConstrainLongRange& aOther);

private:
  static bool
  InitIds(JSContext* cx, ConstrainLongRangeAtoms* atomsCache);
};

namespace binding_detail {
struct FastConstrainLongRange : public ConstrainLongRange
{
  inline FastConstrainLongRange()
    : ConstrainLongRange(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_MediaTrackConstraintSetBinding_h
