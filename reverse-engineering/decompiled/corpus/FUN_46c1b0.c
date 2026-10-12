/* Ghidra analysis pseudocode, not original source.
 * ev_55017b0be5ecbbe7992f90db1bd4d4788b50f0daee2843c81c8d7e89602b0f77
 * Entry: 0x46c1b0; label: FUN_0046c1b0
 */

int FUN_0046c1b0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_40 [16];
  
  iVar1 = FUN_00571c80(param_1);
  if ((iVar1 != 0) && (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xd1e) != '\0')) {
    puVar3 = local_40;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *param_1;
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xd10,local_40);
  }
  return iVar1;
}

