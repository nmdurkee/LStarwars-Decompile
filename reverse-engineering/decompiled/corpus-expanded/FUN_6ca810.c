/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6ca810; label: FUN_006ca810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ca810(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  piVar2 = (int *)FUN_00619250(*(int *)(param_1 + 0x1c) + *(int *)(param_2 + 0x1c),
                               *(undefined4 *)(param_2 + 0x20),0xb4,0xfa,DAT_02973a78,FUN_006bc860,0
                              );
  iVar1 = DAT_02973bac;
  DAT_02973a44 = *(undefined4 *)(param_2 + 0xc);
  if (piVar2 != (int *)0x0) {
    iVar6 = 0;
    if (0 < DAT_02973bac) {
      iVar5 = 0;
      do {
        if ((iVar6 < 0) || (DAT_02973bac <= iVar6)) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          puVar3 = (undefined4 *)(iVar5 + DAT_02973b90);
        }
        if (((puVar3[1] & 0x20000000) == 0) && (puVar3[5] != 0)) {
          uVar4 = FUN_00627a80(iVar6,&DAT_0081f9a0,0,0,FUN_006ca690,*puVar3);
          FUN_00618e10(piVar2,uVar4);
        }
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + 0x18;
      } while (iVar6 < iVar1);
    }
    if (*piVar2 == 0) {
      uVar4 = FUN_00627a80(0,&DAT_0081f9a0,0,0,FUN_006bc8c0,"No Registered Classes");
      FUN_00618e10(piVar2,uVar4);
    }
    piVar2[0xe] = piVar2[0xe] | 1;
    FUN_006279b0(param_1,piVar2);
    FUN_006242b0(piVar2,5);
    FUN_00627930(piVar2,5);
    *(uint *)(param_2 + 0x4c) = *(uint *)(param_2 + 0x4c) & 0xfffffff7;
  }
  return;
}

