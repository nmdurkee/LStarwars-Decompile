/* Ghidra pseudocode, not original source.
 * ev_a2a60ac3c7fd5e2c8ec7dea46f9f8f7cd19ec865371f09d136a7de11792ab0da
 * Entry: 0x6c2350; label: FUN_006c2350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c2350(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  puVar1 = (undefined4 *)*in_ECX;
  while (puVar1 != (undefined4 *)0x0) {
    if (puVar1[1] == 0) {
      in_ECX[1] = puVar1[2];
    }
    else {
      *(undefined4 *)(puVar1[1] + 8) = puVar1[2];
    }
    if (puVar1[2] == 0) {
      *in_ECX = puVar1[1];
    }
    else {
      *(undefined4 *)(puVar1[2] + 4) = puVar1[1];
    }
    puVar1[1] = 0;
    puVar1[2] = 0;
    in_ECX[2] = in_ECX[2] + -1;
    (**(code **)*puVar1)(1);
    puVar1 = (undefined4 *)*in_ECX;
  }
  return;
}

