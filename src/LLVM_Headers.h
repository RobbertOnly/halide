#ifndef HALIDE_LLVM_HEADERS_H
#define HALIDE_LLVM_HEADERS_H

#if LLVM_VERSION < 37
#error "Compiling Halide requires LLVM 3.7 or newer"
#endif

// This seems to be required by some LLVM header, which is likely an LLVM bug.
#include <stddef.h>

// No msvc warnings from llvm headers please
#ifdef _MSC_VER
#pragma warning(push, 0)
#endif
#ifdef __GNUC__
#pragma GCC system_header
#endif
#ifdef __clang__
#pragma clang system_header
#endif

#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/SectionMemoryManager.h>
#include <llvm/ExecutionEngine/JITEventListener.h>

#include <llvm/IR/Verifier.h>
#include <llvm/Linker/Linker.h>
#include "llvm/Support/ErrorHandling.h"
#include <llvm/Support/FileSystem.h>
#if LLVM_VERSION >= 40
#include <llvm/Bitcode/BitcodeReader.h>
#include <llvm/Bitcode/BitcodeWriter.h>
#else
#include <llvm/Bitcode/ReaderWriter.h>
#endif
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/DynamicLibrary.h>
#include <llvm/Support/DataExtractor.h>
#include <llvm/Analysis/TargetLibraryInfo.h>
#include <llvm/Target/TargetSubtargetInfo.h>
#include <llvm/Transforms/IPO/PassManagerBuilder.h>
#include <llvm/Transforms/IPO.h>
#include <llvm/Transforms/Utils/ModuleUtils.h>
#include <llvm/Transforms/Utils/SymbolRewriter.h>
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/StringRef.h"
#include <llvm/ADT/StringMap.h>
#include <llvm/Object/ArchiveWriter.h>
#include <llvm/Object/ObjectFile.h>

#if LLVM_VERSION >= 39
#include <llvm/Transforms/Scalar/GVN.h>
#endif

#if LLVM_VERSION >= 40
#include <llvm/Transforms/IPO/AlwaysInliner.h>
#endif

#include <llvm/IR/Value.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/DataLayout.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Intrinsics.h>
#include <llvm/Analysis/TargetTransformInfo.h>
#include <llvm/IR/MDBuilder.h>

// No msvc warnings from llvm headers please
#ifdef _MSC_VER
#pragma warning(pop)
#endif

// llvm may sometimes define NDEBUG, which is annoying, because we always want asserts
#ifdef NDEBUG
#undef NDEBUG
#include <assert.h>
#define NDEBUG
#endif

namespace Halide { namespace Internal {
template <typename T>
typename T::value_type *iterator_to_pointer(T iter) {
    return &*iter;
}
}}


#endif
