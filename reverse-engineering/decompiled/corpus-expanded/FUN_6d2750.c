/* Ghidra pseudocode, not original source.
 * ev_2fc6966d7cb88e652aff05d91af92c1aae7a14fbd03261d64dee7cfe7594468f
 * Entry: 0x6d2750; label: FUN_006d2750
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d2750(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = (int *)FUN_00619250(*(int *)(param_1 + 0x1c) + *(int *)(param_2 + 0x1c),
                               *(undefined4 *)(param_2 + 0x20),0xb4,0xfa,DAT_02973a78,FUN_006bc860,0
                              );
  if (piVar1 != (int *)0x0) {
    iVar4 = 0;
    if (0 < DAT_02973bac) {
      iVar5 = 0;
      iVar3 = DAT_02973b90;
      do {
        if ((*(uint *)(iVar5 + 4 + iVar3) & 0x20000000) == 0) {
          uVar2 = FUN_00627a80(iVar4,&DAT_0081f9a0,0,0,FUN_006d2620,*(undefined4 *)(iVar5 + iVar3));
          FUN_00618e10(piVar1,uVar2);
          iVar3 = DAT_02973b90;
        }
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 0x18;
      } while (iVar4 < DAT_02973bac);
    }
    if (*piVar1 == 0) {
      uVar2 = FUN_00627a80(0,&DAT_0081f9a0,0,0,FUN_006bc8c0,"No Registered Classes");
      FUN_00618e10(piVar1,uVar2);
    }
    FUN_006242b0(piVar1,5);
    FUN_00627930(piVar1,1);
    FUN_006279b0(param_1,piVar1);
  }
  return;
}

