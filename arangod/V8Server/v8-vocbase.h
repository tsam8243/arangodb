////////////////////////////////////////////////////////////////////////////////
/// @brief V8-vocbase bridge
///
/// @file
///
/// DISCLAIMER
///
/// Copyright 2014 ArangoDB GmbH, Cologne, Germany
/// Copyright 2004-2014 triAGENS GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author Dr. Frank Celler
/// @author Copyright 2014, ArangoDB GmbH, Cologne, Germany
/// @author Copyright 2011-2013, triAGENS GmbH, Cologne, Germany
////////////////////////////////////////////////////////////////////////////////

#ifndef ARANGODB_V8SERVER_V8__VOCBASE_H
#define ARANGODB_V8SERVER_V8__VOCBASE_H 1

#include "Basics/Common.h"

#include "V8/v8-globals.h"
#include "ShapedJson/shaped-json.h"
#include "VocBase/document-collection.h"

struct TRI_server_s;
struct TRI_vocbase_s;

namespace triagens {
  namespace aql {
    class QueryRegistry;
  }

  namespace arango {
    class ApplicationV8;
    class CollectionNameResolver;
    class JSLoader;
  }
}

// -----------------------------------------------------------------------------
// --SECTION--                                                  public functions
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @brief parse vertex handle from a v8 value (string | object)
////////////////////////////////////////////////////////////////////////////////

int TRI_ParseVertex (const v8::FunctionCallbackInfo<v8::Value>& args,
                     triagens::arango::CollectionNameResolver const*,
                     TRI_voc_cid_t&,
                     std::unique_ptr<char[]>&,
                     v8::Handle<v8::Value> const);

////////////////////////////////////////////////////////////////////////////////
/// @brief return the private WRP_VOCBASE_COL_TYPE value
////////////////////////////////////////////////////////////////////////////////

int32_t TRI_GetVocBaseColType ();

////////////////////////////////////////////////////////////////////////////////
/// @brief run version check
////////////////////////////////////////////////////////////////////////////////

bool TRI_UpgradeDatabase (TRI_vocbase_t*,
                          triagens::arango::JSLoader*,
                          v8::Handle<v8::Context>);

////////////////////////////////////////////////////////////////////////////////
/// @brief run upgrade check
////////////////////////////////////////////////////////////////////////////////

int TRI_CheckDatabaseVersion (TRI_vocbase_t* vocbase,
                              triagens::arango::JSLoader* startupLoader,
                              v8::Handle<v8::Context> context);

////////////////////////////////////////////////////////////////////////////////
/// @brief reloads routing
////////////////////////////////////////////////////////////////////////////////

void TRI_V8ReloadRouting (v8::Isolate* isolate);

////////////////////////////////////////////////////////////////////////////////
/// @brief creates a TRI_vocbase_t global context
////////////////////////////////////////////////////////////////////////////////

void TRI_InitV8VocBridge (v8::Isolate* isolate,
                          triagens::arango::ApplicationV8*,
                          v8::Handle<v8::Context>,
                          triagens::aql::QueryRegistry*,
                          struct TRI_server_s*,
                          struct TRI_vocbase_s*,
                          triagens::arango::JSLoader*,
                          size_t);

#endif

// -----------------------------------------------------------------------------
// --SECTION--                                                       END-OF-FILE
// -----------------------------------------------------------------------------

// Local Variables:
// mode: outline-minor
// outline-regexp: "/// @brief\\|/// {@inheritDoc}\\|/// @page\\|// --SECTION--\\|/// @\\}"
// End:
