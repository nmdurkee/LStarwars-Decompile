/* Ghidra analysis pseudocode, not original source.
 * ev_3de2cf7b8df928d729538760151df11dfb76bb55f80af3b4d4d063063f9aa6a2
 * Entry: 0x57adc0; label: FUN_0057adc0
 */

void FUN_0057adc0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f9e70(param_1);
  if (iVar1 < 0xff) {
    if (iVar1 < 0) {
      *(undefined1 *)(DAT_00951c4c + 0xef) = 0;
      return;
    }
  }
  else {
    iVar1 = 0xfe;
  }
  *(char *)(DAT_00951c4c + 0xef) = (char)iVar1;
  return;
}

