/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x461b80; label: FUN_00461b80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00461b80(int param_1,float param_2,int param_3)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_00855ed0;
  if ((*(byte *)((int)param_2 + 0xb0) & 0x80) == 0) {
    puVar1 = &DAT_00855ea4;
  }
  if (param_3 != 0) {
    if (*(int *)(param_1 + 0x14) < 1) {
      param_2 = 1.0;
    }
    else {
      if ((*(float *)(param_1 + 0x18) == 0.0) || (*(float *)(param_1 + 0x1c) == 0.0)) {
        param_2 = 0.0;
      }
      else {
        param_2 = *(float *)(param_1 + 0x18) / *(float *)(param_1 + 0x1c);
      }
      param_2 = 1.0 - param_2;
    }
    FUN_00594c30(puVar1,0,_DAT_00804fb8,puVar1[4],0,param_2,0);
  }
  return;
}

