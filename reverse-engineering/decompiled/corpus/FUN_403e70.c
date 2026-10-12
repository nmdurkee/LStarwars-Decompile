/* Ghidra analysis pseudocode, not original source.
 * ev_9e834adbd1be5074ad62417c72633ab4044f13767a5707860f49455a6f85e9eb
 * Entry: 0x403e70; label: FUN_00403e70
 */

bool FUN_00403e70(void)

{
  int iVar1;
  uint uVar2;
  int *in_EDX;
  int unaff_ESI;
  
  uVar2 = (uint)*(byte *)(in_EDX + 0x1f);
  iVar1 = 0;
  if (uVar2 != 0) {
    do {
      if (*in_EDX == unaff_ESI) break;
      iVar1 = iVar1 + 1;
      in_EDX = in_EDX + 5;
    } while (iVar1 < (int)uVar2);
  }
  return iVar1 < (int)uVar2;
}

