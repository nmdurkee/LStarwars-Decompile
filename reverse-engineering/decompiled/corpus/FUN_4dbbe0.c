/* Ghidra analysis pseudocode, not original source.
 * ev_d881831d71d8ed35fa38d5b5eaee7ca2bcae4cde952964886fd1c7ddf43d442a
 * Entry: 0x4dbbe0; label: FUN_004dbbe0
 */

void FUN_004dbbe0(void)

{
  short *psVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int in_EDX;
  uint uVar4;
  int iVar5;
  int *unaff_ESI;
  int *local_8;
  int local_4;
  
  iVar5 = 0;
  if (((in_ECX != 0) && (unaff_ESI != (int *)0x0)) && (in_EDX != 0)) {
    *unaff_ESI = 0;
    unaff_ESI[1] = 0;
    unaff_ESI[2] = 0;
    unaff_ESI[3] = 0;
    psVar1 = (short *)FUN_005d0690(*(undefined4 *)(in_ECX + 0x13c));
    *unaff_ESI = (int)psVar1;
    if (((psVar1 != (short *)0x0) && (DAT_00882418 != 0)) && (DAT_0088241c != 0)) {
      uVar4 = 0;
      if (*psVar1 != 1 && -1 < *psVar1 + -1) {
        local_8 = unaff_ESI + 1;
        local_4 = 0;
        do {
          if (5 < (int)uVar4) break;
          iVar2 = *(int *)(*unaff_ESI + 8) + local_4;
          iVar3 = DAT_00882418;
          if ((uVar4 & 1) == 0) {
            iVar3 = DAT_0088241c;
          }
          iVar2 = FUN_00551170(iVar2,iVar2 + 0xc,*(int *)(iVar3 + 8),*(int *)(iVar3 + 8) + 0xc,0,0);
          if (iVar2 != 0) {
            uVar4 = uVar4 + 1;
            *(short *)local_8 = (short)iVar5;
            local_8 = (int *)((int)local_8 + 2);
          }
          local_4 = local_4 + 0xc;
          iVar5 = iVar5 + 1;
        } while (iVar5 < *(short *)*unaff_ESI + -1);
      }
      if (*(short *)((int)unaff_ESI + 0xe) == 0) {
        *(undefined2 *)((int)unaff_ESI + 0xe) = *(undefined2 *)*unaff_ESI;
      }
    }
  }
  return;
}

