/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56afe0; label: FUN_0056afe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056afe0(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_40 [64];
  
  iVar3 = *(int *)(param_1 + 0x50c8);
  if (0 < *(int *)(param_1 + 0x50c0)) {
    iVar4 = 0;
    do {
      uVar1 = *(uint *)(iVar3 + 0x94);
      if ((uVar1 & 0x4000) == 0) {
        *(uint *)(iVar3 + 0x94) = uVar1 & 0xffff7fff;
        if ((uVar1 & 1) != 0) {
          if ((*(uint *)(iVar3 + 0x98) & 0x400) == 0) {
            FUN_00568890(iVar3,auStack_40,0);
            FUN_005f33b0(*(int *)(iVar3 + 0xa4) + 0x3c,auStack_40);
          }
          iVar2 = FUN_005cfac0(*(int *)(iVar3 + 0xa4) + 0x54);
          if (iVar2 != 0) {
            FUN_005f33b0(*(int *)(iVar3 + 0xa4) + 0x54,iVar3);
          }
        }
      }
      else {
        iVar2 = FUN_005f33b0(*(int *)(iVar3 + 0xa4) + 0x30,iVar3);
        *(uint *)(iVar3 + 0x94) =
             *(uint *)(iVar3 + 0x94) ^ (iVar2 << 0xf ^ *(uint *)(iVar3 + 0x94)) & 0x8000;
        if ((*(uint *)(iVar3 + 0x94) & 0x8000) != 0) {
          FUN_005d6430(iVar3 + 0x40,iVar3 + 0x30,1,0);
        }
        if (((((*(uint *)(iVar3 + 0x94) & 0x800000) != 0) &&
             ((*(uint *)(iVar3 + 0x94) & 0x8000) != 0)) && ((*(byte *)(iVar3 + 0x98) & 0x10) != 0))
           && (DAT_00950bc0 != (code *)0x0)) {
          (*DAT_00950bc0)(iVar3);
        }
      }
      if (((*(uint *)(iVar3 + 0x94) & 0x800000) != 0) && ((*(uint *)(iVar3 + 0x98) & 0x20000) == 0))
      {
        iVar2 = FUN_005cfac0(*(int *)(iVar3 + 0xa4) + 0x48);
        if (iVar2 != 0) {
          FUN_00568950(iVar3,auStack_40);
          FUN_005f33b0(*(int *)(iVar3 + 0xa4) + 0x48,iVar3);
        }
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x114;
    } while (iVar4 < *(int *)(param_1 + 0x50c0));
  }
  return;
}

