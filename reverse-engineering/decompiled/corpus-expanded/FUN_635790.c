/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x635790; label: FUN_00635790
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00635790(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar1 = FUN_006355f0(param_1,param_2);
  if (-1 < iVar1) {
    iVar2 = FUN_00635660();
    if (-1 < iVar2) {
      puVar3 = (undefined4 *)FUN_00547560(_DAT_02913970,iVar2);
      puVar5 = (undefined4 *)(iVar1 * 0x8c + 4 + param_1);
      for (iVar4 = 0x23; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar3 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar3 = puVar3 + 1;
      }
      return iVar2;
    }
  }
  return -1;
}

