/* Ghidra analysis pseudocode, not original source.
 * ev_1492cb0b37f39299053b51444e553a69bb4676d2f076390f93a438e5515ce6e2
 * Entry: 0x6f5e51; label: _EH4_TransferToHandler
 */

/* Library Function - Single Match
    @_EH4_TransferToHandler@8
   
   Library: Visual Studio 2005 Release
   __fastcall _EH4_TransferToHandler,8 */

void __fastcall _EH4_TransferToHandler(code *UNRECOVERED_JUMPTABLE)

{
  __NLG_Notify(1);
                    /* WARNING: Could not recover jumptable at 0x006f5e68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

