/* Ghidra pseudocode, not original source.
 * ev_65ca4a665d596d296f41bb3c37f26e684dc272ec4121c3f4d046db6dd8870575
 * Entry: 0x53d5d0; label: FUN_0053d5d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053d5d0(undefined4 param_1)

{
  undefined4 *in_ECX;
  undefined *puVar1;
  
  puVar1 = &DAT_028683e0;
  do {
    if (*(int *)(puVar1 + 0x4b0) == 0) {
      *(undefined4 *)(puVar1 + 0x4b0) = 1;
      goto LAB_0053d5f0;
    }
    puVar1 = puVar1 + 0x4b4;
  } while (puVar1 != &DAT_028febe0);
  puVar1 = (undefined *)0x0;
LAB_0053d5f0:
  in_ECX[1] = puVar1;
  in_ECX[2] = param_1;
  in_ECX[3] = param_1;
  *in_ECX = 1;
  return;
}

