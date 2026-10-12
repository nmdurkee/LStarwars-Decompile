/* Ghidra pseudocode, not original source.
 * ev_c5dfc397922749c3a3d752de14fd9803558ba6adea5c02b0f86cafc5797b3dfb
 * Entry: 0x543f10; label: FUN_00543f10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00543f10(void)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = &DAT_02983a60;
  iVar1 = 0;
  do {
    if (*pcVar2 == '\0') {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    pcVar2 = pcVar2 + 0xb0c;
  } while (iVar1 < 8);
  return -1;
}

