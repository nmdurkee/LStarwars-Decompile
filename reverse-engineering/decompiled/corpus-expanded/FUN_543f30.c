/* Ghidra pseudocode, not original source.
 * ev_c5dfc397922749c3a3d752de14fd9803558ba6adea5c02b0f86cafc5797b3dfb
 * Entry: 0x543f30; label: FUN_00543f30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00543f30(void)

{
  undefined4 uVar1;
  int iVar2;
  short *psVar3;
  char *pcVar4;
  int iVar5;
  int local_8;
  
  uVar1 = FUN_0066cbc0();
  pcVar4 = &DAT_02984546;
  local_8 = 8;
  do {
    if (pcVar4[-0xae6] != '\0') {
      FUN_0066cbb0(*(undefined4 *)(pcVar4 + -0xade));
      iVar5 = 0;
      if ('\0' < *pcVar4) {
        psVar3 = (short *)(pcVar4 + -0x32);
        do {
          iVar2 = FUN_005cfac0(pcVar4 + -0x5a);
          if (iVar2 != 0) {
            FUN_0067c930((int)*psVar3);
          }
          iVar5 = iVar5 + 1;
          psVar3 = psVar3 + 1;
        } while (iVar5 < *pcVar4);
      }
      pcVar4[-0xae6] = '\0';
    }
    pcVar4 = pcVar4 + 0xb0c;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  FUN_0066cbb0(uVar1);
  return;
}

