/* Ghidra pseudocode, not original source.
 * ev_4e08cb6b9a05324ae7a2b7ff12e5cd4300e2bf96324e358c1c445da0c9e3f38b
 * Entry: 0x630dc0; label: FUN_00630dc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00630dc0(void)

{
  code *in_EAX;
  int iVar1;
  
  if (in_EAX != (code *)0x0) {
    iVar1 = (*in_EAX)();
    if (iVar1 == 1) {
      return 1;
    }
    if (iVar1 == 2) {
      FUN_00631270();
    }
  }
  return 0;
}

