/* Ghidra analysis pseudocode, not original source.
 * ev_a7e7d672623d9c9895986762e49f541fc5bec923712a30ebf66db24116e2b0d4
 * Entry: 0x4d3760; label: FUN_004d3760
 */

int FUN_004d3760(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_40 [16];
  
  iVar1 = FUN_00571c80(param_1);
  if ((iVar1 != 0) && (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x7be) != '\0')) {
    puVar3 = local_40;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *param_1;
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_005b4b30(local_40,*(float *)(*(int *)(PTR_DAT_00802c54 + 0x5100) + 8) * 4.0);
    FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x7b0,local_40);
  }
  return iVar1;
}

