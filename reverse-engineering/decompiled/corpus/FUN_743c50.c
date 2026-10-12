/* Ghidra analysis pseudocode, not original source.
 * ev_22c3a398bc6b82f0935d4925f42062b7808fee9576bfee9324dc2ce76fb66214
 * Entry: 0x743c50; label: FUN_00743c50
 */

void FUN_00743c50(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  FUN_00742280(param_1);
  iVar1 = 0;
  *(undefined4 *)(param_1 + 0x4cc) = 0;
  *(undefined4 *)(param_1 + 0x4d0) = 0;
  puVar2 = (undefined1 *)(param_1 + 0x22);
  do {
    *puVar2 = (char)iVar1;
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 0xc;
  } while (iVar1 < 100);
  return;
}

