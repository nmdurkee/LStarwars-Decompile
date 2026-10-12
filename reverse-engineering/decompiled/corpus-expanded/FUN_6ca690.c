/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6ca690; label: FUN_006ca690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ca690(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_a4 [4];
  int local_a0;
  int local_9c;
  undefined1 auStack_98 [132];
  uint local_14;
  
  local_14 = DAT_00829570 ^ (uint)auStack_a4;
  iVar3 = *(int *)(param_2 + 0xc);
  local_9c = param_1;
  if ((iVar3 < 0) || (DAT_02973bac <= iVar3)) {
    local_a0 = 0;
  }
  else {
    local_a0 = DAT_02973b90 + iVar3 * 0x18;
  }
  iVar3 = local_a0;
  *(int *)(DAT_02973a44 + 0x10) = local_a0;
  piVar1 = (int *)FUN_00619250(*(int *)(param_2 + 0x1c) + *(int *)(param_1 + 0x1c),
                               *(undefined4 *)(param_2 + 0x20),0xb4,0xfa,DAT_02973a78,FUN_006bc860,0
                              );
  if (piVar1 != (int *)0x0) {
    piVar2 = (int *)FUN_006c69a0(2,1);
    if (piVar2 != (int *)0x0) {
      for (iVar3 = (**(code **)(**(int **)(iVar3 + 0x14) + 0x14))(0); iVar3 != 0;
          iVar3 = (**(code **)(**(int **)(local_a0 + 0x14) + 0x14))(iVar3)) {
        if ((*(byte *)(piVar2 + 7) & 2) != 0) {
          (**(code **)(*piVar2 + 4))(iVar3,DAT_02973ac4,auStack_98,0x80);
          uVar4 = FUN_00627a80(iVar3,&DAT_0081f9a0,0,0,&LAB_006ca5b0,auStack_98);
          FUN_00618e10(piVar1,uVar4);
        }
      }
    }
    if (*piVar1 == 0) {
      uVar4 = FUN_00627a80(0,&DAT_0081f9a0,0,0,FUN_006bc8c0,"No Object");
      FUN_00618e10(piVar1,uVar4);
    }
    piVar1[0xe] = piVar1[0xe] | 1;
    FUN_006279b0(local_9c,piVar1);
    FUN_006271a0(piVar1);
    FUN_006242b0(piVar1,5);
    FUN_00627930(piVar1,5);
  }
  __security_check_cookie(local_14 ^ (uint)auStack_a4);
  return;
}

