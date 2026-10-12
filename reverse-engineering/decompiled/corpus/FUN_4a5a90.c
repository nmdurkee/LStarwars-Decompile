/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a5a90; label: FUN_004a5a90
 */

void FUN_004a5a90(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_00426de0(param_1 + 0x30,0);
  if ((((((iVar2 != 0) && (DAT_0093b324 != 0)) && (iVar1 = *(int *)(param_1 + 0xd4), iVar1 != 0)) &&
       ((iVar1 == DAT_0093d7f0 || (iVar1 == DAT_0093d7f4)))) &&
      (((*(uint *)(iVar1 + 0x1fc) & 1) != 0 && ((*(uint *)(iVar1 + 0x1fc) & 0x1000) != 0)))) &&
     ((*(char *)(iVar1 + 0x280) == '\0' || (*(char *)(iVar1 + 0x280) == '\x01')))) {
    *(uint *)(iVar2 + 0x24) = *(uint *)(iVar2 + 0x24) | 0x10000;
    *(int *)(iVar2 + 8) = iVar1;
  }
  return;
}

