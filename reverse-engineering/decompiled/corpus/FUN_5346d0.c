/* Ghidra analysis pseudocode, not original source.
 * ev_b3428d17d7a525986d1be417305dad2f8f354c51dc50a167d24fd678dc156e11
 * Entry: 0x5346d0; label: FUN_005346d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005346d0(undefined4 param_1)

{
  int iVar1;
  
  FUN_00529ad0(&DAT_00921f20,0);
  if (*(int *)(DAT_009238e4 + 0x371b0) != 0) {
    iVar1 = *(int *)(DAT_009238e4 + 0x371b0);
    *(undefined4 *)(iVar1 + 0x70) = DAT_00921f3c;
    *(undefined4 *)(iVar1 + 0x74) = DAT_00921f40;
    *(undefined4 *)(iVar1 + 0x78) = _DAT_00921f44;
    *(undefined4 *)(iVar1 + 0x7c) = _DAT_00921f48;
    *(uint *)(iVar1 + 0x68) = *(uint *)(iVar1 + 0x68) & 0xffffffe1;
  }
  FUN_006279f0(param_1);
  FUN_00624220(param_1);
  DAT_009242b8 = 0;
  return;
}

