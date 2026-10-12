/* Ghidra pseudocode, not original source.
 * ev_fb6cd954323bef10c706b5185a175772da5bd325e62fab563c9169acbcfebd41
 * Entry: 0x6137a0; label: FUN_006137a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006137a0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  int *in_ECX;
  uint *puVar2;
  int *piVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  piVar3 = (int *)(param_3[2] + 3 & 0xfffffffc);
  puVar2 = (uint *)(piVar3 + 1);
  param_3[2] = piVar3 + 2;
  iVar1 = FUN_00617a00();
  if (param_4 != 0) {
    *piVar3 = iVar1;
    return 1;
  }
  if ((uint)*(ushort *)(in_ECX + 4) < (uint)(iVar1 - *piVar3)) {
    local_10 = *param_3;
    local_c = param_3[1];
    local_8 = param_3[2];
    local_4 = param_3[3];
    iVar1 = (**(code **)(*in_ECX + 8))(param_1,param_2,&local_10,1);
    if (iVar1 != 0) {
      *puVar2 = 0;
      *(ushort *)((int)in_ECX + 0xe) = *(ushort *)((int)in_ECX + 0xe) | 1;
      *piVar3 = local_4;
      return 1;
    }
    if (*puVar2 < 3) {
      *puVar2 = *puVar2 + 1;
      *(ushort *)((int)in_ECX + 0xe) = *(ushort *)((int)in_ECX + 0xe) & 0xfffe;
      *piVar3 = local_4;
      return 1;
    }
  }
  return 0;
}

