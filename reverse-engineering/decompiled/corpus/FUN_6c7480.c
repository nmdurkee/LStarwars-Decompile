/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c7480; label: FUN_006c7480
 */

void FUN_006c7480(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  
  puVar2 = (undefined4 *)*in_ECX;
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar2[1];
    if (puVar2[3] == 0x10) {
      if (puVar1 == (undefined4 *)0x0) {
        in_ECX[1] = puVar2[2];
      }
      else {
        puVar1[2] = puVar2[2];
      }
      if (puVar2[2] == 0) {
        *in_ECX = puVar2[1];
      }
      else {
        *(undefined4 *)(puVar2[2] + 4) = puVar2[1];
      }
      puVar2[1] = 0;
      puVar2[2] = 0;
      in_ECX[2] = in_ECX[2] + -1;
      (**(code **)*puVar2)(1);
      puVar2 = puVar1;
    }
    else {
      puVar2[4] = 0;
      puVar2 = puVar1;
    }
  }
  return;
}

