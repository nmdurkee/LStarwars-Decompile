/* Ghidra pseudocode, not original source.
 * ev_d21561abf9cd5233ed14ae59a5314f19a5c253e33bc7c4e30ba499fb63508ecc
 * Entry: 0x5fb920; label: FUN_005fb920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fb920(int param_1)

{
  char cVar1;
  int in_ECX;
  
  if ((*(short *)(in_ECX + 0x14) == *(short *)(param_1 + 0x14)) &&
     (*(short *)(in_ECX + 0x16) == *(short *)(param_1 + 0x16))) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  FUN_006e5820(*(undefined4 *)(param_1 + 8),0,*(undefined4 *)(in_ECX + 8),0,-cVar1 & 2);
  return;
}

