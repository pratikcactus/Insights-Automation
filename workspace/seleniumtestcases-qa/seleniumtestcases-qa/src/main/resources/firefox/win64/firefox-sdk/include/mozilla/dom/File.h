/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef mozilla_dom_File_h
#define mozilla_dom_File_h

#include "mozilla/Attributes.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/GuardObjects.h"
#include "mozilla/LinkedList.h"
#include "mozilla/StaticMutex.h"
#include "mozilla/StaticPtr.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/Date.h"
#include "nsAutoPtr.h"
#include "nsCycleCollectionParticipant.h"
#include "nsCOMPtr.h"
#include "nsIDOMBlob.h"
#include "nsIFile.h"
#include "nsIMutable.h"
#include "nsIXMLHttpRequest.h"
#include "nsString.h"
#include "nsTemporaryFileInputStream.h"
#include "nsWrapperCache.h"
#include "nsWeakReference.h"

class nsIFile;
class nsIInputStream;

#define BLOBIMPL_IID \
  { 0xbccb3275, 0x6778, 0x4ac5, \
    { 0xaf, 0x03, 0x90, 0xed, 0x37, 0xad, 0xdf, 0x5d } }

namespace mozilla {
namespace dom {

struct BlobPropertyBag;
struct ChromeFilePropertyBag;
struct FilePropertyBag;
class BlobImpl;
class File;
class OwningArrayBufferOrArrayBufferViewOrBlobOrString;

/**
 * Used to indicate when a Blob/BlobImpl that was created from an nsIFile
 * (when IsFile() will return true) was from an nsIFile for which
 * nsIFile::IsDirectory() returned true. This is a tri-state to enable us to
 * assert that the state is always set when callers request it.
 */
enum BlobDirState : uint32_t {
  eIsDir,
  eIsNotDir,
  eUnknownIfDir
};

class Blob : public nsIDOMBlob
           , public nsIXHRSendable
           , public nsIMutable
           , public nsSupportsWeakReference
           , public nsWrapperCache
{
public:
  NS_DECL_NSIDOMBLOB
  NS_DECL_NSIXHRSENDABLE
  NS_DECL_NSIMUTABLE

  NS_DECL_CYCLE_COLLECTING_ISUPPORTS
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS_AMBIGUOUS(Blob, nsIDOMBlob)

  // This creates a Blob or a File based on the type of BlobImpl.
  static Blob*
  Create(nsISupports* aParent, BlobImpl* aImpl);

  static already_AddRefed<Blob>
  Create(nsISupports* aParent, const nsAString& aContentType,
         uint64_t aLength);

  static already_AddRefed<Blob>
  Create(nsISupports* aParent, const nsAString& aContentType, uint64_t aStart,
         uint64_t aLength);

  // The returned Blob takes ownership of aMemoryBuffer. aMemoryBuffer will be
  // freed by free so it must be allocated by malloc or something
  // compatible with it.
  static already_AddRefed<Blob>
  CreateMemoryBlob(nsISupports* aParent, void* aMemoryBuffer, uint64_t aLength,
                   const nsAString& aContentType);

  static already_AddRefed<Blob>
  CreateTemporaryBlob(nsISupports* aParent, PRFileDesc* aFD,
                      uint64_t aStartPos, uint64_t aLength,
                      const nsAString& aContentType);

  BlobImpl* Impl() const
  {
    return mImpl;
  }

  bool IsFile() const;

  /**
   * This may return true if the Blob was created from an nsIFile that is a
   * directory.
   */
  bool IsDirectory() const;

  const nsTArray<RefPtr<BlobImpl>>* GetSubBlobImpls() const;

  // This method returns null if this Blob is not a File; it returns
  // the same object in case this Blob already implements the File interface;
  // otherwise it returns a new File object with the same BlobImpl.
  already_AddRefed<File> ToFile();

  // XXXjwatt Consider having a ToDirectory() method. The need for a FileSystem
  // object complicates that though.

  // This method creates a new File object with the given name and the same
  // BlobImpl.
  already_AddRefed<File> ToFile(const nsAString& aName,
                                ErrorResult& aRv) const;

  already_AddRefed<Blob>
  CreateSlice(uint64_t aStart, uint64_t aLength, const nsAString& aContentType,
              ErrorResult& aRv);

  void
  GetInternalStream(nsIInputStream** aStream, ErrorResult& aRv);

  int64_t
  GetFileId();

  // WebIDL methods
  nsISupports* GetParentObject() const
  {
    return mParent;
  }

  bool
  IsMemoryFile() const;

  // Blob constructor
  static already_AddRefed<Blob>
  Constructor(const GlobalObject& aGlobal, ErrorResult& aRv);

  // Blob constructor
  static already_AddRefed<Blob>
  Constructor(const GlobalObject& aGlobal,
              const Sequence<OwningArrayBufferOrArrayBufferViewOrBlobOrString>& aData,
              const BlobPropertyBag& aBag,
              ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx,
                               JS::Handle<JSObject*> aGivenProto) override;

  uint64_t GetSize(ErrorResult& aRv);

  void GetType(nsAString& aType);

  already_AddRefed<Blob> Slice(const Optional<int64_t>& aStart,
                               const Optional<int64_t>& aEnd,
                               const nsAString& aContentType,
                               ErrorResult& aRv);

protected:
  // File constructor should never be used directly. Use Blob::Create instead.
  Blob(nsISupports* aParent, BlobImpl* aImpl);
  virtual ~Blob() {};

  virtual bool HasFileInterface() const { return false; }

  // The member is the real backend implementation of this File/Blob.
  // It's thread-safe and not CC-able and it's the only element that is moved
  // between threads.
  // Note: we should not store any other state in this class!
  RefPtr<BlobImpl> mImpl;

private:
  nsCOMPtr<nsISupports> mParent;
};

class File final : public Blob
{
  friend class Blob;

public:
  // Note: BlobImpl must be a File in order to use this method.
  // Check impl->IsFile().
  static File*
  Create(nsISupports* aParent, BlobImpl* aImpl);

