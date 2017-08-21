/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef mozilla_dom_AVInputPort_h
#define mozilla_dom_AVInputPort_h

#include "mozilla/dom/InputPort.h"

namespace mozilla {
namespace dom {

class AVInputPort final : public InputPort
{
public:
  static already_AddRefed<AVInputPort> Create(nsPIDOMWindowInner* aWindow,
                                              nsIInputPortListener* aListener,
                                              nsIInputPortData* aData,
                                              ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext *aCx, JS::Handle<JSObject*> aGivenProto) override;

private:
  explicit AVInputPort(nsPIDOMWindowInner* aWindow);

  ~AVInputPort();
};

} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_AVInputPort_h
