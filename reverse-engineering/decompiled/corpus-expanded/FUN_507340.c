/* Ghidra pseudocode, not original source.
 * ev_9d34c938d292037f498e462893e532f4f6f058923093d2cacbd29fd836aaae04
 * Entry: 0x507340; label: FUN_00507340
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00507340(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *param_2 + 3 & 0xfffffffc;
  iVar2 = uVar1 - param_1;
  *param_2 = uVar1;
  if (iVar2 != 0) {
    *(int *)(param_1 + 4) = iVar2;
    *(int *)(param_1 + 0x28) = iVar2;
    FUN_004ef660(uVar1,param_1,*(undefined4 *)(param_1 + 0x58));
    FUN_00505780(1);
  }
  *param_2 = *param_2 + *(int *)(uVar1 + 0x58);
  return uVar1;
}

