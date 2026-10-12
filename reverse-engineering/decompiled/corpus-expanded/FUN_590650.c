/* Ghidra pseudocode, not original source.
 * ev_d7fef5854a4ea50d405948ed3aa82c9004ffbc8626dda7a7f3cbba7e59036064
 * Entry: 0x590650; label: FUN_00590650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00590650(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((*(int *)(PTR_DAT_00802c54 + 300) == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_00951364)
      ) && (*(char *)(param_1 + 0x14) == '\0')) {
    uVar1 = FUN_0055f450();
    iVar2 = FUN_0058ec80(uVar1);
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}

