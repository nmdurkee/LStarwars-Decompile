/* Ghidra pseudocode, not original source.
 * ev_3b3808edeffc7046af602211c0d6f30bd8b518f734faefbc322523a0a631579d
 * Entry: 0x6d6720; label: FUN_006d6720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d6720(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)(DAT_02975144 + 0x5d34);
  iVar2 = 4;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 0x17c;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

