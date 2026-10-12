/* Ghidra pseudocode, not original source.
 * ev_d21561abf9cd5233ed14ae59a5314f19a5c253e33bc7c4e30ba499fb63508ecc
 * Entry: 0x5fc980; label: FUN_005fc980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fc980(void)

{
  undefined1 in_AL;
  int in_ECX;
  
  switch(in_AL) {
  case 0:
    *(undefined1 *)(in_ECX + 1) = 0;
    return;
  case 1:
    *(undefined1 *)(in_ECX + 1) = 1;
    return;
  case 3:
    *(undefined1 *)(in_ECX + 1) = 3;
    return;
  case 4:
    *(undefined1 *)(in_ECX + 1) = 4;
  }
  return;
}