  static already_AddRefed<File>
  Create(nsISupports* aParent, const nsAString& aName,
         const nsAString& aContentType, uint64_t aLength,
         int64_t aLastModifiedDate, BlobDirState aDirState);

  // The returned File takes ownership of aMemoryBuffer. aMemoryBuffer will be
  // freed by free so it must be allocated by malloc or something
  // compatible with it.
  static already_AddRefed<File>
  CreateMemoryFile(nsISupports* aParent, void* aMemoryBuffer, uint64_t aLength,
                   const nsAString& aName, const nsAString& aContentType,
                   int64_t aLastModifiedDate);

  static already_AddRefed<File>
  CreateFromFile(nsISupports* aParent, nsIFile* aFile, bool aTemporary = false);

  static already_AddRefed<File>
  CreateFromFile(nsISupports* aParent, nsIFile* aFile, const nsAString& aName,
                 const nsAString& aContentType);

  // WebIDL methods

  virtual JSObject* WrapObject(JSContext *cx,
                               JS::Handle<JSObject*> aGivenProto) override;

  // File constructor
  static already_AddRefed<File>
  Constructor(const GlobalObject& aGlobal,
              const Sequence<OwningArrayBufferOrArrayBufferViewOrBlobOrString>& aData,
              const nsAString& aName,
              const FilePropertyBag& aBag,
              ErrorResult& aRv);

  // File constructor - ChromeOnly
  static already_AddRefed<File>
  Constructor(const GlobalObject& aGlobal,
              Blob& aData,
              const ChromeFilePropertyBag& aBag,
              ErrorResult& aRv);

  // File constructor - ChromeOnly
  static already_AddRefed<File>
  Constructor(const GlobalObject& aGlobal,
              const nsAString& aData,
              const ChromeFilePropertyBag& aBag,
              ErrorResult& aRv);

  // File constructor - ChromeOnly
  static already_AddRefed<File>
  Constructor(const GlobalObject& aGlobal,
              nsIFile* aData,
              const ChromeFilePropertyBag& aBag,
              ErrorResult& aRv);

  void GetName(nsAString& aName);

  int64_t GetLastModified(ErrorResult& aRv);

