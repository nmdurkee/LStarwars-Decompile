/* Ghidra pseudocode, not original source.
 * ev_be89c5742567956971c64ab2441aea6b3f78c2cf42a7c801ad7bb364f9087e2c
 * Entry: 0x62d500; label: FUN_0062d500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062d500(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  if (0 < *DAT_029130e4) {
    iVar3 = 0;
    piVar2 = DAT_029130e4;
    do {
      if ((*(byte *)(piVar2[8] + 4 + iVar3) & 2) == 0) {
        *(undefined2 *)(piVar2[7] + iVar1 * 2) = 0xffff;
        piVar2 = DAT_029130e4;
      }
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x4c;
    } while (iVar1 < *piVar2);
  }
  return;
}

