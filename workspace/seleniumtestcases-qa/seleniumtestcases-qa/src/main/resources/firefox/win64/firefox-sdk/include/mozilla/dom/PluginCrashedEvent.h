/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim:set ts=2 sw=2 sts=2 et cindent: */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/* THIS FILE IS AUTOGENERATED FROM PluginCrashedEvent.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_PluginCrashedEvent_h
#define mozilla_dom_PluginCrashedEvent_h

#include "mozilla/Attributes.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/Event.h"
#include "mozilla/dom/PluginCrashedEventBinding.h"

struct JSContext;
namespace mozilla {
namespace dom {

class PluginCrashedEvent : public Event
{
public:
  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS_INHERITED(PluginCrashedEvent, Event)
protected:
  virtual ~PluginCrashedEvent();
  explicit PluginCrashedEvent(mozilla::dom::EventTarget* aOwner);

  uint32_t mPluginID;
  nsString mPluginDumpID;
  nsString mPluginName;
  nsString mBrowserDumpID;
  nsString mPluginFilename;
  bool mSubmittedCrashReport;
  bool mGmpPlugin;

public:
  virtual PluginCrashedEvent* AsPluginCrashedEvent() override;

  virtual JSObject* WrapObjectInternal(JSContext* aCx, JS::Handle<JSObject*> aGivenProto) override;

  static already_AddRefed<PluginCrashedEvent> Constructor(mozilla::dom::EventTarget* aOwner, const nsAString& aType, const PluginCrashedEventInit& aEventInitDict);

  static already_AddRefed<PluginCrashedEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const PluginCrashedEventInit& aEventInitDict, ErrorResult& aRv);

  uint32_t PluginID() const;

  void GetPluginDumpID(nsString& aRetVal) const;

  void GetPluginName(nsString& aRetVal) const;

  void GetBrowserDumpID(nsString& aRetVal) const;

  void GetPluginFilename(nsString& aRetVal) const;

  bool SubmittedCrashReport() const;

  bool GmpPlugin() const;
};

} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_PluginCrashedEvent_h
