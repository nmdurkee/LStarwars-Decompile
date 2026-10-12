/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x5346d0; label: FUN_005346d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

