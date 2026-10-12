/* Ghidra analysis pseudocode, not original source.
 * ev_05a50d78b1ac39cbc8ac7a43523eae9528fc8f40ae743077c5c3f4eab8d21813
 * Entry: 0x6e725d; label: fast_error_exit
 */

/* Library Function - Single Match
    _fast_error_exit
   
   Library: Visual Studio 2005 Release */

void __cdecl fast_error_exit(undefined4 param_1)

{
  if (DAT_0297c190 == 1) {
    __FF_MSGBANNER();
  }
  FUN_006f09f8(param_1);
  ___crtExitProcess(0xff);
  return;
}

