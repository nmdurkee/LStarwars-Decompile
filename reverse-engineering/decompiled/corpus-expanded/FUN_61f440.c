/* Ghidra pseudocode, not original source.
 * ev_001bae53855cec29a6ea9336ea11e15c4e661e4f9ad78accb3ab39ae90f716fb
 * Entry: 0x61f440; label: FUN_0061f440
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_0061f440(void)

{
  int in_EAX;
  int iVar1;
  
  if ((in_EAX != 0) &&
     ((in_EAX == *(int *)(DAT_02912e8c + 0x10) ||
      (*(int *)(in_EAX + 0x40) == *(int *)(DAT_02912e8c + 0x10))))) {
    iVar1 = (**(code **)(DAT_02912e8c + 0x18))(DAT_02912e8c);
    DAT_02912e8c = -(uint)(iVar1 != 0) & DAT_02912e8c;
  }
  return DAT_02912e8c != 0;
}

