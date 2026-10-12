/* Ghidra analysis pseudocode, not original source.
 * ev_9e834adbd1be5074ad62417c72633ab4044f13767a5707860f49455a6f85e9eb
 * Entry: 0x408960; label: FUN_00408960
 */

void FUN_00408960(int param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *unaff_ESI;
  char *pcVar5;
  
  *(ushort *)((int)unaff_ESI + 0x1ea) = *(ushort *)((int)unaff_ESI + 0x1ea) | 4;
  if (unaff_ESI[1] != 0) {
    puVar1 = (uint *)(unaff_ESI[1] + 0xef4);
    *puVar1 = *puVar1 & 0xffffffdf;
    *(uint *)(unaff_ESI[1] + 0xef4) = *(uint *)(unaff_ESI[1] + 0xef4) & 0xfffffdff;
  }
  if (param_1 == 0) {
    pcVar5 = "TowCable_Detach";
  }
  else {
    pcVar5 = "TowCable_Snap";
  }
  uVar2 = FUN_00650dc0(pcVar5,unaff_ESI + 2,1,0);
  FUN_005478a0(uVar2);
  iVar3 = *unaff_ESI;
  if (iVar3 != 0) {
    if ((iVar3 == DAT_0093d810) || (iVar3 == DAT_0093d814)) {
      FUN_0054a3e0(PTR_DAT_008021b4,0x3f800000,0,1);
    }
    iVar3 = *unaff_ESI;
    if ((iVar3 != 0) && (*(int **)(iVar3 + 0x1040) == unaff_ESI)) {
      *(undefined4 *)(iVar3 + 0x1040) = 0;
      *unaff_ESI = 0;
    }
  }
  iVar3 = 0;
  unaff_ESI[1] = 0;
  if (*(char *)((int)unaff_ESI + 0x1e7) != '\0') {
    piVar4 = unaff_ESI + 0x33;
    do {
      *piVar4 = 0;
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 3;
    } while (iVar3 < (int)(uint)*(byte *)((int)unaff_ESI + 0x1e7));
  }
  return;
}

