/* Ghidra pseudocode, not original source.
 * ev_8db3786b1d2e9370d3feb832809c6ae27354528dfff9c38ddb75cfb6eefed4ac
 * Entry: 0x6f4c48; label: FUN_006f4c48
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006f4c48(void)

{
  int iVar1;
  EXCEPTION_RECORD local_32c;
  _EXCEPTION_POINTERS local_2dc;
  undefined4 local_2d4;
  
  if (((byte)DAT_00829d70 & 1) != 0) {
    FUN_006f09f8(10);
  }
  iVar1 = FUN_006ed79f();
  if (iVar1 != 0) {
    _raise(0x16);
  }
  if (((byte)DAT_00829d70 & 2) != 0) {
    local_2d4 = 0x10001;
    _memset(&local_32c,0,0x50);
    local_2dc.ExceptionRecord = &local_32c;
    local_2dc.ContextRecord = (PCONTEXT)&local_2d4;
    local_32c.ExceptionCode = 0x40000015;
    SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
    UnhandledExceptionFilter(&local_2dc);
  }
                    /* WARNING: Subroutine does not return */
  __exit(3);
}

