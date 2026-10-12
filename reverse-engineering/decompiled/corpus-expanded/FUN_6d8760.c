/* Ghidra pseudocode, not original source.
 * ev_901c6aaecd0b47868ef1d3f758584dfae83b8347f4e0d529523c41e91b06b177
 * Entry: 0x6d8760; label: FUN_006d8760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d8760(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  if (*(int *)(in_ECX + 0x4e08) != 0) {
    if (*(char *)(in_ECX + 0x4e10) == '\0') {
      *(undefined1 *)(in_ECX + 0x4e10) = 1;
      uVar1 = FUN_006d5990();
      *(undefined4 *)(in_ECX + 0x68b0) = uVar1;
    }
    FUN_006d7990();
    iVar4 = 0;
    do {
      uVar2 = 1 << ((byte)iVar4 & 0x1f);
      if ((*(uint *)(in_ECX + 0x4e08) & uVar2) == 0) {
        *(uint *)(in_ECX + 0x4e04) = *(uint *)(in_ECX + 0x4e04) | uVar2;
        *(uint *)(in_ECX + 0x4e08) = ~uVar2 & *(uint *)(in_ECX + 0x4e08);
        iVar3 = FUN_006d74e0(iVar4,in_ECX + 0x671c);
        if ((iVar3 != 0) || (iVar4 - 10U < 4)) {
          FUN_006d8490(iVar4);
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0xe);
  }
  return;
}

