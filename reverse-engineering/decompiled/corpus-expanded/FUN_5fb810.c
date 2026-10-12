/* Ghidra pseudocode, not original source.
 * ev_d21561abf9cd5233ed14ae59a5314f19a5c253e33bc7c4e30ba499fb63508ecc
 * Entry: 0x5fb810; label: FUN_005fb810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fb810(void)

{
  int *piVar1;
  int *in_ECX;
  
  if ((*in_ECX != 0) && (*(int *)(*in_ECX + 0x28) != 0)) {
    in_ECX[2] = 0;
  }
  piVar1 = (int *)in_ECX[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[2] = 0;
  }
  if ((*in_ECX != 0) && ((char)in_ECX[1] != '\0')) {
    FUN_005f7b40(*in_ECX);
  }
  *in_ECX = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined2 *)(in_ECX + 3) = 0;
  in_ECX[4] = 0;
  *(undefined2 *)(in_ECX + 5) = 0;
  *(undefined2 *)((int)in_ECX + 0x16) = 0;
  return;
}

