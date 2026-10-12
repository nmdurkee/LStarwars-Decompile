/* Ghidra pseudocode, not original source.
 * ev_3e1dd6b2d4f666d2001b5d4d68499aac60c4283e1c30ebf06a77c3cfaf088012
 * Entry: 0x6c7480; label: FUN_006c7480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

