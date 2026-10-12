/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bce50; label: FUN_005bce50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bce50(int param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  float local_14;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = param_4 + -1;
  fVar1 = (float)iVar2;
  local_14 = 0.0;
  if (0 < iVar2) {
    puVar3 = (undefined4 *)(param_3 + 8);
    do {
      FUN_005bcab0(param_1,local_14,param_2,&local_c);
      puVar3[-2] = local_c;
      iVar2 = iVar2 + -1;
      puVar3[-1] = local_8;
      *puVar3 = local_4;
      local_14 = local_14 + 1.0 / fVar1;
      puVar3 = puVar3 + 3;
    } while (iVar2 != 0);
  }
  iVar2 = param_2 + param_1 * 0xc;
  param_3 = param_3 + param_4 * 0xc;
  *(undefined4 *)(param_3 + -0xc) = *(undefined4 *)(param_2 + param_1 * 0xc);
  *(undefined4 *)(param_3 + -8) = *(undefined4 *)(iVar2 + 4);
  *(undefined4 *)(param_3 + -4) = *(undefined4 *)(iVar2 + 8);
  return;
}

