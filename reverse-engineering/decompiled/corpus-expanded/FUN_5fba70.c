/* Ghidra pseudocode, not original source.
 * ev_d21561abf9cd5233ed14ae59a5314f19a5c253e33bc7c4e30ba499fb63508ecc
 * Entry: 0x5fba70; label: FUN_005fba70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fba70(void)

{
  int in_ECX;
  int iVar1;
  int *piVar2;
  
  if (*(int *)(in_ECX + 0x30) != 0) {
    FUN_005f8470(*(int *)(in_ECX + 0x30),0xffffffff,0xffffffff,0xffffffff);
  }
  if (*(int *)(in_ECX + 0x28) != 0) {
    FUN_005f8470(*(int *)(in_ECX + 0x28),0xffffffff,0xffffffff,0xffffffff);
  }
  piVar2 = (int *)(in_ECX + 0x38);
  iVar1 = 2;
  do {
    if (*piVar2 != 0) {
      FUN_005f8470(*piVar2,*(undefined2 *)(*(int *)(in_ECX + 0x30) + 4),
                   *(undefined2 *)(*(int *)(in_ECX + 0x30) + 6),0xffffffff);
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

