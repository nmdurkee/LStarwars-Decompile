/* Ghidra analysis pseudocode, not original source.
 * ev_22c3a398bc6b82f0935d4925f42062b7808fee9576bfee9324dc2ce76fb66214
 * Entry: 0x741f70; label: FUN_00741f70
 */

undefined4 FUN_00741f70(void)

{
  uint in_EAX;
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xb8 + (in_EAX & 0xff) * 4);
  if (iVar1 != 0) {
    iVar1 = FUN_005e5310(iVar1);
    return *(undefined4 *)(iVar1 + 0x24);
  }
  return 0;
}

