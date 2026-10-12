/* Ghidra pseudocode, not original source.
 * ev_fb6cd954323bef10c706b5185a175772da5bd325e62fab563c9169acbcfebd41
 * Entry: 0x613700; label: FUN_00613700
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00613700(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  piVar2 = (int *)(*(int *)(param_3 + 8) + 3U & 0xfffffffc);
  *(int **)(param_3 + 8) = piVar2 + 2;
  param_3 = -1;
  iVar1 = FUN_00617a00();
  if ((param_4 == 0) &&
     ((*(ushort *)(in_ECX + 0x12) == 0 ||
      ((uint)(iVar1 - *piVar2) <= (uint)*(ushort *)(in_ECX + 0x12))))) {
    if (((uint)(iVar1 - *piVar2) <= (uint)*(ushort *)(in_ECX + 0x10)) || (param_5 != 0)) {
      return 0;
    }
    FUN_00613610(param_1,param_2,&param_3);
    if (param_3 == piVar2[1]) {
      return 0;
    }
    piVar2[1] = param_3;
  }
  *piVar2 = iVar1;
  return 1;
}

