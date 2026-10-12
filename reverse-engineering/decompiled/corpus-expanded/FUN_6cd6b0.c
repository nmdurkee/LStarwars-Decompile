/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6cd6b0; label: FUN_006cd6b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cd6b0(int *param_1,int param_2,undefined4 param_3,uint param_4)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (param_2 != 0) {
    if ((param_4 & 2) == 0) {
      FUN_006be9a0(param_2,param_1[1],param_4);
    }
    (**(code **)(*param_1 + 0x20))(param_2);
    puVar1 = (undefined4 *)FUN_006ea018(0x10);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = 0;
      puVar1[1] = 0;
    }
    puVar1[2] = param_1[1];
    puVar1[3] = param_2;
    *puVar1 = 0;
    puVar1[1] = *(undefined4 *)(in_ECX + 0x3c);
    if (*(undefined4 **)(in_ECX + 0x3c) != (undefined4 *)0x0) {
      **(undefined4 **)(in_ECX + 0x3c) = puVar1;
    }
    *(undefined4 **)(in_ECX + 0x3c) = puVar1;
    if (*(int *)(in_ECX + 0x38) == 0) {
      *(undefined4 **)(in_ECX + 0x38) = puVar1;
    }
    *(int *)(in_ECX + 0x40) = *(int *)(in_ECX + 0x40) + 1;
  }
  return;
}

