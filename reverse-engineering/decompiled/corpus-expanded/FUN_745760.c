/* Ghidra pseudocode, not original source.
 * ev_ac26ce749027d8ec0aff2eea20dc28ff8b92ba016e1d9b13f008953590b31814
 * Entry: 0x745760; label: FUN_00745760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00745760(int *param_1,char param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  byte bVar2;
  int in_ECX;
  uint uVar3;
  undefined4 local_4;
  
  local_4 = 0;
  FUN_00744b70(&local_4,param_1,param_2 != '\0');
  *(undefined4 *)(in_ECX + 0x79194) = 0;
  *(undefined4 *)(in_ECX + 0x791a4) = 0;
  FUN_00748d00(param_1,(undefined4 *)(in_ECX + 0x79190),(undefined4 *)(in_ECX + 0x791a0));
  FUN_00743da0(param_3,&local_4,param_4,*(undefined4 *)(in_ECX + 0x79190),
               *(undefined4 *)(in_ECX + 0x79194),*(undefined4 *)(in_ECX + 0x791a0),
               *(undefined4 *)(in_ECX + 0x791a4),*(undefined4 *)(*(int *)(in_ECX + 0x7918c) + 0xb80)
              );
  *(uint *)(param_3 + 0x4d4) =
       *(uint *)(param_3 + 0x4d4) ^ ((uint)(param_1[3] == 0) ^ *(uint *)(param_3 + 0x4d4)) & 1;
  uVar1 = *(uint *)(param_3 + 0x4d4);
  uVar3 = ((uint)(param_1[4] != 0) * 2 ^ uVar1) & 2 ^ uVar1;
  *(uint *)(param_3 + 0x4d4) = uVar3;
  if (param_1[3] == 0) {
    bVar2 = *(byte *)(*param_1 + 0x1ba) & 1;
  }
  else {
    bVar2 = 0;
  }
  uVar3 = ((uint)bVar2 * 4 ^ uVar3) & 4 ^ uVar3;
  *(uint *)(param_3 + 0x4d4) = uVar3;
  *(uint *)(param_3 + 0x4d4) = ((uint)(param_1[6] != 0) * 8 ^ uVar3) & 8 ^ uVar3;
  return CONCAT31((int3)(uVar1 >> 8),1);
}

