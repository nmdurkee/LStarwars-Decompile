/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5eaad0; label: FUN_005eaad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005eaad0(int param_1,float param_2,float param_3)

{
  float fVar1;
  ushort uVar2;
  int iVar3;
  float local_4;
  
  if ((param_1 == 0) && (param_1 = DAT_009738b8, DAT_009738b8 == 0)) {
    return;
  }
  iVar3 = param_1;
  if (((param_1 == 0) && (iVar3 = DAT_009738b8, DAT_009738b8 == 0)) ||
     (uVar2 = FUN_005d0aa0(*(undefined4 *)(iVar3 + 0x38),*(undefined4 *)(iVar3 + 0x10),0x4d),
     uVar2 == 0xffff)) {
    fVar1 = (param_3 * 18.0) / *(float *)(param_1 + 0x14);
    local_4 = fVar1 / param_3;
  }
  else {
    local_4 = (param_2 * 7.0) / *(float *)(*(int *)(param_1 + 0x34) + 8 + (uint)uVar2 * 0xc);
    fVar1 = (param_3 * 18.0) / *(float *)(param_1 + 0x14);
  }
  **(float **)(param_1 + 0x2c) = local_4;
  if (((byte)DAT_009738c4 & 4) == 0) {
    **(float **)(param_1 + 0x30) = fVar1 * 0.5;
  }
  else {
    **(float **)(param_1 + 0x30) = fVar1;
  }
  FUN_005d1530(param_1,local_4,fVar1);
  return;
}

