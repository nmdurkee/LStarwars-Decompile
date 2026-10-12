/* Ghidra pseudocode, not original source.
 * ev_8c08cb58b3e2eca2ce3b645626710873c7692325f2a23ef4bde2c2500b41a2fb
 * Entry: 0x443120; label: FUN_00443120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00443120(void)

{
  if ((((DAT_0093d810 == 0) || (*(int *)(DAT_0093d810 + 0xcd0) == 0)) ||
      (*(char *)(DAT_0093d810 + 0x7b5) == ';')) &&
     (((DAT_0093d814 == 0 || (*(int *)(DAT_0093d814 + 0xcd0) == 0)) ||
      (*(char *)(DAT_0093d814 + 0x7b5) == ';')))) {
    return (float10)0;
  }
  return (float10)1;
}