  Date GetLastModifiedDate(ErrorResult& aRv);

  void GetPath(nsAString& aName, ErrorResult& aRv);

  void GetMozFullPath(nsAString& aFilename, ErrorResult& aRv) const;

  void GetMozFullPathInternal(nsAString& aName, ErrorResult& aRv) const;

protected:
  virtual bool HasFileInterface() const override { return true; }

private:
  // File constructor should never be used directly. Use Blob::Create or
  // File::Create.
  File(nsISupports* aParent, BlobImpl* aImpl);
  ~File() {};
};

// This is the abstract class for any File backend. It must be nsISupports
// because this class must be ref-counted and it has to work with IPC.
class BlobImpl : public nsISupports
{
public:
  NS_DECLARE_STATIC_IID_ACCESSOR(BLOBIMPL_IID)
  NS_DECL_THREADSAFE_ISUPPORTS

  BlobImpl() {}

  virtual void GetName(nsAString& aName) = 0;

  virtual void GetPath(nsAString& aName, ErrorResult& aRv) = 0;

  virtual int64_t GetLastModified(ErrorResult& aRv) = 0;

  virtual void SetLastModified(int64_t aLastModified) = 0;

  virtual void GetMozFullPath(nsAString& aName, ErrorResult& aRv) const = 0;

  virtual void GetMozFullPathInternal(nsAString& aFileName, ErrorResult& aRv) const = 0;

  virtual uint64_t GetSize(ErrorResult& aRv) = 0;

  virtual void GetType(nsAString& aType) = 0;

  /**
   * An effectively-unique serial number identifying this instance of FileImpl.
   *
   * Implementations should obtain a serial number from
   * FileImplBase::NextSerialNumber().
   */
  virtual uint64_t GetSerialNumber() const = 0;

  already_AddRefed<BlobImpl>
  Slice(const Optional<int64_t>& aStart, const Optional<int64_t>& aEnd,
        const nsAString& aContentType, ErrorResult& aRv);

  virtual already_AddRefed<BlobImpl>
  CreateSlice(uint64_t aStart, uint64_t aLength,
              const nsAString& aContentType, ErrorResult& aRv) = 0;

  virtual const nsTArray<RefPtr<BlobImpl>>*
  GetSubBlobImpls() const = 0;

  virtual void GetInternalStream(nsIInputStream** aStream,
                                 ErrorResult& aRv) = 0;

  virtual int64_t GetFileId() = 0;

  virtual nsresult GetSendInfo(nsIInputStream** aBody,
                               uint64_t* aContentLength,
                               nsACString& aContentType,
                               nsACString& aCharset) = 0;

  virtual nsresult GetMutable(bool* aMutable) const = 0;

  virtual nsresult SetMutable(bool aMutable) = 0;

  virtual void SetLazyData(const nsAString& aName,
                           const nsAString& aContentType,
                           uint64_t aLength,
                           int64_t aLastModifiedDate) = 0;

  virtual bool IsMemoryFile() const = 0;

  virtual bool IsSizeUnknown() const = 0;

  virtual bool IsDateUnknown() const = 0;

  virtual bool IsFile() const = 0;

  /**
   * Called when this BlobImpl was created from an nsIFile in order to call
   * nsIFile::IsDirectory() and cache the result so that when the BlobImpl is
   * copied to another process that informaton is available.
   * nsIFile::IsDirectory() does synchronous I/O, and BlobImpl objects may be
   * created on the main thread or in a non-chrome process (where I/O is not
   * allowed). Do not call this on a non-chrome process, and preferably do not
   * call it on the main thread.
   *
   * Not all creators of BlobImplFile will call this method, in which case
   * calling IsDirectory will MOZ_ASSERT.
   */
  virtual void LookupAndCacheIsDirectory() = 0;
  virtual void SetIsDirectory(bool aIsDir) = 0;
  virtual bool IsDirectory() const = 0;

  /**
   * Prefer IsDirectory(). This exists to help consumer code pass on state from
   * one BlobImpl when creating another.
   */
  virtual BlobDirState GetDirState() const = 0;

