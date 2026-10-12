/* Ghidra pseudocode, not original source.
 * ev_fe5af94714569ca149d7ee11beb07ec697c406bef5bd6833183fcd21241d309c
 * Entry: 0x51d750; label: FUN_0051d750
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0051d750(void)

{
  int in_EAX;
  int iVar1;
  
  if ((*(int *)(in_EAX + 0x158) == *(int *)(in_EAX + 0x1cc)) && (*(int *)(in_EAX + 0x1d0) != 0)) {
    return 0;
  }
  FUN_0051d310(in_EAX + 0x1b4);
  if (*(byte *)(in_EAX + 0x143) < *(byte *)(*(int *)(in_EAX + 0x158) + 0x10)) {
    iVar1 = FUN_0051d500();
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0xffffffff;
}

