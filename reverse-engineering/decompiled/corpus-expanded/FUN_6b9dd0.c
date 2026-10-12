/* Ghidra pseudocode, not original source.
 * ev_4470474dfe9095336407712c08b1b1234dd43f54b8096ef09bb626cb5952ee3b
 * Entry: 0x6b9dd0; label: FUN_006b9dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b9dd0(uint param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int in_ECX;
  undefined4 uVar1;
  
  if (((param_2 == *(int *)(in_ECX + 0x10)) || (param_2 == *(int *)(in_ECX + 0x14))) ||
     (param_2 == *(int *)(in_ECX + 0x18))) {
    if ((param_1 & 8) == 0) {
      *(undefined4 *)(param_2 + 0x28) = *param_3;
      *(undefined4 *)(param_2 + 0x2c) = param_3[1];
      *(undefined4 *)(param_2 + 0x30) = param_3[2];
      uVar1 = param_3[3];
    }
    else {
      *(undefined4 *)(param_2 + 0x28) = *param_4;
      *(undefined4 *)(param_2 + 0x2c) = param_4[1];
      *(undefined4 *)(param_2 + 0x30) = param_4[2];
      uVar1 = param_4[3];
    }
    *(undefined4 *)(param_2 + 0x34) = uVar1;
  }
  if (((param_2 == *(int *)(in_ECX + 0x1c)) || (param_2 == *(int *)(in_ECX + 0x20))) ||
     (param_2 == *(int *)(in_ECX + 0x24))) {
    if ((param_1 == 0) || ((param_1 & 0x10) == 0)) {
      *(undefined4 *)(param_2 + 0x28) = *param_3;
      *(undefined4 *)(param_2 + 0x2c) = param_3[1];
      *(undefined4 *)(param_2 + 0x30) = param_3[2];
      uVar1 = param_3[3];
    }
    else {
      *(undefined4 *)(param_2 + 0x28) = *param_4;
      *(undefined4 *)(param_2 + 0x2c) = param_4[1];
      *(undefined4 *)(param_2 + 0x30) = param_4[2];
      uVar1 = param_4[3];
    }
    *(undefined4 *)(param_2 + 0x34) = uVar1;
  }
  if (((param_2 == *(int *)(in_ECX + 0x28)) || (param_2 == *(int *)(in_ECX + 0x2c))) ||
     (param_2 == *(int *)(in_ECX + 0x30))) {
    if ((param_1 != 0) && ((param_1 & 0x20) != 0)) {
      *(undefined4 *)(param_2 + 0x28) = *param_4;
      *(undefined4 *)(param_2 + 0x2c) = param_4[1];
      *(undefined4 *)(param_2 + 0x30) = param_4[2];
      *(undefined4 *)(param_2 + 0x34) = param_4[3];
      return;
    }
    *(undefined4 *)(param_2 + 0x28) = *param_3;
    *(undefined4 *)(param_2 + 0x2c) = param_3[1];
    *(undefined4 *)(param_2 + 0x30) = param_3[2];
    *(undefined4 *)(param_2 + 0x34) = param_3[3];
  }
  return;
}