  // True if this implementation can be sent to other threads.
  virtual bool MayBeClonedToOtherThreads() const
  {
    return true;
  }

protected:
  virtual ~BlobImpl() {}
};

NS_DEFINE_STATIC_IID_ACCESSOR(BlobImpl, BLOBIMPL_IID)

class BlobImplBase : public BlobImpl
{
public:
  BlobImplBase(const nsAString& aName, const nsAString& aContentType,
               uint64_t aLength, int64_t aLastModifiedDate,
               BlobDirState aDirState = BlobDirState::eUnknownIfDir)
    : mIsFile(true)
    , mImmutable(false)
    , mDirState(aDirState)
    , mContentType(aContentType)
    , mName(aName)
    , mStart(0)
    , mLength(aLength)
    , mLastModificationDate(aLastModifiedDate)
    , mSerialNumber(NextSerialNumber())
  {
    // Ensure non-null mContentType by default
    mContentType.SetIsVoid(false);
  }

  BlobImplBase(const nsAString& aName, const nsAString& aContentType,
               uint64_t aLength)
    : mIsFile(true)
    , mImmutable(false)
    , mDirState(BlobDirState::eUnknownIfDir)
    , mContentType(aContentType)
    , mName(aName)
    , mStart(0)
    , mLength(aLength)
    , mLastModificationDate(INT64_MAX)
    , mSerialNumber(NextSerialNumber())
  {
    // Ensure non-null mContentType by default
    mContentType.SetIsVoid(false);
  }

  BlobImplBase(const nsAString& aContentType, uint64_t aLength)
    : mIsFile(false)
    , mImmutable(false)
    , mDirState(BlobDirState::eUnknownIfDir)
    , mContentType(aContentType)
    , mStart(0)
    , mLength(aLength)
    , mLastModificationDate(INT64_MAX)
    , mSerialNumber(NextSerialNumber())
  {
    // Ensure non-null mContentType by default
    mContentType.SetIsVoid(false);
  }

  BlobImplBase(const nsAString& aContentType, uint64_t aStart,
               uint64_t aLength)
    : mIsFile(false)
    , mImmutable(false)
    , mDirState(BlobDirState::eUnknownIfDir)
    , mContentType(aContentType)
    , mStart(aStart)
    , mLength(aLength)
    , mLastModificationDate(INT64_MAX)
    , mSerialNumber(NextSerialNumber())
  {
    NS_ASSERTION(aLength != UINT64_MAX,
                 "Must know length when creating slice");
    // Ensure non-null mContentType by default
    mContentType.SetIsVoid(false);
  }

  virtual void GetName(nsAString& aName) override;

  virtual void GetPath(nsAString& aName, ErrorResult& aRv) override;

  virtual int64_t GetLastModified(ErrorResult& aRv) override;

  virtual void SetLastModified(int64_t aLastModified) override;

  virtual void GetMozFullPath(nsAString& aName, ErrorResult& aRv) const override;

  virtual void GetMozFullPathInternal(nsAString& aFileName,
                                      ErrorResult& aRv) const override;

  virtual uint64_t GetSize(ErrorResult& aRv) override
  {
    return mLength;
  }

  virtual void GetType(nsAString& aType) override;

  virtual uint64_t GetSerialNumber() const override { return mSerialNumber; }

  virtual already_AddRefed<BlobImpl>
  CreateSlice(uint64_t aStart, uint64_t aLength,
              const nsAString& aContentType, ErrorResult& aRv) override
  {
    return nullptr;
  }

  virtual const nsTArray<RefPtr<BlobImpl>>*
  GetSubBlobImpls() const override
  {
    return nullptr;
  }

  virtual void GetInternalStream(nsIInputStream** aStream,
                                 ErrorResult& aRv) override
  {
    aRv.Throw(NS_ERROR_NOT_IMPLEMENTED);
  }

  virtual int64_t GetFileId() override;

  virtual nsresult GetSendInfo(nsIInputStream** aBody,
                               uint64_t* aContentLength,
                               nsACString& aContentType,
                               nsACString& aCharset) override;

  virtual nsresult GetMutable(bool* aMutable) const override;

