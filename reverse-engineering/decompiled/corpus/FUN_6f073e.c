/* Ghidra analysis pseudocode, not original source.
 * ev_526838828e273a637259fe0c0b8910ed57fcbb113f7ca97b4fe0b36ecb2b0c42
 * Entry: 0x6f073e; label: FUN_006f073e
 */

uint FUN_006f073e(DWORD param_1)

{
  uint uVar1;
  
  Sleep(param_1);
  uVar1 = param_1 + 1000;
  if (DAT_0297c548 < uVar1) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

