////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2006 - 2021, Tomas Babej, Paul Beckingham, Federico Hernandez.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// https://www.opensource.org/licenses/mit-license.php
//
////////////////////////////////////////////////////////////////////////////////

#include <cmake.h>
// cmake.h include header must come first

#include <CmdAliases.h>
#include <Command.h>
#include <Context.h>

////////////////////////////////////////////////////////////////////////////////
CmdCompletionAliases::CmdCompletionAliases() {
  _keyword = "_aliases";
  _usage = "task          _aliases";
  _description = "Generates a list of all aliases, for autocompletion purposes";
  _read_only = true;
  _displays_id = false;
  _needs_gc = false;
  _uses_context = false;
  _accepts_filter = false;
  _accepts_modifications = false;
  _accepts_miscellaneous = false;
  _category = Command::Category::internal;
}

////////////////////////////////////////////////////////////////////////////////
int CmdCompletionAliases::execute(std::string& output) {
  for (const auto& alias : Context::getContext().config)
    if (alias.first.substr(0, 6) == "alias.") output += alias.first.substr(6) + '\n';

  return 0;
}

////////////////////////////////////////////////////////////////////////////////
