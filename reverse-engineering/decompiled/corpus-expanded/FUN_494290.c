/* Ghidra pseudocode, not original source.
 * ev_f838318f8db109b6dcd3b75a6a424a1459b1413cbbc9987106adb019bff4cb04
 * Entry: 0x494290; label: FUN_00494290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00494290(void)

{
  int in_EAX;
  float10 fVar1;
  
  if (*(char *)(in_EAX + 6) == '\0') {
    fVar1 = (float10)0;
  }
  else {
    fVar1 = (float10)FUN_00547a70(&DAT_0087656c);
  }
  FUN_00547a30((float)fVar1);
  return (float10)(float)fVar1;
}