  virtual nsresult SetMutable(bool aMutable) override;

  virtual void
  SetLazyData(const nsAString& aName, const nsAString& aContentType,
              uint64_t aLength, int64_t aLastModifiedDate) override
  {
    mName = aName;
    mContentType = aContentType;
    mLength = aLength;
    mLastModificationDate = aLastModifiedDate;
    mIsFile = !aName.IsVoid();
  }

  virtual bool IsMemoryFile() const override
  {
    return false;
  }

  virtual bool IsDateUnknown() const override
  {
    return mIsFile && mLastModificationDate == INT64_MAX;
  }

  virtual bool IsFile() const override
  {
    return mIsFile;
  }

  virtual void LookupAndCacheIsDirectory() override
  {
    MOZ_ASSERT(false, "Why is this being called on a non-BlobImplFile?");
  }

  virtual void SetIsDirectory(bool aIsDir) override
  {
    MOZ_ASSERT(mIsFile,
               "This should only be called when this object has been created "
               "from an nsIFile to note that the nsIFile is a directory");
    mDirState = aIsDir ? BlobDirState::eIsDir : BlobDirState::eIsNotDir;
  }

  /**
   * Returns true if the nsIFile that this object wraps is a directory.
   */
  virtual bool IsDirectory() const override
  {
    MOZ_ASSERT(mDirState != BlobDirState::eUnknownIfDir,
               "Must only be used by callers for whom the code paths are "
               "know to call LookupAndCacheIsDirectory() or "
               "SetIsDirectory()");
    return mDirState == BlobDirState::eIsDir;
  }

  virtual BlobDirState GetDirState() const override
  {
    return mDirState;
  }

  virtual bool IsSizeUnknown() const override
  {
    return mLength == UINT64_MAX;
  }

protected:
  virtual ~BlobImplBase() {}

  /**
   * Returns a new, effectively-unique serial number. This should be used
   * by implementations to obtain a serial number for GetSerialNumber().
   * The implementation is thread safe.
   */
  static uint64_t NextSerialNumber();

  bool mIsFile;
  bool mImmutable;
  BlobDirState mDirState;

  nsString mContentType;
  nsString mName;
  nsString mPath; // The path relative to a directory chosen by the user

  uint64_t mStart;
  uint64_t mLength;

  int64_t mLastModificationDate;

  const uint64_t mSerialNumber;
};

/**
 * This class may be used off the main thread, and in particular, its
 * constructor and destructor may not run on the same thread.  Be careful!
 */
class BlobImplMemory final : public BlobImplBase
{
public:
  NS_DECL_ISUPPORTS_INHERITED

  BlobImplMemory(void* aMemoryBuffer, uint64_t aLength, const nsAString& aName,
                 const nsAString& aContentType, int64_t aLastModifiedDate)
    : BlobImplBase(aName, aContentType, aLength, aLastModifiedDate,
                   BlobDirState::eIsNotDir)
    , mDataOwner(new DataOwner(aMemoryBuffer, aLength))
  {
    NS_ASSERTION(mDataOwner && mDataOwner->mData, "must have data");
  }

  BlobImplMemory(void* aMemoryBuffer, uint64_t aLength,
                 const nsAString& aContentType)
    : BlobImplBase(aContentType, aLength)
    , mDataOwner(new DataOwner(aMemoryBuffer, aLength))
  {
    NS_ASSERTION(mDataOwner && mDataOwner->mData, "must have data");
  }

  virtual void GetInternalStream(nsIInputStream** aStream,
                                 ErrorResult& aRv) override;

  virtual already_AddRefed<BlobImpl>
  CreateSlice(uint64_t aStart, uint64_t aLength,
              const nsAString& aContentType, ErrorResult& aRv) override;

  virtual bool IsMemoryFile() const override
  {
    return true;
  }

