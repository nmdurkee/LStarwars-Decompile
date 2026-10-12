/* Ghidra analysis pseudocode, not original source.
 * ev_9e834adbd1be5074ad62417c72633ab4044f13767a5707860f49455a6f85e9eb
 * Entry: 0x403ea0; label: FUN_00403ea0
 */

undefined4 FUN_00403ea0(undefined1 param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_EDI == 0) {
    return 0;
  }
  bVar1 = *(byte *)(unaff_ESI + 0x1f);
  if (4 < bVar1) {
    iVar2 = FUN_006e6b90();
    iVar3 = FUN_006e6b90();
    if (iVar3 == iVar2) {
      return 1;
    }
    if (bVar1 != 1 && -1 < (int)(bVar1 - 1)) {
      iVar2 = 0;
      puVar4 = unaff_ESI;
      do {
        *puVar4 = puVar4[5];
        puVar4[1] = puVar4[6];
        puVar4[2] = puVar4[7];
        puVar4[3] = puVar4[8];
        puVar4[4] = puVar4[9];
        iVar2 = iVar2 + 1;
        puVar4 = puVar4 + 5;
      } while (iVar2 < (int)(*(byte *)(unaff_ESI + 0x1f) - 1));
    }
    *(char *)(unaff_ESI + 0x1f) = *(char *)(unaff_ESI + 0x1f) + -1;
  }
  unaff_ESI[(uint)*(byte *)(unaff_ESI + 0x1f) * 5] = unaff_EDI;
  *(undefined1 *)(unaff_ESI + (uint)*(byte *)(unaff_ESI + 0x1f) * 5 + 1) = param_1;
  *(undefined1 *)((int)unaff_ESI + (uint)*(byte *)(unaff_ESI + 0x1f) * 0x14 + 5) = 0;
  *(char *)(unaff_ESI + 0x1f) = *(char *)(unaff_ESI + 0x1f) + '\x01';
  return 2;
}

