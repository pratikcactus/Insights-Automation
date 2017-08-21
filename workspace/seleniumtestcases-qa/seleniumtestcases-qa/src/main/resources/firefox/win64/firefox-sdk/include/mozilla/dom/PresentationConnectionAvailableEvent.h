/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim:set ts=2 sw=2 sts=2 et cindent: */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/* THIS FILE IS AUTOGENERATED FROM PresentationConnectionAvailableEvent.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_PresentationConnectionAvailableEvent_h
#define mozilla_dom_PresentationConnectionAvailableEvent_h

#include "mozilla/Attributes.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/Event.h"
#include "mozilla/dom/PresentationConnectionAvailableEventBinding.h"

struct JSContext;
namespace mozilla {
namespace dom {

class PresentationConnectionAvailableEvent : public Event
{
public:
  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS_INHERITED(PresentationConnectionAvailableEvent, Event)
protected:
  virtual ~PresentationConnectionAvailableEvent();
  explicit PresentationConnectionAvailableEvent(mozilla::dom::EventTarget* aOwner);

  RefPtr<PresentationConnection> mConnection;

public:
  virtual PresentationConnectionAvailableEvent* AsPresentationConnectionAvailableEvent() override;

  virtual JSObject* WrapObjectInternal(JSContext* aCx, JS::Handle<JSObject*> aGivenProto) override;

  static already_AddRefed<PresentationConnectionAvailableEvent> Constructor(mozilla::dom::EventTarget* aOwner, const nsAString& aType, const PresentationConnectionAvailableEventInit& aEventInitDict);

  static already_AddRefed<PresentationConnectionAvailableEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const PresentationConnectionAvailableEventInit& aEventInitDict, ErrorResult& aRv);

  PresentationConnection* Connection() const;
};

} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_PresentationConnectionAvailableEvent_h