  class DataOwner final : public mozilla::LinkedListElement<DataOwner>
  {
  public:
    NS_INLINE_DECL_THREADSAFE_REFCOUNTING(DataOwner)
    DataOwner(void* aMemoryBuffer, uint64_t aLength)
      : mData(aMemoryBuffer)
      , mLength(aLength)
    {
      mozilla::StaticMutexAutoLock lock(sDataOwnerMutex);

      if (!sDataOwners) {
        sDataOwners = new mozilla::LinkedList<DataOwner>();
        EnsureMemoryReporterRegistered();
      }
      sDataOwners->insertBack(this);
    }

  private:
    // Private destructor, to discourage deletion outside of Release():
    ~DataOwner() {
      mozilla::StaticMutexAutoLock lock(sDataOwnerMutex);

      remove();
      if (sDataOwners->isEmpty()) {
        // Free the linked list if it's empty.
        sDataOwners = nullptr;
      }

      free(mData);
    }

  public:
    static void EnsureMemoryReporterRegistered();

    // sDataOwners and sMemoryReporterRegistered may only be accessed while
    // holding sDataOwnerMutex!  You also must hold the mutex while touching
    // elements of the linked list that DataOwner inherits from.
    static mozilla::StaticMutex sDataOwnerMutex;
    static mozilla::StaticAutoPtr<mozilla::LinkedList<DataOwner> > sDataOwners;
    static bool sMemoryReporterRegistered;

    void* mData;
    uint64_t mLength;
  };

private:
  // Create slice
  BlobImplMemory(const BlobImplMemory* aOther, uint64_t aStart,
                 uint64_t aLength, const nsAString& aContentType)
    : BlobImplBase(aContentType, aOther->mStart + aStart, aLength)
    , mDataOwner(aOther->mDataOwner)
  {
    NS_ASSERTION(mDataOwner && mDataOwner->mData, "must have data");
    mImmutable = aOther->mImmutable;
  }

  ~BlobImplMemory() {}

  // Used when backed by a memory store
  RefPtr<DataOwner> mDataOwner;
};

class BlobImplTemporaryBlob final : public BlobImplBase
{
public:
  NS_DECL_ISUPPORTS_INHERITED

  BlobImplTemporaryBlob(PRFileDesc* aFD, uint64_t aStartPos,
                        uint64_t aLength, const nsAString& aContentType)
    : BlobImplBase(aContentType, aLength)
    , mStartPos(aStartPos)
  {
    mFileDescOwner = new nsTemporaryFileInputStream::FileDescOwner(aFD);
  }

  virtual void GetInternalStream(nsIInputStream** aStream,
                                 ErrorResult& aRv) override;

  virtual already_AddRefed<BlobImpl>
  CreateSlice(uint64_t aStart, uint64_t aLength,
              const nsAString& aContentType, ErrorResult& aRv) override;

private:
  BlobImplTemporaryBlob(const BlobImplTemporaryBlob* aOther,
                        uint64_t aStart, uint64_t aLength,
                        const nsAString& aContentType)
    : BlobImplBase(aContentType, aLength)
    , mStartPos(aStart)
    , mFileDescOwner(aOther->mFileDescOwner)
  {}

  ~BlobImplTemporaryBlob() {}

  uint64_t mStartPos;
  RefPtr<nsTemporaryFileInputStream::FileDescOwner> mFileDescOwner;
};

class BlobImplFile : public BlobImplBase
{
public:
  NS_DECL_ISUPPORTS_INHERITED

  // Create as a file
  explicit BlobImplFile(nsIFile* aFile, bool aTemporary = false)
    : BlobImplBase(EmptyString(), EmptyString(), UINT64_MAX, INT64_MAX)
    , mFile(aFile)
    , mWholeFile(true)
    , mIsTemporary(aTemporary)
  {
    NS_ASSERTION(mFile, "must have file");
    // Lazily get the content type and size
    mContentType.SetIsVoid(true);
    mFile->GetLeafName(mName);
  }

  // Create as a file
  BlobImplFile(const nsAString& aName, const nsAString& aContentType,
               uint64_t aLength, nsIFile* aFile)
    : BlobImplBase(aName, aContentType, aLength, UINT64_MAX)
    , mFile(aFile)
    , mWholeFile(true)
    , mIsTemporary(false)
  {
    NS_ASSERTION(mFile, "must have file");
  }

