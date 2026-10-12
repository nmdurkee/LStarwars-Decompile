/* Ghidra analysis pseudocode, not original source.
 * ev_a56cd9785cea8d5ba50d25e7433193a9772fbb2aad70e3222a3c6b4dc2863d32
 * Entry: 0x6e0030; label: FUN_006e0030
 */

void FUN_006e0030(int param_1,char *param_2)

{
  if (param_2 != (char *)0x0) {
    _vsprintf(&DAT_0297b698,param_2,&stack0x0000000c);
  }
  _sprintf(&DAT_0297ae98,"NUDEBUG: %s",&DAT_0297b698);
  if (*(char *)(param_1 + 1) != '\0') {
    OutputDebugStringA(&DAT_0297ae98);
  }
  return;
}

