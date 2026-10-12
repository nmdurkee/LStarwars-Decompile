/* Ghidra analysis pseudocode, not original source.
 * ev_9c4a7344b4ed6999b1698de871080e88c37121f37ac9563577536a7a556549db
 * Entry: 0x56e000; label: FUN_0056e000
 */

void FUN_0056e000(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar3 = PTR_DAT_008032c4;
  *(int **)PTR_DAT_008032c4 = param_1;
  *(undefined4 *)(puVar3 + 4) = 0;
  if (param_1 != (int *)0x0) {
    iVar2 = *param_1;
    while (iVar2 != 0) {
      piVar1 = (int *)(puVar3 + 4);
      *piVar1 = *piVar1 + 1;
      param_1 = param_1 + 8;
      iVar2 = *param_1;
    }
  }
  return;
}

