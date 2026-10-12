/* Ghidra pseudocode, not original source.
 * ev_cd751bbce80615e44627de7d2a98b099122eeed2e472d985b2852ac0d20d1b25
 * Entry: 0x60ffd0; label: FUN_0060ffd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060ffd0(int param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  if (7 < param_2) {
    param_2 = 8;
  }
  iVar1 = 0;
  if (0 < param_2) {
    puVar2 = (undefined4 *)(in_ECX + 0x48);
    do {
      *puVar2 = *(undefined4 *)(param_1 + iVar1 * 4);
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar1 < param_2);
  }
  return;
}

