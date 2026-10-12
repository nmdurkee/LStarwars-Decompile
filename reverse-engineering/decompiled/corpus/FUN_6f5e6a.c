/* Ghidra analysis pseudocode, not original source.
 * ev_1492cb0b37f39299053b51444e553a69bb4676d2f076390f93a438e5515ce6e2
 * Entry: 0x6f5e6a; label: _EH4_GlobalUnwind
 */

/* Library Function - Single Match
    @_EH4_GlobalUnwind@4
   
   Library: Visual Studio 2005 Release
   __fastcall _EH4_GlobalUnwind,4 */

void __fastcall _EH4_GlobalUnwind(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x6f5e7f,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}

