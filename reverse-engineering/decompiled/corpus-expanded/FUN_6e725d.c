/* Ghidra pseudocode, not original source.
 * ev_b64bd83017f0ebae738352c8f5b7965ab01e6ce8652f7cf557bf7c06ee96df94
 * Entry: 0x6e725d; label: fast_error_exit
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

