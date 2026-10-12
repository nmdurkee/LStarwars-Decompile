/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6d05e0; label: FUN_006d05e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d05e0(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  char *pcVar7;
  uint uVar8;
  char *pcVar9;
  char local_84 [2];
  char acStack_82 [126];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_84;
  FUN_006d0240();
  iVar2 = FUN_00619250(*(int *)(param_1 + 0x1c) + *(int *)(param_2 + 0x1c),
                       *(undefined4 *)(param_2 + 0x20),0xb4,0xfa,DAT_02973a78,FUN_006bc860,
                       "Save File");
  if (DAT_02974c9c == 0) {
    if (iVar2 != 0) {
      pcVar7 = "Saving not allowed in Debug Mode - change to Edit Mode";
      pcVar9 = local_84;
      for (iVar5 = 0xd; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar9 = pcVar9 + 4;
      }
      *(undefined2 *)pcVar9 = *(undefined2 *)pcVar7;
      pcVar9[2] = pcVar7[2];
      uVar3 = FUN_00627a80(1,&DAT_0081f9a0,0,0,FUN_006bc8c0,local_84);
      FUN_00618e10(iVar2,uVar3);
      FUN_006242b0(iVar2,5);
      FUN_00627930(iVar2,1);
    }
  }
  else {
    uVar8 = 0;
    if (0 < DAT_02973e98) {
      puVar6 = &DAT_02973f40;
      do {
        if (uVar8 < 10) {
          puVar4 = puVar6 + -0x29;
          if ((((puVar6 == (uint *)0xa4) || (uVar1 = *puVar6, (uVar1 & 1) == 0)) ||
              ((uVar1 & 2) == 0)) || ((uVar1 & 4) == 0)) goto LAB_006d06a5;
          *puVar6 = uVar1 & 0xfffffffb;
          if (iVar2 != 0) {
            _sprintf(local_84,"%s successfully saved",puVar4);
            goto LAB_006d06d0;
          }
        }
        else {
          puVar4 = (uint *)0x0;
LAB_006d06a5:
          if (((iVar2 != 0) && (puVar4 != (uint *)0x0)) &&
             (((puVar4[0x29] & 1) != 0 && ((puVar4[0x29] & 2) != 0)))) {
            _sprintf(local_84,"%s : Save Failed, have you got the lock?",puVar4);
LAB_006d06d0:
            uVar3 = FUN_00627a80(1,&DAT_0081f9a0,0,0,FUN_006bc8c0,local_84);
            FUN_00618e10(iVar2,uVar3);
            FUN_006242b0(iVar2,5);
            FUN_00627930(iVar2,1);
          }
        }
        uVar8 = uVar8 + 1;
        puVar6 = puVar6 + 0x2a;
      } while ((int)uVar8 < DAT_02973e98);
    }
  }
  FUN_006242b0(iVar2,5);
  FUN_00627930(iVar2,1);
  FUN_006279b0(param_1,iVar2);
  __security_check_cookie(local_4 ^ (uint)local_84);
  return;
}

