/* Ghidra pseudocode, not original source.
 * ev_2fc6966d7cb88e652aff05d91af92c1aae7a14fbd03261d64dee7cfe7594468f
 * Entry: 0x6d2620; label: FUN_006d2620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d2620(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  
  iVar1 = *(int *)(param_2 + 0xc);
  if ((iVar1 < 0) || (DAT_02973bac <= iVar1)) {
    iVar3 = 0;
  }
  else {
    iVar3 = DAT_02973b90 + iVar1 * 0x18;
  }
  iVar1 = FUN_006d25b0(iVar1);
  if (iVar1 != 0) {
    FUN_0061e5d0(1);
    if (DAT_02973a7c != 0) {
      if (*(int *)(DAT_02973a7c + 0x40) != 0) {
        *(undefined4 *)(*(int *)(DAT_02973a7c + 0x40) + 0x3c) = 0;
      }
      if (*(int *)(DAT_02973a7c + 0x3c) != 0) {
        *(undefined4 *)(*(int *)(DAT_02973a7c + 0x3c) + 0x40) = 0;
      }
    }
    DAT_02973a88 = 1;
    return;
  }
  iVar1 = FUN_00619250(*(int *)(param_1 + 0x1c) + *(int *)(param_2 + 0x1c),
                       *(undefined4 *)(param_2 + 0x20),0xb4,0xfa,DAT_02973a78,FUN_006bc860,"Error!")
  ;
  if (iVar1 == 0) {
    return;
  }
  uVar2 = FUN_00627a80(1,&DAT_0081f9a0,0,0,FUN_006bc8c0,"Failed to create new object");
  FUN_00618e10(iVar1,uVar2);
  if (iVar3 == 0) {
    pcVar4 = "Unknown class id";
  }
  else {
    if ((*(uint *)(iVar3 + 4) & 0x4000000) == 0) goto LAB_006d272c;
    pcVar4 = "No selected objects to clone";
  }
  uVar2 = FUN_00627a80(1,&DAT_0081f9a0,0,0,FUN_006bc8c0,pcVar4);
  FUN_00618e10(iVar1,uVar2);
LAB_006d272c:
  FUN_006242b0(iVar1,5);
  FUN_00627930(iVar1,1);
  FUN_006279b0(param_1,iVar1);
  return;
}

