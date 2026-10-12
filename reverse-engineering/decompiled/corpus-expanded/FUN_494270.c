/* Ghidra pseudocode, not original source.
 * ev_f838318f8db109b6dcd3b75a6a424a1459b1413cbbc9987106adb019bff4cb04
 * Entry: 0x494270; label: FUN_00494270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00494270(void)

{
  int in_EAX;
  float10 fVar1;
  
  if (*(char *)(in_EAX + 6) == '\0') {
    return (float10)0;
  }
  fVar1 = (float10)FUN_00547a70(&DAT_0087656c);
  return fVar1;
}

