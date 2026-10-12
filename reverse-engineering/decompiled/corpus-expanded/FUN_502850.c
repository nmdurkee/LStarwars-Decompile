/* Ghidra pseudocode, not original source.
 * ev_4aacc4015277efc7c796a4684ec1a2293d4b851b48a9fd84999ecda53bd8e95c
 * Entry: 0x502850; label: FUN_00502850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00502850(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x58) + 0x14);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  if ((int)(uint)*(ushort *)(piVar1 + 1) <= param_3) {
    return 0;
  }
  iVar2 = param_3 * 0x5c + *piVar1;
  puVar3 = (undefined4 *)(param_3 * 0x10 + **(int **)(param_1 + 0xa0));
  if ((*(byte *)(iVar2 + 0x58) & 6) != 0) {
    FUN_00502390(iVar2,param_2,param_4);
    if ((*(byte *)(param_1 + 0x88) & 0x80) != 0) {
      FUN_005b5430(param_4,param_4,param_1 + 0x18);
    }
    *param_5 = *puVar3;
    param_5[1] = puVar3[1];
    param_5[2] = puVar3[2];
  }
  return param_3 + 1;
}

