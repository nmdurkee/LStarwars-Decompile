/* Ghidra analysis pseudocode, not original source.
 * ev_b2ae0094aac4233f18363a226dc902c019a1728ce7ff5cc7e95ded3ed7c5c2a8
 * Entry: 0x68ed90; label: FUN_0068ed90
 */

void FUN_0068ed90(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  if (DAT_0292fc68 != 0) {
    iVar3 = 0;
    DAT_02961f50 = 0;
    if (0 < *(int *)(DAT_0292fc68 + 0x154)) {
      iVar5 = 0x158;
      do {
        FUN_0067c930((int)*(short *)(iVar5 + DAT_0292fc68));
        iVar3 = iVar3 + 1;
        iVar5 = iVar5 + 2;
      } while (iVar3 < *(int *)(DAT_0292fc68 + 0x154));
    }
    *(undefined4 *)(DAT_0292fc68 + 0x154) = 0;
    iVar3 = 0;
    DAT_0292fc64 = 0;
    if (0 < *(int *)(DAT_0292fc68 + 0xa48c)) {
      iVar2 = 0;
      iVar5 = DAT_0292fc68;
      do {
        puVar4 = *(undefined4 **)(*(int *)(iVar5 + 0x68) + 0x40 + iVar2);
        if (puVar4 != (undefined4 *)0x0) {
          puVar6 = (undefined4 *)(*(int *)(iVar5 + 0x68) + iVar2);
          for (iVar1 = 0x10; iVar5 = DAT_0292fc68, iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar6 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar6 = puVar6 + 1;
          }
        }
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x6c;
      } while (iVar3 < *(int *)(iVar5 + 0xa48c));
    }
  }
  return;
}

