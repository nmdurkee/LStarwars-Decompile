/* Ghidra pseudocode, not original source.
 * ev_2fc6966d7cb88e652aff05d91af92c1aae7a14fbd03261d64dee7cfe7594468f
 * Entry: 0x6d0830; label: FUN_006d0830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d0830(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  float local_8;
  float local_4;
  
  FUN_0061f7e0(&local_4,&local_8);
  local_4 = local_4 * 640.0;
  local_8 = local_8 * 448.0;
  iVar1 = FUN_006d6c20(0xf);
  if (iVar1 == 0) {
    uVar2 = FUN_006e6b90(100,200,DAT_02973a78,FUN_006bc860,0);
    uVar2 = FUN_006e6b90(uVar2);
    iVar1 = FUN_00619250(uVar2);
    if (iVar1 == 0) {
      DAT_02973a7c = iVar1;
      return;
    }
    if (*(int *)(in_ECX + 0x948) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x948) + 0x30))(iVar1);
    }
  }
  else {
    uVar2 = FUN_006e6b90(100,200,DAT_02973a78,FUN_006bc860,"Level Editor");
    uVar2 = FUN_006e6b90(uVar2);
    iVar1 = FUN_00619250(uVar2);
    if (iVar1 == 0) {
      DAT_02973a7c = iVar1;
      return;
    }
    uVar2 = FUN_00627a80(1,&DAT_0081f9a0,0,0,FUN_006cb920,"Editors...");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627a80(0,&DAT_0081f9a0,0,0,FUN_006d07a0,"Options...");
    FUN_00618e10(iVar1,uVar2);
  }
  FUN_006242b0(iVar1,5);
  FUN_00627930(iVar1,1);
  DAT_02973a7c = iVar1;
  return;
}

