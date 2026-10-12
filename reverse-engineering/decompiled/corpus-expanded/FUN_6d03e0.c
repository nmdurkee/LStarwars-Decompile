/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6d03e0; label: FUN_006d03e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006d03e0(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  int in_ECX;
  int unaff_ESI;
  int iVar2;
  undefined **local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_8;
  int local_4;
  
  iVar2 = *param_3 - *param_2;
  iVar1 = FUN_004f02d0(*param_2,iVar2,1);
  if (iVar1 != 0) {
    *(undefined1 *)(in_ECX + 0x2a0) = 1;
    local_34 = 0;
    local_30 = 0;
    local_3c = 0;
    local_2c = 0;
    local_40 = 2;
    local_48 = &PTR_FUN_0076f9ac;
    local_8 = 0;
    local_44 = 4;
    local_4 = iVar1;
    iVar2 = FUN_006c8480("StreamInfo");
    if (iVar2 != 0) {
      (*(code *)local_48[2])(&local_44,4,1);
      (**(code **)(unaff_ESI + 0x1c))();
    }
    local_2c = 0x400000;
    local_38 = param_1;
    FUN_006cb820(&local_48);
    iVar2 = FUN_004f6d10(iVar1);
    local_4 = 0;
    FUN_004f99e0(iVar1);
    *(undefined1 *)(in_ECX + 0x2a0) = 0;
    return iVar2;
  }
  FUN_006b7c50(in_ECX + 0x9cc);
  *(undefined1 *)(in_ECX + 0x2a0) = 0;
  return iVar2;
}

