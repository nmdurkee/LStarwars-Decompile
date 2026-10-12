/* Ghidra pseudocode, not original source.
 * ev_86be5d0b29c9dd19f96c33e6e07bf1c9a03b071eda0eb4c5bb2270815bb5be61
 * Entry: 0x529bb0; label: FUN_00529bb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00529bb0(undefined4 param_1,int param_2)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  
  if ((param_2 != 0) && (*(int *)(DAT_009238e4 + 0x371b0) != 0)) {
    iVar3 = FUN_00513160(*(undefined4 *)(DAT_009238e4 + 100),*(undefined4 *)(param_2 + 0xc));
    if (iVar3 != 0) {
      FUN_00529ad0(iVar3,0);
      iVar3 = FUN_004f8b10(&DAT_00921f20,*(int *)(DAT_009238e4 + 0x371b0) + 0x18);
      if (iVar3 != 0) {
        pcVar5 = &DAT_00921f20;
        pcVar4 = (char *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x18);
        do {
          cVar2 = *pcVar5;
          *pcVar4 = cVar2;
          pcVar5 = pcVar5 + 1;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
        iVar3 = *(int *)(DAT_009238e4 + 0x371b0);
        *(undefined4 *)(iVar3 + 0x70) = DAT_00921f3c;
        *(undefined4 *)(iVar3 + 0x74) = DAT_00921f40;
        *(undefined4 *)(iVar3 + 0x78) = _DAT_00921f44;
        *(undefined4 *)(iVar3 + 0x7c) = _DAT_00921f48;
        *(uint *)(iVar3 + 0x68) = *(uint *)(iVar3 + 0x68) & 0xffffffe1;
        puVar1 = (uint *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x68);
        *puVar1 = *puVar1 | DAT_00921f4c;
      }
    }
  }
  return;
}

