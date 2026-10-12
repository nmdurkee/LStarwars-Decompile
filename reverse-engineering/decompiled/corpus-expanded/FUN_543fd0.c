/* Ghidra pseudocode, not original source.
 * ev_c5dfc397922749c3a3d752de14fd9803558ba6adea5c02b0f86cafc5797b3dfb
 * Entry: 0x543fd0; label: FUN_00543fd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00543fd0(uint param_1)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  
  if (7 < param_1) {
    return;
  }
  FUN_0066cbc0();
  iVar3 = param_1 * 0xb0c;
  if ((&DAT_02983a60)[iVar3] != '\0') {
    FUN_0066cbb0((&DAT_02983a68)[param_1 * 0x2c3]);
    if ('\0' < (char)(&DAT_02984546)[iVar3]) {
      psVar2 = &DAT_02984514 + param_1 * 0x586;
      iVar4 = 0;
      do {
        iVar1 = FUN_005cfac0(&DAT_029844ec + iVar3);
        if (iVar1 != 0) {
          FUN_0067c930((int)*psVar2);
        }
        iVar4 = iVar4 + 1;
        psVar2 = psVar2 + 1;
      } while (iVar4 < (char)(&DAT_02984546)[iVar3]);
    }
    (&DAT_02983a60)[iVar3] = '\0';
  }
  FUN_0066cbb0();
  return;
}

