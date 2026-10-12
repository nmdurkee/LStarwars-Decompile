/* Ghidra analysis pseudocode, not original source.
 * ev_2bdbbe329da9ea38d1a43ba98d87f55aefaa8a75bec4fa8a7bfad8e968716318
 * Entry: 0x4424c0; label: FUN_004424c0
 */

int FUN_004424c0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_2 == 0) {
    return -1;
  }
  iVar2 = 0;
  puVar3 = (undefined4 *)(param_3 + 0x18);
  do {
    iVar1 = FUN_004f8b10(*puVar3,param_2);
    if (iVar1 == 0) {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 2;
  } while (iVar2 < 4);
  iVar2 = FUN_004f29a0(param_2);
  return iVar2;
}

