/* Ghidra analysis pseudocode, not original source.
 * ev_b3428d17d7a525986d1be417305dad2f8f354c51dc50a167d24fd678dc156e11
 * Entry: 0x534780; label: FUN_00534780
 */

void FUN_00534780(undefined4 param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = DAT_009238e4;
  if (((param_2 != 0) && (*(int *)(DAT_009238e4 + 0x371b0) != 0)) &&
     (*(float *)(param_2 + 0x54) != (float)(&DAT_00921f3c)[*(int *)(param_2 + 0xc)])) {
    (&DAT_00921f3c)[*(int *)(param_2 + 0xc)] = *(undefined4 *)(param_2 + 0x54);
    uVar3 = __allshl();
    DAT_00921f4c = DAT_00921f4c | uVar3;
    iVar2 = *(int *)(iVar2 + 0x371b0);
    *(undefined4 *)(iVar2 + 0x70 + *(int *)(param_2 + 0xc) * 4) =
         (&DAT_00921f3c)[*(int *)(param_2 + 0xc)];
    puVar1 = (uint *)(iVar2 + 0x68);
    *puVar1 = *puVar1 & 0xffffffe1;
    puVar1 = (uint *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x68);
    *puVar1 = *puVar1 | DAT_00921f4c;
    FUN_00534740();
  }
  return;
}

