/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x748790; label: FUN_00748790
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00748790(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(in_ECX + 0x89c)) {
    piVar2 = (int *)(in_ECX + 0x4b4);
    do {
      iVar1 = iVar1 + 1;
      *(undefined4 *)(*piVar2 + 0x20) = 0;
      piVar2 = piVar2 + 1;
    } while (iVar1 < *(int *)(in_ECX + 0x89c));
  }
  return;
}