  BlobImplFile(const nsAString& aName, const nsAString& aContentType,
               uint64_t aLength, nsIFile* aFile,
               int64_t aLastModificationDate)
    : BlobImplBase(aName, aContentType, aLength, aLastModificationDate)
    , mFile(aFile)
    , mWholeFile(true)
    , mIsTemporary(false)
  {
    NS_ASSERTION(mFile, "must have file");
  }

  // Create as a file with custom name
  BlobImplFile(nsIFile* aFile, const nsAString& aName,
               const nsAString& aContentType)
    : BlobImplBase(aName, aContentType, UINT64_MAX, INT64_MAX)
    , mFile(aFile)
    , mWholeFile(true)
    , mIsTemporary(false)
  {
    NS_ASSERTION(mFile, "must have file");
    if (aContentType.IsEmpty()) {
      // Lazily get the content type and size
      mContentType.SetIsVoid(true);
    }
  }

  // Create as a file to be later initialized
  BlobImplFile()
    : BlobImplBase(EmptyString(), EmptyString(), UINT64_MAX, INT64_MAX)
    , mWholeFile(true)
    , mIsTemporary(false)
  {
    // Lazily get the content type and size
    mContentType.SetIsVoid(true);
    mName.SetIsVoid(true);
  }

  // Overrides
  virtual uint64_t GetSize(ErrorResult& aRv) override;
  virtual void GetType(nsAString& aType) override;
  virtual int64_t GetLastModified(ErrorResult& aRv) override;
  virtual void SetLastModified(int64_t aLastModified) override;
  virtual void GetMozFullPathInternal(nsAString& aFullPath,
                                      ErrorResult& aRv) const override;
  virtual void GetInternalStream(nsIInputStream** aInputStream,
                                 ErrorResult& aRv) override;

  void SetPath(const nsAString& aFullPath);

  virtual void LookupAndCacheIsDirectory() override;

  // We always have size and date for this kind of blob.
  virtual bool IsSizeUnknown() const override { return false; }
  virtual bool IsDateUnknown() const override { return false; }

protected:
  virtual ~BlobImplFile() {
    if (mFile && mIsTemporary) {
      NS_WARNING("In temporary ~BlobImplFile");
      // Ignore errors if any, not much we can do. Clean-up will be done by
      // https://mxr.mozilla.org/mozilla-central/source/xpcom/io/nsAnonymousTemporaryFile.cpp?rev=6c1c7e45c902#127
#ifdef DEBUG
      nsresult rv =
#endif
      mFile->Remove(false);
      NS_WARN_IF_FALSE(NS_SUCCEEDED(rv), "Failed to remove temporary DOMFile.");
    }
  }

private:
  // Create slice
  BlobImplFile(const BlobImplFile* aOther, uint64_t aStart,
               uint64_t aLength, const nsAString& aContentType)
    : BlobImplBase(aContentType, aOther->mStart + aStart, aLength)
    , mFile(aOther->mFile)
    , mWholeFile(false)
    , mIsTemporary(false)
  {
    NS_ASSERTION(mFile, "must have file");
    mImmutable = aOther->mImmutable;
  }

  virtual already_AddRefed<BlobImpl>
  CreateSlice(uint64_t aStart, uint64_t aLength,
              const nsAString& aContentType, ErrorResult& aRv) override;

  nsCOMPtr<nsIFile> mFile;
  bool mWholeFile;
  bool mIsTemporary;
};

class EmptyBlobImpl final : public BlobImplBase
{
public:
  NS_DECL_ISUPPORTS_INHERITED

  explicit EmptyBlobImpl(const nsAString& aContentType)
    : BlobImplBase(aContentType, 0 /* aLength */)
  {}

  virtual void GetInternalStream(nsIInputStream** aStream,
                                 ErrorResult& aRv) override;

  virtual already_AddRefed<BlobImpl>
  CreateSlice(uint64_t aStart, uint64_t aLength,
              const nsAString& aContentType, ErrorResult& aRv) override;

  virtual bool IsMemoryFile() const override
  {
    return true;
  }

private:
  ~EmptyBlobImpl() {}
};

} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_File_h
