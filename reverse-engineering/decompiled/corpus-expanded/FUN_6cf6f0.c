/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6cf6f0; label: FUN_006cf6f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cf6f0(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  piVar1 = (int *)FUN_00619250(*(int *)(param_1 + 0x1c) + *(int *)(param_2 + 0x1c),
                               *(undefined4 *)(param_2 + 0x20),0xb4,0xfa,DAT_02973a78,FUN_006bc860,0
                              );
  if (piVar1 != (int *)0x0) {
    uVar6 = 0;
    puVar4 = &DAT_02973e9c;
    do {
      if (((uVar6 < 10) && (puVar4 != (undefined *)0x0)) && ((*(uint *)(puVar4 + 0xa4) & 1) != 0)) {
        uVar2 = FUN_00627bc0(uVar6 << 6,&DAT_0081f9a0,
                             (int)(*(uint *)(puVar4 + 0xa4) << 0x1e) >> 0x1f,1,FUN_006c2da0,puVar4);
        FUN_00618e10(piVar1,uVar2);
      }
      puVar4 = puVar4 + 0xa8;
      uVar6 = uVar6 + 1;
    } while ((int)puVar4 < 0x297452c);
    uVar2 = FUN_00626290(0,&DAT_0081f9a0);
    FUN_00618e10(piVar1,uVar2);
    iVar7 = 0;
    if (0 < DAT_02973bac) {
      iVar5 = 0;
      iVar3 = DAT_02973b90;
      do {
        if (((*(uint *)(iVar5 + 4 + iVar3) & 0x20000000) == 0) &&
           (*(int *)(iVar5 + 0x14 + iVar3) != 0)) {
          uVar2 = FUN_00627a80(iVar7,&DAT_0081f9a0,0,0,FUN_006cf540,*(undefined4 *)(iVar5 + iVar3));
          FUN_00618e10(piVar1,uVar2);
          iVar3 = DAT_02973b90;
        }
        iVar7 = iVar7 + 1;
        iVar5 = iVar5 + 0x18;
      } while (iVar7 < DAT_02973bac);
    }
    if (*piVar1 == 0) {
      uVar2 = FUN_00627a80(0,&DAT_0081f9a0,0,0,FUN_006bc8c0,"No Registered Classes");
      FUN_00618e10(piVar1,uVar2);
    }
    FUN_006242b0(piVar1,5);
    FUN_00627930(piVar1,1);
    FUN_006279b0(param_1,piVar1);
    FUN_00619060(piVar1);
  }
  return;
}

