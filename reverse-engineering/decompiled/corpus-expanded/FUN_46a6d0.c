/* Ghidra pseudocode, not original source.
 * ev_fb4a243913288e8884e4b26b9d3f1b2cc90d3774ba2cd7b272b490162dad9d99
 * Entry: 0x46a6d0; label: FUN_0046a6d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0046a6d0(int *param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int local_4;
  
  iVar1 = param_3;
  if ((*(uint *)(param_3 + 0xf0) & 0x200) == 0) {
    local_4 = param_4;
    param_3 = 3;
  }
  else {
    local_4 = param_4 + 0xc;
    param_3 = 1;
  }
  if (((DAT_0093b268 != (int *)0x0) && (param_1 != (int *)0x0)) &&
     ((*(ushort *)(iVar1 + 0xf8) & 0x800) != 0)) {
    iVar4 = 0;
    if (0 < *DAT_0093b268) {
      puVar6 = (undefined4 *)(*param_1 + 0x10);
      puVar5 = (undefined4 *)(DAT_0093b268[2] + 0x74);
      piVar3 = DAT_0093b268;
      do {
        if (((code *)*puVar5 != (code *)0x0) &&
           (iVar2 = (*(code *)*puVar5)(param_2,*puVar6,*(undefined4 *)(iVar1 + 4),local_4,param_3,
                                       param_7,param_5,param_6,iVar1,1,param_8),
           piVar3 = DAT_0093b268, iVar2 != 0)) {
          (**(code **)(PTR_PTR_008040bc + 0xc))(iVar1,param_4,0xffffffff,0,0);
          if (*(int *)(iVar1 + 4) != 0) {
            FUN_0054a850(**(undefined4 **)(*(int *)(iVar1 + 4) + 0xca4),0x3f19999a,0);
          }
          FUN_00580120(iVar1,1);
          FUN_0057fe80(iVar1);
          return 1;
        }
        iVar4 = iVar4 + 1;
        puVar6 = puVar6 + 5;
        puVar5 = puVar5 + 0x27;
      } while (iVar4 < *piVar3);
    }
  }
  return 0;
}

